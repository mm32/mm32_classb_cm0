/*
 *******************************************************************************
    @file     reg_bkp.h
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

#ifndef __REG_BKP_H
#define __REG_BKP_H

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
  * @brief BKP Base Address Definition
  */
#define BKP_BASE                        (APB1PERIPH_BASE + 0x2840)              /*!< Base Address: 0x40002840 */

/**
  * @brief BKP Register Structure Definition
  */
typedef struct {
    __IO uint32_t RTCCR;                                                        /*!< RTC Calibration Clock register,    offset: 0x00 */
    __IO uint32_t CR;                                                           /*!< BKP control register,              offset: 0x04 */
    __IO uint32_t CSR;                                                          /*!< BKP control/status register,       offset: 0x08 */
    __IO uint32_t RESERVED0x0C;                                                 /*!< Reserved,                          offset: 0x0C */
    union {
        __IO uint32_t DRn[10];                                                  /*!< BKP data register 1 ~ 10           offset: 0x10~0x34 */
        struct {
            __IO uint32_t DR1;                                                  /*!< BKP data register 1,               offset: 0x10    BKP_DR1 */
            __IO uint32_t DR2;                                                  /*!< BKP data register 2,               offset: 0x14    BKP_DR2 */
            __IO uint32_t DR3;                                                  /*!< BKP data register 3,               offset: 0x18    BKP_DR3 */
            __IO uint32_t DR4;                                                  /*!< BKP data register 4,               offset: 0x1C    BKP_DR4 */
            __IO uint32_t DR5;                                                  /*!< BKP data register 5,               offset: 0x20    BKP_DR5 */
            __IO uint32_t DR6;                                                  /*!< BKP data register 6,               offset: 0x24    BKP_DR6 */
            __IO uint32_t DR7;                                                  /*!< BKP data register 7,               offset: 0x28    BKP_DR7 */
            __IO uint32_t DR8;                                                  /*!< BKP data register 8,               offset: 0x2C    BKP_DR8 */
            __IO uint32_t DR9;                                                  /*!< BKP data register 9,               offset: 0x30    BKP_DR9 */
            __IO uint32_t DR10;                                                 /*!< BKP data register 10               offset: 0x34    BKP_DR10 */
        };
    };
} BKP_TypeDef;

/**
  * @brief BKP type pointer Definition
  */
#define BKP                             ((BKP_TypeDef*) BKP_BASE)

/**
  * @brief BKP_DRn Register Bit Definition
  */
#define BKP_DR_BKP_Pos                  (0)
#define BKP_DR_BKP                      (0xFFFFU << BKP_DR_BKP)                 /*!< Backup data */

/**
  * @brief BKP_RTCCR Register Bit Definition
  */
#define BKP_RTCCR_CAL_Pos               (0)
#define BKP_RTCCR_CAL                   (0x7FU << BKP_RTCCR_CAL_Pos)            /*!< Calibration value */
#define BKP_RTCCR_CCO_Pos               (7)
#define BKP_RTCCR_CCO                   (0x01U << BKP_RTCCR_CCO_Pos)            /*!< Calibration Clock Outpu */
#define BKP_RTCCR_ASOE_Pos              (8)
#define BKP_RTCCR_ASOE                  (0x01U << BKP_RTCCR_ASOE_Pos)           /*!< Alarm Or Second Output Enable */
#define BKP_RTCCR_ASOS_Pos              (9)
#define BKP_RTCCR_ASOS                  (0x01U << BKP_RTCCR_ASOS_Pos)           /*!< Alarm Clock Or Second Pulse */

/**
  * @brief BKP_CR Register Bit Definition
  */
#define BKP_CR_TPE_Pos                  (0)
#define BKP_CR_TPE                      (0x01U << BKP_CR_TPE_Pos)               /*!< TAMPER pin enable */
#define BKP_CR_TPAL_Pos                 (1)
#define BKP_CR_TPAL                     (0x01U << BKP_CR_TPAL_Pos)              /*!< TAMPER pin active level */

/**
  * @brief BKP_CSR Register Bit Definition
  */
#define BKP_CSR_CTE_Pos                 (0)
#define BKP_CSR_CTE                     (0x01U << BKP_CSR_CTE_Pos)              /*!< Clear Tamper event */
#define BKP_CSR_CTI_Pos                 (1)
#define BKP_CSR_CTI                     (0x01U << BKP_CSR_CTI_Pos)              /*!< Clear Tamper Interrupt */
#define BKP_CSR_TPIE_Pos                (2)
#define BKP_CSR_TPIE                    (0x01U << BKP_CSR_TPIE_Pos)             /*!< TAMPER Pin interrupt enable */
#define BKP_CSR_TEF_Pos                 (8)
#define BKP_CSR_TEF                     (0x01U << BKP_CSR_TEF_Pos)              /*!< Tamper Event Flag */
#define BKP_CSR_TIF_Pos                 (9)
#define BKP_CSR_TIF                     (0x01U << BKP_CSR_TIF_Pos)              /*!< Tamper Interrupt Flag */

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
