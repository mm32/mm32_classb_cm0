/**
 ******************************************************************************
 * @file    IEC60730_B_param.h
 * @author
 * @version V1.2.0
 * @date    19-Jun-2019
 * @brief   This file contains the parameters to be customized for
 *                      the final application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IEC60730_B_PARAM_H
#define __IEC60730_B_PARAM_H

#include <stdio.h>
#include <stdint.h>
#include <types.h>
#include "hal_crc.h"
#include "hal_conf.h"

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* This avoids having multiply defined global variables */
#ifdef ALLOC_GLOBALS
#define EXTERN
#else
#define EXTERN extern
#endif

/* This is for having self-diagnostic messages reported on a PC via UART or J-Link RTT */
/* comment out next line then Message report is disable. */
#define MESSAGE_REPORT_ENABLE

#ifdef MESSAGE_REPORT_ENABLE
#define PRINT_USING_UART

 #ifdef PRINT_USING_UART
    #define MESSAGE_PRINTF(...)          printf(__VA_ARGS__)
    #define UART_BAUDRATE                115200u
 #endif
#else
#define MESSAGE_PRINTF(...)
#endif

/* uncoment next lines to select using hardware CRC or software CRC. */
#define USE_HARDWARE_CRC
//#define USE_SOFTWARE_CRC

/* uncoment next lines to configure watchdogs & resets for debug purposes */
#define USE_INDEPENDENT_WDOG
// #define USE_WINDOW_WDOG

/* comment out next line to force micro reset at fail mode */
#define NO_RESET_AT_FAIL_MODE

/* comment out next line when there is no window feature at IWDG */
#define IWDG_FEATURES_BY_WINDOW_OPTION

/* system clock & HSE when HSE is applied as PLL source */
#if !defined(HSE_VALUE)
#define HSE_VALUE            ((uint32_t)8000000)
#endif /* HSE_VALUE */

/* Reserved area for RAM buffer, incl overlap for test purposes */
/* Don't change this parameter as it is related to physical technology used! */
#define RT_RAM_BLOCKSIZE     ((uint32_t)6u)
/* Min overlap to cover coupling fault from one tested row to the other */
#define RT_RAM_BLOCK_OVERLAP ((uint32_t)1u)

/* These are the direct and inverted data (pattern) used during the RAM
test, performed using March C- Algorithm */
#define BCKGRND              ((uint32_t)0x00000000uL)
#define BCKGRND_CB           ((uint32_t)0x33333333uL)
#define BCKGRND_VA           ((uint32_t)0xAAAAAAAAuL)
#define INV_BCKGRND          ((uint32_t)0xFFFFFFFFuL)

/* uncoment next line to use March-X test instead of March-C */
//#define USE_MARCHX_RAM_TEST

/* This is to provide a time base longer than the SysTick for the main */
/* For instance this can be used to signalize refresh the LSI watchdog and window watchdog at main */
#define SYSTICK_10ms_TB      ((uint32_t)10uL) /* 10*1ms */

#define LSI_Min              18570u // LSI - 54%
#define LSI_Max              69190u // LSI + 73%

#define HSI_Min              60937u // HSI/128 - 2.5%
#define HSI_Max              64063u // HSI/128 + 2.5%

#define HSE_Min              60937u // HSE/128 - 2.5%
#define HSE_Max              64063u // HSE/128 + 2.5%

#define LSI_INCAP            1u // Clock self-check using HSI(or HSE) and LSI, MCO = LSI
//#define HSI_INCAP            2u // Clock self-check using HSE and HSI, MCO = HSI/4
//#define HSE_INCAP            3u // Clock self-check using HSI and HSE, MCO = HSE

#if defined(__CC_ARM) || defined(__GNUC__)  /* Keil MDK AC(ARM Compiler) 5 or 6 */
/* Constants necessary for execution initial March test */
#define RAM_START              ((uint32_t *)0x20000000uL)
EXTERN  void $Super$$main(void);
#define CRC_FLAG               CRC->IDR
#define GotoCompilerStartUp()  { CRC_FLAG = 0xAAu; __main(); } /* entry to init C before main() */

/* This is the KEIL compiler entry point, usually executed right after reset */
extern void Reset_Handler(void);
extern const uint32_t __Check_Sum;
extern void __main(void);
extern uint32_t Load$$LR$$LR_IROM1$$Base,Load$$LR$$LR_IROM1$$Length,Load$$LR$$LR_IROM1$$Limit;
#define ROM_START             ((uint32_t)&Load$$LR$$LR_IROM1$$Base)
#define CODE_SIZE             ((uint32_t)&Load$$LR$$LR_IROM1$$Length)
#define CODE_END              ((uint32_t)&Load$$LR$$LR_IROM1$$Limit)
#endif /* __CC_ARM || __GNUC__*/

#ifdef __IAR_SYSTEMS_ICC__  /* Using IAR Compiler */
extern void __iar_program_start(void);
#define GotoCompilerStartUp()   { __iar_program_start(); }
/* The 4 variables here above are set by IAR linker */
extern uint32_t __ICFEDIT_region_ROM_start__;
extern uint32_t __ICFEDIT_region_ROM_end__;
extern uint32_t __ICFEDIT_region_RAM_start__;
extern uint32_t __ICFEDIT_region_RAM_end__;
extern uint32_t __ICFEDIT_region_CLASSB_start__;
extern uint32_t __ICFEDIT_region_CLASSB_end__;

#pragma section = ".intvec"
#pragma section = ".data_init"
/* Constants necessary for Flash CRC calculation  (last block - 64 bytes - separated for CRC) */
#define ROM_START             ((uint32_t)__section_begin(".intvec"))
#define CODE_END              ((uint32_t)__section_end(".data_init"))
/* Constants necessary for Full March tests */
#define RAM_START             (uint32_t *)&__ICFEDIT_region_RAM_start__
#define RAM_END               (uint32_t *)&__ICFEDIT_region_RAM_end__
/* Constants necessary for Transparent March tests */
#define CLASS_B_START         ((uint32_t *)(&__ICFEDIT_region_CLASSB_start__))
#define CLASS_B_END           ((uint32_t *)aStackOverFlowPtrn - 4)
#define REF_CRC32             ROM_END
#endif  /* __IAR_SYSTEMS_ICC__ */

#define CRC_BLOCK_BYTE        64u
#define ROM_END               ((uint32_t)((CODE_END & (CRC_BLOCK_BYTE - 1))?((CODE_END + CRC_BLOCK_BYTE) &(~(CRC_BLOCK_BYTE - 1))):CODE_END))
#define ROM_SIZE              (ROM_END - ROM_START)
#define ROM_SIZEinWORDS       (uint32_t) (ROM_SIZE/(CRC_BLOCK_BYTE/16))
#define STEPS_NUMBER          ((uint32_t)ROM_SIZE/CRC_BLOCK_BYTE)
#define FLASH_BLOCK_WORDS     (uint32_t)((ROM_SIZEinWORDS)/STEPS_NUMBER)
#define REF_CRC32             ROM_END

#define MCU_RAM_BuffertestEnd_ADDR     (0x20000000UL + 32UL - 1UL)
#define MCU_RAM_RunTimetestStart_ADDR  (0x20000030UL)
#define MCU_RAM_RunTimetestEnd_ADDR    (0x2000007FUL)
#define MCU_RAM_End_ADDR               (0x20000FFFUL)

/* -------------------------------------------------------------------------- */
/* ------------------ CONTROL FLOW TAGS and CHECKPOINTS --------------------- */
/* -------------------------------------------------------------------------- */
/* RAM_TEST_CALLEE is only needed for CtrlFlowCntInv when exiting routine */
/* This is because the RAM test routines destroys the control flow counters */
#define RAM_TEST_CALLEE         ((uint32_t)0xFFFFFFFFuL)

#define CPU_TEST_CALLER         ((uint32_t)2)
#define CPU_TEST_CALLEE         ((uint32_t)3) /* Do not modify: hard coded in assembly file */
#define WDG_TEST_CALLER         ((uint32_t)5)
#define CRC32_INIT_CALLER       ((uint32_t)7)
#define CRC32_TEST_CALLER       ((uint32_t)11)
#define CRC32_TEST_CALLEE       ((uint32_t)13)
#define CRC_TEST_CALLER         ((uint32_t)17)
#define CRC_STORE_CALLER        ((uint32_t)19)
#define CLOCK_TEST_CALLER       ((uint32_t)23)
#define CLOCK_TEST_CALLEE       ((uint32_t)29)
#define LSI_INIT_CALLEE         ((uint32_t)31)
#define HSE_INIT_CALLEE         ((uint32_t)37)
#define RTC_INIT_CALLEE         ((uint32_t)41)
#define SYSTICK_INIT_CALLEE     ((uint32_t)43)
#define CLOCK_SWITCH_CALLEE     ((uint32_t)47)
#define STACK_OVERFLOW_TEST     ((uint32_t)53)
#define STACK_OVERFLOW_CALLEE   ((uint32_t)59)
#define CLOCKPERIOD_TEST_CALLEE ((uint32_t)61)
#define FLASH_TEST_CALLER       ((uint32_t)63)
#define CRC32_RUN_TEST_CALLEE   ((uint32_t)63)
#define Inter_error             ((uint32_t)80)

#define CHECKPOINT1 ((uint32_t)CPU_TEST_CALLER + \
                     CPU_TEST_CALLEE +           \
                     WDG_TEST_CALLER +           \
                     CRC32_TEST_CALLER +         \
                     CRC_TEST_CALLER)

#define CHECKPOINT2 ((uint32_t)CRC_STORE_CALLER + \
                     CLOCK_TEST_CALLER +          \
                     CLOCK_TEST_CALLEE +          \
                     STACK_OVERFLOW_TEST)

/* This is for run-time tests with 32-bit CRC */
#define DELTA_MAIN ((uint32_t)CPU_TEST_CALLER + \
                    CPU_TEST_CALLEE +           \
                    STACK_OVERFLOW_TEST +       \
                    STACK_OVERFLOW_CALLEE +     \
                    CLOCK_TEST_CALLER +         \
                    CLOCKPERIOD_TEST_CALLEE +   \
                    FLASH_TEST_CALLER +         \
                    CRC32_RUN_TEST_CALLEE)

#define LAST_DELTA_MAIN  ((uint32_t)DELTA_MAIN + CRC32_INIT_CALLER)

#define MEASPERIOD_ISR_CALLER  ((uint32_t)2)
#define MEASPERIOD_ISR_CALLEE  ((uint32_t)3)
#define CLOCKPERIOD_ISR_CALLEE ((uint32_t)5)
#define RAM_MARCHC_ISR_CALLER  ((uint32_t)7)
#define RAM_MARCHC_ISR_CALLEE  ((uint32_t)11)

/* This is for March C tests */
#define DELTA_ISR (uint32_t)(RAM_MARCHC_ISR_CALLER + \
                             RAM_MARCHC_ISR_CALLEE)

/* Exported macro ------------------------------------------------------------*/
#define init_control_flow()    (CtrlFlowCntInv = ~(CtrlFlowCnt = 0))
#define control_flow_call(a)   CtrlFlowCnt += (a)
#define control_flow_resume(a) CtrlFlowCntInv -= (a)

/* Exported functions ------------------------------------------------------- */
void FailSafePOR(uint32_t E_ID);
ErrorStatus control_flow_check_point(uint32_t chck);

#endif /* __SELFTEST_PARAM_H */
/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
