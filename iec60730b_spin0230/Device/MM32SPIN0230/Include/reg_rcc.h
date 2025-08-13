/***********************************************************************************************************************
    @file     reg_rcc.h
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

#ifndef __REG_RCC_H
#define __REG_RCC_H

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
  * @brief RCC Base Address Definition
  */
#define RCC_BASE                        (AHBPERIPH_BASE + 0x1000) /*!< Base Address: 0x40021000 */

/**
  * @brief RCC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                    /*!< Control Register                               offset: 0x00 */
    __IO uint32_t CFGR;                  /*!< Configuration Register                         offset: 0x04 */
    __IO uint32_t CIR;                   /*!< Clock Interrupt Register                       offset: 0x08 */
    __IO uint32_t RESERVED0x0C;          /*!< Reserved                                       offset: 0x0C */
    __IO uint32_t AHBRSTR;               /*!< Advanced High Performance Bus Reset Register   offset: 0x10 */
    __IO uint32_t RESERVED0x14;          /*!< Reserved                                       offset: 0x14 */
    __IO uint32_t APB1RSTR;              /*!< Advanced Peripheral Bus 1 Reset Register       offset: 0x18 */
    __IO uint32_t RESERVED0x1C;          /*!< Reserved                                       offset: 0x1C */
    __IO uint32_t AHBENR;                /*!< Advanced High Performance Bus Enable Register  offset: 0x20 */
    __IO uint32_t RESERVED0x24;          /*!< Reserved                                       offset: 0x24 */
    __IO uint32_t APB1ENR;               /*!< Advanced Peripheral Bus 1 Enable Register      offset: 0x28 */
    __IO uint32_t RESERVED0x2C[3];       /*!< Reserved                                       offset: 0x2C~0x34 */
    __IO uint32_t CSR;                   /*!< Control Status Register                        offset: 0x38 */
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                             ((RCC_TypeDef *)RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define RCC_CR_HSION_Pos                (0)
#define RCC_CR_HSION_Msk                (0x01U << RCC_CR_HSION_Pos)             /*!< Internal High Speed clock enable */

#define RCC_CR_HSIRDY_Pos               (1)
#define RCC_CR_HSIRDY_Msk               (0x01U << RCC_CR_HSIRDY_Pos)            /*!< Internal High Speed clock ready flag */

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define RCC_CFGR_SW_Pos                 (0)
#define RCC_CFGR_SW_Msk                 (0x03U << RCC_CFGR_SW_Pos)              /*!< SW[1:0] bits (System clock Switch) */

#define RCC_CFGR_SWS_Pos                (2)
#define RCC_CFGR_SWS_Msk                (0x03U << RCC_CFGR_SWS_Pos)             /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_HSI                (0x00U << RCC_CFGR_SWS_Pos)         /*!< HSI/6 oscillator used as system clock */
#define RCC_CFGR_SWS_LSI                (0x03U << RCC_CFGR_SWS_Pos)         /*!< LSI used as system clock */

#define RCC_CFGR_HPRE_Pos               (4)
#define RCC_CFGR_HPRE_Msk               (0x0FU << RCC_CFGR_HPRE_Pos)            /*!< HPRE[3:0] bits (AHB prescaler) */
/* legacy define */
#define RCC_CFGR_HPRE_0                 (0x01U << RCC_CFGR_HPRE_Pos)            /*!< Bit 0 */
#define RCC_CFGR_HPRE_1                 (0x02U << RCC_CFGR_HPRE_Pos)            /*!< Bit 1 */
#define RCC_CFGR_HPRE_2                 (0x04U << RCC_CFGR_HPRE_Pos)            /*!< Bit 2 */
#define RCC_CFGR_HPRE_3                 (0x08U << RCC_CFGR_HPRE_Pos)            /*!< Bit 3 */

#define RCC_CFGR_PPRE1_Pos              (8)
#define RCC_CFGR_PPRE1_Msk              (0x07U << RCC_CFGR_PPRE1_Pos)           /*!< PRE1[2:0] bits (APB1 prescaler) */
/* legacy define */
#define RCC_CFGR_PPRE1_0                (0x01U << RCC_CFGR_PPRE1_Pos)           /*!< Bit 0 */
#define RCC_CFGR_PPRE1_1                (0x02U << RCC_CFGR_PPRE1_Pos)           /*!< Bit 1 */
#define RCC_CFGR_PPRE1_2                (0x04U << RCC_CFGR_PPRE1_Pos)           /*!< Bit 2 */

#define RCC_CFGR_MCO_Pos                (24)
#define RCC_CFGR_MCO_Msk                (0x07U << RCC_CFGR_MCO_Pos)             /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCO_NOCLOCK            (0x00U << RCC_CFGR_MCO_Pos)         /*!< No clock */
#define RCC_CFGR_MCO_LSI                (0x02U << RCC_CFGR_MCO_Pos)         /*!< LSI clock */
#define RCC_CFGR_MCO_SYSCLK_DIV8        (0x04U << RCC_CFGR_MCO_Pos)         /*!< System clock 8 frequency division */
#define RCC_CFGR_MCO_HSI_DIV8           (0x06U << RCC_CFGR_MCO_Pos)         /*!< HSI clock 8 frequency division */

/**
  * @brief RCC_CIR Register Bit Definition
  */
#define RCC_CIR_LSIRDYF_Pos             (0)
#define RCC_CIR_LSIRDYF_Msk             (0x01U << RCC_CIR_LSIRDYF_Pos)          /*!< LSI Ready Interrupt flag */

#define RCC_CIR_HSIRDYF_Pos             (2)
#define RCC_CIR_HSIRDYF_Msk             (0x01U << RCC_CIR_HSIRDYF_Pos)          /*!< HSI Ready Interrupt flag */

#define RCC_CIR_LSIRDYIE_Pos            (8)
#define RCC_CIR_LSIRDYIE_Msk            (0x01U << RCC_CIR_LSIRDYIE_Pos)         /*!< LSI Ready Interrupt Enable */

#define RCC_CIR_HSIRDYIE_Pos            (10)
#define RCC_CIR_HSIRDYIE_Msk            (0x01U << RCC_CIR_HSIRDYIE_Pos)         /*!< HSI Ready Interrupt Enable */

#define RCC_CIR_LSIRDYC_Pos             (16)
#define RCC_CIR_LSIRDYC_Msk             (0x01U << RCC_CIR_LSIRDYC_Pos)          /*!< LSI Ready Interrupt Clear */

#define RCC_CIR_HSIRDYC_Pos             (18)
#define RCC_CIR_HSIRDYC_Msk             (0x01U << RCC_CIR_HSIRDYC_Pos)          /*!< HSI Ready Interrupt Clear */

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define RCC_AHBRSTR_DMA_Pos             (0)
#define RCC_AHBRSTR_DMA_Msk             (0x01U << RCC_AHBRSTR_DMA_Pos)          /*!< DMA Reset */

#define RCC_AHBRSTR_GPIOA_Pos           (17)
#define RCC_AHBRSTR_GPIOA_Msk           (0x01U << RCC_AHBRSTR_GPIOA_Pos)        /*!< GPIOA Reset */
#define RCC_AHBRSTR_GPIOB_Pos           (18)
#define RCC_AHBRSTR_GPIOB_Msk           (0x01U << RCC_AHBRSTR_GPIOB_Pos)        /*!< GPIOB Reset */

#define RCC_AHBRSTR_DIVIDER_Pos         (26)
#define RCC_AHBRSTR_DIVIDER_Msk         (0x01U << RCC_AHBRSTR_DIVIDER_Pos)      /*!< DIVIDER Reset */

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define RCC_APB1RSTR_TIM1_Pos           (0)
#define RCC_APB1RSTR_TIM1_Msk           (0x01U << RCC_APB1RSTR_TIM1_Pos)        /*!< Timer 1 reset */
#define RCC_APB1RSTR_TIM2_Pos           (1)
#define RCC_APB1RSTR_TIM2_Msk           (0x01U << RCC_APB1RSTR_TIM2_Pos)        /*!< Timer 3 reset */

#define RCC_APB1RSTR_TIM6_Pos           (5)
#define RCC_APB1RSTR_TIM6_Msk           (0x01U << RCC_APB1RSTR_TIM6_Pos)        /*!< Timer 6 reset */

#define RCC_APB1RSTR_TIM13_Pos          (8)
#define RCC_APB1RSTR_TIM13_Msk          (0x01U << RCC_APB1RSTR_TIM13_Pos)       /*!< Timer 13 reset */
#define RCC_APB1RSTR_TIM14_Pos          (9)
#define RCC_APB1RSTR_TIM14_Msk          (0x01U << RCC_APB1RSTR_TIM14_Pos)       /*!< Timer 14 reset */

#define RCC_APB1RSTR_ADC1_Pos           (13)
#define RCC_APB1RSTR_ADC1_Msk           (0x01U << RCC_APB1RSTR_ADC1_Pos)        /*!< ADC1 reset */

#define RCC_APB1RSTR_USART1_Pos         (16)
#define RCC_APB1RSTR_USART1_Msk         (0x01U << RCC_APB1RSTR_USART1_Pos)      /*!< USART1 reset */

#define RCC_APB1RSTR_COMP_Pos           (23)
#define RCC_APB1RSTR_COMP_Msk           (0x01U << RCC_APB1RSTR_COMP_Pos)        /*!< COMP reset */

#define RCC_APB1RSTR_OPA1_Pos           (25)
#define RCC_APB1RSTR_OPA1_Msk           (0x01U << RCC_APB1RSTR_OPA1_Pos)        /*!< OPA1 reset */
#define RCC_APB1RSTR_OPA2_Pos           (26)
#define RCC_APB1RSTR_OPA2_Msk           (0x01U << RCC_APB1RSTR_OPA2_Pos)        /*!< OPA2 reset */

#define RCC_APB1RSTR_PWR_Pos            (28)
#define RCC_APB1RSTR_PWR_Msk            (0x01U << RCC_APB1RSTR_PWR_Pos)         /*!< Power Interface Reset */
#define RCC_APB1RSTR_DBG_Pos            (29)
#define RCC_APB1RSTR_DBG_Msk            (0x01U << RCC_APB1RSTR_DBG_Pos)         /*!< DBG reset */
#define RCC_APB1RSTR_SYSCFG_Pos         (30)
#define RCC_APB1RSTR_SYSCFG_Msk         (0x01U << RCC_APB1RSTR_SYSCFG_Pos)      /*!< SYSCFG reset */

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define RCC_AHBENR_DMA_Pos              (0)
#define RCC_AHBENR_DMA_Msk              (0x01U << RCC_AHBENR_DMA_Pos)           /*!< DMA1 clock enable */

#define RCC_AHBENR_SRAM_Pos             (2)
#define RCC_AHBENR_SRAM_Msk             (0x01U << RCC_AHBENR_SRAM_Pos)          /*!< SRAM interface clock enable */

#define RCC_AHBENR_FLASH_Pos            (4)
#define RCC_AHBENR_FLASH_Msk            (0x01U << RCC_AHBENR_FLASH_Pos)         /*!< FLITF clock enable */

#define RCC_AHBENR_GPIOA_Pos            (17)
#define RCC_AHBENR_GPIOA_Msk            (0x01U << RCC_AHBENR_GPIOA_Pos)         /*!< GPIOA clock enable */
#define RCC_AHBENR_GPIOB_Pos            (18)
#define RCC_AHBENR_GPIOB_Msk            (0x01U << RCC_AHBENR_GPIOB_Pos)         /*!< GPIOB clock enable */

#define RCC_AHBENR_HWDIV_Pos            (26)
#define RCC_AHBENR_HWDIV_Msk            (0x01U << RCC_AHBENR_HWDIV_Pos)         /*!< HWDIV clock enable */

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define RCC_APB1ENR_TIM1_Pos            (0)
#define RCC_APB1ENR_TIM1_Msk            (0x01U << RCC_APB1ENR_TIM1_Pos)         /*!< Timer 1 clock enable */

#define RCC_APB1ENR_TIM2_Pos            (1)
#define RCC_APB1ENR_TIM2_Msk            (0x01U << RCC_APB1ENR_TIM2_Pos)         /*!< Timer 2 clock enabled */

#define RCC_APB1ENR_TIM6_Pos            (5)
#define RCC_APB1ENR_TIM6_Msk            (0x01U << RCC_APB1ENR_TIM6_Pos)         /*!< TIM 6 clock enable */

#define RCC_APB1ENR_TIM13_Pos           (8)
#define RCC_APB1ENR_TIM13_Msk           (0x01U << RCC_APB1ENR_TIM13_Pos)        /*!< TIM 13 clock enable */
#define RCC_APB1ENR_TIM14_Pos           (9)
#define RCC_APB1ENR_TIM14_Msk           (0x01U << RCC_APB1ENR_TIM14_Pos)        /*!< TIM 14 clock enable */

#define RCC_APB1ENR_ADC1_Pos            (13)
#define RCC_APB1ENR_ADC1_Msk            (0x01U << RCC_APB1ENR_ADC1_Pos)         /*!< ADC1 clock enable */

#define RCC_APB1ENR_USART1_Pos          (16)
#define RCC_APB1ENR_USART1_Msk          (0x01U << RCC_APB1ENR_USART1_Pos)       /*!< USART1 CLOCK enable */

#define RCC_APB1ENR_COMP_Pos            (23)
#define RCC_APB1ENR_COMP_Msk            (0x01U << RCC_APB1ENR_COMP_Pos)         /*!< COMP clock enable*/

#define RCC_APB1ENR_OPA1_Pos            (25)
#define RCC_APB1ENR_OPA1_Msk            (0x01U << RCC_APB1ENR_OPA1_Pos)         /*!< OPA1 clock enable */
#define RCC_APB1ENR_OPA2_Pos            (26)
#define RCC_APB1ENR_OPA2_Msk            (0x01U << RCC_APB1ENR_OPA2_Pos)         /*!< OPA2 clock enable*/
#define RCC_APB1ENR_IWDG_Pos            (27)
#define RCC_APB1ENR_IWDG_Msk            (0x01U << RCC_APB1ENR_IWDG_Pos)         /*!< IWDG clock enable*/
#define RCC_APB1ENR_PWR_Pos             (28)
#define RCC_APB1ENR_PWR                 (0x01U << RCC_APB1ENR_PWR_Pos)          /*!< PWR clock enable*/
#define RCC_APB1ENR_DBG_Pos             (29)
#define RCC_APB1ENR_DBG_Msk             (0x01U << RCC_APB1ENR_DBG_Pos)          /*!< DBG clock enable*/
#define RCC_APB1ENR_SYSCFG_Pos          (30)
#define RCC_APB1ENR_SYSCFG_Msk          (0x01U << RCC_APB1ENR_SYSCFG_Pos)       /*!< SYSCFG clock enable*/
#define RCC_APB1ENR_EXTI_Pos            (31)
#define RCC_APB1ENR_EXTI_Msk            (0x01U << RCC_APB1ENR_EXTI_Pos)         /*!< EXTI clock enable*/

/**
  * @brief RCC_CSR Register Bit Definition
  */
#define RCC_CSR_LSION_Pos               (0)
#define RCC_CSR_LSION_Msk               (0x01U << RCC_CSR_LSION_Pos)    /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos              (1)
#define RCC_CSR_LSIRDY_Msk              (0x01U << RCC_CSR_LSIRDY_Pos)   /*!< Internal Low Speed oscillator Ready */

#define RCC_CSR_PVDRSTEN_Pos            (6)
#define RCC_CSR_PVDRSTEN_Msk            (0x01U << RCC_CSR_PVDRSTEN_Pos) /*!< PVD reset enable */
#define RCC_CSR_LOCKUPEN_Pos            (7)
#define RCC_CSR_LOCKUPEN_Msk            (0x01U << RCC_CSR_LOCKUPEN_Pos) /*!< CPU LOCK reset enable */

#define RCC_CSR_PVDRSTF_Pos             (22)
#define RCC_CSR_PVDRSTF_Msk             (0x01U << RCC_CSR_PVDRSTF_Pos)  /*!< PVD reset flag */
#define RCC_CSR_LOCKUPF_Pos             (23)
#define RCC_CSR_LOCKUPF_Msk             (0x01U << RCC_CSR_LOCKUPF_Pos)  /*!< CPU lockup reset flag */
#define RCC_CSR_RMVF_Pos                (24)
#define RCC_CSR_RMVF_Msk                (0x01U << RCC_CSR_RMVF_Pos)     /*!< Remove reset flag */

#define RCC_CSR_PINRSTF_Pos             (26)
#define RCC_CSR_PINRSTF_Msk             (0x01U << RCC_CSR_PINRSTF_Pos)  /*!< PIN reset flag */

#define RCC_CSR_PORRSTF_Pos             (27)
#define RCC_CSR_PORRSTF_Msk             (0x01U << RCC_CSR_PORRSTF_Pos)  /*!< POR/PDR reset flag */

#define RCC_CSR_SFTRSTF_Pos             (28)
#define RCC_CSR_SFTRSTF_Msk             (0x01U << RCC_CSR_SFTRSTF_Pos)  /*!< Software Reset flag */

#define RCC_CSR_IWDGRSTF_Pos            (29)
#define RCC_CSR_IWDGRSTF_Msk            (0x01U << RCC_CSR_IWDGRSTF_Pos) /*!< Independent Watchdog reset flag */

#define RCC_CSR_LPWRRSTF_Pos            (31)
#define RCC_CSR_LPWRRSTF_Msk            (0x01U << RCC_CSR_LPWRRSTF_Pos) /*!< Low power reset flag */


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

