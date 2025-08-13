/*
 *******************************************************************************
    @file     hal_pwr.c
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
#define __HAL_PWR_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_pwr.h"


/* CR register bit mask */
#define CR_PDDS_Set              ((uint32_t)0x00000002)
#define CR_DS_Mask               ((uint32_t)0xFFFFFFFC)
#define CR_CWUF_Set              ((uint32_t)0x00000004)
#define CR_PLS_Mask              ((uint32_t)0xFFFFE1FF)

/* SLEEPDEEP bit mask */
#define SysCtrl_SLEEPDEEP_Set    ((uint32_t)0x00000004)


/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup PWR_HAL
  * @{
  */

/** @addtogroup PWR_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the PWR peripheral registers to their default reset
  * values.
  * @param  None.
  * @retval None.
  */
void PWR_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1ENR_PWR, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1ENR_PWR, DISABLE);
}

/**
* @brief  Enables or disables access to the RTC and backup registers.
* @param NewState: new state of the access to the RTC and backup
*   registers. This parameter can be: ENABLE or DISABLE.
* @retval : None
*/
void PWR_BackupAccessCmd(FunctionalState NewState)
{

    /* *(__IO uint32_t *) CR_DBP_BB = (uint32_t)NewState; */
    if(NewState!=DISABLE)
    {
        RCC->BDCR |= 0x01000000;
    }
    else
    {
        RCC->BDCR &= 0xfeffffff;
    }

}

/**
* @brief  Enables or disables the Power Voltage Detector(PVD).
* @param NewState: new state of the PVD.
*   This parameter can be: ENABLE or DISABLE.
* @retval : None
*/
void PWR_PVDCmd(FunctionalState NewState)
{
    (NewState) ? (PWR->CR |= PWR_CR_PVDE) : (PWR->CR &= ~PWR_CR_PVDE);
}

/**
* @brief  Configures the voltage threshold detected by the Power Voltage
*   Detector(PVD).
* @param PWR_PVDLevel: specifies the PVD detection level
*   This parameter can be one of the following values:
* @arg PWR_PVDLevel_1V8: PVD detection level set to 2.8V
* @arg PWR_PVDLevel_2V1: PVD detection level set to 2.1V
* @arg PWR_PVDLevel_2V4: PVD detection level set to 2.4V
* @arg PWR_PVDLevel_2V7: PVD detection level set to 2.7V
* @arg PWR_PVDLevel_3V0: PVD detection level set to 3.0V
* @arg PWR_PVDLevel_3V3: PVD detection level set to 3.3V
* @arg PWR_PVDLevel_3V6: PVD detection level set to 3.6V
* @arg PWR_PVDLevel_3V9: PVD detection level set to 3.9V
* @arg PWR_PVDLevel_4V2: PVD detection level set to 4.2V
* @arg PWR_PVDLevel_4V5: PVD detection level set to 4.5V
* @arg PWR_PVDLevel_4V8: PVD detection level set to 4.8V
* @retval : None
*/
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel)
{
    uint32_t tmpreg = 0;

    tmpreg = PWR->CR;
    /* Clear PLS[7:5] bits */
    tmpreg &= CR_PLS_Mask;
    /* Set PLS[7:5] bits according to PWR_PVDLevel value */
    tmpreg |= PWR_PVDLevel;
    /* Store the new value */
    PWR->CR = tmpreg;
}

/**
* @brief  Enables or disables the WakeUp Pin functionality.
* @param NewState: new state of the WakeUp Pin functionality.
*   This parameter can be: ENABLE or DISABLE.
* @retval : None
*/
void PWR_WakeUpPinCmd(uint32_t WKUP_PIN,uint32_t WKUP_EDGE,FunctionalState NewState)
{

/**
  *   if(NewState!=DISABLE)
  *   {
  *       PWR->CSR |= 0x00000100;
  *   }
  *   else
  *   {
  *       PWR->CSR &= 0xfffffeff;
  *   }
  */
    PWR->CSR &= ~0xffffffff;

    if(NewState!=DISABLE)
    {
        if(WKUP_PIN == WKUP_PIN1)
        {
            PWR->CSR = WKUP_PIN1;
        }
        if(WKUP_PIN == WKUP_PIN2)
        {
            PWR->CSR = WKUP_PIN2;
        }
        if(WKUP_PIN == WKUP_PIN4)
        {
            PWR->CSR = WKUP_PIN4;
        }
        if(WKUP_PIN == WKUP_PIN5)
        {
            PWR->CSR = WKUP_PIN5;
        }
        if(WKUP_PIN == WKUP_PIN6)
        {
            PWR->CSR = WKUP_PIN6;
        }
    }
    else
    {
        PWR->CSR &= ~0xffffffff;
    }

    if((WKUP_EDGE==Falling_Edge_WKUP1)||(WKUP_EDGE==Falling_Edge_WKUP2)||(WKUP_EDGE==Falling_Edge_WKUP4)
        ||(WKUP_EDGE==Falling_Edge_WKUP5)||(WKUP_EDGE==Falling_Edge_WKUP6))
    {
        PWR->CR1 &= ~0x3f;
        PWR->CR1 = WKUP_EDGE;
    }
    else
    {
        PWR->CR1 &= ~0x3f;
    }
}

/**
* @brief  Enters STOP mode.
* @param PWR_Regulator: specifies the regulator state in STOP mode.
*   This parameter can be one of the following values:
* @arg PWR_Regulator_ON: STOP mode with regulator ON
* @arg PWR_Regulator_LowPower: STOP mode with
*   regulator in low power mode
* @param PWR_STOPEntry: specifies if STOP mode in entered with WFI or
*   WFE instruction.
*   This parameter can be one of the following values:
* @arg PWR_STOPEntry_WFI: enter STOP mode with WFI instruction
* @arg PWR_STOPEntry_WFE: enter STOP mode with WFE instruction
* @retval : None
*/
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry)
{
    uint32_t systickreg = 0;
    uint32_t nvicReg = 0;
    uint32_t wrIcerReg = 0;
    uint32_t compcsrReg[2] = {0};
    uint32_t wwdgReg = WWDG->CR;
    uint32_t exti16Reg = 0;
    uint32_t adcReg = ADC1->ADCFG;
    
    RCC_APB2PeriphClockCmd( RCC_APB2ENR_COMP, ENABLE);
    RCC_APB1PeriphClockCmd( RCC_APB1ENR_WWDG, ENABLE);
    RCC_APB2PeriphClockCmd( RCC_APB2ENR_ADC, ENABLE);     
    
    compcsrReg[0] = COMP->COMP1_CSR;
    compcsrReg[1] = COMP->COMP2_CSR;
    
    systickreg = SysTick->CTRL & 0x01;

    MODIFY_REG(PWR->CR, PWR_CR_LPDS | PWR_CR_PDDS, PWR_Regulator);
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= SysCtrl_SLEEPDEEP_Set;

    /* By default, clear the enablement of all interrupts except EXTI0 - EXTI15. The interrupt lines with enablement above EXTI16 will maintain their original enabled states */
    nvicReg = NVIC->ISER[0];
    exti16Reg = EXTI->IMR;
    wrIcerReg = nvicReg;
    wrIcerReg &= ~((1UL << EXTI0_1_IRQn)|(1UL << EXTI2_3_IRQn)|(1UL << EXTI4_15_IRQn));
    
    if(exti16Reg & (1UL << 16))
    {
        wrIcerReg &= ~(1UL << PVD_IRQn);
    }
    if(exti16Reg & (1UL << 17))
    {
        wrIcerReg &= ~(1UL << RTC_BKP_IRQn);
    } 
    if(exti16Reg & (1UL << 18))
    {
        wrIcerReg &= ~(1UL << USB_IRQn);
    }
    if(exti16Reg & (0x3 << 19))
    {
        wrIcerReg &= ~(1UL << ADC_COMP_IRQn);
        ADC1->ADCFG &= ~ADC_ADCFG_ADEN;            
        if(!(exti16Reg & (1UL << 19)))
        {
            COMP->COMP1_CSR &= ~COMP_CSR_EN;
        }
        if(!(exti16Reg & (1UL << 20)))
        {
            COMP->COMP2_CSR &= ~COMP_CSR_EN;
        }
    }  
    if(exti16Reg & (1UL << 22))
    {
        wrIcerReg &= ~(1UL << LPUART1_IRQn);
    }
    if(exti16Reg & (1UL << 23))
    {
        wrIcerReg &= ~(1UL << LPTIM1_IRQn);
    }    
    if(exti16Reg & (1UL << 24))
    {
        wrIcerReg &= ~(1UL << WWDG_IWDG_IRQn);
        WWDG->CR &= ~WWDG_CR_WDGA;
    }
    NVIC->ICER[0] = wrIcerReg;
    
    /* Enable HSI */
    RCC->CR |= 0x1;
    while((RCC->CR & 0x2) == 0);
	
    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR  &= ~(RCC_CFGR_HPRE | RCC_CFGR_SW);
    while((RCC->CFGR & RCC_CFGR_SWS) != 0);
	
    /* Before turning off prefetch, you need to clear the latency configuration */
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR &= ~FLASH_ACR_PRFTBE;
    while ((FLASH->ACR & FLASH_ACR_PRFTBS) != 0)
    {
    }
    
    SysTick->CTRL &= 0xFFFFFFFE;

    /* Disable PLL */
    RCC->CR &= ~(RCC_CR_PLL1ON | RCC_CR_PLL2ON); 
	
    /* RCC_HSIDLY register */
    *(__IO uint32_t *)(RCC_BASE + 0x44) = 0xFF;	
    
    if(PWR_STOPEntry == PWR_STOPEntry_WFI)
    {
        /* Request Wait For Interrupt */
        __WFI();
    }
    else
    {
        /* Request Wait For Event */
        __SEV();
        __WFE();
        __WFE();
    }
    NVIC->ISER[0] = nvicReg;
    SysTick->CTRL |= systickreg ;
    
    ADC1->ADCFG = adcReg;
    WWDG->CR = wwdgReg;
    COMP->COMP1_CSR = compcsrReg[0];
    COMP->COMP2_CSR = compcsrReg[1];
    
    CLEAR_BIT(SCB->SCR, ((u32)SCB_SCR_SLEEPDEEP_Msk)); 
}

/**
  * @brief  Enters STANDBY mode.
  * @param  None.
  * @retval None.
  */
void PWR_EnterSTANDBYMode(void)
{
    uint32_t nvicReg = 0;
    uint32_t wrIcerReg = 0;
    uint32_t wwdgReg = WWDG->CR;
    uint32_t exti16Reg = 0;
    uint32_t adcReg = ADC1->ADCFG;
    
    RCC_APB2PeriphClockCmd( RCC_APB2ENR_COMP, ENABLE);
    RCC_APB1PeriphClockCmd( RCC_APB1ENR_WWDG, ENABLE);    
    RCC_APB2PeriphClockCmd( RCC_APB2ENR_ADC, ENABLE); 
	   
    /* By default, clear the enablement of all interrupts except EXTI0 - EXTI15. The interrupt lines with enablement above EXTI16 will maintain their original enabled states */
    nvicReg = NVIC->ISER[0];
    exti16Reg = EXTI->IMR;
    wrIcerReg = nvicReg;
    wrIcerReg &= ~((1UL << EXTI0_1_IRQn)|(1UL << EXTI2_3_IRQn)|(1UL << EXTI4_15_IRQn));
      
    if(exti16Reg & (1UL << 16))
    {
        wrIcerReg &= ~(1UL << PVD_IRQn);
    }
    if(exti16Reg & (1UL << 17))
    {
        wrIcerReg &= ~(1UL << RTC_BKP_IRQn);
    } 
    if(exti16Reg & (1UL << 18))
    {
        wrIcerReg &= ~(1UL << USB_IRQn);
    }
    if(exti16Reg & (0x3 << 19))
    {
        wrIcerReg &= ~(1UL << ADC_COMP_IRQn);
        ADC1->ADCFG &= ~ADC_ADCFG_ADEN;            
        if(!(exti16Reg & (1UL << 19)))
        {
            COMP->COMP1_CSR &= ~COMP_CSR_EN;
        }
        if(!(exti16Reg & (1UL << 20)))
        {
            COMP->COMP2_CSR &= ~COMP_CSR_EN;
        }
    }  
    if(exti16Reg & (1UL << 22))
    {
        wrIcerReg &= ~(1UL << LPUART1_IRQn);
    }
    if(exti16Reg & (1UL << 23))
    {
        wrIcerReg &= ~(1UL << LPTIM1_IRQn);
    }    
    if(exti16Reg & (1UL << 24))
    {
        wrIcerReg &= ~(1UL << WWDG_IWDG_IRQn);
        WWDG->CR &= ~WWDG_CR_WDGA;
    }
    NVIC->ICER[0] = wrIcerReg;
    
    /* Enable HSI */
    RCC->CR |= 0x1;
    while((RCC->CR & 0x2) == 0);
	
    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR  &= ~(RCC_CFGR_HPRE | RCC_CFGR_SW);
    while((RCC->CFGR & RCC_CFGR_SWS) != 0);
	
    /* Before turning off prefetch, you need to clear the latency configuration */
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR &= ~FLASH_ACR_PRFTBE;
    while ((FLASH->ACR & FLASH_ACR_PRFTBS) != 0)
    {
    }
    
    SysTick->CTRL &= 0xFFFFFFFE;

    /* Disable PLL */
    RCC->CR &= ~(RCC_CR_PLL1ON | RCC_CR_PLL2ON); 
	
    /* RCC_HSIDLY register */
    *(__IO uint32_t *)(RCC_BASE + 0x44) = 0xFF;
    
    PWR->CR |= PWR_CR_PDDS;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
#if defined(__CC_ARM)
    __force_stores();
#endif
    __WFI();
}

/**
  * @brief  Checks whether the specified PWR flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    PWR_FLAG_WU: Wake Up flag
  * @arg    PWR_FLAG_SB: StandBy flag
  * @arg    PWR_FLAG_PVDO: PVD Output
  * @retval The new state of PWR_FLAG (SET or RESET).
  */
FlagStatus PWR_GetFlagStatus(uint32_t flag)
{
    FlagStatus bitstatus = RESET;


    if ((PWR->CSR & flag) != (uint32_t)RESET)
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
* @brief  Clears the PWR's pending flags.
* @param PWR_FLAG: specifies the flag to clear.
*   This parameter can be one of the following values:
* @arg PWR_FLAG_WU: Wake Up flag
* @arg PWR_FLAG_SB: StandBy flag
* @retval : None
*/
void PWR_ClearFlag(uint32_t PWR_FLAG)
{

    PWR->CR |=  PWR_FLAG << 2;
}

/**
* @brief  Enables or disables the WakeUp Pin functionality.
* @param FAST_WKUP_TIME: Fast wake up timer selection.
*   This parameter can be one of the following values:
* @arg PWR_STDBY_FSWK_9
* @arg PWR_STDBY_FSWK_7
* @arg PWR_STDBY_FSWK_5
* @arg PWR_STDBY_FSWK_2
* @retval : None
*/
void PWR_Fast_WakeUpConfig(uint32_t FAST_WKUP_TIME)
{
    PWR->CR &= ~PWR_CR_STDBYFSWK_FS_WK;
    PWR->CR |= FAST_WKUP_TIME<<14;
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
