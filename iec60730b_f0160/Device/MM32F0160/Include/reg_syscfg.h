/*
 *******************************************************************************
    @file     reg_syscfg.h
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

#ifndef __REG_SYSCFG_H
#define __REG_SYSCFG_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

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
/* anonymous unions are enabled by default -----------------------------------*/
#else
#warning Not supported compiler type
#endif

#define SYSCFG_BASE                     (APB2PERIPH_BASE + 0x0000)              /*!< Base Address: 0x40010000 */

/**
  * @brief SysTem Configuration Register Structure Definition
  */
typedef struct {
    union {
        __IO uint32_t CFGR;                                                     /*!< SYSCFG configuration register                  offset: 0x00 */
        __IO uint32_t CFGR1;
    };
    __IO uint32_t RESERVED0x04;                                                 /*!< RESERVED register                              offset: 0x04 */
    __IO uint32_t EXTICR[4];                                                    /*!< EXTI Control register                          offset: 0x08-0x14 */
    __IO uint32_t PADHYS;                                                       /*!< PADHYS register                                offset: 0x18 */
} SYSCFG_TypeDef;

#define SYSCFG                          ((SYSCFG_TypeDef *) SYSCFG_BASE)

/**
  * @brief System Configuration (SYSCFG)
  */

/**
  * @brief SYSCFG_CFGR Register Bit definition
  */
#define SYSCFG_CFGR_MEM_MODE_Pos        (0)
#define SYSCFG_CFGR_MEM_MODE_Msk        ((uint32_t)0x00000003)                              /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR_MEM_MODE_0          ((uint32_t)0x00000001)                              /*!< SYSCFG_Memory Remap Config Bit 0 */
#define SYSCFG_CFGR_MEM_MODE_1          ((uint32_t)0x00000002)                              /*!< SYSCFG_Memory Remap Config Bit 1 */
#define SYSCFG_CFGR_ADC_DMA_RMP_Pos     (8)
#define SYSCFG_CFGR_ADC_DMA_RMP         (0x01U  << SYSCFG_CFGR_ADC_DMA_RMP_Pos)             /*!< ADC DMA remap */
#define SYSCFG_CFGR_UART1TX_DMA_RMP_Pos (9)
#define SYSCFG_CFGR_UART1TX_DMA_RMP     (0x01U  << SYSCFG_CFGR_UART1TX_DMA_RMP_Pos)         /*!< UART1 TX DMA remap */
#define SYSCFG_CFGR_UART1RX_DMA_RMP_Pos (10)
#define SYSCFG_CFGR_UART1RX_DMA_RMP     (0x01U  << SYSCFG_CFGR_UART1RX_DMA_RMP_Pos)         /*!< UART1 RX DMA remap */
#define SYSCFG_CFGR_TIM16_DMA_RMP_Pos   (11)
#define SYSCFG_CFGR_TIM16_DMA_RMP       (0x01U  << SYSCFG_CFGR_TIM16_DMA_RMP_Pos)           /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR_TIM17_DMA_RMP_Pos   (12)
#define SYSCFG_CFGR_TIM17_DMA_RMP       (0x01U  << SYSCFG_CFGR_TIM17_DMA_RMP_Pos)           /*!< Timer 17 DMA remap */

#define SYSCFG_CFGR_MIPI_RX_DMA_REMAP_Pos   (31)
#define SYSCFG_CFGR_MIPI_RX_DMA_REMAP       (0x01U  << SYSCFG_CFGR_MIPI_RX_DMA_REMAP_Pos)   /*!< PDMA request remapping bit of MIPI_RX */

/**
  * @brief SYSCFG_EXTICR1 Register Bit definition
  */
#define SYSCFG_EXTICR1_EXTI0            ((uint16_t)0x000F)                      /*!< EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1            ((uint16_t)0x00F0)                      /*!< EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2            ((uint16_t)0x0F00)                      /*!< EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3            ((uint16_t)0xF000)                      /*!< EXTI 3 configuration */

/**
  * @brief  EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA         ((uint16_t)0x0000)                      /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB         ((uint16_t)0x0001)                      /*!< PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC         ((uint16_t)0x0002)                      /*!< PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD         ((uint16_t)0x0003)                      /*!< PD[0] pin */

/**
  * @brief  EXTI1 configuration
  */
#define SYSCFG_EXTICR1_EXTI1_PA         ((uint16_t)0x0000)                      /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         ((uint16_t)0x0010)                      /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         ((uint16_t)0x0020)                      /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         ((uint16_t)0x0030)                      /*!< PD[1] pin */

/**
  * @brief  EXTI2 configuration
  */
#define SYSCFG_EXTICR1_EXTI2_PA         ((uint16_t)0x0000)                      /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         ((uint16_t)0x0100)                      /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         ((uint16_t)0x0200)                      /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         ((uint16_t)0x0300)                      /*!< PD[2] pin */

/**
  * @brief  EXTI3 configuration
  */
#define SYSCFG_EXTICR1_EXTI3_PA         ((uint16_t)0x0000)                      /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         ((uint16_t)0x1000)                      /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         ((uint16_t)0x2000)                      /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         ((uint16_t)0x3000)                      /*!< PD[3] pin */

/**
  * @brief SYSCFG_EXTICR2 Register Bit definition
  */
#define SYSCFG_EXTICR2_EXTI4            ((uint16_t)0x000F)                      /*!< EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5            ((uint16_t)0x00F0)                      /*!< EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6            ((uint16_t)0x0F00)                      /*!< EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7            ((uint16_t)0xF000)                      /*!< EXTI 7 configuration */

/**
  * @brief  EXTI4 configuration
  */
#define SYSCFG_EXTICR2_EXTI4_PA         ((uint16_t)0x0000)                      /*!< PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB         ((uint16_t)0x0001)                      /*!< PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC         ((uint16_t)0x0002)                      /*!< PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD         ((uint16_t)0x0003)                      /*!< PD[4] pin */

/**
  * @brief  EXTI5 configuration
  */
#define SYSCFG_EXTICR2_EXTI5_PA         ((uint16_t)0x0000)                      /*!< PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB         ((uint16_t)0x0010)                      /*!< PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC         ((uint16_t)0x0020)                      /*!< PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD         ((uint16_t)0x0030)                      /*!< PD[5] pin */

/**
  * @brief  EXTI6 configuration
  */
#define SYSCFG_EXTICR2_EXTI6_PA         ((uint16_t)0x0000)                      /*!< PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB         ((uint16_t)0x0100)                      /*!< PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC         ((uint16_t)0x0200)                      /*!< PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD         ((uint16_t)0x0300)                      /*!< PD[6] pin */

/**
  * @brief  EXTI7 configuration
  */
#define SYSCFG_EXTICR2_EXTI7_PA         ((uint16_t)0x0000)                      /*!< PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB         ((uint16_t)0x1000)                      /*!< PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC         ((uint16_t)0x2000)                      /*!< PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD         ((uint16_t)0x3000)                      /*!< PD[7] pin */

/**
  * @brief SYSCFG_EXTICR3 Register Bit definition
  */
#define SYSCFG_EXTICR3_EXTI8            ((uint16_t)0x000F)                      /*!< EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9            ((uint16_t)0x00F0)                      /*!< EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10           ((uint16_t)0x0F00)                      /*!< EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11           ((uint16_t)0xF000)                      /*!< EXTI 11 configuration */

/**
  * @brief  EXTI8 configuration
  */
#define SYSCFG_EXTICR3_EXTI8_PA         ((uint16_t)0x0000)                      /*!< PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB         ((uint16_t)0x0001)                      /*!< PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC         ((uint16_t)0x0002)                      /*!< PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD         ((uint16_t)0x0003)                      /*!< PD[8] pin */

/**
  * @brief  EXTI9 configuration
  */
#define SYSCFG_EXTICR3_EXTI9_PA         ((uint16_t)0x0000)                      /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         ((uint16_t)0x0010)                      /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         ((uint16_t)0x0020)                      /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         ((uint16_t)0x0030)                      /*!< PD[9] pin */

/**
  * @brief  EXTI10 configuration
  */
#define SYSCFG_EXTICR3_EXTI10_PA        ((uint16_t)0x0000)                      /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        ((uint16_t)0x0100)                      /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        ((uint16_t)0x0200)                      /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        ((uint16_t)0x0300)                      /*!< PD[10] pin */

/**
  * @brief  EXTI11 configuration
  */
#define SYSCFG_EXTICR3_EXTI11_PA        ((uint16_t)0x0000)                      /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        ((uint16_t)0x1000)                      /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        ((uint16_t)0x2000)                      /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        ((uint16_t)0x3000)                      /*!< PD[11] pin */

/**
  * @brief SYSCFG_EXTICR4 Register Bit definition
  */
#define SYSCFG_EXTICR4_EXTI12           ((uint16_t)0x000F)                      /*!< EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13           ((uint16_t)0x00F0)                      /*!< EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14           ((uint16_t)0x0F00)                      /*!< EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15           ((uint16_t)0xF000)                      /*!< EXTI 15 configuration */

#define SYSCFG_EXTICR4_EXTI12_PA        ((uint16_t)0x0000)                      /*!< PA[12] pin for EXTI12 */
#define SYSCFG_EXTICR4_EXTI12_PB        ((uint16_t)0x0001)                      /*!< PB[12] pin for EXTI12 */
#define SYSCFG_EXTICR4_EXTI12_PC        ((uint16_t)0x0002)                      /*!< PC[12] pin for EXTI12 */
#define SYSCFG_EXTICR4_EXTI12_PD        ((uint16_t)0x0003)                      /*!< PD[12] pin for EXTI12 */

#define SYSCFG_EXTICR4_EXTI13_PA        ((uint16_t)0x0000)                      /*!< PA[13] pin for EXTI13 */
#define SYSCFG_EXTICR4_EXTI13_PB        ((uint16_t)0x0010)                      /*!< PB[13] pin for EXTI13 */
#define SYSCFG_EXTICR4_EXTI13_PC        ((uint16_t)0x0020)                      /*!< PC[13] pin for EXTI13 */
#define SYSCFG_EXTICR4_EXTI13_PD        ((uint16_t)0x0030)                      /*!< PD[13] pin for EXTI13 */

#define SYSCFG_EXTICR4_EXTI14_PA        ((uint16_t)0x0000)                      /*!< PA[14] pin for EXTI14 */
#define SYSCFG_EXTICR4_EXTI14_PB        ((uint16_t)0x0100)                      /*!< PB[14] pin for EXTI14 */
#define SYSCFG_EXTICR4_EXTI14_PC        ((uint16_t)0x0200)                      /*!< PC[14] pin for EXTI14 */
#define SYSCFG_EXTICR4_EXTI14_PD        ((uint16_t)0x0300)                      /*!< PD[14] pin for EXTI14 */

#define SYSCFG_EXTICR4_EXTI15_PA        ((uint16_t)0x0000)                      /*!< PA[15] pin for EXTI15 */
#define SYSCFG_EXTICR4_EXTI15_PB        ((uint16_t)0x1000)                      /*!< PB[15] pin for EXTI15 */
#define SYSCFG_EXTICR4_EXTI15_PC        ((uint16_t)0x2000)                      /*!< PC[15] pin for EXTI15 */
#define SYSCFG_EXTICR4_EXTI15_PD        ((uint16_t)0x3000)                      /*!< PD[15] pin for EXTI15 */

#define SYSCFG_PADHYS_I2C1_MODE_SEL_Pos (16)
#define SYSCFG_PADHYS_I2C1_MODE_SEL     (0x01U  << SYSCFG_PADHYS_I2C1_MODE_SEL_Pos)                   /*!< I2C1 Enable PushPull mode */
#define SYSCFG_PADHYS_I2C2_MODE_SEL_Pos (17)
#define SYSCFG_PADHYS_I2C2_MODE_SEL     (0x01U  << SYSCFG_PADHYS_I2C2_MODE_SEL_Pos)                   /*!< I2C2 Enable PushPull mode */

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
