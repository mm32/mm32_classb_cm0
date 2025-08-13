/*
 *******************************************************************************
    @file     hal_bkp.h
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
#ifndef __HAL_BKP_H
#define __HAL_BKP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup BKP_HAL
  * @brief BKP HAL modules
  * @{
  */

/** @defgroup BKP_Exported_Types
  * @{
  ******************************************************************************
  * @brief  Data_Backup_Register
  * @anchor Data_Backup_Register
  */
typedef enum {
    BKP_DR1                             = 0x0010,
    BKP_DR2                             = 0x0014,
    BKP_DR3                             = 0x0018,
    BKP_DR4                             = 0x001C,
    BKP_DR5                             = 0x0020,
    BKP_DR6                             = 0x0024,
    BKP_DR7                             = 0x0028,
    BKP_DR8                             = 0x002C,
    BKP_DR9                             = 0x0030,
    BKP_DR10                            = 0x0034
} BKPDR_Typedef;

/**
  * @brief Tamper_Pin_active_level
  * @anchor Tamper_Pin_active_level
  */
typedef enum {
    BKP_TamperPinLevel_High,                                                    /*!< Tamper pin active on high level */
    BKP_TamperPinLevel_Low              = BKP_CR_TPAL                           /*!< Tamper pin active on low level */
} BKPTPAL_Typedef;

/**
  * @brief RTC_output_source_to_output_on_the_Tamper_pin
  * @anchor RTC_output_source_to_output_on_the_Tamper_pin
  */
typedef enum {
    BKP_RTCOutputSource_None            = 0x0000,                               /*!< No RTC output on the Tamper pin */
    BKP_RTCOutputSource_CalibClock      = 0x0080,                               /*!< Output the RTC clock with frequency divided by 64 on the Tamper pin*/
    BKP_RTCOutputSource_Alarm           = 0x0100,                               /*!< Output the RTC Alarm pulse signal on the Tamper pin */
    BKP_RTCOutputSource_Second          = 0x0300                                /*!< Output the RTC Second pulse signal on the Tamper pin */
} BKPRTCOUTPUTSRC_Typedef;
/**
  * @}
  */

/** @defgroup BKP_Exported_Variables
  * @{
  */
#ifdef _HAL_BKP_C_
#define GLOBAL

#else
#define GLOBAL extern
#endif

#undef GLOBAL
/**
  * @}
  */

/** @defgroup BKP_Exported_Functions
  * @{
  */

void BKP_WriteBackupRegister(BKPDR_Typedef bkp_dr, uint16_t data);
uint16_t  BKP_ReadBackupRegister(BKPDR_Typedef bkp_dr);

void BKP_DeInit(void);
void BKP_ClearFlag(void);
void BKP_ClearITPendingBit(void);
void BKP_TamperPinLevelConfig(BKPTPAL_Typedef tamper_pin_level);
void BKP_TamperPinCmd(FunctionalState state);
void BKP_ITConfig(FunctionalState state);
void BKP_RTCOutputConfig(BKPRTCOUTPUTSRC_Typedef rtc_output_source);
void BKP_SetRTCCalibrationValue(uint8_t calibration_value);

ITStatus   BKP_GetITStatus(void);
FlagStatus BKP_GetFlagStatus(void);
void exBKP_Init(void);
void exBKP_ImmWrite(BKPDR_Typedef bkp_dr, uint16_t data);
uint16_t  exBKP_ImmRead(BKPDR_Typedef bkp_dr);
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
#endif/* __HAL_BKP_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
