/***********************************************************************************************************************
    @file     hal_crs.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE ADC FIRMWARE FUNCTIONS.
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
#define _HAL_CRS_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_crs.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup CRS_HAL
  * @{
  */

/** @addtogroup CRS_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the CRS peripheral registers to their default
  *         reset values.
  * @param  None.
  * @retval None.
  */
void CRS_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1ENR_CRS, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1ENR_CRS, DISABLE);
}

/**
  * @brief  Adjusts the Internal High Speed 48 oscillator (HSI 48) calibration
  * value.
  * @note   The calibration is used to compensate for the variations in voltage
  *         and temperature that influence the frequency of the internal HSI48
  *         RC.
  * @note   This function can be called only when the AUTOTRIMEN bit is reset.
  * @param  value: HSI48 calibration value, the value ranges from 0 to 0x3FF.
  * @retval None.
  */
void CRS_AdjustHSI48CalibrationValue(uint32_t value)
{
    MODIFY_REG(CRS->CR, CRS_CR_TRIM, (value << CRS_CR_TRIM_Pos));
}

/**
  * @brief  Enables or disables the oscillator clock for frequency error
  * counter.
  * @note   when the CEN bit is set the CRS_CFGR register becomes
  * write-protected.
  * @param  state: new state of the frequency error counter.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CRS_FrequencyErrorCounterCmd(FunctionalState state)
{
    (state) ?                                \
    (CRS->CR |= (0x01U << CRS_CR_CEN_Pos)) : \
    (CRS->CR &= ~(0x01U << CRS_CR_CEN_Pos));
}

/**
  * @brief  Enables or disables the automatic hardware adjustement of TRIM bits.
  * @note   When the AUTOTRIMEN bit is set the CRS_CFGR register becomes
  * write-protected.
  * @param  state: new state of the automatic trimming.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CRS_AutomaticCalibrationCmd(FunctionalState state)
{
    (state) ?                                       \
    (CRS->CR |= (0x01U << CRS_CR_AUTOTRIMEN_Pos)) : \
    (CRS->CR &= ~(0x01U << CRS_CR_AUTOTRIMEN_Pos));
}

/**
  * @brief  Generate the software synchronization event.
  * @param  None.
  * @retval None.
  */
void CRS_SoftwareSynchronizationGenerate(void)
{
    CRS->CR |= (0x01U << CRS_CR_SWSYNC_Pos);
}

/**
  * @brief  Adjusts the Internal High Speed 48 oscillator (HSI 48) calibration
  * value.
  * @note   The calibration is used to compensate for the variations in voltage
  *         and temperature that influence the frequency of the internal HSI48
  *         RC.
  * @note   This function can be called only when the CEN bit is reset.
  * @param  reload_value: specifies the HSI calibration trimming value.
  *         This parameter must be a number between 0 and 0xFFFF .
  * @retval None.
  */
void CRS_FrequencyErrorCounterReload(uint32_t reload_value)
{
    MODIFY_REG(CRS->CFGR, CRS_CFGR_RELOAD, reload_value << CRS_CFGR_RELOAD_Pos);
}

/**
  * @brief
  * @note   This function can be called only when the CEN bit is reset.
  * @param  error_limit_value: specifies the HSI calibration trimming value.
  *         This parameter must be a number between 0 and 0xFF.
  * @retval None.
  */
void CRS_FrequencyErrorLimitConfig(uint8_t error_limit_value)
{
    MODIFY_REG(CRS->CFGR, CRS_CFGR_FELIM, error_limit_value << CRS_CFGR_FELIM_Pos);
}

/**
  * @brief
  * @note   This function can be called only when the CEN bit is reset.
  * @param  prescaler: specifies the HSI calibration trimming value.
  *         This parameter can be one of the following values:
  * @arg    CRS_SYNC_Div1
  * @arg    CRS_SYNC_Div2
  * @arg    CRS_SYNC_Div4
  * @arg    CRS_SYNC_Div8
  * @arg    CRS_SYNC_Div16
  * @arg    CRS_SYNC_Div32
  * @arg    CRS_SYNC_Div64
  * @arg    CRS_SYNC_Div128
  * @retval None.
  */
void CRS_SyncPrescalerConfig(uint32_t prescaler)
{
    MODIFY_REG(CRS->CFGR, CRS_CFGR_SYNCDIV, prescaler);
}

/**
  * @brief
  * @note   This function can be called only when the CEN bit is reset.
  * @param  source: .
  *         This parameter can be one of the following values:
  * @arg    CRS_SYNCSource_GPIO
  * @arg    CRS_SYNCSource_LSE
  * @arg    CRS_SYNCSource_USB
  * @retval None.
  */
void CRS_SynSourceConfig(uint32_t source)
{
    MODIFY_REG(CRS->CFGR, CRS_CFGR_SYNCSRC, source);
}

/**
  * @brief
  * @note   This function can be called only when the CEN bit is reset.
  * @param  polarity
  *         This parameter can be one of the following values:
  * @arg    CRS_SYNCPolarity_Rising
  * @arg    CRS_SYNCPolarity_Falling
  * @retval None.
  */
void CRS_SynchronizationPolarityConfig(uint32_t polarity)
{
    MODIFY_REG(CRS->CFGR, CRS_CFGR_SYNCPOL, polarity);
}

/**
  * @brief  Returns the Relaod value.
  * @param  None.
  * @retval The reload value
  */
uint32_t CRS_GetReloadValue(void)
{
    return (CRS->CFGR & CRS_CFGR_RELOAD);
}

/**
  * @brief  Returns the HSI48 Calibration value.
  * @param  None.
  * @retval The reload value
  */
uint32_t CRS_GetHSI48CalibrationValue(void)
{
    return ((CRS->CR & CRS_CR_TRIM) >> CRS_CR_TRIM_Pos);
}

/**
  * @brief  Returns the frequency error capture.
  * @param  None.
  * @retval The frequency error capture value
  */
uint32_t CRS_GetFrequencyErrorValue(void)
{
    return (CRS->ISR & CRS_ISR_FECAP);
}

/**
  * @brief  Returns the frequency error direction.
  * @param  None.
  * @retval The frequency error direction. The returned value can be one
  *         of the following values:
  *         - 0x00: Up counting
  *         - 0x8000: Down counting
  */
uint32_t CRS_GetFrequencyErrorDirection(void)
{
    return (CRS->ISR & CRS_ISR_FEDIR);
}

/**
  * @brief  Enables or disables the specified CRS interrupts.
  * @param  it: specifies the RCC interrupt sources to be enabled or
  *         disabled.
  *         This parameter can be any combination of the following values:
  * @arg    CRS_IT_SYNCOK
  * @arg    CRS_IT_SYNCWARN
  * @arg    CRS_IT_ERR
  * @arg    CRS_IT_ESYNC
  * @param  state: new state of the specified CRS interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void CRS_ITConfig(uint32_t it, FunctionalState state)
{
    (state) ?         \
    (CRS->CR |= it) : \
    (CRS->CR &= ~it);
}

/**
  * @brief  Checks whether the specified CRS flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    CRS_FLAG_SYNCOK
  * @arg    CRS_FLAG_SYNCWARN
  * @arg    CRS_FLAG_ERR
  * @arg    CRS_FLAG_ESYNC
  * @arg    CRS_FLAG_SYNCERR
  * @arg    CRS_FLAG_SYNCMISS
  * @arg    CRS_FLAG_TRIMOVF
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus CRS_GetFlagStatus(uint32_t flag)
{
    return ((CRS->ISR & flag) ? SET : RESET);
}

/**
  * @brief  Clears the CRS specified FLAG.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    CRS_FLAG_SYNCOK
  * @arg    CRS_FLAG_SYNCWARN
  * @arg    CRS_FLAG_ERR
  * @arg    CRS_FLAG_ESYNC
  * @arg    CRS_FLAG_SYNCERR
  * @arg    CRS_FLAG_SYNCMISS
  * @arg    CRS_FLAG_TRIMOVF
  * @retval None.
  */
void CRS_ClearFlag(uint32_t flag)
{
    CRS->ICR = (flag & (CRS_FLAG_SYNCOK | CRS_FLAG_SYNCWARN | CRS_FLAG_ESYNC)) ? \
                flag : CRS_FLAG_ERR;
}

/**
  * @brief  Checks whether the specified CRS IT pending bit is set or not.
  * @param  it: specifies the IT pending bit to check.
  *         This parameter can be one of the following values:
  * @arg    CRS_IT_SYNCOK
  * @arg    CRS_IT_SYNCWARN
  * @arg    CRS_IT_ERR
  * @arg    CRS_IT_ESYNC
  * @arg    CRS_IT_SYNCERR
  * @arg    CRS_IT_SYNCMISS
  * @arg    CRS_IT_TRIMOVF
  * @retval The new state of it (SET or RESET).
  */
ITStatus CRS_GetITStatus(uint32_t it)
{
    return ((CRS->ISR & it) ? SET : RESET);
}

/**
  * @brief  Clears the CRS specified IT pending bit.
  * @param  flag: specifies the IT pending bit to clear.
  *         This parameter can be one of the following values:
  * @arg    CRS_IT_SYNCOK
  * @arg    CRS_IT_SYNCWARN
  * @arg    CRS_IT_ERR
  * @arg    CRS_IT_ESYNC
  * @arg    CRS_IT_SYNCERR
  * @arg    CRS_IT_SYNCMISS
  * @arg    CRS_IT_TRIMOVF
  * @retval None.
  */
void CRS_ClearITPendingBit(uint32_t it)
{
    CRS->ICR = (it & (CRS_IT_SYNCOK | CRS_IT_SYNCWARN | CRS_IT_ESYNC)) ? \
                it : CRS_IT_ERR;
}

/**
  * @brief  Get the CRS specified IT Source bit.
  * @param  it: specifies the IT Source.
  *         This parameter can be one of the following values:
  * @arg    CRS_IT_SYNCOK
  * @arg    CRS_IT_SYNCWARN
  * @arg    CRS_IT_ERR
  * @arg    CRS_IT_ESYNC
  * @retval ITStatus: SET or RESET
  */
ITStatus CRS_GetITSource(uint32_t it)
{
    return ((CRS->CR & it) ? SET : RESET);
}

/**
  * @brief  CRS initialization function.
  * @param  init_struct: pointer to a CRS_InitTypeDef structure that
  *         contains the configuration information for the specified CRS
  *         peripheral.
  * @retval None.
  */
void CRS_Init(CRS_InitTypeDef *init_struct)
{
    CRS_DeInit();

    MODIFY_REG(CRS->CFGR, (CRS_CFGR_SYNCDIV | CRS_CFGR_SYNCSRC | CRS_CFGR_SYNCPOL | CRS_CFGR_RELOAD | CRS_CFGR_FELIM),
               (init_struct->Prescaler | \
                init_struct->Source | \
                init_struct->Polarity | \
                init_struct->ReloadValue | \
                (init_struct->ErrorLimitValue << CRS_CFGR_FELIM_Pos)));

    MODIFY_REG(CRS->CR, CRS_CR_TRIM, init_struct->HSI48CalibrationValue << CRS_CR_TRIM_Pos);
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

