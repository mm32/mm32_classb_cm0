/*
 *******************************************************************************
    @file     hal_comp.h
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
#ifndef __HAL_COMP_H
#define __HAL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup COMP_HAL
  * @brief COMP HAL modules
  * @{
  ******************************************************************************
  * @defgroup COMP_Exported_Types
  * @{
  */

/**
  * @brief COMP_InvertingInput
  */
typedef enum {
    COMP_InvertingInput_IO0             = COMP_CSR_INM_SEL_0,                   /*!< INM0 as COMP inverting input */
    COMP_InvertingInput_IO1             = COMP_CSR_INM_SEL_1,                   /*!< INM1 as COMP inverting input */
    COMP_InvertingInput_IO2             = COMP_CSR_INM_SEL_2,                   /*!< INM2 as COMP inverting input */
    COMP_InvertingInput_IO3             = COMP_CSR_INM_SEL_3,                   /*!< INM3 as COMP inverting input */
    COMP_InvertingInput_IO4             = COMP_CSR_INM_SEL_4,                   /*!< INM4 as COMP inverting input */
    COMP_InvertingInput_CRV             = COMP_CSR_INM_SEL_4,                   /*!< INM4 as COMP inverting input */
} EM_COMP_InvertingInput;


/**
  * @brief COMP_NonInvertingInput
  */
typedef enum {
    COMP_NonInvertingInput_IO0          = COMP_CSR_INP_SEL_0,                   /*!< INP0 as COMP non-inverting input */
    COMP_NonInvertingInput_IO1          = COMP_CSR_INP_SEL_1,                   /*!< INP1 as COMP non-inverting input */
    COMP_NonInvertingInput_IO2          = COMP_CSR_INP_SEL_2,                   /*!< INP2 as COMP non-inverting input */
    COMP_NonInvertingInput_IO3          = COMP_CSR_INP_SEL_3,                   /*!< INP3 as COMP non-inverting input */
} EM_COMP_NonInvertingInput;

/**
  * @brief COMP_Output
  */
typedef enum {
    COMP_Output_None                    = 0x00000000,                           /*!< No output */
    COMP_Output_TIM1BKIN                = COMP_CSR_OUT_SEL_TIM1_BRAKE,          /*!< Timer1 Break input */
    COMP_Output_TIM1OCREFCLR            = COMP_CSR_OUT_SEL_TIM1_OCREFCLR,       /*!< Timer1 ocrefclear input */
    COMP_Output_TIM1IC1                 = COMP_CSR_OUT_SEL_TIM1_CAPTURE1,       /*!< Timer1 input capture 1 */
    COMP_Output_TIM2IC4                 = COMP_CSR_OUT_SEL_TIM2_CAPTURE4,       /*!< Timer2 input capture 4 */
    COMP_Output_TIM2OCREFCLR            = COMP_CSR_OUT_SEL_TIM2_OCREFCLR,       /*!< Timer2 ocrefclear input */
    COMP_Output_TIM3IC1                 = COMP_CSR_OUT_SEL_TIM3_CAPTURE1,       /*!< Timer3 input capture 1 */
    COMP_Output_TIM3OCREFCLR            = COMP_CSR_OUT_SEL_TIM3_OCREFCLR,       /*!< Timer3 ocrefclear input */
    COMP_Output_LPTIMERTRIG             = COMP_CSR_OUT_SEL_LPTIMER_TRIG         /*!< LPTIMER trigger input */
} EM_COMP_Output;

/**
  * @brief COMP_OutputPoloarity
  */
typedef enum {
    COMP_NonInverted                    = 0x00000000,                           /*!< COMP non-inverting output */
    COMP_OutputPol_NonInverted          = 0x00000000,
    COMP_Inverted                       = 0x00008000,                           /*!< COMP inverting output */
    COMP_OutputPol_Inverted             = 0x00008000
} EM_COMP_OutputPol;

/**
  * @brief COMP_Hysteresis
  */
typedef enum {
    COMP_Hysteresis_No                  = COMP_CSR_HYST_0,                      /*!< Hysteresis Voltage: 0mV */
    COMP_Hysteresis_Low                 = COMP_CSR_HYST_1,                      /*!< Hysteresis Voltage: 15mV */
    COMP_Hysteresis_Medium              = COMP_CSR_HYST_2,                      /*!< Hysteresis Voltage: 30mV */
    COMP_Hysteresis_High                = COMP_CSR_HYST_3                       /*!< Hysteresis Voltage: 90mV */
} EM_COMP_Hysteresis;
typedef enum {
    COMP_Filter_0_Period                = COMP_CSR_OFLT_0,                      /*!< filter is ((uint32_t)0x00000000) */
    COMP_Filter_2_Period                = COMP_CSR_OFLT_1,                      /*!< filter is ((uint32_t)0x00040000) */
    COMP_Filter_4_Period                = COMP_CSR_OFLT_2,                      /*!< filter is ((uint32_t)0x00080000) */
    COMP_Filter_8_Period                = COMP_CSR_OFLT_3,                      /*!< filter is ((uint32_t)0x000C0000) */
    COMP_Filter_16_Period               = COMP_CSR_OFLT_4,                      /*!< filter is ((uint32_t)0x00100000) */
    COMP_Filter_32_Period               = COMP_CSR_OFLT_5,                      /*!< filter is ((uint32_t)0x00140000) */
    COMP_Filter_64_Period               = COMP_CSR_OFLT_6,                      /*!< filter is ((uint32_t)0x00180000) */
    COMP_Filter_128_Period              = COMP_CSR_OFLT_7,                      /*!< filter is ((uint32_t)0x001C0000) */
} EM_COMP_FILT;

/**
  * @brief COMP_Mode
  */
typedef enum {
    COMP_Mode_HighSpeed                 = COMP_CSR_MODE_HIGHRATE,               /*!< Comparator high rate mode */
    COMP_Mode_MediumSpeed               = COMP_CSR_MODE_MEDIUMRATE,             /*!< Comparator medium rate mode */
    COMP_Mode_LowPower                  = COMP_CSR_MODE_LOWPOWER,               /*!< Comparator low power mode */
    COMP_Mode_UltraLowPower             = COMP_CSR_MODE_LOWESTPOWER             /*!< Comparator lowest power mode */
} EM_COMP_Mode;

/**
  * @brief COMP_OutputLevel
  */
typedef enum {
    COMP_OutputLevel_High               = 0x00000001,                           /*!< High output */
    COMP_OutputLevel_Low                = 0x00000000                            /*!< Low output */
} EM_COMP_OutputLevel;

/**
  * @brief  COMP Init structure definition
  */
typedef struct {
    union {
        uint32_t COMP_InvertingInput;
        uint32_t Invert;                                                        /*!< Selects the inverting input of the comparator. */
    };
    union {
        uint32_t COMP_NonInvertingInput;
        uint32_t NonInvert;                                                     /*!< Selects the non inverting input of the comparator. */
    };
    union {
        uint32_t COMP_Output;
        uint32_t Output;                                                        /*!< Selects the output redirection of the comparator. */
        uint32_t BlankingSrce;                                                  /*!< Selects the output blanking source of the comparator. */
    };
    union {
        uint32_t COMP_OutputPol;
        uint32_t OutputPol;                                                     /*!< Selects the output polarity of the comparator. */
    };
    union {
        uint32_t COMP_Hysteresis;
        uint32_t Hysteresis;                                                    /*!< Selects the hysteresis voltage of the comparator. */
    };
    union {
        uint32_t COMP_Mode;
        uint32_t Mode;                                                          /*!< Selects the operating mode of the comparator and allows */
    };
    union {
        uint32_t COMP_Filter;
        uint32_t OFLT;                                                          /*!< to adjust the speed/consumption. */
    };
} COMP_InitTypeDef;

typedef struct {
    uint32_t COMP_Poll_En;                                                      /*!< Selects the inverting input of the comparator. */

    uint32_t COMP_Poll_Ch;                                                      /*!< Selects the non inverting input of the comparator. */
    uint32_t COMP_Poll_Fixn;                                                    /*!< Selects the output redirection of the comparator. */
    uint32_t COMP_Poll_Period;                                                  /*!< Selects the output polarity of the comparator. */
  /* uint32_t COMP_Poll_Pout; */                                                /*!< Selects the hysteresis voltage of the comparator. */
} COMP_POLL_InitTypeDef;

/**
  * @}
  */

/**
  ******************************************************************************
  * @defgroup COMP_Exported_Constants
  * @{
  ******************************************************************************
  * @brief  COMP Init structure definition
  ******************************************************************************
  */
typedef enum {
    COMP1                               = (0x000000),                           /*!< Select comparator 1 */
    COMP2                               = (0x000004)                            /*!< Select comparator 2 */
} COMP_Selection_TypeDef;


/**
  *   --------------------------------------------
  *   |                 |                | COMP1 |
  *   |-----------------+----------------+-------|
  *   |                 |INM0            |  PA5  |
  *   | Inverting Input |INM1            |  PA6  |
  *   |    (INM)        |INM2            |  PA7  |
  *   |                 |INM3            |  PD6  |
  *   |                 |INM4            |  CRV  |
  *   |-----------------+----------------+-------|
  *   |  Non Inverting  |INP0            |  PA1  |
  *   |    Input        |INP1            |  PA2  |
  *   |    (INP)        |INP2            |  PA3  |
  *   |                 |INP3            |  PA4  |
  *   |-----------------+----------------+-------+
  *   |                 |OUT             |  PA0  |
  *   |    Push Pull    |OUT             |  PA6  |
  *   |    (Output)     |OUT             |  PA11 |
  *   --------------------------------------------
  */

#define COMP1_CSR_INM0_PA5              COMP_CSR_INM_SEL_0
#define COMP1_CSR_INM1_PA6              COMP_CSR_INM_SEL_1
#define COMP1_CSR_INM2_PA7              COMP_CSR_INM_SEL_2
#define COMP1_CSR_INM3_PD6              COMP_CSR_INM_SEL_3
#define COMP1_CSR_INM4_CRV              COMP_CSR_INM_SEL_4
#define COMP1_CSR_INM_CRV               COMP_CSR_INM_SEL_4

#define COMP1_CSR_INP0_PA1              COMP_CSR_INP_SEL_0
#define COMP1_CSR_INP1_PA2              COMP_CSR_INP_SEL_1
#define COMP1_CSR_INP2_PA3              COMP_CSR_INP_SEL_2
#define COMP1_CSR_INP3_PA4              COMP_CSR_INP_SEL_3

#define COMP_BlankingSrce_None          ((uint32_t)0x00000000)
#define COMP_CSR_CLEAR_MASK             ((uint32_t)0x00000003)

#define COMP_CSR_COMPSW1                ((uint32_t)0x00000002)

/**
  * @}
  */

/** @defgroup COMP_Exported_Variables
  * @{
  */
#ifdef _HAL_COMP_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL
/**
  * @}
  */

/** @defgroup COMP_Exported_Functions
  * @{
  */

void COMP_DeInit(COMP_Selection_TypeDef selection);
void COMP_Init(COMP_Selection_TypeDef selection, COMP_InitTypeDef* init_struct);
void COMP_StructInit(COMP_InitTypeDef* init_struct);
void COMP_Cmd(COMP_Selection_TypeDef selection, FunctionalState state);
void COMP_SwitchCmd(COMP_Selection_TypeDef selection, FunctionalState state);
void COMP_LockConfig(COMP_Selection_TypeDef selection);

uint32_t COMP_GetOutputLevel(COMP_Selection_TypeDef selection);

void COMP_SetCrv(uint8_t crv_select, uint8_t crv_level);
#define SET_COMP_CRV COMP_SetCrv

void COMP_POLL_Init(COMP_Selection_TypeDef selection, COMP_POLL_InitTypeDef* poll_init_struct);

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
#endif/* __HAL_COMP_H --------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
