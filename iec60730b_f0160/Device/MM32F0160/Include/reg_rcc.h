/*
 *******************************************************************************
    @file     reg_rcc.h
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

#ifndef __REG_RCC_H
#define __REG_RCC_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>
#if 0
/* IP_RCC_DesignSpec_v1.0 */
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
  * @brief RCC Base Address Definition
  */
#define RCC_BASE                        (AHBPERIPH_BASE + 0x1000)               /*!< Base Address: 0x40021000 */

/**
  * @brief RCC Register Structure Definition
  */
typedef struct {
    __IO uint32_t CR;                                                           /*!< Control Register                               offset: 0x00 */
    __IO uint32_t CFGR;                                                         /*!< Configuration Register                         offset: 0x04 */
    __IO uint32_t CIR;                                                          /*!< Clock Interrupt Register                       offset: 0x08 */
    __IO uint32_t APB2RSTR;                                                     /*!< Advanced Peripheral Bus 2 Reset Register       offset: 0x0C */
    __IO uint32_t APB1RSTR;                                                     /*!< Advanced Peripheral Bus 1 Reset Register       offset: 0x10 */
    __IO uint32_t AHBENR;                                                       /*!< Advanced High Performance Bus Enable Register  offset: 0x14 */
    __IO uint32_t APB2ENR;                                                      /*!< Advanced Peripheral Bus 2 Enable Register      offset: 0x18 */
    __IO uint32_t APB1ENR;                                                      /*!< Advanced Peripheral Bus 1 Enable Register      offset: 0x1C */
    __IO uint32_t BDCR;                                                         /*!< Backup domain control register                 offset: 0x20 */
    __IO uint32_t CSR;                                                          /*!< Control Status Register                        offset: 0x24 */
    __IO uint32_t AHBRSTR;                                                      /*!< Advanced High Performance Bus Reset Register   offset: 0x28 */
    __IO uint32_t CFGR2;                                                        /*!< Configuration Register 2                       offset: 0x2C */
    __IO uint32_t RESERVED0x30[4];                                              /*!< Reserved                                       offset: 0x30 */
    __IO uint32_t SYSCFGR;                                                      /*!< System Configuration Register                  offset: 0x40 */
    __IO uint32_t HSIDLY;                                                       /*!< HSI delay Register                             offset: 0x44 */
    __IO uint32_t HSEDLY;                                                       /*!< HSE delay Register                             offset: 0x48 */
    __IO uint32_t ICSCR;                                                        /*!< Internal clock source calibration register     offset: 0x4C */
    __IO uint32_t PLL1CFGR;                                                     /*!< PLL1 Configuration Register                    offset: 0x50 */
    __IO uint32_t PLL2CFGR;                                                     /*!< PLL2 Configuration Register                    offset: 0x54 */
    __IO uint32_t RESERVED0x58[10];                                             /*!< Reserved                                       offset: 0x58 */
    __IO uint32_t RCC_LDOCR;                                                    /*!< LDO Control Register                           offset: 0x80 */
    __IO uint32_t RESERVED0x84;                                                 /*!< Reserved                                       offset: 0x84 */
    __IO uint32_t PLL1DLY;                                                      /*!< PLL1 delay Register                            offset: 0x88 */
    __IO uint32_t PLL2DLY;                                                      /*!< PLL2 delay Register                            offset: 0x8C */
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                             ((RCC_TypeDef*) RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define RCC_CR_HSION_Pos                (0)
#define RCC_CR_HSION                    (0x01U << RCC_CR_HSION_Pos)             /*!< Internal High Speed clock enable */

#define RCC_CR_HSIRDY_Pos               (1)
#define RCC_CR_HSIRDY                   (0x01U << RCC_CR_HSIRDY_Pos)            /*!< Internal High Speed clock ready flag */

#define RCC_CR_HSELPFBYP_Pos            (4)
#define RCC_CR_HSELPFBYP                (0x01U << RCC_CR_HSELPFBYP_Pos)         /*!< LPF_IN direct output */
#define RCC_CR_HSELPFSEL_Pos            (5)
#define RCC_CR_HSELPFSEL                (0x01U << RCC_CR_HSELPFSEL_Pos)         /*!< Output after LPF filtering */
#define RCC_CR_HSEDEGLITCHBYP_Pos       (6)
#define RCC_CR_HSEDEGLITCHBYP           (0x01U << RCC_CR_HSE_DEGLITCHBYP_Pos)   /*!< Bypass deburring function */
#define RCC_CR_HSEDEGLITCHSEL_Pos       (7)
#define RCC_CR_HSEDEGLITCHSEL           (0x01U << RCC_CR_HSE_DEGLITCHSEL_Pos)   /*!< Deburring width 5nS */
#define RCC_CR_HSEOUTPUTSEL_Pos         (8)
#define RCC_CR_HSEOUTPUTSEL             (0x01U << RCC_CR_HSE_OUTPUTSEL_Pos)     /*!< Filtered output */
#define RCC_CR_HSIDIV_Pos               (11)
#define RCC_CR_HSIDIV_1                 (0x00U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 1   factor */
#define RCC_CR_HSIDIV_2                 (0x01U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 2   factor */
#define RCC_CR_HSIDIV_4                 (0x02U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 4   factor */
#define RCC_CR_HSIDIV_8                 (0x03U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 8   factor */
#define RCC_CR_HSIDIV_16                (0x04U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 16  factor */
#define RCC_CR_HSIDIV_32                (0x05U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 32  factor */
#define RCC_CR_HSIDIV_64                (0x06U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 64  factor */
#define RCC_CR_HSIDIV_128               (0x07U << RCC_CR_HSIDIV_Pos)            /*!< HSI clock division 128 factor */

#define RCC_CR_HSEON_Pos                (16)
#define RCC_CR_HSEON                    (0x01U << RCC_CR_HSEON_Pos)             /*!< External High Speed clock enable */
#define RCC_CR_HSERDY_Pos               (17)
#define RCC_CR_HSERDY                   (0x01U << RCC_CR_HSERDY_Pos)            /*!< External High Speed clock ready flag */
#define RCC_CR_HSEBYP_Pos               (18)
#define RCC_CR_HSEBYP                   (0x01U << RCC_CR_HSEBYP_Pos)            /*!< External High Speed clock Bypass */
#define RCC_CR_CSSON_Pos                (19)
#define RCC_CR_CSSON                    (0x01U << RCC_CR_CSSON_Pos)             /*!< Clock Security System enable */

#define RCC_CR_PLL1ON_Pos               (24)
#define RCC_CR_PLL1ON                   (0x01U << RCC_CR_PLL1ON_Pos)            /*!< PLL1 enable */
#define RCC_CR_PLL1RDY_Pos              (25)
#define RCC_CR_PLL1RDY                  (0x01U << RCC_CR_PLL1RDY_Pos)           /*!< PLL1 clock ready flag */

#define RCC_CR_PLL2ON_Pos               (28)
#define RCC_CR_PLL2ON                   (0x01U << RCC_CR_PLL2ON_Pos)            /*!< PLL2 enable */
#define RCC_CR_PLL2RDY_Pos              (29)
#define RCC_CR_PLL2RDY                  (0x01U << RCC_CR_PLL2RDY_Pos)           /*!< PLL2 clock ready flag */

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define RCC_CFGR_SW_Pos                 (0)
#define RCC_CFGR_SW                     (0x03U << RCC_CFGR_SW_Pos)              /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_HSI                 (0x00U << RCC_CFGR_SW_Pos)              /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                 (0x01U << RCC_CFGR_SW_Pos)              /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL1                (0x02U << RCC_CFGR_SW_Pos)              /*!< PLL1 selected as system clock */
#define RCC_CFGR_SW_LSI                 (0x03U << RCC_CFGR_SW_Pos)              /*!< LSI selected as system clock */

#define RCC_CFGR_SWS_Pos                (2)
#define RCC_CFGR_SWS                    (0x03U << RCC_CFGR_SWS_Pos)             /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_HSI                (0x00U << RCC_CFGR_SWS_Pos)             /*!< HSI/6 oscillator used as system clock */
#define RCC_CFGR_SWS_HSE                (0x01U << RCC_CFGR_SWS_Pos)             /*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL1               (0x02U << RCC_CFGR_SWS_Pos)             /*!< PLL1 used as system clock */
#define RCC_CFGR_SWS_LSI                (0x03U << RCC_CFGR_SWS_Pos)             /*!< LSI used as system clock */

#define RCC_CFGR_HPRE_Pos               (4)
#define RCC_CFGR_HPRE                   (0x0FU << RCC_CFGR_HPRE_Pos)            /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                 (0x01U << RCC_CFGR_HPRE_Pos)            /*!< Bit 0 */
#define RCC_CFGR_HPRE_1                 (0x02U << RCC_CFGR_HPRE_Pos)            /*!< Bit 1 */
#define RCC_CFGR_HPRE_2                 (0x04U << RCC_CFGR_HPRE_Pos)            /*!< Bit 2 */
#define RCC_CFGR_HPRE_3                 (0x08U << RCC_CFGR_HPRE_Pos)            /*!< Bit 3 */

#define RCC_CFGR_HPRE_DIV1              (0x00U << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2              (0x08U << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4              (0x09U << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8              (0x0AU << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16             (0x0BU << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64             (0x0CU << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128            (0x0DU << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256            (0x0EU << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512            (0x0FU << RCC_CFGR_HPRE_Pos)            /*!< AHB = FCLK = SYSCLK divided by 512 */

#define RCC_CFGR_PPRE1_Pos              (8)
#define RCC_CFGR_PPRE1                  (0x07U << RCC_CFGR_PPRE1_Pos)           /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                (0x01U << RCC_CFGR_PPRE1_Pos)           /*!< Bit 0 */
#define RCC_CFGR_PPRE1_1                (0x02U << RCC_CFGR_PPRE1_Pos)           /*!< Bit 1 */
#define RCC_CFGR_PPRE1_2                (0x04U << RCC_CFGR_PPRE1_Pos)           /*!< Bit 2 */

#define RCC_CFGR_PPRE1_DIV1             (0x00U << RCC_CFGR_PPRE1_Pos)           /*!< APB1 = HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2             (0x04U << RCC_CFGR_PPRE1_Pos)           /*!< APB1 = HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4             (0x05U << RCC_CFGR_PPRE1_Pos)           /*!< APB1 = HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8             (0x06U << RCC_CFGR_PPRE1_Pos)           /*!< APB1 = HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16            (0x07U << RCC_CFGR_PPRE1_Pos)           /*!< APB1 = HCLK divided by 16 */

#define RCC_CFGR_PPRE2_Pos              (11)
#define RCC_CFGR_PPRE2                  (0x07U << RCC_CFGR_PPRE2_Pos)           /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                (0x01U << RCC_CFGR_PPRE2_Pos)           /*!< Bit 0 */
#define RCC_CFGR_PPRE2_1                (0x02U << RCC_CFGR_PPRE2_Pos)           /*!< Bit 1 */
#define RCC_CFGR_PPRE2_2                (0x04U << RCC_CFGR_PPRE2_Pos)           /*!< Bit 2 */

#define RCC_CFGR_PPRE2_DIV1             (0x00U << RCC_CFGR_PPRE2_Pos)           /*!< APB2 = HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2             (0x04U << RCC_CFGR_PPRE2_Pos)           /*!< APB2 = HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4             (0x05U << RCC_CFGR_PPRE2_Pos)           /*!< APB2 = HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8             (0x06U << RCC_CFGR_PPRE2_Pos)           /*!< APB2 = HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16            (0x07U << RCC_CFGR_PPRE2_Pos)           /*!< APB2 = HCLK divided by 16 */

#define RCC_CFGR_USBCLKSEL_Pos          (19)
#define RCC_CFGR_USBCLKSEL              (0x01U << RCC_CFGR_USBCLKSEL_Pos)       /*!< Select USBCLK clock source */

#define RCC_CFGR_USBPRE_Pos             (22)
#define RCC_CFGR_USBPRE                 (0x03U << RCC_CFGR_USBPRE_Pos)          /*!< USB prescaler */
#define RCC_CFGR_USBPRE_DIV1            (0x00U << RCC_CFGR_USBPRE_Pos)          /*!< PLL1/2 clock is directly used as USB clock */
#define RCC_CFGR_USBPRE_DIV2            (0x01U << RCC_CFGR_USBPRE_Pos)          /*!< PLL1/2 clock 2 division as USB clock */
#define RCC_CFGR_USBPRE_DIV3            (0x02U << RCC_CFGR_USBPRE_Pos)          /*!< PLL1/2 clock 3 division as USB clock */
#define RCC_CFGR_USBPRE_DIV4            (0x03U << RCC_CFGR_USBPRE_Pos)          /*!< PLL1/2 clock 4 division as USB clock */

#define RCC_CFGR_MCO_Pos                (24)
#define RCC_CFGR_MCO                    (0x07U << RCC_CFGR_MCO_Pos)             /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define RCC_CFGR_MCO_NOCLOCK            (0x00U << RCC_CFGR_MCO_Pos)             /*!< No clock */
#define RCC_CFGR_MCO_LSI                (0x02U << RCC_CFGR_MCO_Pos)             /*!< LSI clock */
#define RCC_CFGR_MCO_LSE                (0x03U << RCC_CFGR_MCO_Pos)             /*!< LSE clock */
#define RCC_CFGR_MCO_SYSCLK             (0x04U << RCC_CFGR_MCO_Pos)             /*!< System clock selected */
#define RCC_CFGR_MCO_HSI                (0x05U << RCC_CFGR_MCO_Pos)             /*!< Internal 48 MHz RC oscillator clock selected */
#define RCC_CFGR_MCO_HSE                (0x06U << RCC_CFGR_MCO_Pos)             /*!< External 1-25 MHz oscillator clock selected */
#define RCC_CFGR_MCO_PLL1               (0x07U << RCC_CFGR_MCO_Pos)             /*!< PLL1 clock divided by 2 selected */
#define RCC_CFGR_MCO_PLL1DIV2           (0x07U << RCC_CFGR_MCO_Pos)             /*!< PLL1 clock divided by 2 selected */

/**
  * @brief RCC_CIR Register Bit Definition
  */
#define RCC_CIR_LSIRDYF_Pos             (0)
#define RCC_CIR_LSIRDYF                 (0x01U << RCC_CIR_LSIRDYF_Pos)          /*!< LSI Ready Interrupt flag */

#define RCC_CIR_LSERDYF_Pos             (1)
#define RCC_CIR_LSERDYF                 (0x01U << RCC_CIR_LSERDYF_Pos)          /*!< LSE Ready Interrupt flag */

#define RCC_CIR_HSIRDYF_Pos             (2)
#define RCC_CIR_HSIRDYF                 (0x01U << RCC_CIR_HSIRDYF_Pos)          /*!< HSI Ready Interrupt flag */
#define RCC_CIR_HSERDYF_Pos             (3)
#define RCC_CIR_HSERDYF                 (0x01U << RCC_CIR_HSERDYF_Pos)          /*!< HSE Ready Interrupt flag */

#define RCC_CIR_PLL1RDYF_Pos            (4)
#define RCC_CIR_PLL1RDYF                (0x01U << RCC_CIR_PLL1RDYF_Pos)         /*!< PLL1 Ready Interrupt flag */

#define RCC_CIR_PLL2RDYF_Pos            (5)
#define RCC_CIR_PLL2RDYF                (0x01U << RCC_CIR_PLL2RDYF_Pos)         /*!< PLL2 Ready Interrupt flag */

#define RCC_CIR_CSSF_Pos                (7)
#define RCC_CIR_CSSF                    (0x01U << RCC_CIR_CSSF_Pos)             /*!< Clock Security System Interrupt flag */
#define RCC_CIR_LSIRDYIE_Pos            (8)
#define RCC_CIR_LSIRDYIE                (0x01U << RCC_CIR_LSIRDYIE_Pos)         /*!< LSI Ready Interrupt Enable */

#define RCC_CIR_LSERDYIE_Pos            (9)
#define RCC_CIR_LSERDYIE                (0x01U << RCC_CIR_LSERDYIE_Pos)         /*!< LSE Ready Interrupt Enable */

#define RCC_CIR_HSIRDYIE_Pos            (10)
#define RCC_CIR_HSIRDYIE                (0x01U << RCC_CIR_HSIRDYIE_Pos)         /*!< HSI Ready Interrupt Enable */
#define RCC_CIR_HSERDYIE_Pos            (11)
#define RCC_CIR_HSERDYIE                (0x01U << RCC_CIR_HSERDYIE_Pos)         /*!< HSE Ready Interrupt Enable */

#define RCC_CIR_PLL1RDYIE_Pos           (12)
#define RCC_CIR_PLL1RDYIE               (0x01U << RCC_CIR_PLL1RDYIE_Pos)        /*!< PLL1 Ready Interrupt Enable */

#define RCC_CIR_LSIRDYC_Pos             (16)
#define RCC_CIR_LSIRDYC                 (0x01U << RCC_CIR_LSIRDYC_Pos)          /*!< LSI Ready Interrupt Clear */

#define RCC_CIR_LSERDYC_Pos             (17)
#define RCC_CIR_LSERDYC                 (0x01U << RCC_CIR_LSERDYC_Pos)          /*!< LSE Ready Interrupt Clear */

#define RCC_CIR_HSIRDYC_Pos             (18)
#define RCC_CIR_HSIRDYC                 (0x01U << RCC_CIR_HSIRDYC_Pos)          /*!< HSI Ready Interrupt Clear */
#define RCC_CIR_HSERDYC_Pos             (19)
#define RCC_CIR_HSERDYC                 (0x01U << RCC_CIR_HSERDYC_Pos)          /*!< HSE Ready Interrupt Clear */

#define RCC_CIR_PLL1RDYC_Pos            (20)
#define RCC_CIR_PLL1RDYC                (0x01U << RCC_CIR_PLL1RDYC_Pos)         /*!< PLL1 Ready Interrupt Clear */

#define RCC_CIR_PLL2RDYC_Pos            (21)
#define RCC_CIR_PLL2RDYC                (0x01U << RCC_CIR_PLL2RDYC_Pos)         /*!< PLL2 Ready Interrupt Clear */

#define RCC_CIR_CSSC_Pos                (23)
#define RCC_CIR_CSSC                    (0x01U << RCC_CIR_CSSC_Pos)             /*!< Clock Security System Interrupt Clear */

/**
  * @brief RCC_APB2RSTR Register Bit Definition
  */
#define RCC_APB2RSTR_SYSCFG_Pos         (0)
#define RCC_APB2RSTR_SYSCFG             (0x01U << RCC_APB2RSTR_SYSCFG_Pos)      /*!< System Configuration register reset */

#define RCC_APB2RSTR_ADC_Pos            (9)
#define RCC_APB2RSTR_ADC                (0x01U << RCC_APB2RSTR_ADC_Pos)         /*!< ADC interface reset */

#define RCC_APB2RSTR_TIM1_Pos           (11)
#define RCC_APB2RSTR_TIM1               (0x01U << RCC_APB2RSTR_TIM1_Pos)        /*!< TIM1 Timer reset */

#define RCC_APB2RSTR_SPI1_Pos           (12)
#define RCC_APB2RSTR_SPI1               (0x01U << RCC_APB2RSTR_SPI1_Pos)        /*!< SPI 1 reset */

#define RCC_APB2RSTR_UART1_Pos          (14)
#define RCC_APB2RSTR_UART1              (0x01U << RCC_APB2RSTR_UART1_Pos)       /*!< UART1 reset */

#define RCC_APB2RSTR_CPT_Pos            (15)
#define RCC_APB2RSTR_CPT                (0x01U << RCC_APB2RSTR_CPT_Pos)         /*!< COMP interface reset */

#define RCC_APB2RSTR_TIM14_Pos          (16)
#define RCC_APB2RSTR_TIM14              (0x01U << RCC_APB2RSTR_TIM14_Pos)       /*!< TIM14 Timer reset */

#define RCC_APB2RSTR_TIM16_Pos          (17)
#define RCC_APB2RSTR_TIM16              (0x01U << RCC_APB2RSTR_TIM16_Pos)       /*!< TIM16 Timer reset */

#define RCC_APB2RSTR_TIM17_Pos          (18)
#define RCC_APB2RSTR_TIM17              (0x01U << RCC_APB2RSTR_TIM17_Pos)       /*!< TIM17 Timer reset */

#define RCC_APB2RSTR_DBG_Pos            (22)
#define RCC_APB2RSTR_DBG                (0x01U << RCC_APB2RSTR_DBG_Pos)         /*!< DBG reset */

#define RCC_APB2RSTR_LPTIM_Pos          (30)
#define RCC_APB2RSTR_LPTIM              (0x01U << RCC_APB2RSTR_LPTIM_Pos)       /*!< LPTIM reset */

#define RCC_APB2RSTR_LPUART_Pos         (31)
#define RCC_APB2RSTR_LPUART             (0x01U << RCC_APB2RSTR_LPUART_Pos)      /*!< LPUART reset */

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define RCC_APB1RSTR_TIM2_Pos           (0)
#define RCC_APB1RSTR_TIM2               (0x01U << RCC_APB1RSTR_TIM2_Pos)        /*!< Timer 2 reset */

#define RCC_APB1RSTR_TIM3_Pos           (1)
#define RCC_APB1RSTR_TIM3               (0x01U << RCC_APB1RSTR_TIM3_Pos)        /*!< Timer 3 reset */

#define RCC_APB1RSTR_I3C_Pos            (6)
#define RCC_APB1RSTR_I3C                (0x01U << RCC_APB1RSTR_I3C_Pos)         /*!< I3C reset */

#define RCC_APB1RSTR_WWDG_Pos           (11)
#define RCC_APB1RSTR_WWDG               (0x01U << RCC_APB1RSTR_WWDG_Pos)        /*!< Window Watchdog reset */

#define RCC_APB1RSTR_SPI2_Pos           (14)
#define RCC_APB1RSTR_SPI2               (0x01U << RCC_APB1RSTR_SPI2_Pos)        /*!< SPI 2 reset */

#define RCC_APB1RSTR_UART2_Pos          (17)
#define RCC_APB1RSTR_UART2              (0x01U << RCC_APB1RSTR_UART2_Pos)       /*!< UART 2 reset */
#define RCC_APB1RSTR_UART3_Pos          (18)
#define RCC_APB1RSTR_UART3              (0x01U << RCC_APB1RSTR_UART3_Pos)       /*!< UART 3 reset */
#define RCC_APB1RSTR_UART4_Pos          (19)
#define RCC_APB1RSTR_UART4              (0x01U << RCC_APB1RSTR_UART4_Pos)       /*!< UART 4 reset */
#define RCC_APB1RSTR_I2C1_Pos           (21)
#define RCC_APB1RSTR_I2C1               (0x01U << RCC_APB1RSTR_I2C1_Pos)        /*!< I2C 1 reset */

#define RCC_APB1RSTR_BKP_Pos            (24)
#define RCC_APB1RSTR_BKP                (0x01U << RCC_APB1RSTR_BKP_Pos)         /*!< BKP reset */

#define RCC_APB1RSTR_FLEXCAN_Pos        (25)
#define RCC_APB1RSTR_FLEXCAN            (0x01U << RCC_APB1RSTR_FLEXCAN_Pos)     /*!< FLEXCAN reset */

#define RCC_APB1RSTR_CRS_Pos            (27)
#define RCC_APB1RSTR_CRS                (0x01U << RCC_APB1RSTR_CRS_Pos)         /*!< CRS reset */

#define RCC_APB1RSTR_PWR_Pos            (28)
#define RCC_APB1RSTR_PWR                (0x01U << RCC_APB1RSTR_PWR_Pos)         /*!< Power interface reset */

#define RCC_APB1RSTR_RTC_Pos            (31)
#define RCC_APB1RSTR_RTC                (0x01U << RCC_APB1RSTR_RTC_Pos)         /*!< RTC reset */

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define RCC_AHBENR_DMA_Pos              (0)
#define RCC_AHBENR_DMA                  (0x01U << RCC_AHBENR_DMA_Pos)           /*!< DMA clock enable */
#define RCC_AHBENR_SRAM_Pos             (2)
#define RCC_AHBENR_SRAM                 (0x01U << RCC_AHBENR_SRAM_Pos)          /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLASH_Pos            (4)
#define RCC_AHBENR_FLASH                (0x01U << RCC_AHBENR_FLASH_Pos)         /*!< FLASH clock enable */
#define RCC_AHBENR_CRC_Pos              (6)
#define RCC_AHBENR_CRC                  (0x01U << RCC_AHBENR_CRC_Pos)           /*!< Internal High Speed clock Calibration */

#define RCC_AHBENR_GPIOA_Pos            (17)
#define RCC_AHBENR_GPIOA                (0x01U << RCC_AHBENR_GPIOA_Pos)         /*!< GPIOA clock enable */
#define RCC_AHBENR_GPIOB_Pos            (18)
#define RCC_AHBENR_GPIOB                (0x01U << RCC_AHBENR_GPIOB_Pos)         /*!< GPIOB clock enable */
#define RCC_AHBENR_GPIOC_Pos            (19)
#define RCC_AHBENR_GPIOC                (0x01U << RCC_AHBENR_GPIOC_Pos)         /*!< GPIOC clock enable */
#define RCC_AHBENR_GPIOD_Pos            (20)
#define RCC_AHBENR_GPIOD                (0x01U << RCC_AHBENR_GPIOD_Pos)         /*!< GPIOD clock enable */

#define RCC_AHBENR_USB_Pos              (24)
#define RCC_AHBENR_USB                  (0x01U << RCC_AHBENR_USB_Pos)           /*!< USB clock enable */

#define RCC_AHBENR_HWDIV_Pos            (26)
#define RCC_AHBENR_HWDIV                (0x01U << RCC_AHBENR_HWDIV_Pos)         /*!< HWDIV clock enable */

/**
  * @brief RCC_APB2ENR Register Bit Definition
  */
#define RCC_APB2ENR_SYSCFG_Pos          (0)
#define RCC_APB2ENR_SYSCFG              (0x01U << RCC_APB2ENR_SYSCFG_Pos)       /*!< SYSCFG Block enable */
#define RCC_APB2ENR_ADC_Pos             (9)
#define RCC_APB2ENR_ADC                 (0x01U << RCC_APB2ENR_ADC_Pos)          /*!< ADC interface clock enable */

#define RCC_APB2ENR_TIM1_Pos            (11)
#define RCC_APB2ENR_TIM1                (0x01U << RCC_APB2ENR_TIM1_Pos)         /*!< TIM1 Timer clock enable */
#define RCC_APB2ENR_SPI1_Pos            (12)
#define RCC_APB2ENR_SPI1                (0x01U << RCC_APB2ENR_SPI1_Pos)         /*!< SPI 1 clock enable */
#define RCC_APB2ENR_UART1_Pos           (14)
#define RCC_APB2ENR_UART1               (0x01U << RCC_APB2ENR_UART1_Pos)        /*!< UART1 clock ena */
#define RCC_APB2ENR_COMP_Pos            (15)
#define RCC_APB2ENR_COMP                (0x01U << RCC_APB2ENR_COMP_Pos)         /*!< Comparator interface clock enable */

#define RCC_APB2ENR_TIM14_Pos           (16)
#define RCC_APB2ENR_TIM14               (0x01U << RCC_APB2ENR_TIM14_Pos)        /*!< TIM14 Timer clock enable */

#define RCC_APB2ENR_TIM16_Pos           (17)
#define RCC_APB2ENR_TIM16               (0x01U << RCC_APB2ENR_TIM16_Pos)        /*!< TIM16 Timer clock enable */
#define RCC_APB2ENR_TIM17_Pos           (18)
#define RCC_APB2ENR_TIM17               (0x01U << RCC_APB2ENR_TIM17_Pos)        /*!< TIM17 Timer clock enable */
#define RCC_APB2ENR_DBG_Pos             (22)
#define RCC_APB2ENR_DBG                 (0x01U << RCC_APB2ENR_DBG_Pos)          /*!< DBG clock enable */
#define RCC_APB2ENR_EXTI_Pos            (29)
#define RCC_APB2ENR_EXTI                (0x01U << RCC_APB2ENR_EXTI_Pos)         /*!< EXTI Block enable */
#define RCC_APB2ENR_LPTIM_Pos           (30)
#define RCC_APB2ENR_LPTIM               (0x01U << RCC_APB2ENR_LPTIM_Pos)        /*!< LPTIM Block enable */
#define RCC_APB2ENR_LPUART_Pos          (31)
#define RCC_APB2ENR_LPUART              (0x01U << RCC_APB2ENR_LPUART_Pos)       /*!< LPUART Block enable */

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define RCC_APB1ENR_TIM2_Pos            (0)
#define RCC_APB1ENR_TIM2                (0x01U << RCC_APB1ENR_TIM2_Pos)         /*!< Timer 2 clock enable */

#define RCC_APB1ENR_TIM3_Pos            (1)
#define RCC_APB1ENR_TIM3                (0x01U << RCC_APB1ENR_TIM3_Pos)         /*!< Timer 3 clock enabled */

#define RCC_APB1ENR_I3C_Pos             (6)
#define RCC_APB1ENR_I3C                 (0x01U << RCC_APB1ENR_I3C_Pos)          /*!< I3C clock enabled */

#define RCC_APB1ENR_WWDG_Pos            (11)
#define RCC_APB1ENR_WWDG                (0x01U << RCC_APB1ENR_WWDG_Pos)         /*!< Window Watchdog clock enable */

#define RCC_APB1ENR_SPI2_Pos            (14)
#define RCC_APB1ENR_SPI2                (0x01U << RCC_APB1ENR_SPI2_Pos)         /*!< SPI 2 clock enable */

#define RCC_APB1ENR_UART2_Pos           (17)
#define RCC_APB1ENR_UART2               (0x01U << RCC_APB1ENR_UART2_Pos)        /*!< UART 2 clock enable */

#define RCC_APB1ENR_UART3_Pos           (18)
#define RCC_APB1ENR_UART3               (0x01U << RCC_APB1ENR_UART3_Pos)        /*!< UART 3 clock enable */

#define RCC_APB1ENR_UART4_Pos           (19)
#define RCC_APB1ENR_UART4               (0x01U << RCC_APB1ENR_UART4_Pos)        /*!< UART 4 clock enable */

#define RCC_APB1ENR_I2C1_Pos            (21)
#define RCC_APB1ENR_I2C1                (0x01U << RCC_APB1ENR_I2C1_Pos)         /*!< I2C 1 clock enable */

#define RCC_APB1ENR_BKP_Pos             (24)
#define RCC_APB1ENR_BKP                 (0x01U << RCC_APB1ENR_BKP_Pos)          /*!< BKP interface clock enable */

#define RCC_APB1ENR_FLEXCAN_Pos         (25)
#define RCC_APB1ENR_FLEXCAN             (0x01U << RCC_APB1ENR_FLEXCAN_Pos)      /*!< FLEXCAN clock enable */

#define RCC_APB1ENR_CRS_Pos             (27)
#define RCC_APB1ENR_CRS                 (0x01U << RCC_APB1ENR_CRS_Pos)          /*!< CRS clock enable */

#define RCC_APB1ENR_PWR_Pos             (28)
#define RCC_APB1ENR_PWR                 (0x01U << RCC_APB1ENR_PWR_Pos)          /*!< Power clock enable */
#define RCC_APB1ENR_IWDG_Pos            (30)
#define RCC_APB1ENR_IWDG                (0x01U << RCC_APB1ENR_IWDG_Pos)         /*!< IWDG clock enable */
#define RCC_APB1ENR_RTC_Pos             (31)
#define RCC_APB1ENR_RTC                 (0x01U << RCC_APB1ENR_RTC_Pos)          /*!< RTC clock enable */

/**
  * @brief RCC_BDCR Register Bit Definition
  */
#define RCC_BDCR_LSEON_Pos              (0)
#define RCC_BDCR_LSEON_Msk              (0x01U << RCC_BDCR_LSEON_Pos)           /*!< External low-speed oscillator enable */
#define RCC_BDCR_LSERDY_Pos             (1)
#define RCC_BDCR_LSERDY                 (0x01U << RCC_BDCR_LSERDY_Pos)          /*!< External low-speed oscillator ready */
#define RCC_BDCR_LSEBYP_Pos             (2)
#define RCC_BDCR_LSEBYP_Msk             (0x01U << RCC_BDCR_LSEBYP_Pos)          /*!< External low-speed oscillator bypass */
#define RCC_BDCR_RTCSEL_Pos             (8)
#define RCC_BDCR_RTCSEL                 (0x03U << RCC_BDCR_RTCSEL_Pos)          /*!< RTC clock source selection */
#define RCC_BDCR_RTCSEL_NONE            (0x00U << RCC_BDCR_RTCSEL_Pos)          /*!< No clock */
#define RCC_BDCR_RTCSEL_LSE             (0x01U << RCC_BDCR_RTCSEL_Pos)          /*!< LSE oscillator used as RTC clock */
#define RCC_BDCR_RTCSEL_LSI             (0x02U << RCC_BDCR_RTCSEL_Pos)          /*!< LSI oscillator used as RTC clock */
#define RCC_BDCR_RTCSEL_HSE             (0x03U << RCC_BDCR_RTCSEL_Pos)          /*!< HSE oscillator is used as RTC clock after 128 frequency division */
#define RCC_BDCR_RTCEN_Pos              (15)
#define RCC_BDCR_RTCEN                  (0x01U << RCC_BDCR_RTCEN_Pos)           /*!< RTC clock enable */
#define RCC_BDCR_BDRST_Pos              (16)
#define RCC_BDCR_BDRST                  (0x01U << RCC_BDCR_BDRST_Pos)           /*!< Backup domain software reset */
#define RCC_BDCR_DBP_Pos                (24)
#define RCC_BDCR_DBP                    (0x01U << RCC_BDCR_DBP_Pos)             /*!< Allow access to RTC and backing registers */

/**
  * @brief RCC_CSR Register Bit Definition
  */
#define RCC_CSR_LSION_Pos               (0)
#define RCC_CSR_LSION                   (0x01U << RCC_CSR_LSION_Pos)            /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos              (1)
#define RCC_CSR_LSIRDY                  (0x01U << RCC_CSR_LSIRDY_Pos)           /*!< Internal Low Speed oscillator ready */
#define RCC_CSR_LSIOE_Pos               (5)
#define RCC_CSR_LSIOE                   (0x01U << RCC_CSR_LSIOE_Pos)            /*!< LSI Output Enable */
#define RCC_CSR_PVDRSTEN_Pos            (6)
#define RCC_CSR_PVDRSTEN                (0x01U << RCC_CSR_PVDRSTEN_Pos)         /*!< PVD reset enable */
#define RCC_CSR_LOCKUPEN_Pos            (7)
#define RCC_CSR_LOCKUPEN                (0x01U << RCC_CSR_LOCKUPEN_Pos)         /*!< CPU Lockup reset enable */

#define RCC_CSR_PVDRSTF_Pos             (22)
#define RCC_CSR_PVDRSTF                 (0x01U << RCC_CSR_PVDRSTF_Pos)          /*!< PVD reset flag */
#define RCC_CSR_LOCKUPF_Pos             (23)
#define RCC_CSR_LOCKUPF                 (0x01U << RCC_CSR_LOCKUPF_Pos)          /*!< CPU lockup reset flag */

#define RCC_CSR_RMVF_Pos                (24)
#define RCC_CSR_RMVF                    (0x01U << RCC_CSR_RMVF_Pos)             /*!< Remove reset flag */
#define RCC_CSR_PINRSTF_Pos             (26)
#define RCC_CSR_PINRSTF                 (0x01U << RCC_CSR_PINRSTF_Pos)          /*!< PIN reset flag */

#define RCC_CSR_PORRSTF_Pos             (27)
#define RCC_CSR_PORRSTF                 (0x01U << RCC_CSR_PORRSTF_Pos)          /*!< POR/PDR reset flag */

#define RCC_CSR_SFTRSTF_Pos             (28)
#define RCC_CSR_SFTRSTF                 (0x01U << RCC_CSR_SFTRSTF_Pos)          /*!< Software Reset flag */

#define RCC_CSR_IWDGRSTF_Pos            (29)
#define RCC_CSR_IWDGRSTF                (0x01U << RCC_CSR_IWDGRSTF_Pos)         /*!< Independent Watchdog reset flag */

#define RCC_CSR_WWDGRSTF_Pos            (30)
#define RCC_CSR_WWDGRSTF                (0x01U << RCC_CSR_WWDGRSTF_Pos)         /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos            (31)
#define RCC_CSR_LPWRRSTF                (0x01U << RCC_CSR_LPWRRSTF_Pos)         /*!< Low power reset flag */

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define RCC_AHBRSTR_DMA_Pos             (0)
#define RCC_AHBRSTR_DMA                 (0x01U << RCC_AHBRSTR_DMA_Pos)          /*!< DMA clock reset */
#define RCC_AHBRSTR_CRC_Pos             (6)
#define RCC_AHBRSTR_CRC                 (0x01U << RCC_AHBRSTR_CRC_Pos)          /*!< CRC clock reset */
#define RCC_AHBRSTR_GPIOA_Pos           (17)
#define RCC_AHBRSTR_GPIOA               (0x01U << RCC_AHBRSTR_GPIOA_Pos)        /*!< GPIOA clock reset */
#define RCC_AHBRSTR_GPIOB_Pos           (18)
#define RCC_AHBRSTR_GPIOB               (0x01U << RCC_AHBRSTR_GPIOB_Pos)        /*!< GPIOB clock reset */
#define RCC_AHBRSTR_GPIOC_Pos           (19)
#define RCC_AHBRSTR_GPIOC               (0x01U << RCC_AHBRSTR_GPIOC_Pos)        /*!< GPIOC clock reset */
#define RCC_AHBRSTR_GPIOD_Pos           (20)
#define RCC_AHBRSTR_GPIOD               (0x01U << RCC_AHBRSTR_GPIOD_Pos)        /*!< GPIOD clock reset */
#define RCC_AHBRSTR_USB_Pos             (24)
#define RCC_AHBRSTR_USB                 (0x01U << RCC_AHBRSTR_USB_Pos)          /*!< USB clock reset */
#define RCC_AHBRSTR_DIVIDER_Pos         (26)
#define RCC_AHBRSTR_DIVIDER             (0x01U << RCC_AHBRSTR_DIVIDER_Pos)      /*!< DIVIDER clock reset */

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define RCC_CFGR2_LPUART_CLKSEL_Pos     (0)
#define RCC_CFGR2_LPUART_CLKSEL         (0x03U << RCC_CFGR2_LPUART_CLKSEL_Pos)      /*!< LPUART clock source selection */
#define RCC_CFGR2_LPUART_CLKSEL_LSE     (0x00U << RCC_CFGR2_LPUART_CLKSEL_Pos)      /*!< LSE (default) */
#define RCC_CFGR2_LPUART_CLKSEL_LSI     (0x01U << RCC_CFGR2_LPUART_CLKSEL_Pos)      /*!< LSI */
#define RCC_CFGR2_LPUART_CLKSEL_PCLK_LPUART (0x02U << RCC_CFGR2_LPUART_CLKSEL_Pos)  /*!< PCLK_LPUART */
#define RCC_CFGR2_LPUART_CLKSEL_NONE    (0x03U << RCC_CFGR2_LPUART_CLKSEL_Pos)      /*!< No clock */

#define RCC_CFGR2_CAN_CLKSEL_Pos        (8)
#define RCC_CFGR2_CAN_CLKSEL            (0x03U << RCC_CFGR2_CAN_CLKSEL_Pos)     /*!< CANPE clock source selection */
#define RCC_CFGR2_CAN_CLKSEL_PLL1       (0x00U << RCC_CFGR2_CAN_CLKSEL_Pos)     /*!< PLL1(default) */
#define RCC_CFGR2_CAN_CLKSEL_PLL2       (0x01U << RCC_CFGR2_CAN_CLKSEL_Pos)     /*!< PLL2 */
#define RCC_CFGR2_CAN_CLKSEL_HSE        (0x02U << RCC_CFGR2_CAN_CLKSEL_Pos)     /*!< HSE */
#define RCC_CFGR2_CAN_CLKSEL_NONE       (0x03U << RCC_CFGR2_CAN_CLKSEL_Pos)     /*!< NO clock */

#define RCC_CFGR2_CANPRE_Pos            (12)
#define RCC_CFGR2_CANPRE                (0x03U << RCC_CFGR2_CANPRE_Pos)         /*!< CANPE clock division */
#define RCC_CFGR2_CANPRE_DIV1           (0x00U << RCC_CFGR2_CANPRE_Pos)         /*!< No frequency division (default) */
#define RCC_CFGR2_CANPRE_DIV2           (0x01U << RCC_CFGR2_CANPRE_Pos)         /*!< 2 Frequency division */
#define RCC_CFGR2_CANPRE_DIV3           (0x02U << RCC_CFGR2_CANPRE_Pos)         /*!< 3 Frequency division */
#define RCC_CFGR2_CANPRE_DIV4           (0x03U << RCC_CFGR2_CANPRE_Pos)         /*!< 4 Frequency division */

#define RCC_CFGR2_APB1_CLK_HV_PRE_POS   (16)
#define RCC_CFGR2_APB1_CLK_HV_PRE       (0x0FU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< APB1_HV output clock frequency division coefficient */
#define RCC_CFGR2_APB1_CLK_HV_PRE_8     (0x03U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 8  frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_10    (0x04U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 10 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_12    (0x05U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 12 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_14    (0x06U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 14 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_16    (0x07U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 16 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_18    (0x08U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 18 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_20    (0x09U << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 20 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_22    (0x0AU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 22 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_24    (0x0BU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 24 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_26    (0x0CU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 26 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_28    (0x0DU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 28 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_30    (0x0EU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 30 frequency division */
#define RCC_CFGR2_APB1_CLK_HV_PRE_32    (0x0FU << RCC_CFGR2_APB1_CLK_HV_PRE_POS)    /*!< 32 frequency division */

#define RCC_CFGR2_MCOPRE_Pos            (20)
#define RCC_CFGR2_MCOPRE_1              (0x00U << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 1   frequency division */
#define RCC_CFGR2_MCOPRE_2              (0x08U << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 2   frequency division */
#define RCC_CFGR2_MCOPRE_4              (0x09U << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 4   frequency division */
#define RCC_CFGR2_MCOPRE_8              (0x0AU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 8   frequency division */
#define RCC_CFGR2_MCOPRE_16             (0x0BU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 16  frequency division */
#define RCC_CFGR2_MCOPRE_64             (0x0CU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 64  frequency division */
#define RCC_CFGR2_MCOPRE_128            (0x0DU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 128 frequency division */
#define RCC_CFGR2_MCOPRE_256            (0x0EU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 256 frequency division */
#define RCC_CFGR2_MCOPRE_512            (0x0FU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 512 frequency division */

#define RCC_CFGR2_LPTIM_CLKSEL_Pos      (29)
#define RCC_CFGR2_LPTIM_CLKSEL          (0x03U << RCC_CFGR2_LPTIM_CLKSEL_Pos)      /*!< LPTIM clock source selection */
#define RCC_CFGR2_LPTIM_CLKSEL_LSE      (0x00U << RCC_CFGR2_LPTIM_CLKSEL_Pos)      /*!< LSE (default) */
#define RCC_CFGR2_LPTIM_CLKSEL_LSI      (0x01U << RCC_CFGR2_LPTIM_CLKSEL_Pos)      /*!< LSI */
#define RCC_CFGR2_LPTIM_CLKSEL_PCLK_LPTIMER (0x02U << RCC_CFGR2_LPTIM_CLKSEL_Pos)  /*!< PCLK_LPTIMER */
#define RCC_CFGR2_LPTIM_CLKSEL_NONE     (0x03U << RCC_CFGR2_LPTIM_CLKSEL_Pos)      /*!< No clock */

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define RCC_SYSCFG_PROG_CHECK_EN_Pos    (0)
#define RCC_SYSCFG_PROG_CHECK_EN        (0x01U << RCC_SYSCFG_PROG_CHECK_EN_Pos) /*!< Whether to check the number in Flash when writing to Flash */
#define RCC_SYSCFG_HSE_RFB_SEL_Pos      (8)
#define RCC_SYSCFG_HSE_RFB_SEL          (0x03U << RCC_SYSCFG_HSE_RFB_SELPos)    /*!< Feedback resistance selection */
#define RCC_SYSCFG_HSE_RFB_SEL_2M       (0x00U << RCC_SYSCFG_HSE_RFB_SELPos)    /*!< 2M */
#define RCC_SYSCFG_HSE_RFB_SEL_1M       (0x01U << RCC_SYSCFG_HSE_RFB_SELPos)    /*!< 1M */
#define RCC_SYSCFG_HSE_RFB_SEL_500K     (0x02U << RCC_SYSCFG_HSE_RFB_SELPos)    /*!< 500K */
#define RCC_SYSCFG_HSE_RFB_SEL_200K     (0x03U << RCC_SYSCFG_HSE_RFB_SELPos)    /*!< 200K */

#define RCC_SYSCFG_HSELPFEN_Pos         (14)
#define RCC_SYSCFG_HSELPFEN             (0x01U << RCC_SYSCFG_HSELPFEN_Pos)      /*!< Oscillator low pass filtering enable */

/**
  * @brief RCC_HSIDLY Register Bit Definition
  */
#define RCC_HSIDLY_HSI_EQU_CNT_Pos      (0)
#define RCC_HSIDLY_HSI_EQU_CNT          (0xFFU << RCC_HSIDLY_HSI_EQU_CNT_Pos)   /*!< HSI Delay Time */

/**
  * @brief RCC_HSEDLY Register Bit Definition
  */
#define RCC_HSEDLY_HSE_EQU_CNT_Pos      (0)
#define RCC_HSEDLY_HSE_EQU_CNT          (0xFFU << RCC_HSEDLY_HSE_EQU_CNT_Pos)   /*!< HSE Delay Time */

/**
  * @brief RCC_ICSCR Register Bit Definition
  */
#define RCC_ICSCR_TRIM_CRS_SEL_Pos      (0)
#define RCC_ICSCR_TRIM_CRS_SEL          (0x01U << RCC_ICSCR_TRIM_CRS_SEL_Pos)   /*!< Whether the HSITRIM value uses the CRS module as the source */
#define RCC_ICSCR_HSI_CAL_SEL_Pos       (11)
#define RCC_ICSCR_HSI_CAL_SEL           (0x1FU << RCC_ICSCR_HSI_CAL_SEL_Pos)    /*!< Select the value of register HSICAL */
#define RCC_ICSCR_HSI_CAL_SFT_Pos       (16)
#define RCC_ICSCR_HSI_CAL_SFT           (0x1FU << RCC_ICSCR_HSI_CAL_SFT_Pos)    /*!< Select the value of register HSICAL */

/**
  * @brief RCC_PLL1CFGR Register Bit Definition
  */
#define RCC_PLL1CFGR_PLL1SRC_Pos        (0)
#define RCC_PLL1CFGR_PLL1SRC            (0x01U << RCC_PLL1CFGR_PLL1SRC_Pos)     /*!< HSE as PLL1 entry clock */
#define RCC_PLL1CFGR_PLL1XTPRE_Pos      (1)
#define RCC_PLL1CFGR_PLL1XTPRE          (0x01U << RCC_PLL1CFGR_PLL1XTPRE_Pos)   /*!< HSE frequency division for PLL1 entry */
#define RCC_PLL1CFGR_PLL1_ICTRL_Pos     (2)
#define RCC_PLL1CFGR_PLL1_ICTRL         (0x03U << RCC_PLL1CFGR_PLL1_ICTRL_Pos)  /*!< PLL1 CP current control signals mask */
#define RCC_PLL1CFGR_PLL1_LDS_Pos       (4)
#define RCC_PLL1CFGR_PLL1_LDS           (0x03U << RCC_PLL1CFGR_PLL1_LDS_Pos)    /*!< PLL1 LOCK DETECTOR ACCURACY SELECT */
#define RCC_PLL1CFGR_PLL1DIV_Pos        (8)
#define RCC_PLL1CFGR_PLL1DIV            (0x07U << RCC_PLL1CFGR_PLL1DIV_Pos)     /*!< PLL1?Divide?Factor */
#define RCC_PLL1CFGR_PLL1MUL_Pos        (16)
#define RCC_PLL1CFGR_PLL1MUL            (0xFFU << RCC_PLL1CFGR_PLL1MUL_Pos)     /*!< PLL1?Multiplication?Factor */
#define RCC_PLL1CFGR_PLL1PDIV_Pos       (29)
#define RCC_PLL1CFGR_PLL1PDIV           (0x07U << RCC_PLL1CFGR_PLL1PDIV_Pos)    /*!< PLL1?Pre-divider?Factor */

/**
  * @brief RCC_PLL2CFGR Register Bit Definition
  */
#define RCC_PLL2CFGR_PLL2SRC_Pos        (0)
#define RCC_PLL2CFGR_PLL2SRC            (0x01U << RCC_PLL2CFGR_PLL2SRC_Pos)     /*!< HSE as PLL2 entry clock */
#define RCC_PLL2CFGR_PLL2XTPRE_Pos      (1)
#define RCC_PLL2CFGR_PLL2XTPRE          (0x01U << RCC_PLL2CFGR_PLL2XTPRE_Pos)   /*!< HSE frequency division for PLL2 entry */
#define RCC_PLL2CFGR_PLL2_ICTRL_Pos     (2)
#define RCC_PLL2CFGR_PLL2_ICTRL         (0x03U << RCC_PLL2CFGR_PLL2_ICTRL_Pos)  /*!< PLL2 CP current control signals mask */
#define RCC_PLL2CFGR_PLL2_LDS_Pos       (4)
#define RCC_PLL2CFGR_PLL2_LDS           (0x03U << RCC_PLL2CFGR_PLL2_LDS_Pos)    /*!< PLL2 LOCK DETECTOR ACCURACY SELECT */
#define RCC_PLL2CFGR_PLL2DIV_Pos        (8)
#define RCC_PLL2CFGR_PLL2DIV            (0x07U << RCC_PLL2CFGR_PLL2DIV_Pos)     /*!< PLL2?Divide?Factor */
#define RCC_PLL2CFGR_PLL2MUL_Pos        (16)
#define RCC_PLL2CFGR_PLL2MUL            (0xFFU << RCC_PLL2CFGR_PLL2MUL_Pos)     /*!< PLL2?Multiplication?Factor */
#define RCC_PLL2CFGR_PLL2PDIV_Pos       (29)
#define RCC_PLL2CFGR_PLL2PDIV           (0x07U << RCC_PLL2CFGR_PLL2PDIV_Pos)    /*!< PLL2?Pre-divider?Factor */

/**
  * @brief RCC_LDOCR Register Bit Definition
  */
#define RCC_LDOCR_LDO_TRIM_SEL_Pos      (11)
#define RCC_LDOCR_LDO_TRIM_SEL          (0x1FU << RCC_LDOCR_LDO_TRIM_SEL_Pos)   /*!< Judge LDOTRIM value as LDO Trim value */

#define RCC_LDOCR_LDO_TRIM_Pos          (16)
#define RCC_LDOCR_LDO_TRIM              (0x0FU << RCC_LDOCR_LDO_TRIM_Pos)       /*!< LDOTRIM value */

/**
  * @brief RCC_PLL1DLY Register Bit Definition
  */
#define RCC_PLL1DLY_EQU_CNT_Pos         (0)
#define RCC_PLL1DLY_EQU_CNT             (0x03FFU << RCC_PLL1DLY_EQU_CNT_Pos)    /*!< PLL1 delay time */

/**
  * @brief RCC_PLLDLY Register Bit Definition
  */
#define RCC_PLL2DLY_EQU_CNT_Pos         (0)
#define RCC_PLL2DLY_EQU_CNT             (0x03FFU << RCC_PLL2DLY_EQU_CNT_Pos)    /*!< PLL2 delay time */

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
