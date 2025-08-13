/**
 ******************************************************************************
 * @file    IEC60730_B_aux.c
 * @author
 * @version V1.2.0
 * @date    19-Jun-2019
 * @brief   This file contains the interface function for Class B test.
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

#define __HAL_RCCCSR_RSTFLAGSCLEAR() SET_BIT(RCC->CSR, RCC_CSR_RMVF)

extern uint32_t RAMRunTimetest_start;
extern uint32_t RAMRunTimetest_end;
extern uint32_t RAM_endadd_run;

volatile static uint32_t tmpIC1;
volatile static uint16_t period = 0;
volatile static uint16_t duty = 0;

#define CLASS_B_ROWS (((uint32_t)RAMRunTimetest_end - (uint32_t)RAMRunTimetest_start) / (RT_RAM_BLOCKSIZE - 2u * RT_RAM_BLOCK_OVERLAP))
/* +2 below is for last block & buffer self-test itself */
#define RAM_TEST_COMPLETED ((uint32_t)(DELTA_ISR * (uint32_t)(CLASS_B_ROWS / 4u + 2u)))

/** @addtogroup
 * @{
 */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/******************************************************************************/
/**
 * @brief  This routine is executed in case of failure is detected by one of
 *    self-test routines. The routine is empty and it has to be filled by end
 *    user to keep application safe while define proper recovery operation
 * @param  : None
 * @retval : None
 */

void FailSafePOR(uint32_t E_ID)
{
    /* disable any checking services at SystTick interrupt */
    Error_word = E_ID;
    TickCounter = TickCounterInv = 0u;

    MESSAGE_PRINTF(" >>>>>>>>>> POR FailSafe Mode <<<<<<<<<<\n\r");
    MESSAGE_PRINTF(" Error ID : %03d \n\r", Error_word);
    switch (Error_word)
    {
    case CPU_TEST_CALLEE:
        MESSAGE_PRINTF(" \n\r cpu test failure (startup)\n\r");
        break;
    case CPU_TEST_CALLER:
        MESSAGE_PRINTF(" \n\r cpu test failure (runtime)\n\r");
        break;
    case RAM_TEST_CALLEE:
        MESSAGE_PRINTF(" \n\r RAM test failure \n\r");
        break;
    }

    while (1)
    {
#ifndef NO_RESET_AT_FAIL_MODE
        /* Generate system reset */
        NVIC_SystemReset();
#else
        while (1)
        {
#ifdef USE_INDEPENDENT_WDOG
            IWDG_ReloadCounter();
#endif /* USE_INDEPENDENT_WDOG */
        }
#endif /* NO_RESET_AT_FAIL_MODE */
    }
}

/**
  * @brief  TIndependent wdg Config
  *
  * @param  prescaler: specifies the IWDG Prescaler value.
  *         This parameter can be one of the following values:
  * @arg    IWDG_Prescaler_4: IWDG prescaler set to 4
  * @arg    IWDG_Prescaler_8: IWDG prescaler set to 8
  * @arg    IWDG_Prescaler_16: IWDG prescaler set to 16
  * @arg    IWDG_Prescaler_32: IWDG prescaler set to 32
  * @arg    IWDG_Prescaler_64: IWDG prescaler set to 64
  * @arg    IWDG_Prescaler_128: IWDG prescaler set to 128
  * @arg    IWDG_Prescaler_256: IWDG prescaler set to 256
  *         reload: specifies the IWDG reload value.
  *         This parameter must be a number between 0 and 0x0FFF.
  * @retval : None
  */
void Iwdg_Init(unsigned short int IWDG_Prescaler, unsigned short int Reload)
{
    /*Start the internal low-speed clock and wait for the clock to be ready*/
    RCC_LSICmd(ENABLE);
    while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);

    /*Set clock prescaler*/
    IWDG_WriteAccessCmd(0x5555);
    IWDG_SetPrescaler(IWDG_Prescaler);
    PVU_CheckStatus();
    /*Set the overload register value*/
    RVU_CheckStatus();
    while ((IWDG->RLR) != Reload)
    {
        IWDG_WriteAccessCmd(0x5555);
        IWDG->RLR = Reload;
        RVU_CheckStatus();
    }

    /*Load and enable counters*/
    IWDG_ReloadCounter();
    IWDG_Enable();
}

/**
  * @brief  windows watchdog Config
  * @param  : ucTcnt: specifies the watchdog counter value
  *         WindowValue: specifies the window value to be compared to the
  *         downcounter.This parameter value must be lower than 0x80.
  * @retval : ErrorStatus(ERROR = 0, SUCCESS = 1)
  */
void WWDG_Init(unsigned char ucTcnt, unsigned char ucWcnt)
{
    WWDG_DeInit();
    RCC_APB1PeriphClockCmd(RCC_APB1ENR_WWDG, ENABLE);
    //WWDG_Prescaler_x,x is 1,2,4,8,WWDG counter clock = (PCLK1/4096)/x
    WWDG_SetPrescaler(WWDG_Prescaler_8);
    WWDG_SetWindowValue(ucWcnt);
    //Watchdog counter decrement assignment as 7-bit data and has a value between 0x40 ~ 0x7f
    WWDG_Enable(ucTcnt);
}

/**
  * @brief  Verifies the watchdog by forcing watchdog resets
  * @param  : None
  * @retval : ErrorStatus(ERROR = 0, SUCCESS = 1)
  */
ErrorStatus IEC60730_B_WDGSelfTest(void)
{
    ErrorStatus result = ERROR;
    /* ==============================================================================*/
    /* MISRA violation of rule 12.4 - side effect of && and || operators ignored */
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pm026
#endif /* __IAR_SYSTEMS_ICC__ */

#ifdef MESSAGE_REPORT_ENABLE
    if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
    {
        MESSAGE_PRINTF("   Pin reset \r\n");
    }

    if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
    {
        MESSAGE_PRINTF("   POR reset \r\n");
    }

    if (RCC_GetFlagStatus(RCC_FLAG_SFTRST) != RESET)
    {
        MESSAGE_PRINTF("   SW reset \r\n");
    }

    if (RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET)
    {
        MESSAGE_PRINTF("   IWDG reset \r\n");
    }

    if (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET)
    {
        MESSAGE_PRINTF("   WWDG reset \r\n");
    }
#endif /* DEBUG_INFO */

    /* start watchdogs test if one of the 4 conditions below is valid */
    if ((RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET) \
            || (RCC_GetFlagStatus(RCC_FLAG_SFTRST) != RESET) \
            || ((RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET) \
            && (RCC_GetFlagStatus(RCC_FLAG_IWDGRST) == RESET) \
            && (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) == RESET)))
    {
        MESSAGE_PRINTF("... Power-on or software reset, testing IWDG ... \r\n");
        /* Clear all flags before resuming test */
        __HAL_RCCCSR_RSTFLAGSCLEAR(); // Clear all reset flags

        /* Setup IWDG to minimum period */
        Iwdg_Init(IWDG_Prescaler_4, 2);

        /* Wait for an independent watchdog reset */
        while (1);
    }
    else /* Watchdog test or software reset triggered by application failure */
    {
        if ((RCC_GetFlagStatus(RCC_FLAG_IWDGRST) == RESET) && (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET))
        {
          /* Clear all flags before resuming test */
           __HAL_RCCCSR_RSTFLAGSCLEAR(); // Clear all reset flags

           MESSAGE_PRINTF("... WWDG reset, re-start WDG test ... \r\n");

            NVIC_SystemReset();
        }
        else  /* If IWDG only was set, continue the test with WWDG test*/
        {
            if ((RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET) && (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) == RESET))
            {

                MESSAGE_PRINTF("... IWDG reset from test or application, testing WWDG\r\n");

                WWDG_Init(64, 63);
                while (1);
            }
            else  /* If both flags IWDG & WWDG flags are set, means that watchdog test is completed */
            {
                if ((RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET) && (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET))
                {
                    /* Clear all flags before resuming test */
                    __HAL_RCCCSR_RSTFLAGSCLEAR();                        //Clear all reset flags

                    MESSAGE_PRINTF(">>>Startup Watchdog Test OK\r\n");

                    result = SUCCESS;
                    return (result);
                }
                else  /* Unexpected Flag configuration, re-start WDG test */
                {
                    /* Clear all flags before resuming test */
                    __HAL_RCCCSR_RSTFLAGSCLEAR();                        //Clear all reset flags
                    MESSAGE_PRINTF("...Unexpected Flag configuration, re-start WDG test... \r\n");
                    return (result);
                } /* End of Unexpected Flag configuration */
            } /* End of normal test sequence */
        } /* End of partial WDG test (IWDG test done) */
    } /* End of part where 1 or 2 Watchdog flags are set */

#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm026
#endif /* __IAR_SYSTEMS_ICC__ */
}

/**
  * @brief  SysTick_Handler is call from interrupt map,about 1ms
  * @note   Call delay count function.
  * @param  : None
  * @retval : None
  */
__IO uint32_t uwTick;
/*__weak*/ uint32_t HAL_GetTick(void)
{
    return uwTick;
}

/**
  * @brief  This function handles SysTick interrupt.
  * @param  : None
  * @retval : None
  */
void SysTick_Handler(void)
{
    uwTick++;

    //---------------------------------------------------------------------------------for class b
    /*----------------------------------------------------------------------*/
    /*---------------- Verify TickCounter integrity  -----------------------*/
    /*----------------------------------------------------------------------*/
    if ((TickCounter ^ TickCounterInv) == 0xFFFFFFFFuL)
    {
        TickCounter++;
        TickCounterInv = ~TickCounter;

        if (TickCounter >= SYSTICK_10ms_TB)
        {
            uint32_t RamTestResult;
            /* Reset timebase counter */
            TickCounter = 0u;
            TickCounterInv = 0xFFFFFFFFuL;

            /* Set Flag read in main loop */
            TimeBaseFlag = 0xAAAAAAAAuL;
            TimeBaseFlagInv = 0x55555555uL;

            ISRCtrlFlowCnt += RAM_MARCHC_ISR_CALLER;
            __disable_irq();
            RamTestResult = IEC60730_B_TranspMarch(RAMRunTimetest_start, RAMRunTimetest_end, RAM_endadd_run);
            __enable_irq();
            ISRCtrlFlowCntInv -= RAM_MARCHC_ISR_CALLER;

            switch (RamTestResult)
            {
            case TEST_RUNNING:
                break;

            case TEST_OK:
                break;

            case TEST_FAILURE:
            case CLASS_B_DATA_FAIL:
            default:
                MESSAGE_PRINTF("\n\r >>>>>>>>>>>>>>>>>>>  RAM Error (March C- Run-time check)\n\r");
                FailSafePOR(RAM_TEST_CALLEE);
                break;
            } /* End of the switch */

            /* Do we reached the end of RAM test? */
            /* Verify 1st ISRCtrlFlowCnt integrity */
            if ((ISRCtrlFlowCnt ^ ISRCtrlFlowCntInv) == 0xFFFFFFFFuL)
            {
                if (RamTestResult == TEST_OK)
                {
                    /* ==============================================================================*/
                    /* MISRA violation of rule 17.4 - pointer arithmetic is used to check RAM test control flow */
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pm088
#endif /* __IAR_SYSTEMS_ICC__ */

                    if (ISRCtrlFlowCnt != RAM_TEST_COMPLETED)
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm088
#endif /* __IAR_SYSTEMS_ICC__ */
                    /* ==============================================================================*/
                    {
                        MESSAGE_PRINTF("\n\r Control Flow error (RAM test) \n\r");
                        FailSafePOR(RAM_TEST_COMPLETED);
                    }
                    else /* Full RAM was scanned */
                    {
                        ISRCtrlFlowCnt = 0u;
                        ISRCtrlFlowCntInv = 0xFFFFFFFFuL;
                    }
                } /* End of RAM completed if*/
            } /* End of control flow monitoring */
            else
            {
                MESSAGE_PRINTF("\n\r Control Flow error in ISR \n\r");
                FailSafePOR(RAM_TEST_COMPLETED);
            }

        } /* End of the 10 ms timebase interrupt */
    }

    /*----------------------------------------------------------------------*/
    /*---------------- Verify TickCounter integrity  -----------------------*/
    /*----------------------------------------------------------------------*/
}

/**
 * @}
 */

/******************* (C) COPYRIGHT 2019 Mindmotion *****END OF FILE****/
