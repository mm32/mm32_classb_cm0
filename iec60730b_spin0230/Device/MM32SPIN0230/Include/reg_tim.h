/***********************************************************************************************************************
    @file     reg_tim.h
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
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/**
  * @brief TIM Base Address Definition
  */
#define TIM1_BASE                       (APB1PERIPH_BASE + 0x12C00) /*!< Base Address: 0x40012C00 */
#define TIM2_BASE                       (APB1PERIPH_BASE + 0x0000)  /*!< Base Address: 0x40000000 */
#define TIM6_BASE                       (APB1PERIPH_BASE + 0x1000)  /*!< Base Address: 0x40001000 */
#define TIM13_BASE                      (APB1PERIPH_BASE + 0x1800)  /*!< Base Address: 0x40001800 */
#define TIM14_BASE                      (APB1PERIPH_BASE + 0x14000) /*!< Base Address: 0x40014000 */

/**
  * @brief Timer Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                 /*!< TIM control register 1,                        offset: 0x00 */
    __IO uint32_t CR2;                 /*!< TIM control register 2,                        offset: 0x04 */
    __IO uint32_t SMCR;                /*!< TIM slave Mode Control register,               offset: 0x08 */
    __IO uint32_t DIER;                /*!< TIM DMA/interrupt enable register,             offset: 0x0C */
    __IO uint32_t SR;                  /*!< TIM status register,                           offset: 0x10 */
    __IO uint32_t EGR;                 /*!< TIM event generation register,                 offset: 0x14 */
    __IO uint32_t CCMR1;               /*!< TIM capture/compare mode register 1,           offset: 0x18 */
    __IO uint32_t CCMR2;               /*!< TIM capture/compare mode register 2,           offset: 0x1C */
    __IO uint32_t CCER;                /*!< TIM capture/compare enable register,           offset: 0x20 */
    __IO uint32_t CNT;                 /*!< TIM counter register,                          offset: 0x24 */
    __IO uint32_t PSC;                 /*!< TIM prescaler register,                        offset: 0x28 */
    __IO uint32_t ARR;                 /*!< TIM auto-reload register,                      offset: 0x2C */
    __IO uint32_t RCR;                 /*!< TIM repetition counter register,               offset: 0x30 */
    __IO uint32_t CCR1;                /*!< TIM capture/compare register 1,                offset: 0x34 */
    __IO uint32_t CCR2;                /*!< TIM capture/compare register 2,                offset: 0x38 */
    __IO uint32_t CCR3;                /*!< TIM capture/compare register 3,                offset: 0x3C */
    __IO uint32_t CCR4;                /*!< TIM capture/compare register 4,                offset: 0x40 */
    __IO uint32_t BDTR;                /*!< TIM break and dead-time register,              offset: 0x44 */
    __IO uint32_t DCR;                 /*!< TIM DMA control register,                      offset: 0x48 */
    __IO uint32_t DMAR;                /*!< TIM DMA address for full transfer register,    offset: 0x4C */
    __IO uint32_t OR;                  /*!< Input option register, for TIM2,               offset: 0x50 */
    __IO uint32_t CCMR3;               /*!< TIM capture/compare mode register 3,           offset: 0x54 */
    __IO uint32_t CCR5;                /*!< TIM capture/compare register 5,                offset: 0x58 */
    __IO uint32_t PDER;                /*!< PWM Shift repeat enable register,              offset: 0x5C */
    __IO uint32_t CCR1FALL;            /*!< PWM shift count CCR1 register,                 offset: 0x60 */
    __IO uint32_t CCR2FALL;            /*!< PWM shift count CCR2 register,                 offset: 0x64 */
    __IO uint32_t CCR3FALL;            /*!< PWM shift count CCR3 register,                 offset: 0x68 */
    __IO uint32_t CCR4FALL;            /*!< PWM shift count CCR4 register,                 offset: 0x6c */
    __IO uint32_t CCR5FALL;            /*!< PWM shift count CCR5 register,                 offset: 0x70 */
    __IO uint32_t BKINF;               /*!< TIM Brake input filter register,               offset: 0x74 */
} TIM_TypeDef;

/**
  * @brief TIM type pointer Definition
  */
#define TIM1                            ((TIM_TypeDef *)TIM1_BASE)
#define TIM2                            ((TIM_TypeDef *)TIM2_BASE)
#define TIM6                            ((TIM_TypeDef *)TIM6_BASE)
#define TIM13                           ((TIM_TypeDef *)TIM13_BASE)
#define TIM14                           ((TIM_TypeDef *)TIM14_BASE)

/**
  * @brief TIM_CR1 Register Bit Definition
  */
#define TIM_CR1_CEN_Pos                 (0)
#define TIM_CR1_CEN_Msk                 (0x01U << TIM_CR1_CEN_Pos)   /*!< Counter enable */
#define TIM_CR1_UDIS_Pos                (1)
#define TIM_CR1_UDIS_Msk                (0x01U << TIM_CR1_UDIS_Pos)  /*!< Update disable */
#define TIM_CR1_URS_Pos                 (2)
#define TIM_CR1_URS_Msk                 (0x01U << TIM_CR1_URS_Pos)   /*!< Update request source */
#define TIM_CR1_OPM_Pos                 (3)
#define TIM_CR1_OPM_Msk                 (0x01U << TIM_CR1_OPM_Pos)   /*!< One pulse mode */
#define TIM_CR1_DIR_Pos                 (4)
#define TIM_CR1_DIR_Msk                 (0x01U << TIM_CR1_DIR_Pos)   /*!< Direction */
#define TIM_CR1_CMS_Pos                 (5)
#define TIM_CR1_CMS_Msk                 (0x03U << TIM_CR1_CMS_Pos)   /*!< CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_EDGEALIGNED         (0x00U << TIM_CR1_CMS_Pos)   /*!< Edge-aligned mode */
#define TIM_CR1_CMS_CENTERALIGNED1      (0x01U << TIM_CR1_CMS_Pos)   /*!< Center-aligned mode 1 */
#define TIM_CR1_CMS_CENTERALIGNED2      (0x02U << TIM_CR1_CMS_Pos)   /*!< Center-aligned mode 2 */
#define TIM_CR1_CMS_CENTERALIGNED3      (0x03U << TIM_CR1_CMS_Pos)   /*!< Center-aligned mode 3 */
#define TIM_CR1_ARPE_Pos                (7)
#define TIM_CR1_ARPE_Msk                (0x01U << TIM_CR1_ARPE_Pos)  /*!< Auto-reload preload enable */
#define TIM_CR1_CKD_Pos                 (8)
#define TIM_CR1_CKD_Msk                 (0x03U << TIM_CR1_CKD_Pos)   /*!< CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_DIV1                (0x00U << TIM_CR1_CKD_Pos)   /*!< Divided by 1 */
#define TIM_CR1_CKD_DIV2                (0x01U << TIM_CR1_CKD_Pos)   /*!< Divided by 2 */
#define TIM_CR1_CKD_DIV4                (0x02U << TIM_CR1_CKD_Pos)   /*!< Divided by 4 */

/**
  * @brief TIM_CR2 Register Bit Definition
  */
#define TIM_CR2_CCPC_Pos                (0)
#define TIM_CR2_CCPC_Msk                (0x01U << TIM_CR2_CCPC_Pos)  /*!< Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos                (2)
#define TIM_CR2_CCUS_Msk                (0x01U << TIM_CR2_CCUS_Pos)  /*!< Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos                (3)
#define TIM_CR2_CCDS_Msk                (0x01U << TIM_CR2_CCDS_Pos)  /*!< Capture/Compare DMA Selection */
#define TIM_CR2_MMS_Pos                 (4)
#define TIM_CR2_MMS_Msk                 (0x07U << TIM_CR2_MMS_Pos)   /*!< MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_RESET               (0x00U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: Reset */
#define TIM_CR2_MMS_ENABLE              (0x01U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: Enable */
#define TIM_CR2_MMS_UPDATE              (0x02U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: Update */
#define TIM_CR2_MMS_OC1                 (0x03U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: OC1 */
#define TIM_CR2_MMS_OC1REF              (0x04U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: OC1Ref */
#define TIM_CR2_MMS_OC2REF              (0x05U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: OC2Ref */
#define TIM_CR2_MMS_OC3REF              (0x06U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: OC3Ref */
#define TIM_CR2_MMS_OC4REF              (0x07U << TIM_CR2_MMS_Pos)   /*!< Master Mode Select: OC4Ref */
#define TIM_CR2_TI1S_Pos                (7)
#define TIM_CR2_TI1S_Msk                (0x01U << TIM_CR2_TI1S_Pos)  /*!< TI1 Selection */
#define TIM_CR2_OIS1_Pos                (8)
#define TIM_CR2_OIS1_Msk                (0x01U << TIM_CR2_OIS1_Pos)  /*!< Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos               (9)
#define TIM_CR2_OIS1N_Msk               (0x01U << TIM_CR2_OIS1N_Pos) /*!< Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos                (10)
#define TIM_CR2_OIS2_Msk                (0x01U << TIM_CR2_OIS2_Pos)  /*!< Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos               (11)
#define TIM_CR2_OIS2N_Msk               (0x01U << TIM_CR2_OIS2N_Pos) /*!< Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos                (12)
#define TIM_CR2_OIS3_Msk                (0x01U << TIM_CR2_OIS3_Pos)  /*!< Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos               (13)
#define TIM_CR2_OIS3N_Msk               (0x01U << TIM_CR2_OIS3N_Pos) /*!< Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos                (14)
#define TIM_CR2_OIS4_Msk                (0x01U << TIM_CR2_OIS4_Pos)  /*!< Output Idle state 4 (OC4 output) */
#define TIM_CR2_OIS4N_Pos               (15)
#define TIM_CR2_OIS4N_Msk               (0x01U << TIM_CR2_OIS4N_Pos) /*!< Output Idle state 4 (OC4N output) */

/**
  * @brief TIM_SMCR Register Bit Definition
  */
#define TIM_SMCR_SMS_Pos                (0)
#define TIM_SMCR_SMS_Msk                (0x07U << TIM_SMCR_SMS_Pos)  /*!< SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_OFF                (0x00U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: OFF */
#define TIM_SMCR_SMS_ENCODER1           (0x01U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: Encoder1 */
#define TIM_SMCR_SMS_ENCODER2           (0x02U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: Encoder2 */
#define TIM_SMCR_SMS_ENCODER3           (0x03U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: Encoder3 */
#define TIM_SMCR_SMS_RESET              (0x04U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: Reset */
#define TIM_SMCR_SMS_GATED              (0x05U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: Gated */
#define TIM_SMCR_SMS_TRIGGER            (0x06U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: Trigger */
#define TIM_SMCR_SMS_EXTERNAL1          (0x07U << TIM_SMCR_SMS_Pos)  /*!< Slave Mode select: External1 */

#define TIM_SMCR_OCCS_Pos               (3)
#define TIM_SMCR_OCCS_Msk               (0x01U << TIM_SMCR_OCCS_Pos) /*!< Output compare clear selection */

#define TIM_SMCR_TS_Pos                 (4)
#define TIM_SMCR_TS_Msk                 (0x07U << TIM_SMCR_TS_Pos)   /*!< TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_ITR0                (0x00U << TIM_SMCR_TS_Pos)   /*!< Internal Trigger 0 (ITR0) */
#define TIM_SMCR_TS_ITR1                (0x01U << TIM_SMCR_TS_Pos)   /*!< Internal Trigger 1 (ITR1) */
#define TIM_SMCR_TS_ITR2                (0x02U << TIM_SMCR_TS_Pos)   /*!< Internal Trigger 2 (ITR2) */
#define TIM_SMCR_TS_ITR3                (0x03U << TIM_SMCR_TS_Pos)   /*!< Internal Trigger 3 (ITR3) */
#define TIM_SMCR_TS_TI1F_ED             (0x04U << TIM_SMCR_TS_Pos)   /*!< TI1 Edge Detector (TI1F_ED) */
#define TIM_SMCR_TS_TI1FP1              (0x05U << TIM_SMCR_TS_Pos)   /*!< Filtered Timer Input 1 (TI1FP1) */
#define TIM_SMCR_TS_TI2FP2              (0x06U << TIM_SMCR_TS_Pos)   /*!< Filtered Timer Input 2 (TI2FP2) */
#define TIM_SMCR_TS_ETR                 (0x07U << TIM_SMCR_TS_Pos)   /*!< External Trigger input (ETRF) */
#define TIM_SMCR_MSM_Pos                (7)
#define TIM_SMCR_MSM_Msk                (0x01U << TIM_SMCR_MSM_Pos)  /*!< Master/slave mode */
#define TIM_SMCR_ETF_Pos                (8)
#define TIM_SMCR_ETF_Msk                (0x0FU << TIM_SMCR_ETF_Pos)  /*!< ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0                  (0x01U << TIM_SMCR_ETF_Pos)  /*!< Bit 0 */
#define TIM_SMCR_ETF_1                  (0x02U << TIM_SMCR_ETF_Pos)  /*!< Bit 1 */
#define TIM_SMCR_ETF_2                  (0x04U << TIM_SMCR_ETF_Pos)  /*!< Bit 2 */
#define TIM_SMCR_ETF_3                  (0x08U << TIM_SMCR_ETF_Pos)  /*!< Bit 3 */
#define TIM_SMCR_ETPS_Pos               (12)
#define TIM_SMCR_ETPS_Msk               (0x03U << TIM_SMCR_ETPS_Pos) /*!< ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_OFF               (0x00U << TIM_SMCR_ETPS_Pos) /*!< Prescaler OFF */
#define TIM_SMCR_ETPS_DIV2              (0x01U << TIM_SMCR_ETPS_Pos) /*!< ETRP frequency divided by 2 */
#define TIM_SMCR_ETPS_DIV4              (0x02U << TIM_SMCR_ETPS_Pos) /*!< ETRP frequency divided by 4 */
#define TIM_SMCR_ETPS_DIV8              (0x03U << TIM_SMCR_ETPS_Pos) /*!< ETRP frequency divided by 8 */
#define TIM_SMCR_ECE_Pos                (14)
#define TIM_SMCR_ECE_Msk                (0x01U << TIM_SMCR_ECE_Pos)  /*!< External clock enable */
#define TIM_SMCR_ETP_Pos                (15)
#define TIM_SMCR_ETP_Msk                (0x01U << TIM_SMCR_ETP_Pos)  /*!< External trigger polarity */

/**
  * @brief TIM_DIER Register Bit Definition
  */
#define TIM_DIER_UIE_Pos                (0)
#define TIM_DIER_UIE_Msk                (0x01U << TIM_DIER_UIE_Pos)   /*!< Update interrupt enable */
#define TIM_DIER_CC1IE_Pos              (1)
#define TIM_DIER_CC1IE_Msk              (0x01U << TIM_DIER_CC1IE_Pos) /*!< Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos              (2)
#define TIM_DIER_CC2IE_Msk              (0x01U << TIM_DIER_CC2IE_Pos) /*!< Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos              (3)
#define TIM_DIER_CC3IE_Msk              (0x01U << TIM_DIER_CC3IE_Pos) /*!< Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos              (4)
#define TIM_DIER_CC4IE_Msk              (0x01U << TIM_DIER_CC4IE_Pos) /*!< Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos              (5)
#define TIM_DIER_COMIE_Msk              (0x01U << TIM_DIER_COMIE_Pos) /*!< COM interrupt enable */
#define TIM_DIER_TIE_Pos                (6)
#define TIM_DIER_TIE_Msk                (0x01U << TIM_DIER_TIE_Pos)   /*!< Trigger interrupt enable */
#define TIM_DIER_BIE_Pos                (7)
#define TIM_DIER_BIE_Msk                (0x01U << TIM_DIER_BIE_Pos)   /*!< Break interrupt enable */
#define TIM_DIER_UDE_Pos                (8)
#define TIM_DIER_UDE_Msk                (0x01U << TIM_DIER_UDE_Pos)   /*!< Update DMA request enable */
#define TIM_DIER_CC1DE_Pos              (9)
#define TIM_DIER_CC1DE_Msk              (0x01U << TIM_DIER_CC1DE_Pos) /*!< Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos              (10)
#define TIM_DIER_CC2DE_Msk              (0x01U << TIM_DIER_CC2DE_Pos) /*!< Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos              (11)
#define TIM_DIER_CC3DE_Msk              (0x01U << TIM_DIER_CC3DE_Pos) /*!< Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos              (12)
#define TIM_DIER_CC4DE_Msk              (0x01U << TIM_DIER_CC4DE_Pos) /*!< Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos              (13)
#define TIM_DIER_COMDE_Msk              (0x01U << TIM_DIER_COMDE_Pos) /*!< COM DMA request enable */
#define TIM_DIER_TDE_Pos                (14)
#define TIM_DIER_TDE_Msk                (0x01U << TIM_DIER_TDE_Pos)   /*!< Trigger DMA request enable */
#define TIM_DIER_CC5IE_Pos              (16)
#define TIM_DIER_CC5IE_Msk              (0x01U << TIM_DIER_CC5IE_Pos) /*!< Capture/Compare 5 interrupt enable */
#define TIM_DIER_CC5DE_Pos              (17)
#define TIM_DIER_CC5DE_Msk              (0x01U << TIM_DIER_CC5DE_Pos) /*!< Capture/Compare 5 DMA request enable */

/**
  * @brief TIM_SR Register Bit Definition
  */
#define TIM_SR_UIF_Pos                  (0)
#define TIM_SR_UIF_Msk                  (0x01U << TIM_SR_UIF_Pos)   /*!< Update interrupt Flag */
#define TIM_SR_CC1IF_Pos                (1)
#define TIM_SR_CC1IF_Msk                (0x01U << TIM_SR_CC1IF_Pos) /*!< Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos                (2)
#define TIM_SR_CC2IF_Msk                (0x01U << TIM_SR_CC2IF_Pos) /*!< Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos                (3)
#define TIM_SR_CC3IF_Msk                (0x01U << TIM_SR_CC3IF_Pos) /*!< Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos                (4)
#define TIM_SR_CC4IF_Msk                (0x01U << TIM_SR_CC4IF_Pos) /*!< Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos                (5)
#define TIM_SR_COMIF_Msk                (0x01U << TIM_SR_COMIF_Pos) /*!< COM interrupt Flag */
#define TIM_SR_TIF_Pos                  (6)
#define TIM_SR_TIF_Msk                  (0x01U << TIM_SR_TIF_Pos)   /*!< Trigger interrupt Flag */
#define TIM_SR_BIF_Pos                  (7)
#define TIM_SR_BIF_Msk                  (0x01U << TIM_SR_BIF_Pos)   /*!< Break interrupt Flag */
#define TIM_SR_CC1OF_Pos                (9)
#define TIM_SR_CC1OF_Msk                (0x01U << TIM_SR_CC1OF_Pos) /*!< Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos                (10)
#define TIM_SR_CC2OF_Msk                (0x01U << TIM_SR_CC2OF_Pos) /*!< Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos                (11)
#define TIM_SR_CC3OF_Msk                (0x01U << TIM_SR_CC3OF_Pos) /*!< Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos                (12)
#define TIM_SR_CC4OF_Msk                (0x01U << TIM_SR_CC4OF_Pos) /*!< Capture/Compare 4 Overcapture Flag */

#define TIM_SR_CC5IF_Pos                (16)
#define TIM_SR_CC5IF_Msk                (0x01U << TIM_SR_CC5IF_Pos) /*!< Capture/Compare 5 interrupt Flag */

/**
  * @brief TIM_EGR Register Bit Definition
  */
#define TIM_EGR_UG_Pos                  (0)
#define TIM_EGR_UG_Msk                  (0x01U << TIM_EGR_UG_Pos)   /*!< Update Generation */
#define TIM_EGR_CC1G_Pos                (1)
#define TIM_EGR_CC1G_Msk                (0x01U << TIM_EGR_CC1G_Pos) /*!< Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos                (2)
#define TIM_EGR_CC2G_Msk                (0x01U << TIM_EGR_CC2G_Pos) /*!< Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos                (3)
#define TIM_EGR_CC3G_Msk                (0x01U << TIM_EGR_CC3G_Pos) /*!< Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos                (4)
#define TIM_EGR_CC4G_Msk                (0x01U << TIM_EGR_CC4G_Pos) /*!< Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos                (5)
#define TIM_EGR_COMG_Msk                (0x01U << TIM_EGR_COMG_Pos) /*!< Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos                  (6)
#define TIM_EGR_TG_Msk                  (0x01U << TIM_EGR_TG_Pos)   /*!< Trigger Generation */
#define TIM_EGR_BG_Pos                  (7)
#define TIM_EGR_BG_Msk                  (0x01U << TIM_EGR_BG_Pos)   /*!< Break Generation */

#define TIM_EGR_CC5G_Pos                (16)
#define TIM_EGR_CC5G_Msk                (0x01U << TIM_EGR_CC5G_Pos) /*!< Capture/Compare 5 Generation */

/**
  * @brief TIM_CCMR1 Register Bit Definition
  */
#define TIM_CCMR1_CC1S_Pos              (0)
#define TIM_CCMR1_CC1S_Msk              (0x03U << TIM_CCMR1_CC1S_Pos)   /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_OC               (0x00U << TIM_CCMR1_CC1S_Pos)   /*!< Channel is configured as output */
#define TIM_CCMR1_CC1S_DIRECTTI         (0x01U << TIM_CCMR1_CC1S_Pos)   /*!< Channel is configured as input, IC1 is mapped on TI1 */
#define TIM_CCMR1_CC1S_INDIRECTTI       (0x02U << TIM_CCMR1_CC1S_Pos)   /*!< Channel is configured as input, IC1 is mapped on TI2 */
#define TIM_CCMR1_CC1S_TRC              (0x03U << TIM_CCMR1_CC1S_Pos)   /*!< Channel is configured as input, IC1 is mapped on TRC */
#define TIM_CCMR1_OC1FE_Pos             (2)
#define TIM_CCMR1_OC1FE_Msk             (0x01U << TIM_CCMR1_OC1FE_Pos)  /*!< Output Compare 1 Fast enable */

#define TIM_CCMR1_OC1PE_Pos             (3)
#define TIM_CCMR1_OC1PE_Msk             (0x01U << TIM_CCMR1_OC1PE_Pos)  /*!< Output Compare 1 Preload enable */
#define TIM_CCMR1_OC1M_Pos              (4)
#define TIM_CCMR1_OC1M_Msk              (0x07U << TIM_CCMR1_OC1M_Pos)   /*!< OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_TIMING           (0x00U << TIM_CCMR1_OC1M_Pos)   /*!< Timing */
#define TIM_CCMR1_OC1M_ACTIVE           (0x01U << TIM_CCMR1_OC1M_Pos)   /*!< Active */
#define TIM_CCMR1_OC1M_INACTIVE         (0x02U << TIM_CCMR1_OC1M_Pos)   /*!< Inactive */
#define TIM_CCMR1_OC1M_TOGGLE           (0x03U << TIM_CCMR1_OC1M_Pos)   /*!< Toggle */
#define TIM_CCMR1_OC1M_FORCEINACTIVE    (0x04U << TIM_CCMR1_OC1M_Pos)   /*!< Forceinactive */
#define TIM_CCMR1_OC1M_FORCEACTIVE      (0x05U << TIM_CCMR1_OC1M_Pos)   /*!< Forceactive */
#define TIM_CCMR1_OC1M_PWM1             (0x06U << TIM_CCMR1_OC1M_Pos)   /*!< PWM1 */
#define TIM_CCMR1_OC1M_PWM2             (0x07U << TIM_CCMR1_OC1M_Pos)   /*!< PWM2 */

#define TIM_CCMR1_OC1CE_Pos             (7)
#define TIM_CCMR1_OC1CE_Msk             (0x01U << TIM_CCMR1_OC1CE_Pos)  /*!< Output Compare 1Clear Enable */
#define TIM_CCMR1_CC2S_Pos              (8)
#define TIM_CCMR1_CC2S_Msk              (0x03U << TIM_CCMR1_CC2S_Pos)   /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_OC2FE_Pos             (10)
#define TIM_CCMR1_OC2FE_Msk             (0x01U << TIM_CCMR1_OC2FE_Pos)  /*!< Output Compare 2 Fast enable */
#define TIM_CCMR1_OC2PE_Pos             (11)
#define TIM_CCMR1_OC2PE_Msk             (0x01U << TIM_CCMR1_OC2PE_Pos)  /*!< Output Compare 2 Preload enable */
#define TIM_CCMR1_OC2M_Pos              (12)
#define TIM_CCMR1_OC2M_Msk              (0x07U << TIM_CCMR1_OC2M_Pos)   /*!< OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_TIMING           (0x00U << TIM_CCMR1_OC2M_Pos)   /*!< Timing */
#define TIM_CCMR1_OC2M_ACTIVE           (0x01U << TIM_CCMR1_OC2M_Pos)   /*!< Active */
#define TIM_CCMR1_OC2M_INACTIVE         (0x02U << TIM_CCMR1_OC2M_Pos)   /*!< Inactive */
#define TIM_CCMR1_OC2M_TOGGLE           (0x03U << TIM_CCMR1_OC2M_Pos)   /*!< Toggle */
#define TIM_CCMR1_OC2M_FORCEINACTIVE    (0x04U << TIM_CCMR1_OC2M_Pos)   /*!< Forceinactive */
#define TIM_CCMR1_OC2M_FORCEACTIVE      (0x05U << TIM_CCMR1_OC2M_Pos)   /*!< Forceactive */
#define TIM_CCMR1_OC2M_PWM1             (0x06U << TIM_CCMR1_OC2M_Pos)   /*!< PWM1 */
#define TIM_CCMR1_OC2M_PWM2             (0x07U << TIM_CCMR1_OC2M_Pos)   /*!< PWM2 */
#define TIM_CCMR1_OC2CE_Pos             (15)
#define TIM_CCMR1_OC2CE_Msk             (0x01U << TIM_CCMR1_OC2CE_Pos)  /*!< Output Compare 2 Clear Enable */

#define TIM_CCMR1_IC1PSC_Pos            (2)
#define TIM_CCMR1_IC1PSC_Msk            (0x03U << TIM_CCMR1_IC1PSC_Pos) /*!< IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_DIV1           (0x00U << TIM_CCMR1_IC1PSC_Pos) /*!< No Prescaler */
#define TIM_CCMR1_IC1PSC_DIV2           (0x01U << TIM_CCMR1_IC1PSC_Pos) /*!< Capture is done once every 2 events */
#define TIM_CCMR1_IC1PSC_DIV4           (0x02U << TIM_CCMR1_IC1PSC_Pos) /*!< Capture is done once every 4 events */
#define TIM_CCMR1_IC1PSC_DIV8           (0x03U << TIM_CCMR1_IC1PSC_Pos) /*!< Capture is done once every 8 events */
#define TIM_CCMR1_IC1F_Pos              (4)
#define TIM_CCMR1_IC1F_Msk              (0x0FU << TIM_CCMR1_IC1F_Pos)   /*!< IC1F[3:0] bits (Input Capture 1 Filter) */
#define TIM_CCMR1_IC1F_0                (0x01U << TIM_CCMR1_IC1F_Pos)   /*!< Bit 0 */
#define TIM_CCMR1_IC1F_1                (0x02U << TIM_CCMR1_IC1F_Pos)   /*!< Bit 1 */
#define TIM_CCMR1_IC1F_2                (0x04U << TIM_CCMR1_IC1F_Pos)   /*!< Bit 2 */
#define TIM_CCMR1_IC1F_3                (0x08U << TIM_CCMR1_IC1F_Pos)   /*!< Bit 3 */

#define TIM_CCMR1_IC2PSC_Pos            (10)
#define TIM_CCMR1_IC2PSC_Msk            (0x03U << TIM_CCMR1_IC2PSC_Pos) /*!< IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TIM_CCMR1_IC2PSC_DIV1           (0x00U << TIM_CCMR1_IC2PSC_Pos) /*!< No Prescaler */
#define TIM_CCMR1_IC2PSC_DIV2           (0x01U << TIM_CCMR1_IC2PSC_Pos) /*!< Capture is done once every 2 events */
#define TIM_CCMR1_IC2PSC_DIV4           (0x02U << TIM_CCMR1_IC2PSC_Pos) /*!< Capture is done once every 4 events */
#define TIM_CCMR1_IC2PSC_DIV8           (0x03U << TIM_CCMR1_IC2PSC_Pos) /*!< Capture is done once every 8 events */
#define TIM_CCMR1_IC2F_Pos              (12)
#define TIM_CCMR1_IC2F_Msk              (0x0FU << TIM_CCMR1_IC2F_Pos)   /*!< IC2F[3:0] bits (Input Capture 2 Filter) */
#define TIM_CCMR1_IC2F_0                (0x01U << TIM_CCMR1_IC2F_Pos)   /*!< Bit 0 */
#define TIM_CCMR1_IC2F_1                (0x02U << TIM_CCMR1_IC2F_Pos)   /*!< Bit 1 */
#define TIM_CCMR1_IC2F_2                (0x04U << TIM_CCMR1_IC2F_Pos)   /*!< Bit 2 */
#define TIM_CCMR1_IC2F_3                (0x08U << TIM_CCMR1_IC2F_Pos)   /*!< Bit 3 */

/**
  * @brief TIM_CCMR2 Register Bit Definition
  */
#define TIM_CCMR2_CC3S_Pos              (0)
#define TIM_CCMR2_CC3S_Msk              (0x03U << TIM_CCMR2_CC3S_Pos)   /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_OC               (0x00U << TIM_CCMR2_CC3S_Pos)   /*!< Channel is configured as output */
#define TIM_CCMR2_CC3S_DIRECTTI         (0x01U << TIM_CCMR2_CC3S_Pos)   /*!< Channel is configured as input, IC3 is mapped on TI3 */
#define TIM_CCMR2_CC3S_INDIRECTTI       (0x02U << TIM_CCMR2_CC3S_Pos)   /*!< Channel is configured as input, IC3 is mapped on TI4 */
#define TIM_CCMR2_CC3S_TRC              (0x03U << TIM_CCMR2_CC3S_Pos)   /*!< Channel is configured as input, IC3 is mapped on TRC */
#define TIM_CCMR2_OC3FE_Pos             (2)
#define TIM_CCMR2_OC3FE_Msk             (0x01U << TIM_CCMR2_OC3FE_Pos)  /*!< Output Compare 3 Fast enable */
#define TIM_CCMR2_IC3PSC_Pos            (2)
#define TIM_CCMR2_IC3PSC_Msk            (0x03U << TIM_CCMR2_IC3PSC_Pos) /*!< IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_DIV1           (0x00U << TIM_CCMR2_IC3PSC_Pos) /*!< No Prescaler */
#define TIM_CCMR2_IC3PSC_DIV2           (0x01U << TIM_CCMR2_IC3PSC_Pos) /*!< Capture is done once every 2 events */
#define TIM_CCMR2_IC3PSC_DIV4           (0x02U << TIM_CCMR2_IC3PSC_Pos) /*!< Capture is done once every 4 events */
#define TIM_CCMR2_IC3PSC_DIV8           (0x03U << TIM_CCMR2_IC3PSC_Pos) /*!< Capture is done once every 8 events */
#define TIM_CCMR2_OC3PE_Pos             (3)
#define TIM_CCMR2_OC3PE_Msk             (0x01U << TIM_CCMR2_OC3PE_Pos)  /*!< Output Compare 3 Preload enable */
#define TIM_CCMR2_OC3M_Pos              (4)
#define TIM_CCMR2_OC3M_Msk              (0x07U << TIM_CCMR2_OC3M_Pos)   /*!< OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_TIMING           (0x00U << TIM_CCMR2_OC3M_Pos)   /*!< Timing */
#define TIM_CCMR2_OC3M_ACTIVE           (0x01U << TIM_CCMR2_OC3M_Pos)   /*!< Active */
#define TIM_CCMR2_OC3M_INACTIVE         (0x02U << TIM_CCMR2_OC3M_Pos)   /*!< Inactive */
#define TIM_CCMR2_OC3M_TOGGLE           (0x03U << TIM_CCMR2_OC3M_Pos)   /*!< Toggle */
#define TIM_CCMR2_OC3M_FORCEINACTIVE    (0x04U << TIM_CCMR2_OC3M_Pos)   /*!< Forceinactive */
#define TIM_CCMR2_OC3M_FORCEACTIVE      (0x05U << TIM_CCMR2_OC3M_Pos)   /*!< Forceactive */
#define TIM_CCMR2_OC3M_PWM1             (0x06U << TIM_CCMR2_OC3M_Pos)   /*!< PWM1 */
#define TIM_CCMR2_OC3M_PWM2             (0x07U << TIM_CCMR2_OC3M_Pos)   /*!< PWM2 */
#define TIM_CCMR2_IC3F_Pos              (4)
#define TIM_CCMR2_IC3F_Msk              (0x0FU << TIM_CCMR2_IC3F_Pos)   /*!< IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0                (0x01U << TIM_CCMR2_IC3F_Pos)   /*!< Bit 0 */
#define TIM_CCMR2_IC3F_1                (0x02U << TIM_CCMR2_IC3F_Pos)   /*!< Bit 1 */
#define TIM_CCMR2_IC3F_2                (0x04U << TIM_CCMR2_IC3F_Pos)   /*!< Bit 2 */
#define TIM_CCMR2_IC3F_3                (0x08U << TIM_CCMR2_IC3F_Pos)   /*!< Bit 3 */
#define TIM_CCMR2_OC3CE_Pos             (7)
#define TIM_CCMR2_OC3CE_Msk             (0x01U << TIM_CCMR2_OC3CE_Pos)  /*!< Output Compare 3 Clear Enable */
#define TIM_CCMR2_CC4S_Pos              (8)
#define TIM_CCMR2_CC4S_Msk              (0x03U << TIM_CCMR2_CC4S_Pos)   /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_OC               (0x00U << TIM_CCMR2_CC4S_Pos)   /*!< Channel is configured as output */
#define TIM_CCMR2_CC4S_DIRECTTI         (0x01U << TIM_CCMR2_CC4S_Pos)   /*!< Channel is configured as input, IC4 is mapped on TI4 */
#define TIM_CCMR2_CC4S_INDIRECTTI       (0x02U << TIM_CCMR2_CC4S_Pos)   /*!< Channel is configured as input, IC4 is mapped on TI3 */
#define TIM_CCMR2_CC4S_TRC              (0x03U << TIM_CCMR2_CC4S_Pos)   /*!< Channel is configured as input, IC4 is mapped on TRC */
#define TIM_CCMR2_OC4FE_Pos             (10)
#define TIM_CCMR2_OC4FE_Msk             (0x01U << TIM_CCMR2_OC4FE_Pos)  /*!< Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos             (11)
#define TIM_CCMR2_OC4PE_Msk             (0x01U << TIM_CCMR2_OC4PE_Pos)  /*!< Output Compare 4 Preload enable */
#define TIM_CCMR2_OC4M_Pos              (12)
#define TIM_CCMR2_OC4M_Msk              (0x07U << TIM_CCMR2_OC4M_Pos)   /*!< OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_TIMING           (0x00U << TIM_CCMR2_OC4M_Pos)   /*!< Timing */
#define TIM_CCMR2_OC4M_ACTIVE           (0x01U << TIM_CCMR2_OC4M_Pos)   /*!< Active */
#define TIM_CCMR2_OC4M_INACTIVE         (0x02U << TIM_CCMR2_OC4M_Pos)   /*!< Inactive */
#define TIM_CCMR2_OC4M_TOGGLE           (0x03U << TIM_CCMR2_OC4M_Pos)   /*!< Toggle */
#define TIM_CCMR2_OC4M_FORCEINACTIVE    (0x04U << TIM_CCMR2_OC4M_Pos)   /*!< Forceinactive */
#define TIM_CCMR2_OC4M_FORCEACTIVE      (0x05U << TIM_CCMR2_OC4M_Pos)   /*!< Forceactive */
#define TIM_CCMR2_OC4M_PWM1             (0x06U << TIM_CCMR2_OC4M_Pos)   /*!< PWM1 */
#define TIM_CCMR2_OC4M_PWM2             (0x07U << TIM_CCMR2_OC4M_Pos)   /*!< PWM2 */
#define TIM_CCMR2_OC4CE_Pos             (15)
#define TIM_CCMR2_OC4CE_Msk             (0x01U << TIM_CCMR2_OC4CE_Pos)  /*!< Output Compare 4 Clear Enable */
#define TIM_CCMR2_IC4PSC_Pos            (10)
#define TIM_CCMR2_IC4PSC_Msk            (0x03U << TIM_CCMR2_IC4PSC_Pos) /*!< IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_DIV1           (0x00U << TIM_CCMR2_IC4PSC_Pos) /*!< No Prescaler */
#define TIM_CCMR2_IC4PSC_DIV2           (0x01U << TIM_CCMR2_IC4PSC_Pos) /*!< Capture is done once every 2 events */
#define TIM_CCMR2_IC4PSC_DIV4           (0x02U << TIM_CCMR2_IC4PSC_Pos) /*!< Capture is done once every 4 events */
#define TIM_CCMR2_IC4PSC_DIV8           (0x03U << TIM_CCMR2_IC4PSC_Pos) /*!< Capture is done once every 8 events */
#define TIM_CCMR2_IC4F_Pos              (12)
#define TIM_CCMR2_IC4F_Msk              (0x0FU << TIM_CCMR2_IC4F_Pos)   /*!< IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0                (0x01U << TIM_CCMR2_IC4F_Pos)   /*!< Bit 0 */
#define TIM_CCMR2_IC4F_1                (0x02U << TIM_CCMR2_IC4F_Pos)   /*!< Bit 1 */
#define TIM_CCMR2_IC4F_2                (0x04U << TIM_CCMR2_IC4F_Pos)   /*!< Bit 2 */
#define TIM_CCMR2_IC4F_3                (0x08U << TIM_CCMR2_IC4F_Pos)   /*!< Bit 3 */

/**
  * @brief TIM_CCER Register Bit Definition
  */
#define TIM_CCER_CC1E_Pos               (0)
#define TIM_CCER_CC1E_Msk               (0x01U << TIM_CCER_CC1E_Pos)  /*!< Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos               (1)
#define TIM_CCER_CC1P_Msk               (0x01U << TIM_CCER_CC1P_Pos)   /*!< Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos              (2)
#define TIM_CCER_CC1NE_Msk              (0x01U << TIM_CCER_CC1NE_Pos)  /*!< Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos              (3)
#define TIM_CCER_CC1NP_Msk              (0x01U << TIM_CCER_CC1NP_Pos)  /*!< Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos               (4)
#define TIM_CCER_CC2E_Msk               (0x01U << TIM_CCER_CC2E_Pos)   /*!< Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos               (5)
#define TIM_CCER_CC2P_Msk               (0x01U << TIM_CCER_CC2P_Pos)   /*!< Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos              (6)
#define TIM_CCER_CC2NE_Msk              (0x01U << TIM_CCER_CC2NE_Pos)  /*!< Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos              (7)
#define TIM_CCER_CC2NP_Msk              (0x01U << TIM_CCER_CC2NP_Pos)  /*!< Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos               (8)
#define TIM_CCER_CC3E_Msk               (0x01U << TIM_CCER_CC3E_Pos)   /*!< Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos               (9)
#define TIM_CCER_CC3P_Msk               (0x01U << TIM_CCER_CC3P_Pos)   /*!< Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos              (10)
#define TIM_CCER_CC3NE_Msk              (0x01U << TIM_CCER_CC3NE_Pos)  /*!< Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos              (11)
#define TIM_CCER_CC3NP_Msk              (0x01U << TIM_CCER_CC3NP_Pos)  /*!< Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos               (12)
#define TIM_CCER_CC4E_Msk               (0x01U << TIM_CCER_CC4E_Pos)   /*!< Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos               (13)
#define TIM_CCER_CC4P_Msk               (0x01U << TIM_CCER_CC4P_Pos)   /*!< Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NE_Pos              (14)
#define TIM_CCER_CC4NE_Msk              (0x01U << TIM_CCER_CC4NE_Pos)  /*!< Capture/Compare 4 Complementary output enable */
#define TIM_CCER_CC4NP_Pos              (15)
#define TIM_CCER_CC4NP_Msk              (0x01U << TIM_CCER_CC4NP_Pos)  /*!< Capture/Compare 4 Complementary output Polarity */

/**
  * @brief TIM_CNT Register Bit Definition
  */
#define TIM_CNT_CNT                     (0xFFFFFFFFU) /*!< Counter Value */

/**
  * @brief TIM_PSC Register Bit Definition
  */
#define TIM_PSC_PSC                     (0xFFFFU)     /*!< Prescaler Value */

/**
  * @brief TIM_ARR Register Bit Definition
  */
#define TIM_ARR_ARR                     (0xFFFFFFFFU)                      /*!< actual auto-reload Value */

/**
  * @brief TIM_RCR Register Bit Definition
  */
#define TIM_RCR_REP_Pos                 (0)
#define TIM_RCR_REP_Msk                 (0xFFU << TIM_RCR_REP_Pos)              /*!< Repetition Counter Value */

#define TIM_RCR_REP_CNT_Pos             (8)
#define TIM_RCR_REP_CNT_Msk             (0xFFU << TIM_RCR_REP_CNT_Pos) /*!< Repetition counter value of real-time writing */

/**
  * @brief TIM_CCR1 Register Bit Definition
  */
#define TIM_CCR1_CCR1                   (0xFFFFFFFFU) /*!< Capture/Compare 1 Value */

/**
  * @brief TIM_CCR2 Register Bit Definition
  */
#define TIM_CCR2_CCR2                   (0xFFFFFFFFU) /*!< Capture/Compare 2 Value */

/**
  * @brief TIM_CCR3 Register Bit Definition
  */
#define TIM_CCR3_CCR3                   (0xFFFFFFFFU) /*!< Capture/Compare 3 Value */

/**
  * @brief TIM_CCR4 Register Bit Definition
  */
#define TIM_CCR4_CCR4                   (0xFFFFFFFFU) /*!< Capture/Compare 4 Value */

/**
  * @brief TIM_BDTR Register Bit Definition
  */
#define TIM_BDTR_DTG_Pos                (0)
#define TIM_BDTR_DTG_Msk                (0xFFU << TIM_BDTR_DTG_Pos)  /*!< DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0                  (0x01U << TIM_BDTR_DTG_Pos)  /*!< Bit 0 */
#define TIM_BDTR_DTG_1                  (0x02U << TIM_BDTR_DTG_Pos)  /*!< Bit 1 */
#define TIM_BDTR_DTG_2                  (0x04U << TIM_BDTR_DTG_Pos)  /*!< Bit 2 */
#define TIM_BDTR_DTG_3                  (0x08U << TIM_BDTR_DTG_Pos)  /*!< Bit 3 */
#define TIM_BDTR_DTG_4                  (0x10U << TIM_BDTR_DTG_Pos)  /*!< Bit 4 */
#define TIM_BDTR_DTG_5                  (0x20U << TIM_BDTR_DTG_Pos)  /*!< Bit 5 */
#define TIM_BDTR_DTG_6                  (0x40U << TIM_BDTR_DTG_Pos)  /*!< Bit 6 */
#define TIM_BDTR_DTG_7                  (0x80U << TIM_BDTR_DTG_Pos)  /*!< Bit 7 */
#define TIM_BDTR_LOCK_Pos               (8)
#define TIM_BDTR_LOCK_Msk               (0x03U << TIM_BDTR_LOCK_Pos) /*!< LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_OFF               (0x00U << TIM_BDTR_LOCK_Pos) /*!< Lock Off */
#define TIM_BDTR_LOCK_1                 (0x01U << TIM_BDTR_LOCK_Pos) /*!< Lock Level 1 */
#define TIM_BDTR_LOCK_2                 (0x02U << TIM_BDTR_LOCK_Pos) /*!< Lock Level 2 */
#define TIM_BDTR_LOCK_3                 (0x03U << TIM_BDTR_LOCK_Pos) /*!< Lock Level 3 */
#define TIM_BDTR_OSSI_Pos               (10)
#define TIM_BDTR_OSSI_Msk               (0x01U << TIM_BDTR_OSSI_Pos) /*!< Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos               (11)
#define TIM_BDTR_OSSR_Msk               (0x01U << TIM_BDTR_OSSR_Pos) /*!< Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos                (12)
#define TIM_BDTR_BKE_Msk                (0x01U << TIM_BDTR_BKE_Pos)  /*!< Break enable */
#define TIM_BDTR_BKP_Pos                (13)
#define TIM_BDTR_BKP_Msk                (0x01U << TIM_BDTR_BKP_Pos)  /*!< Break Polarity */
#define TIM_BDTR_AOE_Pos                (14)
#define TIM_BDTR_AOE_Msk                (0x01U << TIM_BDTR_AOE_Pos)  /*!< Automatic Output enable */
#define TIM_BDTR_MOE_Pos                (15)
#define TIM_BDTR_MOE_Msk                (0x01U << TIM_BDTR_MOE_Pos)  /*!< Main Output enable */

#define TIM_BDTR_DOE_Pos                (16)
#define TIM_BDTR_DOE_Msk                (0x01U << TIM_BDTR_DOE_Pos)  /*!< Direct Output enable */

/**
  * @brief TIM_DCR Register Bit Definition
  */
#define TIM_DCR_DBA_Pos                 (0)
#define TIM_DCR_DBA_Msk                 (0x1FU << TIM_DCR_DBA_Pos)   /*!< DBA[4:0] bits (DMA Base Address) */
#define TIM_DCR_DBA_0                   (0x01U << TIM_DCR_DBA_Pos)   /*!< Bit 0 */
#define TIM_DCR_DBA_1                   (0x02U << TIM_DCR_DBA_Pos)   /*!< Bit 1 */
#define TIM_DCR_DBA_2                   (0x04U << TIM_DCR_DBA_Pos)   /*!< Bit 2 */
#define TIM_DCR_DBA_3                   (0x08U << TIM_DCR_DBA_Pos)   /*!< Bit 3 */
#define TIM_DCR_DBA_4                   (0x10U << TIM_DCR_DBA_Pos)   /*!< Bit 4 */
#define TIM_DCR_DBL_Pos                 (8)
#define TIM_DCR_DBL_Msk                 (0x1FU << TIM_DCR_DBL_Pos)   /*!< DBL[4:0] bits (DMA Burst Length) */
#define TIM_DCR_DBL_0                   (0x01U << TIM_DCR_DBL_Pos)   /*!< Bit 0 */
#define TIM_DCR_DBL_1                   (0x02U << TIM_DCR_DBL_Pos)   /*!< Bit 1 */
#define TIM_DCR_DBL_2                   (0x04U << TIM_DCR_DBL_Pos)   /*!< Bit 2 */
#define TIM_DCR_DBL_3                   (0x08U << TIM_DCR_DBL_Pos)   /*!< Bit 3 */
#define TIM_DCR_DBL_4                   (0x10U << TIM_DCR_DBL_Pos)   /*!< Bit 4 */

/**
  * @brief TIM_DMAR Register Bit Definition
  */
#define TIM_DMAR_DMAB                   (0xFFFFU)                    /*!< DMA register for burst accesses */

/**
  * @brief TIM_OR Register Bit Definition
  */
#define TIM_OR_ETR_RMP_Pos              (0)
#define TIM_OR_ETR_RMP_Msk              (0x03U << TIM_OR_ETR_RMP_Pos)           /*!< ETR multiplexing */

#define TIM_OR_TI4_RMP_Pos              (6)
#define TIM_OR_TI4_RMP_Msk              (0x03U << TIM_OR_TI4_RMP_Pos)
#define TIM_OR_TI4_RMP_0                (0x00U << TIM_OR_TI4_RMP_Pos)           /*!< CH4 GPIO or comparator input */
#define TIM_OR_TI4_RMP_1                (0x01U << TIM_OR_TI4_RMP_Pos)           /*!< LSI clock input */

/**
  * @brief TIM_CCMR3 Register Bit Definition
  */
#define TIM_CCMR3_OC5PE_Pos             (3)
#define TIM_CCMR3_OC5PE_Msk             (0x01U << TIM_CCMR3_OC5PE_Pos)  /*!< Output Compare 5 Preload enable */

/**
  * @brief TIM_CCR5 Register Bit Definition
  */
#define TIM_CCR5_CCR5                   (0xFFFFU)                        /*!< Capture/Compare 5 Value */

/**
  * @brief TIM_PDER Register Bit Definition
  */
#define TIM_PDER_CCDREPE_Pos            (0)
#define TIM_PDER_CCDREPE_Msk            (0x01U << TIM_PDER_CCDREPE_Pos)     /*!< DMA request flow enable */
#define TIM_PDER_CCR1SHIFTEN_Pos        (1)
#define TIM_PDER_CCR1SHIFTEN_Msk        (0x01U << TIM_PDER_CCR1SHIFTEN_Pos) /*!< CCR1 pwm shift enable */
#define TIM_PDER_CCR2SHIFTEN_Pos        (2)
#define TIM_PDER_CCR2SHIFTEN_Msk        (0x01U << TIM_PDER_CCR2SHIFTEN_Pos) /*!< CCR2 pwm shift enable */
#define TIM_PDER_CCR3SHIFTEN_Pos        (3)
#define TIM_PDER_CCR3SHIFTEN_Msk        (0x01U << TIM_PDER_CCR3SHIFTEN_Pos) /*!< CCR3 pwm shift enable */
#define TIM_PDER_CCR4SHIFTEN_Pos        (4)
#define TIM_PDER_CCR4SHIFTEN_Msk        (0x01U << TIM_PDER_CCR4SHIFTEN_Pos) /*!< CCR4 pwm shift enable */
#define TIM_PDER_CCR5SHIFTEN_Pos        (5)
#define TIM_PDER_CCR5SHIFTEN_Msk        (0x01U << TIM_PDER_CCR5SHIFTEN_Pos) /*!< CCR5 pwm shift enable */

/**
  * @brief TIM_CCR1FALL Register Bit Definition
  */
#define TIM_CCR1FALL_CCR1FALL           (0xFFFFU)                           /*!< Capture/compare value for ch1 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR2FALL Register Bit Definition
  */
#define TIM_CCR2FALL_CCR2FALL           (0xFFFFU)                           /*!< Capture/compare value for ch2 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR3FALL Register Bit Definition
  */
#define TIM_CCR3FALL_CCR3FALL           (0xFFFFU)                           /*!< Capture/compare value for ch3 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR4FALL Register Bit Definition
  */
#define TIM_CCR4FALL_CCR4FALL           (0xFFFFU)                           /*!< Capture/compare value for ch4 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_CCR5FALL Register Bit Definition
  */
#define TIM_CCR5FALL_CCR5FALL           (0xFFFFU)                           /*!< Capture/compare value for ch5 when counting down in PWM center-aligned mode */

/**
  * @brief TIM_BKINF Register Bit Definition
  */
#define TIM_BKINF_BKINFE_Pos            (0)
#define TIM_BKINF_BKINFE_Msk            (0x01U << TIM_BKINF_BKINFE_Pos)    /*!< Break input filter enable */
#define TIM_BKINF_BKINF_Pos             (1)
#define TIM_BKINF_BKINF_Msk             (0x0FU << TIM_BKINF_BKINF_Pos)     /*!< Break input filter */

#define TIM_BKINF_IOBKIN_SEL_Pos        (6)
#define TIM_BKINF_IOBKIN_SEL_Msk        (0x7FU << TIM_BKINF_IOBKIN_SEL_Pos)     /*!< IO break input sel */

#define TIM_BKINF_COMPBKIN_SEL_Pos      (13)
#define TIM_BKINF_COMPBKIN_SEL_Msk      (0x03U << TIM_BKINF_COMPBKIN_SEL_Pos)   /*!< COMP break input sel */

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

