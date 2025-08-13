/***********************************************************************************************************************
    @file     hal_opamp.c
	  @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE OPAMP
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
#define _HAL_OPAMP_C

/* Files includes ------------------------------------------------------------*/
#include "hal_opamp.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup OPAMP_HAL
  * @{
  */

/** @addtogroup OPAMP_Exported_Functions
  * @{
  */


/**
  * @brief  Enables or disables the specified OPAMP peripheral.
  * @param  opamp: select the opamp peripheral.
  * @param  state: new state of the OPAMP peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void OPAMP_Cmd(OPAMP_TypeDef* opamp, FunctionalState state)
{
    (state) ? \
    (opamp->CR |=  (0x01U << OPAMP_CR_OPAEN_Pos)) : \
    (opamp->CR &= ~(0x01U << OPAMP_CR_OPAEN_Pos));
}

/**
  * @brief  Select OPAMP peripheral performance mode.
  * @param  opamp: select the opamp peripheral.
  * @param  opamode: OPAMP peripheral performance mode.
  *     @arg   OPAMP_Mode_HighPerformance  
  *     @arg   OPAMP_Mode_LowPower  
  * @retval None.
  */
void OPAMP_ModeConfig(OPAMP_TypeDef* opamp, uint32_t opamode)
{
    MODIFY_REG(opamp->CR, OPAMP_CR_OPAMSEL_Msk, opamode); 
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
