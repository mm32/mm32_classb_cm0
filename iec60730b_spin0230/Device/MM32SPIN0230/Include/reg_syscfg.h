/***********************************************************************************************************************
    @file     reg_syscfg.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/


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
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

#define SYSCFG_BASE                     (APB1PERIPH_BASE + 0x10000) /*!< Base Address: 0x40010000 */

/**
  * @brief SysTem Configuration Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFGR;                 /*!< SYSCFG configuration register                  offset: 0x00 */
    __IO uint32_t RESERVED0x04;         /*!< RESERVED register                              offset: 0x04 */
    __IO uint32_t EXTICR[4];            /*!< EXTI Control register                          offset: 0x08-0x14 */
} SYSCFG_TypeDef;

#define SYSCFG                                        ((SYSCFG_TypeDef *)SYSCFG_BASE)

/**
  * @brief System Configuration (SYSCFG)
  */

/**
  * @brief SYSCFG_CFGR Register Bit definition
  */
#define SYSCFG_CFGR_MEM_MODE_Pos                      (0)
#define SYSCFG_CFGR_MEM_MODE_Msk                      (0x07U << SYSCFG_CFGR_MEM_MODE_Pos)          /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR_MEM_MODE_0                        (0x01U << SYSCFG_CFGR_MEM_MODE_Pos)          /*!< SYSCFG_Memory Remap Config Bit 0 */
#define SYSCFG_CFGR_MEM_MODE_1                        (0x02U << SYSCFG_CFGR_MEM_MODE_Pos)          /*!< SYSCFG_Memory Remap Config Bit 1 */
#define SYSCFG_CFGR_MEM_MODE_2                        (0x04U << SYSCFG_CFGR_MEM_MODE_Pos)          /*!< SYSCFG_Memory Remap Config Bit 1 */

#define SYSCFG_CFGR_ADC1_DMA_RMP_Pos                  (8)
#define SYSCFG_CFGR_ADC1_DMA_RMP                      (0x01U << SYSCFG_CFGR_ADC1_DMA_RMP_Pos)      /*!< ADC DMA remap */
#define SYSCFG_CFGR_USART1_TX_DMA_RMP_Pos             (9)
#define SYSCFG_CFGR_USART1_TX_DMA_RMP                 (0x01U << SYSCFG_CFGR_USART1_TX_DMA_RMP_Pos) /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR_USART1_RX_DMA_RMP_Pos             (10)
#define SYSCFG_CFGR_USART1_RX_DMA_RMP                 (0x01U << SYSCFG_CFGR_USART1_RX_DMA_RMP_Pos) /*!< USART1 RX DMA remap */

/**
  * @brief SYSCFG_EXTICR1 Bit mask
  */
#define SYSCFG_EXTICR1_EXTI0            (0x000FU)                               /*!< EXTI  0 configuration mask */
#define SYSCFG_EXTICR1_EXTI1            (0x00F0U)                               /*!< EXTI  1 configuration mask */
#define SYSCFG_EXTICR1_EXTI2            (0x0F00U)                               /*!< EXTI  2 configuration mask */
#define SYSCFG_EXTICR1_EXTI3            (0xF000U)                               /*!< EXTI  3 configuration mask */

/**
  * @brief SYSCFG_EXTICR2 Bit mask
  */
#define SYSCFG_EXTICR2_EXTI4            (0x000FU)                               /*!< EXTI  4 configuration mask */
#define SYSCFG_EXTICR2_EXTI5            (0x00F0U)                               /*!< EXTI  5 configuration mask */
#define SYSCFG_EXTICR2_EXTI6            (0x0F00U)                               /*!< EXTI  6 configuration mask */
#define SYSCFG_EXTICR2_EXTI7            (0xF000U)                               /*!< EXTI  7 configuration mask */

/**
  * @brief SYSCFG_EXTICR3 Bit mask
  */
#define SYSCFG_EXTICR3_EXTI8            (0x000FU)                               /*!< EXTI  8 configuration mask */
#define SYSCFG_EXTICR3_EXTI9            (0x00F0U)                               /*!< EXTI  9 configuration mask */
#define SYSCFG_EXTICR3_EXTI10           (0x0F00U)                               /*!< EXTI 10 configuration mask */
#define SYSCFG_EXTICR3_EXTI11           (0xF000U)                               /*!< EXTI 11 configuration mask */

/**
  * @brief SYSCFG_EXTICR4 Bit mask
  */
#define SYSCFG_EXTICR4_EXTI12           (0x000FU)                               /*!< EXTI 12 configuration mask */
#define SYSCFG_EXTICR4_EXTI13           (0x00F0U)                               /*!< EXTI 13 configuration mask */
#define SYSCFG_EXTICR4_EXTI14           (0x0F00U)                               /*!< EXTI 14 configuration mask */
#define SYSCFG_EXTICR4_EXTI15           (0xF000U)                               /*!< EXTI 15 configuration mask */

/**
  * @brief EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA         (0x0000U)                               /*!< PA[0] pin  for EXTI[0] */
#define SYSCFG_EXTICR1_EXTI0_PB         (0x0001U)                               /*!< PB[0] pin  for EXTI[0] */

/**
  * @brief EXTI1 configuration
  */
#define SYSCFG_EXTICR1_EXTI1_PA         (0x0000U)                               /*!< PA[1] pin  for EXTI[1] */
#define SYSCFG_EXTICR1_EXTI1_PB         (0x0010U)                               /*!< PB[1] pin  for EXTI[1] */

/**
  * @brief EXTI2 configuration
  */
#define SYSCFG_EXTICR1_EXTI2_PA         (0x0000U)                               /*!< PA[2] pin  for EXTI[2] */
#define SYSCFG_EXTICR1_EXTI2_PB         (0x0100U)                               /*!< PB[2] pin  for EXTI[2] */

/**
  * @brief EXTI3 configuration
  */
#define SYSCFG_EXTICR1_EXTI3_PA         (0x0000U)                               /*!< PA[3] pin  for EXTI[3] */
#define SYSCFG_EXTICR1_EXTI3_PB         (0x1000U)                               /*!< PB[3] pin  for EXTI[3] */

/**
  * @brief EXTI4 configuration
  */
#define SYSCFG_EXTICR2_EXTI4_PA         (0x0000U)                               /*!< PA[4] pin  for EXTI[4] */
#define SYSCFG_EXTICR2_EXTI4_PB         (0x0001U)                               /*!< PB[4] pin  for EXTI[4] */

/**
  * @brief EXTI5 configuration
  */
#define SYSCFG_EXTICR2_EXTI5_PA         (0x0000U)                               /*!< PA[5] pin  for EXTI[5] */
#define SYSCFG_EXTICR2_EXTI5_PB         (0x0010U)                               /*!< PB[5] pin  for EXTI[5] */

/**
  * @brief EXTI6 configuration
  */
#define SYSCFG_EXTICR2_EXTI6_PA         (0x0000U)                               /*!< PA[6] pin  for EXTI[6] */
#define SYSCFG_EXTICR2_EXTI6_PB         (0x0100U)                               /*!< PB[6] pin  for EXTI[6] */

/**
  * @brief EXTI7 configuration
  */
#define SYSCFG_EXTICR2_EXTI7_PA         (0x0000U)                               /*!< PA[7] pin  for EXTI[7] */
#define SYSCFG_EXTICR2_EXTI7_PB         (0x1000U)                               /*!< PB[7] pin  for EXTI[7] */

/**
  * @brief EXTI8 configuration
  */
#define SYSCFG_EXTICR3_EXTI8_PA         (0x0000U)                               /*!< PA[8] pin  for EXTI[8] */
#define SYSCFG_EXTICR3_EXTI8_PB         (0x0001U)                               /*!< PB[8] pin  for EXTI[8] */

/**
  * @brief EXTI9 configuration
  */
#define SYSCFG_EXTICR3_EXTI9_PA         (0x0000U)                               /*!< PA[9] pin  for EXTI[9] */
#define SYSCFG_EXTICR3_EXTI9_PB         (0x0010U)                               /*!< PB[9] pin  for EXTI[9] */

/**
  * @brief EXTI10 configuration
  */
#define SYSCFG_EXTICR3_EXTI10_PA        (0x0000U)                               /*!< PA[10] pin for EXTI[10] */
#define SYSCFG_EXTICR3_EXTI10_PB        (0x0100U)                               /*!< PB[10] pin for EXTI[10] */

/**
  * @brief EXTI11 configuration
  */
#define SYSCFG_EXTICR3_EXTI11_PA        (0x0000U)                               /*!< PA[11] pin for EXTI[11] */
#define SYSCFG_EXTICR3_EXTI11_PB        (0x1000U)                               /*!< PB[11] pin for EXTI[11] */

/**
  * @brief EXTI12 configuration
  */
#define SYSCFG_EXTICR4_EXTI12_PA        (0x0000U)                               /*!< PA[12] pin for EXTI[12] */
#define SYSCFG_EXTICR4_EXTI12_PB        (0x0001U)                               /*!< PB[12] pin for EXTI[12] */

/**
  * @brief EXTI13 configuration
  */
#define SYSCFG_EXTICR4_EXTI13_PA        (0x0000U)                               /*!< PA[13] pin for EXTI[13] */
#define SYSCFG_EXTICR4_EXTI13_PB        (0x0010U)                               /*!< PB[13] pin for EXTI[13] */

/**
  * @brief EXTI14 configuration
  */
#define SYSCFG_EXTICR4_EXTI14_PA        (0x0000U)                               /*!< PA[14] pin for EXTI[14] */
#define SYSCFG_EXTICR4_EXTI14_PB        (0x0100U)                               /*!< PB[14] pin for EXTI[14] */

/**
  * @brief EXTI15 configuration
  */
#define SYSCFG_EXTICR4_EXTI15_PA        (0x0000U)                               /*!< PA[15] pin for EXTI[15] */
#define SYSCFG_EXTICR4_EXTI15_PB        (0x1000U)                               /*!< PB[15] pin for EXTI[15] */

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
/** --------------------------------------------------------------------------*/

