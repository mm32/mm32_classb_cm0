/***********************************************************************************************************************
    @file     hal_hwdiv.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE HWDIV FIRMWARE FUNCTIONS.
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
#define _HAL_HWDIV_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_hwdiv.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup HWDIV_HAL
  * @{
  */

/** @addtogroup HWDIV_Exported_Functions
  * @{
  */

/**
  * @brief  Hardware divider unsigned or signed config.
  * @param  usign: Select signed or unsigned.
  * @arg    HWDIV_Signed      Signed division 
  * @arg    HWDIV_UnSigned    Unsigned division 
  * @retval None.
  */
void HWDIV_UsignConfig(uint32_t usign)
{
    MODIFY_REG(HWDIV->CR, HWDIV_CR_USIGN, usign );  
}

/**
  * @brief  Hardware divider overflow interrupt enable.
  * @param  state: new state of the Hardware divider.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void HWDIV_ITConfig(FunctionalState state)
{ 
    (state) ? \
    (HWDIV->CR |=  (0x01U << HWDIV_CR_OVFE_Pos)) : \
    (HWDIV->CR &= ~(0x01U << HWDIV_CR_OVFE_Pos));
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

