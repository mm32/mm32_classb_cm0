/*
 *******************************************************************************
    @file     hal_rcc.h
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
#ifndef __HAL_RCC_H
#define __HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup RCC_HAL
  * @brief RCC HAL modules
  * @{
  */

/** @defgroup RCC_Exported_Types
  * @{
  */

/** @defgroup RCC_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Exported_Enumeration
  * @{
  */

/**
  * @brief HSE configuration
  */
typedef enum {
    RCC_HSE_OFF                         = 0,                                    /*!< HSE OFF */
    RCC_HSE_ON                          = RCC_CR_HSEON,                         /*!< HSE ON */
    RCC_HSE_Bypass                      = RCC_CR_HSEBYP                         /*!< HSE Bypass */
} RCCHSE_TypeDef;

/**
  * @brief Used for flags
  */
typedef enum {
    CR_REG_INDEX                        = 1,
    BDCR_REG_INDEX                      = 2,
    CSR_REG_INDEX                       = 3,
    RCC_FLAG_MASK                       = 0x1FU
} RCC_RegisterFlag_TypeDef;

/**
  * @brief RCC Flag
  */
typedef enum {
    /* Flags in the CR register ----------------------------------------------*/
    RCC_FLAG_HSIRDY = ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSIRDY_Pos)),         /*!< Internal High Speed clock ready flag */
    RCC_FLAG_HSERDY = ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos)),         /*!< External High Speed clock ready flag */

    RCC_FLAG_PLL1RDY = ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL1RDY_Pos)),       /*!< PLL1 clock ready flag */
    RCC_FLAG_PLL2RDY = ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL2RDY_Pos)),       /*!< PLL2 clock ready flag */

    /* Flag in the BDCR register ---------------------------------------------*/
    RCC_FLAG_LSERDY  = ((uint8_t)((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSERDY_Pos)),    /*!< External Low Speed oscillator Ready */

    /* Flags in the CSR register ---------------------------------------------*/
    RCC_FLAG_LSIRDY  = ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LSIRDY_Pos)),      /*!< Internal Low Speed oscillator Ready */
    RCC_FLAG_PINRST  = ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PINRSTF_Pos)),     /*!< PIN reset flag */
    RCC_FLAG_PORRST  = ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PORRSTF_Pos)),     /*!< POR/PDR reset flag */
    RCC_FLAG_SFTRST  = ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_SFTRSTF_Pos)),     /*!< Software Reset flag */
    RCC_FLAG_IWDGRST = ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_IWDGRSTF_Pos)),    /*!< Independent Watchdog reset flag */
    RCC_FLAG_WWDGRST = ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_WWDGRSTF_Pos)),    /*!< Window watchdog reset flag */
} RCC_FLAG_TypeDef;

/**
  * @brief System clock source
  */
typedef enum {
    RCC_HSI                             = 0,                                    /*!< Set HSI as systemCLOCK */
    RCC_HSE                             = 1,                                    /*!< Set HSE as systemCLOCK */
    RCC_PLL                             = 2,                                    /*!< Set PLL as systemCLOCK */
    RCC_LSI                             = 3                                     /*!< Set LSI as systemCLOCK */
} SYSCLK_TypeDef;

/**
  * @brief PLL entry clock source
  */
typedef enum {
    RCC_HSI_Div4                        = 0,
    RCC_HSI_Div                         = 0,
    RCC_HSE1_Div1                       = RCC_PLL1CFGR_PLL1SRC,
    RCC_HSE1_Div2                       = (RCC_PLL1CFGR_PLL1XTPRE | RCC_PLL1CFGR_PLL1SRC),
    RCC_HSE2_Div1                       = RCC_PLL2CFGR_PLL2SRC,
    RCC_HSE2_Div2                       = (RCC_PLL2CFGR_PLL2XTPRE | RCC_PLL2CFGR_PLL2SRC)
} RCC_PLLSource_TypeDef;

/**
  * @brief PLL multiplication factor
  */
typedef enum {
    RCC_PLLMul_2                        = 0x00000000U,
    RCC_PLLMul_3                        = 0x00040000U,
    RCC_PLLMul_4                        = 0x00080000U,
    RCC_PLLMul_5                        = 0x000C0000U,
    RCC_PLLMul_6                        = 0x00100000U,
    RCC_PLLMul_7                        = 0x00140000U,
    RCC_PLLMul_8                        = 0x00180000U,
    RCC_PLLMul_9                        = 0x001C0000U,
    RCC_PLLMul_10                       = 0x00200000U,
    RCC_PLLMul_11                       = 0x00240000U,
    RCC_PLLMul_12                       = 0x00280000U,
    RCC_PLLMul_13                       = 0x002C0000U,
    RCC_PLLMul_14                       = 0x00300000U,
    RCC_PLLMul_15                       = 0x00340000U,
    RCC_PLLMul_16                       = 0x00380000U,
    RCC_PLLMul_17                       = 0x003A0000U,
    RCC_PLLMul_18                       = 0x003D0000U
} RCC_PLLMul_TypeDef;

/**
  * @brief AHB clock source
  */
typedef enum {
    RCC_SYSCLK_Div1                     = RCC_CFGR_HPRE_DIV1,
    RCC_SYSCLK_Div2                     = RCC_CFGR_HPRE_DIV2,
    RCC_SYSCLK_Div4                     = RCC_CFGR_HPRE_DIV4,
    RCC_SYSCLK_Div8                     = RCC_CFGR_HPRE_DIV8,
    RCC_SYSCLK_Div16                    = RCC_CFGR_HPRE_DIV16,
    RCC_SYSCLK_Div64                    = RCC_CFGR_HPRE_DIV64,
    RCC_SYSCLK_Div128                   = RCC_CFGR_HPRE_DIV128,
    RCC_SYSCLK_Div256                   = RCC_CFGR_HPRE_DIV256,
    RCC_SYSCLK_Div512                   = RCC_CFGR_HPRE_DIV512
} RCC_AHB_CLK_TypeDef;

/**
  * @brief APB1 and APB2clock source
  */
typedef enum {
    RCC_HCLK_Div1                       = RCC_CFGR_PPRE1_DIV1,
    RCC_HCLK_Div2                       = RCC_CFGR_PPRE1_DIV2,
    RCC_HCLK_Div4                       = RCC_CFGR_PPRE1_DIV4,
    RCC_HCLK_Div8                       = RCC_CFGR_PPRE1_DIV8,
    RCC_HCLK_Div16                      = RCC_CFGR_PPRE1_DIV16
} RCC_APB1_APB2_CLK_TypeDef;

/**
  * @brief USB Device clock source
  */
typedef enum {
    RCC_USBCLKSource_PLLCLK_Div1        = 0,
    RCC_USBCLKSource_PLLCLK_Div2        = 1,
    RCC_USBCLKSource_PLLCLK_Div3        = 2,
    RCC_USBCLKSource_PLLCLK_Div4        = 3
} RCC_USBCLKSOURCE_TypeDef;

/**
  * @brief ADC clock source
  */
typedef enum {
    RCC_PCLK2_Div2                      = (0x00000000),
    RCC_PCLK2_Div4                      = (0x00004000),
    RCC_PCLK2_Div6                      = (0x00008000),
    RCC_PCLK2_Div8                      = (0x0000C000)
} RCC_ADCCLKSOURCE_TypeDef;

/**
  * @brief Clock source to output on MCO pin
  */
typedef enum {
    RCC_MCO_NoClock                     = RCC_CFGR_MCO_NOCLOCK,
    RCC_MCO_LSI                         = RCC_CFGR_MCO_LSI,
    RCC_MCO_LSE                         = RCC_CFGR_MCO_LSE,
    RCC_MCO_SYSCLK                      = RCC_CFGR_MCO_SYSCLK,
    RCC_MCO_HSI                         = RCC_CFGR_MCO_HSI,
    RCC_MCO_HSE                         = RCC_CFGR_MCO_HSE,
    RCC_MCO_PLLCLK_Div2                 = RCC_CFGR_MCO_PLL1DIV2
} RCC_MCO_TypeDef;

/**
  * @brief RCC Interrupt source
  */
typedef enum {
    RCC_IT_LSIRDY                       = RCC_CIR_LSIRDYF,
    RCC_IT_LSERDY                       = RCC_CIR_LSERDYF,
    RCC_IT_HSIRDY                       = RCC_CIR_HSIRDYF,
    RCC_IT_HSERDY                       = RCC_CIR_HSERDYF,
    RCC_IT_PLL1RDY                      = RCC_CIR_PLL1RDYF,
    RCC_IT_PLL2RDY                      = RCC_CIR_PLL2RDYF,
    RCC_IT_CSS                          = RCC_CIR_CSSF
} RCC_IT_TypeDef;

/**
  * @brief RCC clock frequency type definition
  */
typedef struct {
    uint32_t SYSCLK_Frequency;                                                  /*!< returns SYSCLK clock frequency. */
    uint32_t HCLK_Frequency;                                                    /*!< returns hclk clock frequency. */
    uint32_t PCLK1_Frequency;                                                   /*!< returns PCLK1 clock frequency. */
    uint32_t PCLK2_Frequency;                                                   /*!< returns PCLK2 clock frequency. */
    uint32_t ADCCLK_Frequency;                                                  /*!< returns ADCCLK clock frequency. */
} RCC_ClocksTypeDef;


/** @defgroup LSE_configuration
  * @{
  */

#define RCC_LSE_OFF                      (0x00U << RCC_BDCR_LSEON_Pos)  /* LSE OFF */
#define RCC_LSE_ON                       (0x01U << RCC_BDCR_LSEON_Pos)  /* LSE ON */
#define RCC_LSE_Bypass                   (0x01U << RCC_BDCR_LSEBYP_Pos) /* LSE Bypass */

/**
  * @}
  */

/** @defgroup System_clock_source
  * @{
  */

#define RCC_SYSCLKSource_HSI             RCC_CFGR_SWS_HSI
#define RCC_SYSCLKSource_HSE             RCC_CFGR_SWS_HSE
#define RCC_SYSCLKSource_PLLCLK          RCC_CFGR_SWS_PLL1
#define RCC_SYSCLKSource_LSI             RCC_CFGR_SWS_LSI
/**
  * @}
  */

/** @defgroup USB_clock_source
  * @{
  */

#define RCC_USBCLKSource_PLLCLK_1Div5    ((uint8_t)0x00)
#define RCC_USBCLKSource_PLLCLK_Div1     ((uint8_t)0x01)

/**
  * @}
  */

/** @defgroup RTC_clock_source
  * @{
  */

#define RCC_RTCCLKSource_LSE             ((uint32_t)0x00000100)
#define RCC_RTCCLKSource_LSI             ((uint32_t)0x00000200)
#define RCC_RTCCLKSource_HSE_Div128      ((uint32_t)0x00000300)

/**
  * @}
  */


/**
  * @}
  */

/** @defgroup RCC_Exported_Variables
  * @{
  */
#ifdef _HAL_RCC_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL
/**
  * @}
  */

/** @defgroup RCC_Exported_Functions
  * @{
  */
void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLL1Config(uint32_t RCC_PLLSource, uint32_t RCC_PLLDN, uint32_t RCC_PLLDM, uint32_t RCC_PLLDP);
void RCC_PLL2Config(uint32_t RCC_PLLSource, uint32_t RCC_PLLDN, uint32_t RCC_PLLDM, uint32_t RCC_PLLDP);
void RCC_PLL1Cmd(FunctionalState NewState);
void RCC_PLL2Cmd(FunctionalState NewState);
void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);
void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);
void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);
void RCC_LSEConfig(uint32_t rcc_lse);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(uint32_t RCC_MCO);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);

void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);

uint8_t  RCC_GetSYSCLKSource(void);
uint32_t RCC_GetSysClockFreq(void);
uint32_t RCC_GetHCLKFreq(void);
uint32_t RCC_GetPCLK1Freq(void);

void RCC_ADC_ClockCmd(ADC_TypeDef* peripheral, FunctionalState state);
void RCC_COMP_ClockCmd(COMP_TypeDef* peripheral, FunctionalState state);
void RCC_DMA_ClockCmd(DMA_TypeDef* peripheral, FunctionalState state);
void RCC_DBGMCU_ClockCmd(DBGMCU_TypeDef* peripheral, FunctionalState state);
void RCC_FLEXCAN_ClockCmd(FLEXCAN_TypeDef* peripheral, FunctionalState state);
void RCC_GPIO_ClockCmd(GPIO_TypeDef* peripheral, FunctionalState state);
void RCC_I2C_ClockCmd(I2C_TypeDef* peripheral, FunctionalState state);
void RCC_SPI_ClockCmd(SPI_TypeDef* peripheral, FunctionalState state);
void RCC_UART_ClockCmd(UART_TypeDef* peripheral, FunctionalState state);
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
#endif/* __HAL_RCC_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

