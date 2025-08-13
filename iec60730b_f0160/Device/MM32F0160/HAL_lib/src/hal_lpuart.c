/*
 *******************************************************************************
    @file     hal_lpuart.c
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
#define _HAL_LPUART_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_lpuart.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup LPUART_HAL
  * @{
  */

/** @addtogroup LPUART_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the lpuart peripheral registers to their
  *         default reset values.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @retval None.
  */
void LPUART_DeInit(LPUART_TypeDef* lpuart)
{
    if(LPUART1 == lpuart) {
        RCC_APB2PeriphResetCmd(RCC_APB2ENR_LPUART, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2ENR_LPUART, DISABLE);
    }
}

/**
  * @brief  Initializes the lpuart peripheral according to the specified
  *         parameters in the LPUART_InitStruct .
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  init_struct: pointer to a LPUART_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified LPUART peripheral.
  * @retval None.
  */
void LPUART_Init(LPUART_TypeDef* lpuart, LPUART_InitTypeDef* init_struct)
{
    RCC->CFGR2 &= ~RCC_CFGR2_LPUART_CLKSEL;
    if(init_struct->LPUART_Clock_Source == 1) {
        RCC->CFGR2 |= RCC_CFGR2_LPUART_CLKSEL_LSI;
    }
    else if(init_struct->LPUART_Clock_Source == 2) {
        RCC->CFGR2 |= RCC_CFGR2_LPUART_CLKSEL_PCLK_LPUART;
    }
    else if(init_struct->LPUART_Clock_Source == 0) {
        RCC->CFGR2 |= RCC_CFGR2_LPUART_CLKSEL_LSE;
    }

    lpuart->LPUBAUD &= (~LPUART_LPUBAUD_BAUD_Msk);
    lpuart->LPUBAUD |= (init_struct->LPUART_BaudRate);
    lpuart->MODU &= (~LPUART_MODU_MCTL);
    lpuart->MODU |= init_struct->LPUART_MDU_Value;                              /* 0x952 if use LSE32.768k as Clock source */

    /* LPUART LPUCON Configuration */
    MODIFY_REG(lpuart->LPUCON, (LPUART_LPUCON_DL | LPUART_LPUCON_SL | \
                                LPUART_LPUCON_PAREN | LPUART_LPUCON_PTYP | \
                                LPUART_LPUCON_RXEV | LPUART_LPUCON_NEDET), \
               (uint32_t)init_struct->LPUART_WordLength | (uint32_t)init_struct->LPUART_StopBits | \
               (uint32_t)init_struct->LPUART_Parity | (uint32_t)init_struct->LPUART_RecvEventCfg | \
               (uint32_t)init_struct->LPUART_NEDET_Source);
}

/**
  * @brief  Fills each LPUART_InitStruct member with its default value.
  * @param  init_struct: pointer to a LPUART_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void LPUART_StructInit(LPUART_InitTypeDef* init_struct)
{
    /* LPUART_InitStruct members default value */
    init_struct->LPUART_Clock_Source    = 0;
    init_struct->LPUART_BaudRate        = LPUART_Baudrate_9600;
    init_struct->LPUART_WordLength      = LPUART_WordLength_8b;
    init_struct->LPUART_StopBits        = LPUART_StopBits_1;
    init_struct->LPUART_Parity          = LPUART_Parity_No;
    init_struct->LPUART_MDU_Value       = 0x952;
    init_struct->LPUART_NEDET_Source    = LPUART_NegativeDectect_Source2;
    init_struct->LPUART_RecvEventCfg    = LPUART_RecvEvent_Start_Bit;
}

/**
  * @brief  Enables or disables the specified LPUART Tx and Rx.
  * @param  lpuart: Select the LPUART peripheral.
  * @param  state: new state of the lpuart peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_Cmd(LPUART_TypeDef* lpuart, FunctionalState state)
{
    if (state != DISABLE) { /* tx/rx enable */
        SET_BIT(lpuart->LPUEN, (LPUART_LPUEN_TXEN | LPUART_LPUEN_RXEN));
    }
    else {
        CLEAR_BIT(lpuart->LPUEN, (LPUART_LPUEN_TXEN | LPUART_LPUEN_RXEN));
    }
}

/**
  * @brief  Enables or disables the specified LPUART Tx.
  * @param  lpuart: Select the LPUART.
  * @param  state: new state of the lpuart Tx.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_TX_Cmd(LPUART_TypeDef* lpuart, FunctionalState state)
{

    if (state != DISABLE) { /* tx/rx enable */
        SET_BIT(lpuart->LPUEN, (LPUART_LPUEN_TXEN));
    }
    else {
        CLEAR_BIT(lpuart->LPUEN, (LPUART_LPUEN_TXEN));
    }
}

/**
  * @brief  Enables or disables the specified LPUART Rx.
  * @param  lpuart: Select the LPUART.
  * @param  state: new state of the lpuart Rx.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_RX_Cmd(LPUART_TypeDef* lpuart, FunctionalState state)
{
    if (state != DISABLE) { /* tx/rx enable */
        SET_BIT(lpuart->LPUEN, (LPUART_LPUEN_RXEN));
    }
    else {
        CLEAR_BIT(lpuart->LPUEN, (LPUART_LPUEN_RXEN));
    }
}

/**
  * @brief  Enables or disables the specified LPUART interrupts.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  it: specifies the LPUART interrupt sources to be
  *         enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    LPUART_LPUCON_ERRIE: Error interrupt Enable
  * @arg    LPUART_LPUCON_RXIE : Receive interrupt Enable
  * @arg    LPUART_LPUCON_TCIE : Transmit complete interrupt Enable
  * @arg    LPUART_LPUCON_TXIE : Transmit Buffer Empty interrupt Enable
  *
  * @param  state: new state of the specified lpuart interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_ITConfig(LPUART_TypeDef* lpuart, uint16_t it, FunctionalState state)
{
    it = it & (LPUART_LPUCON_ERRIE | LPUART_LPUCON_RXIE | \
               LPUART_LPUCON_TCIE | LPUART_LPUCON_TXIE);
    (state) ? (lpuart->LPUCON |= it) : (lpuart->LPUCON &= ~it);
}

/**
  * @brief  Enables or disables the LPUART DMA interface.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_DMACmd(LPUART_TypeDef* lpuart, FunctionalState state)
{
    if (state != DISABLE) { /* tx/rx enable */
        SET_BIT(lpuart->LPUEN, (LPUART_LPUEN_DMAT | LPUART_LPUEN_DMAR));
    }
    else {
        CLEAR_BIT(lpuart->LPUEN, (LPUART_LPUEN_DMAT | LPUART_LPUEN_DMAR));
    }
}

/**
  * @brief  Enables or disables the LPUART DMA Tx interface.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_TX_DMACmd(LPUART_TypeDef* lpuart, FunctionalState state)
{
    if (state != DISABLE) { /* tx/rx enable */
        SET_BIT(lpuart->LPUEN, LPUART_LPUEN_DMAT);
    }
    else {
        CLEAR_BIT(lpuart->LPUEN, LPUART_LPUEN_DMAT);
    }
}

/**
  * @brief  Enables or disables the LPUART DMA Rx interface.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_RX_DMACmd(LPUART_TypeDef* lpuart, FunctionalState state)
{
    if (state != DISABLE) { /* tx/rx enable */
        SET_BIT(lpuart->LPUEN, LPUART_LPUEN_DMAR);
    }
    else {
        CLEAR_BIT(lpuart->LPUEN, LPUART_LPUEN_DMAR);
    }
}

/**
  * @brief  Transmits single data through the lpuart peripheral.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  value: the data to transmit.
  * @retval None.
  */
void LPUART_SendData(LPUART_TypeDef* lpuart, uint8_t value)
{
    /* Transmit Data */
    WRITE_REG(lpuart->LPUTXD, (value & 0xFFU));
}

/**
  * @brief  Returns the most recent received data by the lpuart peripheral.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @retval  The received data.
  */
uint8_t LPUART_ReceiveData(LPUART_TypeDef* lpuart)
{
    /* Receive Data */
    return (uint8_t)(lpuart->LPURXD & 0xFFU);
}

/**
  * @brief  Checks whether the specified LPUART flag is set or not.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    LPUART_LPUSTA_START : Start bit detected flag
  * @arg    LPUART_LPUSTA_PERR  : Check bit error flag
  * @arg    LPUART_LPUSTA_TC    : Transmit data completed flag
  * @arg    LPUART_LPUSTA_TXE   : Transmit buffer empty flag
  * @arg    LPUART_LPUSTA_RXF   : Receive buffer is fulled flag
  * @arg    LPUART_LPUSTA_MATCH : Data is matched flag
  * @arg    LPUART_LPUSTA_FERR  : Frame format error flag
  * @arg    LPUART_LPUSTA_RXOV  : Receive buffer overflow flag
  * @retval The new state of LPUART_FLAG (SET or RESET).
  */
FlagStatus LPUART_GetFlagStatus(LPUART_TypeDef* lpuart, uint16_t flag)
{
    return (lpuart->LPUSTA & flag) ? SET : RESET;
}

/**
  * @brief  Clear the specified LPUART status flag.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    LPUART_LPUSTA_START : Start bit detected flag
  * @arg    LPUART_LPUSTA_PERR  : Check bit error flag
  * @arg    LPUART_LPUSTA_MATCH : Data is matched flag
  * @arg    LPUART_LPUSTA_FERR  : Frame format error flag
  * @arg    LPUART_LPUSTA_RXOV  : Receive buffer overflow flag
  * @retval The new state of LPUART_FLAG (SET or RESET).
  */
void LPUART_ClearFlagStatus(LPUART_TypeDef* lpuart, uint16_t flag)
{
    lpuart->LPUSTA = flag;
}

/**
  * @brief  Checks whether the specified LPUART interrupt has occurred or not.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  it: specifies the LPUART interrupt source to check.
  *         This parameter can be one of the following values:
  * @arg    LPUART_LPUIF_TCIF    : Transmit complete interrupt complete flag
  * @arg    LPUART_LPUIF_RXNEGIF : Received falling edge interrupt flag
  * @arg    LPUART_LPUIF_TXIF    : Transmit buffer empty interrupt flag
  * @arg    LPUART_LPUIF_RXIF    : Receive data finish interrupt flag
  * @retval  The new state of LPUART_IT (SET or RESET).
  */
ITStatus LPUART_GetITStatus(LPUART_TypeDef* lpuart, uint16_t it)
{
    return (lpuart->LPUIF & it) ? SET : RESET;
}

/**
  * @brief  Clears the lpuart interrupt pending bits.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  it: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  * @arg    LPUART_LPUIF_TCIF    : Transmit complete interrupt complete flag
  * @arg    LPUART_LPUIF_RXNEGIF : Received falling edge interrupt flag
  * @arg    LPUART_LPUIF_TXIF    : Transmit buffer empty interrupt flag
  * @arg    LPUART_LPUIF_RXIF    : Receive data finish interrupt flag
  * @retval None.
  */
void LPUART_ClearITPendingBit(LPUART_TypeDef* lpuart, uint16_t it)
{
    /* clear LPUART_IT pendings bit */
    lpuart->LPUIF = it;
}

/**
  * @brief  Selects the LPUART WakeUp method.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  mode: specifies the LPUART wakeup method.
  * @retval None.
  */
void LPUART_WakeUpConfig(LPUART_TypeDef* lpuart, LPUART_WakeUp_TypeDef mode)
{
    MODIFY_REG(lpuart->WKCKE, LPUART_WKCKE, mode);
}

/**
  * @brief  Set LPUART  TX polarity
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of TX polarity.
  * @retval None.
  */
void LPUART_SetTXToggle(LPUART_TypeDef* lpuart, FunctionalState state)
{
    MODIFY_REG(lpuart->LPUCON, LPUART_LPUCON_TXPOL, state << LPUART_LPUCON_TXPOL_Pos);
}

/**
  * @brief  Set LPUART  RX polarity
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of RX polarity.
  * @retval None.
  */
void LPUART_SetRXToggle(LPUART_TypeDef* lpuart, FunctionalState state)
{
    MODIFY_REG(lpuart->LPUCON, LPUART_LPUCON_RXPOL, state << LPUART_LPUCON_RXPOL_Pos);
}

/**
  * @brief  Set LPUART  TX Enable
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of TX.
  * @retval None.
  */
void LPUART_SetTransmitEnable(LPUART_TypeDef* lpuart, FunctionalState state)
{

    MODIFY_REG(lpuart->LPUEN, LPUART_LPUEN_TXEN, state << LPUART_LPUEN_TXEN_Pos);
}

/**
  * @brief  Set LPUART  RX Enable
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of TX.
  * @retval None.
  */
void LPUART_SetRecevieEnable(LPUART_TypeDef* lpuart, FunctionalState state)
{
    MODIFY_REG(lpuart->LPUEN, LPUART_LPUEN_RXEN, state << LPUART_LPUEN_RXEN_Pos);
}

/**
  * @brief  Set match compare data through the lpuart peripheral.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  value: the data to be compared.
  * @retval None.
  */
void LPUART_SetMatchData(LPUART_TypeDef* lpuart, uint8_t value)
{
    /* Transmit Data */
    WRITE_REG(lpuart->COMPARE, (value & 0xFFU));
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
