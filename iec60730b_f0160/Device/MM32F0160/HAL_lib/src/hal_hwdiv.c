/*
 *******************************************************************************
    @file     hal_hwdiv.c
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
  * @brief  Hardware divider unsigned mode initial.
  * @param  usign: Unsigned enable
  * @param  zero: Overflow interrupt enable
  * @retval None.
  */
void HWDIV_Init(bool usign, bool zero)
{
    HWDIV->CR = (usign ? HWDIV_CR_USIGN : 0) | (zero ? HWDIV_CR_OVFE : 0);
}

/**
  * @brief  Calculate by hardware
  * @param  dvd: Dividend data
  * @param  dvs: Divisor data
  * @retval HWDIV->QUOTR
  */
s32 HWDIV_Calc(uint32_t dvd, uint32_t dvs)
{
    HWDIV->DVDR = dvd;
    HWDIV->DVSR = dvs;

    /* overflow */
    if (HWDIV->SR & HWDIV_SR_OVF) {
        return 0xffffffff;
    }
    return HWDIV->QUOTR;
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

