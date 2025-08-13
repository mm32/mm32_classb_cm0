/***********************************************************************************************************************
    @file     reg_adc.h
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

#ifndef __REG_ADC_H
#define __REG_ADC_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/**
  * @brief ADC Base Address Definition
  */
#define ADC1_BASE                       (APB1PERIPH_BASE + 0x12400) /*!< Base Address: 0x40012400 */
#define ADC_VOLTAGE_REF_BASE            (0x1FFFF7E0U)                           ///< Voltage Reference base address(Half Word)
#define ADC_TEMPERATURE_BASE            (0x1FFFF7F6U)                           ///< Temperature base address(Half Word)
#define ADC_AVG_SLOPE_VALUE             (4.821)                                 ///< Temperature Avg_Slope value
// T(C) = (Vsense - V25) / Avg_Slope + 25
// V25: Vsense value for 25C
// T(C) = (Value * Vdda - offset * 3300) / (4096 * Avg_slope) + 25
// offset = (M16(ADC_TEMPERATURE_BASE)
// Vsense: current output voltage of the temperature sensor
// Vsense = Value * Vdda /4096 (Value is the converted result data of ADC)
// Avg_Slope: Average Slope for curve between Temperature vs. Vsense (given in mV/C or uV/C)
// Refer to the Temperature Sensor section for the actual values of V25 and Avg_Slope.
// Vref Fomula  (VREFoffset/4096) * 3.3V = (Value/4096)* VDDA
// VDDA = (VREFoffset/Value) * 3.3



/**
  * @brief Analog-to-Digital Converter register
  */

typedef struct
{
    __IO uint32_t ADDATA;               /*!< ADC data register,                             offset: 0x00 */
    __IO uint32_t ADCFG;                /*!< ADC configuration register,                    offset: 0x04 */
    __IO uint32_t ADCR;                 /*!< ADC control register,                          offset: 0x08 */
    __IO uint32_t ADCHS;                /*!< ADC channel selection register,                offset: 0x0C */
    __IO uint32_t ADCMPR;               /*!< ADC window compare register,                   offset: 0x10 */
    __IO uint32_t ADSTA;                /*!< ADC status register,                           offset: 0x14 */
    __IO uint32_t ADDR0;                /*!< ADC channel0 data register,                    offset: 0x18 */
    __IO uint32_t ADDR1;                /*!< ADC channel1 data register,                    offset: 0x1C */
    __IO uint32_t ADDR2;                /*!< ADC channel2 data register,                    offset: 0x20 */
    __IO uint32_t ADDR3;                /*!< ADC channel3 data register,                    offset: 0x24 */
    __IO uint32_t ADDR4;                /*!< ADC channel4 data register,                    offset: 0x28 */
    __IO uint32_t ADDR5;                /*!< ADC channel5 data register,                    offset: 0x2C */
    __IO uint32_t ADDR6;                /*!< ADC channel6 data register,                    offset: 0x30 */
    __IO uint32_t ADDR7;                /*!< ADC channel7 data register,                    offset: 0x34 */
    __IO uint32_t ADDR8;                /*!< ADC channel8 data register,                    offset: 0x38 */
    __IO uint32_t ADDR9;                /*!< ADC channel9 data register,                    offset: 0x3C */
    __IO uint32_t ADDR10;               /*!< ADC channel10 data register,                   offset: 0x40 */
    __IO uint32_t RESERVED0x44[5];      /*!< RESERVED                                       offset: 0x44-0x54 */
    __IO uint32_t ADSTA_EXT;            /*!< ADC Extended Status Register,                  offset: 0x58 */
    __IO uint32_t CHANY0;               /*!< ADC any Chan Select Register 0,                offset: 0x5C */
    __IO uint32_t CHANY1;               /*!< ADC any Chan Select Register 1,                offset: 0x60 */
    __IO uint32_t ANY_CFG;              /*!< ADC any Chan config Register,                  offset: 0x64 */
    __IO uint32_t ANY_CR;               /*!< ADC any Chan control Register,                 offset: 0x68 */
    __IO uint32_t RESERVED0x6C;         /*!< RESERVED                                       offset: 0x6C */
    __IO uint32_t SMPR1;                /*!< Sampling configuration register 1              offset: 0x70 */
    __IO uint32_t SMPR2;                /*!< Sampling configuration register 2              offset: 0x74 */
    __IO uint32_t RESERVED0x78;         /*!< RESERVED                                       offset: 0x78 */
    __IO uint32_t JOFR0;                /*!< Injection channel data compensation register 0 offset: 0x7C */
    __IO uint32_t JOFR1;                /*!< Injection channel data compensation register 1 offset: 0x80 */
    __IO uint32_t JOFR2;                /*!< Injection channel data compensation register 2 offset: 0x84 */
    __IO uint32_t JOFR3;                /*!< Injection channel data compensation register 3 offset: 0x88 */
    __IO uint32_t JSQR;                 /*!< Injection sequence register                    offset: 0x8C */
    __IO uint32_t JADDATA;              /*!< Inject data register                           offset: 0x90 */
    __IO uint32_t RESERVED0x94[7];      /*!< RESERVED                                       offset: 0x94-0xAC */
    __IO uint32_t JDR0;                 /*!< Injection channel data register 0              offset: 0xB0 */
    __IO uint32_t JDR1;                 /*!< Injection channel data register 1              offset: 0xB4 */
    __IO uint32_t JDR2;                 /*!< Injection channel data register 2              offset: 0xB8 */
    __IO uint32_t JDR3;                 /*!< Injection channel data register 3              offset: 0xBC */
    __IO uint32_t RESERVED0xC0[12];     /*!< RESERVED                                       offset: 0xC0-0xEC */
    __IO uint32_t LDATA;                /*!< ADC Last conversion data register              offset: 0xF0 */
    __IO uint32_t TRGSUPR;              /*!< ADC External rule trigger event suppression register offset: 0xF4 */
} ADC_TypeDef;

/**
  * @brief ADC type pointer Definition
  */
#define ADC1                            ((ADC_TypeDef *)ADC1_BASE)

/**
  * @brief ADC_ADDATA Register Bit Definition
  */
#define ADC_ADDATA_DATA_Pos             (0)
#define ADC_ADDATA_DATA                 (0xFFFFU << ADC_ADDATA_DATA_Pos)        /*!< ADC 12bit convert data */

#define ADC_ADDATA_CHANNELSEL_Pos       (16)
#define ADC_ADDATA_CHANNELSEL           (0x0FU << ADC_ADDATA_CHANNELSEL_Pos)    /*!< CHANNELSEL[19:16] (ADC current channel convert data) */

#define ADC_ADDATA_OVERRUN_Pos          (20)
#define ADC_ADDATA_OVERRUN              (0x01U << ADC_ADDATA_OVERRUN_Pos)       /*!< ADC data will be cover */
#define ADC_ADDATA_VALID_Pos            (21)
#define ADC_ADDATA_VALID                (0x01U << ADC_ADDATA_VALID_Pos)         /*!< ADC data[11:0] is valid */

/**
  * @brief ADC_ADCFG Register Bit Definition
  */
#define ADC_ADCFG_ADEN_Pos              (0)
#define ADC_ADCFG_ADEN                  (0x01U << ADC_ADCFG_ADEN_Pos)    /*!< Enable ADC convert */
#define ADC_ADCFG_AWDEN_Pos             (1)
#define ADC_ADCFG_AWDEN                 (0x01U << ADC_ADCFG_AWDEN_Pos)   /*!< Enable ADC window compare */

#define ADC_ADCFG_VTSEN_Pos             (2)
#define ADC_ADCFG_VTSEN_Msk             (0x03U << ADC_ADCFG_VTSEN_Pos)     /*!< Disable ADC temperature sensor and voltage sensor */
#define ADC_ADCFG_VTSEN_VEN             (0x01U << ADC_ADCFG_VTSEN_Pos)     /*!< Enable ADC voltage sensor */
#define ADC_ADCFG_VTSEN_TEN             (0x02U << ADC_ADCFG_VTSEN_Pos)     /*!< Enable ADC temperature sensor */
#define ADC_ADCFG_VTSEN_DIS             (0x03U << ADC_ADCFG_VTSEN_Pos)     /*!< Disable */

#define ADC_ADCFG_RSLTCTL_Pos           (7)
#define ADC_ADCFG_RSLTCTL_Msk           (0x07U << ADC_ADCFG_RSLTCTL_Pos)   /*!< ADC resolution select */

#define ADC_ADCFG_ADCPREH_Pos           (4)
#define ADC_ADCFG_ADCPREH_Msk           (0x07U << ADC_ADCFG_ADCPREH_Pos)
#define ADC_ADCFG_ADCPREL_Pos           (14)
#define ADC_ADCFG_ADCPREL_Msk           (0x01U << ADC_ADCFG_ADCPREL_Pos)

#define ADC_ADCFG_JAWDEN_Pos            (16)
#define ADC_ADCFG_JAWDEN                (0x01U << ADC_ADCFG_JAWDEN_Pos)   /*!< Inject ADC conversion window comparison enable */

/**
  * @brief ADC_ADCR Register Bit Definition
  */
#define ADC_ADCR_EOSIE_Pos              (0)
#define ADC_ADCR_EOSIE                  (0x01U << ADC_ADCR_EOSIE_Pos)                                       /*!< ADC interrupt enable */
#define ADC_ADCR_AWDIE_Pos              (1)
#define ADC_ADCR_AWDIE                  (0x01U << ADC_ADCR_AWDIE_Pos)                                       /*!< ADC window compare interrupt enable */
#define ADC_ADCR_TRGEN_Pos              (2)
#define ADC_ADCR_TRGEN                  (0x01U << ADC_ADCR_TRGEN_Pos)                                       /*!< extranal trigger single start AD convert */
#define ADC_ADCR_DMAEN_Pos              (3)
#define ADC_ADCR_DMAEN                  (0x01U << ADC_ADCR_DMAEN_Pos)                                       /*!< ADC DMA enable */

#define ADC_ADCR_ADST_Pos               (8)
#define ADC_ADCR_ADST                   (0x01U << ADC_ADCR_ADST_Pos)                                        /*!< ADC start convert data */
#define ADC_ADCR_ADMD_Pos               (9)
#define ADC_ADCR_ADMD_Msk               (0x03U << ADC_ADCR_ADMD_Pos)                                        /*!< ADC convert mode */
#define ADC_ADCR_IMM                    (0x00U << ADC_ADCR_ADMD_Pos)                                        /*!< ADC imm convert mode */
#define ADC_ADCR_SCAN                   (0x01U << ADC_ADCR_ADMD_Pos)                                        /*!< ADC scan convert mode */
#define ADC_ADCR_CONTINUE               (0x02U << ADC_ADCR_ADMD_Pos)                                        /*!< ADC continue scan convert mode */
#define ADC_ADCR_ALIGN_Pos              (11)
#define ADC_ADCR_ALIGN_Msk              (0x01U << ADC_ADCR_ALIGN_Pos)                                       /*!< ADC data align */
#define ADC_ADCR_LEFT                   (0x01U << ADC_ADCR_ALIGN_Pos)                                       /*!< ADC data left align */
#define ADC_ADCR_RIGHT                  (0x00U << ADC_ADCR_ALIGN_Pos)                                       /*!< ADC data right align */
#define ADC_ADCR_CMPCH_Pos              (12)
#define ADC_ADCR_CMPCH_Msk              (0x0FU << ADC_ADCR_CMPCH_Pos)                                       /*!< CMPCH[15:12] ADC window compare channel0 convert data */
#define ADC_ADCR_CMPCH_0                (0x00U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 0 Conversion Results */
#define ADC_ADCR_CMPCH_1                (0x01U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 1 Conversion Results */
#define ADC_ADCR_CMPCH_2                (0x02U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 2 Conversion Results */
#define ADC_ADCR_CMPCH_3                (0x03U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 3 Conversion Results */
#define ADC_ADCR_CMPCH_4                (0x04U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 4 Conversion Results */
#define ADC_ADCR_CMPCH_5                (0x05U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 5 Conversion Results */
#define ADC_ADCR_CMPCH_6                (0x06U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 6 Conversion Results */
#define ADC_ADCR_CMPCH_7                (0x07U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 7 Conversion Results */
#define ADC_ADCR_CMPCH_8                (0x08U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 8 Conversion Results */
#define ADC_ADCR_CMPCH_9                (0x09U << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 9 Conversion Results */
#define ADC_ADCR_CMPCH_10               (0x0AU << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare Channel 10 Conversion Results */
#define ADC_ADCR_CMPCH_ALL              (0x0FU << ADC_ADCR_CMPCH_Pos)                                       /*!< Select Compare ALL Channel Conversion Results */

#define ADC_ADCR_SCANDIR_Pos            (16)
#define ADC_ADCR_SCANDIR                (0x01U << ADC_ADCR_SCANDIR_Pos)                                     /*!< ADC scan direction */

#define ADC_ADCR_TRGSELH_Pos            (17)
#define ADC_ADCR_TRGSELH_Msk            (0x03U << ADC_ADCR_TRGSELH_Pos)                                     /*!< External trigger sources select for high bits */
#define ADC_ADCR_TRGSELL_Pos            (4)
#define ADC_ADCR_TRGSELL_Msk            (0x07U << ADC_ADCR_TRGSELL_Pos)                                     /*!< External trigger sources select for low bits */

#define ADC_ADCR_TRGSHIFT_Pos           (19)
#define ADC_ADCR_TRGSHIFT_Msk           (0x07U << ADC_ADCR_TRGSHIFT_Pos)                                    /*!< External trigger shift sample */

#define ADC_ADCR_TRG_EDGE_Pos           (24)
#define ADC_ADCR_TRG_EDGE_Msk           (0x03U << ADC_ADCR_TRG_EDGE_Pos)                                    /*!< ADC trig edge config */

#define ADC_ADCR_EOSMPIE_Pos            (26)
#define ADC_ADCR_EOSMPIE                (0X01U << ADC_ADCR_EOSMPIE_Pos)                                     /*!< ADC end sampling flag interrupt enable */
#define ADC_ADCR_EOCIE_Pos              (27)
#define ADC_ADCR_EOCIE                  (0X01U << ADC_ADCR_EOCIE_Pos)                                       /*!< ADC end of conversion interrupt enable */


/**
  * @brief ADC_ADCHS Register Bit Definition
  */
#define ADC_ADCHS_CHEN0_Pos             (0)
#define ADC_ADCHS_CHEN0                 (0x01U << ADC_ADCHS_CHEN0_Pos)                                       /*!< Enable ADC channel 0 */
#define ADC_ADCHS_CHEN1_Pos             (1)
#define ADC_ADCHS_CHEN1                 (0x01U << ADC_ADCHS_CHEN1_Pos)                                       /*!< Enable ADC channel 1 */
#define ADC_ADCHS_CHEN2_Pos             (2)
#define ADC_ADCHS_CHEN2                 (0x01U << ADC_ADCHS_CHEN2_Pos)                                       /*!< Enable ADC channel 2 */
#define ADC_ADCHS_CHEN3_Pos             (3)
#define ADC_ADCHS_CHEN3                 (0x01U << ADC_ADCHS_CHEN3_Pos)                                       /*!< Enable ADC channel 3 */
#define ADC_ADCHS_CHEN4_Pos             (4)
#define ADC_ADCHS_CHEN4                 (0x01U << ADC_ADCHS_CHEN4_Pos)                                       /*!< Enable ADC channel 4 */
#define ADC_ADCHS_CHEN5_Pos             (5)
#define ADC_ADCHS_CHEN5                 (0x01U << ADC_ADCHS_CHEN5_Pos)                                       /*!< Enable ADC channel 5 */
#define ADC_ADCHS_CHEN6_Pos             (6)
#define ADC_ADCHS_CHEN6                 (0x01U << ADC_ADCHS_CHEN6_Pos)                                       /*!< Enable ADC channel 6 */
#define ADC_ADCHS_CHEN7_Pos             (7)                  
#define ADC_ADCHS_CHEN7                 (0x01U << ADC_ADCHS_CHEN7_Pos)                                       /*!< Enable ADC channel 7 */
#define ADC_ADCHS_CHEN8_Pos             (8)                  
#define ADC_ADCHS_CHEN8                 (0x01U << ADC_ADCHS_CHEN8_Pos)                                       /*!< Enable ADC channel 8 */
#define ADC_ADCHS_CHEN9_Pos             (9)                   
#define ADC_ADCHS_CHEN9                 (0x01U << ADC_ADCHS_CHEN9_Pos)                                       /*!< Enable ADC channel 9 */
#define ADC_ADCHS_CHEN10_Pos            (10)
#define ADC_ADCHS_CHEN10                (0x01U << ADC_ADCHS_CHEN10_Pos)                                      /*!< Enable ADC channel 10 */
#define ADC_ADCHS_CHT                   (0x01U << ADC_ADCHS_CHEN10_Pos)                                      /*!< Enable ADC Temperature channel */
#define ADC_ADCHS_CHV                   (0x01U << ADC_ADCHS_CHEN10_Pos)                                      /*!< Enable ADC Voltage channel */

/**
  * @brief ADC_ADCMPR Register Bit Definition
  */
#define ADC_ADCMPR_CMPLDATA_Pos         (0)
#define ADC_ADCMPR_CMPLDATA_Msk         (0x0FFFU << ADC_ADCMPR_CMPLDATA_Pos)    /*!< ADC 12bit window compare DOWN LEVEL DATA */
#define ADC_ADCMPR_CMPHDATA_Pos         (16)
#define ADC_ADCMPR_CMPHDATA_Msk         (0x0FFFU << ADC_ADCMPR_CMPHDATA_Pos)    /*!< ADC 12bit window compare UP LEVEL DATA */

/**
  * @brief ADC_ADSTA Register Bit Definition
  */
#define ADC_ADSTA_EOSIF_Pos             (0)
#define ADC_ADSTA_EOSIF_Msk             (0x01U << ADC_ADSTA_EOSIF_Pos)     /*!< ADC convert complete flag */
#define ADC_ADSTA_AWDIF_Pos             (1)
#define ADC_ADSTA_AWDIF_Msk             (0x01U << ADC_ADSTA_AWDIF_Pos)     /*!< ADC compare flag */
#define ADC_ADSTA_BUSY_Pos              (2)
#define ADC_ADSTA_BUSY                  (0x01U << ADC_ADSTA_BUSY_Pos)      /*!< ADC busy flag */
#define ADC_ADSTA_CHANNEL_Pos           (4)
#define ADC_ADSTA_CHANNEL               (0x0FU << ADC_ADSTA_CHANNEL_Pos)   /*!< CHANNEL[7:4] ADC current channel */

#define ADC_ADSTA_VALID_Pos             (8)
#define ADC_ADSTA_VALID                 (0x07FFU << ADC_ADSTA_VALID_Pos)   /*!< VALID[18:8] ADC channel 0..11 valid flag */
#define ADC_ADSTA_OVERRUN_Pos           (20)
#define ADC_ADSTA_OVERRUN               (0x07FFU << ADC_ADSTA_OVERRUN_Pos) /*!< OVERRUN[30:20] ADC channel 0..11 data covered flag */

/**
  * @brief ADC_ADDRn Register Bit Definition
  */
#define ADC_ADDR_DATA_Pos               (0)
#define ADC_ADDR_DATA                   (0xFFFFU << ADC_ADDR_DATA_Pos)  /*!< ADC channel convert data */
#define ADC_ADDR_OVERRUN_Pos            (20)
#define ADC_ADDR_OVERRUN                (0x01U << ADC_ADDR_OVERRUN_Pos) /*!< ADC data covered flag */
#define ADC_ADDR_VALID_Pos              (21)
#define ADC_ADDR_VALID                  (0x01U << ADC_ADDR_VALID_Pos)   /*!< ADC data valid flag */

/**
  * @brief ADC_ADSTA_EXT Register Bit Definition
  */

#define ADC_ADSTA_EXT_EOSMPIF_Pos       (16)
#define ADC_ADSTA_EXT_EOSMPIF_Msk       (0x01U << ADC_ADSTA_EXT_EOSMPIF_Pos)    /*!< End of sampling interrupt flag */
#define ADC_ADSTA_EXT_EOCIF_Pos         (17)
#define ADC_ADSTA_EXT_EOCIF_Msk         (0x01U << ADC_ADSTA_EXT_EOCIF_Pos)      /*!< End of conversion interrupt flag */
#define ADC_ADSTA_EXT_JEOSMPIF_Pos      (18)
#define ADC_ADSTA_EXT_JEOSMPIF_Msk      (0x01U << ADC_ADSTA_EXT_JEOSMPIF_Pos)   /// Injected channel end of sampling interrupt flag */
#define ADC_ADSTA_EXT_JEOCIF_Pos        (19)
#define ADC_ADSTA_EXT_JEOCIF_Msk        (0x01U << ADC_ADSTA_EXT_JEOCIF_Pos)     /*!< Injected channel end of conversion interrupt flag */
#define ADC_ADSTA_EXT_JEOSIF_Pos        (20)
#define ADC_ADSTA_EXT_JEOSIF_Msk        (0x01U << ADC_ADSTA_EXT_JEOSIF_Pos)     /*!< Injected channel end of sequential conversion interrupt flag */
#define ADC_ADSTA_EXT_JBUSY_Pos         (21)
#define ADC_ADSTA_EXT_JBUSY_Msk         (0x01U << ADC_ADSTA_EXT_JBUSY_Pos)      /*!< Injection mode busy/idle */

/**
  * @brief ADC_CHANY0 select Register Bit Definition
  */
#define ADC_CHANY0_SEL0_Pos             (0)                                  /*!< CHANY_SEL0 (Bit 0) */
#define ADC_CHANY0_SEL0                 (0x0FU << ADC_CHANY0_SEL0_Pos)       /*!< CHANY_SEL0 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL1_Pos             (4)                                  /*!< CHANY_SEL1 (Bit 4) */
#define ADC_CHANY0_SEL1                 (0x0FU << ADC_CHANY0_SEL1_Pos)       /*!< CHANY_SEL1 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL2_Pos             (8)                                  /*!< CHANY_SEL2 (Bit 8) */
#define ADC_CHANY0_SEL2                 (0x0FU << ADC_CHANY0_SEL2_Pos)       /*!< CHANY_SEL2 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL3_Pos             (12)                                 /*!< CHANY_SEL3 (Bit 12) */
#define ADC_CHANY0_SEL3                 (0x0FU << ADC_CHANY0_SEL3_Pos)       /*!< CHANY_SEL3 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL4_Pos             (16)                                 /*!< CHANY_SEL4 (Bit 16) */
#define ADC_CHANY0_SEL4                 (0x0FU << ADC_CHANY0_SEL4_Pos)       /*!< CHANY_SEL4 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL5_Pos             (20)                                 /*!< CHANY_SEL5 (Bit 20) */
#define ADC_CHANY0_SEL5                 (0x0FU << ADC_CHANY0_SEL5_Pos)       /*!< CHANY_SEL5 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL6_Pos             (24)                                 /*!< CHANY_SEL6 (Bit 24) */
#define ADC_CHANY0_SEL6                 (0x0FU << ADC_CHANY0_SEL6_Pos)       /*!< CHANY_SEL6 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY0_SEL7_Pos             (28)                                 /*!< CHANY_SEL7 (Bit 28) */
#define ADC_CHANY0_SEL7                 (0x0FU << ADC_CHANY0_SEL7_Pos)       /*!< CHANY_SEL7 (Bitfield-Mask: 0x0f) */

/**
  * @brief ADC_CHANY1 select Register Bit Definition
  */
#define ADC_CHANY1_SEL8_Pos             (0)                                  /*!< CHANY_SEL8 (Bit 0) */
#define ADC_CHANY1_SEL8                 (0x0FU << ADC_CHANY1_SEL8_Pos)       /*!< CHANY_SEL8 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL9_Pos             (4)                                  /*!< CHANY_SEL9 (Bit 4) */
#define ADC_CHANY1_SEL9                 (0x0FU << ADC_CHANY1_SEL9_Pos)       /*!< CHANY_SEL9 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL10_Pos            (8)                                  /*!< CHANY_SEL10 (Bit 8) */
#define ADC_CHANY1_SEL10                (0x0FU << ADC_CHANY1_SEL10_Pos)      /*!< CHANY_SEL10 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL11_Pos            (12)                                 /*!< CHANY_SEL11 (Bit 12) */
#define ADC_CHANY1_SEL11                (0x0FU << ADC_CHANY1_SEL11_Pos)      /*!< CHANY_SEL11 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL12_Pos            (16)                                 /*!< CHANY_SEL12 (Bit 16) */
#define ADC_CHANY1_SEL12                (0x0FU << ADC_CHANY1_SEL12_Pos)      /*!< CHANY_SEL12 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL13_Pos            (20)                                 /*!< CHANY_SEL13 (Bit 20) */
#define ADC_CHANY1_SEL13                (0x0FU << ADC_CHANY1_SEL13_Pos)      /*!< CHANY_SEL13 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL14_Pos            (24)                                 /*!< CHANY_SEL14 (Bit 24) */
#define ADC_CHANY1_SEL14                (0x0FU << ADC_CHANY1_SEL14_Pos)      /*!< CHANY_SEL14 (Bitfield-Mask: 0x0f) */
#define ADC_CHANY1_SEL15_Pos            (28)                                 /*!< CHANY_SEL15 (Bit 28) */
#define ADC_CHANY1_SEL15                (0x0FU << ADC_CHANY1_SEL15_Pos)      /*!< CHANY_SEL15 (Bitfield-Mask: 0x0f) */
                                                                            
/**
  * @brief ADC_ANY_CFG config number Register Bit Definition
  */
#define ADC_ANY_CFG_CHANY_NUM_Pos       (0)                                  /*!< Number of Any Channel Mode */
#define ADC_ANY_CFG_CHANY_NUM_Msk       (0x0FU << ADC_ANY_CFG_CHANY_NUM_Pos)

/**
  * @brief ADC_ANY_CR mode enable Register Bit Definition
  */
#define ADC_ANY_CR_CHANY_MDEN_Pos       (0)                                  /*!< CHANY_MDEN (Bit 0) */
#define ADC_ANY_CR_CHANY_MDEN           (0x01U << ADC_ANY_CR_CHANY_MDEN_Pos) /*!< CHANY_MDEN (Bitfield-Mask: 0x01) */
#define ADC_ANY_CR_JCEN_Pos             (1)
#define ADC_ANY_CR_JCEN                 (0x01U << ADC_ANY_CR_JCEN_Pos)       /*!< Injected channel enable */
#define ADC_ANY_CR_JEOSMPIE_Pos         (2)
#define ADC_ANY_CR_JEOSMPIE             (0x01U << ADC_ANY_CR_JEOSMPIE_Pos)   /*!< Interrupt enable the end of sequence conversion for injected channel */
#define ADC_ANY_CR_JEOCIE_Pos           (3)
#define ADC_ANY_CR_JEOCIE               (0x01U << ADC_ANY_CR_JEOCIE_Pos)     /*!< Interrupt enable the end of conversion for injected channel */
#define ADC_ANY_CR_JEOSIE_Pos           (4)
#define ADC_ANY_CR_JEOSIE               (0x01U << ADC_ANY_CR_JEOSIE_Pos)     /*!< Interrupt enable the end of sequence conversion for injected channel */
#define ADC_ANY_CR_JAUTO_Pos            (5)
#define ADC_ANY_CR_JAUTO                (0x01U << ADC_ANY_CR_JAUTO_Pos)      /*!<Automatic Injected group conversion */
#define ADC_ANY_CR_JADST_Pos            (6)
#define ADC_ANY_CR_JADST                (0x01U << ADC_ANY_CR_JADST_Pos)      /*!< Start conversion of injected channels */
#define ADC_ANY_CR_JTRGEN_Pos           (7)
#define ADC_ANY_CR_JTRGEN               (0x01U << ADC_ANY_CR_JTRGEN_Pos)     /*!< External trigger conversion mode for injected channels */
#define ADC_ANY_CR_JTRGSEL_Pos          (8)                                  /*!< External event select for injected group */
#define ADC_ANY_CR_JTRGSEL_Msk          (0x1FU << ADC_ANY_CR_JTRGSEL_Pos)    /*!< External trigger sources selection for injected channel. */

#define ADC_ANY_CR_JTRGSHIFT_Pos        (13)                                 /*!< Injection mode external trigger delay sampling */
#define ADC_ANY_CR_JTRGSHIFT_Msk        (0x07U << ADC_ANY_CR_JTRGSHIFT_Pos)  /*!< 0   cycle */

#define ADC_ANY_CR_JTRGEDGE_Pos         (16)                                 /*!< Injection mode triggers edge selection */
#define ADC_ANY_CR_JTRGEDGE_Msk         (0x03U << ADC_ANY_CR_JTRGEDGE_Pos)   /*!< Shield trigger */
#define ADC_ANY_CR_JTRGEDGE_R_F         (0x00U << ADC_ANY_CR_JTRGEDGE_Pos)   /*!< Triggered along both rising and falling edges */
#define ADC_ANY_CR_JTRGEDGE_F           (0x01U << ADC_ANY_CR_JTRGEDGE_Pos)   /*!< Drop edge trigger */
#define ADC_ANY_CR_JTRGEDGE_R           (0x02U << ADC_ANY_CR_JTRGEDGE_Pos)   /*!< Rising edge trigger */

/**
  * @brief ADC_SMPR1 mode enable Register Bit Definition
  */
#define ADC_SMPR_SAMCTL_Pos             (0)                                  /*!< Injection mode external trigger delay sampling off_set Position */
#define ADC_SMPR_SAMCTL_Msk             (0x0FU << ADC_SMPR_SAMCTL_Pos)       /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR_SAMCTL_2_5             (0x00U << ADC_SMPR_SAMCTL_Pos)       /*!< 2.5    cycle */
#define ADC_SMPR_SAMCTL_8_5             (0x01U << ADC_SMPR_SAMCTL_Pos)       /*!< 8.5    cycle */
#define ADC_SMPR_SAMCTL_14_5            (0x02U << ADC_SMPR_SAMCTL_Pos)       /*!< 14.5   cycle */
#define ADC_SMPR_SAMCTL_29_5            (0x03U << ADC_SMPR_SAMCTL_Pos)       /*!< 29.5   cycle */
#define ADC_SMPR_SAMCTL_42_5            (0x04U << ADC_SMPR_SAMCTL_Pos)       /*!< 42.5   cycle */
#define ADC_SMPR_SAMCTL_56_5            (0x05U << ADC_SMPR_SAMCTL_Pos)       /*!< 56.5   cycle */
#define ADC_SMPR_SAMCTL_72_5            (0x06U << ADC_SMPR_SAMCTL_Pos)       /*!< 72.5   cycle */
#define ADC_SMPR_SAMCTL_240_5           (0x07U << ADC_SMPR_SAMCTL_Pos)       /*!< 240.5  cycle */
#define ADC_SMPR_SAMCTL_3_5             (0x08U << ADC_SMPR_SAMCTL_Pos)       /*!< 3.5    cycle */
#define ADC_SMPR_SAMCTL_4_5             (0x09U << ADC_SMPR_SAMCTL_Pos)       /*!< 4.5    cycle */
#define ADC_SMPR_SAMCTL_5_5             (0x0AU << ADC_SMPR_SAMCTL_Pos)       /*!< 5.5    cycle */
#define ADC_SMPR_SAMCTL_6_5             (0x0BU << ADC_SMPR_SAMCTL_Pos)       /*!< 6.5    cycle */
#define ADC_SMPR_SAMCTL_7_5             (0x0CU << ADC_SMPR_SAMCTL_Pos)       /*!< 7.5    cycle */

#define ADC_SMPR1_SAMCTL7_Pos           (28)                                 /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL7_Msk           (0x0FU << ADC_SMPR1_SAMCTL7_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL6_Pos           (24)                                 /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL6_Msk           (0x0FU << ADC_SMPR1_SAMCTL6_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL5_Pos           (20)                                 /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL5_Msk           (0x0FU << ADC_SMPR1_SAMCTL5_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL4_Pos           (16)                                 /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL4_Msk           (0x0FU << ADC_SMPR1_SAMCTL4_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL3_Pos           (12)                                 /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL3_Msk           (0x0FU << ADC_SMPR1_SAMCTL3_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL2_Pos           (8)                                  /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL2_Msk           (0x0FU << ADC_SMPR1_SAMCTL2_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL1_Pos           (4)                                  /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL1_Msk           (0x0FU << ADC_SMPR1_SAMCTL1_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR1_SAMCTL0_Pos           (0)                                  /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL0_Msk           (0x0FU << ADC_SMPR1_SAMCTL0_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */

/**
  * @brief ADC_SMPR2 mode enable Register Bit Definition
  */
#define ADC_SMPR2_SAMCTL10_Pos          (8)                                  /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL10_Msk          (0x0FU << ADC_SMPR2_SAMCTL10_Pos)    /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR2_SAMCTL9_Pos           (4)                                  /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL9_Msk           (0x0FU << ADC_SMPR2_SAMCTL9_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */
#define ADC_SMPR2_SAMCTL8_Pos           (0)                                  /*!< Injection mode external trigger delay sampling */
#define ADC_SMPR1_SAMCTL8_Msk           (0x0FU << ADC_SMPR2_SAMCTL8_Pos)     /*!< Injection mode external trigger delay sampling mask for Value */

/**
  * @brief ADC_JOFR0 mode enable Register Bit Definition
  */
#define ADC_JOFR0_JOFFSET                  (0xFFFU)                          /*!< Compensates for the A/D conversion results of the injected channel 0 */

/**
  * @brief ADC_JOFR1 mode enable Register Bit Definition
  */
#define ADC_JOFR1_JOFFSET                  (0xFFFU)                          /*!< Compensates for the A/D conversion results of the injected channel 1 */

/**
  * @brief ADC_JOFR2 mode enable Register Bit Definition
  */
#define ADC_JOFR2_JOFFSET                  (0xFFFU)                          /*!< Compensates for the A/D conversion results of the injected channel 2 */

/**
  * @brief ADC_JOFR3 mode enable Register Bit Definition
  */
#define ADC_JOFR3_JOFFSET                  (0xFFFU)                          /*!< Compensates for the A/D conversion results of the injected channel 3 */

/**
  * @brief ADC_JSQR mode enable Register Bit Definition
  */
#define ADC_JSQR_JSQ0_Pos               (0)                                  /*!< 1st conversion in injected sequence */
#define ADC_JSQR_JSQ1_Pos               (5)                                  /*!< 2st conversion in injected sequence */
#define ADC_JSQR_JSQ2_Pos               (10)                                 /*!< 3st conversion in injected sequence */
#define ADC_JSQR_JSQ3_Pos               (15)                                 /*!< 4st conversion in injected sequence */

#define ADC_JSQR_JNUM_Pos               (20)                                 /*!< Injected Sequence length */
#define ADC_JSQR_JNUM_Msk               (0x03U << ADC_JSQR_JNUM_Pos)         /*!< Channel Number for Injected Sequence mask */

/**
  * @brief ADC_JADDATA mode enable Register Bit Definition
  */
#define ADC_JADDATA_JDATA_Pos           (0)
#define ADC_JADDATA_JDATA               (0xFFFFU << ADC_JADDATA_JDATA_Pos)     /*!< Transfer data */
#define ADC_JADDATA_JCHANNELSEL_Pos     (16)
#define ADC_JADDATA_JCHANNELSEL         (0x0FU << ADC_JADDATA_JCHANNELSEL_Pos) /*!< Channel selection */
#define ADC_JADDATA_JOVERRUN_Pos        (21)
#define ADC_JADDATA_JOVERRUN            (0x01U << ADC_JADDATA_JOVERRUN_Pos)    /*!< Overrun flag */
#define ADC_JADDATA_JVALID_Pos          (22)
#define ADC_JADDATA_JVALID              (0x01U << ADC_JADDATA_JVALID_Pos)      /*!< Valid flag */

/**
  * @brief ADC_JDR0 mode enable Register Bit Definition
  */
#define ADC_JDR0_JDATA_Pos              (0)
#define ADC_JDR0_JDATA                  (0xFFFFU << ADC_JDR0_JDATA_Pos)      /*!< Transfer data */
#define ADC_JDR0_JOVERRUN_Pos           (21)
#define ADC_JDR0_JOVERRUN               (0x01U << ADC_JDR0_JOVERRUN_Pos)     /*!< Overrun flag */
#define ADC_JDR0_JVALID_Pos             (22)
#define ADC_JDR0_JVALID                 (0x01U << ADC_JDR0_JVALID_Pos)       /*!< Valid flag */

/**
  * @brief ADC_JDR1 mode enable Register Bit Definition
  */
#define ADC_JDR1_JDATA_Pos              (0)
#define ADC_JDR1_JDATA                  (0xFFFFU << ADC_JDR1_JDATA_Pos)      /*!< Transfer data */
#define ADC_JDR1_JOVERRUN_Pos           (21) 
#define ADC_JDR1_JOVERRUN               (0x01U << ADC_JDR1_JOVERRUN_Pos)     /*!< Overrun flag */
#define ADC_JDR1_JVALID_Pos             (22) 
#define ADC_JDR1_JVALID                 (0x01U << ADC_JDR1_JVALID_Pos)       /*!< Valid flag */

/**
  * @brief ADC_JDR2 mode enable Register Bit Definition
  */
#define ADC_JDR2_JDATA_Pos              (0)
#define ADC_JDR2_JDATA                  (0xFFFFU << ADC_JDR2_JDATA_Pos)      /*!< Transfer data */
#define ADC_JDR2_JOVERRUN_Pos           (21)
#define ADC_JDR2_JOVERRUN               (0x01U << ADC_JDR2_JOVERRUN_Pos)     /*!< Overrun flag */
#define ADC_JDR2_JVALID_Pos             (22)
#define ADC_JDR2_JVALID                 (0x01U << ADC_JDR2_JVALID_Pos)       /*!< Valid flag */

/**
  * @brief ADC_JDR3 mode enable Register Bit Definition
  */
#define ADC_JDR3_JDATA_Pos              (0)
#define ADC_JDR3_JDATA                  (0xFFFFU << ADC_JDR3_JDATA_Pos)       /*!< Transfer data */
#define ADC_JDR3_JOVERRUN_Pos           (21)
#define ADC_JDR3_JOVERRUN               (0x01U << ADC_JDR3_JOVERRUN_Pos)     /*!< Overrun flag */
#define ADC_JDR3_JVALID_Pos             (22)
#define ADC_JDR3_JVALID                 (0x01U << ADC_JDR3_JVALID_Pos)       /*!< Valid flag */

/**
  * @brief ADC_LDATA mode enable Register Bit Definition
  */
#define ADC_LDATA_LDATA_Pos             (0)
#define ADC_LDATA_LDATA                 (0xFFFFU << ADC_LDATA_LDATA_Pos)       /*!< Transfer data */
#define ADC_LDATA_LCHANNELSEL_Pos       (16)
#define ADC_LDATA_LCHANNELSEL           (0x0FU << ADC_LDATA_LCHANNELSEL_Pos)   /*!< Channel selection */
#define ADC_LDATA_LOVERRUN_Pos          (20)
#define ADC_LDATA_LOVERRUN              (0x01U << ADC_LDATA_LOVERRUN_Pos)      /*!< Overrun flag */
#define ADC_LDATA_LVALID_Pos            (21)
#define ADC_LDATA_LVALID                (0x01U << ADC_LDATA_LVALID_Pos)        /*!< Valid flag */

/**
  * @brief  ADC_TRGSUPR mode enable Register Bit Definition
  */
#define ADC_TRGSUPR_TRG_SUP_CNT_Pos     (0)
#define ADC_TRGSUPR_TRG_SUP_CNT         (0x07U << ADC_TRGSUPR_TRG_SUP_CNT_POS)  /*!< Trigger suppression count target */
#define ADC_TRGSUPR_TRG_SUP_EN_Pos      (7)
#define ADC_TRGSUPR_TRG_SUP_EN          (0x01U << ADC_TRGSUPR_TRG_SUP_EN_Pos)   /*!< Trigger inhibition enable */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/

