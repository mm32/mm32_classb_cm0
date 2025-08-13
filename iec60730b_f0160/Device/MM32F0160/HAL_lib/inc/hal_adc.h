/*
 *******************************************************************************
    @file     hal_adc.h
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
#ifndef __HAL_ADC_H
#define __HAL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

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
  * @brief ADC_Channels
  */
typedef enum {
    ADC_Channel_0                       = 0x00,                                 /*!< ADC Channel 0 */
    ADC_Channel_1                       = 0x01,                                 /*!< ADC Channel 1 */
    ADC_Channel_2                       = 0x02,                                 /*!< ADC Channel 2 */
    ADC_Channel_3                       = 0x03,                                 /*!< ADC Channel 3 */
    ADC_Channel_4                       = 0x04,                                 /*!< ADC Channel 4 */
    ADC_Channel_5                       = 0x05,                                 /*!< ADC Channel 5 */
    ADC_Channel_6                       = 0x06,                                 /*!< ADC Channel 6 */
    ADC_Channel_7                       = 0x07,                                 /*!< ADC Channel 7 */

    ADC_Channel_8                       = 0x08,                                 /*!< ADC Channel 8 */
    ADC_Channel_9                       = 0x09,                                 /*!< ADC Channel 9 */
    ADC_Channel_10                      = 0x0A,                                 /*!< ADC Channel 10 */
    ADC_Channel_11                      = 0x0B,                                 /*!< ADC Channel 11 */
    ADC_Channel_12                      = 0x0C,                                 /*!< ADC Channel 12 */
    ADC_Channel_13                      = 0x0D,                                 /*!< ADC Channel 13 */
    ADC_Channel_14                      = 0x0E,                                 /*!< ADC Channel 14 */
    ADC_Channel_15                      = 0x0F,                                 /*!< ADC Channel 15 */

    ADC_Channel_TempSensor              = 0x0E,                                 /*!< Temperature sensor channel */
    ADC_Channel_VoltReference           = 0x0F,                                 /*!< Internal reference voltage(ADC1) channel */
    ADC_Channel_Vrefint                 = 0x0F,                                 /*!< Internal reference voltage(ADC1) channel */
} ADCCHANNEL_TypeDef;

/**
  * @brief ADC_Sampling_Times
  */
typedef enum {
    ADC_Samctl_2_5                      = ADC_SMPR_SAMP_2_5,                    /*!< ADC sample time select 2.5t */
    ADC_Samctl_8_5                      = ADC_SMPR_SAMP_8_5,                    /*!< ADC sample time select 8.5t */
    ADC_Samctl_14_5                     = ADC_SMPR_SAMP_14_5,                   /*!< ADC sample time select 14.5t */
    ADC_Samctl_29_5                     = ADC_SMPR_SAMP_29_5,                   /*!< ADC sample time select 29.5t */
    ADC_Samctl_42_5                     = ADC_SMPR_SAMP_42_5,                   /*!< ADC sample time select 42.5t */
    ADC_Samctl_56_5                     = ADC_SMPR_SAMP_56_5,                   /*!< ADC sample time select 56.5t */
    ADC_Samctl_72_5                     = ADC_SMPR_SAMP_72_5,                   /*!< ADC sample time select 72.5t */
    ADC_Samctl_240_5                    = ADC_SMPR_SAMP_240_5,                  /*!< ADC sample time select 240.5t */
    ADC_Samctl_3_5                      = ADC_SMPR_SAMP_3_5,                    /*!< ADC sample time select 3.5t */
    ADC_Samctl_4_5                      = ADC_SMPR_SAMP_4_5,                    /*!< ADC sample time select 4.5t */
    ADC_Samctl_5_5                      = ADC_SMPR_SAMP_5_5,                    /*!< ADC sample time select 5.5t */
    ADC_Samctl_6_5                      = ADC_SMPR_SAMP_6_5,                    /*!< ADC sample time select 5.5t */
    ADC_Samctl_7_5                      = ADC_SMPR_SAMP_7_5                     /*!< ADC sample time select 5.5t */
} ADCSAM_TypeDef;

/**
  * @brief ADC_Resolution
  */
typedef enum {
    ADC_Resolution_12b                  = ADC_ADCFG_RSLTCTL_12,                 /*!< ADC resolution select 12bit */
    ADC_Resolution_11b                  = ADC_ADCFG_RSLTCTL_11,                 /*!< ADC resolution select 11bit */
    ADC_Resolution_10b                  = ADC_ADCFG_RSLTCTL_10,                 /*!< ADC resolution select 10bit */
    ADC_Resolution_9b                   = ADC_ADCFG_RSLTCTL_9,                  /*!< ADC resolution select 9bit */
    ADC_Resolution_8b                   = ADC_ADCFG_RSLTCTL_8                   /*!< ADC resolution select 8bit */
} ADCRSL_TypeDef;

/**
  * @brief ADC_Prescare
  */
typedef enum {
    ADC_PCLK2_PRESCARE_3                = ADC_ADCFG_ADCPRE_3,                   /*!< ADC preclk 3 */
    ADC_PCLK2_PRESCARE_5                = ADC_ADCFG_ADCPRE_5,                   /*!< ADC preclk 5 */
    ADC_PCLK2_PRESCARE_7                = ADC_ADCFG_ADCPRE_7,                   /*!< ADC preclk 7 */
    ADC_PCLK2_PRESCARE_9                = ADC_ADCFG_ADCPRE_9,                   /*!< ADC preclk 9 */
    ADC_PCLK2_PRESCARE_11               = ADC_ADCFG_ADCPRE_11,                  /*!< ADC preclk 11 */
    ADC_PCLK2_PRESCARE_13               = ADC_ADCFG_ADCPRE_13,                  /*!< ADC preclk 13 */
    ADC_PCLK2_PRESCARE_15               = ADC_ADCFG_ADCPRE_15,                  /*!< ADC preclk 15 */
    ADC_PCLK2_PRESCARE_17               = ADC_ADCFG_ADCPRE_17,                  /*!< ADC preclk 17 */

    ADC_PCLK2_PRESCARE_2                = ADC_ADCFG_ADCPRE_2,                   /*!< ADC preclk 2 */
    ADC_PCLK2_PRESCARE_4                = ADC_ADCFG_ADCPRE_4,                   /*!< ADC preclk 4 */
    ADC_PCLK2_PRESCARE_6                = ADC_ADCFG_ADCPRE_6,                   /*!< ADC preclk 6 */
    ADC_PCLK2_PRESCARE_8                = ADC_ADCFG_ADCPRE_8,                   /*!< ADC preclk 8 */
    ADC_PCLK2_PRESCARE_10               = ADC_ADCFG_ADCPRE_10,                  /*!< ADC preclk 10 */
    ADC_PCLK2_PRESCARE_12               = ADC_ADCFG_ADCPRE_12,                  /*!< ADC preclk 12 */
    ADC_PCLK2_PRESCARE_14               = ADC_ADCFG_ADCPRE_14,                  /*!< ADC preclk 14 */
    ADC_PCLK2_PRESCARE_16               = ADC_ADCFG_ADCPRE_16                   /*!< ADC preclk 16 */
} ADCPRE_TypeDef;

/**
  * @brief ADC_Conversion_Mode
  */
typedef enum {
    ADC_Mode_Imm                        = ADC_ADCR_ADMD_IMM,                     /*!< ADC single convert mode */
    ADC_Mode_Scan                       = ADC_ADCR_ADMD_SCAN,                    /*!< ADC single period convert mode */
    ADC_Mode_Continue                   = ADC_ADCR_ADMD_CONTINUE                 /*!< ADC continue scan convert mode */
} ADCMODE_TypeDef;

/**
  * @brief ADC_Extrenal_Trigger_Sources_For_Regular_Channels_Conversion
  */
typedef enum {
    ADC1_ExternalTrigConv_T1_CC1        = ADC_ADCR_TRGSEL_T1_CC1,
    ADC1_ExternalTrigConv_T1_CC2        = ADC_ADCR_TRGSEL_T1_CC2,
    ADC1_ExternalTrigConv_T1_CC3        = ADC_ADCR_TRGSEL_T1_CC3,
    ADC1_ExternalTrigConv_T2_CC2        = ADC_ADCR_TRGSEL_T2_CC2,
    ADC1_ExternalTrigConv_T3_TRIG       = ADC_ADCR_TRGSEL_T3_TRIG,
    ADC1_ExternalTrigConv_T1_CC4_CC5    = ADC_ADCR_TRGSEL_T1_CC4_CC5,
    ADC1_ExternalTrigConv_T3_CC1        = ADC_ADCR_TRGSEL_T3_CC1,
    ADC1_ExternalTrigConv_EXTI_11       = ADC_ADCR_TRGSEL_EXTI_11,
    ADC1_ExternalTrigConv_T1_TRIG       = ADC_ADCR_TRGSEL_T1_TRIG,
    ADC1_ExternalTrigConv_EXTI_4        = ADC_ADCR_TRGSEL_EXTI_4,
    ADC1_ExternalTrigConv_EXTI_5        = ADC_ADCR_TRGSEL_EXTI_5,
    ADC1_ExternalTrigConv_T2_CC1        = ADC_ADCR_TRGSEL_T2_CC1,
    ADC1_ExternalTrigConv_T3_CC4        = ADC_ADCR_TRGSEL_T3_CC4,
    ADC1_ExternalTrigConv_T2_TRIG       = ADC_ADCR_TRGSEL_T2_TRIG,
    ADC1_ExternalTrigConv_EXTI_15       = ADC_ADCR_TRGSEL_EXTI_15,
    ADC1_ExternalTrigConv_T1_CC4        = ADC_ADCR_TRGSEL_T1_CC4,
    ADC1_ExternalTrigConv_T1_CC5        = ADC_ADCR_TRGSEL_T1_CC5
} EXTERTRIG_TypeDef;

/**
  * @brief ADC_Data_Align
  */
typedef enum {
    ADC_DataAlign_Right                 = ADC_ADCR_RIGHT,                       /*!< ADC data right align */
    ADC_DataAlign_Left                  = ADC_ADCR_LEFT                         /*!< ADC data left align */
} ADCDATAALI_TypeDef;

/**
  * @brief ADC_Flags_Definition
  */
typedef enum {
    ADC_IT_ENDOFCONVSEQUENCE            = 1,
    ADC_IT_ANALOGWATCHDOG               = 2,
    ADC_IT_ENDOFCONVSINGLE              = 3,
    ADC_IT_ENDOFCONVSAMPLE              = 4,
    ADC_IT_INJENDOFCONVSINGLE           = 5,
    ADC_IT_INJENDOFCONVSAMPLE           = 6,
    ADC_IT_INJENDOFCONVSEQUENCE         = 7,
    ADC_IT_ENDOFCONVCALIBRATION         = 8,
    ADC_FLAG_ENDOFCONVSEQUENCE          = 1,
    ADC_FLAG_ANALOGWATCHDOG             = 2,
    ADC_FLAG_ENDOFCONVSINGLE            = 3,
    ADC_FLAG_ENDOFCONVSAMPLE            = 4,
    ADC_FLAG_INJENDOFCONVSINGLE         = 5,
    ADC_FLAG_INJENDOFCONVSAMPLE         = 6,
    ADC_FLAG_INJENDOFCONVSEQUENCE       = 7,
    ADC_FLAG_ENDOFCONVCALIBRATION       = 8
} ADCFLAG_TypeDef;

/**
  * @brief ADC_Trig_Edge
  */
typedef enum {
    ADC_Trig_Edge_Dual                  = ADC_ADCR_TRG_EDGE_DUAL,               /*!< ADC trig edge dual mode down and up */
    ADC_Trig_Edge_Down                  = ADC_ADCR_TRG_EDGE_DOWN,               /*!< ADC trig edge single mode down */
    ADC_Trig_Edge_Up                    = ADC_ADCR_TRG_EDGE_UP,                 /*!< ADC trig edge single mode up */
    ADC_Trig_Edge_Mask                  = ADC_ADCR_TRG_EDGE_MASK,               /*!< ADC trig edge is mask, not allowed */
    ADC_ADC_Trig_Edge_Dual              = ADC_ADCR_TRG_EDGE_DUAL,               /*!< ADC trig edge dual mode down and up */
    ADC_ADC_Trig_Edge_Down              = ADC_ADCR_TRG_EDGE_DOWN,               /*!< ADC trig edge single mode down */
    ADC_ADC_Trig_Edge_Up                = ADC_ADCR_TRG_EDGE_UP,                 /*!< ADC trig edge single mode up */
    ADC_ADC_Trig_Edge_Mask              = ADC_ADCR_TRG_EDGE_MASK                /*!< ADC trig edge is mask, not allowed */
} ADCTRIGEDGE_TypeDef, ADCTRIGEDGE_TypeEnum;

/**
  * @brief ADC_Scan_Direct
  */
typedef enum {
    ADC_Scan_Direct_Up                  = ADC_ADCR_SCANDIR,                     /*!< ADC scan from low channel to high channel */
    ADC_Scan_Direct_Down                = 0                                     /*!< ADC scan from High channel to low channel */
} ADCSCANDIRECT_TypeDef;

/**
  * @brief ADC_Trig_Shift
  */
typedef enum {
    ADC_Trig_Shift_0                    = ADC_ADCR_TRGSHIFT_0,                  /*!< ADC trig shift bit is 0 */
    ADC_Trig_Shift_4                    = ADC_ADCR_TRGSHIFT_4,                  /*!< ADC trig shift bit is 4 */
    ADC_Trig_Shift_16                   = ADC_ADCR_TRGSHIFT_16,                 /*!< ADC trig shift bit is 16 */
    ADC_Trig_Shift_32                   = ADC_ADCR_TRGSHIFT_32,                 /*!< ADC trig shift bit is 32 */
    ADC_Trig_Shift_64                   = ADC_ADCR_TRGSHIFT_64,                 /*!< ADC trig shift bit is 64 */
    ADC_Trig_Shift_128                  = ADC_ADCR_TRGSHIFT_128,                /*!< ADC trig shift bit is 128 */
    ADC_Trig_Shift_256                  = ADC_ADCR_TRGSHIFT_256,                /*!< ADC trig shift bit is 256 */
    ADC_Trig_Shift_512                  = ADC_ADCR_TRGSHIFT_512,                /*!< ADC trig shift bit is 512 */
    ADC_ADC_Trig_Shift_0                = ADC_ADCR_TRGSHIFT_0,                  /*!< ADC trig shift bit is 0 */
    ADC_ADC_Trig_Shift_4                = ADC_ADCR_TRGSHIFT_4,                  /*!< ADC trig shift bit is 4 */
    ADC_ADC_Trig_Shift_16               = ADC_ADCR_TRGSHIFT_16,                 /*!< ADC trig shift bit is 16 */
    ADC_ADC_Trig_Shift_32               = ADC_ADCR_TRGSHIFT_32,                 /*!< ADC trig shift bit is 32 */
    ADC_ADC_Trig_Shift_64               = ADC_ADCR_TRGSHIFT_64,                 /*!< ADC trig shift bit is 64 */
    ADC_ADC_Trig_Shift_128              = ADC_ADCR_TRGSHIFT_128,                /*!< ADC trig shift bit is 128 */
    ADC_ADC_Trig_Shift_256              = ADC_ADCR_TRGSHIFT_256,                /*!< ADC trig shift bit is 256 */
    ADC_ADC_Trig_Shift_512              = ADC_ADCR_TRGSHIFT_512                 /*!< ADC trig shift bit is 512 */
} ADCTRIGSHIFT_TypeDef, ADCTRIGSHIFT_TypeEnum;

/**
  * @brief ADC_Inject_Sequence_Length the sequencer length for injected channels
  */
typedef enum {
    ADC_Inject_Seqen_Len1               = 0,                                    /*!< ADC Injected Seqence length is 1 */
    ADC_Inject_Seqen_Len2               = 1,                                    /*!< ADC Injected Seqence length is 2 */
    ADC_Inject_Seqen_Len3               = 2,                                    /*!< ADC Injected Seqence length is 3 */
    ADC_Inject_Seqen_Len4               = 3,                                    /*!< ADC Injected Seqence length is 4 */
} ADC_INJ_SEQ_LEN_TypeDef;

/**
  * @brief ADC_Inject_Sequence_Length the sequencer length for injected channels
  */
typedef enum {
    ADC_InjectedChannel_1               = 0x00,
    ADC_InjectedChannel_2               = 0x01,
    ADC_InjectedChannel_3               = 0x02,
    ADC_InjectedChannel_4               = 0x03,
} ADC_INJ_SEQ_Channel_TypeDef;

/**
  * @brief ADC_Extrenal_Trigger_Sources_For_Regular_Channels_Conversion
  */
typedef enum {
    ADC1_InjectExtTrigSrc_T1_CC1        = ADC_ANY_CR_JTRGSEL_TIM1_CC1,          /*!< TIM1  CC1 */
    ADC1_InjectExtTrigSrc_T1_CC2        = ADC_ANY_CR_JTRGSEL_TIM1_CC2,          /*!< TIM1  CC2 */
    ADC1_InjectExtTrigSrc_T1_CC3        = ADC_ANY_CR_JTRGSEL_TIM1_CC3,          /*!< TIM1  CC3 */
    ADC1_InjectExtTrigSrc_T2_CC2        = ADC_ANY_CR_JTRGSEL_TIM2_CC2,          /*!< TIM2  CC2 */
    ADC1_InjectExtTrigSrc_T3_TRGO       = ADC_ANY_CR_JTRGSEL_TIM3_TRGO,         /*!< TIM3  TRGO */
    ADC1_InjectExtTrigSrc_T1_CC4_CC5    = ADC_ANY_CR_JTRGSEL_TIM1_CC4_CC5,      /*!< TIM1  CC4 CC5 */
    ADC1_InjectExtTrigSrc_T3_CC1        = ADC_ANY_CR_JTRGSEL_TIM3_CC1,          /*!< TIM3  CC1 */
    ADC1_InjectExtTrigSrc_EXTI11        = ADC_ANY_CR_JTRGSEL_EXTI11,            /*!< EXTI11 */
    ADC1_InjectExtTrigSrc_T1_TRGO       = ADC_ANY_CR_JTRGSEL_TIM1_TRGO,         /*!< TIM1  TRGO */
    ADC1_InjectExtTrigSrc_EXTI4         = ADC_ANY_CR_JTRGSEL_EXTI4,             /*!< EXTI4 */
    ADC1_InjectExtTrigSrc_EXTI5         = ADC_ANY_CR_JTRGSEL_EXTI5,             /*!< EXTI5 */
    ADC1_InjectExtTrigSrc_T2_CC1        = ADC_ANY_CR_JTRGSEL_TIM2_CC1,          /*!< TIM2  CC1 */
    ADC1_InjectExtTrigSrc_T3_CC4        = ADC_ANY_CR_JTRGSEL_TIM3_CC4,          /*!< TIM3  CC4 */
    ADC1_InjectExtTrigSrc_T2_TRGO       = ADC_ANY_CR_JTRGSEL_TIM2_TRGO,         /*!< TIM2 TRGO */
    ADC1_InjectExtTrigSrc_EXTI15        = ADC_ANY_CR_JTRGSEL_EXTI15,            /*!< EXTI15 */
    ADC1_InjectExtTrigSrc_T1_CC4        = ADC_ANY_CR_JTRGSEL_TIM1_CC4,          /*!< TIM1  CC4 */
    ADC1_InjectExtTrigSrc_T1_CC5        = ADC_ANY_CR_JTRGSEL_TIM1_CC5           /*!< TIM1  CC5 */
} EXTER_INJ_TRIG_TypeDef;

/**
  * @brief ADC Init Structure definition
  */
typedef struct {
    uint32_t                            ADC_Resolution;                         /*!< Convert data resolution */
    uint32_t                            ADC_PRESCARE;                           /*!< Clock prescaler */
    uint32_t                            ADC_Mode;                               /*!< ADC conversion mode */
    FunctionalState                     ADC_ContinuousConvMode;                 /*!< Useless just for compatibility */
    uint32_t                            ADC_ExternalTrigConv;                   /*!< External trigger source selection */
    uint32_t                            ADC_DataAlign;                          /*!< Data alignmentn */
} ADC_InitTypeDef;

#define ADC_ExternalTrigConv_T1_CC1     ADC1_ExternalTrigConv_T1_CC1
#define ADC_ExternalTrigConv_T1_CC2     ADC1_ExternalTrigConv_T1_CC2
#define ADC_ExternalTrigConv_T1_CC3     ADC1_ExternalTrigConv_T1_CC3
#define ADC_ExternalTrigConv_T2_CC2     ADC1_ExternalTrigConv_T2_CC2
#define ADC_ExternalTrigConv_T3_TRIG    ADC1_ExternalTrigConv_T3_TRIG
#define ADC_ExternalTrigConv_T3_CC1     ADC1_ExternalTrigConv_T3_CC1
#define ADC_ExternalTrigConv_EXTI_11    ADC1_ExternalTrigConv_EXTI_11

/**
  * @}
  */

/** @defgroup ADC_Exported_Variables
  * @{
  */
#ifdef _HAL_ADC_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL
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
void ADC_ITConfig(ADC_TypeDef* adc, ADCFLAG_TypeDef adc_interrupt, FunctionalState state);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_RegularChannelConfig(ADC_TypeDef* adc, ADCCHANNEL_TypeDef channel, uint8_t anychan, uint32_t sample_time);
void ADC_AnychanChannelConfig(ADC_TypeDef* adc, ADCCHANNEL_TypeDef channel, uint8_t anychan, uint32_t sample_time);
void ADC_ChannelSampleConfig(ADC_TypeDef* adc, ADCCHANNEL_TypeDef channel, uint32_t sample_time);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_ExternalTrigConvConfig(ADC_TypeDef* adc, EXTERTRIG_TypeDef adc_external_trig_source);
#define ADC_ExternalTrigInjectedConvConfig ADC_ExternalTrigConvConfig
void ADC_AnalogWatchdogCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* adc, uint16_t high_threshold, uint16_t low_threshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* adc, ADCCHANNEL_TypeDef channel);
void ADC_TempSensorVrefintCmd(FunctionalState state);
void ADC_ClearITPendingBit(ADC_TypeDef* adc, ADCFLAG_TypeDef adc_interrupt);
void ADC_ClearFlag(ADC_TypeDef* adc, ADCFLAG_TypeDef adc_flag);

uint16_t ADC_GetConversionValue(ADC_TypeDef* adc);

FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* adc);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* adc, ADCFLAG_TypeDef adc_flag);
ITStatus   ADC_GetITStatus(ADC_TypeDef* adc, ADCFLAG_TypeDef adc_interrupt);
void ADC_TempSensorCmd(FunctionalState state);
void ADC_VrefintCmd(FunctionalState state);
void exADC_TempSensorVrefintCmd(uint32_t chs, FunctionalState state);
void ADC_ANY_CH_Config(ADC_TypeDef* adc, uint8_t anychan, ADCCHANNEL_TypeDef channel);
void ADC_ANY_NUM_Config(ADC_TypeDef* adc, uint8_t num);
void ADC_ANY_Cmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_ExternalTrigInjectedConvertConfig(ADC_TypeDef* adc, EXTER_INJ_TRIG_TypeDef ADC_ExtInjTrigSource);
void ADC_InjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* adc, FunctionalState state);
void ADC_InjectedSequencerConfig(ADC_TypeDef* adc, uint32_t source, uint32_t shift);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* adc, ADC_INJ_SEQ_LEN_TypeDef Length);
void ADC_InjectedSequencerChannelConfig(ADC_TypeDef* adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel, ADCCHANNEL_TypeDef channel);
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel);
uint16_t ADC_GetInjectedCurrentConvertedValue(ADC_TypeDef* adc);
void ADC_SetInjectedOffset(ADC_TypeDef* adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel, uint16_t value);
uint16_t ADC_GetInjectedOffset(ADC_TypeDef* adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel);
uint16_t ADC_GetChannelConvertedValue(ADC_TypeDef* adc, ADCCHANNEL_TypeDef channel);
uint16_t ADC_GetInjectedAnychanConvertedValue(ADC_TypeDef* adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel);

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

