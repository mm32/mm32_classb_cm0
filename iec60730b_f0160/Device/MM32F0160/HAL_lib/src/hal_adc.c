/*
 *******************************************************************************
    @file     hal_adc.c
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
#define _HAL_ADC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_adc.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup ADC_HAL
  * @{
  */

/** @addtogroup ADC_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the adc peripheral registers to their default
  *         reset values.
  * @param  adc: select the ADC peripheral.
  * @retval None.
  */
void ADC_DeInit(ADC_TypeDef *adc)
{
    switch (*(uint32_t *)&adc)
    {
        case ADC1_BASE:
             /* Enable ADC1 reset state */
            RCC_APB2PeriphResetCmd(RCC_APB2ENR_ADC, ENABLE);
             /* Release ADC1 from reset state */
            RCC_APB2PeriphResetCmd(RCC_APB2ENR_ADC, DISABLE);
            break;

        default:
            break;
    }
}

/**
  * @brief  Initializes the adc peripheral according to the specified parameters
  *         in the init_struct, Please use this function if you want to be
  *         compatible with older versions of the library.
  * @param  adc: select the ADC peripheral.
  * @param  init_struct: pointer to an ADC_InitTypeDef structure that contains
  *         the configuration information for the specified ADC peripheral.
  * @retval None.
  */
void ADC_Init(ADC_TypeDef *adc, ADC_InitTypeDef *init_struct)
{
    adc->ADCFG &= ~(ADC_ADCFG_ADCPRE | ADC_ADCFG_RSLTCTL);
    adc->ADCFG |= (u32)(init_struct->ADC_PRESCARE) | init_struct->ADC_Resolution;

    adc->ADCR &= ~(ADC_ADCR_ALIGN | ADC_ADCR_ADMD | ADC_ADCR_TRGSEL);
    adc->ADCR |= ((u32)init_struct->ADC_DataAlign) | init_struct->ADC_ExternalTrigConv | ((u32)init_struct->ADC_Mode);
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct : pointer to an ADC_InitTypeDef structure which will be
  *         initialized.
  * @retval None.
  */
void ADC_StructInit(ADC_InitTypeDef *init_struct)
{
    init_struct->ADC_Resolution         = ADC_Resolution_12b;
    init_struct->ADC_PRESCARE           = ADC_PCLK2_PRESCARE_2;
    init_struct->ADC_Mode               = ADC_ADCR_ADMD_IMM; /*!<ADC_Mode_Single; */
    init_struct->ADC_ContinuousConvMode = DISABLE;           /*!< useless */
    init_struct->ADC_ExternalTrigConv   = ADC1_ExternalTrigConv_T1_CC1;
    init_struct->ADC_DataAlign          = ADC_DataAlign_Right;
}

/**
  * @brief  Enables or disables the specified ADC peripheral.
  * @param  adc:select the ADC peripheral.
  * @param  state: new state of the adc peripheral.
  * @retval None.
  */
void ADC_Cmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ADCFG |= ADC_ADCFG_ADEN) : (adc->ADCFG &= ~ADC_ADCFG_ADEN);
}

/**
  * @brief  Enables or disables the specified ADC DMA request.
  * @param  adc: select the ADC peripheral.
  * @param  state: New state of the selected ADC DMA transfer.
  * @retval None.
  */
void ADC_DMACmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ADCR |= ADC_ADCR_DMAEN) : (adc->ADCR &= ~ADC_ADCR_DMAEN);
}

/**
  * @brief  Enables or disables the specified ADC interrupts.
  * @param  adc: select the ADC peripheral.
  * @param  adc_interrupt: specifies the ADC interrupt sources to be enabled or disabled.
  * @param  state: New state of the specified ADC interrupts.
  * @retval None.
  */
void ADC_ITConfig(ADC_TypeDef *adc, ADCFLAG_TypeDef adc_interrupt, FunctionalState state)
{
    if (state)
    {
        if (ADC_IT_ENDOFCONVSEQUENCE == adc_interrupt)
        {
            adc->ADCR |= ADC_ADCR_EOSIE;
        }
        else if (ADC_IT_ANALOGWATCHDOG == adc_interrupt)
        {
            adc->ADCR |= ADC_ADCR_AWDIE;
        }
        else if (ADC_IT_ENDOFCONVSINGLE == adc_interrupt)
        {
            adc->ADCR |= ADC_ADCR_EOCIE;
        }
        else if (ADC_IT_ENDOFCONVSAMPLE == adc_interrupt)
        {
            adc->ADCR |= ADC_ADCR_EOSMPIE;
        }
        else if (ADC_IT_INJENDOFCONVSEQUENCE == adc_interrupt)
        {
            adc->ANY_CR |= ADC_ANY_CR_JEOSIE;
        }
        else if (ADC_IT_INJENDOFCONVSINGLE == adc_interrupt)
        {
            adc->ANY_CR |= ADC_ANY_CR_JEOCIE;
        }
        else if (ADC_IT_INJENDOFCONVSAMPLE == adc_interrupt)
        {
            adc->ANY_CR |= ADC_ANY_CR_JEOSMPIE;
        }
    }
    else
    {
        if (ADC_IT_ENDOFCONVSEQUENCE == adc_interrupt)
        {
            adc->ADCR &= ~ADC_ADCR_EOSIE;
        }
        else if (ADC_IT_ANALOGWATCHDOG == adc_interrupt)
        {
            adc->ADCR &= ~ADC_ADCR_AWDIE;
        }
        else if (ADC_IT_ENDOFCONVSINGLE == adc_interrupt)
        {
            adc->ADCR &= ~ADC_ADCR_EOCIE;
        }
        else if (ADC_IT_ENDOFCONVSAMPLE == adc_interrupt)
        {
            adc->ADCR &= ~ADC_ADCR_EOSMPIE;
        }
        else if (ADC_IT_INJENDOFCONVSEQUENCE == adc_interrupt)
        {
            adc->ANY_CR &= ~ADC_ANY_CR_JEOSIE;
        }
        else if (ADC_IT_INJENDOFCONVSINGLE == adc_interrupt)
        {
            adc->ANY_CR &= ~ADC_ANY_CR_JEOCIE;
        }
        else if (ADC_IT_INJENDOFCONVSAMPLE == adc_interrupt)
        {
            adc->ANY_CR &= ~ADC_ANY_CR_JEOSMPIE;
        }
    }
}

/**
  * @brief  Enables or disables the selected ADC software start conversion .
  * @param  adc:  select the ADC peripheral.
  * @param  state: New state of the selected ADC software start conversion.
  * @retval None.
  */
void ADC_SoftwareStartConvCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ADCR |= ADC_ADCR_ADST) : (adc->ADCR &= ~ADC_ADCR_ADST);
}

/**
  * @brief  Gets the selected ADC Software start conversion Status.
  * @param  adc: select the ADC peripheral.
  * @retval  The new state of ADC software start conversion (SET or RESET).
  */
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef *adc)
{
    return (((adc->ADCR & ADC_ADCR_ADST) != (u32)RESET) ? SET : RESET);
}

/**
  * @brief  Enable the selected ADC channel and configure its sample time. Please
  *         use this function if you want to be compatible with older versions
  *         of the library.
  * @param  adc:  select the ADC peripheral.
  * @param  channel: the ADC channel to configure.
  * @param  sample_time: the ADC Channel n Sample time to configure.
  * @retval None.
  */
void ADC_RegularChannelConfig(ADC_TypeDef *adc, ADCCHANNEL_TypeDef channel, u8 anychan, u32 sample_time)
{
    if (((uint32_t)channel) >= 8)
    {
        MODIFY_FIELD(adc->SMPR2, 4, (((uint32_t)channel) & 0x07UL), sample_time);
    }
    else
    {
        MODIFY_FIELD(adc->SMPR1, 4, ((uint32_t)channel), sample_time);
    }

    adc->ADCHS &= ~(1 << channel);
    adc->ADCHS |= (1 << channel);
}

/**
  * @brief  Enable the selected ADC channel and configure its sample time. Please
  *         use this function if you want to be compatible with older versions
  *         of the library.
  * @param  adc:  select the ADC peripheral.
  * @param  channel: the ADC channel to configure.
  * @param  sample_time: the ADC Channel n Sample time to configure.
  * @retval None.
  */
void ADC_AnychanChannelConfig(ADC_TypeDef *adc, ADCCHANNEL_TypeDef channel, uint8_t anychan, uint32_t sample_time)
{
    if (((uint32_t)channel) >= 8)
    {
        MODIFY_FIELD(adc->SMPR2, 4, (((uint32_t)channel) & 0x07UL), sample_time);
    }
    else
    {
        MODIFY_FIELD(adc->SMPR1, 4, ((uint32_t)channel), sample_time);
    }

    if (anychan >= 8)
    {
        MODIFY_FIELD(adc->CHANY1, 4, ((uint32_t)anychan & 0x07UL), ((uint32_t)channel));
    }
    else
    {
        MODIFY_FIELD(adc->CHANY0, 4, (uint32_t)anychan, ((uint32_t)channel));
    }
}

/**
  * @brief  Enable the selected ADC channel and configure its sample time. Please
  *         use this function if you want to be compatible with older versions
  *         of the library.
  * @param  adc:  select the ADC peripheral.
  * @param  channel: the ADC channel to configure.
  * @param  sample_time: the ADC Channel n Sample time to configure.
  * @retval None.
  */
void ADC_ChannelSampleConfig(ADC_TypeDef *adc, ADCCHANNEL_TypeDef channel, uint32_t sample_time)
{
    if (((uint32_t)channel) >= 8)
    {
        MODIFY_FIELD(adc->SMPR2, 4, (((uint32_t)channel) & 0x07UL), sample_time);
    }
    else
    {
        MODIFY_FIELD(adc->SMPR1, 4, ((uint32_t)channel), sample_time);
    }
}

/**
  * @brief  Enables or disables the adc conversion through external trigger.
  * @param  adc: select the ADC peripheral.
  * @param  state: New state of the selected ADC external trigger.
  * @retval None.
  */
void ADC_ExternalTrigConvCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ADCR |= ADC_ADCR_TRGEN) : (adc->ADCR &= ~ADC_ADCR_TRGEN);
}

/**
  * @brief  Configures the adc external trigger for injected channels conversion.
  * @param  adc:  select the ADC peripheral.
  * @param  adc_external_trig_source: Configuring the external trigger source
  *         for the ADC.
  * @retval None.
  */
void ADC_ExternalTrigConvConfig(ADC_TypeDef *adc, EXTERTRIG_TypeDef adc_external_trig_source)
{
    adc->ADCR &= ~ADC_ADCR_TRGSEL;
    adc->ADCR |= adc_external_trig_source;
}

/**
  * @brief  Returns the last adc conversion result data for regular channel.
  * @param  adc: select the ADC peripheral.
  * @retval The data conversion value.
  */
uint16_t ADC_GetConversionValue(ADC_TypeDef *adc)
{
    return ((uint16_t)adc->ADDATA);
}

/**
  * @brief  Returns the last ADC conversion result data in dual mode.
  * @param  None
  * @retval The Data conversion value.
  */
uint32_t ADC_GetDualModeConversionValue(void)
{
    return (*(__IO uint32_t *)ADC1_BASE);
}

/**
  * @brief  Enables or disables the analog watchdog.
  * @param  adc:  to select the ADC peripheral.
  * @param  state: New state of the selected ADC analog watchdog.
  * @retval None.
  */
void ADC_AnalogWatchdogCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ADCFG |= ADC_ADCFG_ADWEN) : (adc->ADCFG &= ~ADC_ADCFG_ADWEN);
}

/**
  * @brief  Configures the high and low thresholds of the analog watchdog.
  * @param  adc:  select the ADC peripheral.
  * @param  high_threshold: the ADC analog watchdog High threshold value.
  *         This parameter must be a 12bit value.
  * @param  low_threshold: the ADC analog watchdog Low threshold value.
  *         This parameter must be a 12bit value.
  * @retval None.
  */
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef *adc, uint16_t high_threshold, uint16_t low_threshold)
{
    uint32_t tempThreshold;

    tempThreshold  = high_threshold;
    adc->ADCMPR    = (tempThreshold << 16) | low_threshold;
}

/**
  * @brief  Configures the analog watchdog guarded single channel
  * @param  adc: select the ADC peripheral.
  * @param  channel: the ADC channel to configure for the analog watchdog.
  * @retval None.
  */
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef *adc, ADCCHANNEL_TypeDef channel)
{
    adc->ADCR &= ~ADC_ADCR_CMPCH;
    adc->ADCR |= (channel << ADC_ADCR_CMPCH_Pos);
}

/**
  * @brief  Enables or disables the temperature sensor and Vrefint channel.
  * @param  state: New state of the temperature sensorand Vrefint channel.
  * @retval None.
  */
void ADC_TempSensorVrefintCmd(FunctionalState state)
{
    (state) ? (ADC1->ADCFG |= (ADC_ADCFG_TSEN | ADC_ADCFG_VSEN))
    : (ADC1->ADCFG &= ~(ADC_ADCFG_TSEN | ADC_ADCFG_VSEN));
}

/**
  * @brief  Enables or disables the temperature sensor .
  * @param  state: New state of the temperature sensor.
  * @retval None.
  */
void ADC_TempSensorCmd(FunctionalState state)
{
    (state) ? (ADC1->ADCFG |= (ADC_ADCFG_TSEN))
    : (ADC1->ADCFG &= ~(ADC_ADCFG_TSEN));
}

/**
  * @brief  Enables or disables the Vrefint channel.
  * @param  state: New state of the Vrefint channel.
  * @retval None.
  */
void ADC_VrefintCmd(FunctionalState state)
{
    (state) ? (ADC1->ADCFG |= (ADC_ADCFG_VSEN))
    : (ADC1->ADCFG &= ~(ADC_ADCFG_VSEN));
}

/**
  * @brief  Enables or disables the temperature sensor and Vrefint channel.
  * @param  chs: temperature sensor bit & Vrefint bit.
  * @param  state: New state of the temperature sensor.
  * @retval None.
  */
void exADC_TempSensorVrefintCmd(uint32_t chs, FunctionalState state)
{
    if (chs & ADC_ADCHS_CHT)
    {
        (state) ? (ADC1->ADCFG |= ADC_ADCFG_TSEN)
        : (ADC1->ADCFG &= ~ADC_ADCFG_TSEN);
    }
    else if (chs & ADC_ADCHS_CHV)
    {
        (state) ? (ADC1->ADCFG |= ADC_ADCFG_VSEN)
        : (ADC1->ADCFG &= ~ADC_ADCFG_VSEN);
    }
}

/**
  * @brief  Checks whether the specified ADC flag is set or not.
  * @param  adc: select the ADC peripheral.
  * @param  adc_flag: specifies the flag to check.
  * @retval The New state of adc_flag (SET or RESET).
  */
FlagStatus ADC_GetFlagStatus(ADC_TypeDef *adc, ADCFLAG_TypeDef adc_flag)
{
    FlagStatus ret = RESET;

    if (ADC_FLAG_ENDOFCONVSEQUENCE == adc_flag)
    {
        ret = ((adc->ADSTA & ADC_ADSTA_EOSIF) ? SET : RESET);
    }
    else if (ADC_FLAG_ANALOGWATCHDOG == adc_flag)
    {
        ret = ((adc->ADSTA & ADC_ADSTA_AWDIF) ? SET : RESET);
    }
    else if (ADC_FLAG_ENDOFCONVSINGLE == adc_flag)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_EOCIF) ? SET : RESET);
    }
    else if (ADC_FLAG_ENDOFCONVSAMPLE == adc_flag)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_EOSMPIF) ? SET : RESET);
    }
    else if (ADC_FLAG_INJENDOFCONVSEQUENCE == adc_flag)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_JEOSIF) ? SET : RESET);
    }
    else if (ADC_FLAG_INJENDOFCONVSINGLE == adc_flag)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_JEOCIF) ? SET : RESET);
    }
    else if (ADC_FLAG_INJENDOFCONVSAMPLE == adc_flag)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_JEOSMPIF) ? SET : RESET);
    }

    return (ret);
}

/**
  * @brief  Clears the adc's pending flags.
  * @param  adc: select the ADC peripheral.
  * @param  adc_flag: specifies the flag to clear.
  * @retval None.
  */
void ADC_ClearFlag(ADC_TypeDef *adc, ADCFLAG_TypeDef adc_flag)
{
    if (ADC_FLAG_ENDOFCONVSEQUENCE == adc_flag)
    {
        adc->ADSTA = ADC_ADSTA_EOSIF;
    }
    else if (ADC_FLAG_ANALOGWATCHDOG == adc_flag)
    {
        adc->ADSTA = ADC_ADSTA_AWDIF;
    }
    else if (ADC_FLAG_ENDOFCONVSINGLE == adc_flag)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_EOCIF;
    }
    else if (ADC_FLAG_ENDOFCONVSAMPLE == adc_flag)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_EOSMPIF;
    }
    else if (ADC_FLAG_INJENDOFCONVSINGLE == adc_flag)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_JEOCIF;
    }
    else if (ADC_FLAG_INJENDOFCONVSAMPLE == adc_flag)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_JEOSMPIF;
    }
    else if (ADC_FLAG_INJENDOFCONVSEQUENCE == adc_flag)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_JEOSIF;
    }
}

/**
  * @brief  Checks whether the specified adc's interrupt has occurred or not.
  * @param  adc: select the ADC peripheral.
  * @param  adc_interrupt: specifies the ADC interrupt source to check.
  * @retval The new state of adc_interrupt (SET or RESET).
  */
ITStatus ADC_GetITStatus(ADC_TypeDef *adc, ADCFLAG_TypeDef adc_interrupt)
{
    ITStatus ret = RESET;

    if (ADC_IT_ENDOFCONVSEQUENCE == adc_interrupt)
    {
        ret = ((adc->ADSTA & ADC_ADSTA_EOSIF) ? SET : RESET);
    }
    else if (ADC_IT_ANALOGWATCHDOG == adc_interrupt)
    {
        ret = ((adc->ADSTA & ADC_ADSTA_AWDIF) ? SET : RESET);
    }
    else if (ADC_IT_ENDOFCONVSINGLE == adc_interrupt)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_EOCIF) ? SET : RESET);
    }
    else if (ADC_IT_ENDOFCONVSAMPLE == adc_interrupt)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_EOSMPIF) ? SET : RESET);
    }
    else if (ADC_IT_INJENDOFCONVSEQUENCE == adc_interrupt)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_JEOSIF) ? SET : RESET);
    }
    else if (ADC_IT_INJENDOFCONVSINGLE == adc_interrupt)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_JEOCIF) ? SET : RESET);
    }
    else if (ADC_IT_INJENDOFCONVSAMPLE == adc_interrupt)
    {
        ret = ((adc->ADSTA_EXT & ADC_ADDSTA_EXT_JEOSMPIF) ? SET : RESET);
    }

    return (ret);
}

/**
  * @brief  Clears the adc's interrupt pending bits.
  * @param  adc: select the ADC peripheral.
  * @param  adc_interrupt: specifies the ADC interrupt pending bit to clear.
  * @retval None.
  */
void ADC_ClearITPendingBit(ADC_TypeDef *adc, ADCFLAG_TypeDef adc_interrupt)
{
    if (ADC_IT_ENDOFCONVSEQUENCE == adc_interrupt)
    {
        adc->ADSTA = ADC_ADSTA_EOSIF;
    }
    else if (ADC_IT_ANALOGWATCHDOG == adc_interrupt)
    {
        adc->ADSTA = ADC_ADSTA_AWDIF;
    }
    else if (ADC_IT_ENDOFCONVSINGLE == adc_interrupt)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_EOCIF;
    }
    else if (ADC_IT_ENDOFCONVSAMPLE == adc_interrupt)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_EOSMPIF;
    }
    else if (ADC_IT_INJENDOFCONVSINGLE == adc_interrupt)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_JEOCIF;
    }
    else if (ADC_IT_INJENDOFCONVSAMPLE == adc_interrupt)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_JEOSMPIF;
    }
    else if (ADC_IT_INJENDOFCONVSEQUENCE == adc_interrupt)
    {
        adc->ADSTA_EXT = ADC_ADDSTA_EXT_JEOSIF;
    }
}

/**
  * @brief  Configures the adc any channels conversion anychan and channel.
  * @param  adc: select the ADC peripheral.
  * @param  anychan: anychan can be 0x0~0xf for the convert sequence.
  * @param  adc_channel: Configuring the target channel to be converted.
  * @retval None.
  */
void ADC_ANY_CH_Config(ADC_TypeDef *adc, uint8_t anychan, ADCCHANNEL_TypeDef channel)
{
    if (anychan >= 8)
    {
        MODIFY_FIELD(adc->CHANY1, 4, ((uint32_t)anychan & 0x07UL), ((uint32_t)channel));
    }
    else
    {
        MODIFY_FIELD(adc->CHANY0, 4, (uint32_t)anychan, ((uint32_t)channel));
    }
}

/**
  * @brief  Configures the adc any channels conversion Max rank number
  * @param  adc: select the ADC peripheral.
  * @param  num: Configuring the max rank number for the ADC.
  * @retval None.
  */
void ADC_ANY_NUM_Config(ADC_TypeDef *adc, uint8_t num)
{
    if (num > 15)
    {
        num = 15;
    }

    adc->ANY_CFG = num;
}

/**
  * @brief  Enables or disables the ANY channel converter.
  * @param  state: enable or disable the ANY channel converter mode.
  * @retval None.
  */
void ADC_ANY_Cmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ANY_CR |= ADC_ANY_CR_CHANY_MDEN) : (adc->ANY_CR &= ~ADC_ANY_CR_CHANY_MDEN);
}

/**
  * @brief  Enables or disables the selected ADC automatic injected group
  *         conversion after regular one.
  * @param  adc: where x can be 1, 2 or 3 to select the ADC peripheral.
  * @param  state: new state of the selected ADC auto injected conversion
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_AutoInjectedConvCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ANY_CR |= ADC_ANY_CR_JAUTO) : (adc->ANY_CR &= ~ADC_ANY_CR_JAUTO);
}

/**
  * @brief  Configures the adc external trigger for injected channels conversion.
  * @param  adc: where x can be 1, 2 or 3 to select the ADC peripheral.
  * @param  ADC_ExtInjTrigSource: specifies the ADC trigger to start injected conversion.
  * @retval None
  */
void ADC_ExternalTrigInjectedConvertConfig(ADC_TypeDef *adc, EXTER_INJ_TRIG_TypeDef ADC_ExtInjTrigSource)
{
    uint32_t tmpreg = 0;

     /* Get the old register value */
    tmpreg = adc->ANY_CR;
     /* Clear the old external event selection for injected group */
    tmpreg &= ~ADC_ANY_CR_JTRGSEL;
     /* Set the external event selection for injected group */
    tmpreg |= ADC_ExtInjTrigSource;
     /* Store the new register value */
    adc->ANY_CR = tmpreg;
}

/**
  * @brief  Enables or disables the adc injected channels conversion through
  *         external trigger
  * @param  adc: where x can be 1, 2 or 3 to select the ADC peripheral.
  * @param  state: new state of the selected ADC external trigger start of
  *         injected conversion.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ANY_CR |= ADC_ANY_CR_JTRGEN) : (adc->ANY_CR &= ~ADC_ANY_CR_JTRGEN);
}

/**
  * @brief  Enables or disables the selected ADC start of the injected
  *         channels conversion.
  * @param  adc: where x can be 1, 2 or 3 to select the ADC peripheral.
  * @param  state: new state of the selected ADC software start injected conversion.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_InjectedConvCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ANY_CR |= ADC_ANY_CR_JCEN) : (adc->ANY_CR &= ~ADC_ANY_CR_JCEN);
}

/**
  * @brief  Enables or disables the selected ADC start of the injected
  *         channels conversion.
  * @param  adc: where x can be 1, 2 or 3 to select the ADC peripheral.
  * @param  NewState: new state of the selected ADC software start injected conversion.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef *adc, FunctionalState state)
{
    (state) ? (adc->ANY_CR |= ADC_ANY_CR_JADST) : (adc->ANY_CR &= ~ADC_ANY_CR_JADST);
}

/**
  * @brief  Enable the selected ADC channel and configure its sample time. Please
  *         use this function if you want to be compatible with older versions
  *         of the library.
  * @param  adc:  select the ADC peripheral.
  * @param  source: the ADC external trig source to configure.
  * @param  shift: the ADC inject shift to configure.
  * @retval None.
  */
void ADC_InjectedSequencerConfig(ADC_TypeDef *adc, uint32_t source, uint32_t shift)
{
    adc->ANY_CR &= ~(ADC_ANY_CR_JCEN | ADC_ANY_CR_CHANY_MDEN | (ADC_ANY_CR_JTRGSEL) | \
                     ADC_ANY_CR_JTRGSHIFT_512 | ADC_ANY_CR_JTRGEN);
    adc->ANY_CR |= (ADC_ANY_CR_JCEN | ADC_ANY_CR_CHANY_MDEN | (source & ADC_ANY_CR_JTRGSEL) | \
                    (shift & ADC_ANY_CR_JTRGSHIFT_512) | ADC_ANY_CR_JTRGEN);
}

/**
  * @brief  Injection channel length configuration.
  * @param  adc:  select the ADC peripheral.
  * @param  Length: Injection channel length.
  * @retval None.
  */
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef *adc, ADC_INJ_SEQ_LEN_TypeDef Length)
{
    adc->JSQR &= ~(0x03 << ADC_JSQR_JNUM_Pos);
    adc->JSQR |= Length << ADC_JSQR_JNUM_Pos;
}

/**
  * @brief  Injection channel  configuration.
  * @param  adc  :   select the ADC peripheral.
  * @param  injected_channel :   Injection channel.
  * @param  channel: The sampling channel.
  * @retval None.
  */
void ADC_InjectedSequencerChannelConfig(ADC_TypeDef *adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel, ADCCHANNEL_TypeDef channel)
{
    adc->JSQR &= ~(0x1F << ((injected_channel) * 5));
    adc->JSQR |= (channel << ((injected_channel) * 5));
}

/**
  * @brief  Injection channel  converted value.
  * @param  adc  :   select the ADC peripheral.
  * @param  injected_channel :   Injection channel.
  * @retval value.
  */
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef *adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel)
{
    uint32_t value1, value2;

    value1 = (adc->JDR[injected_channel & 0x03]);
    value2 = (adc->JOFR[injected_channel & 0x03]);

    return ((uint16_t)(value1 - value2));
}

/**
  * @brief  Injection current converted value.
  * @param  adc  :   select the ADC peripheral.
  * @retval value. Returns the last adc conversion result data for injected channel.
  */
uint16_t ADC_GetInjectedCurrentConvertedValue(ADC_TypeDef *adc)
{
    return ((uint16_t)adc->JADDATA);
}

/**
  * @brief  Injection channel  converted value.
  * @param  adc  :   select the ADC peripheral.
  * @param  injected_channel :   Injection channel.
  * @retval value.
  */
uint16_t ADC_GetInjectedAnychanConvertedValue(ADC_TypeDef *adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel)
{
    uint32_t value;

    value = (adc->JDR[injected_channel & 0x03]);

    return ((uint16_t)value);
}

/**
  * @brief  Injection channel compensation configuration.
  * @param  adc         : select the ADC peripheral.
  * @param  injected_channel :   Injection channel.
  * @param  value       : compensation value.
  * @retval None.
  */
void ADC_SetInjectedOffset(ADC_TypeDef *adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel, uint16_t value)
{
    adc->JOFR[0x03 & (injected_channel)] = (uint32_t)value;
}

/**
  * @brief  Injection channel  converted value.
  * @param  adc  :   select the ADC peripheral.
  * @param  injected_channel :   Injection channel.
  * @retval value.
  */
uint16_t ADC_GetInjectedOffset(ADC_TypeDef *adc, ADC_INJ_SEQ_Channel_TypeDef injected_channel)
{
    uint32_t value;

    value = (adc->JOFR[injected_channel & 0x03]);

    return ((uint16_t)value);
}

/**
  * @brief  Get channel convertion result.
  * @param  adc  :   select the ADC peripheral.
  * @param  channel :   Converted channel.
  * @retval The Data conversion value.
  */
uint16_t ADC_GetChannelConvertedValue(ADC_TypeDef *adc, ADCCHANNEL_TypeDef channel)
{
    return ((uint16_t)(adc->ADDR[channel]));
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

