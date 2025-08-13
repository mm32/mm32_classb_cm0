/*
 *******************************************************************************
    @file     reg_tim.h
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

#ifndef __REG_TIM_H
#define __REG_TIM_H

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
  * @brief TIM Base Address Definition
  */
#define TIM1_BASE                       (APB2PERIPH_BASE + 0x2C00)              /*!< Base Address: 0x40012C00 */
#define TIM2_BASE                       (APB1PERIPH_BASE + 0x0000)              /*!< Base Address: 0x40000000 */
#define TIM3_BASE                       (APB1PERIPH_BASE + 0x0400)              /*!< Base Address: 0x40000400 */

#define TIM14_BASE                      (APB2PERIPH_BASE + 0x4000)              /*!< Base Address: 0x40014000 */
#define TIM16_BASE                      (APB2PERIPH_BASE + 0x4400)              /*!< Base Address: 0x40014400 */
#define TIM17_BASE                      (APB2PERIPH_BASE + 0x4800)              /*!< Base Address: 0x40014800 */

/**
  * @brief Timer Register Structure Definition
  */
typedef struct {
    __IO uint32_t CR1;                                                          /*!< TIM control register 1,                        offset: 0x00 */
    __IO uint32_t CR2;                                                          /*!< TIM control register 2,                        offset: 0x04 */
    __IO uint32_t SMCR;                                                         /*!< TIM slave Mode Control register,               offset: 0x08 */
    __IO uint32_t DIER;                                                         /*!< TIM DMA/interrupt enable register,             offset: 0x0C */
    __IO uint32_t SR;                                                           /*!< TIM status register,                           offset: 0x10 */
    __IO uint32_t EGR;                                                          /*!< TIM event generation register,                 offset: 0x14 */
    __IO uint32_t CCMR1;                                                        /*!< TIM capture/compare mode register 1,           offset: 0x18 */
    __IO uint32_t CCMR2;                                                        /*!< TIM capture/compare mode register 2,           offset: 0x1C */
    __IO uint32_t CCER;                                                         /*!< TIM capture/compare enable register,           offset: 0x20 */
    __IO uint32_t CNT;                                                          /*!< TIM counter register,                          offset: 0x24 */
    __IO uint32_t PSC;                                                          /*!< TIM prescaler register,                        offset: 0x28 */
    __IO uint32_t ARR;                                                          /*!< TIM auto-reload register,                      offset: 0x2C */
    __IO uint32_t RCR;                                                          /*!< TIM repetition counter register,               offset: 0x30 */
    __IO uint32_t CCR1;                                                         /*!< TIM capture/compare register 1,                offset: 0x34 */
    __IO uint32_t CCR2;                                                         /*!< TIM capture/compare register 2,                offset: 0x38 */
    __IO uint32_t CCR3;                                                         /*!< TIM capture/compare register 3,                offset: 0x3C */
    __IO uint32_t CCR4;                                                         /*!< TIM capture/compare register 4,                offset: 0x40 */
    __IO uint32_t BDTR;                                                         /*!< TIM break and dead-time register,              offset: 0x44 */
    __IO uint32_t DCR;                                                          /*!< TIM DMA control register,                      offset: 0x48 */
    __IO uint32_t DMAR;                                                         /*!< TIM DMA address for full transfer register,    offset: 0x4C */
    __IO uint32_t OR;                                                           /*!< Input Option Register for TIM2|TIM3,           offset: 0x50 */
    __IO uint32_t CCMR3;                                                        /*!< TIM capture/compare mode register 3,           offset: 0x54 */
    __IO uint32_t CCR5;                                                         /*!< TIM capture/compare register 5,                offset: 0x58 */
    __IO uint32_t PDER;                                                         /*!< PWM Shift repeat enable register,              offset: 0x5C */
    __IO uint32_t CCR1FALL;                                                     /*!< PWM shift count CCR1 register,                 offset: 0x60 */
    __IO uint32_t CCR2FALL;                                                     /*!< PWM shift count CCR2 register,                 offset: 0x64 */
    __IO uint32_t CCR3FALL;                                                     /*!< PWM shift count CCR3 register,                 offset: 0x68 */
    __IO uint32_t CCR4FALL;                                                     /*!< PWM shift count CCR4 register,                 offset: 0x6c */
    __IO uint32_t CCR5FALL;                                                     /*!< PWM shift count CCR5 register,                 offset: 0x70 */
    __IO uint32_t BKINF;                                                        /*!< Break Input filter register TIM1|TIM16|TIM17,  offset: 0x74 */
} TIM_TypeDef;

/**
  * @brief TIM type pointer Definition
  */
#define TIM1                            ((TIM_TypeDef*) TIM1_BASE)
#define TIM2                            ((TIM_TypeDef*) TIM2_BASE)
#define TIM3                            ((TIM_TypeDef*) TIM3_BASE)

#define TIM14                           ((TIM_TypeDef*) TIM14_BASE)
#define TIM16                           ((TIM_TypeDef*) TIM16_BASE)
#define TIM17                           ((TIM_TypeDef*) TIM17_BASE)

/**
  * @brief TIM_CR1 Register Bit Definition
  */
#define TIM_CR1_CEN_Pos                 (0)
#define TIM_CR1_CEN                     (0x01U << TIM_CR1_CEN_Pos)              /*!< Counter enable */
#define TIM_CR1_UDIS_Pos                (1)
#define TIM_CR1_UDIS                    (0x01U << TIM_CR1_UDIS_Pos)             /*!< Update disable */
#define TIM_CR1_URS_Pos                 (2)
#define TIM_CR1_URS                     (0x01U << TIM_CR1_URS_Pos)              /*!< Update request source */
#define TIM_CR1_OPM_Pos                 (3)
#define TIM_CR1_OPM                     (0x01U << TIM_CR1_OPM_Pos)              /*!< One pulse mode */
#define TIM_CR1_DIR_Pos                 (4)
#define TIM_CR1_DIR                     (0x01U << TIM_CR1_DIR_Pos)              /*!< Direction */
#define TIM_CR1_CMS_Pos                 (5)
#define TIM_CR1_CMS                     (0x03U << TIM_CR1_CMS_Pos)              /*!< CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_EDGEALIGNED         (0x00U << TIM_CR1_CMS_Pos)              /*!< Edge-aligned mode */
#define TIM_CR1_CMS_CENTERALIGNED1      (0x01U << TIM_CR1_CMS_Pos)              /*!< Center-aligned mode 1 */
#define TIM_CR1_CMS_CENTERALIGNED2      (0x02U << TIM_CR1_CMS_Pos)              /*!< Center-aligned mode 2 */
#define TIM_CR1_CMS_CENTERALIGNED3      (0x03U << TIM_CR1_CMS_Pos)              /*!< Center-aligned mode 3 */
#define TIM_CR1_APRE_Pos                (7)
#define TIM_CR1_APRE                    (0x01U << TIM_CR1_APRE_Pos)             /*!< Auto-reload preload enable */
#define TIM_CR1_CKD_Pos                 (8)
#define TIM_CR1_CKD                     (0x03U << TIM_CR1_CKD_Pos)              /*!< CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_DIV1                (0x00U << TIM_CR1_CKD_Pos)              /*!< Divided by 1 */
#define TIM_CR1_CKD_DIV2                (0x01U << TIM_CR1_CKD_Pos)              /*!< Divided by 2 */
#define TIM_CR1_CKD_DIV4                (0x02U << TIM_CR1_CKD_Pos)              /*!< Divided by 4 */

/**
  * @brief TIM_CR2 Register Bit Definition
  */
#define TIM_CR2_CCPC_Pos                (0)
#define TIM_CR2_CCPC                    (0x01U << TIM_CR2_CCPC_Pos)             /*!< Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos                (2)
#define TIM_CR2_CCUS                    (0x01U << TIM_CR2_CCUS_Pos)             /*!< Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos                (3)
#define TIM_CR2_CCDS                    (0x01U << TIM_CR2_CCDS_Pos)             /*!< Capture/Compare DMA Selection */
#define TIM_CR2_MMS_Pos                 (4)
#define TIM_CR2_MMS                     (0x07U << TIM_CR2_MMS_Pos)              /*!< MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_RESET               (0x00U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: Reset */
#define TIM_CR2_MMS_ENABLE              (0x01U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: Enable */
#define TIM_CR2_MMS_UPDATE              (0x02U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: Update */
#define TIM_CR2_MMS_OC1                 (0x03U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: OC1 */
#define TIM_CR2_MMS_OC1REF              (0x04U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: OC1Ref */
#define TIM_CR2_MMS_OC2REF              (0x05U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: OC2Ref */
#define TIM_CR2_MMS_OC3REF              (0x06U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: OC3Ref */
#define TIM_CR2_MMS_OC4REF              (0x07U << TIM_CR2_MMS_Pos)              /*!< Master Mode Select: OC4Ref */
#define TIM_CR2_TI1S_Pos                (7)
#define TIM_CR2_TI1S                    (0x01U << TIM_CR2_TI1S_Pos)             /*!< TI1 Selection */
#define TIM_CR2_OIS1_Pos                (8)
#define TIM_CR2_OIS1                    (0x01U << TIM_CR2_OIS1_Pos)             /*!< Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos               (9)
#define TIM_CR2_OIS1N                   (0x01U << TIM_CR2_OIS1N_Pos)            /*!< Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos                (10)
#define TIM_CR2_OIS2                    (0x01U << TIM_CR2_OIS2_Pos)             /*!< Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos               (11)
#define TIM_CR2_OIS2N                   (0x01U << TIM_CR2_OIS2N_Pos)            /*!< Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos                (12)
#define TIM_CR2_OIS3                    (0x01U << TIM_CR2_OIS3_Pos)             /*!< Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos               (13)
#define TIM_CR2_OIS3N                   (0x01U << TIM_CR2_OIS3N_Pos)            /*!< Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos                (14)
#define TIM_CR2_OIS4                    (0x01U << TIM_CR2_OIS4_Pos)             /*!< Output Idle state 4 (OC4 output) */

/**
  * @brief TIM_SMCR Register Bit Definition
  */
#define TIM_SMCR_SMS_Pos                (0)
#define TIM_SMCR_SMS                    (0x07U << TIM_SMCR_SMS_Pos)             /*!< SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_OFF                (0x00U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: OFF */
#define TIM_SMCR_SMS_ENCODER1           (0x01U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: Encoder1 */
#define TIM_SMCR_SMS_ENCODER2           (0x02U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: Encoder2 */
#define TIM_SMCR_SMS_ENCODER3           (0x03U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: Encoder3 */
#define TIM_SMCR_SMS_RESET              (0x04U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: Reset */
#define TIM_SMCR_SMS_GATED              (0x05U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: Gated */
#define TIM_SMCR_SMS_TRIGGER            (0x06U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: Trigger */
#define TIM_SMCR_SMS_EXTERNAL1          (0x07U << TIM_SMCR_SMS_Pos)             /*!< Slave Mode select: External1 */

#define TIM_SMCR_OCCS_Pos               (3)
#define TIM_SMCR_OCCS                   (0x01U << TIM_SMCR_OCCS_Pos)            /*!< Output compare clear selection */

#define TIM_SMCR_TS_Pos                 (4)
#define TIM_SMCR_TS                     (0x07U << TIM_SMCR_TS_Pos)              /*!< TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_ITR0                (0x00U << TIM_SMCR_TS_Pos)              /*!< Internal Trigger 0 (ITR0) */
#define TIM_SMCR_TS_ITR1                (0x01U << TIM_SMCR_TS_Pos)              /*!< Internal Trigger 1 (ITR1) */
#define TIM_SMCR_TS_ITR2                (0x02U << TIM_SMCR_TS_Pos)              /*!< Internal Trigger 2 (ITR2) */
#define TIM_SMCR_TS_ITR3                (0x03U << TIM_SMCR_TS_Pos)              /*!< Internal Trigger 3 (ITR3) */
#define TIM_SMCR_TS_TI1F_ED             (0x04U << TIM_SMCR_TS_Pos)              /*!< TI1 Edge Detector (TI1F_ED) */
#define TIM_SMCR_TS_TI1FP1              (0x05U << TIM_SMCR_TS_Pos)              /*!< Filtered Timer Input 1 (TI1FP1) */
#define TIM_SMCR_TS_TI2FP2              (0x06U << TIM_SMCR_TS_Pos)              /*!< Filtered Timer Input 2 (TI2FP2) */
#define TIM_SMCR_TS_ETR                 (0x07U << TIM_SMCR_TS_Pos)              /*!< External Trigger input (ETR) */
#define TIM_SMCR_MSM_Pos                (7)
#define TIM_SMCR_MSM                    (0x01U << TIM_SMCR_MSM_Pos)             /*!< Master/slave mode */
#define TIM_SMCR_ETF_Pos                (8)
#define TIM_SMCR_ETF                    (0x0FU << TIM_SMCR_ETF_Pos)             /*!< ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0                  (0x01U << TIM_SMCR_ETF_Pos)             /*!< Bit 0 */
#define TIM_SMCR_ETF_1                  (0x02U << TIM_SMCR_ETF_Pos)             /*!< Bit 1 */
#define TIM_SMCR_ETF_2                  (0x04U << TIM_SMCR_ETF_Pos)             /*!< Bit 2 */
#define TIM_SMCR_ETF_3                  (0x08U << TIM_SMCR_ETF_Pos)             /*!< Bit 3 */
#define TIM_SMCR_ETPS_Pos               (12)
#define TIM_SMCR_ETPS                   (0x03U << TIM_SMCR_ETPS_Pos)            /*!< ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_OFF               (0x00U << TIM_SMCR_ETPS_Pos)            /*!< Prescaler OFF */
#define TIM_SMCR_ETPS_DIV2              (0x01U << TIM_SMCR_ETPS_Pos)            /*!< ETRP frequency divided by 2 */
#define TIM_SMCR_ETPS_DIV4              (0x02U << TIM_SMCR_ETPS_Pos)            /*!< ETRP frequency divided by 4 */
#define TIM_SMCR_ETPS_DIV8              (0x03U << TIM_SMCR_ETPS_Pos)            /*!< ETRP frequency divided by 8 */
#define TIM_SMCR_ECE_Pos                (14)
#define TIM_SMCR_ECE                    (0x01U << TIM_SMCR_ECE_Pos)             /*!< External clock enable */
#define TIM_SMCR_ETP_Pos                (15)
#define TIM_SMCR_ETP                    (0x01U << TIM_SMCR_ETP_Pos)             /*!< External trigger polarity */

/**
  * @brief TIM_DIER Register Bit Definition
  */
#define TIM_DIER_UIE_Pos                (0)
#define TIM_DIER_UIE                    (0x01U << TIM_DIER_UIE_Pos)             /*!< Update interrupt enable */
#define TIM_DIER_CC1IE_Pos              (1)
#define TIM_DIER_CC1IE                  (0x01U << TIM_DIER_CC1IE_Pos)           /*!< Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos              (2)
#define TIM_DIER_CC2IE                  (0x01U << TIM_DIER_CC2IE_Pos)           /*!< Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos              (3)
#define TIM_DIER_CC3IE                  (0x01U << TIM_DIER_CC3IE_Pos)           /*!< Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos              (4)
#define TIM_DIER_CC4IE                  (0x01U << TIM_DIER_CC4IE_Pos)           /*!< Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos              (5)
#define TIM_DIER_COMIE                  (0x01U << TIM_DIER_COMIE_Pos)           /*!< COM interrupt enable */
#define TIM_DIER_TIE_Pos                (6)
#define TIM_DIER_TIE                    (0x01U << TIM_DIER_TIE_Pos)             /*!< Trigger interrupt enable */
#define TIM_DIER_BIE_Pos                (7)
#define TIM_DIER_BIE                    (0x01U << TIM_DIER_BIE_Pos)             /*!< Break interrupt enable */
#define TIM_DIER_UDE_Pos                (8)
#define TIM_DIER_UDE                    (0x01U << TIM_DIER_UDE_Pos)             /*!< Update DMA request enable */
#define TIM_DIER_CC1DE_Pos              (9)
#define TIM_DIER_CC1DE                  (0x01U << TIM_DIER_CC1DE_Pos)           /*!< Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos              (10)
#define TIM_DIER_CC2DE                  (0x01U << TIM_DIER_CC2DE_Pos)           /*!< Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos              (11)
#define TIM_DIER_CC3DE                  (0x01U << TIM_DIER_CC3DE_Pos)           /*!< Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos              (12)
#define TIM_DIER_CC4DE                  (0x01U << TIM_DIER_CC4DE_Pos)           /*!< Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos              (13)
#define TIM_DIER_COMDE                  (0x01U << TIM_DIER_COMDE_Pos)           /*!< COM DMA request enable */
#define TIM_DIER_TDE_Pos                (14)
#define TIM_DIER_TDE                    (0x01U << TIM_DIER_TDE_Pos)             /*!< Trigger DMA request enable */
#define TIM_DIER_CC5IE_Pos              (16)
#define TIM_DIER_CC5IE                  (0x01U << TIM_DIER_CC5IE_Pos)           /*!< Capture/Compare 5 interrupt enable */
#define TIM_DIER_CC5DE_Pos              (17)
#define TIM_DIER_CC5DE                  (0x01U << TIM_DIER_CC5DE_Pos)           /*!< Capture/Compare 5 DMA request enable */

/**
  * @brief TIM_SR Register Bit Definition
  */
#define TIM_SR_UIF_Pos                  (0)
#define TIM_SR_UIF                      (0x01U << TIM_SR_UIF_Pos)               /*!< Update interrupt Flag */
#define TIM_SR_CC1IF_Pos                (1)
#define TIM_SR_CC1IF                    (0x01U << TIM_SR_CC1IF_Pos)             /*!< Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos                (2)
#define TIM_SR_CC2IF                    (0x01U << TIM_SR_CC2IF_Pos)             /*!< Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos                (3)
#define TIM_SR_CC3IF                    (0x01U << TIM_SR_CC3IF_Pos)             /*!< Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos                (4)
#define TIM_SR_CC4IF                    (0x01U << TIM_SR_CC4IF_Pos)             /*!< Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos                (5)
#define TIM_SR_COMIF                    (0x01U << TIM_SR_COMIF_Pos)             /*!< COM interrupt Flag */
#define TIM_SR_TIF_Pos                  (6)
#define TIM_SR_TIF                      (0x01U << TIM_SR_TIF_Pos)               /*!< Trigger interrupt Flag */
#define TIM_SR_BIF_Pos                  (7)
#define TIM_SR_BIF                      (0x01U << TIM_SR_BIF_Pos)               /*!< Break interrupt Flag */

#define TIM_SR_CC1OF_Pos                (9)
#define TIM_SR_CC1OF                    (0x01U << TIM_SR_CC1OF_Pos)             /*!< Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos                (10)
#define TIM_SR_CC2OF                    (0x01U << TIM_SR_CC2OF_Pos)             /*!< Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos                (11)
#define TIM_SR_CC3OF                    (0x01U << TIM_SR_CC3OF_Pos)             /*!< Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos                (12)
#define TIM_SR_CC4OF                    (0x01U << TIM_SR_CC4OF_Pos)             /*!< Capture/Compare 4 Overcapture Flag */

#define TIM_SR_CC5IF_Pos                (16)
#define TIM_SR_CC5IF                    (0x01U << TIM_SR_CC5IF_Pos)             /*!< Capture/Compare 5 interrupt Flag */

/**
  * @brief TIM_EGR Register Bit Definition
  */
#define TIM_EGR_UG_Pos                  (0)
#define TIM_EGR_UG                      (0x01U << TIM_EGR_UG_Pos)               /*!< Update Generation */
#define TIM_EGR_CC1G_Pos                (1)
#define TIM_EGR_CC1G                    (0x01U << TIM_EGR_CC1G_Pos)             /*!< Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos                (2)
#define TIM_EGR_CC2G                    (0x01U << TIM_EGR_CC2G_Pos)             /*!< Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos                (3)
#define TIM_EGR_CC3G                    (0x01U << TIM_EGR_CC3G_Pos)             /*!< Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos                (4)
#define TIM_EGR_CC4G                    (0x01U << TIM_EGR_CC4G_Pos)             /*!< Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos                (5)
#define TIM_EGR_COMG                    (0x01U << TIM_EGR_COMG_Pos)             /*!< Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos                  (6)
#define TIM_EGR_TG                      (0x01U << TIM_EGR_TG_Pos)               /*!< Trigger Generation */
#define TIM_EGR_BG_Pos                  (7)
#define TIM_EGR_BG                      (0x01U << TIM_EGR_BG_Pos)               /*!< Break Generation */

#define TIM_EGR_CC5G_Pos                (16)
#define TIM_EGR_CC5G                    (0x01U << TIM_EGR_CC5G_Pos)             /*!< Capture/Compare 5 Generation */

/**
  * @brief TIM_CCMR1 Register Bit Definition
  */
#define TIM_CCMR1_CC1S_Pos              (0)
#define TIM_CCMR1_CC1S                  (0x03U << TIM_CCMR1_CC1S_Pos)           /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_OC               (0x00U << TIM_CCMR1_CC1S_Pos)           /*!< Channel is configured as output */
#define TIM_CCMR1_CC1S_TI1              (0x01U << TIM_CCMR1_CC1S_Pos)           /*!< Channel is configured as input, IC1 is mapped on TI1 */
#define TIM_CCMR1_CC1S_TI2              (0x02U << TIM_CCMR1_CC1S_Pos)           /*!< Channel is configured as input, IC1 is mapped on TI2 */
#define TIM_CCMR1_CC1S_TRC              (0x03U << TIM_CCMR1_CC1S_Pos)           /*!< Channel is configured as input, IC1 is mapped on TRC */
#define TIM_CCMR1_OC1FE_Pos             (2)
#define TIM_CCMR1_OC1FE                 (0x01U << TIM_CCMR1_OC1FE_Pos)          /*!< Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos             (3)
#define TIM_CCMR1_OC1PE                 (0x01U << TIM_CCMR1_OC1PE_Pos)          /*!< Output Compare 1 Preload enable */
#define TIM_CCMR1_OC1M_Pos              (4)
#define TIM_CCMR1_OC1M                  (0x07U << TIM_CCMR1_OC1M_Pos)           /*!< OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_TIMING           (0x00U << TIM_CCMR1_OC1M_Pos)           /*!< Timing */
#define TIM_CCMR1_OC1M_ACTIVE           (0x01U << TIM_CCMR1_OC1M_Pos)           /*!< Active */
#define TIM_CCMR1_OC1M_INACTIVE         (0x02U << TIM_CCMR1_OC1M_Pos)           /*!< Inactive */
#define TIM_CCMR1_OC1M_TOGGLE           (0x03U << TIM_CCMR1_OC1M_Pos)           /*!< Toggle */
#define TIM_CCMR1_OC1M_FORCEINACTIVE    (0x04U << TIM_CCMR1_OC1M_Pos)           /*!< Forceinactive */
#define TIM_CCMR1_OC1M_FORCEACTIVE      (0x05U << TIM_CCMR1_OC1M_Pos)           /*!< Forceactive */
#define TIM_CCMR1_OC1M_PWM1             (0x06U << TIM_CCMR1_OC1M_Pos)           /*!< PWM1 */
#define TIM_CCMR1_OC1M_PWM2             (0x07U << TIM_CCMR1_OC1M_Pos)           /*!< PWM2 */
#define TIM_CCMR1_OC1CE_Pos             (7)
#define TIM_CCMR1_OC1CE                 (0x01U << TIM_CCMR1_OC1CE_Pos)          /*!< Output Compare 1Clear Enable */

#define TIM_CCMR1_CC2S_Pos              (8)
#define TIM_CCMR1_CC2S                  (0x03U << TIM_CCMR1_CC2S_Pos)           /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_OC               (0x00U << TIM_CCMR1_CC2S_Pos)           /*!< Channel is configured as output */
#define TIM_CCMR1_CC2S_TI2              (0x01U << TIM_CCMR1_CC2S_Pos)           /*!< Channel is configured as input, IC2 is mapped on TI2 */
#define TIM_CCMR1_CC2S_TI1              (0x02U << TIM_CCMR1_CC2S_Pos)           /*!< Channel is configured as input, IC2 is mapped on TI1 */
#define TIM_CCMR1_CC2S_TRC              (0x03U << TIM_CCMR1_CC2S_Pos)           /*!< Channel is configured as input, IC2 is mapped on TRC */
#define TIM_CCMR1_OC2FE_Pos             (10)
#define TIM_CCMR1_OC2FE                 (0x01U << TIM_CCMR1_OC2FE_Pos)          /*!< Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos             (11)
#define TIM_CCMR1_OC2PE                 (0x01U << TIM_CCMR1_OC2PE_Pos)          /*!< Output Compare 2 Preload enable */
#define TIM_CCMR1_OC2M_Pos              (12)
#define TIM_CCMR1_OC2M                  (0x07U << TIM_CCMR1_OC2M_Pos)           /*!< OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_TIMING           (0x00U << TIM_CCMR1_OC2M_Pos)           /*!< Timing */
#define TIM_CCMR1_OC2M_ACTIVE           (0x01U << TIM_CCMR1_OC2M_Pos)           /*!< Active */
#define TIM_CCMR1_OC2M_INACTIVE         (0x02U << TIM_CCMR1_OC2M_Pos)           /*!< Inactive */
#define TIM_CCMR1_OC2M_TOGGLE           (0x03U << TIM_CCMR1_OC2M_Pos)           /*!< Toggle */
#define TIM_CCMR1_OC2M_FORCEINACTIVE    (0x04U << TIM_CCMR1_OC2M_Pos)           /*!< Forceinactive */
#define TIM_CCMR1_OC2M_FORCEACTIVE      (0x05U << TIM_CCMR1_OC2M_Pos)           /*!< Forceactive */
#define TIM_CCMR1_OC2M_PWM1             (0x06U << TIM_CCMR1_OC2M_Pos)           /*!< PWM1 */
#define TIM_CCMR1_OC2M_PWM2             (0x07U << TIM_CCMR1_OC2M_Pos)           /*!< PWM2 */
#define TIM_CCMR1_OC2CE_Pos             (15)
#define TIM_CCMR1_OC2CE                 (0x01U << TIM_CCMR1_OC2CE_Pos)          /*!< Output Compare 2 Clear Enable */

#define TIM_CCMR1_IC1PSC_Pos            (2)
#define TIM_CCMR1_IC1PSC                (0x03U << TIM_CCMR1_IC1PSC_Pos)         /*!< IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_DIV1           (0x00U << TIM_CCMR1_IC1PSC_Pos)         /*!< No Prescaler */
#define TIM_CCMR1_IC1PSC_DIV2           (0x01U << TIM_CCMR1_IC1PSC_Pos)         /*!< Capture is done once every 2 events */
#define TIM_CCMR1_IC1PSC_DIV4           (0x02U << TIM_CCMR1_IC1PSC_Pos)         /*!< Capture is done once every 4 events */
#define TIM_CCMR1_IC1PSC_DIV8           (0x03U << TIM_CCMR1_IC1PSC_Pos)         /*!< Capture is done once every 8 events */
#define TIM_CCMR1_IC1F_Pos              (4)
#define TIM_CCMR1_IC1F                  (0x0FU << TIM_CCMR1_IC1F_Pos)           /*!< IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0                (0x01U << TIM_CCMR1_IC1F_Pos)           /*!< Bit 0 */
#define TIM_CCMR1_IC1F_1                (0x02U << TIM_CCMR1_IC1F_Pos)           /*!< Bit 1 */
#define TIM_CCMR1_IC1F_2                (0x04U << TIM_CCMR1_IC1F_Pos)           /*!< Bit 2 */
#define TIM_CCMR1_IC1F_3                (0x08U << TIM_CCMR1_IC1F_Pos)           /*!< Bit 3 */

#define TIM_CCMR1_IC2PSC_Pos            (10)
#define TIM_CCMR1_IC2PSC                (0x03U << TIM_CCMR1_IC2PSC_Pos)         /*!< IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_DIV1           (0x00U << TIM_CCMR1_IC2PSC_Pos)         /*!< No Prescaler */
#define TIM_CCMR1_IC2PSC_DIV2           (0x01U << TIM_CCMR1_IC2PSC_Pos)         /*!< Capture is done once every 2 events */
#define TIM_CCMR1_IC2PSC_DIV4           (0x02U << TIM_CCMR1_IC2PSC_Pos)         /*!< Capture is done once every 4 events */
#define TIM_CCMR1_IC2PSC_DIV8           (0x03U << TIM_CCMR1_IC2PSC_Pos)         /*!< Capture is done once every 8 events */
#define TIM_CCMR1_IC2F_Pos              (12)
#define TIM_CCMR1_IC2F                  (0x0FU << TIM_CCMR1_IC2F_Pos)           /*!< IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0                (0x01U << TIM_CCMR1_IC2F_Pos)           /*!< Bit 0 */
#define TIM_CCMR1_IC2F_1                (0x02U << TIM_CCMR1_IC2F_Pos)           /*!< Bit 1 */
#define TIM_CCMR1_IC2F_2                (0x04U << TIM_CCMR1_IC2F_Pos)           /*!< Bit 2 */
#define TIM_CCMR1_IC2F_3                (0x08U << TIM_CCMR1_IC2F_Pos)           /*!< Bit 3 */

/**
  * @brief TIM_CCMR2 Register Bit Definition
  */
#define TIM_CCMR2_CC3S_Pos              (0)
#define TIM_CCMR2_CC3S                  (0x03U << TIM_CCMR2_CC3S_Pos)           /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_OC               (0x00U << TIM_CCMR2_CC3S_Pos)           /*!< Channel is configured as output */
#define TIM_CCMR2_CC3S_TI3              (0x01U << TIM_CCMR2_CC3S_Pos)           /*!< Channel is configured as input, IC3 is mapped on TI3 */
#define TIM_CCMR2_CC3S_TI4              (0x02U << TIM_CCMR2_CC3S_Pos)           /*!< Channel is configured as input, IC3 is mapped on TI4 */
#define TIM_CCMR2_CC3S_TRC              (0x03U << TIM_CCMR2_CC3S_Pos)           /*!< Channel is configured as input, IC3 is mapped on TRC */
#define TIM_CCMR2_OC3FE_Pos             (2)
#define TIM_CCMR2_OC3FE                 (0x01U << TIM_CCMR2_OC3FE_Pos)          /*!< Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos             (3)
#define TIM_CCMR2_OC3PE                 (0x01U << TIM_CCMR2_OC3PE_Pos)          /*!< Output Compare 3 Preload enable */
#define TIM_CCMR2_OC3M_Pos              (4)
#define TIM_CCMR2_OC3M                  (0x07U << TIM_CCMR2_OC3M_Pos)           /*!< OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_TIMING           (0x00U << TIM_CCMR2_OC3M_Pos)           /*!< Timing */
#define TIM_CCMR2_OC3M_ACTIVE           (0x01U << TIM_CCMR2_OC3M_Pos)           /*!< Active */
#define TIM_CCMR2_OC3M_INACTIVE         (0x02U << TIM_CCMR2_OC3M_Pos)           /*!< Inactive */
#define TIM_CCMR2_OC3M_TOGGLE           (0x03U << TIM_CCMR2_OC3M_Pos)           /*!< Toggle */
#define TIM_CCMR2_OC3M_FORCEINACTIVE    (0x04U << TIM_CCMR2_OC3M_Pos)           /*!< Forceinactive */
#define TIM_CCMR2_OC3M_FORCEACTIVE      (0x05U << TIM_CCMR2_OC3M_Pos)           /*!< Forceactive */
#define TIM_CCMR2_OC3M_PWM1             (0x06U << TIM_CCMR2_OC3M_Pos)           /*!< PWM1 */
#define TIM_CCMR2_OC3M_PWM2             (0x07U << TIM_CCMR2_OC3M_Pos)           /*!< PWM2 */
#define TIM_CCMR2_OC3CE_Pos             (7)
#define TIM_CCMR2_OC3CE                 (0x01U << TIM_CCMR2_OC3CE_Pos)          /*!< Output Compare 3 Clear Enable */

#define TIM_CCMR2_CC4S_Pos              (8)
#define TIM_CCMR2_CC4S                  (0x03U << TIM_CCMR2_CC4S_Pos)           /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_OC               (0x00U << TIM_CCMR2_CC4S_Pos)           /*!< Channel is configured as output */
#define TIM_CCMR2_CC4S_TI4              (0x01U << TIM_CCMR2_CC4S_Pos)           /*!< Channel is configured as input, IC4 is mapped on TI4 */
#define TIM_CCMR2_CC4S_TI3              (0x02U << TIM_CCMR2_CC4S_Pos)           /*!< Channel is configured as input, IC4 is mapped on TI3 */
#define TIM_CCMR2_CC4S_TRC              (0x03U << TIM_CCMR2_CC4S_Pos)           /*!< Channel is configured as input, IC4 is mapped on TRC */
#define TIM_CCMR2_OC4FE_Pos             (10)
#define TIM_CCMR2_OC4FE                 (0x01U << TIM_CCMR2_OC4FE_Pos)          /*!< Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos             (11)
#define TIM_CCMR2_OC4PE                 (0x01U << TIM_CCMR2_OC4PE_Pos)          /*!< Output Compare 4 Preload enable */
#define TIM_CCMR2_OC4M_Pos              (12)
#define TIM_CCMR2_OC4M                  (0x07U << TIM_CCMR2_OC4M_Pos)           /*!< OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_TIMING           (0x00U << TIM_CCMR2_OC4M_Pos)           /*!< Timing */
#define TIM_CCMR2_OC4M_ACTIVE           (0x01U << TIM_CCMR2_OC4M_Pos)           /*!< Active */
#define TIM_CCMR2_OC4M_INACTIVE         (0x02U << TIM_CCMR2_OC4M_Pos)           /*!< Inactive */
#define TIM_CCMR2_OC4M_TOGGLE           (0x03U << TIM_CCMR2_OC4M_Pos)           /*!< Toggle */
#define TIM_CCMR2_OC4M_FORCEINACTIVE    (0x04U << TIM_CCMR2_OC4M_Pos)           /*!< Forceinactive */
#define TIM_CCMR2_OC4M_FORCEACTIVE      (0x05U << TIM_CCMR2_OC4M_Pos)           /*!< Forceactive */
#define TIM_CCMR2_OC4M_PWM1             (0x06U << TIM_CCMR2_OC4M_Pos)           /*!< PWM1 */
#define TIM_CCMR2_OC4M_PWM2             (0x07U << TIM_CCMR2_OC4M_Pos)           /*!< PWM2 */
#define TIM_CCMR2_OC4CE_Pos             (15)
#define TIM_CCMR2_OC4CE                 (0x01U << TIM_CCMR2_OC4CE_Pos)          /*!< Output Compare 4 Clear Enable */


#define TIM_CCMR2_IC3PSC_Pos            (2)
#define TIM_CCMR2_IC3PSC                (0x03U << TIM_CCMR2_IC3PSC_Pos)         /*!< IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_DIV1           (0x00U << TIM_CCMR2_IC3PSC_Pos)         /*!< No Prescaler */
#define TIM_CCMR2_IC3PSC_DIV2           (0x01U << TIM_CCMR2_IC3PSC_Pos)         /*!< Capture is done once every 2 events */
#define TIM_CCMR2_IC3PSC_DIV4           (0x02U << TIM_CCMR2_IC3PSC_Pos)         /*!< Capture is done once every 4 events */
#define TIM_CCMR2_IC3PSC_DIV8           (0x03U << TIM_CCMR2_IC3PSC_Pos)         /*!< Capture is done once every 8 events */
#define TIM_CCMR2_IC3F_Pos              (4)
#define TIM_CCMR2_IC3F                  (0x0FU << TIM_CCMR2_IC3F_Pos)           /*!< IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0                (0x01U << TIM_CCMR2_IC3F_Pos)           /*!< Bit 0 */
#define TIM_CCMR2_IC3F_1                (0x02U << TIM_CCMR2_IC3F_Pos)           /*!< Bit 1 */
#define TIM_CCMR2_IC3F_2                (0x04U << TIM_CCMR2_IC3F_Pos)           /*!< Bit 2 */
#define TIM_CCMR2_IC3F_3                (0x08U << TIM_CCMR2_IC3F_Pos)           /*!< Bit 3 */

#define TIM_CCMR2_IC4PSC_Pos            (10)
#define TIM_CCMR2_IC4PSC                (0x03U << TIM_CCMR2_IC4PSC_Pos)         /*!< IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_DIV1           (0x00U << TIM_CCMR2_IC4PSC_Pos)         /*!< No Prescaler */
#define TIM_CCMR2_IC4PSC_DIV2           (0x01U << TIM_CCMR2_IC4PSC_Pos)         /*!< Capture is done once every 2 events */
#define TIM_CCMR2_IC4PSC_DIV4           (0x02U << TIM_CCMR2_IC4PSC_Pos)         /*!< Capture is done once every 4 events */
#define TIM_CCMR2_IC4PSC_DIV8           (0x03U << TIM_CCMR2_IC4PSC_Pos)         /*!< Capture is done once every 8 events */
#define TIM_CCMR2_IC4F_Pos              (12)
#define TIM_CCMR2_IC4F                  (0x0FU << TIM_CCMR2_IC4F_Pos)           /*!< IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0                (0x01U << TIM_CCMR2_IC4F_Pos)           /*!< Bit 0 */
#define TIM_CCMR2_IC4F_1                (0x02U << TIM_CCMR2_IC4F_Pos)           /*!< Bit 1 */
#define TIM_CCMR2_IC4F_2                (0x04U << TIM_CCMR2_IC4F_Pos)           /*!< Bit 2 */
#define TIM_CCMR2_IC4F_3                (0x08U << TIM_CCMR2_IC4F_Pos)           /*!< Bit 3 */

/**
  * @brief TIM_CCER Register Bit Definition
  */
#define TIM_CCER_CC1E_Pos               (0)
#define TIM_CCER_CC1E                   (0x01U << TIM_CCER_CC1E_Pos)            /*!< Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos               (1)
#define TIM_CCER_CC1P                   (0x01U << TIM_CCER_CC1P_Pos)            /*!< Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos              (2)
#define TIM_CCER_CC1NE                  (0x01U << TIM_CCER_CC1NE_Pos)           /*!< Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos              (3)
#define TIM_CCER_CC1NP                  (0x01U << TIM_CCER_CC1NP_Pos)           /*!< Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos               (4)
#define TIM_CCER_CC2E                   (0x01U << TIM_CCER_CC2E_Pos)            /*!< Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos               (5)
#define TIM_CCER_CC2P                   (0x01U << TIM_CCER_CC2P_Pos)            /*!< Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos              (6)
#define TIM_CCER_CC2NE                  (0x01U << TIM_CCER_CC2NE_Pos)           /*!< Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos              (7)
#define TIM_CCER_CC2NP                  (0x01U << TIM_CCER_CC2NP_Pos)           /*!< Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos               (8)
#define TIM_CCER_CC3E                   (0x01U << TIM_CCER_CC3E_Pos)            /*!< Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos               (9)
#define TIM_CCER_CC3P                   (0x01U << TIM_CCER_CC3P_Pos)            /*!< Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos              (10)
#define TIM_CCER_CC3NE                  (0x01U << TIM_CCER_CC3NE_Pos)           /*!< Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos              (11)
#define TIM_CCER_CC3NP                  (0x01U << TIM_CCER_CC3NP_Pos)           /*!< Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos               (12)
#define TIM_CCER_CC4E                   (0x01U << TIM_CCER_CC4E_Pos)            /*!< Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos               (13)
#define TIM_CCER_CC4P                   (0x01U << TIM_CCER_CC4P_Pos)            /*!< Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NP_Pos              (15)
#define TIM_CCER_CC4NP                  (0x01U << TIM_CCER_CC4NP_Pos)           /*!< Capture/Compare 4 Complementary output Polarity */

/**
  * @brief TIM_CNT Register Bit Definition
  */
#define TIM_CNT_POS                     (0)
#define TIM_CNT                         (0xFFFFU << TIM_CNT_POS)                /*!< Counter Value */

/**
  * @brief TIM_PSC Register Bit Definition
  */
#define TIM_PSC_POS                     (0)
#define TIM_PSC                         (0xFFFFU << TIM_PSC_POS)                /*!< Prescaler Value */

/**
  * @brief TIM_ARR Register Bit Definition
  */
#define TIM_ARR_POS                     (0)
#define TIM_ARR                         (0xFFFFU << TIM_ARR_POS)                /*!< actual auto-reload Value */

/**
  * @brief TIM_RCR Register Bit Definition
  */
#define TIM_RCR_REP_POS                 (0)
#define TIM_RCR_REP                     (0xFFU << TIM_RCR_REP_POS)              /*!< Repetition Counter Value */
#define TIM_RCR_REP_CNT_Pos             (8)
#define TIM_RCR_REP_CNT                 (0xFFU << TIM_RCR_REP_CNT_Pos)          /*!< Repetition counter value of real-time writing */

/**
  * @brief TIM_CCR1 Register Bit Definition
  */
#define TIM_CCR1_POS                    (0)
#define TIM_CCR1                        (0xFFFFU << TIM_CCR1_POS)               /*!< Capture/Compare 1 Value */

/**
  * @brief TIM_CCR2 Register Bit Definition
  */
#define TIM_CCR2_POS                    (0)
#define TIM_CCR2                        (0xFFFFU << TIM_CCR2_POS)               /*!< Capture/Compare 2 Value */

/**
  * @brief TIM_CCR3 Register Bit Definition
  */
#define TIM_CCR3_POS                    (0)
#define TIM_CCR3                        (0xFFFFU << TIM_CCR3_POS)               /*!< Capture/Compare 3 Value */

/**
  * @brief TIM_CCR4 Register Bit Definition
  */
#define TIM_CCR4_POS                    (0)
#define TIM_CCR4                        (0xFFFFU << TIM_CCR4_POS)               /*!< Capture/Compare 4 Value */

/**
  * @brief TIM_BDTR Register Bit Definition
  */
#define TIM_BDTR_DTG_Pos                (0)
#define TIM_BDTR_DTG                    (0xFFU << TIM_BDTR_DTG_Pos)             /*!< DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0                  (0x01U << TIM_BDTR_DTG_Pos)             /*!< Bit 0 */
#define TIM_BDTR_DTG_1                  (0x02U << TIM_BDTR_DTG_Pos)             /*!< Bit 1 */
#define TIM_BDTR_DTG_2                  (0x04U << TIM_BDTR_DTG_Pos)             /*!< Bit 2 */
#define TIM_BDTR_DTG_3                  (0x08U << TIM_BDTR_DTG_Pos)             /*!< Bit 3 */
#define TIM_BDTR_DTG_4                  (0x10U << TIM_BDTR_DTG_Pos)             /*!< Bit 4 */
#define TIM_BDTR_DTG_5                  (0x20U << TIM_BDTR_DTG_Pos)             /*!< Bit 5 */
#define TIM_BDTR_DTG_6                  (0x40U << TIM_BDTR_DTG_Pos)             /*!< Bit 6 */
#define TIM_BDTR_DTG_7                  (0x80U << TIM_BDTR_DTG_Pos)             /*!< Bit 7 */
#define TIM_BDTR_LOCK_Pos               (8)
#define TIM_BDTR_LOCK                   (0x03U << TIM_BDTR_LOCK_Pos)            /*!< LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_OFF               (0x00U << TIM_BDTR_LOCK_Pos)            /*!< Lock Off */
#define TIM_BDTR_LOCK_1                 (0x01U << TIM_BDTR_LOCK_Pos)            /*!< Lock Level 1 */
#define TIM_BDTR_LOCK_2                 (0x02U << TIM_BDTR_LOCK_Pos)            /*!< Lock Level 2 */
#define TIM_BDTR_LOCK_3                 (0x03U << TIM_BDTR_LOCK_Pos)            /*!< Lock Level 3 */
#define TIM_BDTR_OSSI_Pos               (10)
#define TIM_BDTR_OSSI                   (0x01U << TIM_BDTR_OSSI_Pos)            /*!< Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos               (11)
#define TIM_BDTR_OSSR                   (0x01U << TIM_BDTR_OSSR_Pos)            /*!< Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos                (12)
#define TIM_BDTR_BKE                    (0x01U << TIM_BDTR_BKE_Pos)             /*!< Break enable */
#define TIM_BDTR_BKP_Pos                (13)
#define TIM_BDTR_BKP                    (0x01U << TIM_BDTR_BKP_Pos)             /*!< Break Polarity */
#define TIM_BDTR_AOE_Pos                (14)
#define TIM_BDTR_AOE                    (0x01U << TIM_BDTR_AOE_Pos)             /*!< Automatic Output enable */
#define TIM_BDTR_MOE_Pos                (15)
#define TIM_BDTR_MOE                    (0x01U << TIM_BDTR_MOE_Pos)             /*!< Main Output enable */
#define TIM_BDTR_DOE_Pos                (16)
#define TIM_BDTR_DOE                    (0x01U << TIM_BDTR_DOE_Pos)             /*!< Direct Output enable */

/**
  * @brief TIM_DCR Register Bit Definition
  */
#define TIM_DCR_DBA_Pos                 (0)
#define TIM_DCR_DBA                     (0x1FU << TIM_DCR_DBA_Pos)              /*!< DBA[4 :0] bits (DMA Base Address) */
#define TIM_DCR_DBA_0                   (0x01U << TIM_DCR_DBA_Pos)              /*!< Bit 0 */
#define TIM_DCR_DBA_1                   (0x02U << TIM_DCR_DBA_Pos)              /*!< Bit 1 */
#define TIM_DCR_DBA_2                   (0x04U << TIM_DCR_DBA_Pos)              /*!< Bit 2 */
#define TIM_DCR_DBA_3                   (0x08U << TIM_DCR_DBA_Pos)              /*!< Bit 3 */
#define TIM_DCR_DBA_4                   (0x10U << TIM_DCR_DBA_Pos)              /*!< Bit 4 */
#define TIM_DCR_DBL_Pos                 (8)
#define TIM_DCR_DBL                     (0x1FU << TIM_DCR_DBL_Pos)              /*!< DBL[4 :0] bits (DMA Burst Length) */
#define TIM_DCR_DBL_0                   (0x01U << TIM_DCR_DBL_Pos)              /*!< Bit 0 */
#define TIM_DCR_DBL_1                   (0x02U << TIM_DCR_DBL_Pos)              /*!< Bit 1 */
#define TIM_DCR_DBL_2                   (0x04U << TIM_DCR_DBL_Pos)              /*!< Bit 2 */
#define TIM_DCR_DBL_3                   (0x08U << TIM_DCR_DBL_Pos)              /*!< Bit 3 */
#define TIM_DCR_DBL_4                   (0x10U << TIM_DCR_DBL_Pos)              /*!< Bit 4 */

/**
  * @brief TIM_DMAR Register Bit Definition
  */
#define TIM_DMAR_DMAB_Pos               (0)
#define TIM_DMAR_DMAB                   (0xFFFFU << TIM_DMAR_DMAB_Pos)          /*!< DMA register for burst accesses */

/**
  * @brief TIM_OR Register Bit Definition
  */

#define TIM_OR_ETR_RMP_Pos              (0)
#define TIM_OR_ETR_RMP                  (0x03U << TIM_OR_ETR_RMP_Pos)           /*!< ETR multiplex */
#define TIM_OR_ETR_RMP_ETR_GPIO         (0x00U << TIM_OR_ETR_RMP_Pos)           /*!< ETR GPIO input */
#define TIM_OR_ETR_RMP_LSI              (0x01U << TIM_OR_ETR_RMP_Pos)           /*!< LSI clock input */
#define TIM_OR_ETR_RMP_LSE              (0x02U << TIM_OR_ETR_RMP_Pos)           /*!< LSE clock input */
#define TIM_OR_ETR_RMP_HSE_DIV128       (0x03U << TIM_OR_ETR_RMP_Pos)           /*!< HSE_CLK_DIV_128 clock input */
#define TIM_OR_TI4_RMP_Pos              (6)
#define TIM_OR_TI4_RMP                  (0x03U << TIM_OR_TI4_RMP_Pos)           /*!< TI4 multiplex */
#define TIM_OR_TI4_RMP_CH4_GPIO         (0x00U << TIM_OR_TI4_RMP_Pos)           /*!< CH4 GPIO or CPT input */
#define TIM_OR_TI4_RMP_LSI              (0x01U << TIM_OR_TI4_RMP_Pos)           /*!< LSI clock input */
#define TIM_OR_TI4_RMP_LSE              (0x02U << TIM_OR_TI4_RMP_Pos)           /*!< LSE clock input */
#define TIM_OR_TI4_RMP_HSE_DIV128       (0x03U << TIM_OR_TI4_RMP_Pos)           /*!< HSE_CLK_DIV_128 clock input */

/**
  * @brief TIM_CCMR3 Register Bit Definition
  */
#define TIM_CCMR3_OC5PE_Pos             (3)
#define TIM_CCMR3_OC5PE                 (0x01U << TIM_CCMR3_OC5PE_Pos)          /*!< Output Compare 5 Preload enable */

/**
  * @brief TIM_CCR5 Register Bit Definition
  */
#define TIM_CCR5_POS                    (0)
#define TIM_CCR5                        (0xFFFFU << TIM_CCR5_POS)               /*!< Capture/Compare 5 Value */

/**
  * @brief TIM_PDER Register Bit Definition
  */
#define TIM_PDER_CCDREPE_Pos            (0)
#define TIM_PDER_CCDREPE                (0x01U << TIM_PDER_CCDREPE_Pos)         /*!< DMA request flow enable */
#define TIM_PDER_CCR1_SHIFT_EN_Pos      (1)
#define TIM_PDER_CCR1_SHIFT_EN          (0x01U << TIM_PDER_CCR1_SHIFT_EN_Pos)   /*!< CCR1 pwm shift enable */
#define TIM_PDER_CCR2_SHIFT_EN_Pos      (2)
#define TIM_PDER_CCR2_SHIFT_EN          (0x01U << TIM_PDER_CCR2_SHIFT_EN_Pos)   /*!< CCR2 pwm shift enable */
#define TIM_PDER_CCR3_SHIFT_EN_Pos      (3)
#define TIM_PDER_CCR3_SHIFT_EN          (0x01U << TIM_PDER_CCR3_SHIFT_EN_Pos)   /*!< CCR3 pwm shift enable */
#define TIM_PDER_CCR4_SHIFT_EN_Pos      (4)
#define TIM_PDER_CCR4_SHIFT_EN          (0x01U << TIM_PDER_CCR4_SHIFT_EN_Pos)   /*!< CCR4 pwm shift enable */
#define TIM_PDER_CCR5_SHIFT_EN_Pos      (5)
#define TIM_PDER_CCR5_SHIFT_EN          (0x01U << TIM_PDER_CCR5_SHIFT_EN_Pos)   /*!< CCR5 pwm shift enable */

/**
  * @brief TIM_CCR1FALL Register Bit Definition
  */
#define TIM_CCR1FALL_POS                (0)
#define TIM_CCR1FALL                    (0xFFFFU << TIM_CCR1FALL_POS)           /*!< Capture/compare value for ch1 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR2FALL Register Bit Definition
  */
#define TIM_CCR2FALL_POS                (0)
#define TIM_CCR2FALL                    (0xFFFFU << TIM_CCR2FALL_POS)           /*!< Capture/compare value for ch2 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR3FALL Register Bit Definition
  */
#define TIM_CCR3FALL_POS                (0)
#define TIM_CCR3FALL                    (0xFFFFU << TIM_CCR3FALL_POS)           /*!< Capture/compare value for ch3 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR4FALL Register Bit Definition
  */
#define TIM_CCR4FALL_POS                (0)
#define TIM_CCR4FALL                    (0xFFFFU << TIM_CCR4FALL_POS)           /*!< Capture/compare value for ch4 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR5FALL Register Bit Definition
  */
#define TIM_CCR5FALL_POS                (0)
#define TIM_CCR5FALL                    (0xFFFFU << TIM_CCR5FALL_POS)           /*!< Capture/compare value for ch5 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_BKINF Register Bit Definition
  */
#define TIM_BKINF_BKINFE_Pos            (0)
#define TIM_BKINF_BKINFE                (0x01U << TIM_BKINF_BKINFE_Pos)         /*!< Break input filter enable */

#define TIM_BKINF_BKINF_Pos             (1)
#define TIM_BKINF_BKINF                 (0x0FU << TIM_BKINF_BKINF_Pos)          /*!< Break input filter */
#define TIM_BKINF_BKINF_0               (0x01U << TIM_BKINF_BKINF_Pos)          /*!< Bit0 */
#define TIM_BKINF_BKINF_1               (0x02U << TIM_BKINF_BKINF_Pos)          /*!< Bit1 */
#define TIM_BKINF_BKINF_2               (0x04U << TIM_BKINF_BKINF_Pos)          /*!< Bit2 */
#define TIM_BKINF_BKINF_3               (0x08U << TIM_BKINF_BKINF_Pos)          /*!< Bit3 */
#define TIM_BKINF_BKINF_2_Period        (0x00U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 2 cycles */
#define TIM_BKINF_BKINF_4_Period        (0x01U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 4 cycles */
#define TIM_BKINF_BKINF_8_Period        (0x02U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 8 cycles */
#define TIM_BKINF_BKINF_16_Period       (0x03U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 16 cycles */
#define TIM_BKINF_BKINF_32_Period       (0x04U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 32 cycles */
#define TIM_BKINF_BKINF_64_Period       (0x05U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 64 cycles */
#define TIM_BKINF_BKINF_128_Period      (0x06U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 128 cycles */
#define TIM_BKINF_BKINF_256_Period      (0x07U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 256 cycles */
#define TIM_BKINF_BKINF_384_Period      (0x08U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 384 cycles */
#define TIM_BKINF_BKINF_512_Period      (0x09U << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 512 cycles */
#define TIM_BKINF_BKINF_640_Period      (0x0AU << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 640 cycles */
#define TIM_BKINF_BKINF_768_Period      (0x0BU << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 768 cycles */
#define TIM_BKINF_BKINF_896_Period      (0x0CU << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 896 cycles */
#define TIM_BKINF_BKINF_1024_Period     (0x0DU << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 1024 cycles */
#define TIM_BKINF_BKINF_1152_Period     (0x0EU << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 1152 cycles */
#define TIM_BKINF_BKINF_1280_Period     (0x0FU << TIM_BKINF_BKINF_Pos)          /*!< Filter sampling frequency is 1280 cycles */
#define TIM_BKINF_BKIN_SEL_Pos          (5)
#define TIM_BKINF_BKIN_SEL              (0xFFFU << TIM_BKINF_BKIN_SEL_Pos)      /*!< Break input source select */
#define TIM_BKINF_BKIN_SEL_CSS          (0x001U << TIM_BKINF_BKIN_SEL_Pos)      /*!< Bit0 */
#define TIM_BKINF_BKIN_SEL_BKIN1        (0x002U << TIM_BKINF_BKIN_SEL_Pos)      /*!< Bit1 */
#define TIM_BKINF_BKIN_SEL_BKIN2        (0x004U << TIM_BKINF_BKIN_SEL_Pos)      /*!< Bit2 */
#define TIM_BKINF_BKIN_SEL_BKIN3        (0x008U << TIM_BKINF_BKIN_SEL_Pos)      /*!< Bit3 */
#define TIM_BKINF_BKIN_SEL_BKIN4        (0x010U << TIM_BKINF_BKIN_SEL_Pos)      /*!< Bit4 */
#define TIM_BKINF_BKIN_SEL_CPT          (0x040U << TIM_BKINF_BKIN_SEL_Pos)      /*!< Bit6 */

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
