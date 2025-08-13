/***********************************************************************************************************************
    @file     reg_opamp.h
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

#ifndef __REG_OPAMP_H
#define __REG_OPAMP_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif

/**
  * @brief OPAMP Base Address Definition
  */
#define OPAMP1_BASE        (APB1PERIPH_BASE + 0x9000)              /*!< Base Address:  */
#define OPAMP2_BASE        (APB1PERIPH_BASE + 0x9400)              /*!< Base Address:  */

/**
  * @brief Operational Amplifier Registers Structure Definition
  */
typedef struct 
{
    __IO uint32_t CR;                                                           /*!< OPAMP Control Status Register                  Offset: 0x00 */
} OPAMP_TypeDef;

/**
  * @brief OPA type pointer Definition
  */
#define OPAMP1                           ((OPAMP_TypeDef*) OPAMP1_BASE)
#define OPAMP2                           ((OPAMP_TypeDef*) OPAMP2_BASE)
/**
  * @brief OPAMP_CR Register Bit Definition
  */
#define OPAMP_CR_OPAEN_Pos              (0)
#define OPAMP_CR_OPAEN_Msk              (0x01U << OPAMP_CR_OPAEN_Pos)            /*!< OPA ENABLE */
#define OPAMP_CR_OPAMSEL_Pos            (1)
#define OPAMP_CR_OPAMSEL_Msk            (0x01U << OPAMP_CR_OPAMSEL_Pos)         /*!< OPA MODE SELECT */

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

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/
