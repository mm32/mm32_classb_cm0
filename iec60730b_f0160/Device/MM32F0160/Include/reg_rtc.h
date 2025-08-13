/*
 *******************************************************************************
    @file     reg_rtc.h
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

#ifndef __REG_RTC_H
#define __REG_RTC_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if 0
/* IP_RTC_DesignSpec_V0.6 */
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
  * @brief RTC Base Address Definition
  */
#define RTC_BASE                        (APB1PERIPH_BASE + 0x2800)              /*!< Base Address: 0x40002800 */

/**
  * @brief RTC Registers Structure Definition
  */
typedef struct {
    __IO uint32_t CRH;                                                          /*!< Control Register,                              offset: 0x00 */
    __IO uint32_t CRL;                                                          /*!< Control & Status Register,                     offset: 0x04 */
    __IO uint32_t PRLH;                                                         /*!< Prescaler Reload Value High,                   offset: 0x08 */
    __IO uint32_t PRLL;                                                         /*!< Prescaler Reload Value Low,                    offset: 0x0C */
    __IO uint32_t DIVH;                                                         /*!< Clock Divider High,                            offset: 0x10 */
    __IO uint32_t DIVL;                                                         /*!< Clock Divider Low,                             offset: 0x14 */
    __IO uint32_t CNTH;                                                         /*!< Counter High,                                  offset: 0x18 */
    __IO uint32_t CNTL;                                                         /*!< Counter Low,                                   offset: 0x1C */
    __IO uint32_t ALRH;                                                         /*!< Alarm High,                                    offset: 0x20 */
    __IO uint32_t ALRL;                                                         /*!< Alarm Low,                                     offset: 0x24 */
    __IO uint32_t MSRH;                                                         /*!< Millisecond alarm high register                offset: 0x28 */
    __IO uint32_t MSRL;                                                         /*!< Millisecond alarm low register                 offset: 0x2C */
    __IO uint32_t RESERVED0x30[3];                                              /*!< Reserved                                       offset: 0x30~0x38 */
    __IO uint32_t LSE_CFG;                                                      /*!< LSE configure register                         offset: 0x3C */
} RTC_TypeDef;

/**
  * @brief RTC type pointer Definition
  */
#define RTC                             ((RTC_TypeDef*)RTC_BASE)

/**
  * @brief RTC_CRH Register Bit Definition
  */
#define RTC_CRH_SECIE_Pos               (0)
#define RTC_CRH_SECIE                   (0x01U << RTC_CRH_SECIE_Pos)            /*!< Second Interrupt Enable */
#define RTC_CRH_ALRIE_Pos               (1)
#define RTC_CRH_ALRIE                   (0x01U << RTC_CRH_ALRIE_Pos)            /*!< Alarm Interrupt Enable */
#define RTC_CRH_OWIE_Pos                (2)
#define RTC_CRH_OWIE                    (0x01U << RTC_CRH_OWIE_Pos)             /*!< OverfloW Interrupt Enable */

/**
  * @brief RTC_CRL Register Bit Definition
  */
#define RTC_CRL_SECF_Pos                (0)
#define RTC_CRL_SECF                    (0x01U << RTC_CRL_SECF_Pos)             /*!< Second Flag */
#define RTC_CRL_ALRF_Pos                (1)
#define RTC_CRL_ALRF                    (0x01U << RTC_CRL_ALRF_Pos)             /*!< Alarm Flag */
#define RTC_CRL_OWF_Pos                 (2)
#define RTC_CRL_OWF                     (0x01U<< RTC_CRL_OWF_Pos)               /*!< OverfloW Flag */
#define RTC_CRL_RSF_Pos                 (3)
#define RTC_CRL_RSF                     (0x01U << RTC_CRL_RSF_Pos)              /*!< Registers Synchronized Flag */
#define RTC_CRL_CNF_Pos                 (4)
#define RTC_CRL_CNF                     (0x01U << RTC_CRL_CNF_Pos)              /*!< Configuration Flag */
#define RTC_CRL_RTOFF_Pos               (5)
#define RTC_CRL_RTOFF                   (0x01U << RTC_CRL_RTOFF_Pos)            /*!< RTC operation OFF */
#define RTC_CRL_ALPEN_Pos               (6)
#define RTC_CRL_ALPEN                   (0x01U << RTC_CRL_ALPEN_Pos)            /*!< RTC Alarm Loop Enable */

/**
  * @brief RTC_PRLH Register Bit Definition
  */
#define RTC_PRLH_PRL_Pos                (0)
#define RTC_PRLH_PRL                    (0x0FU << RTC_PRLH_PRL_Pos)             /*!< RTC Prescaler Reload Value High */

/**
  * @brief RTC_PRLL Register Bit Definition
  */
#define RTC_PRLL_PRL_Pos                (0)
#define RTC_PRLL_PRL                    (0xFFFFU << RTC_PRLL_PRL_Pos)           /*!< RTC Prescaler Reload Value Low */

/**
  * @brief RTC_DIVH Register Bit Definition
  */
#define RTC_DIVH_DIV_Pos                (0)
#define RTC_DIVH_DIV                    (0x0FU << RTC_DIVH_DIV_Pos)             /*!< RTC Clock Divider High */

/**
  * @brief RTC_DIVL Register Bit Definition
  */
#define RTC_DIVL_DIV_Pos                (0)
#define RTC_DIVL_DIV                    (0xFFFFU << RTC_DIVL_DIV_Pos)           /*!< RTC Clock Divider Low */

/**
  * @brief RTC_CNTH Register Bit Definition
  */
#define RTC_CNTH_CNT_Pos                (0)
#define RTC_CNTH_CNT                    (0xFFFFU << RTC_CNTH_CNT_Pos)           /*!< RTC Counter High */

/**
  * @brief RTC_CNTL Register Bit Definition
  */
#define RTC_CNTL_CNT_Pos                (0)
#define RTC_CNTL_CNT                    (0xFFFFU << RTC_CNTL_CNT_Pos)           /*!< RTC Counter Low */

/**
  * @brief RTC_ALRH Register Bit Definition
  */
#define RTC_ALRH_ALR_Pos                (0)
#define RTC_ALRH_ALR                    (0xFFFFU << RTC_ALRH_ALR_Pos)           /*!< RTC Alarm High */

/**
  * @brief RTC_ALRL Register Bit Definition
  */
#define RTC_ALRL_ALR_Pos                (0)
#define RTC_ALRL_ALR                    (0xFFFFU << RTC_ALRL_ALR_Pos)           /*!< RTC Alarm Low */

/**
  * @brief RTC_MSRH Register Bit Definition
  */
#define RTC_MSRH_MSR_Pos                (0)
#define RTC_MSRH_MSR                    (0x0FU << RTC_MSRH_MSR_Pos)             /*!< RTC MS Alarm Register High */

/**
  * @brief RTC_MSRL Register Bit Definition
  */
#define RTC_MSRL_MSR_Pos                (0)
#define RTC_MSRL_MSR                    (0xFFFFU << RTC_MSRL_MSR_Pos)           /*!< RTC MS Alarm Register Low */

/**
  * @brief RTC_LSE_CFG Register Bit Definition
  */
#define RTC_LSE_CFG_LSE_TEST_Pos        (0)
#define RTC_LSE_CFG_LSE_TEST            (0x0FU << RTC_LSE_CFG_LSE_TEST_Pos)     /*!< Test control signal */
#define RTC_LSE_CFG_LSE_DR_Pos          (4)
#define RTC_LSE_CFG_LSE_DR              (0x03U << RTC_LSE_CFG_LSE_DR_Pos)       /*!< Drive capability selection */
#define RTC_LSE_CFG_LSE_RFB_SEL_Pos     (6)
#define RTC_LSE_CFG_LSE_RFB_SEL_Msk     (0x03U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)  /*!< Feedback resistance selection: */
#define RTC_LSE_CFG_LSE_RFB_SEL_12M     (0x00U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)  /*!< Feedback resistance selection 12M */
#define RTC_LSE_CFG_LSE_RFB_SEL_10M     (0x01U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)  /*!< Feedback resistance selection 10M */
#define RTC_LSE_CFG_LSE_RFB_SEL_6M      (0x02U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)  /*!< Feedback resistance selection 6M */
#define RTC_LSE_CFG_LSE_RFB_SEL_3M      (0x03U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)  /*!< Feedback resistance selection 3M */

#define RTC_LSE_CFG_LSE_IB_Pos          (8)
#define RTC_LSE_CFG_LSE_IB              (0x01U << RTC_LSE_CFG_LSE_IB_Pos)       /*!< Bias current regulation */

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
