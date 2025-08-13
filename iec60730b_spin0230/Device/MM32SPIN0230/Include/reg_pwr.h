/***********************************************************************************************************************
    @file     reg_pwr.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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

#ifndef __REG_PWR_H
#define __REG_PWR_H

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
  * @brief PWR Base Address Definition
  */
#define PWR_BASE                        (APB1PERIPH_BASE + 0x7000) /*!< Base Address: 0x40007000 */

/**
  * @brief PWR Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                   /*!< Control register,                              offset: 0x00 */
    __IO uint32_t CSR;                  /*!< Control Status register                        offset: 0x04 */
    __IO uint32_t RESERVED0x08[7];      /*!< Reserved,                                      offset: 0x08~0x20 */
    __IO uint32_t CFGR;                 /*!< Configuration register                         offset: 0x24 */
    __IO uint32_t RESERVED0x28[2];      /*!< Reserved,                                      offset: 0x28~0x2C */
    __IO uint32_t MEMCR;                /*!< Power store control register                   offset: 0x30 */
} PWR_TypeDef;

/**
  * @brief PWR type pointer Definition
  */
#define PWR                                 ((PWR_TypeDef *)PWR_BASE)

/**
  * @brief PWR_CR register Bit definition
  */
#define PWR_CR_PVDE_Pos                     (4)
#define PWR_CR_PVDE                         (0x01U << PWR_CR_PVDE_Pos)      /*!< Power Voltage Detector Enable */

#define PWR_CR_PLS_Pos                      (9)
#define PWR_CR_PLS_Msk                      (0x0FU << PWR_CR_PLS_Pos)
#define PWR_CR_PLS_1V8                      (0x00U << PWR_CR_PLS_Pos)       /*!< PVD level 1.8V */
#define PWR_CR_PLS_2V1                      (0x01U << PWR_CR_PLS_Pos)       /*!< PVD level 2.1V */
#define PWR_CR_PLS_2V4                      (0x02U << PWR_CR_PLS_Pos)       /*!< PVD level 2.4V */
#define PWR_CR_PLS_2V7                      (0x03U << PWR_CR_PLS_Pos)       /*!< PVD level 2.7V */
#define PWR_CR_PLS_3V0                      (0x04U << PWR_CR_PLS_Pos)       /*!< PVD level 3.0V */
#define PWR_CR_PLS_3V3                      (0x05U << PWR_CR_PLS_Pos)       /*!< PVD level 3.3V */
#define PWR_CR_PLS_3V6                      (0x06U << PWR_CR_PLS_Pos)       /*!< PVD level 3.6V */
#define PWR_CR_PLS_3V9                      (0x07U << PWR_CR_PLS_Pos)       /*!< PVD level 3.9V */
#define PWR_CR_PLS_4V2                      (0x08U << PWR_CR_PLS_Pos)       /*!< PVD level 4.2V */
#define PWR_CR_PLS_4V5                      (0x09U << PWR_CR_PLS_Pos)       /*!< PVD level 4.5V */
#define PWR_CR_PLS_4V8                      (0x0AU << PWR_CR_PLS_Pos)       /*!< PVD level 4.8V */

/**
  * @brief PWR_CSR register Bit definition
  */
#define PWR_CSR_PVDO_Pos                    (2)
#define PWR_CSR_PVDO                        (0x01U << PWR_CSR_PVDO_Pos)                /*!< PVD Output */

/**
  * @brief PWR_CFGR register Bit definition
  */
#define PWR_CFGR_LSICALSEL_Pos              (0)
#define PWR_CFGR_LSICALSEL                  (0x1FU << PWR_CFGR_LSICALSEL_Pos)          /*!< Enable internal clock calibration  */
#define PWR_CFGR_LSICAL_Pos                 (5)
#define PWR_CFGR_LSICAL                     (0x1FU << PWR_CFGR_LSICAL_Pos)             /*!< Internal high-speed clock calibration */

/**
  * @brief PWR_MEMCR register Bit definition
  */
#define PWR_MEMCR_MEM_LOCK_Pos          (0)
#define PWR_MEMCR_MEM_LOCK              (0x1FU << PWR_MEMCR_MEM_LOCK_Pos)       /*!< PWR_MEMCR Configures the lock */
#define PWR_MEMCR_FWUP_EN_Pos           (5)
#define PWR_MEMCR_FWUP_EN               (0x01U << PWR_MEMCR_FWUP_EN_Pos)        /*!< The Flash quick wake up function was enabled */
#define PWR_MEMCR_FDP_EN_Pos            (6)
#define PWR_MEMCR_FDP_EN                (0x01U << PWR_MEMCR_FDP_EN_Pos)         /*!< Flash DeepStandby is enabled in STOP mode */

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
/** --------------------------------------------------------------------------*/

