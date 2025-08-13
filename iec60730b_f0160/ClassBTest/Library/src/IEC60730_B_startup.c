/**
 ******************************************************************************
 * @file    IEC60730_B_startup.c
 * @author  NJ ClassB TEAM
 * @date    19-Jun-2019
 * @brief   This file contains sequence of self-test routines to be executed just
 *          after initialization of the application before main execution starts
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
#define ALLOC_GLOBALS

#include "IEC60730_B_lib.h"
#include "IEC60730_B_startup.h"

/** @addtogroup
 * @{
 */

/* Public variables ---------------------------------------------------------*/
uint32_t RAMRunTimetest_start;
uint32_t RAMRunTimetest_end;
uint32_t RAM_endadd_run;

uint32_t App_ROM_START;
uint32_t App_ROM_END;
uint32_t App_ROM_SIZEinWORDS;
uint32_t App_STEPS_NUMBER;
uint32_t App_FLASH_BLOCK_WORDS;
uint32_t App_REF_CRC32;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void Iwdg_Init(unsigned short int IWDG_Prescaler, unsigned short int Reload);
void PLATFORM_InitConsole(uint32_t Baudrate);

#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
extern void __iar_data_init3(void);
#pragma optimize = none
#endif

#if defined(__CC_ARM) || defined(__GNUC__) /* Using Keil MDK AC(ARM Compiler) 5 or 6 */
/**
 * @brief  Switch between startup and main code
 * @param  : None
 * @retval : None
 */
void $Sub$$main(void)
{
    if (CRC_FLAG != 0xAAu)
    {
        IEC60730_B_startup(); /* trick to call StartUp before main entry */
    }

    CRC_FLAG = 0u;
    $Super$$main();
}
#endif /* __CC_ARM || __GNUC__ */

/**
 * @brief  Contains the very first test routines executed right after the reset
 * @param  : None.  Flash interface initialized, Systick timer ON (2ms timebase)
 * @retval : None
 */
void IEC60730_B_startup(void)
{
    /* block run time tests performed at SysTick interrupt */
    TickCounter = TickCounterInv = 0;

#if defined(PRINT_USING_UART) && defined( MESSAGE_REPORT_ENABLE)
    PLATFORM_InitConsole(UART_BAUDRATE);
#endif

    MESSAGE_PRINTF("\r\n ************************************************\r\n");
    MESSAGE_PRINTF("\r\n                 IEC60730 Class B                \r\n");
#ifdef __IAR_SYSTEMS_ICC__  /* IAR Compiler */
    MESSAGE_PRINTF("\r\n                  IAR toolchain                  \r\n");
#endif
#if defined(__ARMCC_VERSION) || defined(__CC_ARM)
    MESSAGE_PRINTF("\r\n                  Keil toolchain                 \r\n");
#endif
    MESSAGE_PRINTF("\r\n ******* IEC60730 Class B Test in Startup *******\r\n");

    /*--------------------------------------------------------------------------*/
    /*------Initialization of counters for control flow monitoring *------------*/
    /*--------------------------------------------------------------------------*/
    init_control_flow();

    /*--------------------------------------------------------------------------*/
    /*------------------- CPU registers and flags self test --------------------*/
    /*--------------------------------------------------------------------------*/
    if (IEC60730_B_FullCpu_test() != SUCCESS)
    {
        MESSAGE_PRINTF("Startup CPU Test Failure\r\n");
        FailSafePOR(CPU_TEST_CALLER);
    }

    /*--------------------------------------------------------------------------*/
    /*--------------------- WDOGs functionality self test ----------------------*/
    /*--------------------------------------------------------------------------*/
    control_flow_call(WDG_TEST_CALLER);

    /* IWDG test, system reset is performed here */
    if (IEC60730_B_WDGSelfTest() != SUCCESS)
    {
        NVIC_SystemReset();
    }

    control_flow_resume(WDG_TEST_CALLER);

    /*--------------------------------------------------------------------------*/
    /*--------------------- Invariable memory CRC check ------------------------*/
    /*--------------------------------------------------------------------------*/
    Flashtest_config();

    MESSAGE_PRINTF("   FLASH Start addr:0x%08X, End addr:0x%08X\r\n",\
                            App_ROM_START, App_ROM_END);
    if (IEC60730_B_FullFlash_test() != SUCCESS)
    {
        MESSAGE_PRINTF("  FLASH 32bit CRC Error at CRC Addr:%X, Value:%X\r\n", \
                            App_REF_CRC32, (*(uint32_t *)App_REF_CRC32));
        FailSafePOR(CRC32_TEST_CALLER);
    }
    else
    {
        /* Test OK */
        MESSAGE_PRINTF("   FLASH 32bit CRC Addr:0x%X, Value:0x%X\r\n", \
                            App_REF_CRC32, (*(uint32_t *)App_REF_CRC32));
        MESSAGE_PRINTF(">>>Startup FLASH 32-bit CRC OK\r\n");
    }

    /*--------------------------------------------------------------------------*/
    /*-- Verify Control flow before RAM init (which clears Ctrl flow counters) -*/
    /*--------------------------------------------------------------------------*/
    if (control_flow_check_point(CHECKPOINT1) == ERROR)
    {
        MESSAGE_PRINTF("Startup Control Flow Error Checkpoint 1\r\n");
        FailSafePOR(CHECKPOINT1);
    }
    else
    {
        MESSAGE_PRINTF(">>>Control Flow Checkpoint 1 OK \r\n");
    }

    /*--------------------------------------------------------------------------*/
    /* --------------------- Variable memory functional test -------------------*/
    /*--------------------------------------------------------------------------*/
    /* no stack operation can be performed during the test */
    __disable_irq();

    //RAM test using BCKGRND_VA parameter.
    Ramtest_config();
    if ((IEC60730_B_FullRamMarchC(RAM_START, (uint32_t *)RAM_endadd_run, BCKGRND_VA) != SUCCESS))
    {
        /* restore interrupt capability */
        __enable_irq();
        #ifdef __IAR_SYSTEMS_ICC__
        __iar_data_init3();
        #endif /* __IAR_SYSTEMS_ICC__ */
        MESSAGE_PRINTF("Startup RAM Test Failure\r\n");
        FailSafePOR(RAM_TEST_CALLEE);
    }

    // RAM test using BCKGRND_CB parameter to prevent errors from consecutive bit stickiness.
    Ramtest_config();
    if (IEC60730_B_FullRamMarchC(RAM_START, (uint32_t *)RAM_endadd_run, BCKGRND_CB) != SUCCESS)
    {
        /* restore interrupt capability */
        __enable_irq();
        #ifdef __IAR_SYSTEMS_ICC__
        __iar_data_init3();
        #endif /* __IAR_SYSTEMS_ICC__ */
        MESSAGE_PRINTF("Startup RAM Test Failure\r\n");
        FailSafePOR(RAM_TEST_CALLEE);
    }

    //RAM test using BCKGRND parameter.
    Ramtest_config();
    /* WARNING: Stack is zero-initialized when exiting from this routine */
    if (IEC60730_B_FullRamMarchC(RAM_START, (uint32_t *)RAM_endadd_run, BCKGRND) != SUCCESS)
    {
        /* restore interrupt capability */
        __enable_irq();
        #ifdef __IAR_SYSTEMS_ICC__
        __iar_data_init3();
        #endif /* __IAR_SYSTEMS_ICC__ */
        MESSAGE_PRINTF("Startup RAM Test Failure\r\n");
        FailSafePOR(RAM_TEST_CALLEE);
    }

    /* restore interrupt capability */
     __enable_irq();
    /* restore the data segment initializers from flash to SRAM (repeat procedure from IAR & GCC startup) */
    #ifdef __IAR_SYSTEMS_ICC__
    __iar_data_init3();
    #endif /* __IAR_SYSTEMS_ICC__ */
    MESSAGE_PRINTF(">>>Startup Full RAM Test OK\r\n");

    /*--------------------------------------------------------------------------*/
    /*--------- Store reference 32-bit CRC in RAM after RAM test ---------------*/
    /*--------------------------------------------------------------------------*/
    /* Initialization of counters for control flow monitoring
       (destroyed during RAM test) */
    init_control_flow();
    IEC60730_B_CRC_StoreclassBData();

    /*--------------------------------------------------------------------------*/
    /*----------------------- Clock Frequency Self Test ------------------------*/
    /*--------------------------------------------------------------------------*/
    IEC60730_ClockTest_Startup();

    /*--------------------------------------------------------------------------*/
    /* --------------- Initialize stack overflow pattern ---------------------- */
    /*--------------------------------------------------------------------------*/
    control_flow_call(STACK_OVERFLOW_TEST);
    aStackOverFlowPtrn[0] = 0xEEEEEEEEuL;
    aStackOverFlowPtrn[1] = 0xCCCCCCCCuL;
    aStackOverFlowPtrn[2] = 0xBBBBBBBBuL;
    aStackOverFlowPtrn[3] = 0xDDDDDDDDuL;
    control_flow_resume(STACK_OVERFLOW_TEST);

    /*--------------------------------------------------------------------------*/
    /* -----  Verify Control flow before Starting main program execution ------ */
    /*--------------------------------------------------------------------------*/
    if (control_flow_check_point(CHECKPOINT2) == ERROR)
    {
        MESSAGE_PRINTF("Control Flow Error Checkpoint 2\r\n");
        FailSafePOR(CHECKPOINT2);
    }
    else
    {
        MESSAGE_PRINTF(">>>Control Flow Checkpoint 2 OK \r\n");
    }

    /* IEC60730 Class B startup test completed successfully. */
    GotoCompilerStartUp(); //Enter the main function.
}

/**
 * @brief  Flash test interface initialized
 * @param  : None
 * @retval : None
 */
void Flashtest_config(void)
{
    App_ROM_START         = ROM_START;
    App_ROM_END           = ROM_END;
    App_ROM_SIZEinWORDS   = ROM_SIZEinWORDS;
    App_STEPS_NUMBER      = STEPS_NUMBER;
    App_FLASH_BLOCK_WORDS = FLASH_BLOCK_WORDS;
    App_REF_CRC32         = (uint32_t)REF_CRC32;
}

/**
 * @brief  RAM test interface initialized
 * @param  : None
 * @retval : None
 */
void Ramtest_config(void)
{
    RAMRunTimetest_start = MCU_RAM_RunTimetestStart_ADDR;
    RAMRunTimetest_end   = MCU_RAM_RunTimetestEnd_ADDR;
    RAM_endadd_run       = MCU_RAM_End_ADDR;
}

/**
 * @brief  Full CPU test code
 * @param  : None
 * @retval : ErrorStatus (SUCCESS, ERROR)
 */
ErrorStatus IEC60730_B_FullCpu_test(void)
{
    ErrorStatus result = SUCCESS;

    control_flow_call(CPU_TEST_CALLER);
    /* WARNING: all registers destroyed when exiting this function (including
    preserved registers R4 to R11) while excluding stack pointer R13) */
    if (IEC60730_B_StartUpCPUTest() != CPUTEST_SUCCESS)
    {
        result = ERROR;
    }
    else /* CPU Test OK */
    {
        control_flow_resume(CPU_TEST_CALLER);
        MESSAGE_PRINTF(">>>Startup CPU Test OK\r\n");
    }

    return (result);
}

/**
 * @brief  Verifies the consistency and value of control flow counters
 * @param  : check value of the positive counter
 * @retval : ErrorStatus (SUCCESS, ERROR)
 */
ErrorStatus control_flow_check_point(uint32_t chck)
{
    ErrorStatus Result = SUCCESS;

    if ((CtrlFlowCnt != (chck)) || ((CtrlFlowCnt ^ CtrlFlowCntInv) != 0xFFFFFFFFuL))
    {
        Result = ERROR;
    }
    return (Result);
}

/**
 * @}
 */

/******************* (C) COPYRIGHT  Mindmotion *****END OF FILE****/
