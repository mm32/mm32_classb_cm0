/***********************************************************************************************************************
    @file     hal_crs.h
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
#ifndef __HAL_CRS_H
#define __HAL_CRS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup CRS_HAL
  * @brief CRS HAL modules
  * @{
  */

/** @defgroup CRS_Exported_Types
  * @{
  */

/**
  * @brief CRS Init structure definition
  */
typedef struct
{
    uint32_t Prescaler;
    uint32_t Source;
    uint32_t Polarity;
    uint32_t ReloadValue;
    uint32_t ErrorLimitValue;
    uint32_t HSI48CalibrationValue;
} CRS_InitTypeDef;

/**
  * @brief CRS_Exported_Constants
  */

/**
  * @brief CRS Prescaler
  */
#define CRS_SYNC_Div1                    (0x00U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal not divided     */
#define CRS_SYNC_Div2                    (0x01U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 2    */
#define CRS_SYNC_Div4                    (0x02U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 4    */
#define CRS_SYNC_Div8                    (0x03U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 8    */
#define CRS_SYNC_Div16                   (0x04U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 16   */
#define CRS_SYNC_Div32                   (0x05U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 32   */
#define CRS_SYNC_Div64                   (0x06U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 64   */
#define CRS_SYNC_Div128                  (0x07U << CRS_CFGR_SYNCDIV_Pos) /*!< Synchro Signal divided by 128  */

/**
  * @brief CRS Source
  */
#define CRS_SYNCSource_GPIO              (0x00U << CRS_CFGR_SYNCSRC_Pos) /*!< Synchro Signal soucre GPIO      */
#define CRS_SYNCSource_LSE               (0x01U << CRS_CFGR_SYNCSRC_Pos) /*!< Synchro Signal source LSE       */
#define CRS_SYNCSource_USB               (0x02U << CRS_CFGR_SYNCSRC_Pos) /*!< Synchro Signal source USB SOF   */

/**
  * @brief CRS Polarity
  */
#define CRS_SYNCPolarity_Rising          (0x00U << CRS_CFGR_SYNCPOL_Pos) /*!< Synchro Active on rising edge    */
#define CRS_SYNCPolarity_Falling         (0x01U << CRS_CFGR_SYNCPOL_Pos) /*!< Synchro Active on falling edge   */

/**
  * @brief CRS ErrorLimitValue
  */
#define CRS_ERRORLIMIT_DEFAULT           0x22                            /*!< Default Frequency error limit    */

/**
  * @brief CRS IT Definition
  */
#define CRS_IT_SYNCOK                    (0x01U << CRS_CR_SYNCOKIE_Pos)
#define CRS_IT_SYNCWARN                  (0x01U << CRS_CR_SYNCWARNIE_Pos)
#define CRS_IT_ERR                       (0x01U << CRS_CR_ERRIE_Pos)
#define CRS_IT_ESYNC                     (0x01U << CRS_CR_ESYNCIE_Pos)

#define CRS_IT_SYNCERR                   (0x01U << CRS_ISR_SYNCERR_Pos)
#define CRS_IT_SYNCMISS                  (0x01U << CRS_ISR_SYNCMISS_Pos)
#define CRS_IT_TRIMOVF                   (0x01U << CRS_ISR_TRIMOVF_Pos)

/**
  * @brief CRS Flags Definition
  */
#define CRS_FLAG_SYNCOK                  (0x01U << CRS_ISR_SYNCOKF_Pos)
#define CRS_FLAG_SYNCWARN                (0x01U << CRS_ISR_SYNCWARNF_Pos)
#define CRS_FLAG_ERR                     (0x01U << CRS_ISR_ERRF_Pos)
#define CRS_FLAG_ESYNC                   (0x01U << CRS_ISR_ESYNCF_Pos)
#define CRS_FLAG_SYNCERR                 (0x01U << CRS_ISR_SYNCERR_Pos)
#define CRS_FLAG_SYNCMISS                (0x01U << CRS_ISR_SYNCMISS_Pos)
#define CRS_FLAG_TRIMOVF                 (0x01U << CRS_ISR_TRIMOVF_Pos)

/**
  * @}
  */

/** @defgroup CRS_Exported_Functions
  * @{
  */
void CRS_DeInit(void);
void CRS_AdjustHSI48CalibrationValue(uint32_t value);
void CRS_FrequencyErrorCounterCmd(FunctionalState state);
void CRS_AutomaticCalibrationCmd(FunctionalState state);
void CRS_SoftwareSynchronizationGenerate(void);
void CRS_FrequencyErrorCounterReload(uint32_t reload_value);
void CRS_FrequencyErrorLimitConfig(uint8_t error_limit_value);
void CRS_SyncPrescalerConfig(uint32_t prescaler);
void CRS_SynSourceConfig(uint32_t CRS_Source);
void CRS_SynchronizationPolarityConfig(uint32_t polarity);
uint32_t CRS_GetReloadValue(void);
uint32_t CRS_GetHSI48CalibrationValue(void);
uint32_t CRS_GetFrequencyErrorValue(void);
uint32_t CRS_GetFrequencyErrorDirection(void);
void CRS_ITConfig(uint32_t it, FunctionalState state);
FlagStatus CRS_GetFlagStatus(uint32_t flag);
void CRS_ClearFlag(uint32_t flag);
ITStatus CRS_GetITStatus(uint32_t it);
void CRS_ClearITPendingBit(uint32_t it);
ITStatus CRS_GetITSource(uint32_t it);
void CRS_Init(CRS_InitTypeDef *init_struct);

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

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/

