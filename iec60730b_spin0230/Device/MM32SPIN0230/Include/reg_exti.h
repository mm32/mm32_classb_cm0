/***********************************************************************************************************************
    @file     reg_exti.h
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

#ifndef __REG_EXTI_H
#define __REG_EXTI_H

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

/**
  * @brief EXTI Base Address Definition
  */
#define EXTI_BASE                       (APB1PERIPH_BASE + 0x10400)

/**
  * @brief EXTI Registers Structure Definition
  */
typedef struct
{
    __IO uint32_t IMR;                     /*!< Interrupt Mask Register                        offset: 0x00*/
    __IO uint32_t EMR;                     /*!< Event Mask Register                            offset: 0x04*/
    __IO uint32_t RTSR;                    /*!< Rising Trigger Status Register                 offset: 0x08*/
    __IO uint32_t FTSR;                    /*!< Falling Trigger Status Register                offset: 0x0C*/
    __IO uint32_t SWIER;                   /*!< Software Interrupt Enable Register             offset: 0x10*/
    __IO uint32_t PR;                      /*!< Pending Register                               offset: 0x14*/
} EXTI_TypeDef;

/**
  * @brief EXTI type pointer Definition
  */
#define EXTI                         ((EXTI_TypeDef *)EXTI_BASE)


/**
  * @brief EXTI_IMR Register Bit Definition
  */
#define EXTI_IMR_IMR0_Pos               (0)
#define EXTI_IMR_IMR0                   (0x01U << EXTI_IMR_IMR0_Pos)            /*!< Interrupt Mask on line 0 */
#define EXTI_IMR_IMR1_Pos               (1)
#define EXTI_IMR_IMR1                   (0x01U << EXTI_IMR_IMR1_Pos)            /*!< Interrupt Mask on line 1 */
#define EXTI_IMR_IMR2_Pos               (2)
#define EXTI_IMR_IMR2                   (0x01U << EXTI_IMR_IMR2_Pos)            /*!< Interrupt Mask on line 2 */
#define EXTI_IMR_IMR3_Pos               (3)
#define EXTI_IMR_IMR3                   (0x01U << EXTI_IMR_IMR3_Pos)            /*!< Interrupt Mask on line 3 */
#define EXTI_IMR_IMR4_Pos               (4)
#define EXTI_IMR_IMR4                   (0x01U << EXTI_IMR_IMR4_Pos)            /*!< Interrupt Mask on line 4 */
#define EXTI_IMR_IMR5_Pos               (5)
#define EXTI_IMR_IMR5                   (0x01U << EXTI_IMR_IMR5_Pos)            /*!< Interrupt Mask on line 5 */
#define EXTI_IMR_IMR6_Pos               (6)
#define EXTI_IMR_IMR6                   (0x01U << EXTI_IMR_IMR6_Pos)            /*!< Interrupt Mask on line 6 */
#define EXTI_IMR_IMR7_Pos               (7)
#define EXTI_IMR_IMR7                   (0x01U << EXTI_IMR_IMR7_Pos)            /*!< Interrupt Mask on line 7 */
#define EXTI_IMR_IMR8_Pos               (8)
#define EXTI_IMR_IMR8                   (0x01U << EXTI_IMR_IMR8_Pos)            /*!< Interrupt Mask on line 8 */
#define EXTI_IMR_IMR9_Pos               (9)
#define EXTI_IMR_IMR9                   (0x01U << EXTI_IMR_IMR9_Pos)            /*!< Interrupt Mask on line 9 */
#define EXTI_IMR_IMR10_Pos              (10)
#define EXTI_IMR_IMR10                  (0x01U << EXTI_IMR_IMR10_Pos)           /*!< Interrupt Mask on line 10 */
#define EXTI_IMR_IMR11_Pos              (11)
#define EXTI_IMR_IMR11                  (0x01U << EXTI_IMR_IMR11_Pos)           /*!< Interrupt Mask on line 11 */
#define EXTI_IMR_IMR12_Pos              (12)
#define EXTI_IMR_IMR12                  (0x01U << EXTI_IMR_IMR12_Pos)           /*!< Interrupt Mask on line 12 */
#define EXTI_IMR_IMR13_Pos              (13)
#define EXTI_IMR_IMR13                  (0x01U << EXTI_IMR_IMR13_Pos)           /*!< Interrupt Mask on line 13 */
#define EXTI_IMR_IMR14_Pos              (14)
#define EXTI_IMR_IMR14                  (0x01U << EXTI_IMR_IMR14_Pos)           /*!< Interrupt Mask on line 14 */
#define EXTI_IMR_IMR15_Pos              (15)
#define EXTI_IMR_IMR15                  (0x01U << EXTI_IMR_IMR15_Pos)           /*!< Interrupt Mask on line 15 */
#define EXTI_IMR_IMR16_Pos              (16)
#define EXTI_IMR_IMR16                  (0x01U << EXTI_IMR_IMR16_Pos)           /*!< Interrupt Mask on line 16 */
#define EXTI_IMR_IMR17_Pos              (17)
#define EXTI_IMR_IMR17                  (0x01U << EXTI_IMR_IMR17_Pos)           /*!< Interrupt Mask on line 17 */
#define EXTI_IMR_IMR18_Pos              (18)
#define EXTI_IMR_IMR18                  (0x01U << EXTI_IMR_IMR18_Pos)           /*!< Interrupt Mask on line 18 */
#define EXTI_IMR_IMR19_Pos              (19)
#define EXTI_IMR_IMR19                  (0x01U << EXTI_IMR_IMR19_Pos)           /*!< Interrupt Mask on line 19 */
#define EXTI_IMR_IMR20_Pos              (20)
#define EXTI_IMR_IMR20                  (0x01U << EXTI_IMR_IMR20_Pos)           /*!< Interrupt Mask on line 20 */
#define EXTI_IMR_IMR21_Pos              (21)
#define EXTI_IMR_IMR21                  (0x01U << EXTI_IMR_IMR21_Pos)           /*!< Interrupt Mask on line 21 */
#define EXTI_IMR_IMR22_Pos              (22)
#define EXTI_IMR_IMR22                  (0x01U << EXTI_IMR_IMR22_Pos)           /*!< Interrupt Mask on line 22 */
#define EXTI_IMR_IMR23_Pos              (23)
#define EXTI_IMR_IMR23                  (0x01U << EXTI_IMR_IMR23_Pos)           /*!< Interrupt Mask on line 23 */
#define EXTI_IMR_IMR24_Pos              (24)
#define EXTI_IMR_IMR24                  (0x01U << EXTI_IMR_IMR24_Pos)           /*!< Interrupt Mask on line 24 */
#define EXTI_IMR_IMR25_Pos              (25)
#define EXTI_IMR_IMR25                  (0x01U << EXTI_IMR_IMR25_Pos)           /*!< Interrupt Mask on line 25 */
#define EXTI_IMR_IMR26_Pos              (26)
#define EXTI_IMR_IMR26                  (0x01U << EXTI_IMR_IMR26_Pos)           /*!< Interrupt Mask on line 26 */
#define EXTI_IMR_IMR27_Pos              (27)
#define EXTI_IMR_IMR27                  (0x01U << EXTI_IMR_IMR27_Pos)           /*!< Interrupt Mask on line 27 */
#define EXTI_IMR_IMR28_Pos              (28)
#define EXTI_IMR_IMR28                  (0x01U << EXTI_IMR_IMR28_Pos)           /*!< Interrupt Mask on line 28 */
#define EXTI_IMR_IMR29_Pos              (29)
#define EXTI_IMR_IMR29                  (0x01U << EXTI_IMR_IMR29_Pos)           /*!< Interrupt Mask on line 29 */
#define EXTI_IMR_IMR30_Pos              (30)
#define EXTI_IMR_IMR30                  (0x01U << EXTI_IMR_IMR30_Pos)           /*!< Interrupt Mask on line 30 */
#define EXTI_IMR_IMR31_Pos              (31)
#define EXTI_IMR_IMR31                  (0x01U << EXTI_IMR_IMR31_Pos)           /*!< Interrupt Mask on line 31 */

/**
  * @brief EXTI_EMR Register Bit Definition
  */
#define EXTI_EMR_IMR0_Pos               (0)
#define EXTI_EMR_IMR0                   (0x01U << EXTI_EMR_IMR0_Pos)            /*!< Event Mask on line 0 */
#define EXTI_EMR_IMR1_Pos               (1)
#define EXTI_EMR_IMR1                   (0x01U << EXTI_EMR_IMR1_Pos)            /*!< Event Mask on line 1 */
#define EXTI_EMR_IMR2_Pos               (2)
#define EXTI_EMR_IMR2                   (0x01U << EXTI_EMR_IMR2_Pos)            /*!< Event Mask on line 2 */
#define EXTI_EMR_IMR3_Pos               (3)
#define EXTI_EMR_IMR3                   (0x01U << EXTI_EMR_IMR3_Pos)            /*!< Event Mask on line 3 */
#define EXTI_EMR_IMR4_Pos               (4)
#define EXTI_EMR_IMR4                   (0x01U << EXTI_EMR_IMR4_Pos)            /*!< Event Mask on line 4 */
#define EXTI_EMR_IMR5_Pos               (5)
#define EXTI_EMR_IMR5                   (0x01U << EXTI_EMR_IMR5_Pos)            /*!< Event Mask on line 5 */
#define EXTI_EMR_IMR6_Pos               (6)
#define EXTI_EMR_IMR6                   (0x01U << EXTI_EMR_IMR6_Pos)            /*!< Event Mask on line 6 */
#define EXTI_EMR_IMR7_Pos               (7)
#define EXTI_EMR_IMR7                   (0x01U << EXTI_EMR_IMR7_Pos)            /*!< Event Mask on line 7 */
#define EXTI_EMR_IMR8_Pos               (8)
#define EXTI_EMR_IMR8                   (0x01U << EXTI_EMR_IMR8_Pos)            /*!< Event Mask on line 8 */
#define EXTI_EMR_IMR9_Pos               (9)
#define EXTI_EMR_IMR9                   (0x01U << EXTI_EMR_IMR9_Pos)            /*!< Event Mask on line 9 */
#define EXTI_EMR_IMR10_Pos              (10)
#define EXTI_EMR_IMR10                  (0x01U << EXTI_EMR_IMR10_Pos)           /*!< Event Mask on line 10 */
#define EXTI_EMR_IMR11_Pos              (11)
#define EXTI_EMR_IMR11                  (0x01U << EXTI_EMR_IMR11_Pos)           /*!< Event Mask on line 11 */
#define EXTI_EMR_IMR12_Pos              (12)
#define EXTI_EMR_IMR12                  (0x01U << EXTI_EMR_IMR12_Pos)           /*!< Event Mask on line 12 */
#define EXTI_EMR_IMR13_Pos              (13)
#define EXTI_EMR_IMR13                  (0x01U << EXTI_EMR_IMR13_Pos)           /*!< Event Mask on line 13 */
#define EXTI_EMR_IMR14_Pos              (14)
#define EXTI_EMR_IMR14                  (0x01U << EXTI_EMR_IMR14_Pos)           /*!< Event Mask on line 14 */
#define EXTI_EMR_IMR15_Pos              (15)
#define EXTI_EMR_IMR15                  (0x01U << EXTI_EMR_IMR15_Pos)           /*!< Event Mask on line 15 */
#define EXTI_EMR_IMR16_Pos              (16)
#define EXTI_EMR_IMR16                  (0x01U << EXTI_EMR_IMR16_Pos)           /*!< Event Mask on line 16 */
#define EXTI_EMR_IMR17_Pos              (17)
#define EXTI_EMR_IMR17                  (0x01U << EXTI_EMR_IMR17_Pos)           /*!< Event Mask on line 17 */
#define EXTI_EMR_IMR18_Pos              (18)
#define EXTI_EMR_IMR18                  (0x01U << EXTI_EMR_IMR18_Pos)           /*!< Event Mask on line 18 */
#define EXTI_EMR_IMR19_Pos              (19)
#define EXTI_EMR_IMR19                  (0x01U << EXTI_EMR_IMR19_Pos)           /*!< Event Mask on line 19 */
#define EXTI_EMR_IMR20_Pos              (20)
#define EXTI_EMR_IMR20                  (0x01U << EXTI_EMR_IMR20_Pos)           /*!< Event Mask on line 20 */
#define EXTI_EMR_IMR21_Pos              (21)
#define EXTI_EMR_IMR21                  (0x01U << EXTI_EMR_IMR21_Pos)           /*!< Event Mask on line 21 */
#define EXTI_EMR_IMR22_Pos              (22)
#define EXTI_EMR_IMR22                  (0x01U << EXTI_EMR_IMR22_Pos)           /*!< Event Mask on line 22 */
#define EXTI_EMR_IMR23_Pos              (23)
#define EXTI_EMR_IMR23                  (0x01U << EXTI_EMR_IMR23_Pos)           /*!< Event Mask on line 23 */
#define EXTI_EMR_IMR24_Pos              (24)
#define EXTI_EMR_IMR24                  (0x01U << EXTI_EMR_IMR24_Pos)           /*!< Event Mask on line 24 */
#define EXTI_EMR_IMR25_Pos              (25)
#define EXTI_EMR_IMR25                  (0x01U << EXTI_EMR_IMR25_Pos)           /*!< Event Mask on line 25 */
#define EXTI_EMR_IMR26_Pos              (26)
#define EXTI_EMR_IMR26                  (0x01U << EXTI_EMR_IMR26_Pos)           /*!< Event Mask on line 26 */
#define EXTI_EMR_IMR27_Pos              (27)
#define EXTI_EMR_IMR27                  (0x01U << EXTI_EMR_IMR27_Pos)           /*!< Event Mask on line 27 */
#define EXTI_EMR_IMR28_Pos              (28)
#define EXTI_EMR_IMR28                  (0x01U << EXTI_EMR_IMR28_Pos)           /*!< Event Mask on line 28 */
#define EXTI_EMR_IMR29_Pos              (29)
#define EXTI_EMR_IMR29                  (0x01U << EXTI_EMR_IMR29_Pos)           /*!< Event Mask on line 29 */
#define EXTI_EMR_IMR30_Pos              (30)
#define EXTI_EMR_IMR30                  (0x01U << EXTI_EMR_IMR30_Pos)           /*!< Event Mask on line 30 */
#define EXTI_EMR_IMR31_Pos              (31)
#define EXTI_EMR_IMR31                  (0x01U << EXTI_EMR_IMR31_Pos)           /*!< Event Mask on line 31 */

/**
  * @brief EXTI_RTSR Register Bit Definition
  */
#define EXTI_RTSR_TR0_Pos               (0)
#define EXTI_RTSR_TR0                   (0x01U << EXTI_RTSR_TR0_Pos)            /*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR_TR1_Pos               (1)
#define EXTI_RTSR_TR1                   (0x01U << EXTI_RTSR_TR1_Pos)            /*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR_TR2_Pos               (2)
#define EXTI_RTSR_TR2                   (0x01U << EXTI_RTSR_TR2_Pos)            /*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR_TR3_Pos               (3)
#define EXTI_RTSR_TR3                   (0x01U << EXTI_RTSR_TR3_Pos)            /*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR_TR4_Pos               (4)
#define EXTI_RTSR_TR4                   (0x01U << EXTI_RTSR_TR4_Pos)            /*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR_TR5_Pos               (5)
#define EXTI_RTSR_TR5                   (0x01U << EXTI_RTSR_TR5_Pos)            /*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR_TR6_Pos               (6)
#define EXTI_RTSR_TR6                   (0x01U << EXTI_RTSR_TR6_Pos)            /*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR_TR7_Pos               (7)
#define EXTI_RTSR_TR7                   (0x01U << EXTI_RTSR_TR7_Pos)            /*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR_TR8_Pos               (8)
#define EXTI_RTSR_TR8                   (0x01U << EXTI_RTSR_TR8_Pos)            /*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR_TR9_Pos               (9)
#define EXTI_RTSR_TR9                   (0x01U << EXTI_RTSR_TR9_Pos)            /*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR_TR10_Pos              (10)
#define EXTI_RTSR_TR10                  (0x01U << EXTI_RTSR_TR10_Pos)           /*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR_TR11_Pos              (11)
#define EXTI_RTSR_TR11                  (0x01U << EXTI_RTSR_TR11_Pos)           /*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR_TR12_Pos              (12)
#define EXTI_RTSR_TR12                  (0x01U << EXTI_RTSR_TR12_Pos)           /*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR_TR13_Pos              (13)
#define EXTI_RTSR_TR13                  (0x01U << EXTI_RTSR_TR13_Pos)           /*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR_TR14_Pos              (14)
#define EXTI_RTSR_TR14                  (0x01U << EXTI_RTSR_TR14_Pos)           /*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR_TR15_Pos              (15)
#define EXTI_RTSR_TR15                  (0x01U << EXTI_RTSR_TR15_Pos)           /*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR_TR16_Pos              (16)
#define EXTI_RTSR_TR16                  (0x01U << EXTI_RTSR_TR16_Pos)           /*!< Rising trigger event configuration bit of line 16 */
#define EXTI_RTSR_TR17_Pos              (17)
#define EXTI_RTSR_TR17                  (0x01U << EXTI_RTSR_TR17_Pos)           /*!< Rising trigger event configuration bit of line 17 */
#define EXTI_RTSR_TR18_Pos              (18)
#define EXTI_RTSR_TR18                  (0x01U << EXTI_RTSR_TR18_Pos)           /*!< Rising trigger event configuration bit of line 18 */
#define EXTI_RTSR_TR19_Pos              (19)
#define EXTI_RTSR_TR19                  (0x01U << EXTI_RTSR_TR19_Pos)           /*!< Rising trigger event configuration bit of line 19 */
#define EXTI_RTSR_TR20_Pos              (20)
#define EXTI_RTSR_TR20                  (0x01U << EXTI_RTSR_TR20_Pos)           /*!< Rising trigger event configuration bit of line 20 */
#define EXTI_RTSR_TR21_Pos              (21)
#define EXTI_RTSR_TR21                  (0x01U << EXTI_RTSR_TR21_Pos)           /*!< Rising trigger event configuration bit of line 21 */
#define EXTI_RTSR_TR22_Pos              (22)
#define EXTI_RTSR_TR22                  (0x01U << EXTI_RTSR_TR22_Pos)           /*!< Rising trigger event configuration bit of line 22 */
#define EXTI_RTSR_TR23_Pos              (23)
#define EXTI_RTSR_TR23                  (0x01U << EXTI_RTSR_TR23_Pos)           /*!< Rising trigger event configuration bit of line 23 */
#define EXTI_RTSR_TR24_Pos              (24)
#define EXTI_RTSR_TR24                  (0x01U << EXTI_RTSR_TR24_Pos)           /*!< Rising trigger event configuration bit of line 24 */
#define EXTI_RTSR_TR25_Pos              (25)
#define EXTI_RTSR_TR25                  (0x01U << EXTI_RTSR_TR25_Pos)           /*!< Rising trigger event configuration bit of line 25 */
#define EXTI_RTSR_TR26_Pos              (26)
#define EXTI_RTSR_TR26                  (0x01U << EXTI_RTSR_TR26_Pos)           /*!< Rising trigger event configuration bit of line 26 */
#define EXTI_RTSR_TR27_Pos              (27)
#define EXTI_RTSR_TR27                  (0x01U << EXTI_RTSR_TR27_Pos)           /*!< Rising trigger event configuration bit of line 27 */
#define EXTI_RTSR_TR28_Pos              (28)
#define EXTI_RTSR_TR28                  (0x01U << EXTI_RTSR_TR28_Pos)           /*!< Rising trigger event configuration bit of line 28 */
#define EXTI_RTSR_TR29_Pos              (29)
#define EXTI_RTSR_TR29                  (0x01U << EXTI_RTSR_TR29_Pos)           /*!< Rising trigger event configuration bit of line 29 */
#define EXTI_RTSR_TR30_Pos              (30)
#define EXTI_RTSR_TR30                  (0x01U << EXTI_RTSR_TR30_Pos)           /*!< Rising trigger event configuration bit of line 30 */
#define EXTI_RTSR_TR31_Pos              (31)
#define EXTI_RTSR_TR31                  (0x01U << EXTI_RTSR_TR31_Pos)           /*!< Rising trigger event configuration bit of line 31 */

/**
  * @brief EXTI_FTSR Register Bit Definition
  */
#define EXTI_FTSR_TR0_Pos               (0)
#define EXTI_FTSR_TR0                   (0x01U << EXTI_FTSR_TR0_Pos)            /*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR_TR1_Pos               (1)
#define EXTI_FTSR_TR1                   (0x01U << EXTI_FTSR_TR1_Pos)            /*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR_TR2_Pos               (2)
#define EXTI_FTSR_TR2                   (0x01U << EXTI_FTSR_TR2_Pos)            /*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR_TR3_Pos               (3)
#define EXTI_FTSR_TR3                   (0x01U << EXTI_FTSR_TR3_Pos)            /*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR_TR4_Pos               (4)
#define EXTI_FTSR_TR4                   (0x01U << EXTI_FTSR_TR4_Pos)            /*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR_TR5_Pos               (5)
#define EXTI_FTSR_TR5                   (0x01U << EXTI_FTSR_TR5_Pos)            /*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR_TR6_Pos               (6)
#define EXTI_FTSR_TR6                   (0x01U << EXTI_FTSR_TR6_Pos)            /*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR_TR7_Pos               (7)
#define EXTI_FTSR_TR7                   (0x01U << EXTI_FTSR_TR7_Pos)            /*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR_TR8_Pos               (8)
#define EXTI_FTSR_TR8                   (0x01U << EXTI_FTSR_TR8_Pos)            /*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR_TR9_Pos               (9)
#define EXTI_FTSR_TR9                   (0x01U << EXTI_FTSR_TR9_Pos)            /*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR_TR10_Pos              (10)
#define EXTI_FTSR_TR10                  (0x01U << EXTI_FTSR_TR10_Pos)           /*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR_TR11_Pos              (11)
#define EXTI_FTSR_TR11                  (0x01U << EXTI_FTSR_TR11_Pos)           /*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR_TR12_Pos              (12)
#define EXTI_FTSR_TR12                  (0x01U << EXTI_FTSR_TR12_Pos)           /*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR_TR13_Pos              (13)
#define EXTI_FTSR_TR13                  (0x01U << EXTI_FTSR_TR13_Pos)           /*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR_TR14_Pos              (14)
#define EXTI_FTSR_TR14                  (0x01U << EXTI_FTSR_TR14_Pos)           /*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR_TR15_Pos              (15)
#define EXTI_FTSR_TR15                  (0x01U << EXTI_FTSR_TR15_Pos)           /*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR_TR16_Pos              (16)
#define EXTI_FTSR_TR16                  (0x01U << EXTI_FTSR_TR16_Pos)           /*!< Falling trigger event configuration bit of line 16 */
#define EXTI_FTSR_TR17_Pos              (17)
#define EXTI_FTSR_TR17                  (0x01U << EXTI_FTSR_TR17_Pos)           /*!< Falling trigger event configuration bit of line 17 */
#define EXTI_FTSR_TR18_Pos              (18)
#define EXTI_FTSR_TR18                  (0x01U << EXTI_FTSR_TR18_Pos)           /*!< Falling trigger event configuration bit of line 18 */
#define EXTI_FTSR_TR19_Pos              (19)
#define EXTI_FTSR_TR19                  (0x01U << EXTI_FTSR_TR19_Pos)           /*!< Falling trigger event configuration bit of line 19 */
#define EXTI_FTSR_TR20_Pos              (20)
#define EXTI_FTSR_TR20                  (0x01U << EXTI_FTSR_TR20_Pos)           /*!< Falling trigger event configuration bit of line 20 */
#define EXTI_FTSR_TR21_Pos              (21)
#define EXTI_FTSR_TR21                  (0x01U << EXTI_FTSR_TR21_Pos)           /*!< Falling trigger event configuration bit of line 21 */
#define EXTI_FTSR_TR22_Pos              (22)
#define EXTI_FTSR_TR22                  (0x01U << EXTI_FTSR_TR22_Pos)           /*!< Falling trigger event configuration bit of line 22 */
#define EXTI_FTSR_TR23_Pos              (23)
#define EXTI_FTSR_TR23                  (0x01U << EXTI_FTSR_TR23_Pos)           /*!< Falling trigger event configuration bit of line 23 */
#define EXTI_FTSR_TR24_Pos              (24)
#define EXTI_FTSR_TR24                  (0x01U << EXTI_FTSR_TR24_Pos)           /*!< Falling trigger event configuration bit of line 24 */
#define EXTI_FTSR_TR25_Pos              (25)
#define EXTI_FTSR_TR25                  (0x01U << EXTI_FTSR_TR25_Pos)           /*!< Falling trigger event configuration bit of line 25 */
#define EXTI_FTSR_TR26_Pos              (26)
#define EXTI_FTSR_TR26                  (0x01U << EXTI_FTSR_TR26_Pos)           /*!< Falling trigger event configuration bit of line 26 */
#define EXTI_FTSR_TR27_Pos              (27)
#define EXTI_FTSR_TR27                  (0x01U << EXTI_FTSR_TR27_Pos)           /*!< Falling trigger event configuration bit of line 27 */
#define EXTI_FTSR_TR28_Pos              (28)
#define EXTI_FTSR_TR28                  (0x01U << EXTI_FTSR_TR28_Pos)           /*!< Falling trigger event configuration bit of line 28 */
#define EXTI_FTSR_TR29_Pos              (29)
#define EXTI_FTSR_TR29                  (0x01U << EXTI_FTSR_TR29_Pos)           /*!< Falling trigger event configuration bit of line 29 */
#define EXTI_FTSR_TR30_Pos              (30)
#define EXTI_FTSR_TR30                  (0x01U << EXTI_FTSR_TR30_Pos)           /*!< Falling trigger event configuration bit of line 30 */
#define EXTI_FTSR_TR31_Pos              (31)
#define EXTI_FTSR_TR31                  (0x01U << EXTI_FTSR_TR31_Pos)           /*!< Falling trigger event configuration bit of line 31 */

/**
  * @brief EXTI_SWIER Register Bit Definition
  */
#define EXTI_SWIER_SWIER0_Pos           (0)
#define EXTI_SWIER_SWIER0               (0x01U << EXTI_SWIER_SWIER0_Pos)        /*!< Software Interrupt on line  0 */
#define EXTI_SWIER_SWIER1_Pos           (1)
#define EXTI_SWIER_SWIER1               (0x01U << EXTI_SWIER_SWIER1_Pos)        /*!< Software Interrupt on line  1 */
#define EXTI_SWIER_SWIER2_Pos           (2)
#define EXTI_SWIER_SWIER2               (0x01U << EXTI_SWIER_SWIER2_Pos)        /*!< Software Interrupt on line  2 */
#define EXTI_SWIER_SWIER3_Pos           (3)
#define EXTI_SWIER_SWIER3               (0x01U << EXTI_SWIER_SWIER3_Pos)        /*!< Software Interrupt on line  3 */
#define EXTI_SWIER_SWIER4_Pos           (4)
#define EXTI_SWIER_SWIER4               (0x01U << EXTI_SWIER_SWIER4_Pos)        /*!< Software Interrupt on line  4 */
#define EXTI_SWIER_SWIER5_Pos           (5)
#define EXTI_SWIER_SWIER5               (0x01U << EXTI_SWIER_SWIER5_Pos)        /*!< Software Interrupt on line  5 */
#define EXTI_SWIER_SWIER6_Pos           (6)
#define EXTI_SWIER_SWIER6               (0x01U << EXTI_SWIER_SWIER6_Pos)        /*!< Software Interrupt on line  6 */
#define EXTI_SWIER_SWIER7_Pos           (7)
#define EXTI_SWIER_SWIER7               (0x01U << EXTI_SWIER_SWIER7_Pos)        /*!< Software Interrupt on line  7 */
#define EXTI_SWIER_SWIER8_Pos           (8)
#define EXTI_SWIER_SWIER8               (0x01U << EXTI_SWIER_SWIER8_Pos)        /*!< Software Interrupt on line  8 */
#define EXTI_SWIER_SWIER9_Pos           (9)
#define EXTI_SWIER_SWIER9               (0x01U << EXTI_SWIER_SWIER9_Pos)        /*!< Software Interrupt on line  9 */
#define EXTI_SWIER_SWIER10_Pos          (10)
#define EXTI_SWIER_SWIER10              (0x01U << EXTI_SWIER_SWIER10_Pos)       /*!< Software Interrupt on line  10 */
#define EXTI_SWIER_SWIER11_Pos          (11)
#define EXTI_SWIER_SWIER11              (0x01U << EXTI_SWIER_SWIER11_Pos)       /*!< Software Interrupt on line  11 */
#define EXTI_SWIER_SWIER12_Pos          (12)
#define EXTI_SWIER_SWIER12              (0x01U << EXTI_SWIER_SWIER12_Pos)       /*!< Software Interrupt on line  12 */
#define EXTI_SWIER_SWIER13_Pos          (13)
#define EXTI_SWIER_SWIER13              (0x01U << EXTI_SWIER_SWIER13_Pos)       /*!< Software Interrupt on line  13 */
#define EXTI_SWIER_SWIER14_Pos          (14)
#define EXTI_SWIER_SWIER14              (0x01U << EXTI_SWIER_SWIER14_Pos)       /*!< Software Interrupt on line  14 */
#define EXTI_SWIER_SWIER15_Pos          (15)
#define EXTI_SWIER_SWIER15              (0x01U << EXTI_SWIER_SWIER15_Pos)       /*!< Software Interrupt on line  15 */
#define EXTI_SWIER_SWIER16_Pos          (16)
#define EXTI_SWIER_SWIER16              (0x01U << EXTI_SWIER_SWIER16_Pos)       /*!< Software Interrupt on line  16 */
#define EXTI_SWIER_SWIER17_Pos          (17)
#define EXTI_SWIER_SWIER17              (0x01U << EXTI_SWIER_SWIER17_Pos)       /*!< Software Interrupt on line  17 */
#define EXTI_SWIER_SWIER18_Pos          (18)
#define EXTI_SWIER_SWIER18              (0x01U << EXTI_SWIER_SWIER18_Pos)       /*!< Software Interrupt on line  18 */
#define EXTI_SWIER_SWIER19_Pos          (19)
#define EXTI_SWIER_SWIER19              (0x01U << EXTI_SWIER_SWIER19_Pos)       /*!< Software Interrupt on line  19 */
#define EXTI_SWIER_SWIER20_Pos          (20)
#define EXTI_SWIER_SWIER20              (0x01U << EXTI_SWIER_SWIER20_Pos)       /*!< Software Interrupt on line  20 */
#define EXTI_SWIER_SWIER21_Pos          (21)
#define EXTI_SWIER_SWIER21              (0x01U << EXTI_SWIER_SWIER21_Pos)       /*!< Software Interrupt on line  21 */
#define EXTI_SWIER_SWIER22_Pos          (22)
#define EXTI_SWIER_SWIER22              (0x01U << EXTI_SWIER_SWIER22_Pos)       /*!< Software Interrupt on line  22 */
#define EXTI_SWIER_SWIER23_Pos          (23)
#define EXTI_SWIER_SWIER23              (0x01U << EXTI_SWIER_SWIER23_Pos)       /*!< Software Interrupt on line  23 */
#define EXTI_SWIER_SWIER24_Pos          (24)
#define EXTI_SWIER_SWIER24              (0x01U << EXTI_SWIER_SWIER24_Pos)       /*!< Software Interrupt on line  24 */
#define EXTI_SWIER_SWIER25_Pos          (25)
#define EXTI_SWIER_SWIER25              (0x01U << EXTI_SWIER_SWIER25_Pos)       /*!< Software Interrupt on line  25 */
#define EXTI_SWIER_SWIER26_Pos          (26)
#define EXTI_SWIER_SWIER26              (0x01U << EXTI_SWIER_SWIER26_Pos)       /*!< Software Interrupt on line  26 */
#define EXTI_SWIER_SWIER27_Pos          (27)
#define EXTI_SWIER_SWIER27              (0x01U << EXTI_SWIER_SWIER27_Pos)       /*!< Software Interrupt on line  27 */
#define EXTI_SWIER_SWIER28_Pos          (28)
#define EXTI_SWIER_SWIER28              (0x01U << EXTI_SWIER_SWIER28_Pos)       /*!< Software Interrupt on line  28 */
#define EXTI_SWIER_SWIER29_Pos          (29)
#define EXTI_SWIER_SWIER29              (0x01U << EXTI_SWIER_SWIER29_Pos)       /*!< Software Interrupt on line  29 */
#define EXTI_SWIER_SWIER30_Pos          (30)
#define EXTI_SWIER_SWIER30              (0x01U << EXTI_SWIER_SWIER30_Pos)       /*!< Software Interrupt on line  30 */
#define EXTI_SWIER_SWIER31_Pos          (31)
#define EXTI_SWIER_SWIER31              (0x01U << EXTI_SWIER_SWIER31_Pos)       /*!< Software Interrupt on line  31 */

/**
  * @brief EXTI_PR Register Bit Definition
  */
#define EXTI_PR_PR0_Pos                 (0)
#define EXTI_PR_PR0                     (0x01U << EXTI_PR_PR0_Pos)              /*!< Pending bit 0 */
#define EXTI_PR_PR1_Pos                 (1)
#define EXTI_PR_PR1                     (0x01U << EXTI_PR_PR1_Pos)              /*!< Pending bit 1 */
#define EXTI_PR_PR2_Pos                 (2)
#define EXTI_PR_PR2                     (0x01U << EXTI_PR_PR2_Pos)              /*!< Pending bit 2 */
#define EXTI_PR_PR3_Pos                 (3)
#define EXTI_PR_PR3                     (0x01U << EXTI_PR_PR3_Pos)              /*!< Pending bit 3 */
#define EXTI_PR_PR4_Pos                 (4)
#define EXTI_PR_PR4                     (0x01U << EXTI_PR_PR4_Pos)              /*!< Pending bit 4 */
#define EXTI_PR_PR5_Pos                 (5)
#define EXTI_PR_PR5                     (0x01U << EXTI_PR_PR5_Pos)              /*!< Pending bit 5 */
#define EXTI_PR_PR6_Pos                 (6)
#define EXTI_PR_PR6                     (0x01U << EXTI_PR_PR6_Pos)              /*!< Pending bit 6 */
#define EXTI_PR_PR7_Pos                 (7)
#define EXTI_PR_PR7                     (0x01U << EXTI_PR_PR7_Pos)              /*!< Pending bit 7 */
#define EXTI_PR_PR8_Pos                 (8)
#define EXTI_PR_PR8                     (0x01U << EXTI_PR_PR8_Pos)              /*!< Pending bit 8 */
#define EXTI_PR_PR9_Pos                 (9)
#define EXTI_PR_PR9                     (0x01U << EXTI_PR_PR9_Pos)              /*!< Pending bit 9 */
#define EXTI_PR_PR10_Pos                (10)
#define EXTI_PR_PR10                    (0x01U << EXTI_PR_PR10_Pos)             /*!< Pending bit 10 */
#define EXTI_PR_PR11_Pos                (11)
#define EXTI_PR_PR11                    (0x01U << EXTI_PR_PR11_Pos)             /*!< Pending bit 11 */
#define EXTI_PR_PR12_Pos                (12)
#define EXTI_PR_PR12                    (0x01U << EXTI_PR_PR12_Pos)             /*!< Pending bit 12 */
#define EXTI_PR_PR13_Pos                (13)
#define EXTI_PR_PR13                    (0x01U << EXTI_PR_PR13_Pos)             /*!< Pending bit 13 */
#define EXTI_PR_PR14_Pos                (14)
#define EXTI_PR_PR14                    (0x01U << EXTI_PR_PR14_Pos)             /*!< Pending bit 14 */
#define EXTI_PR_PR15_Pos                (15)
#define EXTI_PR_PR15                    (0x01U << EXTI_PR_PR15_Pos)             /*!< Pending bit 15 */
#define EXTI_PR_PR16_Pos                (16)
#define EXTI_PR_PR16                    (0x01U << EXTI_PR_PR16_Pos)             /*!< Pending bit 16 */
#define EXTI_PR_PR17_Pos                (17)
#define EXTI_PR_PR17                    (0x01U << EXTI_PR_PR17_Pos)             /*!< Pending bit 17 */
#define EXTI_PR_PR18_Pos                (18)
#define EXTI_PR_PR18                    (0x01U << EXTI_PR_PR18_Pos)             /*!< Pending bit 18 */
#define EXTI_PR_PR19_Pos                (19)
#define EXTI_PR_PR19                    (0x01U << EXTI_PR_PR19_Pos)             /*!< Pending bit 19 */
#define EXTI_PR_PR20_Pos                (20)
#define EXTI_PR_PR20                    (0x01U << EXTI_PR_PR20_Pos)             /*!< Pending bit 20 */
#define EXTI_PR_PR21_Pos                (21)
#define EXTI_PR_PR21                    (0x01U << EXTI_PR_PR21_Pos)             /*!< Pending bit 21 */
#define EXTI_PR_PR22_Pos                (22)
#define EXTI_PR_PR22                    (0x01U << EXTI_PR_PR22_Pos)             /*!< Pending bit 22 */
#define EXTI_PR_PR23_Pos                (23)
#define EXTI_PR_PR23                    (0x01U << EXTI_PR_PR23_Pos)             /*!< Pending bit 23 */
#define EXTI_PR_PR24_Pos                (24)
#define EXTI_PR_PR24                    (0x01U << EXTI_PR_PR24_Pos)             /*!< Pending bit 24 */
#define EXTI_PR_PR25_Pos                (25)
#define EXTI_PR_PR25                    (0x01U << EXTI_PR_PR25_Pos)             /*!< Pending bit 25 */
#define EXTI_PR_PR26_Pos                (26)
#define EXTI_PR_PR26                    (0x01U << EXTI_PR_PR26_Pos)             /*!< Pending bit 26 */
#define EXTI_PR_PR27_Pos                (27)
#define EXTI_PR_PR27                    (0x01U << EXTI_PR_PR27_Pos)             /*!< Pending bit 27 */
#define EXTI_PR_PR28_Pos                (28)
#define EXTI_PR_PR28                    (0x01U << EXTI_PR_PR28_Pos)             /*!< Pending bit 28 */
#define EXTI_PR_PR29_Pos                (29)
#define EXTI_PR_PR29                    (0x01U << EXTI_PR_PR29_Pos)             /*!< Pending bit 29 */
#define EXTI_PR_PR30_Pos                (30)
#define EXTI_PR_PR30                    (0x01U << EXTI_PR_PR30_Pos)             /*!< Pending bit 30 */
#define EXTI_PR_PR31_Pos                (31)
#define EXTI_PR_PR31                    (0x01U << EXTI_PR_PR31_Pos)             /*!< Pending bit 31 */

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

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/

