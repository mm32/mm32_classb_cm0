/***********************************************************************************************************************
    @file     SYSTEM_MM32SPIN0230.C
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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
  
  
/* Define to prevent recursive inclusion -------------------------------------*/
#define _SYSTEM_MM32_C_

/* Files includes ------------------------------------------------------------*/

/** @addtogroup CMSIS
  * @{
  */

#include "mm32_device.h"

/**
  * @}
  */


#define SYSCLK_HSI_XXMHz  60000000      // HSI 60MHz as Sysclk


#define RCC_CFGR_HPRE_DIV1              (0x00U << RCC_CFGR_HPRE_Pos) 
#define RCC_CFGR_HPRE_DIV2              (0x08U << RCC_CFGR_HPRE_Pos) 
#define RCC_CFGR_HPRE_DIV4              (0x09U << RCC_CFGR_HPRE_Pos) 
#define RCC_CFGR_HPRE_DIV8              (0x0AU << RCC_CFGR_HPRE_Pos) 
#define RCC_CFGR_HPRE_DIV16             (0x0BU << RCC_CFGR_HPRE_Pos) 

#define RCC_CFGR_PPRE1_DIV1             (0x00U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV2             (0x04U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV4             (0x05U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV8             (0x06U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV16            (0x07U << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_SW_HSI                 (0x00U << RCC_CFGR_SW_Pos)              
#define RCC_CFGR_SW_LSI                 (0x03U << RCC_CFGR_SW_Pos)    
     
uint32_t SystemCoreClock         = HSI_VALUE; 

/**
  * @brief  Configures the System clock frequency, HCLK and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
static void SetSysClockToDefine(void)
{
    __IO uint32_t  tn, tm,StartUpCounter = 0, ClkSrcStatus = 1;
    uint32_t temp = 0, i = 0;

    /* Enable HSI */  
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);
    /* Wait till HSI is ready and if Time out is reached exit */
    do 
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSIRDY_Msk;
        StartUpCounter++;
    } while ((ClkSrcStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));
  
    if ((RCC->CR & RCC_CR_HSIRDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }
    
    SystemCoreClock = SYSCLK_HSI_XXMHz;

    if (ClkSrcStatus == (uint32_t)0x01)
    {
        /* Enable Prefetch Buffer */
        FLASH->ACR |=  (0x01U << FLASH_ACR_PRFTBE_Pos);

        FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
        temp = (SystemCoreClock - 1) / 30000000;
        if(temp > 1)
        {
            temp = 1;
        }
        FLASH->ACR |= temp;

        /* HCLK = SYSCLK/4 */
        temp  = RCC->CFGR;
        temp &= ~RCC_CFGR_HPRE_Msk;
        temp |=  RCC_CFGR_HPRE_DIV4;
        RCC->CFGR =  temp;
        
        /* PCLK1 = HCLK */
        temp  = RCC->CFGR;
        temp &= ~RCC_CFGR_PPRE1_Msk;
        temp |=  RCC_CFGR_PPRE1_DIV1;
        RCC->CFGR =  temp;

        for(i=0; i<1000; i++)
        {
            __ASM("nop");
        }
        
        /* HCLK = SYSCLK/2 */
        temp  = RCC->CFGR;
        temp &= ~RCC_CFGR_HPRE_Msk;
        temp |=  RCC_CFGR_HPRE_DIV2;
        RCC->CFGR =  temp;

        for(i=0; i<1000; i++)
        {
            __ASM("nop");
            
        }

        /* HCLK = SYSCLK */
        temp  = RCC->CFGR;
        temp &= ~RCC_CFGR_HPRE_Msk;
        temp |=  RCC_CFGR_HPRE_DIV1;
        RCC->CFGR =  temp;

        for(i=0; i<1000; i++)
        {
            __ASM("nop");
        }
    }
    else
    {
        SystemCoreClock = HSI_VALUE;
    } 
}

/**
  * @brief  Setup the microcontroller system Initialize the Embedded Flash Interface, 
  *         the PLL and update the SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
    /* Reset the RCC clock configuration to the default reset state(for debug purpose) */

    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1 and MCO bits */
    RCC->CFGR = 0x000000A0;

    /* Disable all interrupts and clear pending bits */
    RCC->CIR = 0xFFFFFFFF;
    RCC->CIR = 0;

    /* Configure the System clock frequency, HCLK and PCLK1 prescalers */
    /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClockToDefine();

    *((uint32_t*)0x40022068) = 0x01;
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

