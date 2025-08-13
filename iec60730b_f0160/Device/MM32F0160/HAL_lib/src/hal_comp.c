/*
 *******************************************************************************
    @file     hal_comp.c
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


/* Files includes ------------------------------------------------------------*/
#include "hal_comp.h"


/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup COMP_HAL
  * @{
  */

/** @addtogroup COMP_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes COMP peripheral registers to their default reset
  *         values.
  * @param  selection: the selected comparator.
  *         select the COMP peripheral.
  * @retval None.
  */
void COMP_DeInit(COMP_Selection_TypeDef selection)
{
    *(__IO uint32_t*)(COMP_BASE + selection) = 0;
}

/**
  * @brief  Initializes the COMP peripheral according to the specified
  * @param  selection: the selected comparator.
  *         select the COMP peripheral.
  * @param  init_struct: pointer to an COMP_InitTypeDef structure that
  *         contains the configuration information for the specified COMP
  *         peripheral.
  *         - COMP_InvertingInput specifies the inverting input of COMP
  *         - COMP_NonInvertingInput specifies the non inverting input of COMP
  *         - COMP_Output connect COMP output to selected timer
  *           input (Input capture / Output Compare Reference Clear / Break
  *           Input)
  *         - COMP_BlankingSrce specifies the blanking source of COMP
  *         - COMP_OutputPol select output polarity
  *         - COMP_Hysteresis configures COMP hysteresis value
  *         - COMP_Mode configures COMP power mode
  * @retval None.
  */
void COMP_Init(COMP_Selection_TypeDef selection, COMP_InitTypeDef* init_struct)
{
    *(__IO uint32_t*)(COMP_BASE + selection) =    init_struct->Invert     |
                                         init_struct->NonInvert  |
                                         init_struct->Output     |
                                         init_struct->OutputPol  |
                                         init_struct->BlankingSrce   |
                                         init_struct->Hysteresis |
                                         init_struct->Mode       |
                                         init_struct->OFLT;
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to an COMP_InitTypeDef structure which will
  *         be initialized.
  * @retval None.
  */
void COMP_StructInit(COMP_InitTypeDef* init_struct)
{

    init_struct->Invert         = COMP_InvertingInput_IO1;
    init_struct->NonInvert      = COMP_NonInvertingInput_IO1;
    init_struct->Output         = COMP_Output_None;
    init_struct->BlankingSrce   = COMP_BlankingSrce_None;
    init_struct->OutputPol      = COMP_NonInverted;
    init_struct->Hysteresis     = COMP_Hysteresis_No;
    init_struct->Mode           = COMP_Mode_UltraLowPower;
    init_struct->OFLT           = COMP_Filter_4_Period;                         /*!< to adjust the speed/consumption. */
}

/**
  * @brief  Enable or disable the COMP peripheral.
  * @param  selection: the selected comparator.
  *         select the COMP peripheral.
  * @param  NewState: new state of the COMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  *         When enabled, the comparator compares the non inverting input with
  *         the inverting input and the comparison result is available on
  *         comparator output.
  *         When disabled, the comparator doesn't perform comparison and the
  *         output level is low.
  * @retval None.
  */
void COMP_Cmd(COMP_Selection_TypeDef selection, FunctionalState state)
{
    (state) ? (*(__IO uint32_t*)(COMP_BASE + selection) |=  COMP_CSR_EN) :
    (*(__IO uint32_t*)(COMP_BASE + selection) &= ~COMP_CSR_EN);
}

/**
  * @brief  Select COMP_CRV param.
  * @param  crv_select: Select source for COMP_CRV.
  * @param  crv_level: Set level for COMP_CRV.
  * @retval None.
  */
void COMP_SetCrv(uint8_t crv_select, uint8_t crv_level)
{
    uint32_t temreg = 0;
    temreg = COMP->COMP_CRV;
    temreg &= ~COMP_CRV_SEL;
    /* Load config to COMP_CRV and enable */
    temreg |= crv_select | crv_level | (1 << 4);
    COMP->COMP_CRV = temreg;
}

/**
  * @brief  Close or Open the SW1 switch.
  * @param  selection: the selected comparator.
  *         select the COMP peripheral.
  * @param  state: new state of the COMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  *         When enabled, the comparator compares the non inverting input with
  *         the inverting input and the comparison result is available on
  *         comparator output.
  *         When disabled, the comparator doesn't perform comparison and the
  *         output level is low.
  * @retval None.
  */
void COMP_SwitchCmd(COMP_Selection_TypeDef selection, FunctionalState state)
{
    (state) ?
    (*(__IO uint32_t*)(COMP_BASE + selection) |=  COMP_CSR_COMPSW1) :
    (*(__IO uint32_t*)(COMP_BASE + selection) &= ~COMP_CSR_COMPSW1);
}

/**
  * @brief  Return the output level (high or low) of the selected comparator.
  *         The output level depends on the selected polarity.
  *         If the polarity is not inverted:
  *           - Comparator output is low when the non-inverting input is at a
  *           lower voltage than the inverting input
  *           - Comparator output is high when the non-inverting input is at a
  *           higher voltage than the inverting input
  *         If the polarity is inverted:
  *           - Comparator output is high when the non-inverting input is at a
  *           lower voltage than the inverting input
  *           - Comparator output is low when the non-inverting input is at a
  *           higher voltage than the inverting input
  * @param  comp: the selected comparator.
  *         select the COMP peripheral.
  * @retval  The selected comparator output level: low or high.
  */
uint32_t COMP_GetOutputLevel(COMP_Selection_TypeDef selection)
{
    return (((*(__IO uint32_t*)(COMP_BASE + selection) & COMP_CSR_OUT) != 0) ?
            COMP_OutputLevel_High :
            COMP_OutputLevel_Low );
}

/**
  * @brief  Lock the selected comparator (COMP1/COMP2) configuration.
  * @param  selection: the selected comparator.
  *         select the COMP peripheral.
  * @retval None.
  */
void COMP_LockConfig(COMP_Selection_TypeDef selection)
{
    *(__IO uint32_t*)(COMP_BASE + selection) |= COMP_CSR_LOCK;
}

/**
  * @brief  Enable or disable the COMP register.
  * @param  state: new state of the COMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void exCOMP_CrvCmd(FunctionalState state)
{
    (state) ? (COMP->COMP_CRV |= COMP_CRV_EN_ENABLE) : (COMP->COMP_CRV &= ~COMP_CRV_EN_ENABLE);
}

/**
  * @brief  Select comparator external reference voltage.
  * @param  selection: the selected external reference voltage.
  * @retval None.
  */
void exCOMP_SwitchCrv(uint32_t crv)
{
    COMP->COMP_CRV |= crv;
}

/**
  * @brief  Select comparator external reference voltage source.
  * @param  selection: the selected external reference voltage source.
  *         This parameter can be: COMP_CRV_SRC_AVDD or COMP_CRV_SRC_VREF.
  * @retval None.
  */
void exCOMP_CrvSrc(uint32_t src)
{
    COMP->COMP_CRV |= src;
}

void COMP_POLL_Init(COMP_Selection_TypeDef selection, COMP_POLL_InitTypeDef* poll_init_struct)
{
    if(selection == COMP1) {
        COMP->COMP1_POLL = poll_init_struct->COMP_Poll_En     |
                           poll_init_struct->COMP_Poll_Period |
                           poll_init_struct->COMP_Poll_Ch     |
                           poll_init_struct->COMP_Poll_Fixn ;
    }
    else if(selection == COMP2) {
        COMP->COMP2_POLL = poll_init_struct->COMP_Poll_En     |
                           poll_init_struct->COMP_Poll_Period |
                           poll_init_struct->COMP_Poll_Ch     |
                           poll_init_struct->COMP_Poll_Fixn ;
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
