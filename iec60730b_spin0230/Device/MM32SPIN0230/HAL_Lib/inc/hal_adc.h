/***********************************************************************************************************************
    @file     hal_adc.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE ADC
              FIRMWARE LIBRARY.
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
#ifndef __HAL_ADC_H
#define __HAL_ADC_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup ADC_HAL
  * @brief ADC HAL modules
  * @{
  */

/** @defgroup ADC_Exported_Types
  * @{
  */

/**
  * @brief ADC Init Structure definition
  */
typedef struct
{
    uint32_t       ADC_Resolution;         /*!< Convert data resolution */
    uint32_t       ADC_Prescaler;          /*!< Clock prescaler */
    uint32_t       ADC_Mode;               /*!< ADC conversion mode */
    uint32_t       ADC_DataAlign;          /*!< Data alignmentn */
} ADC_InitTypeDef;

/**
  * @brief ADC_Resolution
  */
#define ADC_Resolution_12b              (0x00U << ADC_ADCFG_RSLTCTL_Pos)/*!< ADC resolution select 12bit */
#define ADC_Resolution_11b              (0x01U << ADC_ADCFG_RSLTCTL_Pos)/*!< ADC resolution select 11bit */
#define ADC_Resolution_10b              (0x02U << ADC_ADCFG_RSLTCTL_Pos)/*!< ADC resolution select 10bit */
#define ADC_Resolution_9b               (0x03U << ADC_ADCFG_RSLTCTL_Pos)/*!< ADC resolution select 9bit */
#define ADC_Resolution_8b               (0x04U << ADC_ADCFG_RSLTCTL_Pos)/*!< ADC resolution select 8bit */

/**
  * @brief ADC_Prescaler
  */
#define ADC_Prescaler_3             ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x00U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 3 */
#define ADC_Prescaler_5             ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x01U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 5 */
#define ADC_Prescaler_7             ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x02U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 7 */
#define ADC_Prescaler_9             ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x03U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 9 */
#define ADC_Prescaler_11            ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x04U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 11 */
#define ADC_Prescaler_13            ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x05U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 13 */
#define ADC_Prescaler_15            ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x06U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 15 */
#define ADC_Prescaler_17            ((0x01U << ADC_ADCFG_ADCPREL_Pos) + (0x07U << ADC_ADCFG_ADCPREH_Pos)) /*!< ADC preclk 17 */
            
#define ADC_Prescaler_2             (0x00U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 2 */
#define ADC_Prescaler_4             (0x01U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 4 */
#define ADC_Prescaler_6             (0x02U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 6 */
#define ADC_Prescaler_8             (0x03U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 8 */
#define ADC_Prescaler_10            (0x04U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 10 */
#define ADC_Prescaler_12            (0x05U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 12 */
#define ADC_Prescaler_14            (0x06U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 14 */
#define ADC_Prescaler_16            (0x07U << ADC_ADCFG_ADCPREH_Pos) /*!< ADC preclk 16 */

/**
  * @brief ADC_Conversion_Mode
  */
#define ADC_Mode_Imm                     (0x00U << ADC_ADCR_ADMD_Pos) /*!< ADC imm convert mode */
#define ADC_Mode_Scan                    (0x01U << ADC_ADCR_ADMD_Pos) /*!< ADC scan convert mode */
#define ADC_Mode_Continue                (0x02U << ADC_ADCR_ADMD_Pos) /*!< ADC continue scan convert mode */

/**
  * @brief ADC_Extrenal_Trigger_Sources
  */
#define ADC_ExtTrig_T1_CC1           ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x00U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T1_CC2           ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x01U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T1_CC3           ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x02U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T2_CC2           ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x03U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T1_CC4_CC5       ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x05U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_EXTI_11          ((0x00U << ADC_ADCR_TRGSELH_Pos) + (0x07U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T1_TRGO          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x00U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T13_CC1          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x01U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T14_CC1          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x02U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T2_CC1           ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x03U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T2_TRGO          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x05U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_EXTI_15          ((0x01U << ADC_ADCR_TRGSELH_Pos) + (0x07U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T1_CC4           ((0x02U << ADC_ADCR_TRGSELH_Pos) + (0x00U << ADC_ADCR_TRGSELL_Pos))
#define ADC_ExtTrig_T1_CC5           ((0x02U << ADC_ADCR_TRGSELH_Pos) + (0x01U << ADC_ADCR_TRGSELL_Pos))

/**
  * @brief ADC_Injected_Extrenal_Trigger_Sources
  */
#define ADC_InjectedExtTrig_T1_CC1           (0x00U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T1_CC2           (0x01U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T1_CC3           (0x02U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T2_CC2           (0x03U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T1_CC4_CC5       (0x05U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_EXTI_11          (0x07U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T1_TRGO          (0x08U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T13_CC1          (0x09U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T14_CC1          (0x0AU << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T2_CC1           (0x0BU << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T2_TRGO          (0x0DU << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_EXTI_15          (0x0FU << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T1_CC4           (0x10U << ADC_ANY_CR_JTRGSEL_Pos)
#define ADC_InjectedExtTrig_T1_CC5           (0x11U << ADC_ANY_CR_JTRGSEL_Pos)

/**
  * @brief ADC_Data_Align
  */
#define ADC_DataAlign_Right              (0x00U << ADC_ADCR_ALIGN_Pos) /*!< ADC data left align */
#define ADC_DataAlign_Left               (0x01U << ADC_ADCR_ALIGN_Pos)   /*!< ADC data right align */

/**
  * @brief ADCIT and Flags Definition
  */
#define ADC_IT_AWD             (0x01U << ADC_ADCR_AWDIE_Pos) 
#define ADC_IT_EOS             (0x01U << ADC_ADCR_EOSIE_Pos) 
#define ADC_IT_EOC             (0X01U << ADC_ADCR_EOCIE_Pos) 
#define ADC_IT_EOSMP           (0X01U << ADC_ADCR_EOSMPIE_Pos)
#define ADC_IT_INJEOS          (0x01U << ADC_ANY_CR_JEOSIE_Pos)
#define ADC_IT_INJEOC          (0x01U << ADC_ANY_CR_JEOCIE_Pos)
#define ADC_IT_INJEOSMP        (0x01U << ADC_ANY_CR_JEOSMPIE_Pos)
                                             
#define ADC_FLAG_AWD           (0x01U << ADC_ADSTA_AWDIF_Pos)
#define ADC_FLAG_EOS           (0x01U << ADC_ADSTA_EOSIF_Pos)
#define ADC_FLAG_EOC           (0x01U << ADC_ADSTA_EXT_EOCIF_Pos)
#define ADC_FLAG_EOSMP         (0x01U << ADC_ADSTA_EXT_EOSMPIF_Pos)
#define ADC_FLAG_INJEOS        (0x01U << ADC_ADSTA_EXT_JEOSIF_Pos)
#define ADC_FLAG_INJEOC        (0x01U << ADC_ADSTA_EXT_JEOCIF_Pos)
#define ADC_FLAG_INJEOSMP      (0x01U << ADC_ADSTA_EXT_JEOSMPIF_Pos)                        
   
                                      
/**                                      
  * @brief ADC_Channels                  
  */                                     
#define ADC_Channel_0                    0x00 /*!< ADC Channel 0 */
#define ADC_Channel_1                    0x01 /*!< ADC Channel 1 */
#define ADC_Channel_2                    0x02 /*!< ADC Channel 2 */
#define ADC_Channel_3                    0x03 /*!< ADC Channel 3 */
#define ADC_Channel_4                    0x04 /*!< ADC Channel 4 */
#define ADC_Channel_5                    0x05 /*!< ADC Channel 5 */
#define ADC_Channel_6                    0x06 /*!< ADC Channel 6 */
#define ADC_Channel_7                    0x07 /*!< ADC Channel 7 */                             
#define ADC_Channel_8                    0x08 /*!< ADC Channel 8 */
#define ADC_Channel_9                    0x09 /*!< ADC Channel 9 */
#define ADC_Channel_10                   0x0A /*!< ADC Channel 10 */
#define ADC_Channel_TempSensor           0x0A /*!< Temperature sensor channel */
#define ADC_Channel_VoltReference        0x0A /*!< Internal reference voltage(ADC1) channel */
                                         
/**
  * @brief ADC_AnyChannels
  */
#define ADC_AnyChannel_0                 0x00 /*!< ADC AnyChannel 0 */
#define ADC_AnyChannel_1                 0x01 /*!< ADC AnyChannel 1 */
#define ADC_AnyChannel_2                 0x02 /*!< ADC AnyChannel 2 */
#define ADC_AnyChannel_3                 0x03 /*!< ADC AnyChannel 3 */
#define ADC_AnyChannel_4                 0x04 /*!< ADC AnyChannel 4 */
#define ADC_AnyChannel_5                 0x05 /*!< ADC AnyChannel 5 */
#define ADC_AnyChannel_6                 0x06 /*!< ADC AnyChannel 6 */
#define ADC_AnyChannel_7                 0x07 /*!< ADC AnyChannel 7 */                             
#define ADC_AnyChannel_8                 0x08 /*!< ADC AnyChannel 8 */
#define ADC_AnyChannel_9                 0x09 /*!< ADC AnyChannel 9 */
#define ADC_AnyChannel_10                0x0A /*!< ADC AnyChannel 10 */

#define ADC_InjectedChannel_0            0x00
#define ADC_InjectedChannel_1            0x01
#define ADC_InjectedChannel_2            0x02
#define ADC_InjectedChannel_3            0x03

/**
  * @brief ADC_Sampling_Times
  */
#define ADC_SampleTime_2_5          ((uint8_t)0x00) /*!< ADC sample time select 2.5t */
#define ADC_SampleTime_8_5          ((uint8_t)0x01) /*!< ADC sample time select 8.5t */
#define ADC_SampleTime_14_5         ((uint8_t)0x02) /*!< ADC sample time select 14.5t */
#define ADC_SampleTime_29_5         ((uint8_t)0x03) /*!< ADC sample time select 29.5t */
#define ADC_SampleTime_42_5         ((uint8_t)0x04) /*!< ADC sample time select 42.5t */
#define ADC_SampleTime_56_5         ((uint8_t)0x05) /*!< ADC sample time select 56.5t */
#define ADC_SampleTime_72_5         ((uint8_t)0x06) /*!< ADC sample time select 72.5t */
#define ADC_SampleTime_240_5        ((uint8_t)0x07) /*!< ADC sample time select 240.5t */
#define ADC_SampleTime_3_5          ((uint8_t)0x08) /*!< ADC sample time select 3.5t */
#define ADC_SampleTime_4_5          ((uint8_t)0x09) /*!< ADC sample time select 4.5t */
#define ADC_SampleTime_5_5          ((uint8_t)0x0A) /*!< ADC sample time select 5.5t */
#define ADC_SampleTime_6_5          ((uint8_t)0x0B) /*!< ADC sample time select 6.5t */
#define ADC_SampleTime_7_5          ((uint8_t)0x0C) /*!< ADC sample time select 7.5t */


/**
  * @brief ADC_Trig_Shift
  */
#define ADC_ExtTrig_Shift_0               (0x00U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 0 */
#define ADC_ExtTrig_Shift_4               (0x01U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 4 */
#define ADC_ExtTrig_Shift_16              (0x02U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 16 */
#define ADC_ExtTrig_Shift_32              (0x03U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 32 */
#define ADC_ExtTrig_Shift_64              (0x04U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 64 */
#define ADC_ExtTrig_Shift_128             (0x05U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 128 */
#define ADC_ExtTrig_Shift_256             (0x06U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 256 */
#define ADC_ExtTrig_Shift_512             (0x07U << ADC_ADCR_TRGSHIFT_Pos)     /*!< ADC trig shift bit is 512 */

/**
  * @brief ADC_InjectedTrig_Shift
  */
#define ADC_InjectedExtTrig_Shift_0       (0x00U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 0 */
#define ADC_InjectedExtTrig_Shift_4       (0x01U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 4 */
#define ADC_InjectedExtTrig_Shift_16      (0x02U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 16 */
#define ADC_InjectedExtTrig_Shift_32      (0x03U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 32 */
#define ADC_InjectedExtTrig_Shift_64      (0x04U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 64 */
#define ADC_InjectedExtTrig_Shift_128     (0x05U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 128 */
#define ADC_InjectedExtTrig_Shift_256     (0x06U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 256 */
#define ADC_InjectedExtTrig_Shift_512     (0x07U << ADC_ANY_CR_JTRGSHIFT_Pos)/*!< ADC injected trigger shift bit is 512 */


/**
  * @brief ADC_ExtTrig_Edge
  */
#define ADC_ExtTrig_Edge_Dual             (0x00U << ADC_ADCR_TRG_EDGE_Pos)/*!< ADC trig edge dual mode down and up */
#define ADC_ExtTrig_Edge_Down             (0x01U << ADC_ADCR_TRG_EDGE_Pos)/*!< ADC trig edge single mode down */
#define ADC_ExtTrig_Edge_Up               (0x02U << ADC_ADCR_TRG_EDGE_Pos)/*!< ADC trig edge single mode up */


/**
  * @brief ADC_InjectedExtTrig_Edge
  */
#define ADC_InjectedExtTrig_Edge_Dual     (0x00U << ADC_ANY_CR_JTRGEDGE_Pos) /*!< ADC injected trig edge dual mode down and up */
#define ADC_InjectedExtTrig_Edge_Down     (0x01U << ADC_ANY_CR_JTRGEDGE_Pos) /*!< ADC injected trig edge single mode down */
#define ADC_InjectedExtTrig_Edge_Up       (0x02U << ADC_ANY_CR_JTRGEDGE_Pos) /*!< ADC injected trig edge single mode up */
#define ADC_InjectedExtTrig_Mask          (0x03U << ADC_ANY_CR_JTRGEDGE_Pos) /*!< Mask injected trig  */


/**
  * @}
  */



/** @defgroup ADC_Exported_Functions
  * @{
  */
void ADC_DeInit(ADC_TypeDef* adc);
void ADC_Init(ADC_TypeDef* adc, ADC_InitTypeDef* init_struct);
void ADC_StructInit(ADC_InitTypeDef* init_struct);
void ADC_Cmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_DMACmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* adc, FunctionalState state);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* adc);

void ADC_SampleTimeConfig(ADC_TypeDef *adc, uint8_t channel,  uint8_t sample_time);
void ADC_ChannelCmd(ADC_TypeDef *adc, uint8_t channel, FunctionalState state);

void ADC_ExternalTrigConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_ExternalTrigSourceConfig(ADC_TypeDef *adc, uint32_t trig_source,uint32_t trig_edge, uint32_t shift);


uint16_t ADC_GetConversionValue(ADC_TypeDef* adc);
uint16_t ADC_GetChannelConvertedValue(ADC_TypeDef *adc, uint8_t channel);

void ADC_AnalogWatchdogCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef *adc, uint16_t high_threshold, uint16_t low_threshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef *adc, uint8_t channel);

void ADC_TempSensorCmd(FunctionalState state);
void ADC_VrefSensorCmd(FunctionalState state);

void ADC_AnyChannelSelect(ADC_TypeDef* adc, uint8_t anychannel, uint8_t channel);
void ADC_AnyChannelNumCfg(ADC_TypeDef* adc, uint8_t num);
void ADC_AnyChannelCmd(ADC_TypeDef* adc, FunctionalState state);

void ADC_ITConfig(ADC_TypeDef* adc, uint32_t adc_interrupt, FunctionalState state);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* adc, uint32_t adc_flag);
void ADC_ClearFlag(ADC_TypeDef* adc, uint32_t adc_flag);
ITStatus ADC_GetITStatus(ADC_TypeDef* adc, uint32_t adc_interrupt);
void ADC_ClearITPendingBit(ADC_TypeDef* adc, uint32_t adc_interrupt);

void ADC_AutoInjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);

void ADC_InjectedExternalTrigSourceConfig(ADC_TypeDef* adc, uint32_t trig_source,uint32_t trig_edge, uint32_t shift);
void ADC_InjectedExternalTrigConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_InjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_InjectedChannelNumCfg(ADC_TypeDef *adc, uint8_t num);
void ADC_InjectedChannelSelect(ADC_TypeDef* adc, uint8_t injected_channel, uint8_t channel);

uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* adc);
uint16_t ADC_GetInjectedChannelConvertedValue(ADC_TypeDef *adc, uint8_t injected_channel);
void ADC_InjectedChannelOffsetCfg(ADC_TypeDef* adc, uint8_t injected_channel, uint16_t value);
uint16_t ADC_GetInjectedChannelOffset(ADC_TypeDef* adc, uint8_t injected_channel);

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

