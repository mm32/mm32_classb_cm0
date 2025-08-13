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
void Iwdg_Init(unsigned short int IWDG_Prescaler, unsigned short int Reload);

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

#ifdef USE_TIM2_CLOCK_CHECK
/**
  * @brief  Config TIM2 input capture LSI clock.
  * @param  : None
  * @retval : None
  */
void TIM2_Init(void)
{
    NVIC_InitTypeDef  NVIC_InitStruct;
    //-------------------------------------------------------------
    TIM_TimeBaseInitTypeDef TIM_StructInit;
    TIM_ICInitTypeDef TIM_ICStructInit;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);               //TIM2 CLOCK ENALBE,Clock is pclk1=8mhz
    TIM_StructInit.TIM_Period=0xffffffff;
    TIM_StructInit.TIM_Prescaler=0;
    TIM_StructInit.TIM_ClockDivision=TIM_CKD_Div1;
    TIM_StructInit.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_StructInit.TIM_RepetitionCounter=0;
    TIM_TimeBaseInit(TIM2, &TIM_StructInit);

    TIM_ICStructInit.TIM_Channel=TIM_Channel_4;
    TIM_ICStructInit.TIM_ICPolarity=TIM_ICPolarity_Rising;
    TIM_ICStructInit.TIM_ICSelection=TIM_ICSelection_DirectTI;
    TIM_ICStructInit.TIM_ICPrescaler=TIM_ICPSC_Div8;                // flsi/8
    TIM_ICStructInit.TIM_ICFilter=0;
    TIM_ICInit(TIM2, &TIM_ICStructInit);

    TIM_ITConfig(TIM2,TIM_IT_CC4,ENABLE);

    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    TIM_Cmd(TIM2, DISABLE);
    TIM2->CNT=0;

#ifdef LSI_INCAP
    TIM2->OR=(1<<6); // LSI as TIM2_CH4 capture input

#elif defined HSE_INCAP
    TIM2->RESERVED0x50=(3<<6); // HSE/128 as TIM2_CH4 capture input
#endif

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE); //Enable power register clocked

    RCC_LSICmd(ENABLE);
    while((RCC->CSR & RCC_CSR_LSIRDY_Msk) == 0);
}

/**
  * @brief This function handles tim2 interrupt.
  * @param  : None
  * @retval : None
  */
void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2,TIM_IT_CC4))
    {
        tmpCC4_last = tmpCC4_now;
        tmpCC4_now = TIM_GetCapture4(TIM2);

        if (LSIPeriodFlag == 0u)
        {
            if ( TIM_GetFlagStatus(TIM2,TIM_FLAG_CC4OF) == 0u)
            {
                if (tmpCC4_now <=  tmpCC4_last)
                {
                    PeriodValue = (0xFFFFFFFF - tmpCC4_last + tmpCC4_now);
                }
                else
                {
                    PeriodValue = tmpCC4_now - tmpCC4_last;
                }

                /* Set Flag tested at main loop */
                PeriodValueInv = ~PeriodValue;
                LSIPeriodFlag = 0xAAAAAAAAuL;
                LSIPeriodFlagInv = 0x55555555uL;
            }
            else
            {
                TIM_ClearFlag(TIM2,TIM_FLAG_CC4OF);
            }
        }

        TIM_ClearITPendingBit(TIM2,TIM_IT_CC4);
    }

}
#else
void Tim14_UPCount_test(u16 Prescaler, u16 Period)
{
    TIM_TimeBaseInitTypeDef TIM_StructInit;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14 | RCC_APB1Periph_SYSCFG, ENABLE);

    TIM_StructInit.TIM_Period    = Period;
    TIM_StructInit.TIM_Prescaler = Prescaler;

    TIM_StructInit.TIM_ClockDivision     = TIM_CKD_Div1;
    TIM_StructInit.TIM_CounterMode       = TIM_CounterMode_Up;

    TIM_TimeBaseInit(TIM14, &TIM_StructInit);
}

/**
  * @brief This function handles IWDG interrupt.
  * @param  : None
  * @retval : None
  */
void IWDG_IRQHandler(void)
{
    tmpCC4_last = tmpCC4_now;
    tmpCC4_now = TIM_GetCounter(TIM14);

    /* overight results only in case the data is required */
    if (LSIPeriodFlag == 0u)
    {
        /* Compute period length */
        if (tmpCC4_now > tmpCC4_last)
        {
            PeriodValue = (tmpCC4_now - tmpCC4_last) & 0xFFFFuL;
        }
        else
        {
            PeriodValue = (0xFFFF - tmpCC4_last + tmpCC4_now)& 0xFFFFuL;
        }

        PeriodValueInv = ~PeriodValue;

        /* Set Flag tested at main loop */
        LSIPeriodFlag    = 0xAAAAAAAAuL;
        LSIPeriodFlagInv = 0x55555555uL;
    }

    IWDG_ClearITPendingBit();
    IWDG_ReloadCounter();
    EXTI_ClearITPendingBit(EXTI_Line24); //���EXTI��24�ϵ�IWDG�ж�
}

void Iwdg_Enable_Interrupt(void)
{
    IWDG_WriteAccessCmd(0x5555);
    IWDG_SetIGen(40);
    IWDG->CR |= IWDG_CR_IRQ_SEL_Msk;
}

void TIM14_IWDG_Xcross_Measure_Init(void)
{
    EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_StructInit;

    Tim14_UPCount_test(60-1, 0xFFFF);
    Iwdg_Init(IWDG_Prescaler_4, 440);
    Iwdg_Enable_Interrupt();

    EXTI_DeInit();
    EXTI_InitStructure.EXTI_Line    = EXTI_Line24;
    EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
    EXTI_ClearITPendingBit(EXTI_Line24);

    NVIC_StructInit.NVIC_IRQChannel = IWDG_IRQn;
    NVIC_StructInit.NVIC_IRQChannelPriority = 0x01;
    NVIC_StructInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_StructInit);

    IWDG_Enable();
    TIM_Cmd(TIM14, ENABLE);
}
#endif

/**
  * @brief  Init clock for IEC60730 xcross messurement
  * @param  : None
  * @retval : ErrorStatus (SUCCESS, ERROR)
  */
ErrorStatus IEC60730_InitClock_Xcross_Measurement(void)
{
    ErrorStatus result = SUCCESS;

#ifdef USE_TIM2_CLOCK_CHECK
    TIM2_Init();

    TIM_ClearFlag(TIM2, TIM_FLAG_CC4);
    TIM_Cmd(TIM2, ENABLE);
    TIM_CCxCmd(TIM2, TIM_Channel_4, TIM_CCx_Enable);
#else
    /* USING TIM and IWDG to clock check. */
    TIM14_IWDG_Xcross_Measure_Init();
#endif

    return result;
}

/**
  * @brief  IEC60730 clock module HSE CLOCK Valuecheck at startup
  * @param  : None
  * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
  *  HSI_HSE_SWITCH_FAIL, XCROSS_CONFIG_FAIL, EXT_SOURCE_FAIL, FREQ_OK)
  */
ClockStatus IEC60730_HSI_LSIcheck(void)
{
#ifdef USE_TIM2_CLOCK_CHECK
    uint32_t tim_freq;
#endif
    ClockStatus clck_sts = TEST_ONGOING;

    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }

    /*-------------------- HSI measurement check -------------------------*/
#ifdef USE_TIM2_CLOCK_CHECK
//    if( RCC->CFGR & RCC_CFGR_PPRE1)
//    {
//        tim_freq = RCC_GetPCLK1Freq() * 2;
//    }
//    else
//    {
//        tim_freq = RCC_GetPCLK1Freq();
//    }

    tim_freq = HSI_VALUE;/* PCLK1:60MHz. */
    Incap_Freq = (uint32_t)((float)tim_freq / (float)(PeriodValue) * 8);
#else
    Incap_Freq = PeriodValue;
#endif

#ifdef LSI_INCAP
    if (Incap_Freq < LSI_Min)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
    else if (Incap_Freq > LSI_Max)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
#else
    if (Incap_Freq < HSI_Min)
    {
        clck_sts = EXT_SOURCE_FAIL;
    }
    else if (Incap_Freq > HSI_Max)
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
ClockStatus IEC60730_HSE_LSIcheck(void)
{
#ifdef USE_TIM2_CLOCK_CHECK
    uint32_t tim_freq;
#endif
    ClockStatus clck_sts = TEST_ONGOING;

    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }

    /*-------------------- HSE measurement check -------------------------*/
#ifdef USE_TIM2_CLOCK_CHECK
    tim_freq = HSI_VALUE;/* PCLK1:60MHz. */
    Incap_Freq = (uint32_t)((float)tim_freq / (float)(PeriodValue) * 8);
#else
    Incap_Freq = PeriodValue;
#endif

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
  * @brief  IEC60730 clock module  CLOCK Valuecheck at run time
  * @param  : None
  * @retval : ClockStatus = (LSI_START_FAIL, HSE_START_FAIL,
  *  HSI_HSE_SWITCH_FAIL, XCROSS_CONFIG_FAIL, EXT_SOURCE_FAIL, FREQ_OK)
  */
ClockStatus IEC60730_clockrun_valuecheck(void)
{
#ifdef USE_TIM2_CLOCK_CHECK
    uint32_t tim_freq;
#endif
    ClockStatus result = TEST_ONGOING;

#ifdef USE_TIM2_CLOCK_CHECK

    tim_freq = HSI_VALUE;/* PCLK1:60MHz. */

    Incap_Freq = (uint32_t)((float)tim_freq / (float)(PeriodValue) * 8);
#else
    Incap_Freq = PeriodValue;
#endif

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
