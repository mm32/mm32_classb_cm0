/*
 *******************************************************************************
    @file     hal_exti.c
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



/* Files includes ------------------------------------------------------------*/
#include "hal_exti.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup EXTI_HAL
  * @{
  */

/** @addtogroup EXTI_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the EXTI peripheral registers to their default reset
  *         values.
  * @param  None.
  * @retval None.
  */

/**
  * @brief  Deinitializes the EXTI registers to their default reset values.
  * @param  None.
  * @retval None.
  * @note   MEM_MODE bits are not affected by APB reset.
  * @note   MEM_MODE bits took the value from the user option bytes.
  * @note   CFGR2 register is not affected by APB reset.
  * @note   CLABBB configuration bits are locked when set.
  * @note   To unlock the configuration, perform a system reset.
  */
void EXTI_DeInit(void)
{
    EXTI->IMR = 0x00000000;
    EXTI->EMR = 0x00000000;
    EXTI->RTSR = 0x00000000;
    EXTI->FTSR = 0x00000000;
    EXTI->PR = 0x001FFFFF;
}

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  port_source_gpio: selects the GPIO port to be used as source for EXTI lines .
  * @param  pin_source: specifies the EXTI line to be configured.
  * @note   This parameter can be pin_source where x can be:
  *         For MCU: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOD.
  * @retval None.
  */
void EXTI_LineConfig(uint8_t port_source_gpio, uint8_t pin_source)
{
    uint32_t tmp = 0x00;

    /* Check the parameters */

    tmp = ((uint32_t)0x0F) << (0x04 * (pin_source & (uint8_t)0x03));
    SYSCFG->EXTICR[pin_source >> 0x02] &= ~tmp;
    SYSCFG->EXTICR[pin_source >> 0x02] |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
}

/**
  * @brief  Initializes the EXTI peripheral according to the specified
  *         parameters in the init_struct.
  * @param  init_struct: pointer to a EXTI_InitTypeDef structure that
  *         contains the configuration information for the EXTI peripheral.
  * @retval None.
  */
void EXTI_Init(EXTI_InitTypeDef* init_struct)
{
    if (init_struct->EXTI_LineCmd != DISABLE) {
        EXTI->IMR  &= ~init_struct->EXTI_Line;
        EXTI->EMR  &= ~init_struct->EXTI_Line;
        if (init_struct->EXTI_Mode == EXTI_Mode_Interrupt) {
            EXTI->IMR |= init_struct->EXTI_Line;
        }
        else {
            EXTI->EMR |= init_struct->EXTI_Line;
        }
        EXTI->RTSR &= ~init_struct->EXTI_Line;
        EXTI->FTSR &= ~init_struct->EXTI_Line;
        if (init_struct->EXTI_Trigger == EXTI_Trigger_Rising_Falling) {
            EXTI->RTSR |= init_struct->EXTI_Line;
            EXTI->FTSR |= init_struct->EXTI_Line;                               /*!< Rising and Faling    afio */
        }
        else if (init_struct->EXTI_Trigger == EXTI_Trigger_Rising) {
            EXTI->RTSR |= init_struct->EXTI_Line;
        }
        else {
            EXTI->FTSR |= init_struct->EXTI_Line;
        }
    }
    else {
        if (init_struct->EXTI_Mode == EXTI_Mode_Interrupt) {
            EXTI->IMR &= ~init_struct->EXTI_Line;
        }
        else {
            EXTI->EMR &= ~init_struct->EXTI_Line;
        }
    }
}

/**
  * @brief  Fills each init_struct member with its reset value.
  * @param  init_struct: pointer to a EXTI_InitTypeDef structure which will
  *         be initialized.
  * @retval None.
  */
void EXTI_StructInit(EXTI_InitTypeDef* init_struct)
{
    init_struct->EXTI_Line    = EXTI_LineNone;
    init_struct->EXTI_Mode    = EXTI_Mode_Interrupt;
    init_struct->EXTI_Trigger = EXTI_Trigger_Falling;
    init_struct->EXTI_LineCmd = DISABLE;
}

/**
  * @brief  Generates a Software interrupt on selected EXTI line.
  * @param  line: specifies the EXTI line on which the software interrupt
  *         will be generated.
  * @retval None.
  */
void EXTI_GenerateSWInterrupt(uint32_t line)
{
    EXTI->SWIER |= line;
}

/**
  * @brief  Checks whether the specified EXTI line flag is set or not.
  * @param  line: specifies the EXTI line flag to check.
  * @retval The new state of line (SET or RESET).
  */
FlagStatus EXTI_GetFlagStatus(uint32_t line)
{
    return (EXTI->PR & line) ? SET : RESET;
}

/**
  * @brief  Clears the EXTI's line pending flags.
  * @param  line: specifies the EXTI lines flags to clear.
  * @retval None.
  */
void EXTI_ClearFlag(uint32_t line)
{
    EXTI->PR = line;
}

/**
  * @brief  Checks whether the specified EXTI line is asserted or not.
  * @param  line: specifies the EXTI line to check.
  * @retval The new state of line (SET or RESET).
  */
ITStatus EXTI_GetITStatus(uint32_t line)
{
    return ((EXTI->PR & line) && (EXTI->IMR & line)) ? SET : RESET;
}

/**
  * @brief  Clears the EXTI's line pending bits.
  * @param  line: specifies the EXTI lines to clear.
  * @retval None.
  */
void EXTI_ClearITPendingBit(uint32_t line)
{
    EXTI->PR = line;
}

/**
  * @brief  EXTI Line Disable
  * @param  line: specifies the EXTI lines to clear.
  * @retval None.
  */
void exEXTI_LineDisable(uint32_t line)
{
    EXTI->IMR  &= ~line;
    EXTI->EMR  &= ~line;
    EXTI->RTSR &= ~line;
    EXTI->FTSR &= ~line;
}

/**
  * @brief  Clears the EXTI's line all pending bits.
  * @param  None.
  * @retval None.
  */
uint32_t exEXTI_GetAllFlagStatus(void)
{
    return EXTI->PR;
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
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

