/*
 *******************************************************************************
    @file     hal_lptim.h
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
#ifndef __HAL_LPTIM_H
#define __HAL_LPTIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup LPTIM_HAL
  * @brief TIM HAL modules
  * @{
  */

/** @defgroup LPTIM_Exported_Types
  * @{
  */

/**
  * @brief LPTIM_CLK_SOURCE_TypeDef
  * @anchor LPTIM_CLK_SOURCE_TypeDef
  */
typedef enum {
    LPTIM_LSE_Source                    = RCC_CFGR2_LPTIM_CLKSEL_LSE,           /*!< LPTIM clock source select LSE */
    LPTIM_LSI_Source                    = RCC_CFGR2_LPTIM_CLKSEL_LSI,           /*!< LPTIM clock source select LSI */
    LPTIM_PCLK_Source                   = RCC_CFGR2_LPTIM_CLKSEL_PCLK_LPTIMER   /*!< LPTIM clock source select PCLK */
} LPTIM_CLK_SOURCE_TypeDef;

/**
  * @brief LPTIM_Count_Mode_TypeDef
  * @anchor LPTIM_Count_Mode_TypeDef
  */
typedef enum {
    LPTIM_CONTINUOUS_COUNT_Mode         = 0,                                    /*!< LPTIM Continuous Count mode */
    LPTIM_SINGLE_COUNT_Mode             = LPT_CFG_MODE,                         /*!< LPTIM Single Count mode */
} LPTIM_Count_Mode_TypeDef;

/**
  * @brief LPTIM_OUTPUT_Mode_TypeDef
  * @anchor LPTIM_OUTPUT_Mode_TypeDef
  */
typedef enum {
    LPTIM_NORMAL_WAV_Mode               = LPT_CFG_TMODE_0,                      /*!< LPTIM Normal TIM Wave output mode */
    LPTIM_PULSE_TRIG_Mode               = LPT_CFG_TMODE_1,                      /*!< LPTIM pulse trig count output mode */
    LPTIM_TIMEOUT_Mode                  = LPT_CFG_TMODE_3                       /*!< LPTIM time out output mode */
} LPTIM_OUTPUT_Mode_TypeDef;

/**
  * @brief LPTIM_PWMOUT_Mode_TypeDef
  * @anchor LPTIM_PWMOUT_Mode_TypeDef
  */
typedef enum {
    LPTIM_CycleSquareOutput_Mode        = 0,                                    /*!< LPTIM Cycle Square Wave output mode */
    LPTIM_AdjustPwmOutput_Mode          = LPT_CFG_PWM,                          /*!< LPTIM Pulse Wave Modified output mode */
} LPTIM_PWMOUT_Mode_TypeDef;

/**
  * @brief LPTIM_COMPARE_Polarity_TypeDef
  * @anchor LPTIM_COMPARE_Polarity_TypeDef
  */
typedef enum {
    LPTIM_Positive_Wave                 = 0,                                    /*!< LPTIM Compare Match Wave mode(positive) */
    LPTIM_Negative_Wave                 = LPT_CFG_POLARITY,                     /*!< LPTIM Compare Match Wave mode(negative) */
} LPTIM_COMPARE_Polarity_TypeDef;

/**
  * @brief LPTIM_TrigSourceConfig_TypeDef
  * @anchor LPTIM_TrigSourceConfig_TypeDef
  */
typedef enum {
    LPTIM_External_PIN_Trig             = 0,                                    /*!< LPTIM use external pin as trig source */
    LPTIM_COMP_OUT_Trig                 = LPT_CFG_TRIGSEL,                      /*!< LPTIM out COPM output as trig source */
} LPTIM_TrigSourceConfig_TypeDef;

/**
  * @brief LPTIM_TrigEdgeConfig_TypeDef
  * @anchor LPTIM_TrigEdgeConfig_TypeDef
  */
typedef enum {
    LPTIM_ExInputUpEdge                 = LPT_CFG_TRIGCFG_Rise,                 /*!< LPTIM use external signal raise edge trig */
    LPTIM_ExInputDownEdge               = LPT_CFG_TRIGCFG_Fall,                 /*!< LPTIM use external signal fall edge trig */
    LPTIM_ExInputUpDownEdge             = LPT_CFG_TRIGCFG_Both,                 /*!< LPTIM use external signal raise and fall edge trig */
} LPTIM_TrigEdgeConfig_TypeDef;

/**
  * @brief LPTIM_CLOCK_DIV_TypeDef
  * @anchor LPTIM_CLOCK_DIV_TypeDef
  */
typedef enum {
    LPTIM_CLK_DIV1                      = LPT_CFG_DIVSEL_1,                     /*!< LPTIM  Counter Clock div 1 */
    LPTIM_CLK_DIV2                      = LPT_CFG_DIVSEL_2,                     /*!< LPTIM  Counter Clock div 2 */
    LPTIM_CLK_DIV4                      = LPT_CFG_DIVSEL_4,                     /*!< LPTIM  Counter Clock div 4 */
    LPTIM_CLK_DIV8                      = LPT_CFG_DIVSEL_8,                     /*!< LPTIM  Counter Clock div 8 */
    LPTIM_CLK_DIV16                     = LPT_CFG_DIVSEL_16,                    /*!< LPTIM  Counter Clock div 16 */
    LPTIM_CLK_DIV32                     = LPT_CFG_DIVSEL_32,                    /*!< LPTIM  Counter Clock div 32 */
    LPTIM_CLK_DIV64                     = LPT_CFG_DIVSEL_64,                    /*!< LPTIM  Counter Clock div 64 */
    LPTIM_CLK_DIV128                    = LPT_CFG_DIVSEL_128,                   /*!< LPTIM  Counter Clock div 128 */
} LPTIM_CLOCK_DIV_TypeDef;

/**
  * @brief LPTIM_FilterTrig_TypeDef
  * @anchor LPTIM_FilterTrig_TypeDef
  */
typedef enum {
    LPTIM_FilterTrig_Disable            = 0,                                    /*!< LPTIM Filter Trig disable */
    LPTIM_FilterTrig_Enable             = LPT_CFG_FLTEN,                        /*!< LPTIM Filter Trig enable */
} LPTIM_FilterTrig_TypeDef;

/**
  * @brief  TIM Time Base Init structure definition
  * @note   This structure is used with all lptim.
  */
typedef struct {
    LPTIM_CLK_SOURCE_TypeDef            ClockSource;                            /*!< Specifies the clock source of the LPTIM. */
    LPTIM_Count_Mode_TypeDef            CountMode;                              /*!< Specifies the Count mode */
    LPTIM_OUTPUT_Mode_TypeDef           OutputMode;                             /*!< Specifies the Output Mode */
    LPTIM_PWMOUT_Mode_TypeDef           Waveform;                               /*!< Specifies the PWM wave form. */
    LPTIM_COMPARE_Polarity_TypeDef      Polarity;                               /*!< Specifies the Output Polarity */
    LPTIM_CLOCK_DIV_TypeDef             ClockDivision;                          /*!< Specifies the clock divide. */
} LPTIM_TimeBaseInit_TypeDef;

/**
  * @}
  */

/** @defgroup LPTIM_Exported_Variables
  * @{
  */
#ifdef _HAL_LPTIM_C_
#define GLOBAL

#else
#define GLOBAL extern
#endif

#undef GLOBAL
/**
  * @}
  */

/**
  * @defgroup LPTIM_Exported_Functions
  * @{
  */

/*----------------------------------------------------------------------------*/
/*=================  TimeBase management  ====================================*/
void LPTIM_DeInit(LPTIM_TypeDef* lptim);
void LPTIM_Cmd(LPTIM_TypeDef* lptim, FunctionalState state);
void LPTIM_CLKConfig(LPTIM_TypeDef* lptim, LPTIM_CLK_SOURCE_TypeDef lptim_clk_src);
void LPTIM_TimeBaseStructInit(LPTIM_TimeBaseInit_TypeDef* init_struct);
void LPTIM_TimeBaseInit(LPTIM_TypeDef* lptim, LPTIM_TimeBaseInit_TypeDef* init_struct);
/*void LPTIM_CounterModeConfig(LPTIM_TypeDef* lptim, TIMCOUNTMODE_Typedef counter_mode); */
void LPTIM_SetClockDivision(LPTIM_TypeDef* lptim, LPTIM_CLOCK_DIV_TypeDef clock_div);
void LPTIM_SetCounter(LPTIM_TypeDef* lptim, uint16_t counter);
uint32_t LPTIM_GetCounter(LPTIM_TypeDef* lptim);
void LPTIM_SetCompare(LPTIM_TypeDef* lptim, uint16_t compare);
uint16_t LPTIM_GetCompare(LPTIM_TypeDef* lptim);
void LPTIM_SetTarget(LPTIM_TypeDef* lptim, uint16_t target);
uint16_t LPTIM_GetTarget(LPTIM_TypeDef* lptim);

void LPTIM_ITConfig(LPTIM_TypeDef* lptim, uint32_t it, FunctionalState state);
ITStatus LPTIM_GetITStatus(LPTIM_TypeDef* lptim, uint32_t it);
void LPTIM_ClearITPendingBit(LPTIM_TypeDef* lptim,  uint32_t it);

void LPTIM_InputTrigEdgeConfig(LPTIM_TypeDef* lptim, LPTIM_TrigEdgeConfig_TypeDef edgeselect);
void LPTIM_InputTrigSourceConfig(LPTIM_TypeDef* lptim, LPTIM_TrigSourceConfig_TypeDef source);

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
#endif/* __HAL_LPTIM_H -------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
