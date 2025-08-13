/*
 *******************************************************************************
    @file     hal_dma.c
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

/** @defgroup DMA_Private_Defines
  * @{
  */

/* DMA ENABLE mask */
#define CCR_ENABLE_Set          ((uint32_t)0x00000001)
#define CCR_ENABLE_Reset        ((uint32_t)0xFFFFFFFE)

/* DMA1 Channelx interrupt pending bit masks */
#define DMA1_Channel1_IT_Mask    ((uint32_t)0x0000000F)
#define DMA1_Channel2_IT_Mask    ((uint32_t)0x000000F0)
#define DMA1_Channel3_IT_Mask    ((uint32_t)0x00000F00)
#define DMA1_Channel4_IT_Mask    ((uint32_t)0x0000F000)
#define DMA1_Channel5_IT_Mask    ((uint32_t)0x000F0000)

/* Files includes ------------------------------------------------------------*/

#include "hal_dma.h"

/* DMA registers Masks */
#define CCR_CLEAR_Mask           ((uint32_t)0xFFFF800F)

/**
  * @}
  */

/** @defgroup DMA_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Private_Variables
  * @{
  */

/** @addtogroup DMA_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the DMA Channeln registers to their default reset
  *         values.
  * @param   select the DMA Channel.
  * @retval None.
  */
void DMA_DeInit(DMA_Channel_TypeDef* channel)
{
    channel->CCR &= ~DMA_CCR_EN;
    channel->CCR   = 0;
    channel->CNDTR = 0;
    channel->CPAR  = 0;
    channel->CMAR  = 0;
    DMA1->IFCR = (uint32_t)0x0F << (((*(__IO uint32_t*)&channel & (uint32_t)0xff) - 8) / 5);
}

/**
  * @brief  Initializes the DMA Channeln according to the specified
  *         parameters in the init_struct.
  * @param  select the DMA Channel.
  * @param  init_struct: pointer to a DMA_InitTypeDef structure that
  *         contains the configuration information for the specified DMA
  *         Channel.
  * @retval None.
  */
void DMA_Init(DMA_Channel_TypeDef* channel, DMA_InitTypeDef* init_struct)
{
    MODIFY_REG(
        channel->CCR,
        (DMA_CCR_DIR | DMA_CCR_CIRC | DMA_CCR_PINC | DMA_CCR_MINC | DMA_CCR_PSIZE | DMA_CCR_MSIZE | DMA_CCR_PL | DMA_CCR_MEM2MEM),
        ((uint32_t)init_struct->DMA_DIR | (uint32_t)init_struct->DMA_Mode | (uint32_t)init_struct->DMA_PeripheralInc |
         (uint32_t)init_struct->DMA_MemoryInc | (uint32_t)init_struct->DMA_PeripheralDataSize | (uint32_t)init_struct->DMA_MemoryDataSize |
         (uint32_t)init_struct->DMA_Priority | (uint32_t)init_struct->DMA_M2M));

    MODIFY_REG(channel->CCR, DMA_CCR_ARE, init_struct->DMA_Auto_reload);
    channel->CNDTR = init_struct->DMA_BufferSize;
    channel->CPAR  = init_struct->DMA_PeripheralBaseAddr;
    channel->CMAR  = init_struct->DMA_MemoryBaseAddr;
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct : pointer to a DMA_InitTypeDef structure which will
  *         be initialized.
  * @retval None.
  */
void DMA_StructInit(DMA_InitTypeDef* init_struct)
{
    init_struct->DMA_PeripheralBaseAddr = 0;
    init_struct->DMA_MemoryBaseAddr     = 0;
    init_struct->DMA_DIR                = DMA_DIR_PeripheralSRC;
    init_struct->DMA_BufferSize         = 0;
    init_struct->DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    init_struct->DMA_MemoryInc          = DMA_MemoryInc_Disable;
    init_struct->DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    init_struct->DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;
    init_struct->DMA_Mode               = DMA_Mode_Normal;
    init_struct->DMA_Priority           = DMA_Priority_Low;
    init_struct->DMA_M2M                = DMA_M2M_Disable;

    init_struct->DMA_Auto_reload        = DMA_Auto_Reload_Disable;
}

/**
  * @brief  Enables or disables the specified DMA Channeln.
  * @param  channel: select the DMA Channel.
  * @param  state: new state of the DMA Channeln.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void DMA_Cmd(DMA_Channel_TypeDef* channel, FunctionalState state)
{
    (state) ? (channel->CCR |= DMA_CCR_EN) : (channel->CCR &= ~DMA_CCR_EN);
}

/**
  * @brief  Enables or disables the specified DMA Channeln interrupts.
  * @param  channel: select the DMA Channel.
  * @param  it: specifies the DMA interrupts sources to be enabled
  *         or disabled.
  *         This parameter can be any combination of the following values:
  *    @arg DMA_IT_TC:  Transfer complete interrupt mask
  *    @arg DMA_IT_HT:  Half transfer interrupt mask
  *    @arg DMA_IT_TE:  Transfer error interrupt mask
  * @param  state: new state of the specified DMA interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void DMA_ITConfig(DMA_Channel_TypeDef* channel, DMA_Interrupt_EN_TypeDef it, FunctionalState state)
{
    (state) ? (channel->CCR |= it) : (channel->CCR &= ~it);
}

/**
  * @brief  Sets the number of data units in the select the DMA Channel .
  * @param  channel: select the DMA Channel
  * @param  DataNumber: The number of data units in the current DMAy Channelx
  *         transfer.
  * @note   This function can only be used when the DMAy_Channelx is disabled.
  * @retval None.
  */
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef* channel, uint16_t length)
{
    channel->CNDTR = length;
}

/**
  * @brief  Returns the number of remaining data units in the current
  *         DMA Channeln transfer.
  * @retval The number of remaining data units in the current DMA Channeln
  *         transfer.
  */
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* channel)
{
    return channel->CNDTR;
}

/**
  * @brief  Checks whether the specified DMA Channeln flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  *    @arg DMA1_FLAG_GLn: DMA1 Channeln global flag(n = 1..7).
  *    @arg DMA1_FLAG_TCn: DMA1 Channeln transfer complete flag(n = 1..7).
  *    @arg DMA1_FLAG_HTn: DMA1 Channeln half transfer flag(n = 1..7).
  *    @arg DMA1_FLAG_TEn: DMA1 Channeln transfer error flag(n = 1..7).
  * @retval The new state of DMAy_FLAG (SET or RESET).
  */
FlagStatus DMA_GetFlagStatus(DMA_Flags_TypeDef flag)
{
    return (DMA1->ISR & flag) ? SET : RESET;
}

/**
  * @brief  Clears the DMA Channeln's pending flags.
  * @param  flag: specifies the flag to clear.
  *         This parameter can be any combination (for the same DMA) of the
  *         following values:
  *    @arg DMA1_FLAG_GLn: DMA1 Channeln global flag(n = 1..7).
  *    @arg DMA1_FLAG_TCn: DMA1 Channeln transfer complete flag(n = 1..7).
  *    @arg DMA1_FLAG_HTn: DMA1 Channeln half transfer flag(n = 1..7).
  *    @arg DMA1_FLAG_TEn: DMA1 Channeln transfer error flag(n = 1..7).
  * @retval None.
  */
void DMA_ClearFlag(DMA_Flags_TypeDef flag)
{
    DMA1->IFCR = flag;
}

/**
  * @brief  Checks whether the specified DMA Channeln interrupt has occurred or
  * not.
  * @param  it: specifies the DMA interrupt source to check.
  *         This parameter can be one of the following values:
  *    @arg DMA1_IT_GLn: DMA1 Channeln global interrupt(n = 1..7).
  *    @arg DMA1_IT_TCn: DMA1 Channeln transfer complete interrupt(n = 1..7).
  *    @arg DMA1_IT_HTn: DMA1 Channeln half transfer interrupt(n = 1..7).
  *    @arg DMA1_IT_TEn: DMA1 Channeln transfer error interrupt(n = 1..7).
  * @retval  The new state of DMAy_IT (SET or RESET).
  */
ITStatus DMA_GetITStatus(DMA_Interrupts_TypeDef it)
{
    return (DMA1->ISR & it) ? SET : RESET;
}

/**
  * @brief  Clears the DMA Channeln's interrupt pending bits.
  * @param  it: specifies the DMA interrupt pending bit to clear.
  *         This parameter can be any combination (for the same DMA) of the
  *         following values:
  *    @arg DMA1_IT_GLn: DMA1 Channeln global interrupt(n = 1..7).
  *    @arg DMA1_IT_TCn: DMA1 Channeln transfer complete interrupt(n = 1..7).
  *    @arg DMA1_IT_HTn: DMA1 Channeln half transfer interrupt(n = 1..7).
  *    @arg DMA1_IT_TEn: DMA1 Channeln transfer error interrupt(n = 1..7).
  * @retval None.
  */
void DMA_ClearITPendingBit(DMA_Interrupts_TypeDef it)
{
    DMA1->IFCR = it;
}

/**
  * @brief  Set the DMA Channeln's Peripheral address.
  * @param  channel : where n can be 1 to 7 for DMA1 to select the DMA Channel.
  * @param  address : DMA Peripheral address.
  * @retval None.
  */
void exDMA_SetPeripheralAddress(DMA_Channel_TypeDef* channel, uint32_t address)
{
    channel->CPAR = address;
}

/**
  * @brief  Set the DMA Channeln's Peripheral address.
  * @param  channel : select the DMA Channel.
  * @param  length : Transmit lengths.
  * @retval None.
  */
void exDMA_SetTransmitLen(DMA_Channel_TypeDef* channel, uint16_t length)
{
    channel->CNDTR = length;
}

/**
  * @brief  Set the DMA Channeln's Peripheral address.
  * @param  channel :select the DMA Channel.
  * @param  address : DMA memery address.
  * @retval None.
  */
void exDMA_SetMemoryAddress(DMA_Channel_TypeDef* channel, uint32_t address)
{
    channel->CMAR = address;
}

/**
  * @brief  Clears the DMA Channeln's interrupt pending bits.
  * @param  it: specifies the DMA interrupt pending bit to clear.
  *         This parameter can be any combination (for the same DMA) of the
  *         following values:
  *    @arg DMA1_IT_GLn: DMA1 Channeln global interrupt(n = 1..7).
  *    @arg DMA1_IT_TCn: DMA1 Channeln transfer complete interrupt(n = 1..7).
  *    @arg DMA1_IT_HTn: DMA1 Channeln half transfer interrupt(n = 1..7).
  *    @arg DMA1_IT_TEn: DMA1 Channeln transfer error interrupt(n = 1..7).
  * @retval None.
  */
void exDMA_ClearITPendingBit(DMA_Channel_TypeDef* channel, uint32_t it)
{
    DMA1->IFCR = (uint32_t)0x0F << (((*(__IO uint32_t*)&channel & (uint32_t)0xff) - 8) / 5);
    DMA1->IFCR = it;
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
