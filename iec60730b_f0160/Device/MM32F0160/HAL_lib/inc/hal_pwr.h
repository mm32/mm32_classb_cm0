/*
 *******************************************************************************
    @file     hal_pwr.h
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
#ifndef __HAL_PWR_H
#define __HAL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"
/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup PWR_HAL
  * @brief PWR HAL modules
  * @{
  */

/** @defgroup PWR_Exported_Types
  * @{
  ******************************************************************************
  * @brief PVD_detection_level
  */
typedef enum {
    emPVD_LEVEL0                        = PWR_CR_PLS_1V8,
    emPVD_LEVEL1                        = PWR_CR_PLS_2V1,
    emPVD_LEVEL2                        = PWR_CR_PLS_2V4,
    emPVD_LEVEL3                        = PWR_CR_PLS_2V7,
    emPVD_LEVEL4                        = PWR_CR_PLS_3V0,
    emPVD_LEVEL5                        = PWR_CR_PLS_3V3,
    emPVD_LEVEL6                        = PWR_CR_PLS_3V6,
    emPVD_LEVEL7                        = PWR_CR_PLS_3V9,
    emPVD_LEVEL8                        = PWR_CR_PLS_4V2,
    emPVD_LEVEL9                        = PWR_CR_PLS_4V5,
    emPVD_LEVEL10                       = PWR_CR_PLS_4V8
} emPVD_Level_Typedef;

#define PWR_PVDLevel_1V8                PWR_CR_PLS_1V8
#define PWR_PVDLevel_2V1                PWR_CR_PLS_2V1
#define PWR_PVDLevel_2V4                PWR_CR_PLS_2V4
#define PWR_PVDLevel_2V7                PWR_CR_PLS_2V7
#define PWR_PVDLevel_3V0                PWR_CR_PLS_3V0
#define PWR_PVDLevel_3V3                PWR_CR_PLS_3V3
#define PWR_PVDLevel_3V6                PWR_CR_PLS_3V6
#define PWR_PVDLevel_3V9                PWR_CR_PLS_3V9
#define PWR_PVDLevel_4V2                PWR_CR_PLS_4V2
#define PWR_PVDLevel_4V5                PWR_CR_PLS_4V5
#define PWR_PVDLevel_4V8                PWR_CR_PLS_4V8

/**
  * @brief Regulator_state_is_STOP_mode
  */
typedef enum {
    PWR_Regulator_ON                    = 0x00000000,
    PWR_Regulator_LowPower              = 0x00000001
} emPWR_Reg_Stop_mode_Typedef;

/**
  * @brief STOP_mode_entry
  */
typedef enum {
    PWR_STOPEntry_WFI                   = 0x00000001,
    PWR_STOPEntry_WFE                   = 0x00000002
} emPWR_STOP_ModeEn_Typedef;

/**
  * @brief Low Power Mode
  */
typedef enum {
    LP_STOP_MODE                        = 0,
    LP_SLEEP_MODE                       = 1,
    LP_STANDBY_MODE                     = 2
} emPWR_LP_Mode_Typedef;

/**
  * @brief Wait_for_mode
  */
typedef enum {
    LP_WFI,
    LP_WFE
} emPWR_Wait_Mode_Typedef;
/**
  * @brief PWR_Flag
  */
typedef enum {
    PWR_FLAG_WU                         = PWR_CSR_WUF,
    PWR_FLAG_SB                         = PWR_CSR_SBF,

    PWR_FLAG_PVDO                       = PWR_CSR_PVDO
} emPWR_PWR_Flag_Typedef;

#define WKUP_PIN1           ((uint32_t)0x00000100)
#define WKUP_PIN2           ((uint32_t)0x00000200)
#define WKUP_PIN4           ((uint32_t)0x00000800)
#define WKUP_PIN5           ((uint32_t)0x00001000)
#define WKUP_PIN6           ((uint32_t)0x00002000)

#define Rising_Edge_WKUP    ((uint32_t)0x00000000)
#define Falling_Edge_WKUP1  ((uint32_t)0x00000001)
#define Falling_Edge_WKUP2  ((uint32_t)0x00000002)
#define Falling_Edge_WKUP4  ((uint32_t)0x00000008)
#define Falling_Edge_WKUP5  ((uint32_t)0x00000010)
#define Falling_Edge_WKUP6  ((uint32_t)0x00000020)

#define PWR_STDBY_FSWK_9    ((uint32_t)0x00000000)
#define PWR_STDBY_FSWK_7    ((uint32_t)0x00000001)
#define PWR_STDBY_FSWK_5    ((uint32_t)0x00000002)
#define PWR_STDBY_FSWK_2    ((uint32_t)0x00000003)

/**
  * @}
  */

/** @defgroup PWR_Exported_Variables
  * @{
  */

#ifdef _HAL_PWR_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL

/**
  * @}
  */

/** @defgroup PWR_Exported_Functions
  * @{
  */

void PWR_DeInit(void);

void PWR_PVDCmd(FunctionalState state);
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_WakeUpPinCmd(uint32_t WKUP_PIN,uint32_t WKUP_EDGE,FunctionalState NewState);
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);

void PWR_ClearFlag(uint32_t flag);
FlagStatus PWR_GetFlagStatus(uint32_t flag);
void exPWR_EnterLowPowerMode(emPWR_LP_Mode_Typedef lp_mode, emPWR_Wait_Mode_Typedef wait_mode);
void PWR_Fast_WakeUpConfig(uint32_t FAST_WKUP_TIME);
void PWR_BackupAccessCmd(FunctionalState NewState);
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
#endif/* __HAL_PWR_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
