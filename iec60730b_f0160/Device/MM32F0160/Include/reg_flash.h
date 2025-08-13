/*
 *******************************************************************************
    @file     reg_flash.h
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

#ifndef __REG_FLASH_H
#define __REG_FLASH_H

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
  * @brief  MM32 MCU Memory/Peripherals mapping
  */
#define FLASH_BASE                      (0x08000000U)                           /*!< FLASH base address in the alias region */
#define SRAM_BASE                       (0x20000000U)                           /*!< SRAM base address in the alias region */

/**
  * @brief FLASH Base Address Definition
  */
#define FLASH_REG_BASE                  (AHBPERIPH_BASE + 0x2000)               /*!< Base Address: 0x40022000 */

/**
  * @brief OPTB Base Address Definition
  */
#define OB_BASE                         (0x1FFFF800U)                           /*!< Flash Option Bytes base address */
#define PROTECT_BASE                    (0x1FFE0000U)                           /*!< Flash Protect Bytes base address */

/**
  * @brief FLASH Registers Structure Definition
  */
typedef struct {
    __IO uint32_t ACR;                                                          /*!< Access control Register                        offset: 0x00 */
    __IO uint32_t KEYR;                                                         /*!< Key Register                                   offset: 0x04 */
    __IO uint32_t OPTKEYR;                                                      /*!< Option byte key Register                       offset: 0x08 */
    __IO uint32_t SR;                                                           /*!< State Register                                 offset: 0x0C */
    __IO uint32_t CR;                                                           /*!< Control Register                               offset: 0x10 */
    __IO uint32_t AR;                                                           /*!< Address Register                               offset: 0x14 */
    __IO uint32_t RESERVED0x18;                                                 /*!< Reserved                                       offset: 0x18 */
    __IO uint32_t OBR;                                                          /*!< Option bytes Register                          offset: 0x1C */
    __IO uint32_t WRPR0;                                                        /*!< Write protect Register1                        offset: 0x20 */
    __IO uint32_t RESERVED0x24[13];                                             /*!< Reserved                                       offset: 0x24 */
    __IO uint32_t CPU_RSTN_MATCH;                                               /*!< Data matching status register                  offset: 0x58 */
    __IO uint32_t SEC4_KEYR;                                                    /*!< NVR4 Key Register                              offset: 0x5C */
    __IO uint32_t RESERVED0x60[48];                                             /*!< Reserved                                       offset: 0x60 */
    __IO uint32_t RCELL;                                                        /*!< Reference cell initialization                  offset: 0x120 */
    __IO uint32_t RESERVED0x124[23];                                            /*!< Reserved                                       offset: 0x124 */
    __IO uint32_t NVS_C;                                                        /*!< Flash ip nvs_C Time parameters                 offset: 0x180 */
    __IO uint32_t NVS_S;                                                        /*!< Flash ip NVS_S Time parameters                 offset: 0x184 */
    __IO uint32_t PROG;                                                         /*!< Flash ip PROG Time parameters                  offset: 0x188 */
    __IO uint32_t PGS;                                                          /*!< Flash ip PGS Time parameters                   offset: 0x18C */
    __IO uint32_t PRCV;                                                         /*!< Flash ip PRCV Time parameters                  offset: 0x190 */
    __IO uint32_t ERCV_C;                                                       /*!< Flash ip ERCV_C Time parameters                offset: 0x194 */
    __IO uint32_t ERASE_C;                                                      /*!< Flash ip ERASE_C Time parameters               offset: 0x198 */
    __IO uint32_t ERASE_S;                                                      /*!< Flash ip ERASE_S Time parameters               offset: 0x19C */
    __IO uint32_t RW_S;                                                         /*!< Flash ip RW_S Time parameters                  offset: 0x1A0 */
    __IO uint32_t RW_C;                                                         /*!< Flash ip RW_C Time parameters                  offset: 0x1A4 */
} FLASH_TypeDef;

/**
  * @brief  OPT Structure Definition
  */
typedef struct {
    __IO uint16_t RDP;                                                          /*!< Read Protect,                                  offset: 0x00 */
    __IO uint16_t USER;                                                         /*!< User option byte,                              offset: 0x02 */
    __IO uint16_t Data0;                                                        /*!< User data 0,                                   offset: 0x04 */
    __IO uint16_t Data1;                                                        /*!< User data 1,                                   offset: 0x06 */
    __IO uint16_t WRPOB[4];                                                     /*!< Flash write protection option bytes            offset: 0x08 */
} OB_TypeDef;

/**
  * @brief  PROTECT BYTES Structure Definition
  */
typedef struct {
    __IO uint16_t PROTECT_LEN0;                                                 /*!< The length of Protect byte 0,                  offset: 0x00 */
    __IO uint16_t PROTECT_ADDR0;                                                /*!< Data of Protect byte 0,                        offset: 0x02 */
    __IO uint16_t PROTECT_LEN1;                                                 /*!< The length of Protect byte 1,                  offset: 0x04 */
    __IO uint16_t PROTECT_ADDR1;                                                /*!< Data of Protect byte 1,                        offset: 0x06 */
    __IO uint16_t PROTECT_LEN2;                                                 /*!< The length of Protect byte 2,                  offset: 0x08 */
    __IO uint16_t PROTECT_ADDR2;                                                /*!< Data of Protect byte 2,                        offset: 0x0A */
    __IO uint16_t PROTECT_LEN3;                                                 /*!< The length of Protect byte 3,                  offset: 0x0C */
    __IO uint16_t PROTECT_ADDR3;                                                /*!< Data of Protect byte 3,                        offset: 0x0E */
} PROTECT_TypeDef;

/**
  * @brief  CACHE BYTES Structure Definition
  */

/**
  * @brief FLASH type pointer Definition
  */
#define FLASH                           ((FLASH_TypeDef*) FLASH_REG_BASE)

/**
  * @brief OPTB type pointer Definition
  */
#define OB                              ((OB_TypeDef*) OB_BASE)
#define PROTECT                         ((PROTECT_TypeDef*) PROTECT_BASE)

/**
  * @brief FLASH_ACR Register Bit Definition
  */
#define FLASH_ACR_LATENCY_Pos           (0)
#define FLASH_ACR_LATENCY               (0x07U << FLASH_ACR_LATENCY_Pos)        /*!< LATENCY[2:0] bits (Latency) */
#define FLASH_ACR_LATENCY_0             (0x00U << FLASH_ACR_LATENCY_Pos)        /*!< 0 waiting state */
#define FLASH_ACR_LATENCY_1             (0x01U << FLASH_ACR_LATENCY_Pos)        /*!< 1 waiting state */
#define FLASH_ACR_LATENCY_2             (0x02U << FLASH_ACR_LATENCY_Pos)        /*!< 2 waiting state */
#define FLASH_ACR_LATENCY_3             (0x03U << FLASH_ACR_LATENCY_Pos)        /*!< 3 waiting state */
#define FLASH_ACR_HLFCYA_Pos            (3)
#define FLASH_ACR_HLFCYA                (0x01U << FLASH_ACR_HLFCYA_Pos)         /*!< Flash Half Cycle Access Enable */
#define FLASH_ACR_PRFTBE_Pos            (4)
#define FLASH_ACR_PRFTBE                (0x01U << FLASH_ACR_PRFTBE_Pos)         /*!< Prefetch Buffer Enable */
#define FLASH_ACR_PRFTBS_Pos            (5)
#define FLASH_ACR_PRFTBS                (0x01U << FLASH_ACR_PRFTBS_Pos)         /*!< Prefetch Buffer Status */
#define FLASH_ACR_CFG_ENABLE_Pos        (12)
#define FLASH_ACR_CFG_ENABLE            (0xFFFFFU << FLASH_ACR_CFG_ENABLE_Pos)

/**
  * @brief FLASH_KEYR Register Bit Definition
  */
#define FLASH_KEYR_FKEY_Pos             (0)
#define FLASH_KEYR_FKEY                 (0xFFFFFFFFU << FLASH_KEYR_FKEY_Pos)    /*!< FLASH Key */

/**
  * @brief FLASH_OPTKEYR Register Bit Definition
  */
#define FLASH_OPTKEYR_Pos               (0)
#define FLASH_OPTKEYR                   (0xFFFFFFFFU << FLASH_OPTKEYR_Pos)      /*!< Option Byte Key */

/**
  * @brief FLASH_SR Register Bit Definition
  */
#define FLASH_SR_BUSY_Pos               (0)
#define FLASH_SR_BUSY                   (0x01U << FLASH_SR_BUSY_Pos)            /*!< Busy */
#define FLASH_SR_PGERR_Pos              (2)
#define FLASH_SR_PGERR                  (0x01U << FLASH_SR_PGERR_Pos)           /*!< Programming Error */
#define FLASH_SR_WRPRTERR_Pos           (4)
#define FLASH_SR_WRPRTERR               (0x01U << FLASH_SR_WRPRTERR_Pos)        /*!< Write Protection Error */
#define FLASH_SR_EOP_Pos                (5)
#define FLASH_SR_EOP                    (0x01U << FLASH_SR_EOP_Pos)             /*!< End of operation */

/**
  * @brief FLASH_CR Register Bit Definition
  */
#define FLASH_CR_PG_Pos                 (0)
#define FLASH_CR_PG                     (0x01U << FLASH_CR_PG_Pos)              /*!< Programming */
#define FLASH_CR_PER_Pos                (1)
#define FLASH_CR_PER                    (0x01U << FLASH_CR_PER_Pos)             /*!< Page Erase */
#define FLASH_CR_MER_Pos                (2)
#define FLASH_CR_MER                    (0x01U << FLASH_CR_MER_Pos)             /*!< Mass Erase */
#define FLASH_CR_OPTPG_Pos              (4)
#define FLASH_CR_OPTPG                  (0x01U << FLASH_CR_OPTPG_Pos)           /*!< Option Byte Programming */
#define FLASH_CR_OPTER_Pos              (5)
#define FLASH_CR_OPTER                  (0x01U << FLASH_CR_OPTER_Pos)           /*!< Option Byte Erase */
#define FLASH_CR_STRT_Pos               (6)
#define FLASH_CR_STRT                   (0x01U << FLASH_CR_STRT_Pos)            /*!< Start */
#define FLASH_CR_LOCK_Pos               (7)
#define FLASH_CR_LOCK                   (0x01U << FLASH_CR_LOCK_Pos)            /*!< Lock */
#define FLASH_CR_OPTWRE_Pos             (9)
#define FLASH_CR_OPTWRE                 (0x01U << FLASH_CR_OPTWRE_Pos)          /*!< Option Bytes Write Enable */
#define FLASH_CR_ERRIE_Pos              (10)
#define FLASH_CR_ERRIE                  (0x01U << FLASH_CR_ERRIE_Pos)           /*!< Error Interrupt Enable */
#define FLASH_CR_EOPIE_Pos              (12)
#define FLASH_CR_EOPIE                  (0x01U << FLASH_CR_EOPIE_Pos)           /*!< End of operation interrupt enable */
#define FLASH_CR_SYS_ER_Pos             (16)
#define FLASH_CR_SYS_ER                 (0xFFFFU << FLASH_CR_SYS_ER_Pos)        /*!< Write 0x'hA5BA for sys space erase */

/**
  * @brief FLASH_AR Register Bit Definition
  */
#define FLASH_AR_FAR_Pos                (0)
#define FLASH_AR_FAR                    (0xFFFFFFFFU << FLASH_AR_FAR_Pos)       /*!< Flash Address */

/**
  * @brief FLASH_OBR Register Bit Definition
  */
#define FLASH_OBR_OPTERR_Pos            (0)
#define FLASH_OBR_OPTERR                (0x01U << FLASH_OBR_OPTERR_Pos)         /*!< Option Byte Error */
#define FLASH_OBR_RDP_Pos               (0)
#define FLASH_OBR_RDP                   (0x01U << FLASH_OBR_RDP_Pos)            /*!< Read Protection Enable */
#define FLASH_OBR_WDG_SW_Pos            (2)
#define FLASH_OBR_WDG_SW                (0x01U << FLASH_OBR_WDG_SW_Pos)         /*!< User Option Bytes */
#define FLASH_OBR_NRST_STOP_Pos         (3)
#define FLASH_OBR_NRST_STOP             (0x01U << FLASH_OBR_NRST_STOP_Pos)      /*!< Select stop mode */
#define FLASH_OBR_NRST_STDBY_Pos        (4)
#define FLASH_OBR_NRST_STDBY            (0x01U << FLASH_OBR_NRST_STDBY_Pos)     /*!< Select standy mode */
#define FLASH_OBR_NBOOT1_Pos            (6)
#define FLASH_OBR_NBOOT1                (0x01U << FLASH_OBR_NBOOT1_Pos)         /*!< Chip Boot Configuration Selection */

#define FLASH_OBR_DATA0_Pos             (10)
#define FLASH_OBR_DATA0                 (0xFFU << FLASH_OBR_DATA0_Pos)          /*!< User data storage option byte */
#define FLASH_OBR_DATA1_Pos             (18)
#define FLASH_OBR_DATA1                 (0xFFU << FLASH_OBR_DATA1_Pos)          /*!< User data storage option byte */

/**
  * @brief FLASH_WRPR Register Bit Definition
  */
#define FLASH_WRPR0_WRP0_Pos            (0)
#define FLASH_WRPR0_WRP0                (0xFFFFFFFFU << FLASH_WRPR0_WRP0_Pos)   /*!< Write Protect */

/**
  * @brief FLASH_KEYS0~1 Register Bit Definition
  */
#define FLASH_KEYS_SECRT_KEY_CPU_Pos    (0)
#define FLASH_KEYS_SECRT_KEY_CPU        (0xFFFFFFFFU << FLASH_KEYS_SECRT_KEY_CPU_Pos)   /*!< Write Protect */

/**
  * @brief CPU_RSTN_KEYR Register Bit Definition
  */
#define CPU_RSTN_KEYR_CPU_RSTN_KEY_POS  (0)
#define CPU_RSTN_KEYR_CPU_RSTN_KEY      (0x01U << CPU_RSTN_KEYR_CPU_RSTN_KEY_POS)   /*!< Indicates the read NVR4 spatial data match */

/**
  * @brief CPU_RSTN_MATCH Register Bit Definition
  */
#define CPU_RSTN_VLU_MATCH_POS          (0)
#define CPU_RSTN_VLU_MATCH              (0x01U << CPU_RSTN_VLU_MATCH_POS)       /*!< Indicates the read NVR4 spatial data match */

/**
  * @brief FLASH_SEC4_KEYR Register Bit Definition
  */
#define FLASH_SEC4_KEYR_SEC4_KEY_CPU_POS    (0)
#define FLASH_SEC4_KEYR_SEC4_KEY_CPU    (0xFFFFFFFFU << FLASH_SEC4_KEYR_SEC4_KEY_CPU_POS)  /*!< When writing 32'h30c30726 through SWD, NVR4 space can be operated */

/**
  * @brief FLASH_RCELL Register Bit Definition
  */
#define FLASH_RCELL_POS                 (0)
#define FLASH_RCELL                     (0x01U << FLASH_RCELL_POS)              /*!< When there is no CP test for Flash, complete the flash reference cell initialization by setting RCELL to 1 */

/**
  * @brief FLASH_NVS_C Register Bit Definition
  */
#define FLASH_NVS_C_POS                 (0)
#define FLASH_NVS_C                     (0x7FFFFU << FLASH_NVS_C_POS)           /*!< Chip erase nvs */

/**
  * @brief FLASH_NVS_S Register Bit Definition
  */
#define FLASH_NVS_S_POS                 (0)
#define FLASH_NVS_S                     (0x7FFFFU << FLASH_NVS_S_POS)           /*!< sector erase nvs */

/**
  * @brief FLASH_PROG Register Bit Definition
  */
#define FLASH_PROG_POS                  (0)
#define FLASH_PROG                      (0x7FFFFU << FLASH_PROG_POS)            /*!< Flash program */

/**
  * @brief FLASH_PGS Register Bit Definition
  */
#define FLASH_PGS_POS                   (0)
#define FLASH_PGS                       (0x7FFFFU << FLASH_PGS_POS)             /*!< Flash pgs */

/**
  * @brief FLASH_PRCV Register Bit Definition
  */
#define FLASH_PRCV_POS                  (0)
#define FLASH_PRCV                      (0x7FFFFU << FLASH_PRCV_POS)            /*!< Flash prcv */

/**
  * @brief FLASH_ERCV_C Register Bit Definition
  */
#define FLASH_ERCV_C_POS                (0)
#define FLASH_ERCV_C                    (0x7FFFFU << FLASH_ERCV_C_POS)          /*!< Flash chip erase rcv */

/**
  * @brief FLASH_ERASE_C Register Bit Definition
  */
#define FLASH_ERASE_C_POS               (0)
#define FLASH_ERASE_C                   (0x7FFFFU << FLASH_ERASE_C_POS)         /*!< Flash chip erase */

/**
  * @brief FLASH_ERASE_S Register Bit Definition
  */
#define FLASH_ERASE_S_POS               (0)
#define FLASH_ERASE_S                   (0x7FFFFU << FLASH_ERASE_S_POS)         /*!< Flash sector erase */

/**
  * @brief FLASH_RW_S Register Bit Definition
  */
#define FLASH_RW_S_POS                  (0)
#define FLASH_RW_S                      (0x7FFFFU << FLASH_RW_S_POS)            /*!< Flash sector erase rw */

/**
  * @brief FLASH_RW_C Register Bit Definition
  */
#define FLASH_RW_C_POS                  (0)
#define FLASH_RW_C                      (0x7FFFFU << FLASH_RW_C_POS)            /*!< Flash chip erase rw */

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
