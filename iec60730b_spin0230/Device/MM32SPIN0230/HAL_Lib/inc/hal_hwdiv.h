/***********************************************************************************************************************
    @file     hal_hwdiv.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE HWDIV
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
#ifndef __HAL_HWDIV_H
#define __HAL_HWDIV_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup HWDIV_HAL
  * @brief HWDIV HAL modules
  * @{
  */

/** @defgroup HWDIV_Exported_Types
  * @{
  */

/** @defgroup CRS_Exported_Constants
  * @{
  */

#define SET_DVDR(x)   (HWDIV->DVDR) = (x)
#define SET_DVSR(y)   (HWDIV->DVSR) = (y)
#define GET_QUOTR()   (HWDIV->QUOTR)
#define GET_RMDR()    (HWDIV->RMDR)


/**
  * @brief HWDIV_Sign_Typedef
  */
#define HWDIV_Signed      (0x00U << HWDIV_CR_USIGN_Pos)     /*!< Signed division */
#define HWDIV_UnSigned    (0x01U << HWDIV_CR_USIGN_Pos)     /*!< Unsigned division */


/**
  * @}
  */


void HWDIV_UsignConfig(uint32_t usign);
void HWDIV_ITConfig(FunctionalState state);


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
#endif /* __HAL_HWDIV_H ------------------------------------------------------*/
/** --------------------------------------------------------------------------*/

