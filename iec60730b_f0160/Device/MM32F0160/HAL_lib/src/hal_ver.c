/*
 *******************************************************************************
    @file     hal_ver.c
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
#define _HAL_VER_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_ver.h"

/* MM32 Library version is 1.2 -----------------------------------------------*/

#define __MM32_LIB_VERSION_MAIN         (0x01U)                                 /*!< [15:8] main version */
#define __MM32_LIB_VERSION_SUB          (0x02U)                                 /*!< [7:0] sub version */
#define __MM32_LIB_VERSION              ((__MM32_LIB_VERSION_MAIN << 8U)\
                                        |(__MM32_LIB_VERSION_SUB  << 0U))

/* MM32 Library release date is 2023-11-16 (YYYY-MM-DD) ----------------------*/
#define __MM32_LIB_RELESE_YEARH         (0x20U)                                 /*!< [31:24] release year high */
#define __MM32_LIB_RELESE_YEARL         (0x23U)                                 /*!< [23:16] release year low */
#define __MM32_LIB_RELESE_MONTH         (0x11U)                                 /*!< [15:8]  release month */
#define __MM32_LIB_RELESE_DAY           (0x16U)                                 /*!< [7:0]   release day */
#define __MM32_LIB_RELESE_DATE          ((__MM32_LIB_RELESE_YEARH << 24U)\
                                        |(__MM32_LIB_RELESE_YEARL << 16U)\
                                        |(__MM32_LIB_RELESE_MONTH << 8U )\
                                        |(__MM32_LIB_RELESE_DAY))

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup VER_HAL
  * @{
  */

/** @addtogroup Lib and chipset_Exported_Functions
  * @{
  */

/**
  * @brief  This method returns the Lib revision.
  * @param  None.
  * @retval return the Lib version.
  */
uint32_t Get_MM32LibVersion(void)
{
    return __MM32_LIB_VERSION;
}

/**
  * @brief  This method returns the Lib release date.
  * @param  None.
  * @retval return the Lib release date.
  */
uint32_t Get_MM32LibReleaseDate(void)
{
    return __MM32_LIB_RELESE_DATE;
}

/**
  * @brief  Returns the device revision identifier.
  * @param  None.
  * @retval return the device revision identifier.
  */
uint32_t Get_ChipsetREVID(void)
{
    return (uint32_t)(DBGMCU->IDCODE) & 0xF ;
}

/**
  * @brief  Returns the device identifier..
  * @param  None.
  * @retval return the device Device identifier.
  */
uint32_t Get_ChipsetDEVID(void)
{
    return (uint32_t)DBGMCU->IDCODE;
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
