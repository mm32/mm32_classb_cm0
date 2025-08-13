/*
 *******************************************************************************
    @file     reg_crs.h
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

#ifndef __REG_CRS_H
#define __REG_CRS_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if 0
/* IP_CRS_DesignSpec_v1.0 */
/* THY  2022/11/25 */
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
  * @brief CRS Base Address Definition
  */
#define CRS_BASE                        (APB1PERIPH_BASE + 0x6C00)              /*!< Base Address: 0x40006C00 */

/**
  * @brief CRS Register Structure Definition
  */
typedef struct {
    __IO uint32_t CR;                                                           /*!< Control Register                    offset: 0x00 */
    __IO uint32_t CFGR;                                                         /*!< Configuration Register              offset: 0x04 */
    __IO uint32_t ISR;                                                          /*!< Interrupt and Status Register       offset: 0x08 */
    __IO uint32_t ICR;                                                          /*!< Interrupt Flag Clear Register       offset: 0x0C */
} CRS_TypeDef;

/**
  * @brief CRS type pointer Definition
  */
#define CRS                             ((CRS_TypeDef*) CRS_BASE)

/**
  * @brief CRS_CR Register Bit Definition
  */
#define CRS_CR_SYNCOKIE_Pos             (0)
#define CRS_CR_SYNCOKIE                 (0x01U << CRS_CR_SYNCOKIE_Pos)          /*!< SYNC event OK interrupt enable */
#define CRS_CR_SYNCWARNIE_Pos           (1)
#define CRS_CR_SYNCWARNIE               (0x01U << CRS_CR_SYNCWARNIE_Pos)        /*!< SYNC warning interrupt enable */
#define CRS_CR_ERRIE_Pos                (2)
#define CRS_CR_ERRIE                    (0x01U << CRS_CR_ERRIE_Pos)             /*!< Synchronization or trimming error interrupt enable */
#define CRS_CR_ESYNCIE_Pos              (3)
#define CRS_CR_ESYNCIE                  (0x01U << CRS_CR_ESYNCIE_Pos)           /*!< Expected SYNC interrupt enable */
#define CRS_CR_CEN_Pos                  (5)
#define CRS_CR_CEN                      (0x01U << CRS_CR_CEN_Pos)               /*!< Frequency error counter enable */
#define CRS_CR_AUTOTRIMEN_Pos           (6)
#define CRS_CR_AUTOTRIMEN               (0x01U << CRS_CR_AUTOTRIMEN_Pos)        /*!< Automatic trimming enable */
#define CRS_CR_SWSYNC_Pos               (7)
#define CRS_CR_SWSYNC                   (0x01U << CRS_CR_SWSYNC_Pos)            /*!< Generate software SYNC event */
#define CRS_CR_TRIM_Pos                 (8)
#define CRS_CR_TRIM                     (0x3FFU << CRS_CR_TRIM_Pos)             /*!< HSI Trimming */

/**
  * @brief CRS_CFGR Register Bit Definition
  */
#define CRS_CFGR_RELOAD_Pos             (0)
#define CRS_CFGR_RELOAD                 (0xFFFFU << CRS_CFGR_RELOAD_Pos)        /*!< Counter reload value */
#define CRS_CFGR_FELIM_Pos              (16)
#define CRS_CFGR_FELIM                  (0xFFU << CRS_CFGR_FELIM_Pos)           /*!< Frequency error limit */
#define CRS_CFGR_SYNCDIV_Pos            (24)
#define CRS_CFGR_SYNCDIV                (0x07U << CRS_CFGR_SYNCDIV_Pos)         /*!< SYNC divider */
#define CRS_CFGR_SYNCSRC_Pos            (28)
#define CRS_CFGR_SYNCSRC                (0x03U << CRS_CFGR_SYNCSRC_Pos)         /*!< SYNC signal source selection */
#define CRS_CFGR_SYNCSRC_GPIO           (0x00U << CRS_CFGR_SYNCSRC_Pos)         /*!< GPIO selected as synchronous signal source */
#define CRS_CFGR_SYNCSRC_LSE            (0x01U << CRS_CFGR_SYNCSRC_Pos)         /*!< LSE clock as synchronous signal source */
#define CRS_CFGR_SYNCSRC_USBSOF         (0x02U << CRS_CFGR_SYNCSRC_Pos)         /*!< USB SOF selected as synchronous signal source */
#define CRS_CFGR_SYNCPOL_Pos            (31)
#define CRS_CFGR_SYNCPOL                (0x01U << CRS_CFGR_SYNCPOL_Pos)         /*!< SYNC polarity selection */

/**
  * @brief CRS_ISR Register Bit Definition
  */
#define CRS_ISR_SYNCOKF_Pos             (0)
#define CRS_ISR_SYNCOKF                 (0x01U << CRS_ISR_SYNCOKF_Pos)          /*!< SYNC event OK flag */
#define CRS_ISR_SYNCWARNF_Pos           (1)
#define CRS_ISR_SYNCWARNF               (0x01U << CRS_ISR_SYNCWARNF_Pos)        /*!< SYNC warning flag */
#define CRS_ISR_ERRF_Pos                (2)
#define CRS_ISR_ERRF                    (0x01U << CRS_ISR_ERRF_Pos)             /*!< Error flag */
#define CRS_ISR_ESYNCF_Pos              (3)
#define CRS_ISR_ESYNCF                  (0x01U << CRS_ISR_ESYNCF_Pos)           /*!< Expected SYNC flag */
#define CRS_ISR_SYNCERR_Pos             (8)
#define CRS_ISR_SYNCERR                 (0x01U << CRS_ISR_SYNCERR_Pos)          /*!< SYNC error */
#define CRS_ISR_SYNCMISS_Pos            (9)
#define CRS_ISR_SYNCMISS                (0x01U << CRS_ISR_SYNCMISS_Pos)         /*!< SYNC missed */
#define CRS_ISR_TRIMOVF_Pos             (10)
#define CRS_ISR_TRIMOVF                 (0x01U << CRS_ISR_TRIMOVF_Pos)          /*!< Trimming overflow */
#define CRS_ISR_FEDIR_Pos               (15)
#define CRS_ISR_FEDIR                   (0x01U << CRS_ISR_FEDIR_Pos)            /*!< Frequency error direction */
#define CRS_ISR_FECAP_Pos               (16)
#define CRS_ISR_FECAP                   (0xFFFFU << CRS_ISR_FECAP_Pos)          /*!< Frequency error capture */

/**
  * @brief CRS_ICR Register Bit Definition
  */
#define CRS_ICR_SYNCOKC_Pos             (0)
#define CRS_ICR_SYNCOKC                 (0x01U << CRS_ICR_SYNCOKC_Pos)          /*!< SYNC event OK clear flag */
#define CRS_ICR_SYNCWARNC_Pos           (1)
#define CRS_ICR_SYNCWARNC               (0x01U << CRS_ICR_SYNCWARNC_Pos)        /*!< SYNC warning clear flag */
#define CRS_ICR_ERRC_Pos                (2)
#define CRS_ICR_ERRC                    (0x01U << CRS_ICR_ERRC_Pos)             /*!< Error clear flag */
#define CRS_ICR_ESYNCC_Pos              (3)
#define CRS_ICR_ESYNCC                  (0x01U << CRS_ICR_ESYNCC_Pos)           /*!< Expected SYNC clear flag */

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
