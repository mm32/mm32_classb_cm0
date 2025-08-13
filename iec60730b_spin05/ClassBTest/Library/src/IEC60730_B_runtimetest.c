/**
 ******************************************************************************
 * @file    IEC60730_B_runtimetest.c
 * @author
 * @version V1.2.0
 * @date    19-Jun-2019
 * @brief   Contains the Self-test functions executed during main program execution.
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

extern uint32_t App_STEPS_NUMBER;
extern uint32_t SystemCoreClock;
uint32_t FULL_FLASH_CHECKED;
uint8_t  runtime_checkindx = 0;
uint8_t  runtime_flash_CtrlFlow_indx = 0;
uint32_t rom_test;

/** @addtogroup
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
ErrorStatus IEC60730_CheckStack(void);

/******************************************************************************/
/**
 * @brief  Initializes the Class B variables and their inverted redundant
 *   counterparts. Init also the Systick for clock frequency monitoring.
 * @param  : None
 * @retval : None
 */
void IEC60730_InitRunTimeChecks(void)
{
    MESSAGE_PRINTF(">>>Init run system...\r\n");

    /* Initialize variables for invariable memory check */
    IEC60730_B_TranspMarchInit();

    /* Init Class B variables required in main routine and SysTick interrupt
    service routine for timing purposes */
    TickCounter = 0u;
    TickCounterInv = 0xFFFFFFFFuL;

    TimeBaseFlag = 0u;
    TimeBaseFlagInv = 0xFFFFFFFFuL;

    LastCtrlFlowCnt = 0u;
    LastCtrlFlowCntInv = 0xFFFFFFFFuL;
    init_control_flow();

    /* Initialize variables for SysTick interrupt routine control flow monitoring */
    ISRCtrlFlowCnt = 0u;
    ISRCtrlFlowCntInv = 0xFFFFFFFFuL;

    aStackOverFlowPtrn[0] = 0xEEEEEEEEuL;
    aStackOverFlowPtrn[1] = 0xCCCCCCCCuL;
    aStackOverFlowPtrn[2] = 0xBBBBBBBBuL;
    aStackOverFlowPtrn[3] = 0xDDDDDDDDuL;

    /* Initialize SysTick to generate 1ms time base */
    if (SysTick_Config(SystemCoreClock / 1000uL) != 0x00)
    {
        MESSAGE_PRINTF("Run time base init failure\r\n");
        FailSafePOR(SYSTICK_INIT_CALLEE);
    }

    RefCrc32 = 0;
    RefCrc32Inv = ~RefCrc32;
    /* Initialize variables for invariable memory check */
    Flashtest_config();
    IEC60730_FlashCrc32Init();
    FULL_FLASH_CHECKED = ((uint32_t)DELTA_MAIN * App_STEPS_NUMBER + LAST_DELTA_MAIN);

    /* wait for  incapture Value is valid */
    LSIPeriodFlag = 0u;
    while (LSIPeriodFlag == 0u)
    {
    }

    /* Initialize variables for main routine control flow monitoring */
    CtrlFlowCnt = 0u;
    CtrlFlowCntInv = 0xFFFFFFFFuL;

    MESSAGE_PRINTF(">>>Do run time Checks...\r\n");
}

/**
  * @brief  CPU test at runtime
  * @param  : None
  * @retval : None
  */
ErrorStatus IEC60730_B_CpuRunTime_test(void)
{
    ErrorStatus result = SUCCESS;
    /*----------------------------------------------------------------------*/
    /*---------------------------- CPU registers ---------------------------*/
    /*----------------------------------------------------------------------*/
    control_flow_call(CPU_TEST_CALLER);

    if (IEC60730_B_RunTimeCPUTest() != CPUTEST_SUCCESS)
    {
        result = ERROR;
    }
    else
    {
        control_flow_resume(CPU_TEST_CALLER);
    }
    return (result);
}

/**
  * @brief  Stack overflow test at runtime
  * @param  : None
  * @retval : ErrorStatus (SUCCESS, ERROR)
  */
ErrorStatus IEC60730_Stack_Check(void)
{
    ErrorStatus result = SUCCESS;
    /*----------------------------------------------------------------------*/
    /*------------------------- Stack overflow -----------------------------*/
    /*----------------------------------------------------------------------*/
    control_flow_call(STACK_OVERFLOW_TEST);

    if (IEC60730_CheckStack() != SUCCESS)
    {
        result = ERROR;
    }
    else
    {
        control_flow_resume(STACK_OVERFLOW_TEST);
    }
    return (result);
}

/**
  * @brief  Clock  test at runtime
  * @param  : None
  * @retval : None
  */
void IEC60730_ClockTest_RunTime(void)
{
    /*----------------------------------------------------------------------*/
    /*------------------------- Clock monitoring ---------------------------*/
    /*----------------------------------------------------------------------*/
    control_flow_call(CLOCK_TEST_CALLER);
    switch (IEC60730_MainClockTest())
    {
    case FREQ_OK:
        control_flow_resume(CLOCK_TEST_CALLER);
        runtime_checkindx++;
        break;

    case EXT_SOURCE_FAIL:
        MESSAGE_PRINTF("\n\r Clock Source failure (Run-time)\n\r");
        FailSafePOR(CLOCK_TEST_CALLER);
        break;

    case CLASS_B_VAR_FAIL:
        MESSAGE_PRINTF("\n\r Class B variable error (clock test)\n\r");
        FailSafePOR(CLOCK_TEST_CALLER);
        break;

    case LSI_START_FAIL:
    case HSE_START_FAIL:
    case HSI_HSE_SWITCH_FAIL:
    case TEST_ONGOING:
    case CTRL_FLOW_ERROR:
    default:
        MESSAGE_PRINTF("Abnormal Clock Test routine termination \n\r");
        FailSafePOR(CLOCK_TEST_CALLER);
        break;
    }
}

/**
 * @brief  Perform set of generic tests at run time from main
 *         (can be divided into more separated segments if necessary)
 * @param  : None
 * @retval : None
 */
void IEC60730_DoRunTimeChecks(void)
{
    /* Is the time base duration elapsed? */
    if (TimeBaseFlag == 0xAAAAAAAAuL)
    {
        /* Verification of TimeBaseFlag integrity */
        /* The following pair of volatile variables is changed consistently at Systick ISR only */
        #ifdef __IAR_SYSTEMS_ICC__  /* IAR Compiler */
        #pragma diag_suppress=Pa082 // Suppress diagnostic Pa082
        #endif /* __IAR_SYSTEMS_ICC__ */
        if ((TimeBaseFlag ^ TimeBaseFlagInv) == 0xFFFFFFFFuL)
        #ifdef __IAR_SYSTEMS_ICC__  /* IAR Compiler */
        #pragma diag_default=Pa082  // Restore diagnostic Pa082
        #endif /* __IAR_SYSTEMS_ICC__ */
        {
            TimeBaseFlag = 0u;

            if (runtime_checkindx == 0)
            {
                /* Runtime CPU registers test.  */
                if (IEC60730_B_CpuRunTime_test() != SUCCESS)
                {
                    MESSAGE_PRINTF("Run-time CPU Test Failure\n\r");
                    FailSafePOR(CPU_TEST_CALLER);
                }
                else
                {
                    runtime_checkindx++;
                }
            }
            else if (runtime_checkindx == 1)
            {
                /* Runtime Stack overflow test. */
                if (IEC60730_Stack_Check() != SUCCESS)
                {
                    MESSAGE_PRINTF("Stack overflow\n\r");
                    FailSafePOR(STACK_OVERFLOW_TEST);
                }
                else
                {
                    runtime_checkindx++;
                }
            }
            else if (runtime_checkindx == 2)
            {
                /* Runtime clock test. */
                IEC60730_ClockTest_RunTime();
            }
            else if (runtime_checkindx == 3)
            {
                /* Runtime  Invariable memory CRC check.*/
                IEC60730_B_FlashRunTime_test();
            }
        }
        else
        {
            MESSAGE_PRINTF("Class B variable Error (main loop)\n\r");
            FailSafePOR(DELTA_MAIN);
        }
    } /* End of periodic Self-test routine */
}

/**
  * @brief  Flash test at runtime
  * @param  : None
  * @retval : None
  */
void IEC60730_B_FlashRunTime_test(void)
{
    if (runtime_flash_CtrlFlow_indx == 0)
    {
        control_flow_call(FLASH_TEST_CALLER);
        rom_test = IEC60730_crc32Run();

        switch (rom_test)
        {
        case TEST_RUNNING:
            control_flow_resume(FLASH_TEST_CALLER);
            runtime_flash_CtrlFlow_indx++;
            MESSAGE_PRINTF(".");
            break;

        case TEST_OK:
            CtrlFlowCntInv -= FLASH_TEST_CALLER;
            runtime_flash_CtrlFlow_indx++;
            MESSAGE_PRINTF("#\r\n");
            break;
        case TEST_FAILURE:
        case CLASS_B_DATA_FAIL:
        default:
            MESSAGE_PRINTF(" Run-time FLASH CRC Error\n\r");
            FailSafePOR(FLASH_TEST_CALLER);
            break;
        }
    }
    else if (runtime_flash_CtrlFlow_indx == 1)
    {
        /*----------------------------------------------------------------------*/
        /*---------------- Check Safety routines Control flow  -----------------*/
        /*------------- Refresh Window and independent watchdogs ---------------*/
        /*----------------------------------------------------------------------*/
        if (((CtrlFlowCnt ^ CtrlFlowCntInv) == 0xFFFFFFFFuL) && ((LastCtrlFlowCnt ^ LastCtrlFlowCntInv) == 0xFFFFFFFFuL))
        {
            if (rom_test == TEST_OK)
            {
                /* ==============================================================================*/
                /* MISRA violation of rule 11.4,17.4 - pointer arithmetic & casting has is used */
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pm088, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */
                if ((CtrlFlowCnt == FULL_FLASH_CHECKED) && ((CtrlFlowCnt - LastCtrlFlowCnt) == (LAST_DELTA_MAIN)))
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm088, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */
                /* ==============================================================================*/
                {
                    CtrlFlowCnt = 0u;
                    CtrlFlowCntInv = 0xFFFFFFFFuL;
                }
                else /* Return value form crc check was corrupted */
                {
                    MESSAGE_PRINTF("Control Flow Error (main loop, Flash CRC)\n\r");
                    FailSafePOR(LAST_DELTA_MAIN);
                }
            }
            else /* Flash test not completed yet */
            {
                if ((CtrlFlowCnt - LastCtrlFlowCnt) != DELTA_MAIN)
                {
                    MESSAGE_PRINTF("Control Flow Error (main loop, Flash CRC on-going)\n\r");
                    FailSafePOR(DELTA_MAIN);
                }
            }

            LastCtrlFlowCnt = CtrlFlowCnt;
            LastCtrlFlowCntInv = CtrlFlowCntInv;
            runtime_flash_CtrlFlow_indx = 0;
            runtime_checkindx = 0;
        }
        else
        {
            MESSAGE_PRINTF("Class B variable Error (main loop)\n\r");
            FailSafePOR(DELTA_MAIN);
        }
    }
}

/**
 * @brief  This function verifies that Stack didn't overflow
 * @param  : None
 * @retval : ErrorStatus = (ERROR, SUCCESS)
 */
ErrorStatus IEC60730_CheckStack(void)
{
    ErrorStatus result = SUCCESS;

    CtrlFlowCnt += STACK_OVERFLOW_CALLEE;

    if (aStackOverFlowPtrn[0] != 0xEEEEEEEEuL)
    {
        result = ERROR;
    }
    if (aStackOverFlowPtrn[1] != 0xCCCCCCCCuL)
    {
        result = ERROR;
    }
    if (aStackOverFlowPtrn[2] != 0xBBBBBBBBuL)
    {
        result = ERROR;
    }
    if (aStackOverFlowPtrn[3] != 0xDDDDDDDDuL)
    {
        result = ERROR;
    }

    CtrlFlowCntInv -= STACK_OVERFLOW_CALLEE;

    return (result);
}

/**
 * @}
 */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
