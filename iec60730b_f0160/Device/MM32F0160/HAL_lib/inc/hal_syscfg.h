/*
 *******************************************************************************
    @file     hal_syscfg.h
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
#ifndef __HAL_SYSCFG_H
#define __HAL_SYSCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup SYSCFG_HAL
  * @brief SYSCFG HAL modules
  * @{
  */

/** @defgroup SYSCFG_Exported_Types
  * @{
  */

/**
  * @brief  SYSCFG mode enumeration
  */
/** @defgroup SYSCFG_Memory_Remap_Config
  */
#define SYSCFG_MemoryRemap_Flash        ((uint8_t)0x00)
#define SYSCFG_MemoryRemap_SystemMemory ((uint8_t)0x01)
#define SYSCFG_MemoryRemap_SRAM         ((uint8_t)0x03)

#define SYSCFG_DMARemap_TIM17           EXTI_CFGR_TIM17DMA                      /*!< Remap TIM17 DMA requests from channel1 to channel2 */
#define SYSCFG_DMARemap_TIM16           EXTI_CFGR_TIM16DMA                      /*!< Remap TIM16 DMA requests from channel3 to channel4 */
#define SYSCFG_DMARemap_UART1Rx         EXTI_CFGR_UART1RXDMA                    /*!< Remap UART1 Rx DMA requests from channel3 to channel5 */
#define SYSCFG_DMARemap_UART1Tx         EXTI_CFGR_UART1TXDMA                    /*!< Remap UART1 Tx DMA requests from channel2 to channel4 */
#define SYSCFG_DMARemap_ADC1            EXTI_CFGR_ADCDMA                        /*!< Remap ADC1 DMA requests from channel1 to channel2 */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Function used to set the SYSCFG configuration to the default reset state --*/
#define SYSCFG_DeInit                   EXTI_DeInit
#define SYSCFG_MemoryRemapConfig        EXTI_MemoryRemapConfig
#define SYSCFG_DMAChannelRemapConfig    EXTI_DMAChannelRemapConfig
#define SYSCFG_EXTILineConfig           EXTI_LineConfig
uint32_t SYSCFG_GetPendingIT(uint32_t ITSourceLine);
void SYSCFG_BreakConfig(uint32_t SYSCFG_Break);
FlagStatus SYSCFG_GetFlagStatus(uint32_t SYSCFG_Flag);
void SYSCFG_ClearFlag(uint32_t SYSCFG_Flag);

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
#endif/*__HAL_SYSCFG_H -------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

