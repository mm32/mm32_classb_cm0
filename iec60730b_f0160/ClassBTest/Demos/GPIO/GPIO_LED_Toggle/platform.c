/***********************************************************************************************************************
    @file    platform.c
    @author  FAE Team
    @date    23-Aug-2023
    @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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

/* Define to prevent recursive inclusion */
#define _PLATFORM_C_

/* Files include */
#include <stdio.h>
#include "platform.h"

/**
  * @addtogroup MM32F0160_LibSamples
  * @{
  */

/**
  * @addtogroup GPIO
  * @{
  */

/**
  * @addtogroup GPIO_LED_Toggle
  * @{
  */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/

/***********************************************************************************************************************
  * @brief  Initialize SysTick for delay function
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_InitDelay(void)
{
    RCC_ClocksTypeDef RCC_Clocks;

    RCC_GetClocksFreq(&RCC_Clocks);

    if (SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000))
    {
        while (1)
        {
        }
    }

    NVIC_SetPriority(SysTick_IRQn, 0x0);
}

/***********************************************************************************************************************
  * @brief  Millisecond delay
  * @note   none
  * @param  Millisecond: delay time unit
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_DelayMS(uint32_t Millisecond)
{
    PLATFORM_DelayTick = Millisecond;

    while (0 != PLATFORM_DelayTick)
    {
    }
}

/***********************************************************************************************************************
  * @brief  Initialize console for printf
  * @note   none
  * @param  Baudrate : UART2 communication baudrate
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_InitConsole(uint32_t Baudrate)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    UART_InitTypeDef UART_InitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1ENR_UART2, ENABLE);

    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.BaudRate      = Baudrate;
    UART_InitStruct.WordLength    = UART_WordLength_8b;
    UART_InitStruct.StopBits      = UART_StopBits_1;
    UART_InitStruct.Parity        = UART_Parity_No;
    UART_InitStruct.HWFlowControl = UART_HWFlowControl_None;
    UART_InitStruct.Mode          = UART_Mode_Tx;
    UART_Init(UART2, &UART_InitStruct);

    UART_Cmd(UART2, ENABLE);

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

#if   defined (__ICCARM__)

#if   (__VER__ >= 9030001)

/* Files include */
#include <stddef.h>
#include <LowLevelIOInterface.h>

/***********************************************************************************************************************
  * @brief  redefine __write function
  * @note   for printf
  * @param  handle
  * @param  *buf
  * @param  bufSize
  * @retval nChars
  *********************************************************************************************************************/
size_t __write(int handle, const unsigned char *buf, size_t bufSize)
{
    size_t nChars = 0;

    /* Check for the command to flush all handles */
    if (-1 == handle)
    {
        return (0);
    }

    /* Check for stdout and stderr (only necessary if FILE descriptors are enabled.) */
    if ((_LLIO_STDOUT != handle) && (_LLIO_STDERR != handle))
    {
        return (-1);
    }

    for (/* Empty */; bufSize > 0; --bufSize)
    {
        UART_SendData(UART2, *buf);

        while (RESET == UART_GetFlagStatus(UART2, UART_FLAG_TXEPT))
        {
        }

        ++buf;
        ++nChars;
    }

    return (nChars);
}

#else

/***********************************************************************************************************************
  * @brief  redefine putchar function
  * @note   for printf
  * @param  ch
  * @param  f
  * @retval ch
  *********************************************************************************************************************/
int putchar(int ch)
{
    UART_SendData(UART2, (uint8_t)ch);

    while (RESET == UART_GetFlagStatus(UART2, UART_FLAG_TXEPT))
    {
    }

    return (ch);
}

#endif

#elif (defined (__GNUC__) || defined (__CC_ARM))

/***********************************************************************************************************************
  * @brief  redefine fputc function
  * @note   for printf
  * @param  ch
  * @param  f
  * @retval ch
  *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
    UART_SendData(UART2, (uint8_t)ch);

    while (RESET == UART_GetFlagStatus(UART2, UART_FLAG_TXEPT))
    {
    }

    return (ch);
}
#endif

/***********************************************************************************************************************
  * @brief  Initialize LED GPIO pin
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_InitLED(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOC, ENABLE);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    PLATFORM_LED_Enable(LED1, ENABLE);
    PLATFORM_LED_Enable(LED2, ENABLE);
    PLATFORM_LED_Enable(LED3, ENABLE);
    PLATFORM_LED_Enable(LED4, ENABLE);
}

/***********************************************************************************************************************
  * @brief  LED on or off
  * @note   none
  * @param  LEDn : LED index
  * @arg    LED1, LED2, LED3, LED4
  * @param  State
  * @arg    ENABLE, DISABLE
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_LED_Enable(LEDn_TypeDef LEDn, FunctionalState State)
{
    switch (LEDn)
    {
        case LED1:
            GPIO_WriteBit(GPIOC, GPIO_Pin_9, (ENABLE == State) ? Bit_RESET : Bit_SET);
            break;

        case LED2:
            GPIO_WriteBit(GPIOC, GPIO_Pin_8, (ENABLE == State) ? Bit_RESET : Bit_SET);
            break;

        case LED3:
            GPIO_WriteBit(GPIOC, GPIO_Pin_7, (ENABLE == State) ? Bit_RESET : Bit_SET);
            break;

        case LED4:
            GPIO_WriteBit(GPIOC, GPIO_Pin_6, (ENABLE == State) ? Bit_RESET : Bit_SET);
            break;

        default:
            break;
    }
}

/***********************************************************************************************************************
  * @brief  LED toggle display
  * @note   none
  * @param  LEDn : LED index
  * @arg    LED1, LED2, LED3, LED4
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_LED_Toggle(LEDn_TypeDef LEDn)
{
    switch (LEDn)
    {
        case LED1:
            GPIO_WriteBit(GPIOC, GPIO_Pin_9, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_9) ? Bit_RESET : Bit_SET);
            break;

        case LED2:
            GPIO_WriteBit(GPIOC, GPIO_Pin_8, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_8) ? Bit_RESET : Bit_SET);
            break;

        case LED3:
            GPIO_WriteBit(GPIOC, GPIO_Pin_7, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_7) ? Bit_RESET : Bit_SET);
            break;

        case LED4:
            GPIO_WriteBit(GPIOC, GPIO_Pin_6, GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_6) ? Bit_RESET : Bit_SET);
            break;

        default:
            break;
    }
}

/***********************************************************************************************************************
  * @brief  Print information
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_PrintInfo(void)
{
    RCC_ClocksTypeDef RCC_Clocks;

    printf("\r\nBOARD : Mini-F0163");
    printf("\r\nMCU : MM32F0163D7P");

    printf("\r\n");

    switch (RCC->CFGR & RCC_CFGR_SWS)
    {
        case 0x00:
            printf("\r\nHSI used as system clock source");
            break;

        case 0x04:
            printf("\r\nHSE used as system clock source");
            break;

        case 0x08:
            if (RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1SRC)
            {
                printf("\r\nPLL1 (clocked by HSE) used as system clock source");
            }
            else
            {
                printf("\r\nPLL1 (clocked by HSI) used as system clock source");
            }

            break;

        case 0x0C:
            printf("\r\nLSI used as system clock source");
            break;

        default:
            break;
    }

    RCC_GetClocksFreq(&RCC_Clocks);

    printf("\r\n");
    printf("\r\nSYSCLK Frequency : %7.3f MHz", (double)RCC_Clocks.SYSCLK_Frequency / (double)1000000.0);
    printf("\r\nHCLK   Frequency : %7.3f MHz", (double)RCC_Clocks.HCLK_Frequency   / (double)1000000.0);
    printf("\r\nPCLK1  Frequency : %7.3f MHz", (double)RCC_Clocks.PCLK1_Frequency  / (double)1000000.0);
    printf("\r\nPCLK2  Frequency : %7.3f MHz", (double)RCC_Clocks.PCLK2_Frequency  / (double)1000000.0);
    printf("\r\n");
}

/***********************************************************************************************************************
  * @brief  Initialize Platform
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_Init(void)
{
    PLATFORM_InitDelay();

    PLATFORM_InitConsole(115200);

    PLATFORM_InitLED();

    PLATFORM_PrintInfo();
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

/********************************************** (C) Copyright MindMotion **********************************************/

