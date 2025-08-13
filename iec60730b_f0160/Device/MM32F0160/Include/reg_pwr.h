/*
 *******************************************************************************
    @file     reg_pwr.h
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
#define PWR_BASE                        (APB1PERIPH_BASE + 0x7000)              /*!< Base Address: 0x40007000 */

/**
  * @brief PWR Register Structure Definition
  */
typedef struct {
    __IO uint32_t CR;                                                           /*!< Control register,                              offset: 0x00 */
    __IO uint32_t CSR;                                                          /*!< Control Status register                        offset: 0x04 */
    __IO uint32_t RESERVED0x08[1];                                              /*!< Reserved                                       offset: 0x08 */
    __IO uint32_t CR1;                                                          /*!< Control register  2                            offset: 0x0C */
    __IO uint32_t SR1;                                                          /*!< Status  register                               offset: 0x10 */
    __IO uint32_t SCR;                                                          /*!< clear status register                          offset: 0x14 */
    __IO uint32_t RESERVED0x18[3];                                              /*!< Reserved,                                      offset: 0x18 */
    __IO uint32_t CFGR;                                                         /*!< Configuration register                         offset: 0x24 */
} PWR_TypeDef;

/**
  * @brief PWR type pointer Definition
  */
#define PWR                             ((PWR_TypeDef*) PWR_BASE)

/**
  * @brief PWR_CR register Bit definition
  */
#define PWR_CR_LPDS_Pos                 (0)
#define PWR_CR_LPDS                     (0x01U << PWR_CR_LPDS_Pos)              /*!< Low power deepsleep */

#define PWR_CR_PDDS_Pos                 (1)
#define PWR_CR_PDDS                     (0x01U << PWR_CR_PDDS_Pos)              /*!< Power Down Deepsleep */

#define PWR_CR_CWUF_Pos                 (2)
#define PWR_CR_CWUF                     (0x01U << PWR_CR_CWUF_Pos)              /*!< Clear Standby Flag */

#define PWR_CR_CSBF_Pos                 (3)
#define PWR_CR_CSBF                     (0x01U << PWR_CR_CSBF_Pos)              /*!< Clear Standby Flag */

#define PWR_CR_PVDE_Pos                 (4)
#define PWR_CR_PVDE                     (0x01U << PWR_CR_PVDE_Pos)              /*!< Power Voltage Detector Enable */

#define PWR_CR_PLS_Pos                  (9)
#define PWR_CR_PLS                      (0x0FU  << PWR_CR_PLS_Pos)
#define PWR_CR_PLS_LEVEL0               (0x00U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  1.8v */
#define PWR_CR_PLS_LEVEL1               (0x01U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  2.1v */
#define PWR_CR_PLS_LEVEL2               (0x02U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  2.4v */
#define PWR_CR_PLS_LEVEL3               (0x03U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  2.7v */
#define PWR_CR_PLS_LEVEL4               (0x04U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  3.0v */
#define PWR_CR_PLS_LEVEL5               (0x05U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  3.3v */
#define PWR_CR_PLS_LEVEL6               (0x06U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  3.6v */
#define PWR_CR_PLS_LEVEL7               (0x07U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  3.9v */
#define PWR_CR_PLS_LEVEL8               (0x08U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  4.2v */
#define PWR_CR_PLS_LEVEL9               (0x09U  << PWR_CR_PLS_Pos)              /*!< PVD level selection  4.5v */
#define PWR_CR_PLS_LEVEL10              (0x0AU  << PWR_CR_PLS_Pos)              /*!< PVD level selection  4.8v */

/* legacy define */
#define PWR_CR_PLS_0                    PWR_CR_PLS_LEVEL0
#define PWR_CR_PLS_1                    PWR_CR_PLS_LEVEL1
#define PWR_CR_PLS_2                    PWR_CR_PLS_LEVEL2
#define PWR_CR_PLS_3                    PWR_CR_PLS_LEVEL3
#define PWR_CR_PLS_4                    PWR_CR_PLS_LEVEL4
#define PWR_CR_PLS_5                    PWR_CR_PLS_LEVEL5
#define PWR_CR_PLS_6                    PWR_CR_PLS_LEVEL6
#define PWR_CR_PLS_7                    PWR_CR_PLS_LEVEL7
#define PWR_CR_PLS_8                    PWR_CR_PLS_LEVEL8
#define PWR_CR_PLS_9                    PWR_CR_PLS_LEVEL9
#define PWR_CR_PLS_10                   PWR_CR_PLS_LEVEL10

#define PWR_CR_PLS_1V8                  PWR_CR_PLS_LEVEL0
#define PWR_CR_PLS_2V1                  PWR_CR_PLS_LEVEL1
#define PWR_CR_PLS_2V4                  PWR_CR_PLS_LEVEL2
#define PWR_CR_PLS_2V7                  PWR_CR_PLS_LEVEL3
#define PWR_CR_PLS_3V0                  PWR_CR_PLS_LEVEL4
#define PWR_CR_PLS_3V3                  PWR_CR_PLS_LEVEL5
#define PWR_CR_PLS_3V6                  PWR_CR_PLS_LEVEL6
#define PWR_CR_PLS_3V9                  PWR_CR_PLS_LEVEL7
#define PWR_CR_PLS_4V2                  PWR_CR_PLS_LEVEL8
#define PWR_CR_PLS_4V5                  PWR_CR_PLS_LEVEL9
#define PWR_CR_PLS_4V8                  PWR_CR_PLS_LEVEL10

#define PWR_CR_STDBYFSWK_FS_WK_Pos      (14)
#define PWR_CR_STDBYFSWK_FS_WK          (0x03U  << PWR_CR_STDBYFSWK_FS_WK_Pos)
#define PWR_CR_STDBYFSWK_FS_WK_0        (0x00U  << PWR_CR_STDBYFSWK_FS_WK_Pos)  /*!< 9 LSI40K cycles to wake up the standby */
#define PWR_CR_STDBYFSWK_FS_WK_1        (0x01U  << PWR_CR_STDBYFSWK_FS_WK_Pos)  /*!< 7 LSI40K cycles to wake up the standby */
#define PWR_CR_STDBYFSWK_FS_WK_2        (0x02U  << PWR_CR_STDBYFSWK_FS_WK_Pos)  /*!< 5 LSI40K cycles to wake up the standby */
#define PWR_CR_STDBYFSWK_FS_WK_3        (0x03U  << PWR_CR_STDBYFSWK_FS_WK_Pos)  /*!< 3 LSI40K cycles to wake up the standby */

/**
  * @brief PWR_CSR register Bit definition
  */
#define PWR_CSR_WUF_Pos                 (0)
#define PWR_CSR_WUF                     (0x01U << PWR_CSR_WUF_Pos)              /*!< Wakeup Flag */
#define PWR_CSR_SBF_Pos                 (1)
#define PWR_CSR_SBF                     (0x01U << PWR_CSR_SBF_Pos)              /*!< Standby Flag */
#define PWR_CSR_PVDO_Pos                (2)
#define PWR_CSR_PVDO                    (0x01U << PWR_CSR_PVDO_Pos)             /*!< PVD Output */
#define PWR_CSR_EWUP1_Pos               (8)
#define PWR_CSR_EWUP1                   (0x01U << PWR_CSR_EWUP1_Pos)            /*!< Enable WKUP1 pin */
#define PWR_CSR_EWUP2_Pos               (9)
#define PWR_CSR_EWUP2                   (0x01U << PWR_CSR_EWUP2_Pos)            /*!< Enable WKUP2 pin */

#define PWR_CSR_EWUP4_Pos               (11)
#define PWR_CSR_EWUP4                   (0x01U << PWR_CSR_EWUP4_Pos)            /*!< Enable WKUP4 pin */
#define PWR_CSR_EWUP5_Pos               (12)
#define PWR_CSR_EWUP5                   (0x01U << PWR_CSR_EWUP5_Pos)            /*!< Enable WKUP5 pin */
#define PWR_CSR_EWUP6_Pos               (13)
#define PWR_CSR_EWUP6                   (0x01U << PWR_CSR_EWUP6_Pos)            /*!< Enable WKUP6 pin */

/**
  * @brief PWR_CR1 register Bit definition
  */
#define PWR_CR1_WKP_EDGE1_Pos           (0)
#define PWR_CR1_WKP_EDGE1               (0x01U << PWR_CR1_WKP_EDGE1_Pos)        /*!< Wake up on rising edge 1 */
#define PWR_CR1_WKP_EDGE2_Pos           (1)
#define PWR_CR1_WKP_EDGE2               (0x01U << PWR_CR1_WKP_EDGE2_Pos)        /*!< Wake up on rising edge 2 */

#define PWR_CR1_WKP_EDGE4_Pos           (3)
#define PWR_CR1_WKP_EDGE4               (0x01U << PWR_CR1_WKP_EDGE4_Pos)        /*!< Wake up on rising edge 4 */
#define PWR_CR1_WKP_EDGE5_Pos           (4)
#define PWR_CR1_WKP_EDGE5               (0x01U << PWR_CR1_WKP_EDGE5_Pos)        /*!< Wake up on rising edge 5 */
#define PWR_CR1_WKP_EDGE6_Pos           (5)
#define PWR_CR1_WKP_EDGE6               (0x01U << PWR_CR1_WKP_EDGE6_Pos)        /*!< Wake up on rising edge 6 */

/**
  * @brief PWR_SR1 register Bit definition
  */
#define PWR_SR1_WUF1_Pos                (0)
#define PWR_SR1_WUF1                    (0x01U << PWR_SR1_WUF1_Pos)             /*!< wake-up flag 1 */
#define PWR_SR1_WUF2_Pos                (1)
#define PWR_SR1_WUF2                    (0x01U << PWR_SR1_WUF2_Pos)             /*!< wake-up flag 2 */

#define PWR_SR1_WUF4_Pos                (3)
#define PWR_SR1_WUF4                    (0x01U << PWR_SR1_WUF4_Pos)             /*!< wake-up flag 4 */
#define PWR_SR1_WUF5_Pos                (4)
#define PWR_SR1_WUF5                    (0x01U << PWR_SR1_WUF5_Pos)             /*!< wake-up flag 5 */
#define PWR_SR1_WUF6_Pos                (5)
#define PWR_SR1_WUF6                    (0x01U << PWR_SR1_WUF6_Pos)             /*!< wake-up flag 6 */

/**
  * @brief PWR_SCR register Bit definition
  */
#define PWR_SCR_WUF1_CLR_Pos            (0)
#define PWR_SCR_WUF1_CLR                (0x01U << PWR_SCR_WUF1_CLR_Pos)         /*!< clear wake-up flag 1 */
#define PWR_SCR_WUF2_CLR_Pos            (1)
#define PWR_SCR_WUF2_CLR                (0x01U << PWR_SCR_WUF2_CLR_Pos)         /*!< clear wake-up flag 2 */

#define PWR_SCR_WUF4_CLR_Pos            (3)
#define PWR_SCR_WUF4_CLR                (0x01U << PWR_SCR_WUF4_CLR_Pos)         /*!< clear wake-up flag 4 */
#define PWR_SCR_WUF5_CLR_Pos            (4)
#define PWR_SCR_WUF5_CLR                (0x01U << PWR_SCR_WUF5_CLR_Pos)         /*!< clear wake-up flag 5 */
#define PWR_SCR_WUF6_CLR_Pos            (5)
#define PWR_SCR_WUF6_CLR                (0x01U << PWR_SCR_WUF6_CLR_Pos)         /*!< clear wake-up flag 6 */

/**
  * @brief PWR_CFGR register Bit definition
  */
#define PWR_CFGR_LSICALSEL_Pos          (0)
#define PWR_CFGR_LSICALSEL              (0x1FU << PWR_CFGR_LSICALSEL_Pos)       /*!< Enable internal clock calibration */
#define PWR_CFGR_LSICAL_Pos             (5)
#define PWR_CFGR_LSICAL                 (0x1FU << PWR_CFGR_LSICAL_Pos)          /*!< Internal high-speed clock calibration */

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
