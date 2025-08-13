/*
 *******************************************************************************
    @file     system_mm32f0160.c
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

/** @addtogroup CMSIS
  * @{
  */
#include "mm32_device.h"

/**
  * @}
  */

/*
 *  Only one of SYSCLK_HSI_XXMHz and SYSCLK_HSE_XXMHz can be defined at a time.
 *  When HSI(HSI_VALUE =  8MHz) is used as the clock source, SYSCLK_HSI_XXMHz is used.
 *  When HSE(HSE_VALUE = 12MHz) is used as the clock source, SYSCLK_HSE_XXMHz is used.
 */

#define SYSCLK_HSI_XXMHz    96000000   /* default:96MHz, can be set as 48000000 or others */
// #define SYSCLK_HSI_XXMHz    48000000
// #define SYSCLK_HSI_XXMHz    36000000
// #define SYSCLK_HSI_XXMHz    24000000

// #define SYSCLK_HSE_XXMHz   96000000 /* default:96MHz, can be set as 48000000 or others */
// #define SYSCLK_HSE_XXMHz   48000000
// #define SYSCLK_HSE_XXMHz   36000000
// #define SYSCLK_HSE_XXMHz   24000000

/**
  * @}
  */
#define PLL_SOURCE_HSI         0
#define PLL_SOURCE_HSE         1
#define PLL_SOURCE_HSE_DIV_2   2

#define SYS_CLOCK_HSI          0
#define SYS_CLOCK_HSE          1
#define SYS_CLOCK_PLL          2
/*******************************************************************************
 *  Clock Definitions
 *******************************************************************************/
#if defined SYSCLK_HSE_XXMHz
#define SYSTEM_CLOCK           SYSCLK_HSE_XXMHz; /*!< System Clock Frequency (Core Clock) */
#define PLL_SOURCE             PLL_SOURCE_HSE
#define SYS_CLOCK_SRC          SYS_CLOCK_PLL
uint32_t    SystemCoreClock = SYSCLK_HSE_XXMHz;

#elif defined SYSCLK_HSI_XXMHz
#define SYSTEM_CLOCK           SYSCLK_HSI_XXMHz; /*!< System Clock Frequency (Core Clock) */
#define PLL_SOURCE             PLL_SOURCE_HSI
#define SYS_CLOCK_SRC          SYS_CLOCK_PLL
uint32_t    SystemCoreClock = SYSCLK_HSI_XXMHz;

#else /*!< HSI Selected as System Clock source */
uint32_t SystemCoreClock         = HSI_VALUE; /*!< System Clock Frequency (Core Clock) */

#endif

__I uint8_t AHBPrescTable[16] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9
};

/**
  * @}
  */

static void SetSysClock(void);

#if (defined SYSCLK_HSE_XXMHz) || (defined SYSCLK_HSI_XXMHz)
void SetSysClockToDefine(void);
#endif

/**
  * @}
  */

/**
  * @brief  use to return the pllm&plln.
  * @param  pllclkSourceFrq : PLL source clock frquency;
          pllclkFrq : Target PLL clock frquency;
          plln : PLL factor PLLN
          pllm : PLL factor PLLM
  * @retval amount of error
  */
uint32_t AutoCalPllFactor(uint32_t pllclkSourceFrq, uint32_t pllclkFrq, uint8_t *plln, uint8_t *pllm)
{
    uint32_t n, m;
    uint32_t tempFrq;
    uint32_t minDiff = pllclkFrq;
    uint8_t  flag    = 0;

    for (m = 0; m < 4; m++)
    {
        for (n = 0; n < 64; n++)
        {
            tempFrq = pllclkSourceFrq * (n + 1) / (m + 1);
            tempFrq = (tempFrq > pllclkFrq) ? (tempFrq - pllclkFrq) : (pllclkFrq - tempFrq);

            if (minDiff > tempFrq)
            {
                minDiff = tempFrq;
                *plln   = n;
                *pllm   = m;
            }

            if (minDiff == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag != 0)
        {
            break;
        }
    }

    return (minDiff);
}

/**
  * @}
  */

/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the
  *         SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
     /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
     /* Set HSION bit */
    RCC->CR |= RCC_CR_HSION;

     /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR &= ~RCC_CFGR_PPRE2;
    RCC->CFGR &= ~RCC_CFGR_MCO;

     /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= ~RCC_CR_HSEON;
    RCC->CR &= ~RCC_CR_CSSON;
    RCC->CR &= ~RCC_CR_PLL1ON;

     /* Reset HSEBYP bit */
    RCC->CR &= ~RCC_CR_HSEBYP;

     /* Reset PLLSRC, PLLXTPRE, PLLMUL */
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1SRC;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1PDIV;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1MUL;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1DIV;

     /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0xFFFFFFFF;
    RCC->CIR = 0;

     /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
     /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClock();
}

/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
static void SetSysClock(void)
{
#if (defined SYSCLK_HSE_XXMHz) || (defined SYSCLK_HSI_XXMHz)
    SetSysClockToDefine();
#endif

    /* If none of the define above is enabled, the HSI is used as System clock
       source (default after reset) */
}

#if (defined SYSCLK_HSE_XXMHz) || (defined SYSCLK_HSI_XXMHz)
/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the
  *         SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  pllclkSourceFrq:PLL source clock frquency;
          pllclkFrq:Target PLL clock frquency;
  * @retval None
  */
void SetSysClockToDefine(void)
{
    __IO uint32_t StartUpCounter = 0, ClkSrcStatus = 1;
    uint32_t temp;
    uint8_t plln, pllm, pllp;
    volatile uint32_t i;

#if ((SYS_CLOCK_SRC == SYS_CLOCK_PLL) && (PLL_SOURCE == PLL_SOURCE_HSE)) || (SYS_CLOCK_SRC == SYS_CLOCK_HSE)
    RCC->CR |= RCC_CR_HSEON;
    i = 5000;

    while (i--)
    {
    }

    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSERDY) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
        i = 5000;

        while (i--)
        {
        }
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }
#endif

    SystemCoreClock = SYSTEM_CLOCK;

    if (ClkSrcStatus == (uint32_t)0x01)
    {
         /* Config FLASH latency */
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        FLASH->ACR |= FLASH_ACR_PRFTBE;
        temp = (SystemCoreClock - 1) / 24000000;

        if (temp > 3)
        {
            temp = 3;
        }

        FLASH->ACR |= temp;

         /* Config pll clock */
#if (SYS_CLOCK_SRC == SYS_CLOCK_PLL)
        RCC->PLL1CFGR &= ~(RCC_PLL1CFGR_PLL1SRC | RCC_PLL1CFGR_PLL1XTPRE);
#if (PLL_SOURCE == PLL_SOURCE_HSI)
        temp = HSI_VALUE_PLL_ON;
        RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1SRC;
#elif (PLL_SOURCE == PLL_SOURCE_HSE)
        temp = HSE_VALUE;
        RCC->PLL1CFGR |= RCC_PLL1CFGR_PLL1SRC;
#elif (PLL_SOURCE == PLL_SOURCE_HSE_DIV_2)
        temp = HSE_VALUE / 2;
        RCC->PLL1CFGR |= RCC_PLL1CFGR_PLL1XTPRE;
#endif

        pllp = 1;
        AutoCalPllFactor(temp, SystemCoreClock * 2, &plln, &pllm);

        RCC->PLL1CFGR &= ~(RCC_PLL1CFGR_PLL1PDIV | RCC_PLL1CFGR_PLL1MUL | RCC_PLL1CFGR_PLL1DIV);
        RCC->PLL1CFGR |= ((pllm << RCC_PLL1CFGR_PLL1PDIV_Pos) | (plln << RCC_PLL1CFGR_PLL1MUL_Pos) | (pllp << RCC_PLL1CFGR_PLL1DIV_Pos));

        RCC->PLL1CFGR |= ((0x02 << RCC_PLL1CFGR_PLL1_LDS_Pos) | (0x03 << RCC_PLL1CFGR_PLL1_ICTRL_Pos));

        RCC->CR |= RCC_CR_PLL1ON;

        while ((RCC->CR & RCC_CR_PLL1RDY) == 0)
        {
            __ASM("nop");              /* __NOP(); */
        }

         /* select system clock */
        RCC->CFGR &= ~RCC_CFGR_SW;
        RCC->CFGR |= RCC_CFGR_SW_PLL1;

        while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL1)
        {
            __ASM("nop");              /* __NOP(); */
        }
#endif

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

         /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

         /* HCLK = SYSCLK/2 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV2;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

         /* HCLK = SYSCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV1;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
    }
    else
    {
        /* If HSE not ready within the given time, the program will stop here.
           User can add here some code to deal with this error */
        while (1)
        {
            /* please check Whether the crystal oscillator starts*/
        }
    }
}

#endif
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/*-------------------------(C) COPYRIGHT 2021 MindMotion ----------------------*/

