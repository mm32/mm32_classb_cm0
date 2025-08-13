/***********************************************************************************************************************
    @file     hal_dbg.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE DBG
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
#ifndef __HAL_DBG_H
#define __HAL_DBG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup DBG_HAL
  * @brief DBG HAL modules
  * @{
  */

/** @defgroup DBG_Exported_Types
  * @{
  */

/**
  * @brief DBGMCU_CR Register Bit Definition
  */

#define DBGMCU_SLEEP                 (0x01U << DBGMCU_CR_SLEEP_Pos)          /*!< Debug Sleep mode */
#define DBGMCU_IWDG_STOP             (0x01U << DBGMCU_CR_IWDG_STOP_Pos)      /*!< Debug independent watchdog stopped when core is halted */
#define DBGMCU_TIM1_STOP             (0x01U << DBGMCU_CR_TIM1_STOP_Pos)      /*!< TIM1 stops work when the core enters the debug mode */
#define DBGMCU_TIM2_STOP             (0x01U << DBGMCU_CR_TIM2_STOP_Pos)      /*!< TIM2 stops work when the core enters the debug mode */
#define DBGMCU_TIM1_PWM_OFF          (0x01U << DBGMCU_CR_TIM1_PWM_OFF_Pos)   /*!< TIM1 outputs all 0 at debug halt */
#define DBGMCU_TIM2_PWM_OFF          (0x01U << DBGMCU_CR_TIM2_PWM_OFF_Pos)   /*!< TIM2 outputs all 0 at debug halt */
#define DBGMCU_TIM14_STOP            (0x01U << DBGMCU_CR_TIM14_STOP_Pos)     /*!< TIM14 stops work when the core enters the debug mode */
#define DBGMCU_TIM13_STOP            (0x01U << DBGMCU_CR_TIM13_STOP_Pos)     /*!< TIM13 stops work when the core enters the debug mode */
#define DBGMCU_TIM6_STOP             (0x01U << DBGMCU_CR_TIM6_STOP_Pos)      /*!< TIM6 stops work when the core enters the debug mode */



/** @defgroup DBG_Exported_Functions
  * @{
  */
void DBGMCU_Configure(uint32_t periph, FunctionalState state);
uint32_t DBGMCU_GetDeviceIDCode(void);

/**
  * @}
  */

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
#endif /* __HAL_DBG_H --------------------------------------------------------*/
/** --------------------------------------------------------------------------*/
