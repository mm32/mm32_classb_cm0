/**
 ******************************************************************************
 * @file    IEC60730_B_clocktest.c
 * @author
 * @version V1.2.0
 * @date    19-Jun-2019
 * @brief   This file contains the test function for clock circuitry
 *          and wrong frequency detection.
 ******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

/* Includes ------------------------------------------------------------------*/
#include "IEC60730_B_lib.h"

volatile static uint32_t tmpCC4_now;
volatile static uint32_t tmpCC4_last;
volatile uint16_t period = 0;
volatile uint16_t duty = 0;

/** @addtogroup
 * @{
 */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Clock test at starup
 * @param  : None
 * @retval : None
 */
void IEC60730_ClockTest_Startup(void)
{
    ClockStatus clk_sts;

    control_flow_call(CLOCK_TEST_CALLER);

    /* test LSI & HSI clock systems */
    clk_sts = IEC60730_ClockStartUpTest();

    #ifdef MESSAGE_REPORT_ENABLE
    /* print out the test result */
    switch (clk_sts)
    {
        case LSI_START_FAIL:
            MESSAGE_PRINTF("LSI startup failure \r\n");
            break;

        case HSE_START_FAIL:
            MESSAGE_PRINTF("HSE startup failure \r\n");
            break;

        case HSI_HSE_SWITCH_FAIL:
        case HSE_HSI_SWITCH_FAIL:
        case PLL_OFF_FAIL:
            MESSAGE_PRINTF("Clock switch failure \r\n");
            break;

        case XCROSS_CONFIG_FAIL:
            MESSAGE_PRINTF("Clock Xcross measurement failure \r\n");
            break;

        case EXT_SOURCE_FAIL:
            MESSAGE_PRINTF("HSE clock found out of range\r\n");
            break;

        case FREQ_OK:
            MESSAGE_PRINTF(">>>Startup Clock frequency OK \r\n");
            break;

        default:
            MESSAGE_PRINTF("Abnormal exit from clock test\r\n");
    }
    #endif /* DEBUG_INFO */

    if (clk_sts != FREQ_OK)
    {
        FailSafePOR(CLOCK_TEST_CALLER);
    }

    control_flow_resume(CLOCK_TEST_CALLER);
}

/**
 * @brief  This function verifies the frequency from the last clock
 *   period measurement
 * @param  : None
 * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
 *   HSI_HSE_SWITCH_FAIL, TEST_ONGOING, EXT_SOURCE_FAIL,
 *   CLASS_B_VAR_FAIL, CTRL_FLOW_ERROR, FREQ_OK)
 */
ClockStatus IEC60730_MainClockTest(void)
{

    ClockStatus result = TEST_ONGOING; /* In case of unexpected exit */

    CtrlFlowCnt += CLOCKPERIOD_TEST_CALLEE;
    /* ==============================================================================*/
    /* MISRA violation of rule 12.4 - "&&" operand can't contain side effects in normal operation
     - all the following pairs of volatile variables are changed consistently at timer ISR only */
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pa082
#endif /* __IAR_SYSTEMS_ICC__ */
    /* checking result of LSI measurement done at TIM3 interrupt */
    if (((PeriodValue ^ PeriodValueInv) == 0xFFFFFFFFuL) && ((LSIPeriodFlag ^ LSIPeriodFlagInv) == 0xFFFFFFFFuL) && (LSIPeriodFlag != 0u))
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm026
#endif /* __IAR_SYSTEMS_ICC__ */
    /* ==============================================================================*/
    {
        result = IEC60730_clockrun_valuecheck();
    } /* Control Flow error */
    else
    {
        result = CLASS_B_VAR_FAIL;
    }
    CtrlFlowCntInv -= CLOCKPERIOD_TEST_CALLEE;

    return (result);
}

/**
  * @brief  Clock test at startup
  * @param  : None
  * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
  *   HSI_HSE_SWITCH_FAIL, TEST_ONGOING, EXT_SOURCE_FAIL,
  *   CLASS_B_VAR_FAIL, CTRL_FLOW_ERROR, FREQ_OK)
  */
ClockStatus IEC60730_ClockStartUpTest(void)
{
    ClockStatus clck_sts = TEST_ONGOING;

    CtrlFlowCnt += CLOCK_TEST_CALLEE;

#ifndef CUSTOM_HSE_FREQ
    if (clck_sts == TEST_ONGOING)
    {
        /* Configure dedicated timer to measure LSI period */
        if (IEC60730_InitClock_Xcross_Measurement() == ERROR)
        {
            clck_sts = XCROSS_CONFIG_FAIL;
        }
        else
        {
            clck_sts = IEC60730_HSI_LSIcheck();
        }
    }
#else
    if (clck_sts == TEST_ONGOING)
    {
        /* Configure dedicated timer to measure HSE period */
        if (IEC60730_InitClock_Xcross_Measurement() == ERROR)
        {
            clck_sts = XCROSS_CONFIG_FAIL;
        }
        else
        {
            clck_sts = IEC60730_HSE_LSIcheck();
        }
    }
#endif

    if (clck_sts == TEST_ONGOING)
    {
        clck_sts = FREQ_OK;
    }

    CtrlFlowCntInv -= CLOCK_TEST_CALLEE;

    return (clck_sts);
}

/**
  * @brief Config MCO, using LSI as input
  * @param  : None
  * @retval : None
  */
static void MCO_Config(void)
{
    /* MCO use PA9 */
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    GPIO_PinAFConfig( GPIOA, GPIO_PinSource9, GPIO_AF_5);

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

#ifdef LSI_INCAP
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE); // POWER reg clocked
    RCC_LSICmd(ENABLE);
    while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);

    RCC_MCOConfig(RCC_MCO_LSI);
#elif defined (HSE_INCAP)
    RCC_HSEConfig(RCC_HSE_ON);
    while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);

    RCC_MCOConfig(RCC_MCO_HSE);
#elif defined (HSI_INCAP)
    RCC_HSICmd(ENABLE);
    while (RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);

    RCC_MCOConfig(RCC_CFGR_MCO_HSI);
#endif
}


/**
  * @brief  Config TIM3 input capture GPIO pin.
  * @param  : None
  * @retval : None
  */
void TIM3_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    // TIM3_CH2 - PB5 -AF1
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_1);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/**
  * @brief  Config TIM3 input capture LSI
  * @param  : None
  * @retval : None
  */
void TIM3_PWM_Input_Init(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStruct;
    TIM_ICInitTypeDef  TIM3_ICInitStruct;
    NVIC_InitTypeDef        NVIC_InitStruct;

    TIM3_GPIO_Init();

    RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM3, ENABLE);

    TIM_TimeBaseStructInit(&TIM_TimeBaseStruct);
    TIM_TimeBaseStruct.TIM_Period    = 0xFFFF;
    TIM_TimeBaseStruct.TIM_Prescaler = 1 - 1;
    //Setting Clock Segmentation
    TIM_TimeBaseStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
    TIM_TimeBaseStruct.TIM_RepetitionCounter = 0;
    //TIM Upward Counting Mode
    TIM_TimeBaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStruct);

    TIM_ICStructInit(&TIM3_ICInitStruct);
    TIM3_ICInitStruct.TIM_Channel     = TIM_Channel_2;
    TIM3_ICInitStruct.TIM_ICPolarity  = TIM_ICPolarity_Rising;
    TIM3_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM3_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM3_ICInitStruct.TIM_ICFilter    = 0x0;
    //Configure PWM
    TIM_PWMIConfig(TIM3, &TIM3_ICInitStruct);
    //Select the valid input
    TIM_SelectInputTrigger(TIM3, TIM_TS_TI2FP2);
    //Configuration in master-slave reset mode
    TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);

    TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

    NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPriority = 0x00;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    TIM_Cmd(TIM3, ENABLE);
}

/**
  * @brief  TIM3 Handler Funtion
  * @param  : None
  * @retval : None
  */
void TIM3_IRQHandler(void)
{
    uint32_t tim_ccx_now;

    //Capture 1 Occurs Capture Event
    if (TIM_GetITStatus(TIM3, TIM_IT_CC1) != RESET)
    {
        /* get currently captured value. */
        tim_ccx_now = TIM_GetCapture2(TIM3);

        if (LSIPeriodFlag == 0u)
        {
                PeriodValue = tim_ccx_now;
                PeriodValueInv = ~PeriodValue;

                /* Set Flag tested at main loop */
                LSIPeriodFlag = 0xAAAAAAAAuL;
                LSIPeriodFlagInv = 0x55555555uL;
        }

        TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);

    }
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
}

/**
  * @brief  Init clock for IEC60730 xcross messurement
  * @param  : None
  * @retval : ErrorStatus (SUCCESS, ERROR)
  */
ErrorStatus IEC60730_InitClock_Xcross_Measurement(void)
{
    ErrorStatus result = SUCCESS;

    MCO_Config();
    TIM3_PWM_Input_Init();

    return result;
}

/**
  * @brief  IEC60730 clock module HSE CLOCK Valuecheck at startup
  * @param  : None
  * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
  *  HSI_HSE_SWITCH_FAIL, XCROSS_CONFIG_FAIL, EXT_SOURCE_FAIL, FREQ_OK)
  */
ClockStatus IEC60730_HSE_LSIcheck(void)
{
    ClockStatus clck_sts = TEST_ONGOING;
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }

    Incap_Freq =(uint32_t) ((float)RCC_GetHCLKFreq() / (float)PeriodValue);

    /*-------------------- HSE measurement check -------------------------*/

#ifdef HSE_INCAP
    if (Incap_Freq < HSE_Min)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
    else if (Incap_Freq > HSE_Max)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
#else
    if (Incap_Freq < LSI_Min)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
    else if (Incap_Freq > LSI_Max)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
#endif

    MESSAGE_PRINTF("   Read Incapture Frequency OK freq = %05dHz !\r\n", Incap_Freq);
    return (clck_sts);
}

/**
  * @brief  IEC60730 clock module HSE CLOCK Valuecheck at startup
  * @param  : None
  * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
  *  HSI_HSE_SWITCH_FAIL, XCROSS_CONFIG_FAIL, EXT_SOURCE_FAIL, FREQ_OK)
  */
ClockStatus IEC60730_HSI_LSIcheck(void)
{
    ClockStatus clck_sts = TEST_ONGOING;
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }

    Incap_Freq =(uint32_t) ((float)RCC_GetHCLKFreq() / (float)PeriodValue);

    /*-------------------- HSI measurement check -------------------------*/
#ifndef LSI_INCAP
    if (Incap_Freq < HSI_Min)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
    else if (Incap_Freq > HSI_Max)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
#else
    if (Incap_Freq < LSI_Min)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
    else if (Incap_Freq > LSI_Max)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
#endif

    MESSAGE_PRINTF("   Read Incapture Frequency OK freq = %05dHz !\r\n", Incap_Freq);

    return (clck_sts);
}

/**
  * @brief  IEC60730 clock module  CLOCK Valuecheck at run time
  * @param  : None
  * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
  *  HSI_HSE_SWITCH_FAIL, XCROSS_CONFIG_FAIL, EXT_SOURCE_FAIL, FREQ_OK)
  */
ClockStatus IEC60730_clockrun_valuecheck(void)
{
    ClockStatus result = TEST_ONGOING;

    Incap_Freq =(uint32_t) ((float)RCC_GetHCLKFreq() / (float)PeriodValue);

#ifdef CUSTOM_HSE_FREQ
    #ifdef HSI_INCAP
        if(Incap_Freq < HSI_Min )
    #else
        if(Incap_Freq < LSI_Min )
    #endif
#else
    #ifdef HSE_INCAP
        if(Incap_Freq < HSE_Min )
    #else
        if(Incap_Freq < LSI_Min )
    #endif
#endif
    {
        result = EXT_SOURCE_FAIL; /* Sub-harmonics: LSI -25% below expected */
    }
    else
    {
#ifdef CUSTOM_HSE_FREQ
    #ifdef HSI_INCAP
        if (Incap_Freq > HSI_Max)
    #else
        if (Incap_Freq > LSI_Max)
    #endif
#else
    #ifdef HSE_INCAP
        if (Incap_Freq > HSE_Max)
    #else
        if (Incap_Freq > LSI_Max)
    #endif
#endif
        {
            /* Switch back to internal clock */
            result = EXT_SOURCE_FAIL; /* Harmonics: LSI +25% above expected */
        }
        else
        {
            result = FREQ_OK; /* Crystal or Resonator started correctly */
            /* clear flag here to ensure refresh LSI measurement result will be taken at next check */
            LSIPeriodFlag = 0u;
        } /* No harmonics */
    } /* No sub-harmonics */

    return (result);
}

/**
 * @}
 */

/******************* (C) COPYRIGHT 2019 Mindmotion *****END OF FILE****/
