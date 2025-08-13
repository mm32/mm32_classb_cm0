/*
 *******************************************************************************
    @file     reg_hwdic.h
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

#ifndef __REG_HWDIV_H
#define __REG_HWDIV_H

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
  * @brief HWDIV Base Address Definition
  */
#define HWDIV_BASE                      (AHBPERIPH_BASE + 0x00010000)           /*!< Base Address: 0x40030000 */

/**
  * @brief HWDIV Register Structure Definition
  */
typedef struct {
    __IO uint32_t DVDR;                                                         /*!< Divider data register,             offset: 0x00 */
    __IO uint32_t DVSR;                                                         /*!< Divisor register,                  offset: 0x04 */
    __IO uint32_t QUOTR;                                                        /*!< Quotient register,                 offset: 0x08 */
    __IO uint32_t RMDR;                                                         /*!< Remainder register,                offset: 0x0C */
    __IO uint32_t SR;                                                           /*!< Status register,                   offset: 0x10 */
    __IO uint32_t CR;                                                           /*!< Control register,                  offset: 0x14 */
} HWDIV_TypeDef;

/**
  * @brief HWDIV type pointer Definition
  */
#define HWDIV                           ((HWDIV_TypeDef*) HWDIV_BASE)

/**
  * @brief HWDIV_DVDR Register Bit Definition
  */
#define HWDIV_DVDR_DIVIDEND_Pos         (0)
#define HWDIV_DVDR_DIVIDEND             (0xFFFFFFFFU << HWDIV_DVDR_DIVIDEND_Pos)/*!< Dividend data register */

/**
  * @brief HWDIV_DVSR Register Bit Definition
  */
#define HWDIV_DVSR_DIVISOR_Pos          (0)
#define HWDIV_DVSR_DIVISOR              (0xFFFFFFFFU << HWDIV_DVSR_DIVISOR_Pos) /*!< Divisor data register */

/**
  * @brief HWDIV_QUOTR Register Bit Definition
  */
#define HWDIV_QUOTR_QUOTIENT_Pos        (0)
#define HWDIV_QUOTR_QUOTIENT            (0xFFFFFFFFU << HWDIV_QUOTR_QUOTIENT_Pos) /*!< Quotient data register */

/**
  * @brief HWDIV_RMDR Register Bit Definition
  */
#define HWDIV_RMDR_REMAINDER_Pos        (0)
#define HWDIV_RMDR_REMAINDER            (0xFFFFFFFFU << HWDIV_RMDR_REMAINDER_Pos) /*!< Remainder data register */

/**
  * @brief HWDIV_SR Register Bit Definition
  */
#define HWDIV_SR_OVF_Pos                (0)
#define HWDIV_SR_OVF                    (0x01U << HWDIV_SR_OVF_Pos)             /*!< Overflow state bit */

/**
  * @brief HWDIV_CR Register Bit Definition
  */
#define HWDIV_CR_USIGN_Pos              (0)
#define HWDIV_CR_USIGN                  (0x01U << HWDIV_CR_USIGN_Pos)           /*!< Unsigned enable */
#define HWDIV_CR_OVFE_Pos               (1)
#define HWDIV_CR_OVFE                   (0x01U << HWDIV_CR_OVFE_Pos)            /*!< Overflow interruput enable */

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
#endif
/*----------------------------------------------------------------------------*/
