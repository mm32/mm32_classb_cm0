/*
 *******************************************************************************
    @file     hal_rcc.c
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

/* Includes ------------------------------------------------------------------*/
#include "hal_rcc.h"

/** @addtogroup StdPeriph_Driver
  * @{
  */

/** @defgroup RCC
  * @brief RCC driver modules
  * @{
  */

/** @defgroup RCC_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Private_Defines
  * @{
  */

/* ------------ RCC registers bit address in the alias region ----------- */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)

/* --- CR Register ---*/

/* Alias word address of HSION bit */
#define CR_OFFSET                 (RCC_OFFSET + 0x00)
#define HSION_BitNumber           0x00
#define CR_HSION_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (HSION_BitNumber * 4))

/* Alias word address of PLLON bit */
#define PLLON_BitNumber           0x18
#define CR_PLLON_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (PLLON_BitNumber * 4))

/* Alias word address of CSSON bit */
#define CSSON_BitNumber           0x13
#define CR_CSSON_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (CSSON_BitNumber * 4))

/* --- CFGR Register ---*/

/* Alias word address of USBPRE bit */
#define CFGR_OFFSET               (RCC_OFFSET + 0x04)
#define USBPRE_BitNumber          0x16
#define CFGR_USBPRE_BB            (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (USBPRE_BitNumber * 4))

/* --- BDCR Register ---*/

/* Alias word address of RTCEN bit */
#define BDCR_OFFSET               (RCC_OFFSET + 0x20)
#define RTCEN_BitNumber           0x0F
#define BDCR_RTCEN_BB             (PERIPH_BB_BASE + (BDCR_OFFSET * 32) + (RTCEN_BitNumber * 4))

/* Alias word address of BDRST bit */
#define BDRST_BitNumber           0x10
#define BDCR_BDRST_BB             (PERIPH_BB_BASE + (BDCR_OFFSET * 32) + (BDRST_BitNumber * 4))

/* --- CSR Register ---*/

/* Alias word address of LSION bit */
#define CSR_OFFSET                (RCC_OFFSET + 0x24)
#define LSION_BitNumber           0x00
#define CSR_LSION_BB              (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (LSION_BitNumber * 4))

/* ---------------------- RCC registers bit mask ------------------------ */

/* CR register bit mask */
#define CR_HSEBYP_Reset           ((uint32_t)0xFFFBFFFF)
#define CR_HSEBYP_Set             ((uint32_t)0x00040000)
#define CR_HSEON_Reset            ((uint32_t)0xFFFEFFFF)
#define CR_HSEON_Set              ((uint32_t)0x00010000)
#define CR_HSITRIM_Mask           ((uint32_t)0xFFFFFF07)

/* CFGR register bit mask */
#define CFGR_PLL_Mask             ((uint32_t)0xFFC0FFFF)
#define CFGR_PLLMull_Mask         ((uint32_t)0x003C0000)
#define CFGR_PLLSRC_Mask          ((uint32_t)0x00010000)
#define CFGR_PLLXTPRE_Mask        ((uint32_t)0x00020000)
#define CFGR_SWS_Mask             ((uint32_t)0x0000000C)
#define CFGR_SW_Mask              ((uint32_t)0xFFFFFFFC)
#define CFGR_HPRE_Reset_Mask      ((uint32_t)0xFFFFFF0F)
#define CFGR_HPRE_Set_Mask        ((uint32_t)0x000000F0)
#define CFGR_PPRE1_Reset_Mask     ((uint32_t)0xFFFFF8FF)
#define CFGR_PPRE1_Set_Mask       ((uint32_t)0x00000700)
#define CFGR_PPRE2_Reset_Mask     ((uint32_t)0xFFFFC7FF)
#define CFGR_PPRE2_Set_Mask       ((uint32_t)0x00003800)
#define CFGR_ADCPRE_Reset_Mask    ((uint32_t)0xFFFF3FFF)
#define CFGR_ADCPRE_Set_Mask      ((uint32_t)0x0000C000)

/* CSR register bit mask */
#define CSR_RMVF_Set              ((uint32_t)0x01000000)

/* RCC Flag Mask */
#define RCC_FLAG_Mask                 ((uint8_t)0x1F)

/* Typical Value of the HSI in Hz */
#define HSI_Value                 ((uint32_t)8000000)

/* CIR register byte 2 (Bits[15:8]) base address */
#define CIR_BYTE2_ADDRESS         ((uint32_t)0x40021009)

/* CIR register byte 3 (Bits[23:16]) base address */
#define CIR_BYTE3_ADDRESS         ((uint32_t)0x4002100A)

/* CFGR register byte 4 (Bits[31:24]) base address */
#define CFGR_BYTE4_ADDRESS        ((uint32_t)0x40021007)

/* BDCR register base address */
#define BDCR_ADDRESS              (PERIPH_BASE + BDCR_OFFSET)

#ifndef HSEStartUp_TimeOut
/* Time out for HSE start up */
#define HSEStartUp_TimeOut        ((uint16_t)0x0500)
#endif

/**
  * @}
  */

/** @defgroup RCC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Private_Variables
  * @{
  */

static __I uint8_t APBAHBPrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};
static __I uint8_t ADCPrescTable[4] = {2, 4, 6, 8};
uint8_t tbPresc[] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};
/**
  * @}
  */

/** @defgroup RCC_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Private_Functions
  * @{
  */

/**
  * @brief  Resets the RCC clock configuration to the default reset state.
  * @param  None
  * @retval : None
  */
void RCC_DeInit(void)
{
    /* Set HSION bit */
    RCC->CR |= (uint32_t)0x00000001;
    /* Reset SW[1:0], HPRE[3:0], PPRE1[2:0], PPRE2[2:0], ADCPRE[1:0] and MCO[2:0] bits */
    RCC->CFGR &= (uint32_t)0xF8FF0000;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= (uint32_t)0xFEF6FFFF;
    /* Reset HSEBYP bit */
    RCC->CR &= (uint32_t)0xFFFBFFFF;
    /* Reset PLLSRC, PLLXTPRE, PLLMUL[3:0] and USBPRE bits */
    RCC->CFGR &= (uint32_t)0xFF80FFFF;
    /* Disable all interrupts */
    RCC->CIR = 0x00000000;
}

/**
  * @brief  Configures the External High Speed oscillator (HSE).
  *   HSE can not be stopped if it is used directly or through the
  *   PLL as system clock.
  * @param RCC_HSE: specifies the new state of the HSE.
  *   This parameter can be one of the following values:
  * @arg RCC_HSE_OFF: HSE oscillator OFF
  * @arg RCC_HSE_ON: HSE oscillator ON
  * @arg RCC_HSE_Bypass: HSE oscillator bypassed with external
  *   clock
  * @retval : None
  */
void RCC_HSEConfig(uint32_t RCC_HSE)
{

    /* Reset HSEON and HSEBYP bits before configuring the HSE ------------------*/
    /* Reset HSEON bit */
    RCC->CR &= CR_HSEON_Reset;
    /* Reset HSEBYP bit */
    RCC->CR &= CR_HSEBYP_Reset;
    /* Configure HSE (RCC_HSE_OFF is already covered by the code section above) */
    switch(RCC_HSE)
    {
    case RCC_HSE_ON:
        /* Set HSEON bit */
        RCC->CR |= CR_HSEON_Set;
        break;

    case RCC_HSE_Bypass:
        /* Set HSEBYP and HSEON bits */
        RCC->CR |= CR_HSEBYP_Set | CR_HSEON_Set;
        break;

    default:
        break;
    }
}

/**
  * @brief  Waits for HSE start-up.
  * @param  None
  * @retval : An ErrorStatus enumuration value:
  * - SUCCESS: HSE oscillator is stable and ready to use
  * - ERROR: HSE oscillator not yet ready
  */
ErrorStatus RCC_WaitForHSEStartUp(void)
{
    __IO uint32_t StartUpCounter = 0;
    ErrorStatus status = ERROR;
    FlagStatus HSEStatus = RESET;

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC_GetFlagStatus(RCC_FLAG_HSERDY);
        StartUpCounter++;
    } while((HSEStatus == RESET) && (StartUpCounter != HSEStartUp_TimeOut));
    if (RCC_GetFlagStatus(RCC_FLAG_HSERDY) != RESET)
    {
        status = SUCCESS;
    }
    else
    {
        status = ERROR;
    }
    return (status);
}

/**
  * @brief  Adjusts the Internal High Speed oscillator (HSI) calibration
  *   value.
  * @param HSICalibrationValue: specifies the calibration trimming value.
  *   This parameter must be a number between 0 and 0x1F.
  * @retval : None
  */
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->CR;
    /* Clear HSITRIM[4:0] bits */
    tmpreg &= CR_HSITRIM_Mask;
    /* Set the HSITRIM[4:0] bits according to HSICalibrationValue value */
    tmpreg |= (uint32_t)HSICalibrationValue << 3;
    /* Store the new value */
    RCC->CR = tmpreg;
}

/**
  * @brief  Enables or disables the Internal High Speed oscillator (HSI).
  *   HSI can not be stopped if it is used directly or through the
  *   PLL as system clock.
  * @param NewState: new state of the HSI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_HSICmd(FunctionalState NewState)
{

    if(NewState==ENABLE)
    {
        RCC->CR |= 0x01;
    }
    else
    {
        RCC->CR &= 0xfffffffe;
    }
}
/**
  * @brief  Configures the PLL clock source and DM DN factor.
  *   This function must be used only when the PLL is disabled.
  * @param RCC_PLLSource: specifies the PLL entry clock source.
  *   This parameter can be one of the following values:
  * @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected
  *   as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @param RCC_PLLDN: specifies the PLL multiplication factor.
  *   This parameter can be RCC_PLLMul_x where x:[31:26]
  * @param RCC_PLLDM: specifies the PLL Divsior factor.
  *   This parameter can be RCC_Divsior_x where x:[22:20]
  * @retval : None
  */
void RCC_PLL1DMDNConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLDN, uint32_t RCC_PLLDM, uint32_t RCC_PLLDP)
{
    uint32_t tmpreg0 = 0;
    /* uint32_t RCC_PLLDP = 0; */ /* 0-7 */

    tmpreg0 = RCC->PLL1CFGR;

    tmpreg0 &= 0x1f00f8ff;

    /* Set the PLL configuration bits */
    tmpreg0 |= (RCC_PLLDN<<16)|(RCC_PLLDM<<29)|(RCC_PLLDP<<8);

    RCC->PLL1CFGR = tmpreg0;
}

/**
  * @brief  Configures the PLL clock source and DM DN factor.
  *   This function must be used only when the PLL is disabled.
  * @param RCC_PLLSource: specifies the PLL entry clock source.
  *   This parameter can be one of the following values:
  * @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected
  *   as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @param RCC_PLLDN: specifies the PLL multiplication factor.
  *   This parameter can be RCC_PLLMul_x where x:[31:26]
  * @param RCC_PLLDM: specifies the PLL Divsior factor.
  *   This parameter can be RCC_Divsior_x where x:[22:20]
  * @retval : None
  */
void RCC_PLL2DMDNConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLDN, uint32_t RCC_PLLDM, uint32_t RCC_PLLDP)
{
    uint32_t tmpreg0 = 0;
    /* uint32_t RCC_PLLDP = 0; */ /* 0-7 */

    tmpreg0 = RCC->PLL2CFGR;

    tmpreg0 &= 0x1f00f8ff;

    /* Set the PLL configuration bits */
    tmpreg0 |= (RCC_PLLDN<<16)|(RCC_PLLDM<<29)|(RCC_PLLDP<<8);

    RCC->PLL2CFGR = tmpreg0;
}

/**
  * @brief  Configures the PLL clock source and multiplication factor.
  *   This function must be used only when the PLL is disabled.
  * @param RCC_PLLSource: specifies the PLL entry clock source.
  *   This parameter can be one of the following values:
  * @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected
  *   as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @param RCC_PLLDN: specifies the PLL multiplication factor.
  *   This parameter can be RCC_PLLMul_x where x:[31:26][22:20]
  * @retval : None
  */
void RCC_PLL1Config(uint32_t RCC_PLLSource, uint32_t RCC_PLLDN, uint32_t RCC_PLLDM, uint32_t RCC_PLLDP)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->PLL1CFGR;
    /* Clear PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
    tmpreg &= (~3);/* tmpreg &= CFGR_PLL_Mask; */
    /* Set the PLL configuration bits */
    tmpreg |= RCC_PLLSource;
    /* Store the new value */
    RCC->PLL1CFGR = tmpreg;

    RCC_PLL1DMDNConfig(RCC_PLLSource, RCC_PLLDN, RCC_PLLDM, RCC_PLLDP);
}

/**
  * @brief  Configures the PLL clock source and multiplication factor.
  *   This function must be used only when the PLL is disabled.
  * @param RCC_PLLSource: specifies the PLL entry clock source.
  *   This parameter can be one of the following values:
  * @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected
  *   as PLL clock entry
  * @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided
  *   by 2 selected as PLL clock entry
  * @param RCC_PLLDN: specifies the PLL multiplication factor.
  *   This parameter can be RCC_PLLMul_x where x:[31:26][22:20]
  * @retval : None
  */
void RCC_PLL2Config(uint32_t RCC_PLLSource, uint32_t RCC_PLLDN, uint32_t RCC_PLLDM, uint32_t RCC_PLLDP)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->PLL2CFGR;
    /* Clear PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
    tmpreg &= (~3);/* tmpreg &= CFGR_PLL_Mask; */
    /* Set the PLL configuration bits */
    tmpreg |= RCC_PLLSource;
    /* Store the new value */
    RCC->PLL2CFGR = tmpreg;

    RCC_PLL2DMDNConfig(RCC_PLLSource, RCC_PLLDN, RCC_PLLDM, RCC_PLLDP);

}
/**
  * @brief  Enables or disables the PLL.
  *   The PLL can not be disabled if it is used as system clock.
  * @param NewState: new state of the PLL.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_PLL1Cmd(FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->CR |= 0x01000000;
    }
    else
    {
        RCC->CR &= 0xfeffffff;
    }
}

/**
  * @brief  Enables or disables the PLL.
  *   The PLL can not be disabled if it is used as system clock.
  * @param NewState: new state of the PLL.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_PLL2Cmd(FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->CR |= 0x10000000;
    }
    else
    {
        RCC->CR &= 0xefffffff;
    }
}
/**
  * @brief  Configures the system clock (SYSCLK).
  * @param RCC_SYSCLKSource: specifies the clock source used as system
  *   clock. This parameter can be one of the following values:
  * @arg RCC_SYSCLKSource_HSI: HSI selected as system clock
  * @arg RCC_SYSCLKSource_HSE: HSE selected as system clock
  * @arg RCC_SYSCLKSource_PLLCLK: PLL selected as system clock
  * @retval : None
  */
void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->CFGR;
    /* Clear SW[1:0] bits */
    tmpreg &= CFGR_SW_Mask;
    /* Set SW[1:0] bits according to RCC_SYSCLKSource value */
    tmpreg |= RCC_SYSCLKSource;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None
  * @retval : The clock source used as system clock. The returned value can
  *   be one of the following:
  * - 0x00: HSI/6 used as system clock
  * - 0x04: HSE used as system clock
  * - 0x08: PLL used as system clock
  */
uint8_t RCC_GetSYSCLKSource(void)
{
    return ((uint8_t)(RCC->CFGR & CFGR_SWS_Mask));
}

/**
  * @brief  Configures the AHB clock (HCLK).
  * @param RCC_SYSCLK: defines the AHB clock divider. This clock is derived from
  *                    the system clock (SYSCLK).
  *   This parameter can be one of the following values:
  * @arg RCC_SYSCLK_Div1: AHB clock = SYSCLK
  * @arg RCC_SYSCLK_Div2: AHB clock = SYSCLK/2
  * @arg RCC_SYSCLK_Div4: AHB clock = SYSCLK/4
  * @arg RCC_SYSCLK_Div8: AHB clock = SYSCLK/8
  * @arg RCC_SYSCLK_Div16: AHB clock = SYSCLK/16
  * @arg RCC_SYSCLK_Div64: AHB clock = SYSCLK/64
  * @arg RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
  * @arg RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
  * @arg RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
  * @retval : None
  */
void RCC_HCLKConfig(uint32_t RCC_SYSCLK)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->CFGR;
    /* Clear HPRE[3:0] bits */
    tmpreg &= CFGR_HPRE_Reset_Mask;
    /* Set HPRE[3:0] bits according to RCC_SYSCLK value */
    tmpreg |= RCC_SYSCLK;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the Low Speed APB clock (PCLK1).
  * @param RCC_HCLK: defines the APB1 clock divider. This clock is derived from
  *                  the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  * @arg RCC_HCLK_Div1: APB1 clock = HCLK
  * @arg RCC_HCLK_Div2: APB1 clock = HCLK/2
  * @arg RCC_HCLK_Div4: APB1 clock = HCLK/4
  * @arg RCC_HCLK_Div8: APB1 clock = HCLK/8
  * @arg RCC_HCLK_Div16: APB1 clock = HCLK/16
  * @retval : None
  */
void RCC_PCLK1Config(uint32_t RCC_HCLK)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->CFGR;
    /* Clear PPRE1[2:0] bits */
    tmpreg &= CFGR_PPRE1_Reset_Mask;
    /* Set PPRE1[2:0] bits according to RCC_HCLK value */
    tmpreg |= RCC_HCLK;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the High Speed APB clock (PCLK2).
  * @param RCC_HCLK: defines the APB2 clock divider. This clock is derived from
  *                  the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  * @arg RCC_HCLK_Div1: APB2 clock = HCLK
  * @arg RCC_HCLK_Div2: APB2 clock = HCLK/2
  * @arg RCC_HCLK_Div4: APB2 clock = HCLK/4
  * @arg RCC_HCLK_Div8: APB2 clock = HCLK/8
  * @arg RCC_HCLK_Div16: APB2 clock = HCLK/16
  * @retval : None
  */
void RCC_PCLK2Config(uint32_t RCC_HCLK)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->CFGR;
    /* Clear PPRE2[2:0] bits */
    tmpreg &= CFGR_PPRE2_Reset_Mask;
    /* Set PPRE2[2:0] bits according to RCC_HCLK value */
    tmpreg |= RCC_HCLK << 3;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Enables or disables the specified RCC interrupts.
  * @param RCC_IT: specifies the RCC interrupt sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_PLLRDY: PLL ready interrupt
  * @param NewState: new state of the specified RCC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        /* Perform Byte access to RCC_CIR[12:8] bits to enable the selected interrupts */

        RCC->CIR |= ((uint32_t)RCC_IT)<<8;
    }
    else
    {
        /* Perform Byte access to RCC_CIR[12:8] bits to disable the selected interrupts */

        RCC->CIR &= ~((uint32_t)RCC_IT<<8);
    }
}

/**
  * @brief  Configures the USB clock (USBCLK).
  * @param RCC_USBCLKSource: specifies the USB clock source. This clock is
  *                          derived from the PLL output.
  *   This parameter can be one of the following values:
  * @arg RCC_USBCLKSource_PLLCLK_1Div5: PLL clock divided by 1,5 selected as USB
  *                                     clock source
  * @arg RCC_USBCLKSource_PLLCLK_Div1: PLL clock selected as USB clock source
  * @retval : None
  */
void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource)
{

    RCC->CFGR |= RCC_USBCLKSource;
}

/**
  * @brief  Configures the ADC clock (ADCCLK).
  * @param RCC_PCLK2: defines the ADC clock divider. This clock is derived from
  *                   the APB2 clock (PCLK2).
  *   This parameter can be one of the following values:
  * @arg RCC_PCLK2_Div2: ADC clock = PCLK2/2
  * @arg RCC_PCLK2_Div4: ADC clock = PCLK2/4
  * @arg RCC_PCLK2_Div6: ADC clock = PCLK2/6
  * @arg RCC_PCLK2_Div8: ADC clock = PCLK2/8
  * @retval : None
  */
void RCC_ADCCLKConfig(uint32_t RCC_PCLK2)
{
    uint32_t tmpreg = 0;

    tmpreg = RCC->CFGR;
    /* Clear ADCPRE[1:0] bits */
    tmpreg &= CFGR_ADCPRE_Reset_Mask;
    /* Set ADCPRE[1:0] bits according to RCC_PCLK2 value */
    tmpreg |= RCC_PCLK2;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the External Low Speed oscillator (LSE).
  * @param RCC_LSE: specifies the new state of the LSE.
  *   This parameter can be one of the following values:
  * @arg RCC_LSE_OFF: LSE oscillator OFF
  * @arg RCC_LSE_ON: LSE oscillator ON
  * @arg RCC_LSE_Bypass: LSE oscillator bypassed with external
  *   clock
  * @retval : None
  */
void RCC_LSEConfig(uint32_t rcc_lse)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    tmpreg &= ~RCC_BDCR_LSEON_Msk;

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }    

    tmpreg &= ~RCC_BDCR_LSEBYP_Msk;

    if (rcc_lse == RCC_LSE_Bypass)
    {
        tmpreg |= RCC_LSE_Bypass;
        tmpreg |= RCC_LSE_ON;
    }
    else
    {
        tmpreg |= rcc_lse;
    }

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the Internal Low Speed oscillator (LSI).
  *   LSI can not be disabled if the IWDG is running.
  * @param NewState: new state of the LSI.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_LSICmd(FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->CSR |= 0x00000021;
    }
    else
    {
        RCC->CSR &= 0xffffffce;
    }
}

/**
  * @brief  Configures the RTC clock (RTCCLK).
  *   Once the RTC clock is selected it can be changed unless the
  *   Backup domain is reset.
  * @param RCC_RTCCLKSource: specifies the RTC clock source.
  *   This parameter can be one of the following values:
  * @arg RCC_RTCCLKSource_LSE: LSE selected as RTC clock
  * @arg RCC_RTCCLKSource_LSI: LSI selected as RTC clock
  * @arg RCC_RTCCLKSource_HSE_Div128: HSE clock divided by 128
  *   selected as RTC clock
  * @retval : None
  */
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource)
{
    RCC_ClocksTypeDef clk;
    uint16_t factor = 0;
    uint32_t temp = 0;
    uint8_t i = 0;

    RCC_GetClocksFreq(&clk);
    factor = clk.SYSCLK_Frequency / clk.PCLK1_Frequency;

    temp = RCC->BDCR;
    for(i=0; i<3*factor; i++)
    {
        __NOP();
    }

    /* Select the RTC clock source */
    temp |= RCC_RTCCLKSource;

    RCC->BDCR = temp;
    for(i=0; i<3*factor; i++)
    {
        __NOP();
    }

}

/**
  * @brief  Enables or disables the RTC clock.
  *   This function must be used only after the RTC clock was
  *   selected using the RCC_RTCCLKConfig function.
  * @param NewState: new state of the RTC clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_RTCCLKCmd(FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->BDCR |= 0x00008000;
    }
    else
    {
        RCC->BDCR &= 0xffff7fff;
    }
}

/**
  * @brief  Returns the clock frequency of different on chip clocks.
  * @param  None.
  * @retval sys_clk : System clock frequency
  */
uint32_t RCC_GetSysClockFreq(void)
{
    uint32_t result;
    uint32_t clock, mul, div;
    switch (RCC->CFGR & RCC_CFGR_SWS) {

        case RCC_CFGR_SWS_HSE:
            result = HSE_VALUE;
            break;

        case RCC_CFGR_SWS_PLL1:
            clock = READ_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1SRC) ? (READ_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1XTPRE) ? (HSE_VALUE >> 1) : HSE_VALUE)
                    : HSI_VALUE_PLL_ON;
            mul = ((RCC->PLL1CFGR & (uint32_t)RCC_PLL1CFGR_PLL1MUL) >> RCC_PLL1CFGR_PLL1MUL_Pos) + 1;
            div = ((RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1DIV) >> RCC_PLL1CFGR_PLL1DIV_Pos) + 1;

            result = clock * mul / div;
            break;
        default:
            result =  HSI_VALUE;
            break;
    }
    return result;
}

/**
  * @brief  Returns the hclk frequency of different on chip clocks.
  * @param  None.
  * @retval hclk frequency
  */
uint32_t RCC_GetHCLKFreq(void)
{
    return (RCC_GetSysClockFreq() >> tbPresc[(RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos]);
}

/**
  * @brief  Returns the pclk1 frequency of different on chip clocks.
  * @param  None.
  * @retval pclk1 frequency
  */
uint32_t RCC_GetPCLK1Freq(void)
{
    return (RCC_GetHCLKFreq() >> tbPresc[(RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos]);
}

/**
  * @brief  Returns the pclk2 frequency of different on chip clocks.
  * @param  None.
  * @retval pclk2 frequency
  */
uint32_t RCC_GetPCLK2Freq(void)
{
    return (RCC_GetHCLKFreq() >> tbPresc[(RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos]);
}


/**
  * @brief  Returns the frequency of different on chip clocks.
  * @param  clk: pointer to a RCC_ClocksTypeDef structure which
  *   will hold the clocks frequency.
  * @retval None.
  */
void RCC_GetClocksFreq(RCC_ClocksTypeDef* clk)
{
    uint8_t tbADCPresc[] = {2, 4, 6, 8};

    clk->SYSCLK_Frequency = RCC_GetSysClockFreq();
    clk->HCLK_Frequency   = RCC_GetHCLKFreq();
    clk->PCLK1_Frequency  = RCC_GetPCLK1Freq();
    clk->PCLK2_Frequency  = RCC_GetPCLK2Freq();

    clk->ADCCLK_Frequency = clk->PCLK2_Frequency / tbADCPresc[(RCC->CFGR & ADC_ADCFG_ADCPRE) >> ADC_ADCFG_ADCPREL_Pos];

}

/**
  * @brief  Enables or disables the AHB peripheral clock.
  * @param RCC_AHBPeriph: specifies the AHB peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  * @arg RCC_AHBENR_DMA,RCC_AHBENR_SRAM,RCC_AHBENR_FLASH,
  *   RCC_AHBENR_CRC,RCC_AHBENR_GPIOA,RCC_AHBENR_GPIOB,
  *   RCC_AHBENR_GPIOC,RCC_AHBENR_GPIOD,RCC_AHBENR_USB,
  *   RCC_AHBENR_HWDIV

  *   SRAM and FLITF clock can be disabled only during sleep mode.
  * @param NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */

void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->AHBENR |= RCC_AHBPeriph;
    }
    else
    {
        RCC->AHBENR &= ~RCC_AHBPeriph;
    }
}

/**
  * @brief  Enables or disables the High Speed APB (APB2) peripheral clock.
  * @param RCC_APB2Periph: specifies the APB2 peripheral to gates its
  *   clock.
  *   This parameter can be any combination of the following values:
  * @arg RCC_APB2ENR_SYSCFG,RCC_APB2ENR_ADC,
  *   RCC_APB2ENR_TIM1,RCC_APB2ENR_SPI1,RCC_APB2ENR_UART1,
  *   RCC_APB2ENR_COMP,RCC_APB2ENR_TIM14,RCC_APB2ENR_TIM16,
  *   RCC_APB2ENR_TIM17,RCC_APB2ENR_DBG,RCC_APB2ENR_EXTI,
  *   RCC_APB2ENR_LPTIM,RCC_APB2ENR_LPUART,
  * @param NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->APB2ENR |= RCC_APB2Periph;
    }
    else
    {
        RCC->APB2ENR &= ~RCC_APB2Periph;
    }
}

/**
  * @brief  Enables or disables the Low Speed APB (APB1) peripheral clock.
  * @param RCC_APB1Periph: specifies the APB1 peripheral to gates its
  *   clock.
  *   This parameter can be any combination of the following values:

  * @arg RCC_APB1ENR_TIM2,RCC_APB1ENR_TIM3,RCC_APB1ENR_I3C,
  *   RCC_APB1ENR_WWDG, RCC_APB1ENR_SPI2, RCC_APB1ENR_UART2,
  *   RCC_APB1ENR_UART3, RCC_APB1ENR_UART4, RCC_APB1ENR_I2C1,
  *   RCC_APB1ENR_BKP, RCC_APB1ENR_FLEXCAN, RCC_APB1ENR_CRS,
  *   RCC_APB1ENR_PWR, RCC_APB1ENR_PWR, RCC_APB1ENR_IWDG,
  *   RCC_APB1ENR_RTC
  *   RCC_APB1Periph_ALL
  * @param NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->APB1ENR |= RCC_APB1Periph;
    }
    else
    {
        RCC->APB1ENR &= ~RCC_APB1Periph;
    }
}


/**
  * @brief  Forces or releases High Speed APB (APB2) peripheral reset.
  * @param RCC_APB2Periph: specifies the APB2 peripheral to reset.
  *   This parameter can be any combination of the following values:
  * @arg
  				RCC_AHBENR_DMA
  				RCC_AHBPeriph_SRAM
  				RCC_AHBPeriph_FLITF
  				RCC_AHBPeriph_CRC
  				RCC_AHBPeriph_GPIOA
  				RCC_AHBPeriph_GPIOB
  				RCC_AHBPeriph_GPIOC
  				RCC_AHBPeriph_GPIOD
  				RCC_AHBPeriph_HWDIV
  * @param NewState: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->AHBRSTR |= RCC_AHBPeriph;
    }
    else
    {
        RCC->AHBRSTR &= ~RCC_AHBPeriph;
    }
}

/**
  * @brief  Forces or releases High Speed APB (APB2) peripheral reset.
  * @param RCC_APB2Periph: specifies the APB2 peripheral to reset.
  *   This parameter can be any combination of the following values:
  * @arg  RCC_APB2Periph_ADC1,
  *   RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
  *   RCC_APB2Periph_TIM8, RCC_APB2Periph_UART1, RCC_APB2Periph_ADC3,
  *   RCC_APB2Periph_ALL
  * @param NewState: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->APB2RSTR |= RCC_APB2Periph;
    }
    else
    {
        RCC->APB2RSTR &= ~RCC_APB2Periph;
    }
}

/**
  * @brief  Forces or releases Low Speed APB (APB1) peripheral reset.
  * @param RCC_APB1Periph: specifies the APB1 peripheral to reset.
  *   This parameter can be any combination of the following values:
  * @arg RCC_APB1Periph_TIM2, RCC_APB1Periph_TIM3, RCC_APB1Periph_TIM4,
  *   RCC_APB1Periph_TIM5, RCC_APB1Periph_TIM6, RCC_APB1Periph_TIM7,
  *   RCC_APB1Periph_WWDG, RCC_APB1Periph_SPI2, RCC_APB1Periph_SPI3,
  *   RCC_APB1Periph_UART2, RCC_APB1Periph_UART3, RCC_APB1Periph_UART4,
  *   RCC_APB1Periph_UART5, RCC_APB1Periph_I2C1, RCC_APB1Periph_I2C2,
  *   RCC_APB1Periph_USB, RCC_APB1Periph_CAN1, RCC_APB1Periph_BKP,
  *   RCC_APB1Periph_PWR, RCC_APB1Periph_DAC, RCC_APB1Periph_ALL
  * @param NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{

    if (NewState != DISABLE)
    {
        RCC->APB1RSTR |= RCC_APB1Periph;
    }
    else
    {
        RCC->APB1RSTR &= ~RCC_APB1Periph;
    }
}

/**
  * @brief  Forces or releases the Backup domain reset.
  * @param NewState: new state of the Backup domain reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_BackupResetCmd(FunctionalState NewState)
{

/* *(__IO uint32_t *) BDCR_BDRST_BB = (uint32_t)NewState; */
    if(NewState==ENABLE)
    {
        RCC->BDCR |= (uint32_t)0x00010000;
    }
    else
    {
        RCC->BDCR &= (uint32_t)0xfffeffff;
    }
}

/**
  * @brief  Enables or disables the Clock Security System.
  * @param NewState: new state of the Clock Security System..
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void RCC_ClockSecuritySystemCmd(FunctionalState NewState)
{

    /* *(__IO uint32_t *) CR_CSSON_BB = (uint32_t)NewState; */
    if(NewState==ENABLE)
    {
        RCC->CR |= (uint32_t)0x00080000;
    }
    else
    {
        RCC->CR &= (uint32_t)0xfff7ffff;
    }
}

/**
  * @brief  Selects the clock source to output on MCO pin.
  * @param RCC_MCO: specifies the clock source to output.
  *   This parameter can be one of the following values:
  * @arg RCC_MCO_NoClock: No clock selected
  * @arg RCC_MCO_SYSCLK: System clock selected
  * @arg RCC_MCO_HSI: HSI oscillator clock selected
  * @arg RCC_MCO_HSE: HSE oscillator clock selected
  * @arg RCC_MCO_PLLCLK_Div2: PLL clock divided by 2 selected
  * @retval : None
  */
void RCC_MCOConfig(uint32_t RCC_MCO)
{
    /* Perform Byte access to MCO[2:0] bits to select the MCO source */
    RCC->CFGR &= 0xF8FFFFFF;
    RCC->CFGR |= RCC_MCO;/* (RCC_MCO<<24); */
}

/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param RCC_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  * @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready
  * @arg RCC_FLAG_HSERDY: HSE oscillator clock ready
  * @arg RCC_FLAG_PLLRDY: PLL clock ready
  * @arg RCC_FLAG_LSERDY: LSE oscillator clock ready
  * @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready
  * @arg RCC_FLAG_PINRST: Pin reset
  * @arg RCC_FLAG_PORRST: POR/PDR reset
  * @arg RCC_FLAG_SFTRST: Software reset
  * @arg RCC_FLAG_IWDGRST: Independent Watchdog reset
  * @arg RCC_FLAG_WWDGRST: Window Watchdog reset
  * @arg RCC_FLAG_LPWRRST: Low Power reset
  * @retval : The new state of RCC_FLAG (SET or RESET).
  */
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG)
{
    uint32_t tmp = 0;
    uint32_t statusreg = 0;
    FlagStatus bitstatus = RESET;

    /* Get the RCC register index */
    tmp = RCC_FLAG >> 5;
    if (tmp == 1)               /* The flag to check is in CR register */
    {
        statusreg = RCC->CR;
    }
    else if (tmp == 2)          /* The flag to check is in BDCR register */
    {
        statusreg = RCC->BDCR;
    }
    else                       /* The flag to check is in CSR register */
    {
        statusreg = RCC->CSR;
    }
    /* Get the flag position */
    tmp = RCC_FLAG & RCC_FLAG_Mask;
    if ((statusreg & ((uint32_t)1 << tmp)) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    /* Return the flag status */
    return bitstatus;
}

/**
  * @brief  Clears the RCC reset flags.
  *   The reset flags are: RCC_FLAG_PINRST, RCC_FLAG_PORRST,
  *   RCC_FLAG_SFTRST, RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST,
  *   RCC_FLAG_LPWRRST
  * @param  None
  * @retval : None
  */
void RCC_ClearFlag(void)
{
    /* Set RMVF bit to clear the reset flags */
    RCC->CSR |= CSR_RMVF_Set;
}

/**
  * @brief  Checks whether the specified RCC interrupt has occurred or not.
  * @param RCC_IT: specifies the RCC interrupt source to check.
  *   This parameter can be one of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_PLLRDY: PLL ready interrupt
  * @arg RCC_IT_CSS: Clock Security System interrupt
  * @retval : The new state of RCC_IT (SET or RESET).
  */
ITStatus RCC_GetITStatus(uint8_t RCC_IT)
{
    ITStatus bitstatus = RESET;

    /* Check the status of the specified RCC interrupt */
    if ((RCC->CIR & RCC_IT) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    /* Return the RCC_IT status */
    return  bitstatus;
}

/**
  * @brief  Clears the RCC interrupt pending bits.
  * @param RCC_IT: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_PLLRDY: PLL ready interrupt
  * @arg RCC_IT_CSS: Clock Security System interrupt
  * @retval : None
  */
void RCC_ClearITPendingBit(uint8_t RCC_IT)
{

    /* Perform Byte access to RCC_CIR[23:16] bits to clear the selected interrupt
    pending bits */

    RCC->CIR |= (uint32_t)RCC_IT<<16;
}
/**
  * @brief  Enables or disables the specified ADC peripheral Clock.
  * @param  peripheral:select the ADC peripheral.
  * @param  state: new state of the ADC peripheral.
  * @retval None.
  */
void RCC_ADC_ClockCmd(ADC_TypeDef* peripheral, FunctionalState state)
{
    if(ADC1 == peripheral) {
        (state) ? (RCC->APB2ENR |= RCC_APB2ENR_ADC) : (RCC->APB2ENR &= ~RCC_APB2ENR_ADC);
    }

}

/**
  * @brief  Enables or disables the specified COMP peripheral Clock.
  * @param  peripheral:select the COMP peripheral.
  * @param  state: new state of the COMP peripheral.
  * @retval None.
  */
void RCC_COMP_ClockCmd(COMP_TypeDef* peripheral, FunctionalState state)
{
    if(COMP == peripheral) {
        (state) ? (RCC->APB2ENR |= RCC_APB2ENR_COMP) : (RCC->APB2ENR &= ~RCC_APB2ENR_COMP);
    }
}

/**
  * @brief  Enables or disables the specified CRC peripheral Clock.
  * @param  peripheral:select the CRC peripheral.
  * @param  state: new state of the CRC peripheral.
  * @retval None.
  */
void RCC_CRC_ClockCmd(CRC_TypeDef* peripheral, FunctionalState state)
{
    if(CRC == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_CRC) : (RCC->AHBENR &= ~RCC_AHBENR_CRC);
    }
}

/**
  * @brief  Enables or disables the specified DIV peripheral Clock.
  * @param  peripheral:select the DIV peripheral.
  * @param  state: new state of the DIV peripheral.
  * @retval None.
  */
void RCC_DIV_ClockCmd(HWDIV_TypeDef* peripheral, FunctionalState state)
{
    if(HWDIV == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_HWDIV) : (RCC->AHBENR &= ~RCC_AHBENR_HWDIV);
    }
}

/**
  * @brief  Enables or disables the specified DMA peripheral Clock.
  * @param  peripheral:select the DMA peripheral.
  * @param  state: new state of the DMA peripheral.
  * @retval None.
  */
void RCC_DMA_ClockCmd(DMA_TypeDef* peripheral, FunctionalState state)
{
    if(DMA1 == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_DMA) : (RCC->AHBENR &= ~RCC_AHBENR_DMA);
    }
}

/**
  * @brief  Enables or disables the specified DBGMCU peripheral Clock.
  * @param  peripheral:select the DBGMCU peripheral.
  * @param  state: new state of the DBGMCU peripheral.
  * @retval None.
  */
void RCC_DBGMCU_ClockCmd(DBGMCU_TypeDef* peripheral, FunctionalState state)
{
    if(DBGMCU == peripheral) {
        RCC_APB2PeriphClockCmd(RCC_APB2ENR_DBG, state);
    }
}

/**
  * @brief  Enables or disables the specified CAN peripheral Clock.
  * @param  peripheral:select the CAN peripheral.
  * @param  state: new state of the CAN peripheral.
  * @retval None.
  */
void RCC_FLEXCAN_ClockCmd(FLEXCAN_TypeDef* peripheral, FunctionalState state)
{
    if(FLEXCAN == peripheral) {
        (state) ? (RCC->APB1ENR |= RCC_APB1ENR_FLEXCAN) : (RCC->APB1ENR &= ~RCC_APB1ENR_FLEXCAN);
    }
}

/**
  * @brief  Enables or disables the specified GPIO peripheral Clock.
  * @param  peripheral:select the GPIO peripheral.
  * @param  state: new state of the GPIO peripheral.
  * @retval None.
  */
void RCC_GPIO_ClockCmd(GPIO_TypeDef* peripheral, FunctionalState state)
{
    if(GPIOA == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_GPIOA) : (RCC->AHBENR &= ~RCC_AHBENR_GPIOA);
    }
    else if(GPIOB == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_GPIOB) : (RCC->AHBENR &= ~RCC_AHBENR_GPIOB);
    }
    else if(GPIOC == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_GPIOC) : (RCC->AHBENR &= ~RCC_AHBENR_GPIOC);
    }
    else if(GPIOD == peripheral) {
        (state) ? (RCC->AHBENR |= RCC_AHBENR_GPIOD) : (RCC->AHBENR &= ~RCC_AHBENR_GPIOD);
    }
}

/**
  * @brief  Deinitializes the i2c peripheral registers to their
  *         default reset values.
  * @param  peripheral: Select the I2C or the I2C peripheral.
  * @retval None.
  */
void RCC_I2C_ClockCmd(I2C_TypeDef* peripheral, FunctionalState state)
{
    if(I2C1 == peripheral) {
        (state) ? (RCC->APB1ENR |= RCC_APB1ENR_I2C1) : (RCC->APB1ENR &= ~RCC_APB1ENR_I2C1);
    }
}

/**
  * @brief  Deinitializes the spi peripheral registers to their
  *         default reset values.
  * @param  peripheral: Select the SPI or the SPI peripheral.
  * @retval None.
  */
void RCC_SPI_ClockCmd(SPI_TypeDef* peripheral, FunctionalState state)
{
    if(SPI2 == peripheral) {
        (state) ? (RCC->APB1ENR |= RCC_APB1ENR_SPI2) : (RCC->APB1ENR &= ~RCC_APB1ENR_SPI2);
    }
    else if(SPI1 == peripheral) {
        (state) ? (RCC->APB2ENR |= RCC_APB2ENR_SPI1) : (RCC->APB2ENR &= ~RCC_APB2ENR_SPI1);
    }
}

/**
  * @brief  Deinitializes the uart peripheral registers to their
  *         default reset values.
  * @param  peripheral: Select the UART or the UART peripheral.
  * @retval None.
  */
void RCC_UART_ClockCmd(UART_TypeDef* peripheral, FunctionalState state)
{
    if(UART1 == peripheral) {
        (state) ? (RCC->APB2ENR |= RCC_APB2ENR_UART1) : (RCC->APB2ENR &= ~RCC_APB2ENR_UART1);
    }
    else if(UART2 == peripheral) {
        (state) ? (RCC->APB1ENR |= RCC_APB1ENR_UART2) : (RCC->APB1ENR &= ~RCC_APB1ENR_UART2);
    }
    else if(UART3 == peripheral) {
        (state) ? (RCC->APB1ENR |= RCC_APB1ENR_UART3) : (RCC->APB1ENR &= ~RCC_APB1ENR_UART3);
    }
    else if(UART4 == peripheral) {
        (state) ? (RCC->APB1ENR |= RCC_APB1ENR_UART4) : (RCC->APB1ENR &= ~RCC_APB1ENR_UART4);
    }
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

/*-------------------------(C) COPYRIGHT 2016 MindMotion ----------------------*/
