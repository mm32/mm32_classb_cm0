/***********************************************************************************************************************
    @file     hal_syscfg.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE FLASH FIRMWARE FUNCTIONS.
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


/* Includes ------------------------------------------------------------------*/
#include "hal_syscfg.h"

/** @addtogroup StdPeriph_Driver
* @{
*/

/** @defgroup SYSCFG
* @brief SYSCFG driver modules
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SYSCFG_Private_Functions
* @{
*/

/** @defgroup SYSCFG_Group1 SYSCFG Initialization and Configuration functions
*  @brief   SYSCFG Initialization and Configuration functions
*
@verbatim
===============================================================================
##### SYSCFG Initialization and Configuration functions #####
===============================================================================

@endverbatim
* @{
*/

/**
* @brief  Deinitializes the SYSCFG registers to their default reset values.
* @param  None
* @retval None
*/
void SYSCFG_DeInit(void)
{
    /* Set SYSCFG_CFGR1 register to reset value without affecting MEM_MODE bits */
    SYSCFG->CFGR &= SYSCFG_CFGR_MEM_MODE_Msk;
    /* Set EXTICRx registers to reset value */
    SYSCFG->EXTICR[0] = 0;
    SYSCFG->EXTICR[1] = 0;
    SYSCFG->EXTICR[2] = 0;
    SYSCFG->EXTICR[3] = 0;
}

/**
* @brief  Configures the memory mapping at address 0x00000000.
* @param  SYSCFG_MemoryRemap: selects the memory remapping.
*          This parameter can be one of the following values:
*            @arg SYSCFG_MemoryRemap_Flash: Main Flash memory mapped at 0x00000000
*            @arg SYSCFG_MemoryRemap_SystemMemory: System Flash memory mapped at 0x00000000
*            @arg SYSCFG_MemoryRemap_SRAM: Embedded SRAM mapped at 0x00000000
* @retval None
*/
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap)
{
    MODIFY_REG(SYSCFG->CFGR, SYSCFG_CFGR_MEM_MODE_Msk, SYSCFG_MemoryRemap);
}

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  port_source_gpio: EXTI_PortSourceGPIOx .
  * @param  pin_source: EXTI_PinSourcex.
  * @retval None.
  */
void SYSCFG_EXTILineConfig(uint8_t port_source_gpio, uint8_t pin_source)
{
    uint32_t tmp = 0x00;

    tmp = ((uint32_t)0x0F) << (0x04 * (pin_source & (uint8_t)0x03));
    SYSCFG->EXTICR[pin_source >> 0x02] &= ~tmp;
    SYSCFG->EXTICR[pin_source >> 0x02] |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
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

/**
* @}
*/ 

