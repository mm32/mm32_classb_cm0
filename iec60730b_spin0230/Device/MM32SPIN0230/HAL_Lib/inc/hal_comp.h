/***********************************************************************************************************************
    @file     hal_comp.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE COMP
              FIRMWARE LIBRARY.
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
#ifndef __HAL_COMP_H
#define __HAL_COMP_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup COMP_HAL
  * @brief COMP HAL modules
  * @{
  */

/** @defgroup COMP_Exported_Types
  * @{
  */


/**
  * @brief  COMP Init structure definition
  */
typedef struct
{
    uint32_t COMP_Invert;                   /*!< Selects the inverting input of the comparator. */
    uint32_t COMP_NonInvert;                /*!< Selects the non inverting input of the comparator. */
    uint32_t COMP_Output;                   /*!< Selects the output redirection of the comparator. */
    uint32_t COMP_OutputPol;                /*!< Selects the output polarity of the comparator. */
    uint32_t COMP_Hysteresis;               /*!< Selects the hysteresis voltage of the comparator. */
    uint32_t COMP_Mode;                     /*!< Selects the operating mode of the comparator and allows */
    uint32_t COMP_OutAnaSel; 			   /*!< Selects the output source of the comparator */
    uint32_t COMP_OFLT;                     /*!< Comparator Output Filter Period */
} COMP_InitTypeDef;

/**
  * @brief  COMP POLL Init structure definition
  */
typedef struct
{
    uint32_t  COMP_Poll_Ch;             /*!< Selects the comparator polling channel. */
    uint32_t  COMP_Poll_Fixn;           /*!< Polling inverting input fix. */
    uint32_t  COMP_Poll_Period;         /*!< Selects the polling wait cycle. */
} COMP_POLL_InitTypeDef;


/**
  * @brief COMP_InvertingInput
  */
#define COMP_InvertingInput_0        (0x00U << COMP_CSR_INM_SEL_Pos) /*!< INM0 as COMP inverting input */
#define COMP_InvertingInput_1        (0x01U << COMP_CSR_INM_SEL_Pos) /*!< INM1 as COMP inverting input */
#define COMP_InvertingInput_2        (0x02U << COMP_CSR_INM_SEL_Pos) /*!< INM2 as COMP inverting input */
#define COMP_InvertingInput_3        (0x03U << COMP_CSR_INM_SEL_Pos) /*!< INM3 as COMP inverting input */

/**
  * @brief COMP_NonInvertingInput
  */
#define COMP_NonInvertingInput_0     (0x00U << COMP_CSR_INP_SEL_Pos)/*!< INP0 as COMP non-inverting input */
#define COMP_NonInvertingInput_1     (0x01U << COMP_CSR_INP_SEL_Pos)/*!< INP1 as COMP non-inverting input */
#define COMP_NonInvertingInput_2     (0x02U << COMP_CSR_INP_SEL_Pos)/*!< INP2 as COMP non-inverting input */
#define COMP_NonInvertingInput_3     (0x03U << COMP_CSR_INP_SEL_Pos)/*!< INP3 as COMP non-inverting input */


/**
  * @brief COMP_Output
  */
#define COMP_Output_None               (0x00U << COMP_CSR_OUT_SEL_Pos)/*!< No output */
#define COMP_Output_TIM1BKIN           (0x02U << COMP_CSR_OUT_SEL_Pos)/*!< Timer1 brake input */
#define COMP_Output_TIM1OCREFCLR       (0x06U << COMP_CSR_OUT_SEL_Pos)/*!< Timer1 ocrefclear input */
#define COMP_Output_TIM2IC4            (0x08U << COMP_CSR_OUT_SEL_Pos)/*!< Timer2 input capture 4 */
#define COMP_Output_TIM2OCREFCLR       (0x09U << COMP_CSR_OUT_SEL_Pos)/*!< Timer2 ocrefclear input */
#define COMP_Output_TIM2IC1            (0x0CU << COMP_CSR_OUT_SEL_Pos)/*!< Timer2 input capture 1  */
#define COMP_Output_TIM13IC1           (0x0DU << COMP_CSR_OUT_SEL_Pos)/*!< Timer13 input capture 1 */
#define COMP_Output_TIM14IC1           (0x0EU << COMP_CSR_OUT_SEL_Pos)/*!< Timer14 input capture 1  */

/**
  * @brief COMP_OutputPoloarity
  */
#define COMP_Pol_NonInvertedOut         (0x00U << COMP_CSR_POL_Pos) /*!< COMP non-inverting output */
#define COMP_Pol_InvertedOut            (0x01U << COMP_CSR_POL_Pos) /*!< COMP inverting output */



/**
  * @brief COMP_Hysteresis
  */
#define COMP_Hysteresis_No              (0x00U << COMP_CSR_HYST_Pos)/*!< COMP_Hysteresis_No */
#define COMP_Hysteresis_Low             (0x01U << COMP_CSR_HYST_Pos)/*!< COMP_Hysteresis_Low */
#define COMP_Hysteresis_Medium          (0x02U << COMP_CSR_HYST_Pos)/*!< COMP_Hysteresis_Medium */
#define COMP_Hysteresis_High            (0x03U << COMP_CSR_HYST_Pos)/*!< COMP_Hysteresis_High */

/**
  * @brief COMP_Mode
  */
#define COMP_Mode_HighPower             (0x00U << COMP_CSR_MODE_Pos)  /*!< Comparator high power mode */
#define COMP_Mode_MediumPower           (0x01U << COMP_CSR_MODE_Pos)  /*!< Comparator medium power mode */
#define COMP_Mode_LowPower              (0x02U << COMP_CSR_MODE_Pos)  /*!< Comparator low power mode */
#define COMP_Mode_VeryLowPower          (0x03U << COMP_CSR_MODE_Pos)  /*!< Comparator very low power mode */

/**
  * @brief COMP_OutAnaSel
  */
#define COMP_AnalogOutput_Sync          (0x00U << COMP_CSR_OUT_ANA_SEL_Pos) /*!<  Select a synchronized analog output signal */
#define COMP_AnalogOutput               (0x01U << COMP_CSR_OUT_ANA_SEL_Pos)/*!<  Select the analog output signal */



#define COMP_Filter_0_Period            (0x00U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x00000000) */
#define COMP_Filter_2_Period            (0x01U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x00040000) */
#define COMP_Filter_4_Period            (0x02U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x00080000) */
#define COMP_Filter_8_Period            (0x03U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x000C0000) */
#define COMP_Filter_16_Period           (0x04U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x00100000) */
#define COMP_Filter_32_Period           (0x05U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x00140000) */
#define COMP_Filter_64_Period           (0x06U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x00180000) */
#define COMP_Filter_128_Period          (0x07U << COMP_CSR_OFLT_Pos)/*!< filter is ((uint32_t)0x001C0000) */


/**
  * @brief COMP_OutputLevel
  */
#define COMP_OutputLevel_High            ((uint32_t)0x00000001) /*!<  High output */
#define COMP_OutputLevel_Low             ((uint32_t)0x00000000) /*!<  Low output */


/**
  * @brief COMP_CRV_SRC_Sel
  */
#define COMP_CRV_SRC_VREFINT             (0x00U << COMP_CRV_SRC_Pos)/*!<  Select VREFINT 1/20 as CRV source  */
#define COMP_CRV_SRC_VDDA                (0x01U << COMP_CRV_SRC_Pos)/*!<  Select VDDA as CRV source */


/**
  * @brief COMP_PollChannelSel
  */
#define COMP_POLL_1_2                    (0x00U << COMP_POLL_CH_Pos)/*!< Selects the polling channel 1/2. */
#define COMP_POLL_1_2_3                  (0x01U << COMP_POLL_CH_Pos)/*!< Selects the polling channel 1/2/3. */


/**
  * @brief COMP_PollInputFix
  */
#define COMP_POLL_INPUT_FIXN             (0x00U << COMP_POLL_FIXN_Pos) /*!< Polling inverting input is unfixed. */ 
#define COMP_POLL_INPUT_FIX              (0x01U << COMP_POLL_FIXN_Pos) /*!< Polling inverting input is fixed. */


/**
  * @brief COMP_PollWaitCycle
  */
#define COMP_POLL_WAIT_1                 (0x00U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 1 Cycles. */
#define COMP_POLL_WAIT_2                 (0x01U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 2 Cycles. */
#define COMP_POLL_WAIT_4                 (0x02U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 4 Cycles. */
#define COMP_POLL_WAIT_8                 (0x03U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 8 Cycles. */
#define COMP_POLL_WAIT_16                (0x04U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 16 Cycles. */
#define COMP_POLL_WAIT_32                (0x05U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 32 Cycles. */
#define COMP_POLL_WAIT_64                (0x06U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 64 Cycles. */
#define COMP_POLL_WAIT_128               (0x07U << COMP_POLL_PERIOD_Pos)/*!< Polling wait 128 Cycles. */



/** @defgroup COMP_Exported_Functions
  * @{
  */

void COMP_DeInit(COMP_TypeDef *comp);
void COMP_StructInit(COMP_InitTypeDef *init_struct);
void COMP_Init(COMP_TypeDef *comp, COMP_InitTypeDef *init_struct);
void COMP_Cmd(COMP_TypeDef *comp, FunctionalState state);
void COMP_LockConfig(COMP_TypeDef *comp);
uint32_t COMP_GetOutputLevel(COMP_TypeDef *comp);
void COMP_SetCrv(uint32_t crv_source, uint32_t crv_level);
void COMP_CrvCmd(FunctionalState state);
void COMP_PollStructInit(COMP_POLL_InitTypeDef *init_struct);
void COMP_PollInit(COMP_TypeDef *comp, COMP_POLL_InitTypeDef * poll_init_struct);
void COMP_PollCmd(COMP_TypeDef *comp, FunctionalState state);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/** --------------------------------------------------------------------------*/
#endif /* __HAL_COMP_H--------------------------------------------------------*/
/** --------------------------------------------------------------------------*/


