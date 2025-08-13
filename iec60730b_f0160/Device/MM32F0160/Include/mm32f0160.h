/*
 *******************************************************************************
    @file     mm32f0160.h
    @author   AE TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE ADC
              FIRMWARE LIBRARY.
 *******************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its
       contributors may be used to endorse or promote products derived from this
       software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES,INCLUDING, BUT NOT LIMITED TO,
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __MM32F0160_H
#define __MM32F0160_H


#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

#ifndef HSE_VALUE
#define HSE_VALUE                       (8000000U)                              /*!< Value of the External High oscillator in Hz. */
#endif

#ifndef HSE_STARTUP_TIMEOUT
#define HSE_STARTUP_TIMEOUT             (0x0500U)                               /*!< Time out for HSE start up. */
#endif

#ifndef HSI_PLLSRC_VALUE
#define HSI_PLLSRC_VALUE                (8000000U)                              /*!< Value of the PLL Source Frequence in Hz. */
#endif
#define HSI_VALUE_PLL_ON                HSI_PLLSRC_VALUE

#ifndef HSI_SYSCLKSRC_VALUE
#define HSI_SYSCLKSRC_VALUE             (8000000U)                              /*!< Value of the High Internal oscillator in Hz. */
/* legacy define */
#ifndef HSI_VALUE
#define HSI_VALUE                       HSI_SYSCLKSRC_VALUE
#endif
#endif

#ifndef LSI_VALUE
#define LSI_VALUE                       (40000U)                                /*!< Value of the Low Internal oscillator in Hz. */
#endif


#define HSI_Value_Pll_OFF    ((uint32_t)8000000) /*!< Value of the Internal oscillator in Hz*/
/* #define HSI_Value_Pll_OFF    ((uint32_t)20000000) */ /*!< for test*/
/* #define HSI_Value_Pll_OFF    ((uint32_t)50000000) */
#define HSI_VALUE_PLL_OFF   HSI_Value_Pll_OFF


#define __MPU_PRESENT                   (0)                                     /*!< Cortex-M0 does not provide a MPU present or not */
#ifndef __NVIC_PRIO_BITS
#define __NVIC_PRIO_BITS                (2)                                     /*!< Cortex-M0 uses 2 Bits for the Priority Levels */
/* #warning "__NVIC_PRIO_BITS not defined in device header file; using default!" */
#endif
#define __Vendor_SysTickConfig          (0)                                     /*!< Set to 1 if different SysTick Config is used */

/**
  * @brief  MM32 MCU Interrupt Handle
  */
typedef enum IRQn {
    NonMaskableInt_IRQn                 = -14,                                  /*!< 2 Non Maskable Interrupt */
    HardFault_IRQn                      = -13,                                  /*!< 3 Cortex-M0 Hard Fault Interrupt */
    SVC_IRQn                            = -5,                                   /*!< 11 Cortex-M0 SV Call Interrupt */
    DebugMonitor_IRQn                   = -4,                                   /*!< 12 Cortex-M0 Debug Monitor Interrupt */
    PendSV_IRQn                         = -2,                                   /*!< 14 Cortex-M0 Pend SV Interrupt */
    SysTick_IRQn                        = -1,                                   /*!< 15 Cortex-M0 System Tick Interrupt */

    WWDG_IWDG_IRQn                      = 0,                                    /*!< WatchDog Interrupt */
    PVD_IRQn                            = 1,                                    /*!< PVD through EXTI Line detect Interrupt */
    RTC_BKP_IRQn                        = 2,                                    /*!< RTC_BKP */
    FLASH_IRQn                          = 3,                                    /*!< FLASH Interrupt */
    RCC_IRQn                            = 4,                                    /*!< RCC Interrupt */
    EXTI0_1_IRQn                        = 5,                                    /*!< EXTI Line 0 and 1 Interrupts */
    EXTI2_3_IRQn                        = 6,                                    /*!< EXTI Line 2 and 3 Interrupts */
    EXTI4_15_IRQn                       = 7,                                    /*!< EXTI Line 4 to 15 Interrupts */
    HARDDIV_IRQn                        = 8,                                    /*!< HWDIV Global Interrupt */
    DMA1_Channel1_IRQn                  = 9,                                    /*!< DMA1 Channel 1 Interrupt */
    DMA1_Channel2_3_IRQn                = 10,                                   /*!< DMA1 Channel 2 and Channel 3 Interrupts */
    DMA1_Channel4_7_IRQn                = 11,                                   /*!< DMA1 Channel 4 and Channel 7 Interrupts */
    ADC_COMP_IRQn                       = 12,                                   /*!< ADC & COMP Interrupts */
    TIM1_BRK_UP_TRG_COM_IRQn            = 13,                                   /*!< TIM1 Break, Update, Trigger and Commutation Interrupts */
    TIM1_CC_IRQn                        = 14,                                   /*!< TIM1 Capture Compare Interrupt */
    TIM2_IRQn                           = 15,                                   /*!< TIM2 Interrupt */
    TIM3_IRQn                           = 16,                                   /*!< TIM3 Interrupt */
    LPUART1_IRQn                        = 17,                                   /*!< LPUART1 interrupt */
    LPTIM1_IRQn                         = 18,                                   /*!< LPTIM1 interrupt */
    TIM14_IRQn                          = 19,                                   /*!< TIM14 Interrupt */
    TIM16_IRQn                          = 21,                                   /*!< TIM16 Interrupt */
    TIM17_IRQn                          = 22,                                   /*!< TIM17 Interrupt */
    I2C1_IRQn                           = 23,                                   /*!< I2C1 Interrupt */
    I3C1_IRQn                           = 24,                                   /*!< I3C1 interrupt */
    SPI1_IRQn                           = 25,                                   /*!< SPI1 Interrupt */
    SPI2_IRQn                           = 26,                                   /*!< SPI2 Interrupt */
    UART1_IRQn                          = 27,                                   /*!< UART1 Interrupt */
    UART2_IRQn                          = 28,                                   /*!< UART2 Interrupt */
    UART3_UART4_IRQn                    = 29,                                   /*!< UART3 & UART4 Interrupt */
    FLEX_CAN_IRQn                       = 30,                                   /*!< FLEX_CAN Interrupt */
    USB_IRQn                            = 31,                                   /*!< USB interrupt */
} IRQn_Type;


#include <core_cm0.h>
#include <stdint.h>
#include <stdbool.h>


typedef int64_t u64;
typedef uint64_t s64;
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

typedef bool                            BOOL;

#ifndef NULL
#define NULL                            ((void *)0)
#endif

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
#define IS_FUNCTIONAL_STATE(STATE)      (((STATE) == DISABLE) || ((STATE) == ENABLE))

#define U8_MAX                          ((u8)255)
#define S8_MAX                          ((s8)127)
#define S8_MIN                          ((s8)-128)
#define U16_MAX                         ((u16)65535u)
#define S16_MAX                         ((s16)32767)
#define S16_MIN                         ((s16)-32768)
#define U32_MAX                         ((u32)4294967295uL)
#define S32_MAX                         ((s32)2147483647)
#define S32_MIN                         ((s32)-2147483648uL)

#define MAX(a,b)                        ((a)>(b)?(a):(b))
#define MIN(a,b)                        ((a)<(b)?(a):(b))

#define SET_BIT(reg, bit)               ((reg) = (reg)|(bit))
#define CLEAR_BIT(reg, bit)             ((reg) = (reg) & (~(bit)))
#define READ_BIT(reg, bit)              ((reg) & (bit))
#define CLEAR_REG(reg)                  ((reg) = (0x0))
#define WRITE_REG(reg, value)           ((reg) = (value))
#define READ_REG(reg)                   ((reg))
#define MODIFY_REG(reg, MASK_CLEAR, SET_BITS) WRITE_REG((reg), (((READ_REG(reg)) & (~(MASK_CLEAR))) | ((SET_BITS) & (MASK_CLEAR))))

#define SET_BIT_W_CHECK(reg, SET_BITS)                                          \
    do{                                                                         \
        SET_BIT(reg, SET_BITS);                                                 \
        while(READ_BIT(reg, SET_BITS) != (SET_BITS)) {                          \
        }                                                                       \
    } while(0)
#define CLEAR_BIT_W_CHECK(reg, SET_BITS)                                        \
    do{                                                                         \
        CLEAR_BIT(reg, SET_BITS);                                               \
        while(READ_BIT(reg, SET_BITS) != (0)) {                                 \
        }                                                                       \
    } while(0)

#define MODIFY_REG_W_CHECK(reg, MASK_CLEAR, SET_BITS)                           \
    do{                                                                         \
        WRITE_REG((reg), (((READ_REG(reg)) & (~(MASK_CLEAR))) |                 \
        ((SET_BITS) & (MASK_CLEAR))));                                          \
        while(((READ_REG(reg))&MASK_CLEAR) != ((SET_BITS) & (MASK_CLEAR))) {    \
        }                                                                       \
    } while(0)

#define MODIFY_FIELD(reg, FIELD_STEP, FIELD_GROUP, FIELD_BITS) WRITE_REG((reg), (((READ_REG(reg)) & (~(((0x01UL<<(FIELD_STEP))-1)<<((FIELD_GROUP)*(FIELD_STEP))))) | (((FIELD_BITS) & ((0x01UL<<(FIELD_STEP))-1))<<((FIELD_GROUP)*(FIELD_STEP)))))
#define READ_FIELD(reg, FIELD_STEP, FIELD_GROUP) (((READ_REG(reg))>>((FIELD_GROUP)*(FIELD_STEP))) & (((0x01UL<<(FIELD_STEP))-1)))
#define POSITION_VAL(value)             (__CLZ(__RBIT(value)))

#ifndef LEFT_SHIFT_BIT
#define LEFT_SHIFT_BIT(x)               (1 << x)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)                   (sizeof(x) / sizeof((x)[0]))
#endif


#define PERIPH_BASE                     (0x40000000U)                           /*!< Peripheral base address in the alias region */
#define APB1PERIPH_BASE                 (PERIPH_BASE + 0x00000000)
#define APB2PERIPH_BASE                 (PERIPH_BASE + 0x00010000)
#define AHBPERIPH_BASE                  (PERIPH_BASE + 0x00020000)



#include "reg_adc.h"
#include "reg_bkp.h"
#include "reg_comp.h"
#include "reg_core.h"
#include "reg_crc.h"
#include "reg_crs.h"
#include "reg_dbg.h"
#include "reg_hwdiv.h"
#include "reg_dma.h"
#include "reg_exti.h"
#include "reg_flexcan.h"
#include "reg_flash.h"
#include "reg_gpio.h"
#include "reg_i2c.h"
#include "reg_i3c.h"
#include "reg_iwdg.h"
#include "reg_lptim.h"
#include "reg_lpuart.h"
#include "reg_pwr.h"
#include "reg_rcc.h"
#include "reg_rtc.h"
#include "reg_spi.h"
#include "reg_syscfg.h"
#include "reg_tim.h"
#include "reg_uart.h"
#include "reg_usb.h"
#include "reg_wwdg.h"


#include "hal_conf.h"


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------*/
#endif
/*----------------------------------------------------------------------------*/
