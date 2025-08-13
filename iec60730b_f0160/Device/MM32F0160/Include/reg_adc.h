/*
 *******************************************************************************
    @file     reg_adc.h
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

#ifndef __REG_ADC_H
#define __REG_ADC_H

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
  * @brief ADC Base Address Definition
  */
#define ADC1_BASE                       (APB2PERIPH_BASE + 0x2400)              /*!< Base Address: 0x40012400 */

/**
  * @brief Analog-to-Digital Converter register
  */
typedef struct {
    __IO uint32_t ADDATA;                                                            /*!< ADC data register,                             offset: 0x00 */
    __IO uint32_t ADCFG;                                                             /*!< ADC configuration register,                    offset: 0x04 */
    __IO uint32_t ADCR;                                                              /*!< ADC control register,                          offset: 0x08 */
    __IO uint32_t ADCHS;                                                             /*!< ADC channel selection register,                offset: 0x0C */
    __IO uint32_t ADCMPR;                                                            /*!< ADC window compare register,                   offset: 0x10 */
    __IO uint32_t ADSTA;                                                             /*!< ADC status register,                           offset: 0x14 */
    union {
        __IO uint32_t ADDR[16];                                                      /*!< ADC data registers                             offset: 0x18~0x54 */
        struct {
            __IO uint32_t ADDR0;                                                     /*!< ADC data register 0,                           offset: 0x18 */
            __IO uint32_t ADDR1;                                                     /*!< ADC data register 1,                           offset: 0x1C */
            __IO uint32_t ADDR2;                                                     /*!< ADC data register 2,                           offset: 0x20 */
            __IO uint32_t ADDR3;                                                     /*!< ADC data register 3,                           offset: 0x24 */
            __IO uint32_t ADDR4;                                                     /*!< ADC data register 4,                           offset: 0x28 */
            __IO uint32_t ADDR5;                                                     /*!< ADC data register 5,                           offset: 0x2C */
            __IO uint32_t ADDR6;                                                     /*!< ADC data register 6,                           offset: 0x30 */
            __IO uint32_t ADDR7;                                                     /*!< ADC data register 7,                           offset: 0x34 */
            __IO uint32_t ADDR8;                                                     /*!< ADC data register 8,                           offset: 0x38 */
            __IO uint32_t ADDR9;                                                     /*!< ADC data register 9,                           offset: 0x3C */
            __IO uint32_t ADDR10;                                                    /*!< ADC data register 10,                          offset: 0x40 */
            __IO uint32_t ADDR11;                                                    /*!< ADC data register 11,                          offset: 0x44 */
            __IO uint32_t ADDR12;                                                    /*!< ADC data register 12,                          offset: 0x48 */
            __IO uint32_t ADDR13;                                                    /*!< ADC data register 13,                          offset: 0x4C */
            __IO uint32_t ADDR14;                                                    /*!< ADC data register 14,                          offset: 0x50 */
            __IO uint32_t ADDR15;                                                    /*!< ADC data register 15,                          offset: 0x54 */
        };
    };
    __IO uint32_t ADSTA_EXT;                                                         /*!< ADC Extended Status Register,                  offset: 0x58 */
    __IO uint32_t CHANY0;                                                            /*!< ADC any Chan Select Register 0,                offset: 0x5C */
    __IO uint32_t CHANY1;                                                            /*!< ADC any Chan Select Register 1,                offset: 0x60 */
    __IO uint32_t ANY_CFG;                                                           /*!< ADC any Chan config Register,                  offset: 0x64 */
    __IO uint32_t ANY_CR;                                                            /*!< ADC any Chan control Register,                 offset: 0x68 */
    __IO uint32_t RESERVED0x6C;                                                      /*!< Reserved register                              offset: 0x6C */
    __IO uint32_t SMPR1;                                                             /*!< Sampling configuration register 1              offset: 0x70 */
    __IO uint32_t SMPR2;                                                             /*!< Sampling configuration register 2              offset: 0x74 */
    __IO uint32_t RESERVED0x78;                                                      /*!< Reserved register                              offset: 0x78 */
    union {
        __IO uint32_t JOFR[4];                                                       /*!< Injection channel data compensation registers  offset: 0x7C~0x88 */
        struct {
            __IO uint32_t JOFR0;                                                     /*!< Injection channel data compensation register 0 offset: 0x7C */
            __IO uint32_t JOFR1;                                                     /*!< Injection channel data compensation register 1 offset: 0x80 */
            __IO uint32_t JOFR2;                                                     /*!< Injection channel data compensation register 2 offset: 0x84 */
            __IO uint32_t JOFR3;                                                     /*!< Injection channel data compensation register 3 offset: 0x88 */
        };
    };
    __IO uint32_t JSQR;                                                              /*!< Injection sequence register                    offset: 0x8C */
    __IO uint32_t JADDATA;                                                           /*!< Inject data register                           offset: 0x90 */
    __IO uint32_t RESERVED0x94[7];                                                   /*!< Reserved                                       offset: 0x94~0xAC */
    union {
        __IO uint32_t JDR[4];                                                        /*!< Injection channel data registers               offset: 0xB0~0xBC */
        struct {
            __IO uint32_t JDR0;                                                      /*!< Injection channel data register 0              offset: 0xB0 */
            __IO uint32_t JDR1;                                                      /*!< Injection channel data register 1              offset: 0xB4 */
            __IO uint32_t JDR2;                                                      /*!< Injection channel data register 2              offset: 0xB8 */
            __IO uint32_t JDR3;                                                      /*!< Injection channel data register 3              offset: 0xBC */
        };
    };
    __IO uint32_t RESERVED0xC0[12];                                                  /*!< Reserved                                       offset: 0xC0~0xEC */
    __IO uint32_t LDATA;                                                             /*!< Last Conversion Data registers                 offset: 0xF0 */
} ADC_TypeDef;


/**
  * @brief ADC type pointer Definition
  */
#define ADC1                            ((ADC_TypeDef*) ADC1_BASE)

/**
  * @brief ADC_ADDATA Register Bit Definition
  */
#define ADC_ADDATA_DATA_Pos             (0)
#define ADC_ADDATA_DATA                 (0xFFFFU << ADC_ADDATA_DATA_Pos)        /*!< ADC 12bit convert data */

#define ADC_ADDATA_CHANNELSEL_Pos       (16)
#define ADC_ADDATA_CHANNELSEL           (0x0FU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< CHANNELSEL[19:16] (ADC current channel convert data) */
#define ADC_ADDATA_CHANNELSEL_0         (0x00U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  0 */
#define ADC_ADDATA_CHANNELSEL_1         (0x01U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  1 */
#define ADC_ADDATA_CHANNELSEL_2         (0x02U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  2 */
#define ADC_ADDATA_CHANNELSEL_3         (0x03U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  3 */
#define ADC_ADDATA_CHANNELSEL_4         (0x04U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  4 */
#define ADC_ADDATA_CHANNELSEL_5         (0x05U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  5 */
#define ADC_ADDATA_CHANNELSEL_6         (0x06U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  6 */
#define ADC_ADDATA_CHANNELSEL_7         (0x07U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  7 */
#define ADC_ADDATA_CHANNELSEL_8         (0x08U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  8 */
#define ADC_ADDATA_CHANNELSEL_9         (0x09U << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  9 */
#define ADC_ADDATA_CHANNELSEL_10        (0x0AU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  10 */
#define ADC_ADDATA_CHANNELSEL_11        (0x0BU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  11 */
#define ADC_ADDATA_CHANNELSEL_12        (0x0CU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  12 */
#define ADC_ADDATA_CHANNELSEL_13        (0x0DU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  13 */
#define ADC_ADDATA_CHANNELSEL_14        (0x0EU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  14 */
#define ADC_ADDATA_CHANNELSEL_15        (0x0FU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< ADC Channel select  15 */

#define ADC_ADDATA_OVERRUN_Pos          (20)
#define ADC_ADDATA_OVERRUN              (0x01U << ADC_ADDATA_OVERRUN_Pos)       /*!< ADC data will be cover */
#define ADC_ADDATA_VALID_Pos            (21)
#define ADC_ADDATA_VALID                (0x01U << ADC_ADDATA_VALID_Pos)         /*!< ADC data[11:0] is valid */

/**
  * @brief ADC_ADCFG Register Bit Definition
  */
#define ADC_ADCFG_ADEN_Pos              (0)
#define ADC_ADCFG_ADEN                  (0x01U << ADC_ADCFG_ADEN_Pos)           /*!< Enable ADC convert */
#define ADC_ADCFG_ADWEN_Pos             (1)
#define ADC_ADCFG_ADWEN                 (0x01U << ADC_ADCFG_ADWEN_Pos)          /*!< Enable ADC window compare */

#define ADC_ADCFG_TSEN_Pos              (2)
#define ADC_ADCFG_TSEN                  (0x01U << ADC_ADCFG_TSEN_Pos)           /*!< Enable ADC temperature sensor */

#define ADC_ADCFG_VSEN_Pos              (3)
#define ADC_ADCFG_VSEN                  (0x01U << ADC_ADCFG_VSEN_Pos)           /*!< Enable ADC voltage reference */

#define ADC_ADCFG_ADCPREH_Pos           (4)
#define ADC_ADCFG_ADCPREL_Pos           (14)
#define ADC_ADCFG_ADCPRE                ((0x07U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))
#define ADC_ADCFG_ADCPRE_2              ((0x00U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 2 */
#define ADC_ADCFG_ADCPRE_4              ((0x01U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 4 */
#define ADC_ADCFG_ADCPRE_6              ((0x02U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 6 */
#define ADC_ADCFG_ADCPRE_8              ((0x03U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 8 */
#define ADC_ADCFG_ADCPRE_10             ((0x04U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 10 */
#define ADC_ADCFG_ADCPRE_12             ((0x05U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 12 */
#define ADC_ADCFG_ADCPRE_14             ((0x06U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 14 */
#define ADC_ADCFG_ADCPRE_16             ((0x07U << ADC_ADCFG_ADCPREH_Pos) + (0x00U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 16 */
#define ADC_ADCFG_ADCPRE_3              ((0x00U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 3 */
#define ADC_ADCFG_ADCPRE_5              ((0x01U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 5 */
#define ADC_ADCFG_ADCPRE_7              ((0x02U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 7 */
#define ADC_ADCFG_ADCPRE_9              ((0x03U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 9 */
#define ADC_ADCFG_ADCPRE_11             ((0x04U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 11 */
#define ADC_ADCFG_ADCPRE_13             ((0x05U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 13 */
#define ADC_ADCFG_ADCPRE_15             ((0x06U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 15 */
#define ADC_ADCFG_ADCPRE_17             ((0x07U << ADC_ADCFG_ADCPREH_Pos) + (0x01U << ADC_ADCFG_ADCPREL_Pos))    /*!< ADC preclk 17 */

#define ADC_ADCFG_RSLTCTL_Pos           (7)
#define ADC_ADCFG_RSLTCTL               (0x07U << ADC_ADCFG_RSLTCTL_Pos)        /*!< ADC resolution select */
#define ADC_ADCFG_RSLTCTL_12            (0x00U << ADC_ADCFG_RSLTCTL_Pos)        /*!< ADC resolution select 12bit */
#define ADC_ADCFG_RSLTCTL_11            (0x01U << ADC_ADCFG_RSLTCTL_Pos)        /*!< ADC resolution select 11bit */
#define ADC_ADCFG_RSLTCTL_10            (0x02U << ADC_ADCFG_RSLTCTL_Pos)        /*!< ADC resolution select 10bit */
#define ADC_ADCFG_RSLTCTL_9             (0x03U << ADC_ADCFG_RSLTCTL_Pos)        /*!< ADC resolution select 9bit */
#define ADC_ADCFG_RSLTCTL_8             (0x04U << ADC_ADCFG_RSLTCTL_Pos)        /*!< ADC resolution select 8bit */
#define ADC_ADCFG_JAWDEN_Pos            (16)
#define ADC_ADCFG_JAWDEN                (0x01U << ADC_ADCFG_JAWDEN_Pos)         /*!< Inject ADC conversion window comparison enable */

/**
  * @brief ADC_CR Register Bit Definition
  */
#define ADC_ADCR_EOSIE_Pos              (0)
#define ADC_ADCR_EOSIE                  (0x01U << ADC_ADCR_EOSIE_Pos)           /*!< ADC interrupt enable */

#define ADC_ADCR_AWDIE_Pos              (1)
#define ADC_ADCR_AWDIE                  (0x01U << ADC_ADCR_AWDIE_Pos)           /*!< Interrupt Enable of Analog Watchdog */

#define ADC_ADCR_TRGEN_Pos              (2)
#define ADC_ADCR_TRGEN                  (0x01U << ADC_ADCR_TRGEN_Pos)           /*!< extranal trigger single start AD convert */
#define ADC_ADCR_DMAEN_Pos              (3)
#define ADC_ADCR_DMAEN                  (0x01U << ADC_ADCR_DMAEN_Pos)           /*!< ADC DMA enable */



#define ADC_ADCR_ADST_Pos               (8)
#define ADC_ADCR_ADST                   (0x01U << ADC_ADCR_ADST_Pos)            /*!< ADC start convert data */
#define ADC_ADCR_ADMD_Pos               (9)
#define ADC_ADCR_ADMD                   (0x03U << ADC_ADCR_ADMD_Pos)            /*!< ADC convert mode */
#define ADC_ADCR_ADMD_IMM               (0x00U << ADC_ADCR_ADMD_Pos)            /*!< ADC imm convert mode */
#define ADC_ADCR_ADMD_SCAN              (0x01U << ADC_ADCR_ADMD_Pos)            /*!< ADC scan convert mode */
#define ADC_ADCR_ADMD_CONTINUE          (0x02U << ADC_ADCR_ADMD_Pos)            /*!< ADC continue scan convert mode */
#define ADC_ADCR_ALIGN_Pos              (11)
#define ADC_ADCR_ALIGN                  (0x01U << ADC_ADCR_ALIGN_Pos)           /*!< ADC data align */
#define ADC_ADCR_LEFT                   (0x01U << ADC_ADCR_ALIGN_Pos)           /*!< ADC data left align */
#define ADC_ADCR_RIGHT                  (0x00U << ADC_ADCR_ALIGN_Pos)           /*!< ADC data right align */
#define ADC_ADCR_CMPCH_Pos              (12)
#define ADC_ADCR_CMPCH                  (0x0FU << ADC_ADCR_CMPCH_Pos)           /*!< CMPCH[15:12] ADC window compare channel0 convert data */
#define ADC_ADCR_CMPCH_0                (0x00U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 0 Conversion Results */
#define ADC_ADCR_CMPCH_1                (0x01U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 1 Conversion Results */
#define ADC_ADCR_CMPCH_2                (0x02U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 2 Conversion Results */
#define ADC_ADCR_CMPCH_3                (0x03U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 3 Conversion Results */
#define ADC_ADCR_CMPCH_4                (0x04U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 4 Conversion Results */
#define ADC_ADCR_CMPCH_5                (0x05U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 5 Conversion Results */
#define ADC_ADCR_CMPCH_6                (0x06U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 6 Conversion Results */
#define ADC_ADCR_CMPCH_7                (0x07U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 7 Conversion Results */
#define ADC_ADCR_CMPCH_8                (0x08U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 8 Conversion Results */
#define ADC_ADCR_CMPCH_9                (0x09U << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 9 Conversion Results */
#define ADC_ADCR_CMPCH_10               (0x0AU << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 10 Conversion Results */
#define ADC_ADCR_CMPCH_11               (0x0BU << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 11 Conversion Results */
#define ADC_ADCR_CMPCH_12               (0x0CU << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 12 Conversion Results */
#define ADC_ADCR_CMPCH_13               (0x0DU << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 13 Conversion Results */
#define ADC_ADCR_CMPCH_14               (0x0EU << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare Channel 14 Conversion Results */
#define ADC_ADCR_CMPCH_ALL              (0x0FU << ADC_ADCR_CMPCH_Pos)           /*!< Select Compare ALL Channel Conversion Results */

#define ADC_ADCR_SCANDIR_Pos            (16)
#define ADC_ADCR_SCANDIR                (0x01U << ADC_ADCR_SCANDIR_Pos)         /*!< ADC scan direction */

#define ADC_ADCR_TRGSELH_Pos            (17)
#define ADC_ADCR_TRGSELL_Pos            (4)
#define ADC_ADCR_TRGSEL                 ((0x03U << ADC_ADCR_TRGSELH_Pos) + (0x07U << ADC_ADCR_TRGSELL_Pos))   /*!< TRGSEL[6:4][18:17] ADC external trigger source select */
#define ADC_ADCR_TRGSEL_T1_CC1          ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x00U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_CC1 */
#define ADC_ADCR_TRGSEL_T1_CC2          ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x01U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_CC2 */
#define ADC_ADCR_TRGSEL_T1_CC3          ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x02U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_CC3 */
#define ADC_ADCR_TRGSEL_T2_CC2          ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x03U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T2_CC2 */
#define ADC_ADCR_TRGSEL_T3_TRIG         ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x04U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T3_TRIG */
#define ADC_ADCR_TRGSEL_T1_CC4_CC5      ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x05U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_CC4_CC5 */
#define ADC_ADCR_TRGSEL_T3_CC1          ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x06U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T3_CC1 */
#define ADC_ADCR_TRGSEL_EXTI_11         ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x07U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is EXTI_11 */
#define ADC_ADCR_TRGSEL_T1_TRIG         ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x00U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_TRIG */
#define ADC_ADCR_TRGSEL_EXTI_4          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x01U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is EXTI_4 */
#define ADC_ADCR_TRGSEL_EXTI_5          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x02U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is EXTI_5 */
#define ADC_ADCR_TRGSEL_T2_CC1          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x03U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T2_CC1 */
#define ADC_ADCR_TRGSEL_T3_CC4          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x04U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T3_CC4 */
#define ADC_ADCR_TRGSEL_T2_TRIG         ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x05U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T2_TRIG */
#define ADC_ADCR_TRGSEL_EXTI_15         ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x07U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is EXTI_15 */
#define ADC_ADCR_TRGSEL_T1_CC4          ((0x02U << ADC_ADCR_TRGSELH_Pos) + (0x00U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_CC4 */
#define ADC_ADCR_TRGSEL_T1_CC5          ((0x02U << ADC_ADCR_TRGSELH_Pos) + (0x01U << ADC_ADCR_TRGSELL_Pos))   /*!< The external trigger source of the ADC is T1_CC5 */

#define ADC_ADCR_TRGSHIFT_Pos           (19)
#define ADC_ADCR_TRGSHIFT               (0x07U << ADC_ADCR_TRGSHIFT_Pos)        /*!< External trigger shift sample */
#define ADC_ADCR_TRGSHIFT_0             (0x00U << ADC_ADCR_TRGSHIFT_Pos)        /*!< No shift */
#define ADC_ADCR_TRGSHIFT_4             (0x01U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 4 period */
#define ADC_ADCR_TRGSHIFT_16            (0x02U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 16 period */
#define ADC_ADCR_TRGSHIFT_32            (0x03U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 32 period */
#define ADC_ADCR_TRGSHIFT_64            (0x04U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 64 period */
#define ADC_ADCR_TRGSHIFT_128           (0x05U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 128 period */
#define ADC_ADCR_TRGSHIFT_256           (0x06U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 256 period */
#define ADC_ADCR_TRGSHIFT_512           (0x07U << ADC_ADCR_TRGSHIFT_Pos)        /*!< Shift 512 period */
#define ADC_ADCR_TRG_EDGE_Pos           (24)
#define ADC_ADCR_TRG_EDGE               (0x03U << ADC_ADCR_TRG_EDGE_Pos)        /*!< ADC trig edge config */
#define ADC_ADCR_TRG_EDGE_DUAL          (0x00U << ADC_ADCR_TRG_EDGE_Pos)        /*!< ADC dual edge trig mode */
#define ADC_ADCR_TRG_EDGE_DOWN          (0x01U << ADC_ADCR_TRG_EDGE_Pos)        /*!< ADC down edge trig mode */
#define ADC_ADCR_TRG_EDGE_UP            (0x02U << ADC_ADCR_TRG_EDGE_Pos)        /*!< ADC up   edge trig mode */
#define ADC_ADCR_TRG_EDGE_MASK          (0x03U << ADC_ADCR_TRG_EDGE_Pos)        /*!< ADC mask edge trig mode */

#define ADC_ADCR_EOSMPIE_Pos            (26)
#define ADC_ADCR_EOSMPIE                (0X01U << ADC_ADCR_EOSMPIE_Pos)         /*!< ADC end sampling flag interrupt enable */
#define ADC_ADCR_EOCIE_Pos              (27)
#define ADC_ADCR_EOCIE                  (0X01U << ADC_ADCR_EOCIE_Pos)           /*!< ADC end of conversion interrupt enable */

/**
  * @brief ADC_ADCHS Register Bit Definition
  */
#define ADC_ADCHS_CHEN0_Pos             (0)
#define ADC_ADCHS_CHEN0                 (0x01U << ADC_ADCHS_CHEN0_Pos)          /*!< Enable ADC channel 0 */
#define ADC_ADCHS_CHEN1_Pos             (1)
#define ADC_ADCHS_CHEN1                 (0x01U << ADC_ADCHS_CHEN1_Pos)          /*!< Enable ADC channel 1 */
#define ADC_ADCHS_CHEN2_Pos             (2)
#define ADC_ADCHS_CHEN2                 (0x01U << ADC_ADCHS_CHEN2_Pos)          /*!< Enable ADC channel 2 */
#define ADC_ADCHS_CHEN3_Pos             (3)
#define ADC_ADCHS_CHEN3                 (0x01U << ADC_ADCHS_CHEN3_Pos)          /*!< Enable ADC channel 3 */
#define ADC_ADCHS_CHEN4_Pos             (4)
#define ADC_ADCHS_CHEN4                 (0x01U << ADC_ADCHS_CHEN4_Pos)          /*!< Enable ADC channel 4 */
#define ADC_ADCHS_CHEN5_Pos             (5)
#define ADC_ADCHS_CHEN5                 (0x01U << ADC_ADCHS_CHEN5_Pos)          /*!< Enable ADC channel 5 */
#define ADC_ADCHS_CHEN6_Pos             (6)
#define ADC_ADCHS_CHEN6                 (0x01U << ADC_ADCHS_CHEN6_Pos)          /*!< Enable ADC channel 6 */
#define ADC_ADCHS_CHEN7_Pos             (7)
#define ADC_ADCHS_CHEN7                 (0x01U << ADC_ADCHS_CHEN7_Pos)          /*!< Enable ADC channel 7 */
#define ADC_ADCHS_CHEN8_Pos             (8)
#define ADC_ADCHS_CHEN8                 (0x01U << ADC_ADCHS_CHEN8_Pos)          /*!< Enable ADC channel 8 */
#define ADC_ADCHS_CHEN9_Pos             (9)
#define ADC_ADCHS_CHEN9                 (0x01U << ADC_ADCHS_CHEN9_Pos)          /*!< Enable ADC channel 9 */
#define ADC_ADCHS_CHEN10_Pos            (10)
#define ADC_ADCHS_CHEN10                (0x01U << ADC_ADCHS_CHEN10_Pos)         /*!< Enable ADC channel 10 */
#define ADC_ADCHS_CHEN11_Pos            (11)
#define ADC_ADCHS_CHEN11                (0x01U << ADC_ADCHS_CHEN11_Pos)         /*!< Enable ADC channel 11 */
#define ADC_ADCHS_CHEN12_Pos            (12)
#define ADC_ADCHS_CHEN12                (0x01U << ADC_ADCHS_CHEN12_Pos)         /*!< Enable ADC channel 12 */
#define ADC_ADCHS_CHEN13_Pos            (13)
#define ADC_ADCHS_CHEN13                (0x01U << ADC_ADCHS_CHEN13_Pos)         /*!< Enable ADC channel 13 */
#define ADC_ADCHS_CHEN14_Pos            (14)
#define ADC_ADCHS_CHEN14                (0x01U << ADC_ADCHS_CHEN14_Pos)         /*!< Enable ADC channel 14 */
#define ADC_ADCHS_CHEN15_Pos            (15)
#define ADC_ADCHS_CHEN15                (0x01U << ADC_ADCHS_CHEN15_Pos)         /*!< Enable ADC channel 15 */

#define ADC_ADCHS_CHT_Pos                ADC_ADCHS_CHEN14_Pos
#define ADC_ADCHS_CHT                    ADC_ADCHS_CHEN14                           /*!< Enable Temperature Sensor */
#define ADC_ADCHS_CHV_Pos                ADC_ADCHS_CHEN15_Pos
#define ADC_ADCHS_CHV                    ADC_ADCHS_CHEN15                           /*!< Enable Voltage Sensor */

/**
  * @brief ADC_ADCMPR Register Bit Definition
  */
#define ADC_ADCMPR_CMPLDATA_Pos         (0)
#define ADC_ADCMPR_CMPLDATA             (0x0FFFU << ADC_ADCMPR_CMPLDATA_Pos)    /*!< ADC 12bit window compare DOWN LEVEL DATA */
#define ADC_ADCMPR_CMPHDATA_Pos         (16)
#define ADC_ADCMPR_CMPHDATA             (0x0FFFU << ADC_ADCMPR_CMPHDATA_Pos)    /*!< ADC 12bit window compare UP LEVEL DATA */

/**
  * @brief ADC_ADSTA Register Bit Definition
  */
#define ADC_ADSTA_EOSIF_Pos             (0)
#define ADC_ADSTA_EOSIF                 (0x01U << ADC_ADSTA_EOSIF_Pos)          /*!< ADC convert complete flag */

#define ADC_ADSTA_AWDIF_Pos             (1)
#define ADC_ADSTA_AWDIF                 (0x01U << ADC_ADSTA_AWDIF_Pos)          /*!< ADC compare flag */

#define ADC_ADSTA_BUSY_Pos              (2)
#define ADC_ADSTA_BUSY                  (0x01U << ADC_ADSTA_BUSY_Pos)           /*!< ADC busy flag */
#define ADC_ADSTA_CHANNEL_Pos           (4)
#define ADC_ADSTA_CHANNEL               (0x0FU << ADC_ADSTA_CHANNEL_Pos)        /*!< CHANNEL[7:4] ADC current channel */
#define ADC_ADSTA_CHANNEL_0             (0x00U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 0 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_1             (0x01U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 1 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_2             (0x02U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 2 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_3             (0x03U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 3 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_4             (0x04U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 4 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_5             (0x05U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 5 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_6             (0x06U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 6 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_7             (0x07U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 7 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_8             (0x08U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 8 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_9             (0x09U << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 9 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_10            (0x0AU << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 10 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_11            (0x0BU << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 11 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_12            (0x0CU << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 12 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_13            (0x0DU << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 13 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_14            (0x0EU << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 14 is the current conversion channel */
#define ADC_ADSTA_CHANNEL_15            (0x0FU << ADC_ADSTA_CHANNEL_Pos)        /*!< Channel 15 is the current conversion channel */
#define ADC_ADSTA_CHT                   ADC_ADSTA_CCHEN_14
#define ADC_ADSTA_CHV                   ADC_ADSTA_CCHEN_15

#define ADC_ADSTA_VALID_Pos             (8)
#define ADC_ADSTA_VALID                 (0x0FFFU << ADC_ADSTA_VALID_Pos)        /*!< VALID[19:8] ADC channel 0..11 valid flag */
#define ADC_ADSTA_OVERRUN_Pos           (20)
#define ADC_ADSTA_OVERRUN               (0x0FFFU << ADC_ADSTA_OVERRUN_Pos)      /*!< OVERRUN[31:20] ADC channel 0..11 data covered flag */

/**
  * @brief ADC_ADDRn Register Bit Definition
  */
#define ADC_ADDR_DATA_Pos               (0)
#define ADC_ADDR_DATA                   (0xFFFFU << ADC_ADDR_DATA_Pos)          /*!< ADC channel convert data */
#define ADC_ADDR_OVERRUN_Pos            (20)
#define ADC_ADDR_OVERRUN                (0x01U << ADC_ADDR_OVERRUN_Pos)         /*!< ADC data covered flag */
#define ADC_ADDR_VALID_Pos              (21)
#define ADC_ADDR_VALID                  (0x01U << ADC_ADDR_VALID_Pos)           /*!< ADC data valid flag */

/**
  * @brief ADC_ADDSTA_EXT Register Bit Definition
  */
#define ADC_ADDSTA_EXT_VALID_Pos        (0)
#define ADC_ADDSTA_EXT_VALID            (0x0FU << ADC_ADDSTA_EXT_VALID_Pos)     /*!< VALID[3:0] ADC channel 12,14..15 valid flag */
#define ADC_ADDSTA_EXT_VALID_CH12       (0x01U << ADC_ADDSTA_EXT_VALID_Pos)     /*!< channel 12 */
#define ADC_ADDSTA_EXT_VALID_CH13       (0x02U << ADC_ADDSTA_EXT_VALID_Pos)     /*!< channel 13 */
#define ADC_ADDSTA_EXT_VALID_CH14       (0x04U << ADC_ADDSTA_EXT_VALID_Pos)     /*!< channel 14  T_SENSOR */
#define ADC_ADDSTA_EXT_VALID_CH15       (0x08U << ADC_ADDSTA_EXT_VALID_Pos)     /*!< channel 15  V_SENSOR */

#define ADC_ADDSTA_EXT_OVERRUN_Pos      (4)
#define ADC_ADDSTA_EXT_OVERRUN          (0x0FU << ADC_ADDSTA_EXT_OVERRUN_Pos)   /*!< OVERRUN[7:4] ADC channel 12,14..15 data covered flag */
#define ADC_ADDSTA_EXT_OVERRUN_CH12     (0x01U << ADC_ADDSTA_EXT_OVERRUN_Pos)   /*!< channel 12 */
#define ADC_ADDSTA_EXT_OVERRUN_CH13     (0x02U << ADC_ADDSTA_EXT_OVERRUN_Pos)   /*!< channel 13 */
#define ADC_ADDSTA_EXT_OVERRUN_CH14     (0x04U << ADC_ADDSTA_EXT_OVERRUN_Pos)   /*!< channel 14  T_SENSOR */
#define ADC_ADDSTA_EXT_OVERRUN_CH15     (0x08U << ADC_ADDSTA_EXT_OVERRUN_Pos)   /*!< channel 15  V_SENSOR */

#define ADC_ADDSTA_EXT_EOSMPIF_Pos      (16)
#define ADC_ADDSTA_EXT_EOSMPIF          (0x01U << ADC_ADDSTA_EXT_EOSMPIF_Pos)   /*!< End of sampling interrupt flag */
#define ADC_ADDSTA_EXT_EOCIF_Pos        (17)
#define ADC_ADDSTA_EXT_EOCIF            (0x01U << ADC_ADDSTA_EXT_EOCIF_Pos)     /*!< End of conversion interrupt flag */
#define ADC_ADDSTA_EXT_JEOSMPIF_Pos     (18)
#define ADC_ADDSTA_EXT_JEOSMPIF         (0x01U << ADC_ADDSTA_EXT_JEOSMPIF_Pos)  /*!< Injected channel end of sampling interrupt flag */
#define ADC_ADDSTA_EXT_JEOCIF_Pos       (19)
#define ADC_ADDSTA_EXT_JEOCIF           (0x01U << ADC_ADDSTA_EXT_JEOCIF_Pos)    /*!< Injected channel end of conversion interrupt flag */
#define ADC_ADDSTA_EXT_JEOSIF_Pos       (20)
#define ADC_ADDSTA_EXT_JEOSIF           (0x01U << ADC_ADDSTA_EXT_JEOSIF_Pos)    /*!< Injected channel end of sequential conversion interrupt flag */
#define ADC_ADDSTA_EXT_JBUSY_Pos        (21)
#define ADC_ADDSTA_EXT_JBUSY            (0x01U << ADC_ADDSTA_EXT_JBUSY_Pos)     /*!< Injection mode busy/idle */

/**
  * @brief ADC_CHANY0 select Register Bit Definition
  */
#define ADC_CHANY0_SEL0_Pos             (0)                                     /*!< CHANY_SEL0 (Bit 0) */
#define ADC_CHANY0_SEL0                 (0x0FU << ADC_CHANY0_SEL0_Pos)          /*!< CHANY_SEL0 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL1_Pos             (4)                                     /*!< CHANY_SEL1 (Bit 4) */
#define ADC_CHANY0_SEL1                 (0x0FU << ADC_CHANY0_SEL1_Pos)          /*!< CHANY_SEL1 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL2_Pos             (8)                                     /*!< CHANY_SEL2 (Bit 8) */
#define ADC_CHANY0_SEL2                 (0x0FU << ADC_CHANY0_SEL2_Pos)          /*!< CHANY_SEL2 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL3_Pos             (12)                                    /*!< CHANY_SEL3 (Bit 12) */
#define ADC_CHANY0_SEL3                 (0x0FU << ADC_CHANY0_SEL3_Pos)          /*!< CHANY_SEL3 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL4_Pos             (16)                                    /*!< CHANY_SEL4 (Bit 16) */
#define ADC_CHANY0_SEL4                 (0x0FU << ADC_CHANY0_SEL4_Pos)          /*!< CHANY_SEL4 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL5_Pos             (20)                                    /*!< CHANY_SEL5 (Bit 20) */
#define ADC_CHANY0_SEL5                 (0x0FU << ADC_CHANY0_SEL5_Pos)          /*!< CHANY_SEL5 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL6_Pos             (24)                                    /*!< CHANY_SEL6 (Bit 24) */
#define ADC_CHANY0_SEL6                 (0x0FU << ADC_CHANY0_SEL6_Pos)          /*!< CHANY_SEL6 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL7_Pos             (28)                                    /*!< CHANY_SEL7 (Bit 28) */
#define ADC_CHANY0_SEL7                 (0x0FU << ADC_CHANY0_SEL7_Pos)          /*!< CHANY_SEL7 (Bitfield-Mask: 0x0f) */

/**
  * @brief ADC_CHANY1 select Register Bit Definition
  */
#define ADC_CHANY1_SEL8_Pos             (0)                                     /*!< CHANY_SEL8 (Bit 0) */
#define ADC_CHANY1_SEL8                 (0x0FU << ADC_CHANY1_SEL8_Pos)          /*!< CHANY_SEL8 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL9_Pos             (4)                                     /*!< CHANY_SEL9 (Bit 4) */
#define ADC_CHANY1_SEL9                 (0x0FU << ADC_CHANY1_SEL9_Pos)          /*!< CHANY_SEL9 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL10_Pos            (8)                                     /*!< CHANY_SEL10 (Bit 8) */
#define ADC_CHANY1_SEL10                (0x0FU << ADC_CHANY1_SEL10_Pos)         /*!< CHANY_SEL10 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL11_Pos            (12)                                    /*!< CHANY_SEL11 (Bit 12) */
#define ADC_CHANY1_SEL11                (0x0FU << ADC_CHANY1_SEL11_Pos)         /*!< CHANY_SEL11 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL12_Pos            (16)                                    /*!< CHANY_SEL12 (Bit 16) */
#define ADC_CHANY1_SEL12                (0x0FU << ADC_CHANY1_SEL12_Pos)         /*!< CHANY_SEL12 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL13_Pos            (20)                                    /*!< CHANY_SEL13 (Bit 20) */
#define ADC_CHANY1_SEL13                (0x0FU << ADC_CHANY1_SEL13_Pos)         /*!< CHANY_SEL13 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL14_Pos            (24)                                    /*!< CHANY_SEL14 (Bit 24) */
#define ADC_CHANY1_SEL14                (0x0FU << ADC_CHANY1_SEL14_Pos)         /*!< CHANY_SEL14 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL15_Pos            (28)                                    /*!< CHANY_SEL15 (Bit 28) */
#define ADC_CHANY1_SEL15                (0x0FU << ADC_CHANY1_SEL15_Pos)         /*!< CHANY_SEL15 (Bitfield-Mask: 0x0f) */


/**
  * @brief ADC_ANY_CFG config number Register Bit Definition
  */
#define ADC_ANY_CFG_CHANY_NUM_Pos       (0)                                     /*!< CHANY_CFG_NUM Pos */
#define ADC_ANY_CFG_CHANY_NUM           (0x0FU << ADC_ANY_CFG_CHANY_NUM_Pos)    /*!< CHANY_CFG_NUM (Bitfield-Mask: 0x0f) */

/**
  * @brief ADC_ANY_CR mode enable Register Bit Definition
  */
#define ADC_ANY_CR_CHANY_MDEN_Pos       (0)                                     /*!< CHANY_MDEN (Bit 0) */
#define ADC_ANY_CR_CHANY_MDEN           (0x01U << ADC_ANY_CR_CHANY_MDEN_Pos)    /*!< CHANY_MDEN (Bitfield-Mask: 0x01) */
#define ADC_ANY_CR_JCEN_Pos             (1)
#define ADC_ANY_CR_JCEN                 (0x01U << ADC_ANY_CR_JCEN_Pos)          /*!< Injected channel enable */
#define ADC_ANY_CR_JEOSMPIE_Pos         (2)
#define ADC_ANY_CR_JEOSMPIE             (0x01U << ADC_ANY_CR_JEOSMPIE_Pos)      /*!< Interrupt enable the end of sequence conversion for injected channel */
#define ADC_ANY_CR_JEOCIE_Pos           (3)
#define ADC_ANY_CR_JEOCIE               (0x01U << ADC_ANY_CR_JEOCIE_Pos)        /*!< Interrupt enable the end of conversion for injected channel */
#define ADC_ANY_CR_JEOSIE_Pos           (4)
#define ADC_ANY_CR_JEOSIE               (0x01U << ADC_ANY_CR_JEOSIE_Pos)        /*!< Interrupt enable the end of sequence conversion for injected channel */
#define ADC_ANY_CR_JAUTO_Pos            (5)
#define ADC_ANY_CR_JAUTO                (0x01U << ADC_ANY_CR_JAUTO_Pos)         /*!<Automatic Injected group conversion */
#define ADC_ANY_CR_JADST_Pos            (6)
#define ADC_ANY_CR_JADST                (0x01U << ADC_ANY_CR_JADST_Pos)         /*!< Start conversion of injected channels */
#define ADC_ANY_CR_JTRGEN_Pos           (7)
#define ADC_ANY_CR_JTRGEN               (0x01U << ADC_ANY_CR_JTRGEN_Pos)        /*!< External trigger conversion mode for injected channels */

#define ADC_ANY_CR_JTRGSEL_Pos          (8)
#define ADC_ANY_CR_JTRGSEL              (0x1FU << ADC_ANY_CR_JTRGSEL_Pos)       /*!< External event select for injected group */
#define ADC_ANY_CR_JTRGSEL_TIM1_CC1     (0x00U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1  CC1 */
#define ADC_ANY_CR_JTRGSEL_TIM1_CC2     (0x01U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1  CC2 */
#define ADC_ANY_CR_JTRGSEL_TIM1_CC3     (0x02U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1  CC3 */
#define ADC_ANY_CR_JTRGSEL_TIM2_CC2     (0x03U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM2  CC2 */
#define ADC_ANY_CR_JTRGSEL_TIM3_TRGO    (0x04U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM3  TRGO */
#define ADC_ANY_CR_JTRGSEL_TIM1_CC4_CC5 (0x05U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1  CC4 CC5 */
#define ADC_ANY_CR_JTRGSEL_TIM3_CC1     (0x06U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM3  CC1 */
#define ADC_ANY_CR_JTRGSEL_EXTI11       (0x07U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< EXTI11 */
#define ADC_ANY_CR_JTRGSEL_TIM1_TRGO    (0x08U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1  TRGO */
#define ADC_ANY_CR_JTRGSEL_EXTI4        (0x09U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< EXTI 4 */
#define ADC_ANY_CR_JTRGSEL_EXTI5        (0x0AU << ADC_ANY_CR_JTRGSEL_Pos)       /*!< EXTI 5 */
#define ADC_ANY_CR_JTRGSEL_TIM2_CC1     (0x0BU << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM2  CC1 */
#define ADC_ANY_CR_JTRGSEL_TIM3_CC4     (0x0CU << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM3  CC4 */
#define ADC_ANY_CR_JTRGSEL_TIM2_TRGO    (0x0DU << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM2 TRGO */
#define ADC_ANY_CR_JTRGSEL_EXTI15       (0x0FU << ADC_ANY_CR_JTRGSEL_Pos)       /*!< EXTI15 */
#define ADC_ANY_CR_JTRGSEL_TIM1_CC4     (0x10U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1_CC4 */
#define ADC_ANY_CR_JTRGSEL_TIM1_CC5     (0x11U << ADC_ANY_CR_JTRGSEL_Pos)       /*!< TIM1_CC5 */

#define ADC_ANY_CR_JTRGSHIFT_Pos        (13)
#define ADC_ANY_CR_JTRGSHIFT            (0x07U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< select the sample time of corresponding channel */
#define ADC_ANY_CR_JTRGSHIFT_0          (0x00U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 0   cycle */
#define ADC_ANY_CR_JTRGSHIFT_4          (0x01U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 4   cycle */
#define ADC_ANY_CR_JTRGSHIFT_16         (0x02U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 16  cycle */
#define ADC_ANY_CR_JTRGSHIFT_32         (0x03U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 32  cycle */
#define ADC_ANY_CR_JTRGSHIFT_64         (0x04U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 64  cycle */
#define ADC_ANY_CR_JTRGSHIFT_128        (0x05U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 128 cycle */
#define ADC_ANY_CR_JTRGSHIFT_256        (0x06U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 256 cycle */
#define ADC_ANY_CR_JTRGSHIFT_512        (0x07U << ADC_ANY_CR_JTRGSHIFT_Pos)     /*!< 512 cycle */

#define ADC_ANY_CR_JTRGEDGE_Pos         (16)
#define ADC_ANY_CR_JTRGEDGE             (0x03U << ADC_ANY_CR_JTRGEDGE_Pos)      /*!< Injection mode triggers edge selection */
#define ADC_ANY_CR_JTRGEDGE_R_F         (0x00U << ADC_ANY_CR_JTRGEDGE_Pos)      /*!< Triggered along both rising and falling edges */
#define ADC_ANY_CR_JTRGEDGE_F           (0x01U << ADC_ANY_CR_JTRGEDGE_Pos)      /*!< Drop edge trigger */
#define ADC_ANY_CR_JTRGEDGE_R           (0x02U << ADC_ANY_CR_JTRGEDGE_Pos)      /*!< Rising edge trigger */
#define ADC_ANY_CR_JTRGEDGE_S           (0x03U << ADC_ANY_CR_JTRGEDGE_Pos)      /*!< Shield trigger */

/**
  * @brief ADC_SMPR1 mode enable Register Bit Definition
  */

#define ADC_SMPR_SAMP_Pos               (0)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR_SAMP                   (0x0FU << ADC_SMPR_SAMP_Pos)            /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR_SAMP_SEL_0             (0x00U << ADC_SMPR_SAMP_Pos)            /*!< 2.5    cycle */
#define ADC_SMPR_SAMP_SEL_1             (0x01U << ADC_SMPR_SAMP_Pos)            /*!< 8.5    cycle */
#define ADC_SMPR_SAMP_SEL_2             (0x02U << ADC_SMPR_SAMP_Pos)            /*!< 14.5   cycle */
#define ADC_SMPR_SAMP_SEL_3             (0x03U << ADC_SMPR_SAMP_Pos)            /*!< 29.5   cycle */
#define ADC_SMPR_SAMP_SEL_4             (0x04U << ADC_SMPR_SAMP_Pos)            /*!< 42.5   cycle */
#define ADC_SMPR_SAMP_SEL_5             (0x05U << ADC_SMPR_SAMP_Pos)            /*!< 56.5   cycle */
#define ADC_SMPR_SAMP_SEL_6             (0x06U << ADC_SMPR_SAMP_Pos)            /*!< 72.5   cycle */
#define ADC_SMPR_SAMP_SEL_7             (0x07U << ADC_SMPR_SAMP_Pos)            /*!< 240.5  cycle */
#define ADC_SMPR_SAMP_SEL_8             (0x08U << ADC_SMPR_SAMP_Pos)            /*!< 3.5    cycle */
#define ADC_SMPR_SAMP_SEL_9             (0x09U << ADC_SMPR_SAMP_Pos)            /*!< 4.5    cycle */
#define ADC_SMPR_SAMP_SEL_10            (0x0AU << ADC_SMPR_SAMP_Pos)            /*!< 5.5    cycle */
#define ADC_SMPR_SAMP_SEL_11            (0x0BU << ADC_SMPR_SAMP_Pos)            /*!< 6.5    cycle */
#define ADC_SMPR_SAMP_SEL_12            (0x0CU << ADC_SMPR_SAMP_Pos)            /*!< 7.5    cycle */

#define ADC_SMPR_SAMP_2_5               (0x00U << ADC_SMPR_SAMP_Pos)            /*!< 2.5    cycle */
#define ADC_SMPR_SAMP_8_5               (0x01U << ADC_SMPR_SAMP_Pos)            /*!< 8.5    cycle */
#define ADC_SMPR_SAMP_14_5              (0x02U << ADC_SMPR_SAMP_Pos)            /*!< 14.5   cycle */
#define ADC_SMPR_SAMP_29_5              (0x03U << ADC_SMPR_SAMP_Pos)            /*!< 29.5   cycle */
#define ADC_SMPR_SAMP_42_5              (0x04U << ADC_SMPR_SAMP_Pos)            /*!< 42.5   cycle */
#define ADC_SMPR_SAMP_56_5              (0x05U << ADC_SMPR_SAMP_Pos)            /*!< 56.5   cycle */
#define ADC_SMPR_SAMP_72_5              (0x06U << ADC_SMPR_SAMP_Pos)            /*!< 72.5   cycle */
#define ADC_SMPR_SAMP_240_5             (0x07U << ADC_SMPR_SAMP_Pos)            /*!< 240.5  cycle */
#define ADC_SMPR_SAMP_3_5               (0x08U << ADC_SMPR_SAMP_Pos)            /*!< 3.5    cycle */
#define ADC_SMPR_SAMP_4_5               (0x09U << ADC_SMPR_SAMP_Pos)            /*!< 4.5    cycle */
#define ADC_SMPR_SAMP_5_5               (0x0AU << ADC_SMPR_SAMP_Pos)            /*!< 5.5    cycle */
#define ADC_SMPR_SAMP_6_5               (0x0BU << ADC_SMPR_SAMP_Pos)            /*!< 6.5    cycle */
#define ADC_SMPR_SAMP_7_5               (0x0CU << ADC_SMPR_SAMP_Pos)            /*!< 7.5    cycle */

#define ADC_SMPR_SAMP_Pos_ShiftStep     (4)

#define ADC_SMPR1_SAMP0_Pos             (0)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP0_Msk             (0x0FU << ADC_SMPR1_SAMP0_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP0_2_5             (0x00U << ADC_SMPR1_SAMP0_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP0_8_5             (0x01U << ADC_SMPR1_SAMP0_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP0_14_5            (0x02U << ADC_SMPR1_SAMP0_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP0_29_5            (0x03U << ADC_SMPR1_SAMP0_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP0_42_5            (0x04U << ADC_SMPR1_SAMP0_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP0_56_5            (0x05U << ADC_SMPR1_SAMP0_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP0_72_5            (0x06U << ADC_SMPR1_SAMP0_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP0_240_5           (0x07U << ADC_SMPR1_SAMP0_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP0_3_5             (0x08U << ADC_SMPR1_SAMP0_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP0_4_5             (0x09U << ADC_SMPR1_SAMP0_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP0_5_5             (0x0AU << ADC_SMPR1_SAMP0_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP0_6_5             (0x0BU << ADC_SMPR1_SAMP0_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP0_7_5             (0x0CU << ADC_SMPR1_SAMP0_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP1_Pos             (4)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP1_Msk             (0x0FU << ADC_SMPR1_SAMP1_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP1_2_5             (0x00U << ADC_SMPR1_SAMP1_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP1_8_5             (0x01U << ADC_SMPR1_SAMP1_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP1_14_5            (0x02U << ADC_SMPR1_SAMP1_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP1_29_5            (0x03U << ADC_SMPR1_SAMP1_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP1_42_5            (0x04U << ADC_SMPR1_SAMP1_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP1_56_5            (0x05U << ADC_SMPR1_SAMP1_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP1_72_5            (0x06U << ADC_SMPR1_SAMP1_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP1_240_5           (0x07U << ADC_SMPR1_SAMP1_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP1_3_5             (0x08U << ADC_SMPR1_SAMP1_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP1_4_5             (0x09U << ADC_SMPR1_SAMP1_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP1_5_5             (0x0AU << ADC_SMPR1_SAMP1_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP1_6_5             (0x0BU << ADC_SMPR1_SAMP1_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP1_7_5             (0x0CU << ADC_SMPR1_SAMP1_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP2_Pos             (8)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP2_Msk             (0x0FU << ADC_SMPR1_SAMP2_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP2_2_5             (0x00U << ADC_SMPR1_SAMP2_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP2_8_5             (0x01U << ADC_SMPR1_SAMP2_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP2_14_5            (0x02U << ADC_SMPR1_SAMP2_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP2_29_5            (0x03U << ADC_SMPR1_SAMP2_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP2_42_5            (0x04U << ADC_SMPR1_SAMP2_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP2_56_5            (0x05U << ADC_SMPR1_SAMP2_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP2_72_5            (0x06U << ADC_SMPR1_SAMP2_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP2_240_5           (0x07U << ADC_SMPR1_SAMP2_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP2_3_5             (0x08U << ADC_SMPR1_SAMP2_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP2_4_5             (0x09U << ADC_SMPR1_SAMP2_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP2_5_5             (0x0AU << ADC_SMPR1_SAMP2_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP2_6_5             (0x0BU << ADC_SMPR1_SAMP2_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP2_7_5             (0x0CU << ADC_SMPR1_SAMP2_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP3_Pos             (12)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP3_Msk             (0x0FU << ADC_SMPR1_SAMP3_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP3_2_5             (0x00U << ADC_SMPR1_SAMP3_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP3_8_5             (0x01U << ADC_SMPR1_SAMP3_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP3_14_5            (0x02U << ADC_SMPR1_SAMP3_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP3_29_5            (0x03U << ADC_SMPR1_SAMP3_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP3_42_5            (0x04U << ADC_SMPR1_SAMP3_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP3_56_5            (0x05U << ADC_SMPR1_SAMP3_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP3_72_5            (0x06U << ADC_SMPR1_SAMP3_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP3_240_5           (0x07U << ADC_SMPR1_SAMP3_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP3_3_5             (0x08U << ADC_SMPR1_SAMP3_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP3_4_5             (0x09U << ADC_SMPR1_SAMP3_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP3_5_5             (0x0AU << ADC_SMPR1_SAMP3_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP3_6_5             (0x0BU << ADC_SMPR1_SAMP3_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP3_7_5             (0x0CU << ADC_SMPR1_SAMP3_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP4_Pos             (16)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP4_Msk             (0x0FU << ADC_SMPR1_SAMP4_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP4_2_5             (0x00U << ADC_SMPR1_SAMP4_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP4_8_5             (0x01U << ADC_SMPR1_SAMP4_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP4_14_5            (0x02U << ADC_SMPR1_SAMP4_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP4_29_5            (0x03U << ADC_SMPR1_SAMP4_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP4_42_5            (0x04U << ADC_SMPR1_SAMP4_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP4_56_5            (0x05U << ADC_SMPR1_SAMP4_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP4_72_5            (0x06U << ADC_SMPR1_SAMP4_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP4_240_5           (0x07U << ADC_SMPR1_SAMP4_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP4_3_5             (0x08U << ADC_SMPR1_SAMP4_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP4_4_5             (0x09U << ADC_SMPR1_SAMP4_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP4_5_5             (0x0AU << ADC_SMPR1_SAMP4_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP4_6_5             (0x0BU << ADC_SMPR1_SAMP4_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP4_7_5             (0x0CU << ADC_SMPR1_SAMP4_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP5_Pos             (20)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP5_Msk             (0x0FU << ADC_SMPR1_SAMP5_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP5_2_5             (0x00U << ADC_SMPR1_SAMP5_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP5_8_5             (0x01U << ADC_SMPR1_SAMP5_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP5_14_5            (0x02U << ADC_SMPR1_SAMP5_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP5_29_5            (0x03U << ADC_SMPR1_SAMP5_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP5_42_5            (0x04U << ADC_SMPR1_SAMP5_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP5_56_5            (0x05U << ADC_SMPR1_SAMP5_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP5_72_5            (0x06U << ADC_SMPR1_SAMP5_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP5_240_5           (0x07U << ADC_SMPR1_SAMP5_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP5_3_5             (0x08U << ADC_SMPR1_SAMP5_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP5_4_5             (0x09U << ADC_SMPR1_SAMP5_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP5_5_5             (0x0AU << ADC_SMPR1_SAMP5_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP5_6_5             (0x0BU << ADC_SMPR1_SAMP5_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP5_7_5             (0x0CU << ADC_SMPR1_SAMP5_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP6_Pos             (24)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP6_Msk             (0x0FU << ADC_SMPR1_SAMP6_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP6_2_5             (0x00U << ADC_SMPR1_SAMP6_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP6_8_5             (0x01U << ADC_SMPR1_SAMP6_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP6_14_5            (0x02U << ADC_SMPR1_SAMP6_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP6_29_5            (0x03U << ADC_SMPR1_SAMP6_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP6_42_5            (0x04U << ADC_SMPR1_SAMP6_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP6_56_5            (0x05U << ADC_SMPR1_SAMP6_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP6_72_5            (0x06U << ADC_SMPR1_SAMP6_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP6_240_5           (0x07U << ADC_SMPR1_SAMP6_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP6_3_5             (0x08U << ADC_SMPR1_SAMP6_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP6_4_5             (0x09U << ADC_SMPR1_SAMP6_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP6_5_5             (0x0AU << ADC_SMPR1_SAMP6_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP6_6_5             (0x0BU << ADC_SMPR1_SAMP6_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP6_7_5             (0x0CU << ADC_SMPR1_SAMP6_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR1_SAMP7_Pos             (28)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR1_SAMP7_Msk             (0x0FU << ADC_SMPR1_SAMP7_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR1_SAMP7_2_5             (0x00U << ADC_SMPR1_SAMP7_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR1_SAMP7_8_5             (0x01U << ADC_SMPR1_SAMP7_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR1_SAMP7_14_5            (0x02U << ADC_SMPR1_SAMP7_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR1_SAMP7_29_5            (0x03U << ADC_SMPR1_SAMP7_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR1_SAMP7_42_5            (0x04U << ADC_SMPR1_SAMP7_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR1_SAMP7_56_5            (0x05U << ADC_SMPR1_SAMP7_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR1_SAMP7_72_5            (0x06U << ADC_SMPR1_SAMP7_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR1_SAMP7_240_5           (0x07U << ADC_SMPR1_SAMP7_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR1_SAMP7_3_5             (0x08U << ADC_SMPR1_SAMP7_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR1_SAMP7_4_5             (0x09U << ADC_SMPR1_SAMP7_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR1_SAMP7_5_5             (0x0AU << ADC_SMPR1_SAMP7_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR1_SAMP7_6_5             (0x0BU << ADC_SMPR1_SAMP7_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR1_SAMP7_7_5             (0x0CU << ADC_SMPR1_SAMP7_Pos)          /*!< 7.5    cycle */

/**
  * @brief ADC_SMPR2 mode enable Register Bit Definition
  */
#define ADC_SMPR2_SAMP8_Pos             (0)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP8_Msk             (0x0FU << ADC_SMPR2_SAMP8_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP8_2_5             (0x00U << ADC_SMPR2_SAMP8_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP8_8_5             (0x01U << ADC_SMPR2_SAMP8_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP8_14_5            (0x02U << ADC_SMPR2_SAMP8_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP8_29_5            (0x03U << ADC_SMPR2_SAMP8_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP8_42_5            (0x04U << ADC_SMPR2_SAMP8_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP8_56_5            (0x05U << ADC_SMPR2_SAMP8_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP8_72_5            (0x06U << ADC_SMPR2_SAMP8_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP8_240_5           (0x07U << ADC_SMPR2_SAMP8_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP8_3_5             (0x08U << ADC_SMPR2_SAMP8_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP8_4_5             (0x09U << ADC_SMPR2_SAMP8_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP8_5_5             (0x0AU << ADC_SMPR2_SAMP8_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP8_6_5             (0x0BU << ADC_SMPR2_SAMP8_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP8_7_5             (0x0CU << ADC_SMPR2_SAMP8_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP9_Pos             (4)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP9_Msk             (0x0FU << ADC_SMPR2_SAMP9_Pos)          /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP9_2_5             (0x00U << ADC_SMPR2_SAMP9_Pos)          /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP9_8_5             (0x01U << ADC_SMPR2_SAMP9_Pos)          /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP9_14_5            (0x02U << ADC_SMPR2_SAMP9_Pos)          /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP9_29_5            (0x03U << ADC_SMPR2_SAMP9_Pos)          /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP9_42_5            (0x04U << ADC_SMPR2_SAMP9_Pos)          /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP9_56_5            (0x05U << ADC_SMPR2_SAMP9_Pos)          /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP9_72_5            (0x06U << ADC_SMPR2_SAMP9_Pos)          /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP9_240_5           (0x07U << ADC_SMPR2_SAMP9_Pos)          /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP9_3_5             (0x08U << ADC_SMPR2_SAMP9_Pos)          /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP9_4_5             (0x09U << ADC_SMPR2_SAMP9_Pos)          /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP9_5_5             (0x0AU << ADC_SMPR2_SAMP9_Pos)          /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP9_6_5             (0x0BU << ADC_SMPR2_SAMP9_Pos)          /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP9_7_5             (0x0CU << ADC_SMPR2_SAMP9_Pos)          /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP10_Pos            (8)                                     /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP10_Msk            (0x0FU << ADC_SMPR2_SAMP10_Pos)         /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP10_2_5            (0x00U << ADC_SMPR2_SAMP10_Pos)         /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP10_8_5            (0x01U << ADC_SMPR2_SAMP10_Pos)         /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP10_14_5           (0x02U << ADC_SMPR2_SAMP10_Pos)         /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP10_29_5           (0x03U << ADC_SMPR2_SAMP10_Pos)         /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP10_42_5           (0x04U << ADC_SMPR2_SAMP10_Pos)         /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP10_56_5           (0x05U << ADC_SMPR2_SAMP10_Pos)         /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP10_72_5           (0x06U << ADC_SMPR2_SAMP10_Pos)         /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP10_240_5          (0x07U << ADC_SMPR2_SAMP10_Pos)         /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP10_3_5            (0x08U << ADC_SMPR2_SAMP10_Pos)         /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP10_4_5            (0x09U << ADC_SMPR2_SAMP10_Pos)         /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP10_5_5            (0x0AU << ADC_SMPR2_SAMP10_Pos)         /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP10_6_5            (0x0BU << ADC_SMPR2_SAMP10_Pos)         /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP10_7_5            (0x0CU << ADC_SMPR2_SAMP10_Pos)         /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP11_Pos            (12)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP11_Msk            (0x0FU << ADC_SMPR2_SAMP11_Pos)         /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP11_2_5            (0x00U << ADC_SMPR2_SAMP11_Pos)         /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP11_8_5            (0x01U << ADC_SMPR2_SAMP11_Pos)         /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP11_14_5           (0x02U << ADC_SMPR2_SAMP11_Pos)         /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP11_29_5           (0x03U << ADC_SMPR2_SAMP11_Pos)         /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP11_42_5           (0x04U << ADC_SMPR2_SAMP11_Pos)         /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP11_56_5           (0x05U << ADC_SMPR2_SAMP11_Pos)         /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP11_72_5           (0x06U << ADC_SMPR2_SAMP11_Pos)         /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP11_240_5          (0x07U << ADC_SMPR2_SAMP11_Pos)         /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP11_3_5            (0x08U << ADC_SMPR2_SAMP11_Pos)         /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP11_4_5            (0x09U << ADC_SMPR2_SAMP11_Pos)         /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP11_5_5            (0x0AU << ADC_SMPR2_SAMP11_Pos)         /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP11_6_5            (0x0BU << ADC_SMPR2_SAMP11_Pos)         /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP11_7_5            (0x0CU << ADC_SMPR2_SAMP11_Pos)         /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP12_Pos            (16)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP12_Msk            (0x0FU << ADC_SMPR2_SAMP12_Pos)         /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP12_2_5            (0x00U << ADC_SMPR2_SAMP12_Pos)         /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP12_8_5            (0x01U << ADC_SMPR2_SAMP12_Pos)         /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP12_14_5           (0x02U << ADC_SMPR2_SAMP12_Pos)         /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP12_29_5           (0x03U << ADC_SMPR2_SAMP12_Pos)         /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP12_42_5           (0x04U << ADC_SMPR2_SAMP12_Pos)         /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP12_56_5           (0x05U << ADC_SMPR2_SAMP12_Pos)         /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP12_72_5           (0x06U << ADC_SMPR2_SAMP12_Pos)         /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP12_240_5          (0x07U << ADC_SMPR2_SAMP12_Pos)         /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP12_3_5            (0x08U << ADC_SMPR2_SAMP12_Pos)         /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP12_4_5            (0x09U << ADC_SMPR2_SAMP12_Pos)         /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP12_5_5            (0x0AU << ADC_SMPR2_SAMP12_Pos)         /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP12_6_5            (0x0BU << ADC_SMPR2_SAMP12_Pos)         /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP12_7_5            (0x0CU << ADC_SMPR2_SAMP12_Pos)         /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP13_Pos            (20)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP13_Msk            (0x0FU << ADC_SMPR2_SAMP13_Pos)         /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP13_2_5            (0x00U << ADC_SMPR2_SAMP13_Pos)         /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP13_8_5            (0x01U << ADC_SMPR2_SAMP13_Pos)         /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP13_14_5           (0x02U << ADC_SMPR2_SAMP13_Pos)         /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP13_29_5           (0x03U << ADC_SMPR2_SAMP13_Pos)         /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP13_42_5           (0x04U << ADC_SMPR2_SAMP13_Pos)         /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP13_56_5           (0x05U << ADC_SMPR2_SAMP13_Pos)         /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP13_72_5           (0x06U << ADC_SMPR2_SAMP13_Pos)         /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP13_240_5          (0x07U << ADC_SMPR2_SAMP13_Pos)         /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP13_3_5            (0x08U << ADC_SMPR2_SAMP13_Pos)         /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP13_4_5            (0x09U << ADC_SMPR2_SAMP13_Pos)         /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP13_5_5            (0x0AU << ADC_SMPR2_SAMP13_Pos)         /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP13_6_5            (0x0BU << ADC_SMPR2_SAMP13_Pos)         /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP13_7_5            (0x0CU << ADC_SMPR2_SAMP13_Pos)         /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP14_Pos            (24)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP14_Msk            (0x0FU << ADC_SMPR2_SAMP14_Pos)         /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP14_2_5            (0x00U << ADC_SMPR2_SAMP14_Pos)         /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP14_8_5            (0x01U << ADC_SMPR2_SAMP14_Pos)         /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP14_14_5           (0x02U << ADC_SMPR2_SAMP14_Pos)         /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP14_29_5           (0x03U << ADC_SMPR2_SAMP14_Pos)         /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP14_42_5           (0x04U << ADC_SMPR2_SAMP14_Pos)         /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP14_56_5           (0x05U << ADC_SMPR2_SAMP14_Pos)         /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP14_72_5           (0x06U << ADC_SMPR2_SAMP14_Pos)         /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP14_240_5          (0x07U << ADC_SMPR2_SAMP14_Pos)         /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP14_3_5            (0x08U << ADC_SMPR2_SAMP14_Pos)         /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP14_4_5            (0x09U << ADC_SMPR2_SAMP14_Pos)         /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP14_5_5            (0x0AU << ADC_SMPR2_SAMP14_Pos)         /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP14_6_5            (0x0BU << ADC_SMPR2_SAMP14_Pos)         /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP14_7_5            (0x0CU << ADC_SMPR2_SAMP14_Pos)         /*!< 7.5    cycle */
#define ADC_SMPR2_SAMP15_Pos            (28)                                    /*!< select the sample time of corresponding channel off_set Position */
#define ADC_SMPR2_SAMP15_Msk            (0x0FU << ADC_SMPR2_SAMP15_Pos)         /*!< select the sample time of corresponding channel mask for Value */
#define ADC_SMPR2_SAMP15_2_5            (0x00U << ADC_SMPR2_SAMP15_Pos)         /*!< 2.5    cycle */
#define ADC_SMPR2_SAMP15_8_5            (0x01U << ADC_SMPR2_SAMP15_Pos)         /*!< 8.5    cycle */
#define ADC_SMPR2_SAMP15_14_5           (0x02U << ADC_SMPR2_SAMP15_Pos)         /*!< 14.5   cycle */
#define ADC_SMPR2_SAMP15_29_5           (0x03U << ADC_SMPR2_SAMP15_Pos)         /*!< 29.5   cycle */
#define ADC_SMPR2_SAMP15_42_5           (0x04U << ADC_SMPR2_SAMP15_Pos)         /*!< 42.5   cycle */
#define ADC_SMPR2_SAMP15_56_5           (0x05U << ADC_SMPR2_SAMP15_Pos)         /*!< 56.5   cycle */
#define ADC_SMPR2_SAMP15_72_5           (0x06U << ADC_SMPR2_SAMP15_Pos)         /*!< 72.5   cycle */
#define ADC_SMPR2_SAMP15_240_5          (0x07U << ADC_SMPR2_SAMP15_Pos)         /*!< 240.5  cycle */
#define ADC_SMPR2_SAMP15_3_5            (0x08U << ADC_SMPR2_SAMP15_Pos)         /*!< 3.5    cycle */
#define ADC_SMPR2_SAMP15_4_5            (0x09U << ADC_SMPR2_SAMP15_Pos)         /*!< 4.5    cycle */
#define ADC_SMPR2_SAMP15_5_5            (0x0AU << ADC_SMPR2_SAMP15_Pos)         /*!< 5.5    cycle */
#define ADC_SMPR2_SAMP15_6_5            (0x0BU << ADC_SMPR2_SAMP15_Pos)         /*!< 6.5    cycle */
#define ADC_SMPR2_SAMP15_7_5            (0x0CU << ADC_SMPR2_SAMP15_Pos)         /*!< 7.5    cycle */

/**
  * @brief ADC_JOFR0 mode enable Register Bit Definition
  */
#define ADC_JOFR0_JOFFSET               (0xFFFU)                                /*!< Compensates for the A/D conversion results of the injected channel 0 */
/**
  * @brief ADC_JOFR1 mode enable Register Bit Definition
  */
#define ADC_JOFR1_JOFFSET               (0xFFFU)                                /*!< Compensates for the A/D conversion results of the injected channel 1 */
/**
  * @brief ADC_JOFR2 mode enable Register Bit Definition
  */
#define ADC_JOFR2_JOFFSET               (0xFFFU)                                /*!< Compensates for the A/D conversion results of the injected channel 2 */
/**
  * @brief ADC_JOFR3 mode enable Register Bit Definition
  */
#define ADC_JOFR3_JOFFSET               (0xFFFU)                                /*!< Compensates for the A/D conversion results of the injected channel 3 */
/**
  * @brief ADC_JSQR mode enable Register Bit Definition
  */
#define ADC_JSQR_JSQ0_Pos               (0)                                     /*!< 1st conversion in injected sequence */
#define ADC_JSQR_JSQ0                   (0x1FU << ADC_JSQR_JSQ0_Pos)            /*!< 0th Conversion for Injected Sequence */
#define ADC_JSQR_JSQ0_CH0               (0x00U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 0 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH1               (0x01U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 1 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH2               (0x02U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 2 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH3               (0x03U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 3 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH4               (0x04U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 4 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH5               (0x05U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 5 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH6               (0x06U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 6 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH7               (0x07U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 7 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH8               (0x08U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 8 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH9               (0x09U << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 9 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH10              (0x0AU << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 10 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH11              (0x0BU << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 11 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH12              (0x0CU << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 12 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH13              (0x0DU << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 13 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH14              (0x0EU << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 14 as injection channel 0 */
#define ADC_JSQR_JSQ0_CH15              (0x0FU << ADC_JSQR_JSQ0_Pos)            /*!< Configure any channel 15 as injection channel 0 */
#define ADC_JSQR_JSQ0_0                 (0x01U << ADC_JSQR_JSQ0_Pos)            /*!< Bit 0 */
#define ADC_JSQR_JSQ0_1                 (0x02U << ADC_JSQR_JSQ0_Pos)            /*!< Bit 1 */
#define ADC_JSQR_JSQ0_2                 (0x04U << ADC_JSQR_JSQ0_Pos)            /*!< Bit 2 */
#define ADC_JSQR_JSQ0_3                 (0x08U << ADC_JSQR_JSQ0_Pos)            /*!< Bit 3 */
#define ADC_JSQR_JSQ0_4                 (0x10U << ADC_JSQR_JSQ0_Pos)            /*!< Bit 4 */
#define ADC_JSQR_JSQ1_Pos               (5)                                     /*!< 2st conversion in injected sequence */
#define ADC_JSQR_JSQ1                   (0x1FU << ADC_JSQR_JSQ1_Pos)            /*!< 1th Conversion for Injected Sequence */
#define ADC_JSQR_JSQ1_CH0               (0x00U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 0 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH1               (0x01U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 1 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH2               (0x02U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 2 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH3               (0x03U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 3 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH4               (0x04U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 4 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH5               (0x05U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 5 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH6               (0x06U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 6 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH7               (0x07U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 7 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH8               (0x08U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 8 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH9               (0x09U << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 9 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH10              (0x0AU << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 10 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH11              (0x0BU << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 11 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH12              (0x0CU << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 12 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH13              (0x0DU << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 13 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH14              (0x0EU << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 14 as injection channel 1 */
#define ADC_JSQR_JSQ1_CH15              (0x0FU << ADC_JSQR_JSQ1_Pos)            /*!< Configure any channel 15 as injection channel 1 */
#define ADC_JSQR_JSQ1_0                 (0x01U << ADC_JSQR_JSQ1_Pos)            /*!< Bit 0 */
#define ADC_JSQR_JSQ1_1                 (0x02U << ADC_JSQR_JSQ1_Pos)            /*!< Bit 1 */
#define ADC_JSQR_JSQ1_2                 (0x04U << ADC_JSQR_JSQ1_Pos)            /*!< Bit 2 */
#define ADC_JSQR_JSQ1_3                 (0x08U << ADC_JSQR_JSQ1_Pos)            /*!< Bit 3 */
#define ADC_JSQR_JSQ1_4                 (0x10U << ADC_JSQR_JSQ1_Pos)            /*!< Bit 4 */
#define ADC_JSQR_JSQ2_Pos               (10)                                    /*!< 3st conversion in injected sequence */
#define ADC_JSQR_JSQ2                   (0x1FU << ADC_JSQR_JSQ2_Pos)            /*!< 2th Conversion for Injected Sequence */
#define ADC_JSQR_JSQ2_CH0               (0x00U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 0 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH1               (0x01U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 1 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH2               (0x02U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 2 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH3               (0x03U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 3 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH4               (0x04U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 4 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH5               (0x05U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 5 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH6               (0x06U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 6 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH7               (0x07U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 7 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH8               (0x08U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 8 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH9               (0x09U << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 9 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH10              (0x0AU << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 10 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH11              (0x0BU << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 11 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH12              (0x0CU << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 12 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH13              (0x0DU << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 13 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH14              (0x0EU << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 14 as injection channel 2 */
#define ADC_JSQR_JSQ2_CH15              (0x0FU << ADC_JSQR_JSQ2_Pos)            /*!< Configure any channel 15 as injection channel 2 */
#define ADC_JSQR_JSQ2_0                 (0x01U << ADC_JSQR_JSQ2_Pos)            /*!< Bit 0 */
#define ADC_JSQR_JSQ2_1                 (0x02U << ADC_JSQR_JSQ2_Pos)            /*!< Bit 1 */
#define ADC_JSQR_JSQ2_2                 (0x04U << ADC_JSQR_JSQ2_Pos)            /*!< Bit 2 */
#define ADC_JSQR_JSQ2_3                 (0x08U << ADC_JSQR_JSQ2_Pos)            /*!< Bit 3 */
#define ADC_JSQR_JSQ2_4                 (0x10U << ADC_JSQR_JSQ2_Pos)            /*!< Bit 4 */
#define ADC_JSQR_JSQ3_Pos               (15)                                    /*!< 4st conversion in injected sequence */
#define ADC_JSQR_JSQ3                   (0x1FU << ADC_JSQR_JSQ3_Pos)            /*!< 3th Conversion for Injected Sequence */
#define ADC_JSQR_JSQ3_CH0               (0x00U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 0 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH1               (0x01U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 1 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH2               (0x02U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 2 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH3               (0x03U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 3 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH4               (0x04U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 4 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH5               (0x05U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 5 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH6               (0x06U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 6 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH7               (0x07U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 7 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH8               (0x08U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 8 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH9               (0x09U << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 9 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH10              (0x0AU << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 10 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH11              (0x0BU << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 11 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH12              (0x0CU << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 12 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH13              (0x0DU << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 13 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH14              (0x0EU << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 14 as injection channel 3 */
#define ADC_JSQR_JSQ3_CH15              (0x0FU << ADC_JSQR_JSQ3_Pos)            /*!< Configure any channel 15 as injection channel 3 */
#define ADC_JSQR_JSQ3_0                 (0x01U << ADC_JSQR_JSQ3_Pos)            /*!< Bit 0 */
#define ADC_JSQR_JSQ3_1                 (0x02U << ADC_JSQR_JSQ3_Pos)            /*!< Bit 1 */
#define ADC_JSQR_JSQ3_2                 (0x04U << ADC_JSQR_JSQ3_Pos)            /*!< Bit 2 */
#define ADC_JSQR_JSQ3_3                 (0x08U << ADC_JSQR_JSQ3_Pos)            /*!< Bit 3 */
#define ADC_JSQR_JSQ3_4                 (0x10U << ADC_JSQR_JSQ3_Pos)            /*!< Bit 4 */

#define ADC_JSQR_JNUM_Pos               (20)
#define ADC_JSQR_JNUM                   (0x03U << ADC_JSQR_JNUM_Pos)            /*!< Channel Number for Injected Sequence mask */
#define ADC_JSQR_JNUM_MODE0             (0x00U << ADC_JSQR_JNUM_Pos)            /*!< JSQ0 channel only */
#define ADC_JSQR_JNUM_MODE1             (0x01U << ADC_JSQR_JNUM_Pos)            /*!< JSQ0~JSQ1 channels */
#define ADC_JSQR_JNUM_MODE2             (0x02U << ADC_JSQR_JNUM_Pos)            /*!< JSQ0~JSQ2 channels */
#define ADC_JSQR_JNUM_MODE3             (0x03U << ADC_JSQR_JNUM_Pos)            /*!< JSQ0~JSQ3 channels */
#define ADC_JSQR_JNUM_0                 (0x01U << ADC_JSQR_JNUM_Pos)            /*!< Channel Number for Injected Sequence bit 0 */
#define ADC_JSQR_JNUM_1                 (0x02U << ADC_JSQR_JNUM_Pos)            /*!< Channel Number for Injected Sequence bit 1 */

/**
  * @brief ADC_JDATA mode enable Register Bit Definition
  */
#define ADC_JADDATA_JDATA_Pos           (0)
#define ADC_JADDATA_JDATA               (0xFFFFU << ADC_JADDATA_JDATA_Pos)      /*!< Transfer data */
#define ADC_JADDATA_JCHANNELSEL_Pos     (16)
#define ADC_JADDATA_JCHANNELSEL         (0x1FU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Channel selection */
#define ADC_JADDATA_JCHANNELSEL_CHAN0   (0x00U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 0 */
#define ADC_JADDATA_JCHANNELSEL_CHAN1   (0x01U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 1 */
#define ADC_JADDATA_JCHANNELSEL_CHAN2   (0x02U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 2 */
#define ADC_JADDATA_JCHANNELSEL_CHAN3   (0x03U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 3 */
#define ADC_JADDATA_JCHANNELSEL_CHAN4   (0x04U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 4 */
#define ADC_JADDATA_JCHANNELSEL_CHAN5   (0x05U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 5 */
#define ADC_JADDATA_JCHANNELSEL_CHAN6   (0x06U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 6 */
#define ADC_JADDATA_JCHANNELSEL_CHAN7   (0x07U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 7 */
#define ADC_JADDATA_JCHANNELSEL_CHAN8   (0x08U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 8 */
#define ADC_JADDATA_JCHANNELSEL_CHAN9   (0x09U << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 9 */
#define ADC_JADDATA_JCHANNELSEL_CHAN10  (0x0AU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 10 */
#define ADC_JADDATA_JCHANNELSEL_CHAN11  (0x0BU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 11 */
#define ADC_JADDATA_JCHANNELSEL_CHAN12  (0x0CU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 12 */
#define ADC_JADDATA_JCHANNELSEL_CHAN13  (0x0DU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 13 */
#define ADC_JADDATA_JCHANNELSEL_CHAN14  (0x0EU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 14 */
#define ADC_JADDATA_JCHANNELSEL_CHAN15  (0x0FU << ADC_JADDATA_JCHANNELSEL_Pos)  /*!< Conversion data of channel 15 */

#define ADC_JADDATA_JOVERRUN_Pos        (21)
#define ADC_JADDATA_JOVERRUN            (0x01U << ADC_JADDATA_JOVERRUN_Pos)     /*!< Overrun flag */
#define ADC_JADDATA_JVALID_Pos          (22)
#define ADC_JADDATA_JVALID              (0x01U << ADC_JADDATA_JVALID_Pos)       /*!< Valid flag */

/**
  * @brief ADC_JDR0 mode enable Register Bit Definition
  */
#define ADC_JDR0_JDATA_Pos              (0)
#define ADC_JDR0_JDATA                  (0xFFFFU << ADC_JDR0_JDATA_Pos)         /*!< Transfer data */
#define ADC_JDR0_JOVERRUN_Pos           (21)
#define ADC_JDR0_JOVERRUN               (0x01U << ADC_JDR0_JOVERRUN_Pos)        /*!< Overrun flag */
#define ADC_JDR0_JVALID_Pos             (22)
#define ADC_JDR0_JVALID                 (0x01U << ADC_JDR0_JVALID_Pos)          /*!< Valid flag */

/**
  * @brief ADC_JDR1 mode enable Register Bit Definition
  */
#define ADC_JDR1_JDATA_Pos              (0)
#define ADC_JDR1_JDATA                  (0xFFFFU << ADC_JDR1_JDATA_Pos)         /*!< Transfer data */
#define ADC_JDR1_JOVERRUN_Pos           (21)
#define ADC_JDR1_JOVERRUN               (0x01U << ADC_JDR1_JOVERRUN_Pos)        /*!< Overrun flag */
#define ADC_JDR1_JVALID_Pos             (22)
#define ADC_JDR1_JVALID                 (0x01U << ADC_JDR1_JVALID_Pos)          /*!< Valid flag */

/**
  * @brief ADC_JDR2 mode enable Register Bit Definition
  */
#define ADC_JDR2_JDATA_Pos              (0)
#define ADC_JDR2_JDATA                  (0xFFFFU << ADC_JDR2_JDATA_Pos)         /*!< Transfer data */
#define ADC_JDR2_JOVERRUN_Pos           (21)
#define ADC_JDR2_JOVERRUN               (0x01U << ADC_JDR2_JOVERRUN_Pos)        /*!< Overrun flag */
#define ADC_JDR2_JVALID_Pos             (22)
#define ADC_JDR2_JVALID                 (0x01U << ADC_JDR2_JVALID_Pos)          /*!< Valid flag */

/**
  * @brief ADC_JDR3 mode enable Register Bit Definition
  */
#define ADC_JDR3_JDATA_Pos              (0)
#define ADC_JDR3_JDATA                  (0xFFFFU << ADC_JDR3_JDATA_Pos)         /*!< Transfer data */
#define ADC_JDR3_JOVERRUN_Pos           (21)
#define ADC_JDR3_JOVERRUN               (0x01U << ADC_JDR3_JOVERRUN_Pos)        /*!< Overrun flag */
#define ADC_JDR3_JVALID_Pos             (22)
#define ADC_JDR3_JVALID                 (0x01U << ADC_JDR3_JVALID_Pos)          /*!< Valid flag */

/**
  * @brief ADC_LDATA mode enable Register Bit Definition
  */
#define ADC_LDATA_LDATA_Pos             (0)
#define ADC_LDATA_LDATA                 (0xFFFFU << ADC_LDATA_LDATA_Pos)        /*!< Last Conversion Data */
#define ADC_LDATA_LCHANNELSEL_Pos       (16)
#define ADC_LDATA_LCHANNELSEL           (0x0FU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Last Channel Selection: */
#define ADC_LDATA_LCHANNELSEL_CH0       (0x00U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 1 */
#define ADC_LDATA_LCHANNELSEL_CH1       (0x01U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 2 */
#define ADC_LDATA_LCHANNELSEL_CH2       (0x02U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 3 */
#define ADC_LDATA_LCHANNELSEL_CH3       (0x03U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 4 */
#define ADC_LDATA_LCHANNELSEL_CH4       (0x04U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 5 */
#define ADC_LDATA_LCHANNELSEL_CH5       (0x05U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 6 */
#define ADC_LDATA_LCHANNELSEL_CH6       (0x06U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 7 */
#define ADC_LDATA_LCHANNELSEL_CH7       (0x07U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 8 */
#define ADC_LDATA_LCHANNELSEL_CH8       (0x08U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 9 */
#define ADC_LDATA_LCHANNELSEL_CH9       (0x09U << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 10 */
#define ADC_LDATA_LCHANNELSEL_CH10      (0x0AU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 11 */
#define ADC_LDATA_LCHANNELSEL_CH11      (0x0BU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 12 */
#define ADC_LDATA_LCHANNELSEL_CH12      (0x0CU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 13 */
#define ADC_LDATA_LCHANNELSEL_CH13      (0x0DU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 14 */
#define ADC_LDATA_LCHANNELSEL_CH14      (0x0EU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 15 */
#define ADC_LDATA_LCHANNELSEL_CH15      (0x0FU << ADC_LDATA_LCHANNELSEL_Pos)    /*!< Channel 16 */
#define ADC_LDATA_LOVERRUN_Pos          (20)
#define ADC_LDATA_LOVERRUM              (0x01U << ADC_LDATA_LOVERRUN_Pos)       /*!< Overrun Flag */
#define ADC_LDATA_LVALID_Pos            (21)
#define ADC_LDATA_LVALID                (0x01U << ADC_LDATA_LVALID_Pos)         /*!< Valid Flag */

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
