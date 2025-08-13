/*
 *******************************************************************************
    @file     hal_exti.h
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
#ifndef __HAL_EXTI_H
#define __HAL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup EXTI_HAL
  * @brief EXTI HAL modules
  * @{
  */

/** @defgroup EXTI_Exported_Types
  * @{
  */

/**
  * @brief  EXTI mode enumeration
  */
typedef enum
{
    EXTI_Mode_Interrupt                 = 0x00,                                 /*!< EXTI interrupt mode */
    EXTI_Mode_Event                     = 0x04                                  /*!< EXTI event mode */
} EXTIMode_TypeDef;

/**
  * @brief  EXTI Trigger enumeration
  */
typedef enum
{
    EXTI_Trigger_Rising                 = 0x08,                                 /*!< EXTI rising edge triggering */
    EXTI_Trigger_Falling                = 0x0C,                                 /*!< EXTI falling edge triggering */
    EXTI_Trigger_Rising_Falling         = 0x10                                  /*!< EXTI rising and falling edge triggers */
} EXTITrigger_TypeDef;

/**
  * @brief  EXTI Init Structure definition
  */
typedef struct
{
    uint32_t EXTI_Line;                                                         /*!< Specifies the EXTI lines to be enabled or disabled. */
    /*!< This parameter can be any combination of @ref EXTI_Lines */
    EXTIMode_TypeDef EXTI_Mode;                                                 /*!< Specifies the mode for the EXTI lines. */
    /*!< This parameter can be a value of @ref EXTIMode_TypeDef */
    EXTITrigger_TypeDef EXTI_Trigger;                                           /*!< Specifies the trigger signal active edge for the EXTI lines. */
    /*!< This parameter can be a value of @ref EXTIMode_TypeDef */
    FunctionalState EXTI_LineCmd;                                               /*!< Specifies the new state of the selected EXTI lines. */
    /*!< This parameter can be set either to ENABLE or DISABLE */
} EXTI_InitTypeDef;

/**
  * @}
  */

/** @defgroup EXTI_Exported_Constants
  * @{
  */
#define EXTI_LineNone                   ((uint32_t)0x0000000)                   /*!< No interrupt selected */
#define EXTI_Line0                      ((uint32_t)0x0000001)                   /*!< External interrupt line 0 */
#define EXTI_Line1                      ((uint32_t)0x0000002)                   /*!< External interrupt line 1 */
#define EXTI_Line2                      ((uint32_t)0x0000004)                   /*!< External interrupt line 2 */
#define EXTI_Line3                      ((uint32_t)0x0000008)                   /*!< External interrupt line 3 */
#define EXTI_Line4                      ((uint32_t)0x0000010)                   /*!< External interrupt line 4 */
#define EXTI_Line5                      ((uint32_t)0x0000020)                   /*!< External interrupt line 5 */
#define EXTI_Line6                      ((uint32_t)0x0000040)                   /*!< External interrupt line 6 */
#define EXTI_Line7                      ((uint32_t)0x0000080)                   /*!< External interrupt line 7 */
#define EXTI_Line8                      ((uint32_t)0x0000100)                   /*!< External interrupt line 8 */
#define EXTI_Line9                      ((uint32_t)0x0000200)                   /*!< External interrupt line 9 */
#define EXTI_Line10                     ((uint32_t)0x0000400)                   /*!< External interrupt line 10 */
#define EXTI_Line11                     ((uint32_t)0x0000800)                   /*!< External interrupt line 11 */
#define EXTI_Line12                     ((uint32_t)0x0001000)                   /*!< External interrupt line 12 */
#define EXTI_Line13                     ((uint32_t)0x0002000)                   /*!< External interrupt line 13 */
#define EXTI_Line14                     ((uint32_t)0x0004000)                   /*!< External interrupt line 14 */
#define EXTI_Line15                     ((uint32_t)0x0008000)                   /*!< External interrupt line 15 */
#define EXTI_Line16                     ((uint32_t)0x0010000)                   /*!< External interrupt line 16 Connected to the PVD Output */
#define EXTI_Line17                     ((uint32_t)0x0020000)                   /*!< External interrupt line 17 Connected to the RTC Alarm event */
#define EXTI_Line18                     ((uint32_t)0x0040000)                   /*!< External interrupt line 18 Connected to the USB Wakeup from suspend event */
#define EXTI_Line19                     ((uint32_t)0x0080000)                   /*!< External interrupt line 19 */
#define EXTI_Line20                     ((uint32_t)0x0100000)                   /*!< External interrupt line 20 */
#define EXTI_Line21                     ((uint32_t)0x0200000)                   /*!< External interrupt line 21 */
#define EXTI_Line22                     ((uint32_t)0x0400000)                   /*!< External interrupt line 22 */
#define EXTI_Line23                     ((uint32_t)0x0800000)                   /*!< External interrupt line 23 */
#define EXTI_Line24                     ((uint32_t)0x1000000)                   /*!< External interrupt line 24 */

#define PVD_OUT_CONNECT_EXTI_LINE       EXTI_Line16                             /*!< PVD_OUT connect EXTI16 */
#define RTC_ALARM_EXTI_LINE             EXTI_Line17
#define USB_WAKEUP_EXTI_LINE            EXTI_Line18
#define COMP1_OUT_CONNECT_EXTI_LINE     EXTI_Line19                             /*!< COMP1_OUT connect EXTI19 */
#define COMP2_OUT_CONNECT_EXTI_LINE     EXTI_Line20
#define LPUART1_OUT_EXTI_LINE           EXTI_Line22
#define LPTIM1_OUT_EXTI_LINE            EXTI_Line23
#define IWDG_CONNECT_EXTI_LINE          EXTI_Line24                             /*!< IWDG connect EXTI24 */

#define EXTI_PortSourceGPIOA            (0x00U)
#define EXTI_PortSourceGPIOB            (0x01U)
#define EXTI_PortSourceGPIOC            (0x02U)
#define EXTI_PortSourceGPIOD            (0x03U)

#define EXTI_PinSource0                 (0x00U)
#define EXTI_PinSource1                 (0x01U)
#define EXTI_PinSource2                 (0x02U)
#define EXTI_PinSource3                 (0x03U)
#define EXTI_PinSource4                 (0x04U)
#define EXTI_PinSource5                 (0x05U)
#define EXTI_PinSource6                 (0x06U)
#define EXTI_PinSource7                 (0x07U)
#define EXTI_PinSource8                 (0x08U)
#define EXTI_PinSource9                 (0x09U)
#define EXTI_PinSource10                (0x0AU)
#define EXTI_PinSource11                (0x0BU)
#define EXTI_PinSource12                (0x0CU)
#define EXTI_PinSource13                (0x0DU)
#define EXTI_PinSource14                (0x0EU)
#define EXTI_PinSource15                (0x0FU)

#define EXTI_DMARemap_TIM17             EXTI_CFGR_TIM17DMA                      /*!< Remap TIM17 DMA requests from channel1 to channel2 */
#define EXTI_DMARemap_TIM16             EXTI_CFGR_TIM16DMA                      /*!< Remap TIM16 DMA requests from channel3 to channel4 */
#define EXTI_DMARemap_UART1Rx           EXTI_CFGR_UART1RXDMA                    /*!< Remap UART1 Rx DMA requests from channel3 to channel5 */
#define EXTI_DMARemap_UART1Tx           EXTI_CFGR_UART1TXDMA                    /*!< Remap UART1 Tx DMA requests from channel2 to channel4 */
#define EXTI_DMARemap_ADC1              EXTI_CFGR_ADCDMA                        /*!< Remap ADC1 DMA requests from channel1 to channel2 */
/**
  * @}
  */



/** @defgroup EXTI_Exported_Functions
  * @{
  */
FlagStatus EXTI_GetFlagStatus(uint32_t line);
ITStatus   EXTI_GetITStatus(uint32_t line);

void EXTI_DeInit(void);
void EXTI_Init(EXTI_InitTypeDef* init_struct);
void EXTI_StructInit(EXTI_InitTypeDef* init_struct);
void EXTI_GenerateSWInterrupt(uint32_t line);
void EXTI_ClearFlag(uint32_t line);
void EXTI_ClearITPendingBit(uint32_t line);
void exEXTI_LineDisable(uint32_t line);
uint32_t  exEXTI_GetAllFlagStatus(void);

void EXTI_MemoryRemapConfig(uint32_t memory_remap);
void EXTI_DMAChannelRemapConfig(uint32_t dma_remap, FunctionalState state);
void EXTI_LineConfig(uint8_t port_source_gpio, uint8_t pin_source);
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap);

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
#endif/* __HAL_EXTI_H --------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
