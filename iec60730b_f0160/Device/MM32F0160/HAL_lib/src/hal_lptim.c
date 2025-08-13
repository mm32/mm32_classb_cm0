/*
 *******************************************************************************
    @file     hal_lptim.c
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
#define _HAL_LPTIM_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_lptim.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup LPTIM_HAL
  * @{
  */

/** @addtogroup LPTIM_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the lptim peripheral registers to their default reset values.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval None.
  */
void LPTIM_DeInit(LPTIM_TypeDef* lptim)
{
    if(lptim == LPTIM1) {
        RCC_APB2PeriphResetCmd(RCC_APB2ENR_LPTIM, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2ENR_LPTIM, DISABLE);
    }
}

/**
  * @brief  Configures the LPTIM1 clock (LPTIM1 CLK).
  *         Once the RTC clock is selected it can be changed unless the
  *         Backup domain is reset.
  * @param  rtc_clk_src: specifies the RTC clock source.
  *         This parameter can be one of the following values:
  * @arg    LPTIM_LSE_Source : LSE selected as LPTIM1 clock
  * @arg    LPTIM_LSI_Source : LSI selected as LPTIM1 clock
  * @arg    LPTIM_PCLK_Source: PCLK(AHB) selected as LPTIM1 clock
  * @retval None.
  */
void LPTIM_CLKConfig(LPTIM_TypeDef* lptim, LPTIM_CLK_SOURCE_TypeDef lptim_clk_src)
{
    if(lptim == LPTIM1) {
        MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPTIM_CLKSEL, lptim_clk_src);
    }
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct : pointer to a LPTIM_TimeBaseInit_TypeDef
  *         structure which will be initialized.
  * @retval None.
  */
void LPTIM_TimeBaseStructInit(LPTIM_TimeBaseInit_TypeDef* init_struct)
{
    init_struct->ClockSource            = LPTIM_PCLK_Source;
    init_struct->CountMode              = LPTIM_CONTINUOUS_COUNT_Mode;
    init_struct->OutputMode             = LPTIM_NORMAL_WAV_Mode;
    init_struct->Waveform               = LPTIM_CycleSquareOutput_Mode;
    init_struct->Polarity               = LPTIM_Positive_Wave;
    init_struct->ClockDivision          = LPTIM_CLK_DIV1;
}

/**
  * @brief  Initializes the lptim Time Base Unit peripheral according to
  *         the specified parameters in the init_struct.
  * @param  lptim: select the LPTIM peripheral.
  * @param  init_struct: pointer to a LPTIM_TimeBaseInit_TypeDef
  *         structure that contains the configuration information for the
  *         specified LPTIM peripheral.
  *         LPTIM_CLK_SOURCE_TypeDef ClockSource    : Specifies the clock source of the LPTIM.
  *         LPTIM_Count_Mode_TypeDef CountMode      : Specifies the Count mode
  *         LPTIM_OUTPUT_Mode_TypeDef OutputMode    : Specifies the Output Mode
  *         LPTIM_PWMOUT_Mode_TypeDef Waveform      : Specifies the PWM wave form.
  *         LPTIM_COMPARE_Polarity_TypeDef Polarity : Specifies the Output Polarity
  *         LPTIM_CLOCK_DIV_TypeDef ClockDivision   : Specifies the clock divide.
  * @retval None.
  */
void LPTIM_TimeBaseInit(LPTIM_TypeDef* lptim, LPTIM_TimeBaseInit_TypeDef* init_struct)
{
    uint32_t temp = 0;
    RCC->CFGR2 &= ~(RCC_CFGR2_LPTIM_CLKSEL);
    RCC->CFGR2 |= (init_struct->ClockSource)&RCC_CFGR2_LPTIM_CLKSEL;
    temp |= (init_struct->CountMode);
    temp |= (init_struct->OutputMode);
    temp |= (init_struct->Waveform);
    temp |= (init_struct->Polarity);
    temp |= (init_struct->ClockDivision);
    lptim->CFG = temp;
}

/**
  * @brief  Enables or disables the specified LPTIM peripheral.
  * @param  lptim: where x can be 1 to select the lptim peripheral.
  * @param  state: new state of the lptim peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPTIM_Cmd(LPTIM_TypeDef* lptim, FunctionalState state)
{
    (state) ? SET_BIT(lptim->CTRL, LPT_CTRL_LPTEN) : CLEAR_BIT(lptim->CTRL, LPT_CTRL_LPTEN);
}

/**
  * @brief  Enables or disables the specified LPTIM input trig source.
  * @param  lptim:  select the lptim peripheral.
  * @param  source: LPTIM input trig source.
  * @retval None.
  */
void LPTIM_InputTrigEdgeConfig(LPTIM_TypeDef* lptim, LPTIM_TrigEdgeConfig_TypeDef edgeselect)
{
    MODIFY_REG(lptim->CFG, LPT_CFG_TRIGCFG_Msk, edgeselect);
}

/**
  * @brief  Enables or disables the specified LPTIM input trig source.
  * @param  lptim:  select the lptim peripheral.
  * @param  source: LPTIM input trig source.
  * @retval None.
  */
void LPTIM_InputTrigSourceConfig(LPTIM_TypeDef* lptim, LPTIM_TrigSourceConfig_TypeDef source)
{
    MODIFY_REG(lptim->CFG, LPT_CFG_TRIGSEL, source);
}

/**
  * @brief  Sets the lptim Clock Division value.
  * @param  lptim:  select
  *   the LPTIM peripheral.
  * @param  clock_div: specifies the clock division value.
  *   This parameter can be one of the following value:
  *     @arg LPTIM_CLK_DIV1
  *     @arg LPTIM_CLK_DIV2
  *     @arg LPTIM_CLK_DIV4
  *     @arg LPTIM_CLK_DIV8
  *     @arg LPTIM_CLK_DIV16
  *     @arg LPTIM_CLK_DIV32
  *     @arg LPTIM_CLK_DIV64
  *     @arg LPTIM_CLK_DIV128
  * @retval None.
  */
void LPTIM_SetClockDivision(LPTIM_TypeDef* lptim, LPTIM_CLOCK_DIV_TypeDef clock_div)
{
    MODIFY_REG(lptim->CFG, LPT_CFG_DIVSEL_Msk, clock_div);
}

/**
  * @brief  Enables or disables the specified LPTIM input filter function.
  * @param  lptim:  select the lptim peripheral.
  * @param  state: new state of the LPTIM input filter mode.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPTIM_InputFilterConfig(LPTIM_TypeDef* lptim, FunctionalState state)
{
    (state) ? SET_BIT(lptim->CFG, LPT_CFG_FLTEN) : CLEAR_BIT(lptim->CFG, LPT_CFG_FLTEN);
}

/**
  * @brief  Sets the lptim Counter Register value
  * @param  lptim:  select the LPTIM peripheral.
  * @param  counter: specifies the Counter register new value.
  * @retval None.
  */
void LPTIM_SetCounter(LPTIM_TypeDef* lptim, uint16_t counter)
{
    WRITE_REG(lptim->CNT, (uint32_t)counter);
}

/**
  * @brief  Gets the lptim Counter value.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval Value: Counter Register value.
  */
uint32_t LPTIM_GetCounter(LPTIM_TypeDef* lptim)
{
    return lptim->CNT;
}

/**
  * @brief  Sets the lptim Compare Register value
  * @param  lptim:  select the LPTIM peripheral.
  * @param  compare: specifies the Compare register new value.
  * @retval None.
  */
void LPTIM_SetCompare(LPTIM_TypeDef* lptim, uint16_t compare)
{
    WRITE_REG(lptim->CMP, (uint32_t)compare);
}

/**
  * @brief  Gets the lptim Compare value.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval Value: Compare Register value.
  */
uint16_t LPTIM_GetCompare(LPTIM_TypeDef* lptim)
{
    return (uint16_t)lptim->CMP;
}

/**
  * @brief  Sets the lptim target Register value
  * @param  lptim:  select the LPTIM peripheral.
  * @param  target: specifies the target register new value.
  * @retval None.
  */
void LPTIM_SetTarget(LPTIM_TypeDef* lptim, uint16_t target)
{
    WRITE_REG(lptim->TARGET, (uint32_t)target);
}

/**
  * @brief  Gets the lptim target value.
  * @param  lptim:  select the LPTIM peripheral.
  * @retval Value: target Register value.
  */
uint16_t LPTIM_GetTarget(LPTIM_TypeDef* lptim)
{
    return (uint16_t)lptim->CNT;
}

/**
  * @brief  Enables or disables the specified LPTIM interrupts.
  * @param  lptim:  select the lptim peripheral.
  * @param  it: specifies the LPTIM interrupts sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg LPTIE_COMPIE: LPTIM COMPARE Interrupt Enable Bit
  *     @arg LPTIE_TRIGIE: LPTIM Ext Trig Interrupt Enable Bit
  *     @arg LPTIE_OVIE  : LPTIM Overflow Interrupt Enable Bit
  * @param  state: new state of the LPTIM interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPTIM_ITConfig(LPTIM_TypeDef* lptim, uint32_t it, FunctionalState state)
{
    (state) ? SET_BIT(lptim->IE, it) : CLEAR_BIT(lptim->IE, it);
}

/**
  * @brief  Checks whether the LPTIM interrupt has occurred or not.
  * @param  lptim:  select the LPTIM peripheral.
  * @param  it: specifies the LPTIM interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg LPTIF_COMPIF: LPTIM Compare Interrupt Flag
  *     @arg LPTIF_TRIGIF: LPTIM Trig Interrupt Flag
  *     @arg LPTIF_OVIF  : LPTIM Counter Overflow Interrupt Flag
  * @retval State: The new state of the LPTIM_IT(SET or RESET).
  */
ITStatus LPTIM_GetITStatus(LPTIM_TypeDef* lptim, uint32_t it)
{
    return ( (lptim->IF & it)  ? SET : RESET);
}

/**
  * @brief  Clears the lptim's interrupt pending bits, write 1 to clear bit.
  * @param  lptim:  select the LPTIM peripheral.
  * @param  it: specifies the pending bit to clear by write 1 to clear.
  *   This parameter can be any combination of the following values:
  *     @arg LPTIF_COMPIF: LPTIM Compare Interrupt Flag
  *     @arg LPTIF_TRIGIF: LPTIM Trig Interrupt Flag
  *     @arg LPTIF_OVIF  : LPTIM Counter Overflow Interrupt Flag
  * @retval None.
  */
void LPTIM_ClearITPendingBit(LPTIM_TypeDef* lptim,  uint32_t it)
{
    lptim->IF = it;
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
