/*
 *******************************************************************************
    @file     hal_rtc.h
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
#ifndef __HAL_RTC_H
#define __HAL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"


/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup RTC_HAL
  * @brief RTC HAL modules
  * @{
  */

/** @defgroup RTC_Exported_Types
  * @{
  */

/**
  * @brief RTC_interrupts_define
  */

#define    RTC_IT_OW                    (uint16_t)RTC_CRH_OWIE                  /*!< Overflow interrupt */
#define    RTC_IT_ALR                   (uint16_t)RTC_CRH_ALRIE                 /*!< Alarm interrupt */
#define    RTC_IT_SEC                   (uint16_t)RTC_CRH_SECIE                 /*!< Second interrupt */



/**
  * @brief RTC_interrupts_flags
  */

#define    RTC_FLAG_RTOFF               (uint16_t)RTC_CRL_RTOFF                 /*!< RTC Operation OFF flag */
#define    RTC_FLAG_RSF                 (uint16_t)RTC_CRL_RSF                   /*!< Registers Synchronized flag */
#define    RTC_FLAG_OW                  (uint16_t)RTC_CRL_OWF                   /*!< Overflow flag */
#define    RTC_FLAG_ALR                 (uint16_t)RTC_CRL_ALRF                  /*!< Alarm flag */
#define    RTC_FLAG_SEC                 (uint16_t)RTC_CRL_SECF                  /*!< Second flag */

/**
  * @}
  */

/** @defgroup RTC_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_Exported_Variables
  * @{
  */


/**
  * @}
  */

/**
  * @defgroup RTC_Exported_Functions
  * @{
  */
void RTC_ITConfig(uint16_t it, FunctionalState state);
void RTC_EnterConfigMode(void);
void RTC_ExitConfigMode(void);
uint32_t RTC_GetCounter(void);
void RTC_SetCounter(uint32_t count);
void RTC_SetPrescaler(uint32_t prescaler);
void RTC_SetAlarm(uint32_t alarm);
uint32_t RTC_GetDivider(void);
void RTC_WaitForLastTask(void);
void RTC_WaitForSynchro(void);
FlagStatus RTC_GetFlagStatus(uint16_t flag);
void RTC_ClearFlag(uint16_t flag);
ITStatus   RTC_GetITStatus(uint16_t it);
void RTC_ClearITPendingBit(uint16_t it);

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
#endif /* __HAL_RTC_H --------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
