/*
 *******************************************************************************
    @file     reg_exti.h
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
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/**
  * @brief EXTI Base Address Definition
  */
#define EXTI_BASE                       (APB2PERIPH_BASE + 0x0400)              /*!< Base Address: 0x40010400 */

/**
  * @brief EXTI Registers Structure Definition
  */
typedef struct {
    __IO uint32_t IMR;                                                          /*!< Interrupt Mask Register                        offset: 0x00 */
    __IO uint32_t EMR;                                                          /*!< Event Mask Register                            offset: 0x04 */
    __IO uint32_t RTSR;                                                         /*!< Rising Trigger Status Register                 offset: 0x08 */
    __IO uint32_t FTSR;                                                         /*!< Falling Trigger Status Register                offset: 0x0C */
    __IO uint32_t SWIER;                                                        /*!< Software Interrupt Enable Register             offset: 0x10 */
    __IO uint32_t PR;                                                           /*!< Pending Register                               offset: 0x14 */
} EXTI_TypeDef;

/**
  * @brief EXTI type pointer Definition
  */
#define EXTI                            ((EXTI_TypeDef*) EXTI_BASE)

/**
  * @brief EXTI_IMR Register Bit Definition
  */
#define EXTI_IMR_Pos                    (0)
#define EXTI_IMR                        (0xFFFFFFFFU << EXTI_IMR_Pos)           /*!< Interrupt Mask */

#define EXTI_IMR_0_Pos                  (0)
#define EXTI_IMR_0                      (0x01U << EXTI_IMR_0_Pos)               /*!< Interrupt Mask on line 0 */
#define EXTI_IMR_1_Pos                  (1)
#define EXTI_IMR_1                      (0x01U << EXTI_IMR_1_Pos)               /*!< Interrupt Mask on line 1 */
#define EXTI_IMR_2_Pos                  (2)
#define EXTI_IMR_2                      (0x01U << EXTI_IMR_2_Pos)               /*!< Interrupt Mask on line 2 */
#define EXTI_IMR_3_Pos                  (3)
#define EXTI_IMR_3                      (0x01U << EXTI_IMR_3_Pos)               /*!< Interrupt Mask on line 3 */
#define EXTI_IMR_4_Pos                  (4)
#define EXTI_IMR_4                      (0x01U << EXTI_IMR_4_Pos)               /*!< Interrupt Mask on line 4 */
#define EXTI_IMR_5_Pos                  (5)
#define EXTI_IMR_5                      (0x01U << EXTI_IMR_5_Pos)               /*!< Interrupt Mask on line 5 */
#define EXTI_IMR_6_Pos                  (6)
#define EXTI_IMR_6                      (0x01U << EXTI_IMR_6_Pos)               /*!< Interrupt Mask on line 6 */
#define EXTI_IMR_7_Pos                  (7)
#define EXTI_IMR_7                      (0x01U << EXTI_IMR_7_Pos)               /*!< Interrupt Mask on line 7 */
#define EXTI_IMR_8_Pos                  (8)
#define EXTI_IMR_8                      (0x01U << EXTI_IMR_8_Pos)               /*!< Interrupt Mask on line 8 */
#define EXTI_IMR_9_Pos                  (9)
#define EXTI_IMR_9                      (0x01U << EXTI_IMR_9_Pos)               /*!< Interrupt Mask on line 9 */
#define EXTI_IMR_10_Pos                 (10)
#define EXTI_IMR_10                     (0x01U << EXTI_IMR_10_Pos)              /*!< Interrupt Mask on line 10 */
#define EXTI_IMR_11_Pos                 (11)
#define EXTI_IMR_11                     (0x01U << EXTI_IMR_11_Pos)              /*!< Interrupt Mask on line 11 */
#define EXTI_IMR_12_Pos                 (12)
#define EXTI_IMR_12                     (0x01U << EXTI_IMR_12_Pos)              /*!< Interrupt Mask on line 12 */
#define EXTI_IMR_13_Pos                 (13)
#define EXTI_IMR_13                     (0x01U << EXTI_IMR_13_Pos)              /*!< Interrupt Mask on line 13 */
#define EXTI_IMR_14_Pos                 (14)
#define EXTI_IMR_14                     (0x01U << EXTI_IMR_14_Pos)              /*!< Interrupt Mask on line 14 */
#define EXTI_IMR_15_Pos                 (15)
#define EXTI_IMR_15                     (0x01U << EXTI_IMR_15_Pos)              /*!< Interrupt Mask on line 15 */
#define EXTI_IMR_16_Pos                 (16)
#define EXTI_IMR_16                     (0x01U << EXTI_IMR_16_Pos)              /*!< Interrupt Mask on line 16 */
#define EXTI_IMR_17_Pos                 (17)
#define EXTI_IMR_17                     (0x01U << EXTI_IMR_17_Pos)              /*!< Interrupt Mask on line 17 */
#define EXTI_IMR_18_Pos                 (18)
#define EXTI_IMR_18                     (0x01U << EXTI_IMR_18_Pos)              /*!< Interrupt Mask on line 18 */
#define EXTI_IMR_19_Pos                 (19)
#define EXTI_IMR_19                     (0x01U << EXTI_IMR_19_Pos)              /*!< Interrupt Mask on line 19 */
#define EXTI_IMR_20_Pos                 (20)
#define EXTI_IMR_20                     (0x01U << EXTI_IMR_20_Pos)              /*!< Interrupt Mask on line 20 */
#define EXTI_IMR_21_Pos                 (21)
#define EXTI_IMR_21                     (0x01U << EXTI_IMR_21_Pos)              /*!< Interrupt Mask on line 21 */
#define EXTI_IMR_22_Pos                 (22)
#define EXTI_IMR_22                     (0x01U << EXTI_IMR_22_Pos)              /*!< Interrupt Mask on line 22 */
#define EXTI_IMR_23_Pos                 (23)
#define EXTI_IMR_23                     (0x01U << EXTI_IMR_23_Pos)              /*!< Interrupt Mask on line 23 */
#define EXTI_IMR_24_Pos                 (24)
#define EXTI_IMR_24                     (0x01U << EXTI_IMR_24_Pos)              /*!< Interrupt Mask on line 24 */
#define EXTI_IMR_25_Pos                 (25)
#define EXTI_IMR_25                     (0x01U << EXTI_IMR_25_Pos)              /*!< Interrupt Mask on line 25 */
#define EXTI_IMR_26_Pos                 (26)
#define EXTI_IMR_26                     (0x01U << EXTI_IMR_26_Pos)              /*!< Interrupt Mask on line 26 */
#define EXTI_IMR_27_Pos                 (27)
#define EXTI_IMR_27                     (0x01U << EXTI_IMR_27_Pos)              /*!< Interrupt Mask on line 27 */
#define EXTI_IMR_28_Pos                 (28)
#define EXTI_IMR_28                     (0x01U << EXTI_IMR_28_Pos)              /*!< Interrupt Mask on line 28 */
#define EXTI_IMR_29_Pos                 (29)
#define EXTI_IMR_29                     (0x01U << EXTI_IMR_29_Pos)              /*!< Interrupt Mask on line 29 */
#define EXTI_IMR_30_Pos                 (30)
#define EXTI_IMR_30                     (0x01U << EXTI_IMR_30_Pos)              /*!< Interrupt Mask on line 30 */
#define EXTI_IMR_31_Pos                 (31)
#define EXTI_IMR_31                     (0x01U << EXTI_IMR_31_Pos)              /*!< Interrupt Mask on line 31 */

/**
  * @brief EXTI_EMR Register Bit Definition
  */
#define EXTI_EMR_Pos                    (0)
#define EXTI_EMR                        (0xFFFFFFFFU << EXTI_EMR_Pos)           /*!< Event Mask */

#define EXTI_EMR_0_Pos                  (0)
#define EXTI_EMR_0                      (0x01U << EXTI_EMR_0_Pos)               /*!< Event Mask on line 0 */
#define EXTI_EMR_1_Pos                  (1)
#define EXTI_EMR_1                      (0x01U << EXTI_EMR_1_Pos)               /*!< Event Mask on line 1 */
#define EXTI_EMR_2_Pos                  (2)
#define EXTI_EMR_2                      (0x01U << EXTI_EMR_2_Pos)               /*!< Event Mask on line 2 */
#define EXTI_EMR_3_Pos                  (3)
#define EXTI_EMR_3                      (0x01U << EXTI_EMR_3_Pos)               /*!< Event Mask on line 3 */
#define EXTI_EMR_4_Pos                  (4)
#define EXTI_EMR_4                      (0x01U << EXTI_EMR_4_Pos)               /*!< Event Mask on line 4 */
#define EXTI_EMR_5_Pos                  (5)
#define EXTI_EMR_5                      (0x01U << EXTI_EMR_5_Pos)               /*!< Event Mask on line 5 */
#define EXTI_EMR_6_Pos                  (6)
#define EXTI_EMR_6                      (0x01U << EXTI_EMR_6_Pos)               /*!< Event Mask on line 6 */
#define EXTI_EMR_7_Pos                  (7)
#define EXTI_EMR_7                      (0x01U << EXTI_EMR_7_Pos)               /*!< Event Mask on line 7 */
#define EXTI_EMR_8_Pos                  (8)
#define EXTI_EMR_8                      (0x01U << EXTI_EMR_8_Pos)               /*!< Event Mask on line 8 */
#define EXTI_EMR_9_Pos                  (9)
#define EXTI_EMR_9                      (0x01U << EXTI_EMR_9_Pos)               /*!< Event Mask on line 9 */
#define EXTI_EMR_10_Pos                 (10)
#define EXTI_EMR_10                     (0x01U << EXTI_EMR_10_Pos)              /*!< Event Mask on line 10 */
#define EXTI_EMR_11_Pos                 (11)
#define EXTI_EMR_11                     (0x01U << EXTI_EMR_11_Pos)              /*!< Event Mask on line 11 */
#define EXTI_EMR_12_Pos                 (12)
#define EXTI_EMR_12                     (0x01U << EXTI_EMR_12_Pos)              /*!< Event Mask on line 12 */
#define EXTI_EMR_13_Pos                 (13)
#define EXTI_EMR_13                     (0x01U << EXTI_EMR_13_Pos)              /*!< Event Mask on line 13 */
#define EXTI_EMR_14_Pos                 (14)
#define EXTI_EMR_14                     (0x01U << EXTI_EMR_14_Pos)              /*!< Event Mask on line 14 */
#define EXTI_EMR_15_Pos                 (15)
#define EXTI_EMR_15                     (0x01U << EXTI_EMR_15_Pos)              /*!< Event Mask on line 15 */
#define EXTI_EMR_16_Pos                 (16)
#define EXTI_EMR_16                     (0x01U << EXTI_EMR_16_Pos)              /*!< Event Mask on line 16 */
#define EXTI_EMR_17_Pos                 (17)
#define EXTI_EMR_17                     (0x01U << EXTI_EMR_17_Pos)              /*!< Event Mask on line 17 */
#define EXTI_EMR_18_Pos                 (18)
#define EXTI_EMR_18                     (0x01U << EXTI_EMR_18_Pos)              /*!< Event Mask on line 18 */
#define EXTI_EMR_19_Pos                 (19)
#define EXTI_EMR_19                     (0x01U << EXTI_EMR_19_Pos)              /*!< Event Mask on line 19 */
#define EXTI_EMR_20_Pos                 (20)
#define EXTI_EMR_20                     (0x01U << EXTI_EMR_20_Pos)              /*!< Event Mask on line 20 */
#define EXTI_EMR_21_Pos                 (21)
#define EXTI_EMR_21                     (0x01U << EXTI_EMR_21_Pos)              /*!< Event Mask on line 21 */
#define EXTI_EMR_22_Pos                 (22)
#define EXTI_EMR_22                     (0x01U << EXTI_EMR_22_Pos)              /*!< Event Mask on line 22 */
#define EXTI_EMR_23_Pos                 (23)
#define EXTI_EMR_23                     (0x01U << EXTI_EMR_23_Pos)              /*!< Event Mask on line 23 */
#define EXTI_EMR_24_Pos                 (24)
#define EXTI_EMR_24                     (0x01U << EXTI_EMR_24_Pos)              /*!< Event Mask on line 24 */
#define EXTI_EMR_25_Pos                 (25)
#define EXTI_EMR_25                     (0x01U << EXTI_EMR_25_Pos)              /*!< Event Mask on line 25 */
#define EXTI_EMR_26_Pos                 (26)
#define EXTI_EMR_26                     (0x01U << EXTI_EMR_26_Pos)              /*!< Event Mask on line 26 */
#define EXTI_EMR_27_Pos                 (27)
#define EXTI_EMR_27                     (0x01U << EXTI_EMR_27_Pos)              /*!< Event Mask on line 27 */
#define EXTI_EMR_28_Pos                 (28)
#define EXTI_EMR_28                     (0x01U << EXTI_EMR_28_Pos)              /*!< Event Mask on line 28 */
#define EXTI_EMR_29_Pos                 (29)
#define EXTI_EMR_29                     (0x01U << EXTI_EMR_29_Pos)              /*!< Event Mask on line 29 */
#define EXTI_EMR_30_Pos                 (30)
#define EXTI_EMR_30                     (0x01U << EXTI_EMR_30_Pos)              /*!< Event Mask on line 30 */
#define EXTI_EMR_31_Pos                 (31)
#define EXTI_EMR_31                     (0x01U << EXTI_EMR_31_Pos)              /*!< Event Mask on line 31 */

/**
  * @brief EXTI_RTSR Register Bit Definition
  */
#define EXTI_RTSR_TR_Pos                (0)
#define EXTI_RTSR_TR                    (0xFFFFFFFFU << EXTI_RTSR_TR_Pos)       /*!< Rising trigger event configuration bit */

#define EXTI_RTSR_TR_0_Pos              (0)
#define EXTI_RTSR_TR_0                  (0x01U << EXTI_RTSR_TR_0_Pos)           /*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR_TR_1_Pos              (1)
#define EXTI_RTSR_TR_1                  (0x01U << EXTI_RTSR_TR_1_Pos)           /*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR_TR_2_Pos              (2)
#define EXTI_RTSR_TR_2                  (0x01U << EXTI_RTSR_TR_2_Pos)           /*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR_TR_3_Pos              (3)
#define EXTI_RTSR_TR_3                  (0x01U << EXTI_RTSR_TR_3_Pos)           /*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR_TR_4_Pos              (4)
#define EXTI_RTSR_TR_4                  (0x01U << EXTI_RTSR_TR_4_Pos)           /*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR_TR_5_Pos              (5)
#define EXTI_RTSR_TR_5                  (0x01U << EXTI_RTSR_TR_5_Pos)           /*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR_TR_6_Pos              (6)
#define EXTI_RTSR_TR_6                  (0x01U << EXTI_RTSR_TR_6_Pos)           /*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR_TR_7_Pos              (7)
#define EXTI_RTSR_TR_7                  (0x01U << EXTI_RTSR_TR_7_Pos)           /*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR_TR_8_Pos              (8)
#define EXTI_RTSR_TR_8                  (0x01U << EXTI_RTSR_TR_8_Pos)           /*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR_TR_9_Pos              (9)
#define EXTI_RTSR_TR_9                  (0x01U << EXTI_RTSR_TR_9_Pos)           /*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR_TR_10_Pos             (10)
#define EXTI_RTSR_TR_10                 (0x01U << EXTI_RTSR_TR_10_Pos)          /*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR_TR_11_Pos             (11)
#define EXTI_RTSR_TR_11                 (0x01U << EXTI_RTSR_TR_11_Pos)          /*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR_TR_12_Pos             (12)
#define EXTI_RTSR_TR_12                 (0x01U << EXTI_RTSR_TR_12_Pos)          /*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR_TR_13_Pos             (13)
#define EXTI_RTSR_TR_13                 (0x01U << EXTI_RTSR_TR_13_Pos)          /*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR_TR_14_Pos             (14)
#define EXTI_RTSR_TR_14                 (0x01U << EXTI_RTSR_TR_14_Pos)          /*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR_TR_15_Pos             (15)
#define EXTI_RTSR_TR_15                 (0x01U << EXTI_RTSR_TR_15_Pos)          /*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR_TR_16_Pos             (16)
#define EXTI_RTSR_TR_16                 (0x01U << EXTI_RTSR_TR_16_Pos)          /*!< Rising trigger event configuration bit of line 16 */
#define EXTI_RTSR_TR_17_Pos             (17)
#define EXTI_RTSR_TR_17                 (0x01U << EXTI_RTSR_TR_17_Pos)          /*!< Rising trigger event configuration bit of line 17 */
#define EXTI_RTSR_TR_18_Pos             (18)
#define EXTI_RTSR_TR_18                 (0x01U << EXTI_RTSR_TR_18_Pos)          /*!< Rising trigger event configuration bit of line 18 */
#define EXTI_RTSR_TR_19_Pos             (19)
#define EXTI_RTSR_TR_19                 (0x01U << EXTI_RTSR_TR_19_Pos)          /*!< Rising trigger event configuration bit of line 19 */
#define EXTI_RTSR_TR_20_Pos             (20)
#define EXTI_RTSR_TR_20                 (0x01U << EXTI_RTSR_TR_20_Pos)          /*!< Rising trigger event configuration bit of line 20 */
#define EXTI_RTSR_TR_21_Pos             (21)
#define EXTI_RTSR_TR_21                 (0x01U << EXTI_RTSR_TR_21_Pos)          /*!< Rising trigger event configuration bit of line 21 */
#define EXTI_RTSR_TR_22_Pos             (22)
#define EXTI_RTSR_TR_22                 (0x01U << EXTI_RTSR_TR_22_Pos)          /*!< Rising trigger event configuration bit of line 22 */
#define EXTI_RTSR_TR_23_Pos             (23)
#define EXTI_RTSR_TR_23                 (0x01U << EXTI_RTSR_TR_23_Pos)          /*!< Rising trigger event configuration bit of line 23 */
#define EXTI_RTSR_TR_24_Pos             (24)
#define EXTI_RTSR_TR_24                 (0x01U << EXTI_RTSR_TR_24_Pos)          /*!< Rising trigger event configuration bit of line 24 */
#define EXTI_RTSR_TR_25_Pos             (25)
#define EXTI_RTSR_TR_25                 (0x01U << EXTI_RTSR_TR_25_Pos)          /*!< Rising trigger event configuration bit of line 25 */
#define EXTI_RTSR_TR_26_Pos             (26)
#define EXTI_RTSR_TR_26                 (0x01U << EXTI_RTSR_TR_26_Pos)          /*!< Rising trigger event configuration bit of line 26 */
#define EXTI_RTSR_TR_27_Pos             (27)
#define EXTI_RTSR_TR_27                 (0x01U << EXTI_RTSR_TR_27_Pos)          /*!< Rising trigger event configuration bit of line 27 */
#define EXTI_RTSR_TR_28_Pos             (28)
#define EXTI_RTSR_TR_28                 (0x01U << EXTI_RTSR_TR_28_Pos)          /*!< Rising trigger event configuration bit of line 28 */
#define EXTI_RTSR_TR_29_Pos             (29)
#define EXTI_RTSR_TR_29                 (0x01U << EXTI_RTSR_TR_29_Pos)          /*!< Rising trigger event configuration bit of line 29 */
#define EXTI_RTSR_TR_30_Pos             (30)
#define EXTI_RTSR_TR_30                 (0x01U << EXTI_RTSR_TR_30_Pos)          /*!< Rising trigger event configuration bit of line 30 */
#define EXTI_RTSR_TR_31_Pos             (31)
#define EXTI_RTSR_TR_31                 (0x01U << EXTI_RTSR_TR_31_Pos)          /*!< Rising trigger event configuration bit of line 31 */

/**
  * @brief EXTI_FTSR Register Bit Definition
  */
#define EXTI_FTSR_TR_Pos                (0)
#define EXTI_FTSR_TR                    (0xFFFFFFFFU << EXTI_FTSR_TR_Pos)       /*!< Falling trigger event configuration bit */

#define EXTI_FTSR_TR_0_Pos              (0)
#define EXTI_FTSR_TR_0                  (0x01U << EXTI_FTSR_TR_0_Pos)           /*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR_TR_1_Pos              (1)
#define EXTI_FTSR_TR_1                  (0x01U << EXTI_FTSR_TR_1_Pos)           /*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR_TR_2_Pos              (2)
#define EXTI_FTSR_TR_2                  (0x01U << EXTI_FTSR_TR_2_Pos)           /*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR_TR_3_Pos              (3)
#define EXTI_FTSR_TR_3                  (0x01U << EXTI_FTSR_TR_3_Pos)           /*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR_TR_4_Pos              (4)
#define EXTI_FTSR_TR_4                  (0x01U << EXTI_FTSR_TR_4_Pos)           /*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR_TR_5_Pos              (5)
#define EXTI_FTSR_TR_5                  (0x01U << EXTI_FTSR_TR_5_Pos)           /*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR_TR_6_Pos              (6)
#define EXTI_FTSR_TR_6                  (0x01U << EXTI_FTSR_TR_6_Pos)           /*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR_TR_7_Pos              (7)
#define EXTI_FTSR_TR_7                  (0x01U << EXTI_FTSR_TR_7_Pos)           /*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR_TR_8_Pos              (8)
#define EXTI_FTSR_TR_8                  (0x01U << EXTI_FTSR_TR_8_Pos)           /*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR_TR_9_Pos              (9)
#define EXTI_FTSR_TR_9                  (0x01U << EXTI_FTSR_TR_9_Pos)           /*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR_TR_10_Pos             (10)
#define EXTI_FTSR_TR_10                 (0x01U << EXTI_FTSR_TR_10_Pos)          /*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR_TR_11_Pos             (11)
#define EXTI_FTSR_TR_11                 (0x01U << EXTI_FTSR_TR_11_Pos)          /*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR_TR_12_Pos             (12)
#define EXTI_FTSR_TR_12                 (0x01U << EXTI_FTSR_TR_12_Pos)          /*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR_TR_13_Pos             (13)
#define EXTI_FTSR_TR_13                 (0x01U << EXTI_FTSR_TR_13_Pos)          /*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR_TR_14_Pos             (14)
#define EXTI_FTSR_TR_14                 (0x01U << EXTI_FTSR_TR_14_Pos)          /*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR_TR_15_Pos             (15)
#define EXTI_FTSR_TR_15                 (0x01U << EXTI_FTSR_TR_15_Pos)          /*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR_TR_16_Pos             (16)
#define EXTI_FTSR_TR_16                 (0x01U << EXTI_FTSR_TR_16_Pos)          /*!< Falling trigger event configuration bit of line 16 */
#define EXTI_FTSR_TR_17_Pos             (17)
#define EXTI_FTSR_TR_17                 (0x01U << EXTI_FTSR_TR_17_Pos)          /*!< Falling trigger event configuration bit of line 17 */
#define EXTI_FTSR_TR_18_Pos             (18)
#define EXTI_FTSR_TR_18                 (0x01U << EXTI_FTSR_TR_18_Pos)          /*!< Falling trigger event configuration bit of line 18 */
#define EXTI_FTSR_TR_19_Pos             (19)
#define EXTI_FTSR_TR_19                 (0x01U << EXTI_FTSR_TR_19_Pos)          /*!< Falling trigger event configuration bit of line 19 */
#define EXTI_FTSR_TR_20_Pos             (20)
#define EXTI_FTSR_TR_20                 (0x01U << EXTI_FTSR_TR_20_Pos)          /*!< Falling trigger event configuration bit of line 20 */
#define EXTI_FTSR_TR_21_Pos             (21)
#define EXTI_FTSR_TR_21                 (0x01U << EXTI_FTSR_TR_21_Pos)          /*!< Falling trigger event configuration bit of line 21 */
#define EXTI_FTSR_TR_22_Pos             (22)
#define EXTI_FTSR_TR_22                 (0x01U << EXTI_FTSR_TR_22_Pos)          /*!< Falling trigger event configuration bit of line 22 */
#define EXTI_FTSR_TR_23_Pos             (23)
#define EXTI_FTSR_TR_23                 (0x01U << EXTI_FTSR_TR_23_Pos)          /*!< Falling trigger event configuration bit of line 23 */
#define EXTI_FTSR_TR_24_Pos             (24)
#define EXTI_FTSR_TR_24                 (0x01U << EXTI_FTSR_TR_24_Pos)          /*!< Falling trigger event configuration bit of line 24 */
#define EXTI_FTSR_TR_25_Pos             (25)
#define EXTI_FTSR_TR_25                 (0x01U << EXTI_FTSR_TR_25_Pos)          /*!< Falling trigger event configuration bit of line 25 */
#define EXTI_FTSR_TR_26_Pos             (26)
#define EXTI_FTSR_TR_26                 (0x01U << EXTI_FTSR_TR_26_Pos)          /*!< Falling trigger event configuration bit of line 26 */
#define EXTI_FTSR_TR_27_Pos             (27)
#define EXTI_FTSR_TR_27                 (0x01U << EXTI_FTSR_TR_27_Pos)          /*!< Falling trigger event configuration bit of line 27 */
#define EXTI_FTSR_TR_28_Pos             (28)
#define EXTI_FTSR_TR_28                 (0x01U << EXTI_FTSR_TR_28_Pos)          /*!< Falling trigger event configuration bit of line 28 */
#define EXTI_FTSR_TR_29_Pos             (29)
#define EXTI_FTSR_TR_29                 (0x01U << EXTI_FTSR_TR_29_Pos)          /*!< Falling trigger event configuration bit of line 29 */
#define EXTI_FTSR_TR_30_Pos             (30)
#define EXTI_FTSR_TR_30                 (0x01U << EXTI_FTSR_TR_30_Pos)          /*!< Falling trigger event configuration bit of line 30 */
#define EXTI_FTSR_TR_31_Pos             (31)
#define EXTI_FTSR_TR_31                 (0x01U << EXTI_FTSR_TR_31_Pos)          /*!< Falling trigger event configuration bit of line 31 */

/**
  * @brief EXTI_SWIER Register Bit Definition
  */
#define EXTI_SWIER_Pos                  (0)
#define EXTI_SWIER                      (0x01U << EXTI_SWIER_Pos)               /*!< Software Interrupt */

#define EXTI_SWIER_0_Pos                (0)
#define EXTI_SWIER_0                    (0x01U << EXTI_SWIER_0_Pos)             /*!< Software Interrupt on line  0 */
#define EXTI_SWIER_1_Pos                (1)
#define EXTI_SWIER_1                    (0x01U << EXTI_SWIER_1_Pos)             /*!< Software Interrupt on line  1 */
#define EXTI_SWIER_2_Pos                (2)
#define EXTI_SWIER_2                    (0x01U << EXTI_SWIER_2_Pos)             /*!< Software Interrupt on line  2 */
#define EXTI_SWIER_3_Pos                (3)
#define EXTI_SWIER_3                    (0x01U << EXTI_SWIER_3_Pos)             /*!< Software Interrupt on line  3 */
#define EXTI_SWIER_4_Pos                (4)
#define EXTI_SWIER_4                    (0x01U << EXTI_SWIER_4_Pos)             /*!< Software Interrupt on line  4 */
#define EXTI_SWIER_5_Pos                (5)
#define EXTI_SWIER_5                    (0x01U << EXTI_SWIER_5_Pos)             /*!< Software Interrupt on line  5 */
#define EXTI_SWIER_6_Pos                (6)
#define EXTI_SWIER_6                    (0x01U << EXTI_SWIER_6_Pos)             /*!< Software Interrupt on line  6 */
#define EXTI_SWIER_7_Pos                (7)
#define EXTI_SWIER_7                    (0x01U << EXTI_SWIER_7_Pos)             /*!< Software Interrupt on line  7 */
#define EXTI_SWIER_8_Pos                (8)
#define EXTI_SWIER_8                    (0x01U << EXTI_SWIER_8_Pos)             /*!< Software Interrupt on line  8 */
#define EXTI_SWIER_9_Pos                (9)
#define EXTI_SWIER_9                    (0x01U << EXTI_SWIER_9_Pos)             /*!< Software Interrupt on line  9 */
#define EXTI_SWIER_10_Pos               (10)
#define EXTI_SWIER_10                   (0x01U << EXTI_SWIER_10_Pos)            /*!< Software Interrupt on line  10 */
#define EXTI_SWIER_11_Pos               (11)
#define EXTI_SWIER_11                   (0x01U << EXTI_SWIER_11_Pos)            /*!< Software Interrupt on line  11 */
#define EXTI_SWIER_12_Pos               (12)
#define EXTI_SWIER_12                   (0x01U << EXTI_SWIER_12_Pos)            /*!< Software Interrupt on line  12 */
#define EXTI_SWIER_13_Pos               (13)
#define EXTI_SWIER_13                   (0x01U << EXTI_SWIER_13_Pos)            /*!< Software Interrupt on line  13 */
#define EXTI_SWIER_14_Pos               (14)
#define EXTI_SWIER_14                   (0x01U << EXTI_SWIER_14_Pos)            /*!< Software Interrupt on line  14 */
#define EXTI_SWIER_15_Pos               (15)
#define EXTI_SWIER_15                   (0x01U << EXTI_SWIER_15_Pos)            /*!< Software Interrupt on line  15 */
#define EXTI_SWIER_16_Pos               (16)
#define EXTI_SWIER_16                   (0x01U << EXTI_SWIER_16_Pos)            /*!< Software Interrupt on line  16 */
#define EXTI_SWIER_17_Pos               (17)
#define EXTI_SWIER_17                   (0x01U << EXTI_SWIER_17_Pos)            /*!< Software Interrupt on line  17 */
#define EXTI_SWIER_18_Pos               (18)
#define EXTI_SWIER_18                   (0x01U << EXTI_SWIER_18_Pos)            /*!< Software Interrupt on line  18 */
#define EXTI_SWIER_19_Pos               (19)
#define EXTI_SWIER_19                   (0x01U << EXTI_SWIER_19_Pos)            /*!< Software Interrupt on line  19 */
#define EXTI_SWIER_20_Pos               (20)
#define EXTI_SWIER_20                   (0x01U << EXTI_SWIER_20_Pos)            /*!< Software Interrupt on line  20 */
#define EXTI_SWIER_21_Pos               (21)
#define EXTI_SWIER_21                   (0x01U << EXTI_SWIER_21_Pos)            /*!< Software Interrupt on line  21 */
#define EXTI_SWIER_22_Pos               (22)
#define EXTI_SWIER_22                   (0x01U << EXTI_SWIER_22_Pos)            /*!< Software Interrupt on line  22 */
#define EXTI_SWIER_23_Pos               (23)
#define EXTI_SWIER_23                   (0x01U << EXTI_SWIER_23_Pos)            /*!< Software Interrupt on line  23 */
#define EXTI_SWIER_24_Pos               (24)
#define EXTI_SWIER_24                   (0x01U << EXTI_SWIER_24_Pos)            /*!< Software Interrupt on line  24 */
#define EXTI_SWIER_25_Pos               (25)
#define EXTI_SWIER_25                   (0x01U << EXTI_SWIER_25_Pos)            /*!< Software Interrupt on line  25 */
#define EXTI_SWIER_26_Pos               (26)
#define EXTI_SWIER_26                   (0x01U << EXTI_SWIER_26_Pos)            /*!< Software Interrupt on line  26 */
#define EXTI_SWIER_27_Pos               (27)
#define EXTI_SWIER_27                   (0x01U << EXTI_SWIER_27_Pos)            /*!< Software Interrupt on line  27 */
#define EXTI_SWIER_28_Pos               (28)
#define EXTI_SWIER_28                   (0x01U << EXTI_SWIER_28_Pos)            /*!< Software Interrupt on line  28 */
#define EXTI_SWIER_29_Pos               (29)
#define EXTI_SWIER_29                   (0x01U << EXTI_SWIER_29_Pos)            /*!< Software Interrupt on line  29 */
#define EXTI_SWIER_30_Pos               (30)
#define EXTI_SWIER_30                   (0x01U << EXTI_SWIER_30_Pos)            /*!< Software Interrupt on line  30 */
#define EXTI_SWIER_31_Pos               (31)
#define EXTI_SWIER_31                   (0x01U << EXTI_SWIER_31_Pos)            /*!< Software Interrupt on line  31 */

/**
  * @brief EXTI_PR Register Bit Definition
  */
#define EXTI_PR_Pos                     (0)
#define EXTI_PR                         (0x01U << EXTI_PR_Pos)                  /*!< Pending bit */

#define EXTI_PR_0_Pos                   (0)
#define EXTI_PR_0                       (0x01U << EXTI_PR_0_Pos)                /*!< Pending bit 0 */
#define EXTI_PR_1_Pos                   (1)
#define EXTI_PR_1                       (0x01U << EXTI_PR_1_Pos)                /*!< Pending bit 1 */
#define EXTI_PR_2_Pos                   (2)
#define EXTI_PR_2                       (0x01U << EXTI_PR_2_Pos)                /*!< Pending bit 2 */
#define EXTI_PR_3_Pos                   (3)
#define EXTI_PR_3                       (0x01U << EXTI_PR_3_Pos)                /*!< Pending bit 3 */
#define EXTI_PR_4_Pos                   (4)
#define EXTI_PR_4                       (0x01U << EXTI_PR_4_Pos)                /*!< Pending bit 4 */
#define EXTI_PR_5_Pos                   (5)
#define EXTI_PR_5                       (0x01U << EXTI_PR_5_Pos)                /*!< Pending bit 5 */
#define EXTI_PR_6_Pos                   (6)
#define EXTI_PR_6                       (0x01U << EXTI_PR_6_Pos)                /*!< Pending bit 6 */
#define EXTI_PR_7_Pos                   (7)
#define EXTI_PR_7                       (0x01U << EXTI_PR_7_Pos)                /*!< Pending bit 7 */
#define EXTI_PR_8_Pos                   (8)
#define EXTI_PR_8                       (0x01U << EXTI_PR_8_Pos)                /*!< Pending bit 8 */
#define EXTI_PR_9_Pos                   (9)
#define EXTI_PR_9                       (0x01U << EXTI_PR_9_Pos)                /*!< Pending bit 9 */
#define EXTI_PR_10_Pos                  (10)
#define EXTI_PR_10                      (0x01U << EXTI_PR_10_Pos)               /*!< Pending bit 10 */
#define EXTI_PR_11_Pos                  (11)
#define EXTI_PR_11                      (0x01U << EXTI_PR_11_Pos)               /*!< Pending bit 11 */
#define EXTI_PR_12_Pos                  (12)
#define EXTI_PR_12                      (0x01U << EXTI_PR_12_Pos)               /*!< Pending bit 12 */
#define EXTI_PR_13_Pos                  (13)
#define EXTI_PR_13                      (0x01U << EXTI_PR_13_Pos)               /*!< Pending bit 13 */
#define EXTI_PR_14_Pos                  (14)
#define EXTI_PR_14                      (0x01U << EXTI_PR_14_Pos)               /*!< Pending bit 14 */
#define EXTI_PR_15_Pos                  (15)
#define EXTI_PR_15                      (0x01U << EXTI_PR_15_Pos)               /*!< Pending bit 15 */
#define EXTI_PR_16_Pos                  (16)
#define EXTI_PR_16                      (0x01U << EXTI_PR_16_Pos)               /*!< Pending bit 16 */
#define EXTI_PR_17_Pos                  (17)
#define EXTI_PR_17                      (0x01U << EXTI_PR_17_Pos)               /*!< Pending bit 17 */
#define EXTI_PR_18_Pos                  (18)
#define EXTI_PR_18                      (0x01U << EXTI_PR_18_Pos)               /*!< Pending bit 18 */
#define EXTI_PR_19_Pos                  (19)
#define EXTI_PR_19                      (0x01U << EXTI_PR_19_Pos)               /*!< Pending bit 19 */
#define EXTI_PR_20_Pos                  (20)
#define EXTI_PR_20                      (0x01U << EXTI_PR_20_Pos)               /*!< Pending bit 20 */
#define EXTI_PR_21_Pos                  (21)
#define EXTI_PR_21                      (0x01U << EXTI_PR_21_Pos)               /*!< Pending bit 21 */
#define EXTI_PR_22_Pos                  (22)
#define EXTI_PR_22                      (0x01U << EXTI_PR_22_Pos)               /*!< Pending bit 22 */
#define EXTI_PR_23_Pos                  (23)
#define EXTI_PR_23                      (0x01U << EXTI_PR_23_Pos)               /*!< Pending bit 23 */
#define EXTI_PR_24_Pos                  (24)
#define EXTI_PR_24                      (0x01U << EXTI_PR_24_Pos)               /*!< Pending bit 24 */
#define EXTI_PR_25_Pos                  (25)
#define EXTI_PR_25                      (0x01U << EXTI_PR_25_Pos)               /*!< Pending bit 25 */
#define EXTI_PR_26_Pos                  (26)
#define EXTI_PR_26                      (0x01U << EXTI_PR_26_Pos)               /*!< Pending bit 26 */
#define EXTI_PR_27_Pos                  (27)
#define EXTI_PR_27                      (0x01U << EXTI_PR_27_Pos)               /*!< Pending bit 27 */
#define EXTI_PR_28_Pos                  (28)
#define EXTI_PR_28                      (0x01U << EXTI_PR_28_Pos)               /*!< Pending bit 28 */
#define EXTI_PR_29_Pos                  (29)
#define EXTI_PR_29                      (0x01U << EXTI_PR_29_Pos)               /*!< Pending bit 29 */
#define EXTI_PR_30_Pos                  (30)
#define EXTI_PR_30                      (0x01U << EXTI_PR_30_Pos)               /*!< Pending bit 30 */
#define EXTI_PR_31_Pos                  (31)
#define EXTI_PR_31                      (0x01U << EXTI_PR_31_Pos)               /*!< Pending bit 31 */

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
