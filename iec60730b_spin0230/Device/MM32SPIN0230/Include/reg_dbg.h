/***********************************************************************************************************************
    @file     reg_dbg.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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

#ifndef __REG_DBG_H
#define __REG_DBG_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/**
  * @brief DBG Base Address Definition
  */
#define DBG_BASE                        (0x40013400UL) /*!< Base Address: 0x40013400 */

/**
  * @brief DEBUG Registers Structure Definition
  */
typedef struct
{
    __IO uint32_t IDCODE;              /*!< Code ID                                        offset: 0x00 */
    __IO uint32_t CR;                  /*!< Control Register                               offset: 0x04 */
} DBGMCU_TypeDef;

/**
  * @brief DBGMCU type pointer Definition
  */
#define DBGMCU                          ((DBGMCU_TypeDef *)DBG_BASE)

/**
  * @brief DBGMCU_IDCODE Register Bit Definition
  */
#define DBGMCU_IDCODE_DEV_ID_Pos        (0)
#define DBGMCU_IDCODE_DEV_ID            (0xFFFFFFFFU << DBGMCU_IDCODE_DEV_ID_Pos) /*!< Device identifier */

/**
  * @brief DBGMCU_CR Register Bit Definition
  */
#define DBGMCU_CR_SLEEP_Pos             (0)
#define DBGMCU_CR_SLEEP                 (0x01U << DBGMCU_CR_SLEEP_Pos)          /*!< Debug Sleep mode */

#define DBGMCU_CR_IWDG_STOP_Pos         (8)
#define DBGMCU_CR_IWDG_STOP             (0x01U << DBGMCU_CR_IWDG_STOP_Pos)      /*!< Debug independent watchdog stopped when core is halted */

#define DBGMCU_CR_TIM1_STOP_Pos         (10)
#define DBGMCU_CR_TIM1_STOP             (0x01U << DBGMCU_CR_TIM1_STOP_Pos)      /*!< TIM1 counter stopped when core is halted */
#define DBGMCU_CR_TIM2_STOP_Pos         (11)
#define DBGMCU_CR_TIM2_STOP             (0x01U << DBGMCU_CR_TIM2_STOP_Pos)      /*!< TIM2 counter stopped when core is halted */

#define DBGMCU_CR_TIM1_PWM_OFF_Pos      (13)
#define DBGMCU_CR_TIM1_PWM_OFF          (0x01U << DBGMCU_CR_TIM1_PWM_OFF_Pos)   /*!< TIM1 in debug mode PWM output is all 0 */
#define DBGMCU_CR_TIM2_PWM_OFF_Pos      (14)
#define DBGMCU_CR_TIM2_PWM_OFF          (0x01U << DBGMCU_CR_TIM2_PWM_OFF_Pos)   /*!< TIM2 in debug mode PWM output is all 0*/

#define DBGMCU_CR_TIM14_STOP_Pos        (18)
#define DBGMCU_CR_TIM14_STOP            (0x01U << DBGMCU_CR_TIM14_STOP_Pos)     /*!< TIM14 counter stopped when core is halted */
#define DBGMCU_CR_TIM13_STOP_Pos        (19)
#define DBGMCU_CR_TIM13_STOP            (0x01U << DBGMCU_CR_TIM13_STOP_Pos)     /*!< TIM13 counter stopped when core is halted */

#define DBGMCU_CR_TIM6_STOP_Pos         (22)
#define DBGMCU_CR_TIM6_STOP             (0x01U << DBGMCU_CR_TIM6_STOP_Pos)      /*!< TIM6 counter stopped when core is halted */

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

