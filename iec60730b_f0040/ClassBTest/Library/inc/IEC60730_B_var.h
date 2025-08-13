/**
 ******************************************************************************
 * @file    IEC60730_B_var.h
 * @author
 * @version V1.2.0
 * @date    19-June-2019
 * @brief   Contains all safety critical variables; they must have
 *          predefined addresses and inverse redundant storage
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
#ifndef __IEC60730_B_VAR_H
#define __IEC60730_B_VAR_H

/* This avoids having multiply defined global variables */
#ifdef ALLOC_GLOBALS
#define EXTERN
#else
#define EXTERN extern
#endif

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
/* RAM location for temporary storage of original values at run time RAM transparent test */
EXTERN __no_init uint32_t aRunTimeRamBuf[RT_RAM_BLOCKSIZE + 2U] @ "RUN_TIME_RAM_BUF";

/* pointers for run time RAM transparent test */
EXTERN __no_init uint32_t *pRunTimeRamChk @ "x`";
EXTERN __no_init uint32_t *pRunTimeRamChkInv @ "RUN_TIME_RAM_PNT";
EXTERN __no_init uint32_t aGAP_FOR_RAM_TEST_OVERLAY[2] @ "RUN_TIME_RAM_PNT";

/* Class B non inverted variables area */
EXTERN __no_init uint32_t CtrlFlowCnt @ "CLASS_B_RAM";        /* Counter for verifying correct program execution at start */
EXTERN __no_init uint32_t ISRCtrlFlowCnt @ "CLASS_B_RAM";     /* Counter for verifying correct program execution in interrupt */
EXTERN __no_init uint32_t PeriodValue @ "CLASS_B_RAM";        /* LSI period measurement at TIM5 IRQHandler */
EXTERN __no_init uint32_t TickCounter @ "CLASS_B_RAM";        /* Software time base used in main program (incremented in SysTick timer ISR */
EXTERN __no_init __IO uint32_t TimeBaseFlag @ "CLASS_B_RAM";  /* Indicates to the main routine a 100ms tick */
EXTERN __no_init __IO uint32_t LSIPeriodFlag @ "CLASS_B_RAM"; /* Indicates to the main routine a 100ms tick */
EXTERN __no_init uint32_t LastCtrlFlowCnt @ "CLASS_B_RAM";    /* Stores the Control flow counter from one main loop to the other */
EXTERN __no_init uint32_t *pRunCrc32Chk @ "CLASS_B_RAM";      /* Pointer to FLASH for crc32 run-time tests */
EXTERN __no_init uint32_t RefCrc32 @ "CLASS_B_RAM";           /* Reference 32-bit CRC for run-time tests */
EXTERN __no_init uint32_t Incap_Freq @ "CLASS_B_RAM";

/* Class B inverted variables area */
EXTERN __no_init uint32_t CtrlFlowCntInv @ "CLASS_B_RAM_REV";
EXTERN __no_init uint32_t ISRCtrlFlowCntInv @ "CLASS_B_RAM_REV";
EXTERN __no_init uint32_t PeriodValueInv @ "CLASS_B_RAM_REV";
EXTERN __no_init uint32_t TickCounterInv @ "CLASS_B_RAM_REV";
EXTERN __no_init __IO uint32_t TimeBaseFlagInv @ "CLASS_B_RAM_REV";
EXTERN __no_init __IO uint32_t LSIPeriodFlagInv @ "CLASS_B_RAM_REV";
EXTERN __no_init uint32_t LastCtrlFlowCntInv @ "CLASS_B_RAM_REV";
EXTERN __no_init uint32_t *pRunCrc32ChkInv @ "CLASS_B_RAM_REV";
EXTERN __no_init uint32_t RefCrc32Inv @ "CLASS_B_RAM_REV";

/* Magic pattern for Stack overflow in this array */
EXTERN __no_init __IO uint32_t aStackOverFlowPtrn[4] @ "STACK_BOTTOM";
EXTERN uint32_t Error_word;
#endif /* __IAR_SYSTEMS_ICC__ */

#ifdef __CC_ARM /* KEIL Compiler AC5 */
/* RAM location for temporary storage of original values at run time RAM transparent test */
EXTERN uint32_t aRunTimeRamBuf[RT_RAM_BLOCKSIZE + 2] __attribute__((section("RUN_TIME_RAM_BUF")));

/* RAM pointer for run-time tests */
EXTERN uint32_t *pRunTimeRamChk __attribute__((section("RUN_TIME_RAM_PNT")));
EXTERN uint32_t *pRunTimeRamChkInv __attribute__((section("RUN_TIME_RAM_PNT")));
EXTERN uint32_t aGAP_FOR_RAM_TEST_OVERLAY[2] __attribute__((section("RUN_TIME_RAM_PNT")));

/* Note: the zero_init forces the linker to place variables in the bss section */
/* This allows the UNINIT directive (in scatter file) to work. On the contrary */
/* all Class B variables pairs should be initialized properly by user before using them */

/* Counter for verifying correct program execution at start */
EXTERN uint32_t CtrlFlowCnt __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t CtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Counter for verifying correct program execution in interrupt */
EXTERN uint32_t ISRCtrlFlowCnt __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t ISRCtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* LSI period measurement at TIM5 IRQHandler */
EXTERN uint32_t PeriodValue __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t PeriodValueInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Sofware time base used in main program (incremented in SysTick timer ISR */
EXTERN uint32_t TickCounter __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t TickCounterInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Indicates to the main routine a 100ms tick */
EXTERN __IO uint32_t TimeBaseFlag __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN __IO uint32_t TimeBaseFlagInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Indicates to the main routine a 100ms tick */
EXTERN __IO uint32_t LSIPeriodFlag __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN __IO uint32_t LSIPeriodFlagInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Stores the Control flow counter from one main loop to the other */
EXTERN uint32_t LastCtrlFlowCnt __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t LastCtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Pointer to FLASH for crc32 run-time tests */
EXTERN uint32_t *pRunCrc32Chk __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t *pRunCrc32ChkInv __attribute__((section("CLASS_B_RAM_REV"), zero_init));

/* Reference 32-bit CRC for run-time tests */
EXTERN uint32_t RefCrc32 __attribute__((section("CLASS_B_RAM"), zero_init));
EXTERN uint32_t RefCrc32Inv __attribute__((section("CLASS_B_RAM_REV"), zero_init));
EXTERN uint32_t Incap_Freq __attribute__((section("CLASS_B_RAM"), zero_init));
/* Magic pattern for Stack overflow in this array */
EXTERN __IO uint32_t aStackOverFlowPtrn[4] __attribute__((section("STACK_BOTTOM"), zero_init));
EXTERN uint32_t Error_word;
#endif /* __CC_ARM */

#ifdef __GNUC__ /* Keil AC6 or GCC Compiler */
#ifndef ALLOC_GLOBALS
/* RAM location for temporary storage of original values at run time RAM transparent test */
extern uint32_t aRunTimeRamBuf[RT_RAM_BLOCKSIZE + 2] __attribute__((section("RUN_TIME_RAM_BUF")));

/* RAM pointer for run-time tests */
extern uint32_t *pRunTimeRamChk __attribute__((section("RUN_TIME_RAM_PNT")));
extern uint32_t *pRunTimeRamChkInv __attribute__((section("RUN_TIME_RAM_PNT")));
extern uint32_t aGAP_FOR_RAM_TEST_OVERLAY[2] __attribute__((section("RUN_TIME_RAM_PNT")));

/* Note: the zero_init forces the linker to place variables in the bss section */
/* This allows the UNINIT directive (in scatter file) to work. On the contrary */
/* all Class B variables pairs should be initialized properly by user before using them */

/* Counter for verifying correct program execution at start */
extern uint32_t CtrlFlowCnt __attribute__((section("CLASS_B_RAM")));
extern uint32_t CtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV")));

/* Counter for verifying correct program execution in interrupt */
extern uint32_t ISRCtrlFlowCnt __attribute__((section("CLASS_B_RAM")));
extern uint32_t ISRCtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV")));

/* LSI period measurement at TIM5 IRQHandler */
extern uint32_t PeriodValue __attribute__((section("CLASS_B_RAM")));
extern uint32_t PeriodValueInv __attribute__((section("CLASS_B_RAM_REV")));

/* Sofware time base used in main program (incremented in SysTick timer ISR */
extern uint32_t TickCounter __attribute__((section("CLASS_B_RAM")));
extern uint32_t TickCounterInv __attribute__((section("CLASS_B_RAM_REV")));

/* Indicates to the main routine a 100ms tick */
extern __IO uint32_t TimeBaseFlag __attribute__((section("CLASS_B_RAM")));
extern __IO uint32_t TimeBaseFlagInv __attribute__((section("CLASS_B_RAM_REV")));

/* Indicates to the main routine a 100ms tick */
extern __IO uint32_t LSIPeriodFlag __attribute__((section("CLASS_B_RAM")));
extern __IO uint32_t LSIPeriodFlagInv __attribute__((section("CLASS_B_RAM_REV")));

/* Stores the Control flow counter from one main loop to the other */
extern uint32_t LastCtrlFlowCnt __attribute__((section("CLASS_B_RAM")));
extern uint32_t LastCtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV")));

/* Pointer to FLASH for crc32 run-time tests */
extern uint32_t *pRunCrc32Chk __attribute__((section("CLASS_B_RAM")));
extern uint32_t *pRunCrc32ChkInv __attribute__((section("CLASS_B_RAM_REV")));

/* Reference 32-bit CRC for run-time tests */
extern uint32_t RefCrc32 __attribute__((section("CLASS_B_RAM")));
extern uint32_t RefCrc32Inv __attribute__((section("CLASS_B_RAM_REV")));
EXTERN uint32_t Incap_Freq __attribute__((section("CLASS_B_RAM")));

/* Magic pattern for Stack overflow in this array */
extern __IO uint32_t aStackOverFlowPtrn[4] __attribute__((section("STACK_BOTTOM")));
extern uint32_t Error_word;
#else
/* RAM location for temporary storage of original values at run time RAM transparent test */
uint32_t aRunTimeRamBuf[RT_RAM_BLOCKSIZE + 2] __attribute__((section("RUN_TIME_RAM_BUF")));

/* RAM pointer for run-time tests */
uint32_t *pRunTimeRamChk __attribute__((section("RUN_TIME_RAM_PNT")));
uint32_t *pRunTimeRamChkInv __attribute__((section("RUN_TIME_RAM_PNT")));
uint32_t aGAP_FOR_RAM_TEST_OVERLAY[2] __attribute__((section("RUN_TIME_RAM_PNT")));

/* Note: the zero_init forces the linker to place variables in the bss section */
/* This allows the UNINIT directive (in scatter file) to work. On the contrary */
/* all Class B variables pairs should be initialized properly by user before using them */

/* Counter for verifying correct program execution at start */
uint32_t CtrlFlowCnt __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t CtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Counter for verifying correct program execution in interrupt */
uint32_t ISRCtrlFlowCnt __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t ISRCtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* LSI period measurement at TIM5 IRQHandler */
uint32_t PeriodValue __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t PeriodValueInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Sofware time base used in main program (incremented in SysTick timer ISR */
uint32_t TickCounter __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t TickCounterInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Indicates to the main routine a 100ms tick */
__IO uint32_t TimeBaseFlag __attribute__((section("CLASS_B_RAM"))) = {0};
__IO uint32_t TimeBaseFlagInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Indicates to the main routine a 100ms tick */
__IO uint32_t LSIPeriodFlag __attribute__((section("CLASS_B_RAM"))) = {0};
__IO uint32_t LSIPeriodFlagInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Stores the Control flow counter from one main loop to the other */
uint32_t LastCtrlFlowCnt __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t LastCtrlFlowCntInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Pointer to FLASH for crc32 run-time tests */
uint32_t *pRunCrc32Chk __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t *pRunCrc32ChkInv __attribute__((section("CLASS_B_RAM_REV"))) = {0};

/* Reference 32-bit CRC for run-time tests */
uint32_t RefCrc32 __attribute__((section("CLASS_B_RAM"))) = {0};
uint32_t RefCrc32Inv __attribute__((section("CLASS_B_RAM_REV"))) = {0};
uint32_t Incap_Freq __attribute__((section("CLASS_B_RAM"))) = {0};

/* Magic pattern for Stack overflow in this array */
__IO uint32_t aStackOverFlowPtrn[4] __attribute__((section("STACK_BOTTOM"))) = {0};
uint32_t Error_word;
#endif /* ALLOC_GLOBALS */
#endif /* __GNUC__ */

#endif /* IEC60730_B_var.h  */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
