/*
 *******************************************************************************
    @file     hal_uart.h
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
#ifndef __HAL_UART_H
#define __HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup UART_HAL
  * @brief UART HAL modules
  * @{
  */

/** @defgroup UART_Exported_Types
  * @{
  */


#define UART_IER_TXIEN                  UART_IER_TX_IEN
#define UART_IER_RXIEN                  UART_IER_RX_IEN
#define UART_IER_RXOERREN               UART_IER_RXOERR_IEN
#define UART_IER_RXPERREN               UART_IER_RXPERR_IEN
#define UART_IER_RXFERREN               UART_IER_RXFERR_IEN
#define UART_IER_RXBRKEN                UART_IER_RXBRK_IEN

#define UART_ICR_TXICLR                 UART_ICR_TX
#define UART_ICR_RXICLR                 UART_ICR_RX
#define UART_ICR_RXOERRCLR              UART_ICR_RXOERR
#define UART_ICR_RXPERRCLR              UART_ICR_RXPERR
#define UART_ICR_RXFERRCLR              UART_ICR_RXFERR
#define UART_ICR_RXBRKCLR               UART_ICR_RXBRK

#define UART_Mode_Rx                    UART_GCR_RXEN
#define UART_Mode_Tx                    UART_GCR_TXEN
#define UART_EN                         UART_GCR_UART
#define UART_IT_RXBRK                   UART_IER_RXBRK_IEN
#define UART_IT_ERR                     UART_IER_RXFERR_IEN
#define UART_IT_PE                      UART_IER_RXPERR_IEN
#define UART_OVER_ERR                   UART_IER_RXOERR_IEN
#define UART_IT_RXIEN                   UART_IER_RX_IEN
#define UART_IT_TXIEN                   UART_IER_TX_IEN

#define UART_HardwareFlowControl_None   UART_HWFlowControl_None

#define UART_BRR_DIV_MANTISSA           UART_BRR_MANTISSA
#define UART_BRR_DIV_FRACTION           UART_BRR_FRACTION

#define UART_DMAReq_EN                  UART_GCR_DMA
#define UART_FLAG_TXEMPTY               UART_CSR_TXEPT
#define UART_FLAG_TXFULL                UART_CSR_TXFULL
#define UART_FLAG_RXAVL                 UART_CSR_RXAVL
#define UART_FLAG_TXEPT                 UART_CSR_TXC

/**
  * @brief UART Word Length Enumerate definition
  * @anchor UART_Word_Length
  */
typedef enum {
    UART_WordLength_5b                  = 0U,
    UART_WordLength_6b                  = 1U << UART_CCR_CHAR_Pos,
    UART_WordLength_7b                  = 2U << UART_CCR_CHAR_Pos,
    UART_WordLength_8b                  = 3U << UART_CCR_CHAR_Pos
} UART_WordLength_TypeDef;

/**
  * @brief UART Stop Bits Enumerate definition
  * @anchor UART_Stop_Bits
  */
typedef enum {
    UART_StopBits_1                     = 0U,
    UART_StopBits_2                     = UART_CCR_SPB0,

    UART_StopBits_0_5                   = UART_CCR_SPB1,
    UART_StopBits_1_5                   = UART_CCR_SPB1 | UART_CCR_SPB0,
} UART_Stop_Bits_TypeDef;

/**
  * @brief UART Parity Enumerate definition
  * @anchor UART_Parity
  */
typedef enum {
    UART_Parity_No                      = 0U,
    UART_Parity_Even                    = UART_CCR_PEN | UART_CCR_PSEL,
    UART_Parity_Odd                     = UART_CCR_PEN
} UART_Parity_TypeDef;

/**
  * @brief UART Hardware Flow Control Enumerate definition
  * @anchor UART_Hardware_Flow_Control
  */
typedef enum {
    UART_HWFlowControl_None             = 0U,

    /*    UART_HWFlowControl_RTS     = UART_GCR_AUTOFLOWEN, */
    /*    UART_HWFlowControl_CTS     = UART_GCR_AUTOFLOW, */

    UART_HWFlowControl_RTS_CTS          = UART_GCR_AUTOFLOWEN
} UART_HW_FLOWCONTROL_TypeDef;

typedef enum {
    UART_WakeUp_IdleLine                = 0U,
    UART_WakeUp_AddressMark             = UART_CCR_WAKE
} UART_WakeUp_TypeDef;

typedef enum {
    UART_9bit_Polarity_Low              = 0U,
    UART_9bit_Polarity_High             = UART_CCR_B8POL
} UART_9bit_Polarity_TypeDef;

/**
  * @brief UART Auto BaudRate definition
  */
typedef enum {
    Data_F8 = 0,
    Data_FE,
    ABRMODE_FALLING_TO_RISINGEDGE1BIT,
    ABRMODE_FALLING_TO_RISINGEDGE2BIT,
    ABRMODE_FALLING_TO_RISINGEDGE4BIT,
    ABRMODE_FALLING_TO_RISINGEDGE8BIT,
    ABRMODE_FALLING_TO_FALLINGEDGE2BIT,
    ABRMODE_FALLING_TO_FALLINGEDGE4BIT,
    ABRMODE_FALLING_TO_FALLINGEDGE8BIT,
    ABRMODE_STARTBIT,
    ABRMODE_VALUE0X55,
    ABRMODE_VALUE0x7F,
    ABRMODE_VALUE0X80,
    ABRMODE_VALUE0XF7,
    ABRMODE_VALUE0XF8 = Data_F8,
    ABRMODE_VALUE0XFE = Data_FE,
    ABRMODE_VALUE0XFF,
} UART_AutoBaud_TypeDef;

/**
  * @brief UART Init Structure definition
  */
typedef struct {
    union {
        uint32_t                             BaudRate;                               /*!< This member configures the UART communication baud rate. */
        uint32_t                             UART_BaudRate;
    };
    union {
        UART_WordLength_TypeDef         WordLength;                             /*!< Specifies the number of data bits transmitted or received in a frame. */
        uint16_t                             UART_WordLength;
    };
    union {
        UART_Stop_Bits_TypeDef          StopBits;                               /*!< Specifies the number of stop bits transmitted. */
        uint16_t                             UART_StopBits;
    };
    union {
        UART_Parity_TypeDef             Parity;                                 /*!< Specifies the parity mode. */
        uint16_t                             UART_Parity;
    };
    union {
        uint16_t                             Mode;                                   /*!< Specifies wether the Receive or Transmit mode is */
        uint16_t                             UART_Mode;
    };
    union {
        UART_HW_FLOWCONTROL_TypeDef     HWFlowControl;                          /*!< Specifies wether the hardware flow control mode is enabled or disabled. */
        uint16_t                             UART_HardwareFlowControl;
    };
} UART_InitTypeDef;

/**
  * @}
  */

/** @defgroup UART_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Exported_Variables
  * @{
  */
#ifdef _HAL_UART_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL
/**
  * @}
  */


/** @defgroup UART_Exported_Functions
  * @{
  */
void UART_DeInit(UART_TypeDef* uart);
void UART_Init(UART_TypeDef* uart, UART_InitTypeDef* init_struct);
void UART_StructInit(UART_InitTypeDef* init_struct);
void UART_Cmd(UART_TypeDef* uart, FunctionalState state);
void UART_ITConfig(UART_TypeDef* uart, uint16_t it, FunctionalState state);
void UART_DMACmd(UART_TypeDef* uart, FunctionalState state);
void UART_SendData(UART_TypeDef* uart, uint16_t Data);
void UART_ClearITPendingBit(UART_TypeDef* uart, uint16_t it);

uint16_t        UART_ReceiveData(UART_TypeDef* uart);
FlagStatus UART_GetFlagStatus(UART_TypeDef* uart, uint16_t flag);

ITStatus   UART_GetITStatus(UART_TypeDef* uart, uint16_t it);

void UART_WakeUpConfig(UART_TypeDef* uart, UART_WakeUp_TypeDef mode);
void UART_ReceiverWakeUpCmd(UART_TypeDef* uart, FunctionalState state);
void UART_SetRXAddress(UART_TypeDef* uart, uint8_t address);
void UART_SetRXMASK(UART_TypeDef* uart, uint8_t address);
void UART_Enable9bit(UART_TypeDef* uart, FunctionalState state);
void UART_Set9bitLevel(UART_TypeDef* uart, FunctionalState state);
void UART_Set9bitPolarity(UART_TypeDef* uart, UART_9bit_Polarity_TypeDef polarity);
void UART_Set9bitAutomaticToggle(UART_TypeDef* uart, FunctionalState state);
void UART_HalfDuplexCmd(UART_TypeDef* uart, FunctionalState state);
void UART_SetGuardTime(UART_TypeDef* uart, uint8_t guard_time);
void UART_SmartCardCmd(UART_TypeDef* uart, FunctionalState state);
void UART_SmartCardNACKCmd(UART_TypeDef* uart, FunctionalState state);
void UART_SendBreak(UART_TypeDef* uart);
void UART_AutoBaudRateCmd(UART_TypeDef* uart, FunctionalState state);
void UART_AutoBaudRateSet(UART_TypeDef* uart, UART_AutoBaud_TypeDef value, FunctionalState state);
void UART_SetTXToggle(UART_TypeDef* uart, FunctionalState state);
void UART_SetRXToggle(UART_TypeDef* uart, FunctionalState state);
void UART_SetTxRxSWAP(UART_TypeDef* uart, FunctionalState state);
void UART_SetTransmitEnable(UART_TypeDef* uart, FunctionalState state);
void UART_SetRecevieEnable(UART_TypeDef* uart, FunctionalState state);
void UART_SetLIN(UART_TypeDef* uart, FunctionalState state);

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
#endif/* __HAL_UART_H --------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
