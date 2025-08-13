/*
 *******************************************************************************
    @file     lptim.h
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

#ifndef __REG_LPTIM_H
#define __REG_LPTIM_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if 0
/* IP_LPT_imer_DesignSpec_v1.4 */
#endif

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
  * @brief LPTIM Base Address Definition
  */
#define LPTIM_BASE                      (APB2PERIPH_BASE + 0x2800)              /*!< Base Address: 0x40012800 */

/**
  * @brief LPTIM Register Structure Definition
  */
typedef struct {
    __IO uint32_t  CFG;                                                         /*!< configuration register                                       offset: 0x00 */
    __IO uint32_t  IE;                                                          /*!< interrupt enable register                                    offset: 0x04 */
    __IO uint32_t  IF;                                                          /*!< interrupt flag register                                      offset: 0x08 */
    __IO uint32_t  CTRL;                                                        /*!< control register                                             offset: 0x0C */
    __IO uint32_t  CNT;                                                         /*!< count register                                               offset: 0x10 */
    __IO uint32_t  CMP;                                                         /*!< compare value register                                       offset: 0x14 */
    __IO uint32_t  TARGET;                                                      /*!< target value register                                        offset: 0x18 */
} LPTIM_TypeDef;

/**
  * @brief LPTIM type pointer Definition
  */
#define LPTIM1                          ((LPTIM_TypeDef*) LPTIM_BASE)

/**
  * @brief LPT_CFG Register Bit Definition
  */
#define LPT_CFG_MODE_Pos                (0)
#define LPT_CFG_MODE                    (0x01U << LPT_CFG_MODE_Pos)             /*!< Counting mode */
#define LPT_CFG_TMODE_Pos               (1)
#define LPT_CFG_TMODE_Msk               (0x03U << LPT_CFG_TMODE_Pos)
#define LPT_CFG_TMODE_0                 (0x00U << LPT_CFG_TMODE_Pos)            /*!< Normal timer mode with waveform output */
#define LPT_CFG_TMODE_1                 (0x01U << LPT_CFG_TMODE_Pos)            /*!< Trigger pulse trigger count mode */
#define LPT_CFG_TMODE_2                 (0x02U << LPT_CFG_TMODE_Pos)            /*!< Normal timer mode with waveform output */
#define LPT_CFG_TMODE_3                 (0x03U << LPT_CFG_TMODE_Pos)            /*!< Timerout mode */
#define LPT_CFG_PWM_Pos                 (3)
#define LPT_CFG_PWM                     (0x01U << LPT_CFG_PWM_Pos)              /*!< PWM mode output */
#define LPT_CFG_POLARITY_Pos            (4)
#define LPT_CFG_POLARITY                (0x01U << LPT_CFG_POLARITY_Pos)         /*!< Compare waveform polarity select */
#define LPT_CFG_TRIGSEL_Pos             (5)
#define LPT_CFG_TRIGSEL                 (0x01U << LPT_CFG_TRIGSEL_Pos)          /*!< COMP input trigger */
#define LPT_CFG_TRIGCFG_Pos             (6)
#define LPT_CFG_TRIGCFG_Msk             (0x03U << LPT_CFG_TRIGCFG_Pos)
#define LPT_CFG_TRIGCFG_Rise            (0x00U << LPT_CFG_TRIGCFG_Pos)          /*!< External input signal rising edge trigger */
#define LPT_CFG_TRIGCFG_Fall            (0x01U << LPT_CFG_TRIGCFG_Pos)          /*!< External input signal falling edge trigger */
#define LPT_CFG_TRIGCFG_Both            (0x02U << LPT_CFG_TRIGCFG_Pos)          /*!< External input signal rising and falling edge trigger */
#define LPT_CFG_DIVSEL_Pos              (8)
#define LPT_CFG_DIVSEL_Msk              (0x07U << LPT_CFG_DIVSEL_Pos)
#define LPT_CFG_DIVSEL_1                (0x00U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 1 */
#define LPT_CFG_DIVSEL_2                (0x01U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 2 */
#define LPT_CFG_DIVSEL_4                (0x02U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 4 */
#define LPT_CFG_DIVSEL_8                (0x03U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 8 */
#define LPT_CFG_DIVSEL_16               (0x04U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 16 */
#define LPT_CFG_DIVSEL_32               (0x05U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 32 */
#define LPT_CFG_DIVSEL_64               (0x06U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 64 */
#define LPT_CFG_DIVSEL_128              (0x07U << LPT_CFG_DIVSEL_Pos)           /*!< Count clock divided by 128 */
#define LPT_CFG_FLTEN_Pos               (15)
#define LPT_CFG_FLTEN                   (0x01U << LPT_CFG_FLTEN_Pos)            /*!< Input signal filtering enable */

/**
  * @brief LPT_IE Register Bit Definition
  */
#define LPT_IE_OVIE_Pos                 (0)
#define LPT_IE_OVIE                     (0x01U << LPT_IE_OVIE_Pos)              /*!< Counter overflow interrupt enable */
#define LPT_IE_TRIGIE_Pos               (1)
#define LPT_IE_TRIGIE                   (0x01U << LPT_IE_TRIGIE_Pos)            /*!< Counter value and comparison value match interrupt enable */
#define LPT_IE_COMPIE_Pos               (2)
#define LPT_IE_COMPIE                   (0x01U << LPT_IE_COMPIE_Pos)            /*!< External trigger arrival interrupt enable */

/**
  * @brief LPT_IF Register Bit Definition
  */
#define LPT_IF_OVIF_Pos                 (0)
#define LPT_IF_OVIF                     (0x01U << LPT_IF_OVIF_Pos)              /*!< Counter overflow interrupt flag */
#define LPT_IF_TRIGIF_Pos               (1)
#define LPT_IF_TRIGIF                   (0x01U << LPT_IF_TRIGIF_Pos)            /*!< Counter value and comparison value match interrupt flag */
#define LPT_IF_COMPIF_Pos               (2)
#define LPT_IF_COMPIF                   (0x01U << LPT_IF_COMPIF_Pos)            /*!< External trigger arrival interrupt flag */

/**
  * @brief LPT_CTRL Register Bit Definition
  */
#define LPT_CTRL_LPTEN_Pos              (0)
#define LPT_CTRL_LPTEN                  (0x01U << LPT_CTRL_LPTEN_Pos)           /*!< Enable counter count */

/**
  * @brief LPT_CNT Register Bit Definition
  */
#define LPT_CNT_CNT_Pos                 (0)
#define LPT_CNT_CNT                     (0xFFFFU << LPT_CNT_CNT_Pos)            /*!< counter count value */

/**
  * @brief LPT_CMP Register Bit Definition
  */
#define LPT_CMP_COMPARE_REG_Pos         (0)
#define LPT_CMP_COMPARE_REG             (0xFFFFU << LPT_CMP_COMPARE_REG_Pos)    /*!< compare value */

/**
  * @brief LPT_TARGET Register Bit Definition
  */
#define LPT_TARGET_REG_Pos              (0)
#define LPT_TARGET_REG                  (0xFFFFU << LPT_TARGET_REG_Pos)         /*!< target value */



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
