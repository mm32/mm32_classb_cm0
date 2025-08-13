/*
 *******************************************************************************
    @file     hal_ver.h
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
#ifndef __HAL_VER_H
#define __HAL_VER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup VER_HAL
  * @brief VER HAL modules
  * @{
  */

/** @defgroup VER_Exported_Types
  * @{
  */

/**
  * @brief VER Word Length Enumerate definition
  * @anchor VER_Word_Length
  */

/**
  * @}
  */


/** @defgroup VER_Exported_Constants
  * @{
  */

/**
  * @}
  */

/**
  * @defgroup VER_Exported_Variables
  * @{
  */
#ifdef _HAL_VER_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL
/**
  * @}
  */


/** @defgroup VER_Exported_Functions
  * @{
  */
uint32_t Get_MM32LibVersion(void);
uint32_t Get_MM32LibReleaseDate(void);
uint32_t Get_ChipsetREVID(void);
uint32_t Get_ChipsetDEVID(void);
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
#endif/* __HAL_VER_H ---------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
