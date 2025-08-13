/*
 *******************************************************************************
    @file     hal_bkp.c
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
#define _HAL_BKP_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_bkp.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup BKP_HAL
  * @{
  */

/** @addtogroup BKP_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the BKP peripheral registers to their default reset
  *         values.
  * @param  None.
  * @retval None.
  */
void BKP_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1ENR_BKP, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1ENR_BKP, DISABLE);
}

/**
  * @brief  Configures the Tamper Pin active level.
  * @param  tamper_pin_level: specifies the Tamper Pin active level.
  *         This parameter can be one of the following values:
  * @arg    BKP_TamperPinLevel_High: Tamper pin active on high level
  * @arg    BKP_TamperPinLevel_Low: Tamper pin active on low level
  * @retval None.
  */
void BKP_TamperPinLevelConfig(BKPTPAL_Typedef tamper_pin_level)
{
    BKP->CR |= tamper_pin_level;
}

/**
  * @brief  Enables or disables the Tamper Pin activation.
  * @param  state: new state of the Tamper Pin activation.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void BKP_TamperPinCmd(FunctionalState state)
{
    (state) ? SET_BIT(BKP->CR, BKP_CR_TPE) : CLEAR_BIT(BKP->CR, BKP_CR_TPE);
}

/**
  * @brief  Enables or disables the Tamper Pin Interrupt.
  * @param  state: new state of the Tamper Pin Interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void BKP_ITConfig(FunctionalState state)
{
    (state) ? SET_BIT(BKP->CSR, BKP_CSR_TPIE) : CLEAR_BIT(BKP->CSR, BKP_CSR_TPIE);
}

/**
  * @brief  Select the RTC output source to output on the Tamper pin.
  * @param  rtc_output_source: specifies the RTC output source.
  *         This parameter can be one of the following values:
  * @arg    BKP_RTCOutputSource_None: no RTC output on the Tamper pin.
  * @arg    BKP_RTCOutputSource_CalibClock: output the RTC clock with frequency
  *                                          divided by 64 on the Tamper pin.
  * @arg    BKP_RTCOutputSource_Alarm: output the RTC Alarm pulse signal on
  *                                     the Tamper pin.
  * @arg    BKP_RTCOutputSource_Second: output the RTC Second pulse signal on
  *                                      the Tamper pin.
  * @retval None.
  */
void BKP_RTCOutputConfig(BKPRTCOUTPUTSRC_Typedef rtc_output_source)
{
    MODIFY_REG(BKP->RTCCR, BKP_RTCCR_CCO | BKP_RTCCR_ASOE | BKP_RTCCR_ASOS, rtc_output_source);
}

/**
  * @brief  Sets RTC Clock Calibration value.
  * @param  calibration_value: specifies the RTC Clock Calibration value.
  *         This parameter must be a number between 0 and 0x7F.
  * @retval None.
  */
void BKP_SetRTCCalibrationValue(uint8_t calibration_value)
{
    MODIFY_REG(BKP->RTCCR, BKP_RTCCR_CAL, calibration_value);
}

/**
  * @brief  Checks whether the Tamper Pin Event flag is set or not.
  * @param  None.
  * @retval State: The new state of the Tamper Pin Event flag (SET or RESET).
  */
FlagStatus BKP_GetFlagStatus(void)
{
    return ((BKP->CSR & BKP_CSR_TEF) ? SET : RESET);
}

/**
  * @brief  Clears Tamper Pin Event pending flag.
  * @param  None.
  * @retval None.
  */
void BKP_ClearFlag(void)
{
    SET_BIT(BKP->CSR, BKP_CSR_CTE);
}

/**
  * @brief  Checks whether the Tamper Pin Interrupt has occurred or not.
  * @param  None.
  * @retval State: The new state of the Tamper Pin Interrupt (SET or RESET).
  */
ITStatus BKP_GetITStatus(void)
{
    return ((BKP->CSR & BKP_CSR_TIF) ? SET : RESET);
}

/**
  * @brief  Clears Tamper Pin Interrupt pending bit.
  * @param  None.
  * @retval None.
  */
void BKP_ClearITPendingBit(void)
{
    SET_BIT(BKP->CSR, BKP_CSR_CTI);
}

/**
  * @brief  Writes user data to the specified data Backup Register.
  * @param  bkp_dr: specifies the data Backup Register.
  *         This parameter can be BKP_DRx where x:[1, 10]
  * @param  data: data to write
  * @retval None.
  */
void BKP_WriteBackupRegister(BKPDR_Typedef bkp_dr, uint16_t data)
{
    *(__IO uint16_t *)(BKP_BASE + bkp_dr) = data;
}

/**
  * @brief  Reads data from the specified data Backup Register.
  * @param  bkp_dr: specifies the data Backup Register.
  *         This parameter can be BKP_DRx where x:[1, 10]
  * @retval data: The content of the specified data Backup Register
  */
uint16_t BKP_ReadBackupRegister(BKPDR_Typedef bkp_dr)
{
    return (*(__IO uint16_t *)(BKP_BASE + bkp_dr));
}

/**
  *         Extended function interface
  ******************************************************************************
  * @brief  Initializes the BKP peripheral, enable access to the backup
  *         registers.
  * @param  None.
  * @retval None.
  */
void exBKP_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1ENR_PWR, ENABLE);
    /*COMMON_EnableIpClock(emCLOCK_PWR); */
    /*   RCC_APB1PeriphClockCmd(RCC_APB1ENR_BKP, ENABLE); */

    SET_BIT_W_CHECK(RCC->BDCR, RCC_BDCR_DBP);
}

/**
  * @brief  Writes user data to the specified data Backup Register immediately.
  * @param  bkp_dr: specifies the data Backup Register.
  *         This parameter can be BKP_DRx where x:[1, 10]
  * @param  data: data to write
  * @retval None.
  */
void exBKP_ImmWrite(BKPDR_Typedef bkp_dr, uint16_t dat)
{
    SET_BIT_W_CHECK(RCC->BDCR, RCC_BDCR_DBP);
    *(__IO uint16_t *)(BKP_BASE + bkp_dr) = dat;
    CLEAR_BIT_W_CHECK(RCC->BDCR, RCC_BDCR_DBP);
}

/**
  * @brief  Reads data from the specified data Backup Register immediately.
  * @param  bkp_dr: specifies the data Backup Register.
  *         This parameter can be BKP_DRx where x:[1, 10]
  * @retval data: The content of the specified data Backup Register
  */
uint16_t exBKP_ImmRead(BKPDR_Typedef bkp_dr)
{
    uint16_t dat;

    SET_BIT_W_CHECK(RCC->BDCR, RCC_BDCR_DBP);
    dat = (*(__IO uint16_t *)(BKP_BASE + bkp_dr));
    CLEAR_BIT_W_CHECK(RCC->BDCR, RCC_BDCR_DBP);
    return (dat);
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

