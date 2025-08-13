/*
 *******************************************************************************
    @file     hal_uart.c
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
#define _HAL_UART_C_

/* Files includes ------------------------------------------------------------*/

#include "hal_uart.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup UART_HAL
  * @{
  */

/** @addtogroup UART_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the uart peripheral registers to their
  *         default reset values.
  * @param  uart: Select the UART or the UART peripheral.
  * @retval None.
  */
void UART_DeInit(UART_TypeDef* uart)
{
    if (uart == UART1)
    {
        RCC_APB2PeriphResetCmd(RCC_APB2RSTR_UART1, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2RSTR_UART1, DISABLE);
    }
    else if (uart == UART2)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1RSTR_UART2, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1RSTR_UART2, DISABLE);
    }
    else if (uart == UART3)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1RSTR_UART3, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1RSTR_UART3, DISABLE);
    }
    else if (uart == UART4)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1RSTR_UART4, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1RSTR_UART4, DISABLE);
    }
}

/**
  * @brief  Initializes the uart peripheral according to the specified
  *         parameters in the UART_InitStruct .
  * @param  uart: Select the UART or the UART peripheral.
  * @param  init_struct: pointer to a UART_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified UART peripheral.
  * @retval None.
  */
void UART_Init(UART_TypeDef* uart, UART_InitTypeDef* init_struct)
{
    uint32_t apbclock = 0x00;

    RCC_ClocksTypeDef RCC_ClocksStatus;

    /* UART CCR Configuration */
    MODIFY_REG(uart->CCR, UART_CCR_CHAR, init_struct->WordLength);

    MODIFY_REG(uart->CCR, (UART_CCR_SPB0 | UART_CCR_SPB1), init_struct->StopBits);

    MODIFY_REG(uart->CCR, (UART_CCR_PEN | UART_CCR_PSEL), init_struct->Parity);

    /* UART GCR Configuration */
    MODIFY_REG(uart->GCR, (UART_GCR_TXEN | UART_GCR_RXEN), init_struct->Mode);
    MODIFY_REG(uart->GCR, UART_GCR_AUTOFLOWEN, init_struct->HWFlowControl);

    /* UART BRR Configuration */
    /* Configure the UART Baud Rate */
    RCC_GetClocksFreq(&RCC_ClocksStatus);
    if (uart == UART1) {

         apbclock = RCC_ClocksStatus.PCLK2_Frequency;
    }
    else {
         apbclock = RCC_ClocksStatus.PCLK1_Frequency;
    }
    /* Determine the UART_baud */
    uart->BRR = (apbclock / init_struct->BaudRate) / 16;
    uart->FRA = (apbclock / init_struct->BaudRate) % 16;
}

/**
  * @brief  Fills each UART_InitStruct member with its default value.
  * @param  init_struct: pointer to a UART_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void UART_StructInit(UART_InitTypeDef* init_struct)
{
    /* UART_InitStruct members default value */
    init_struct->BaudRate       = 9600;
    init_struct->WordLength     = UART_WordLength_8b;
    init_struct->StopBits       = UART_StopBits_1;
    init_struct->Parity         = UART_Parity_No;
    init_struct->Mode           = UART_GCR_RXEN | UART_GCR_TXEN;
    init_struct->HWFlowControl  = UART_HWFlowControl_None;
}

/**
  * @brief  Enables or disables the specified UART peripheral.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the uart peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void UART_Cmd(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_UARTEN, state << UART_GCR_UARTEN_Pos);
}

/**
  * @brief  Enables or disables the specified UART interrupts.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  it: specifies the UART interrupt sources to be
  *         enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    UART_IT_ERR:  Error interrupt(Frame error,)
  * @arg    UART_IT_PE:   Parity Error interrupt
  * @arg    UART_OVER_ERR:  overrun Error interrupt
  * @arg    UART_IT_RXIEN: Receive Data register interrupt
  * @arg    UART_IT_TXIEN:  Tansmit Data Register empty interrupt
  *
  * @param  state: new state of the specified uart interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void UART_ITConfig(UART_TypeDef* uart, uint16_t it, FunctionalState state)
{
    (state) ? (uart->IER |= it) : (uart->IER &= ~it);
}

/**
  * @brief  Enables or disables the UART DMA interface.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  dma_request: specifies the DMA request.
  *         This parameter can be any combination of the following values:
  * @arg    UART_DMAReq_EN: UART DMA transmit request
  *
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void UART_DMACmd(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_DMAMODE, state << UART_GCR_DMAMODE_Pos);
}

/**
  * @brief  Transmits single data through the uart peripheral.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  Data: the data to transmit.
  * @retval None.
  */
void UART_SendData(UART_TypeDef* uart, uint16_t value)
{
    /* Transmit Data */
    WRITE_REG(uart->TDR, (value & 0xFFU));
}

/**
  * @brief  Returns the most recent received data by the uart peripheral.
  * @param  uart: Select the UART or the UART peripheral.
  * @retval  The received data.
  */
uint16_t UART_ReceiveData(UART_TypeDef* uart)
{
    /* Receive Data */
    return (uint16_t)(uart->RDR & 0xFFU);
}

/**
  * @brief  Checks whether the specified UART flag is set or not.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    UART_FLAG_TXEMPTY: Transmit data register empty flag
  * @arg    UART_FLAG_TXFULL: Transmit data buffer full
  * @arg    UART_FLAG_RXAVL: RX Buffer has a byte flag
  * @arg    UART_FLAG_TXEPT: tx and shifter are emptys flag
  * @retval  The new state of UART_FLAG (SET or RESET).
  */
FlagStatus UART_GetFlagStatus(UART_TypeDef* uart, uint16_t flag)
{
    return (uart->CSR & flag) ? SET : RESET;
}

/**
  * @brief  Checks whether the specified UART interrupt has occurred or not.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  it: specifies the UART interrupt source to check.
  *         This parameter can be one of the following values:
  * @arg    UART_IT_ERR:  Error interrupt(Frame error,)
  * @arg    UART_IT_PE:   Parity Error interrupt
  * @arg    UART_OVER_ERR:  overrun Error interrupt
  * @arg    UART_IT_RXIEN: Receive Data register interrupt
  * @arg    UART_IT_TXIEN:  Tansmit Data Register empty interrupt
  * @retval  The new state of UART_IT (SET or RESET).
  */
ITStatus UART_GetITStatus(UART_TypeDef* uart, uint16_t it)
{
    if(uart->IER & it)
    {
        return (uart->ISR & it) ? SET : RESET;
    }   
    else 
    {
        return RESET;
    }
}

/**
  * @brief  Clears the uart interrupt pending bits.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  it: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  * @arg    UART_IT_ERR:  Error interrupt(Frame error,)
  * @arg    UART_IT_PE:   Parity Error interrupt
  * @arg    UART_OVER_ERR:  overrun Error interrupt
  * @arg    UART_IT_RXIEN: Receive Data register interrupt
  * @arg    UART_IT_TXIEN:  Tansmit Data Register empty interrupt
  * @retval None.
  */
void UART_ClearITPendingBit(UART_TypeDef* uart, uint16_t it)
{
    /* clear UART_IT pendings bit */
    uart->ICR = it;
}

/**
  * @brief  Selects the UART WakeUp method.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  mode: specifies the UART wakeup method.
  * @retval None.
  */
void UART_WakeUpConfig(UART_TypeDef* uart, UART_WakeUp_TypeDef mode)
{
    MODIFY_REG(uart->CCR, UART_CCR_WAKE, mode);
}

/**
  * @brief  Determines if the UART is in mute mode or not.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the UART mute mode.
  * @retval None.
  */
void UART_ReceiverWakeUpCmd(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->CCR, UART_CCR_RWU, state << UART_CCR_RWU_Pos);
}

/**
  * @brief  Sets the address of the UART Rx Address.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  address: Indicates the address of the UART Rx Address.
  * @retval None.
  */
void UART_SetRXAddress(UART_TypeDef* uart, uint8_t address)
{
    MODIFY_REG(uart->RXADDR, UART_RXADDR, address);
}

/**
  * @brief  Sets the address of the UART Rx MASK.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  address: Indicates the address of the UART Rx MASK.
  * @retval None.
  */
void UART_SetRXMASK(UART_TypeDef* uart, uint8_t address)
{
    MODIFY_REG(uart->RXMASK, UART_RXMASK, address);
}

/**
  * @brief  ENBALE or DISABLE the UART's 9bit.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the UART 9 bit.
  * @retval None.
  */
void UART_Enable9bit(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->CCR, UART_CCR_B8EN, state << UART_CCR_B8EN_Pos);
}

/**
  * @brief  Set the UART's 9bit Level.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the UART 9 bit.
  * @retval None.
  */
void UART_Set9bitLevel(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->CCR, UART_CCR_B8TXD, state << UART_CCR_B8TXD_Pos);
}

/**
  * @brief  Set the UART's 9bit Polarity.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  polarity: new state of the UART 9 bit Polarity.
  * @retval None.
  */
void UART_Set9bitPolarity(UART_TypeDef* uart, UART_9bit_Polarity_TypeDef polarity)
{
    MODIFY_REG(uart->CCR, UART_CCR_B8POL, polarity);
}

/**
  * @brief  Set the UART's 9bit Automatic Toggle.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the UART 9 bit Automatic Toggle.
  * @retval None.
  */
void UART_Set9bitAutomaticToggle(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->CCR, UART_CCR_B8TOG, state << UART_CCR_B8TOG_Pos);
}

/**
  * @brief  Enables or disables the UART Half Duplex communication.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the UART Communication.
  * @retval None.
  */
void UART_HalfDuplexCmd(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->SCR, UART_SCR_HDSEL, state << UART_SCR_HDSEL_Pos);
}

/**
  * @brief  Sets the specified UART guard time.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  guard_time: specifies the guard time.
  * @retval None.
  */
void UART_SetGuardTime(UART_TypeDef* uart, uint8_t guard_time)
{
    MODIFY_REG(uart->SCR, UART_SCR_SCFCNT, guard_time << UART_SCR_SCFCNT_Pos);
    /* Clear the UART Guard time */
    /* uart->SCR &= SCR_SCFCNT_Mask; */
    /* Set the UART guard time */
    /* uart->SCR |= (uint16_t)((uint16_t)guard_time << 0x04); */
}

/**
  * @brief  Enables or disables the UART's Smart Card mode.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the Smart Card mode.
  * @retval None.
  */
void UART_SmartCardCmd(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->SCR, UART_SCR_SCEN, state << UART_SCR_SCEN_Pos);
}

/**
  * @brief  Enables or disables NACK transmission.
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the NACK transmission.
  * @retval None.
  */
void UART_SmartCardNACKCmd(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->SCR, UART_SCR_SCEN, state << UART_SCR_SCAEN_Pos);
}

/**
  * @brief  Transmits break characters.
  * @param  uart: Select the UART or the UART peripheral.
  * @retval None.
  */
void UART_SendBreak(UART_TypeDef* uart)
{
    SET_BIT(uart->CCR, UART_CCR_BRK);
}

/**
  * @brief  Enable or Disable Auto Baud-Rate Detection
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of the UART AutoBaudRate Detection.
  * @retval None.
  */
void UART_AutoBaudRateCmd(UART_TypeDef* uart, FunctionalState state)
{
    state ? SET_BIT(uart->ABRCR, UART_ABRCR_ABREN) : CLEAR_BIT(uart->ABRCR, UART_ABRCR_ABREN) ;
}

/**
  * @brief  AutoBaudRate.
  * @param  uart: Select the UART or the UART peripheral.
  *         value: special character.
  *         state: ENABLE/DISABLE.
  * @retval None.
  */
void UART_AutoBaudRateSet(UART_TypeDef* uart, UART_AutoBaud_TypeDef value, FunctionalState state)
{
    CLEAR_BIT(uart->ABRCR, UART_ABRCR_ABREN);
    /* This bit field can only be written when ABREN = 0 or the UART is disabled (UARTEN=0). */

    if ((value == ABRMODE_FALLING_TO_RISINGEDGE1BIT) || (value == ABRMODE_STARTBIT) || (value == ABRMODE_VALUE0XFF)) {
        /* UART measures the duration of the start bit (falling edge) to first rising edge */
        /* FORMER edge = 0  LATTER edge= 1, from fist falling edge to rising edge = one bit */
        /* ___   _               _______ */
        /*    |_|1 x x x x x x x|        = Bxxxx xxx1  F to U = 1 start bit */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_LATTER_EDGE | UART_ABRCR_ABR_BITCNT_MODE0 );
    }
    else if((value == ABRMODE_FALLING_TO_RISINGEDGE2BIT) || (value == Data_FE))  {
        /* UART measures the duration of the start bit (falling edge) to first rising edge */
        /* FORMER edge = 0  LATTER edge= 1, from fist falling edge to rising edge = two bit */
        /* ___     _             _______ */
        /*    |_ _|1 x x x x x x|        = Bxxxx xx10  F to U = 2 */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_LATTER_EDGE | UART_ABRCR_ABR_BITCNT_MODE1);
    }
    else if((value == ABRMODE_FALLING_TO_RISINGEDGE4BIT) || (value == Data_F8)) {
        /* UART measures the duration of the start bit (falling edge) to first rising edge */
        /* FORMER edge = 0  LATTER edge= 1, from fist falling edge to rising edge = four bit */
        /* ___         _         _______ */
        /*    |_ _ _ _|1 x x x x|        = Bxxxx 1000  F to U = 4 */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_LATTER_EDGE | UART_ABRCR_ABR_BITCNT_MODE2);
    }
    else if((value == ABRMODE_FALLING_TO_RISINGEDGE8BIT) || (value == ABRMODE_VALUE0X80))  {
        /* UART measures the duration of the start bit (falling edge) to first rising edge */
        /* FORMER edge = 0  LATTER edge= 1, from fist falling edge to rising edge = eight bit */
        /* ___                 _ ______ */
        /*    |_ _ _ _ _ _ _ _|1         = B1000 0000  F to U = 8 */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_LATTER_EDGE | UART_ABRCR_ABR_BITCNT_MODE3);
    }
    else if((value == ABRMODE_FALLING_TO_FALLINGEDGE2BIT) || (value == ABRMODE_VALUE0X55)) {
        /* UART measures the duration of the start bit (falling edge) to next falling edge */
        /* FORMER edge = 0  LATTER edge= 0, from fist falling edge to next falling edge = two bit */
        /* ___   _               ______ */
        /*    |_|1|_|x x x x x x|        = Bxxxx xx01  F to F = 2 0x55 and Falling to Falling */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_ABR_BITCNT_MODE1);
    }
    else if((value == ABRMODE_FALLING_TO_FALLINGEDGE4BIT) || (value == ABRMODE_VALUE0XF7))  {
        /* UART measures the duration of the start bit (falling edge) to next falling edge */
        /* FORMER edge = 0  LATTER edge= 0, from fist falling edge to next falling edge = four bit */
        /* ___   _ _ _           ______ */
        /*    |_|1 1 1|_|x x x x|        = Bxxxx 0111  F to F = 4 */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_ABR_BITCNT_MODE2);
    }
    else if((value == ABRMODE_FALLING_TO_FALLINGEDGE8BIT) || (value == ABRMODE_VALUE0x7F)) {
        /* UART measures the duration of the start bit (falling edge) to next falling edge */
        /* FORMER edge = 0  LATTER edge= 0, from fist falling edge to next falling edge = eight bit */
        /* ___   _ _ _ _ _ _ _   ______ */
        /*    |_|1 1 1 1 1 1 1|_|        = B0111 1111  F to F = 8 0x7F */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_ABR_BITCNT_MODE3);
    }

    else {
        /* UART measures the duration of the start bit (falling edge) to next falling edge */
        /* FORMER edge = 0  LATTER edge= 0, from fist falling edge to next falling edge = eight bit */
        /* ___   _ _ _ _ _ _ _   ______ */
        /*    |_|1 1 1 1 1 1 1|_|        = B0111 1111  F to F = 8 0x7F */

        MODIFY_REG(uart->ABRCR, UART_ABRCR_LATTER_EDGE | UART_ABRCR_FORMER_EDGE | UART_ABRCR_ABR_BITCNT, \
                   UART_ABRCR_ABR_BITCNT_MODE3);
    }
    if(state == ENABLE) {
        SET_BIT(uart->ABRCR, UART_ABRCR_ABREN);
    }
}

/**
  * @brief  Set UART  TX polarity
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of TX polarity.
  * @retval None.
  */
void UART_SetTXToggle(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_TXTOG, state << UART_GCR_TXTOG_Pos);
}

/**
  * @brief  Set UART  RX polarity
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of RX polarity.
  * @retval None.
  */
void UART_SetRXToggle(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_RXTOG, state << UART_GCR_RXTOG_Pos);
}

/**
  * @brief  Set UART  TX<--->RX
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of tx and rx .
  * @retval None.
  */
void UART_SetTxRxSWAP(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_SWAP, state << UART_GCR_SWAP_Pos);
}

/**
  * @brief  Set UART  TX Enable
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of TX.
  * @retval None.
  */
void UART_SetTransmitEnable(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_TXEN, state << UART_GCR_TXEN_Pos);
}

/**
  * @brief  Set UART  RX Enable
  * @param  uart: Select the UART or the UART peripheral.
  * @param  state: new state of TX.
  * @retval None.
  */
void UART_SetRecevieEnable(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->GCR, UART_GCR_RXEN, state << UART_GCR_RXEN_Pos);
}

/**
  * @brief  Set LIN  Enable
  * @param  uart: Select the UART or the UART peripheral.
  * @retval None.
  */
void UART_SetLIN(UART_TypeDef* uart, FunctionalState state)
{
    MODIFY_REG(uart->CCR, UART_CCR_LIN, state << UART_CCR_LIN_Pos);
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
