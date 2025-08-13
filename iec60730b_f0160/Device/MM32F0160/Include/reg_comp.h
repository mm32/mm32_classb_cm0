/*
 *******************************************************************************
    @file     reg_comp.h
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

#ifndef __REG_COMP_H
#define __REG_COMP_H

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
  * @brief COMP Base Address Definition
  */
#define COMP_BASE                       (APB2PERIPH_BASE + 0x3C00)              /*!< Base Address: 0x40013C00 */

/**
  * @brief Comparators Register Structure Definition
  */
typedef struct {
    __IO uint32_t COMP1_CSR;                                                    /*!< COMP1 Control Status Register                  offset: 0x00 */
    __IO uint32_t COMP2_CSR;                                                    /*!< COMP2 Control Status Register                  offset: 0x04 */
    __IO uint32_t RESERVED0x08[4];                                              /*!< Reserved                                       offset: 0x08~0x14 */
    __IO uint32_t COMP_CRV;                                                     /*!< COMP external reference voltage register       offset: 0x18 */
    __IO uint32_t COMP1_POLL;                                                   /*!< COMP1 polling register                         offset: 0x1C */
    __IO uint32_t COMP2_POLL;                                                   /*!< COMP2 polling register                         offset: 0x20 */
} COMP_TypeDef;

/**
  * @brief COMP type pointer Definition
  */
#define COMP                            ((COMP_TypeDef*) COMP_BASE)

/**
  * @brief COMP_CSR Register Bit Definition
  */
#define COMP_CSR_EN_Pos                 (0)
#define COMP_CSR_EN                     (0x01U << COMP_CSR_EN_Pos)              /*!< Comparator enable */
#define COMP_CSR_MODE_Pos               (2)
#define COMP_CSR_MODE                   (0x03U << COMP_CSR_MODE_Pos)            /*!< Comparator mode */
#define COMP_CSR_MODE_LOWESTPOWER       (0x03U << COMP_CSR_MODE_Pos)            /*!< Comparator lowest power mode */
#define COMP_CSR_MODE_LOWPOWER          (0x02U << COMP_CSR_MODE_Pos)            /*!< Comparator low power mode */
#define COMP_CSR_MODE_MEDIUMRATE        (0x01U << COMP_CSR_MODE_Pos)            /*!< Comparator medium rate mode */
#define COMP_CSR_MODE_HIGHRATE          (0x00U << COMP_CSR_MODE_Pos)            /*!< Comparator high rate mode */

#define COMP_CSR_INM_SEL_Pos            (4)
#define COMP_CSR_INM_SEL                (0x07U << COMP_CSR_INM_SEL_Pos)         /*!< Comparator inverting input selection */
#define COMP_CSR_INM_SEL_0              (0x00U << COMP_CSR_INM_SEL_Pos)         /*!< INM0 as COMP inverting input */
#define COMP_CSR_INM_SEL_1              (0x01U << COMP_CSR_INM_SEL_Pos)         /*!< INM1 as COMP inverting input */
#define COMP_CSR_INM_SEL_2              (0x02U << COMP_CSR_INM_SEL_Pos)         /*!< INM2 as COMP inverting input */
#define COMP_CSR_INM_SEL_3              (0x03U << COMP_CSR_INM_SEL_Pos)         /*!< INM3 as COMP inverting input */
#define COMP_CSR_INM_SEL_4              (0x04U << COMP_CSR_INM_SEL_Pos)         /*!< INM4_CRV as COMP inverting input */

#define COMP_CSR_INP_SEL_Pos            (7)
#define COMP_CSR_INP_SEL                (0x03U << COMP_CSR_INP_SEL_Pos)         /*!< Comparator non-inverting input selection */
#define COMP_CSR_INP_SEL_0              (0x00U << COMP_CSR_INP_SEL_Pos)         /*!< INP0 as COMP non-inverting input */
#define COMP_CSR_INP_SEL_1              (0x01U << COMP_CSR_INP_SEL_Pos)         /*!< INP1 as COMP non-inverting input */
#define COMP_CSR_INP_SEL_2              (0x02U << COMP_CSR_INP_SEL_Pos)         /*!< INP2 as COMP non-inverting input */
#define COMP_CSR_INP_SEL_3              (0x03U << COMP_CSR_INP_SEL_Pos)         /*!< INP3 as COMP non-inverting input */

#define COMP_CSR_OUT_SEL_Pos            (10)
#define COMP_CSR_OUT_SEL                (0x0FU << COMP_CSR_OUT_SEL_Pos)         /*!< Comparator output selection */
#define COMP_CSR_OUT_SEL_TIM1_BRAKE     (0x02U << COMP_CSR_OUT_SEL_Pos)         /*!< Timer1 Break input */
#define COMP_CSR_OUT_SEL_TIM1_OCREFCLR  (0x06U << COMP_CSR_OUT_SEL_Pos)         /*!< Timer1 ocrefclear input */
#define COMP_CSR_OUT_SEL_TIM1_CAPTURE1  (0x07U << COMP_CSR_OUT_SEL_Pos)         /*!< Timer1 input capture 1 */
#define COMP_CSR_OUT_SEL_TIM2_CAPTURE4  (0x08U << COMP_CSR_OUT_SEL_Pos)         /*!< Timer2 input capture 4 */
#define COMP_CSR_OUT_SEL_TIM2_OCREFCLR  (0x09U << COMP_CSR_OUT_SEL_Pos)         /*!< Timer2 ocrefclear input */
#define COMP_CSR_OUT_SEL_TIM3_CAPTURE1  (0x0AU << COMP_CSR_OUT_SEL_Pos)         /*!< Timer3 input capture 1 */
#define COMP_CSR_OUT_SEL_TIM3_OCREFCLR  (0x0BU << COMP_CSR_OUT_SEL_Pos)         /*!< Timer3 ocrefclear input */
#define COMP_CSR_OUT_SEL_LPTIMER_TRIG   (0x0FU << COMP_CSR_OUT_SEL_Pos)         /*!< LPTIMER TRIG input */

#define COMP_CSR_POL_Pos                (15)
#define COMP_CSR_POL                    (0x01U << COMP_CSR_POL_Pos)             /*!< Comparator output polarity */
#define COMP_CSR_HYST_Pos               (16)
#define COMP_CSR_HYST                   (0x03U << COMP_CSR_HYST_Pos)            /*!< Comparator hysteresis */
#define COMP_CSR_HYST_0                 (0x00U << COMP_CSR_HYST_Pos)            /*!< Hysteresis Voltage: 0mV */
#define COMP_CSR_HYST_1                 (0x01U << COMP_CSR_HYST_Pos)            /*!< Hysteresis Voltage: 22mV/15mV */
#define COMP_CSR_HYST_2                 (0x02U << COMP_CSR_HYST_Pos)            /*!< Hysteresis Voltage: 45mV/32mV */
#define COMP_CSR_HYST_3                 (0x03U << COMP_CSR_HYST_Pos)            /*!< Hysteresis Voltage: 85mV/60mV */

#define COMP_CSR_OFLT_Pos               (18)
#define COMP_CSR_OFLT                   (0x07U << COMP_CSR_OFLT_Pos)            /*!< Comparator output filter */
#define COMP_CSR_OFLT_0                 (0x00U << COMP_CSR_OFLT_Pos)            /*!< 0 clock cycle */
#define COMP_CSR_OFLT_1                 (0x01U << COMP_CSR_OFLT_Pos)            /*!< 2 clock cycle */
#define COMP_CSR_OFLT_2                 (0x02U << COMP_CSR_OFLT_Pos)            /*!< 4 clock cycle */
#define COMP_CSR_OFLT_3                 (0x03U << COMP_CSR_OFLT_Pos)            /*!< 8 clock cycle */
#define COMP_CSR_OFLT_4                 (0x04U << COMP_CSR_OFLT_Pos)            /*!< 16 clock cycle */
#define COMP_CSR_OFLT_5                 (0x05U << COMP_CSR_OFLT_Pos)            /*!< 32 clock cycle */
#define COMP_CSR_OFLT_6                 (0x06U << COMP_CSR_OFLT_Pos)            /*!< 64 clock cycle */
#define COMP_CSR_OFLT_7                 (0x07U << COMP_CSR_OFLT_Pos)            /*!< 128 clock cycle */
#define COMP_CSR_OUT_ANA_SEL_Pos        (29)
#define COMP_CSR_OUT_ANA_SEL            (0x01U << COMP_CSR_OUT_ANA_SEL_Pos)     /*!< Comparator x output source select Analog output */
#define COMP_CSR_OUT_Pos                (30)
#define COMP_CSR_OUT                    (0x01U << COMP_CSR_OUT_Pos)             /*!< Comparator output status */
#define COMP_CSR_LOCK_Pos               (31)
#define COMP_CSR_LOCK                   (0x01U << COMP_CSR_LOCK_Pos)            /*!< Comparator lock */

/**
  * @brief COMP_CRV Register Bit Definition
  */
#define COMP_CRV_SEL_Pos                (0)
#define COMP_CRV_SEL                    (0x0FU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_1_20               (0x00U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_2_20               (0x01U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_3_20               (0x02U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_4_20               (0x03U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_5_20               (0x04U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_6_20               (0x05U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_7_20               (0x06U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_8_20               (0x07U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_9_20               (0x08U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_10_20              (0x09U << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_11_20              (0x0AU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_12_20              (0x0BU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_13_20              (0x0CU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_14_20              (0x0DU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_15_20              (0x0EU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_16_20              (0x0FU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */

#define COMP_CRV_EN_Pos                 (4)
#define COMP_CRV_EN                     (0x01U << COMP_CRV_EN_Pos)              /*!< Comparator external reference voltage enable */
#define COMP_CRV_EN_DISABLE             (0x00U << COMP_CRV_EN_Pos)              /*!< Disable comparator external reference voltage */
#define COMP_CRV_EN_ENABLE              (0x01U << COMP_CRV_EN_Pos)              /*!< Enable comparator external reference voltage */
#define COMP_CRV_SRC_Pos                (5)
#define COMP_CRV_SRC                    (0x01U << COMP_CRV_SRC_Pos)             /*!< Comparator external reference voltage source select */
#define COMP_CRV_SRC_VREF               (0x00U << COMP_CRV_SRC_Pos)             /*!< Select VREF */
#define COMP_CRV_SRC_AVDD               (0x01U << COMP_CRV_SRC_Pos)             /*!< Select AVDD */

/**
  * @brief COMP_POL Register Bit Definition
  */
#define COMP_POLL_EN_Pos                (0)
#define COMP_POLL_EN                    (0x01U << COMP_POLL_EN_Pos)             /*!< Comparator polling enable */
#define COMP_POLL_EN_DISABLE            (0x00U << COMP_POLL_EN_Pos)             /*!< Disable comparator polling mode */
#define COMP_POLL_EN_ENABLE             (0x01U << COMP_POLL_EN_Pos)             /*!< Enable comparator polling mode */
#define COMP_POLL_CH_Pos                (1)
#define COMP_POLL_CH                    (0x01U << COMP_POLL_CH_Pos)             /*!< Comparator polling channel */
#define COMP_POLL_CH_1_2                (0x00U << COMP_POLL_CH_Pos)             /*!< Polling channel 1/2 */
#define COMP_POLL_CH_1_2_3              (0x01U << COMP_POLL_CH_Pos)             /*!< Polling channel 1/2/3 */
#define COMP_POLL_FIXN_Pos              (2)
#define COMP_POLL_FIXN                  (0x01U << COMP_POLL_FIXN_Pos)           /*!< Polling inverting input fix */
#define COMP_POLL_FIXN_NOTFIXED         (0x00U << COMP_POLL_FIXN_Pos)           /*!< Polling channel inverting input is not fixed */
#define COMP_POLL_FIXN_FIXED            (0x01U << COMP_POLL_FIXN_Pos)           /*!< Polling channel inverting input fixed */
#define COMP_POLL_PERIOD_Pos            (4)
#define COMP_POLL_PERIOD                (0x07U << COMP_POLL_PERIOD_Pos)         /*!< polling wait cycle */
#define COMP_POLL_PERIOD_1              (0x00U << COMP_POLL_PERIOD_Pos)         /*!< 1 clock cycle */
#define COMP_POLL_PERIOD_2              (0x01U << COMP_POLL_PERIOD_Pos)         /*!< 2 clock cycle */
#define COMP_POLL_PERIOD_4              (0x02U << COMP_POLL_PERIOD_Pos)         /*!< 4 clock cycle */
#define COMP_POLL_PERIOD_8              (0x03U << COMP_POLL_PERIOD_Pos)         /*!< 8 clock cycle */
#define COMP_POLL_PERIOD_16             (0x04U << COMP_POLL_PERIOD_Pos)         /*!< 16 clock cycle */
#define COMP_POLL_PERIOD_32             (0x05U << COMP_POLL_PERIOD_Pos)         /*!< 32 clock cycle */
#define COMP_POLL_PERIOD_64             (0x06U << COMP_POLL_PERIOD_Pos)         /*!< 64 clock cycle */
#define COMP_POLL_PERIOD_128            (0x07U << COMP_POLL_PERIOD_Pos)         /*!< 128 clock cycle */
#define COMP_POLL_POUT_Pos              (8)
#define COMP_POLL_POUT                  (0x07U << COMP_POLL_POUT_Pos)           /*!< Polling output */
#define COMP_POLL_POUT_Low              (0x00U << COMP_POLL_POUT_Pos)           /*!< Non-inverting input is lower than inverting input */
#define COMP_POLL_POUT_High             (0x01U << COMP_POLL_POUT_Pos)           /*!< Non-inverting input is higher than inverting input */

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
