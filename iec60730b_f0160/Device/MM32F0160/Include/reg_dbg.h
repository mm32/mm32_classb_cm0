/*
 *******************************************************************************
    @file     reg_dbg.h
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

#ifndef __REG_DBG_H
#define __REG_DBG_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>


#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default -----------------------------------*/
#else
#warning Not supported compiler type
#endif

/**
  * @brief DBG Base Address Definition
  */
#define DBG_BASE                        (0x40013400UL)                          /*!< Base Address: 0x40013400 */

/**
  * @brief DEBUG Registers Structure Definition
  */
typedef struct {
    __IO uint32_t IDCODE;                                                       /*!< Code ID                                        offset: 0x00 */
    __IO uint32_t CR;                                                           /*!< Control Register                               offset: 0x04 */
} DBGMCU_TypeDef;

/**
  * @brief DBGMCU type pointer Definition
  */
#define DBGMCU                          ((DBGMCU_TypeDef*) DBG_BASE)

/**
  * @brief DBGMCU_IDCODE Register Bit Definition
  */
#define DBGMCU_IDCODE_DEV_ID_Pos        (0)
#define DBGMCU_IDCODE_DEV_ID            (0xFFFFFFFFU << DBGMCU_IDCODE_DEV_ID_Pos)   /*!< Device identifier */

/**
  * @brief DBGMCU_CR Register Bit Definition
  */
#define DBGMCU_CR_SLEEP_Pos             (0)
#define DBGMCU_CR_SLEEP                 (0x01U << DBGMCU_CR_SLEEP_Pos)          /*!< Debug Sleep mode */
#define DBGMCU_CR_STOP_Pos              (1)
#define DBGMCU_CR_STOP                  (0x01U << DBGMCU_CR_STOP_Pos)           /*!< Debug Stop mode */
#define DBGMCU_CR_STANDBY_Pos           (2)
#define DBGMCU_CR_STANDBY               (0x01U << DBGMCU_CR_STANDBY_Pos)        /*!< Debug Standby mode */
#define DBGMCU_CR_STOP_FOR_LDO_Pos      (3)
#define DBGMCU_CR_STOP_FOR_LDO          (0x01U << DBGMCU_CR_STOP_FOR_LDO_Pos)   /*!< can not enter stop mode ,LDO on */

#define DBGMCU_CR_IWDG_STOP_Pos         (8)
#define DBGMCU_CR_IWDG_STOP             (0x01U << DBGMCU_CR_IWDG_STOP_Pos)      /*!< Debug independent watchdog stopped when core is halted */
#define DBGMCU_CR_WWDG_STOP_Pos         (9)
#define DBGMCU_CR_WWDG_STOP             (0x01U << DBGMCU_CR_WWDG_STOP_Pos)      /*!< Debug window watchdog stopped when core is halted */
#define DBGMCU_CR_TIM_STOP_Pos          (10)
#define DBGMCU_CR_TIM1_STOP             (0x01U << DBGMCU_CR_TIM_STOP_Pos)       /*!< TIM1 counter stopped when core is halted */
#define DBGMCU_CR_TIM2_STOP             (0x02U << DBGMCU_CR_TIM_STOP_Pos)       /*!< TIM2 counter stopped when core is halted */
#define DBGMCU_CR_TIM3_STOP             (0x04U << DBGMCU_CR_TIM_STOP_Pos)       /*!< TIM3 counter stopped when core is halted */

#define DBGMCU_CR_TIM16UP_STOP_Pos      (16)
#define DBGMCU_CR_TIM16_STOP            (0x01U << DBGMCU_CR_TIM16UP_STOP_Pos)   /*!< TIM16 counter stopped when core is halted */
#define DBGMCU_CR_TIM17_STOP            (0x02U << DBGMCU_CR_TIM16UP_STOP_Pos)   /*!< TIM17 counter stopped when core is halted */
#define DBGMCU_CR_TIM14_STOP            (0x04U << DBGMCU_CR_TIM16UP_STOP_Pos)   /*!< TIM14 counter stopped when core is halted */

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
