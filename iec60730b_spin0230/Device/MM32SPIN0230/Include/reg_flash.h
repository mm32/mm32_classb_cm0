/***********************************************************************************************************************
    @file     reg_flash.h
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
/* anonymous unions are enabled by default -----------------------------------*/
#else
#warning Not supported compiler type
#endif

/**
  * @brief  MM32 MCU Memory/Peripherals mapping
  */
#define FLASH_BASE                      (0x08000000U)             /*!< FLASH base address in the alias region */
#define SRAM_BASE                       (0x20000000U)             /*!< SRAM base address in the alias region */

/**
  * @brief FLASH Base Address Definition
  */
#define FLASH_REG_BASE                  (AHBPERIPH_BASE + 0x2000) /*!< Base Address: 0x40022000 */

/**
  * @brief OPTB Base Address Definition
  */
#define OB_BASE                         (0x1FFFF800U)             /*!< Flash Option Bytes base address */
#define PROTECT_BASE                    (0x1FFE0000U)             /*!< Flash Protect Bytes base address */

/**
  * @brief FLASH Registers Structure Definition
  */
typedef struct
{
    __IO uint32_t ACR;                 /*!< Access control Register                        offset: 0x00 */
    __IO uint32_t KEYR;                /*!< Key Register                                   offset: 0x04 */
    __IO uint32_t OPTKEYR;             /*!< Option byte key Register                       offset: 0x08 */
    __IO uint32_t SR;                  /*!< State Register                                 offset: 0x0C */
    __IO uint32_t CR;                  /*!< Control Register                               offset: 0x10 */
    __IO uint32_t AR;                  /*!< Address Register                               offset: 0x14 */
    __IO uint32_t RESERVED0x18;        /*!< Reserved,                                      offset: 0x18 */
    __IO uint32_t OBR;                 /*!< Option bytes Register                          offset: 0x1C */
    __IO uint32_t WRPR;               /*!< Write protect Register                         offset: 0x20 */
    __IO uint32_t RESERVED0x24[10];    /*!< Reserved,                                      offset: 0x24~0x54 */
    __IO uint32_t CPU_RSTN_MATCH;      /*!< Data matching status register                  offset: 0x58 */
    __IO uint32_t SEC4_KEYR;           /*!< NVR4 key register                              offset: 0x5C */
    __IO uint32_t RESERVED0x60[2];     /*!< Reserved,                                      offset: 0x60~0x64 */
    __IO uint32_t CFG2;                /*!< Configuration register 2                       offset: 0x68*/
} FLASH_TypeDef;

/**
  * @brief  OPT Structure Definition
  */
typedef struct
{
    __IO uint16_t RDP;                 /*!< Read Protect,                                  offset: 0x00 */
    __IO uint16_t USER;                /*!< User option byte,                              offset: 0x02 */
    __IO uint16_t Data0;               /*!< User data 0,                                   offset: 0x04 */
    __IO uint16_t Data1;               /*!< User data 1,                                   offset: 0x06 */
    __IO uint16_t WRP0;                /*!< Flash write protection option byte 0,          offset: 0x08 */
    __IO uint16_t WRP1;                /*!< Flash write protection option byte 1,          offset: 0x0A */
    __IO uint16_t WRP2;                /*!< Flash write protection option byte 2,          offset: 0x0C */
    __IO uint16_t WRP3;                /*!< Flash write protection option byte 3,          offset: 0x0E */
} OB_TypeDef;

/**
  * @brief  PROTECT BYTES Structure Definition
  */
typedef struct
{
    __IO uint16_t PROTECT_LEN0;        /*!< The length of Protect byte 0,                  offset: 0x00 */
    __IO uint16_t PROTECT_ADDR0;       /*!< Data of Protect byte 0,                        offset: 0x02 */
    __IO uint16_t PROTECT_LEN1;        /*!< The length of Protect byte 1,                  offset: 0x04 */
    __IO uint16_t PROTECT_ADDR1;       /*!< Data of Protect byte 1,                        offset: 0x06 */
    __IO uint16_t PROTECT_LEN2;        /*!< The length of Protect byte 2,                  offset: 0x08 */
    __IO uint16_t PROTECT_ADDR2;       /*!< Data of Protect byte 2,                        offset: 0x0A */
    __IO uint16_t PROTECT_LEN3;        /*!< The length of Protect byte 3,                  offset: 0x0C */
    __IO uint16_t PROTECT_ADDR3;       /*!< Data of Protect byte 3,                        offset: 0x0E */
} PROTECT_TypeDef;

/**
  * @brief  CACHE BYTES Structure Definition
  */

/**
  * @brief FLASH type pointer Definition
  */
#define FLASH                           ((FLASH_TypeDef *)FLASH_REG_BASE)

/**
  * @brief OPTB type pointer Definition
  */
#define OB                              ((OB_TypeDef *)OB_BASE)
#define PROTECT                         ((PROTECT_TypeDef *)PROTECT_BASE)

/**
  * @brief FLASH_ACR Register Bit Definition
  */
#define FLASH_ACR_LATENCY_Pos           (0)
#define FLASH_ACR_LATENCY_Msk           (0x07U << FLASH_ACR_LATENCY_Pos)        /*!< LATENCY[2:0] bits (Latency) */
#define FLASH_ACR_LATENCY_0             (0x00U << FLASH_ACR_LATENCY_Pos)        /*!< 0 waiting state */
#define FLASH_ACR_LATENCY_1             (0x01U << FLASH_ACR_LATENCY_Pos)        /*!< 1 waiting state */
#define FLASH_ACR_HLFCYA_Pos            (3)
#define FLASH_ACR_HLFCYA                (0x01U << FLASH_ACR_HLFCYA_Pos)         /*!< Flash Half Cycle Access Enable */
#define FLASH_ACR_PRFTBE_Pos            (4)
#define FLASH_ACR_PRFTBE_Msk            (0x01U << FLASH_ACR_PRFTBE_Pos)         /*!< Prefetch Buffer Enable */
#define FLASH_ACR_PRFTBS_Pos            (5)
#define FLASH_ACR_PRFTBS_Msk            (0x01U << FLASH_ACR_PRFTBS_Pos)         /*!< Prefetch Buffer Status */

#define FLASH_ACR_CFG_ENABLE_Pos        (12)
#define FLASH_ACR_CFG_ENABLE            (0xFFFFFU << FLASH_ACR_CFG_ENABLE_Pos)  /* CFG ENABLE */

/**
  * @brief FLASH_KEYR Register Bit Definition
  */
#define FLASH_KEYR_FKEYR_Pos            (0)
#define FLASH_KEYR_FKEYR                (0xFFFFFFFFU << FLASH_KEYR_FKEYR_Pos)   /*!< FLASH Key */

/**
  * @brief FLASH_OPTKEYR Register Bit Definition
  */
#define FLASH_OPTKEYR_OPTKEYR_Pos       (0)
#define FLASH_OPTKEYR_OPTKEYR           (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_Pos) /*!< Option Byte Key */

/**
  * @brief FLASH_SR Register Bit Definition
  */
#define FLASH_SR_BSY_Pos                (0)
#define FLASH_SR_BSY                    (0x01U << FLASH_SR_BSY_Pos)     /*!< Busy */
#define FLASH_SR_PGERR_Pos              (2)
#define FLASH_SR_PGERR                  (0x01U << FLASH_SR_PGERR_Pos)    /*!< Programming Error */
#define FLASH_SR_WRPRTERR_Pos           (4)
#define FLASH_SR_WRPRTERR               (0x01U << FLASH_SR_WRPRTERR_Pos) /*!< Write Protection Error */
#define FLASH_SR_EOP_Pos                (5)
#define FLASH_SR_EOP                    (0x01U << FLASH_SR_EOP_Pos)      /*!< End of operation */

/**
  * @brief FLASH_CR Register Bit Definition
  */
#define FLASH_CR_PG_Pos                 (0)
#define FLASH_CR_PG_Msk                 (0x01U << FLASH_CR_PG_Pos)              /*!< Programming */
#define FLASH_CR_PER_Pos                (1)
#define FLASH_CR_PER_Msk                (0x01U << FLASH_CR_PER_Pos)             /*!< Page Erase */
#define FLASH_CR_MER_Pos                (2)
#define FLASH_CR_MER_Msk                (0x01U << FLASH_CR_MER_Pos)             /*!< Mass Erase */
#define FLASH_CR_OPTPG_Pos              (4)
#define FLASH_CR_OPTPG_Msk              (0x01U << FLASH_CR_OPTPG_Pos)           /*!< Option Byte Programming */
#define FLASH_CR_OPTER_Pos              (5)
#define FLASH_CR_OPTER_Msk              (0x01U << FLASH_CR_OPTER_Pos)           /*!< Option Byte Erase */
#define FLASH_CR_STRT_Pos               (6)
#define FLASH_CR_STRT_Msk               (0x01U << FLASH_CR_STRT_Pos)            /*!< Start */
#define FLASH_CR_LOCK_Pos               (7)
#define FLASH_CR_LOCK                   (0x01U << FLASH_CR_LOCK_Pos)   /*!< Lock */
#define FLASH_CR_OPTWRE_Pos             (9)
#define FLASH_CR_OPTWRE                 (0x01U << FLASH_CR_OPTWRE_Pos) /*!< Option Bytes Write Enable */
#define FLASH_CR_ERRIE_Pos              (10)
#define FLASH_CR_ERRIE                  (0x01U << FLASH_CR_ERRIE_Pos)  /*!< Error Interrupt Enable */
#define FLASH_CR_EOPIE_Pos              (12)
#define FLASH_CR_EOPIE                  (0x01U << FLASH_CR_EOPIE_Pos)  /*!< End of operation interrupt enable */

#define FLASH_CR_SYS_ER_Pos             (16)
#define FLASH_CR_SYS_ER                 (0xFFFFU << FLASH_CR_SYS_ER_Pos)        /*!< Write 0x'hA5BA for sys space erase */

/**
  * @brief FLASH_AR Register Bit Definition
  */
#define FLASH_AR_FAR_Pos                (0)
#define FLASH_AR_FAR                    (0xFFFFFFFFU << FLASH_AR_FAR_Pos) /*!< Flash Address */

/**
  * @brief FLASH_OBR Register Bit Definition
  */
#define FLASH_OBR_OPTERR_Pos            (0)
#define FLASH_OBR_OPTERR                (0x01U << FLASH_OBR_OPTERR_Pos) /*!< Option Byte Error */
#define FLASH_OBR_RDP_Pos               (1)
#define FLASH_OBR_RDP                   (0x01U << FLASH_OBR_RDP_Pos)    /*!< The read protection function was enabled */
#define FLASH_OBR_WDG_SW_Pos            (2)
#define FLASH_OBR_WDG_SW                (0x01U << FLASH_OBR_WDG_SW_Pos)   /*!< WDG_SW */
#define FLASH_OBR_nRST_STOP_Pos         (3)
#define FLASH_OBR_nRST_STOP             (0x01U << FLASH_OBR_nRST_STOP_Pos) /*!< Select stop mode */
#define FLASH_OBR_nRST_STDBY_Pos        (4)
#define FLASH_OBR_nRST_STDBY            (0x01U << FLASH_OBR_nRST_STDBY_Pos)  /*!< Select standy mode */

#define FLASH_OBR_BOOT1_Pos             (6)
#define FLASH_OBR_BOOT1                 (0x01U << FLASH_OBR_BOOT1_Pos)   /*!< BOOT1 information stored by the NVR */
#define FLASH_OBR_OBRRSTN_Pos           (7)
#define FLASH_OBR_OBRRSTN               (0x01U << FLASH_OBR_OBRRSTN_Pos)  /*!< NRST multiplexes PA10 */
#define FLASH_OBR_BOOT0_Pos             (8)
#define FLASH_OBR_BOOT0                 (0x01U << FLASH_OBR_BOOT0_Pos)   /*!< BOOT0 information stored by the NVR */
#define FLASH_OBR_BOOTSEL_Pos           (9)
#define FLASH_OBR_BOOTSEL               (0x01U << FLASH_OBR_BOOTSEL_Pos)   /*!< Chip boot configuration BOOT0 select */

#define FLASH_OBR_Data0_Pos             (10)
#define FLASH_OBR_Data0                 (0xFFU << FLASH_OBR_Data0_Pos)  /*!< User data storage option byte */
#define FLASH_OBR_Data1_Pos             (18)
#define FLASH_OBR_Data1                 (0xFFU << FLASH_OBR_Data1_Pos)  /*!< User data storage option byte */

/**
  * @brief FLASH_WRPR Register Bit Definition
  */
#define FLASH_WRPR_WRP_Pos            (0)
#define FLASH_WRPR_WRP                (0xFFFFFFFFU << FLASH_WRPR_WRP_Pos) /*!< Write Protect */

/**
  * @brief CPU_RSTN_MATCH Register Bit Definition
  */
#define CPU_RSTN_VLU_MATCH_Pos          (0)
#define CPU_RSTN_VLU_MATCH              (0x01U << CPU_RSTN_VLU_MATCH_Pos)       /*! Indicates the read NVR4 spatial data matching */

/**
  * @brief FLASH_SEC4_KEYR Register Bit Definition
  */
#define FLASH_SEC4_KEYR_CPU_Pos         (0)
#define FLASH_SEC4_KEYR_CPU             (0xFFFFFFFFU << FLASH_SEC4_KEYR_CPU_Pos) /*!< This operation is available when 32'h30c30726 is written to SWD NVR4 space */

/**
  * @brief FLASH_CFG2 Register Bit Definition
  */
#define FLASH_CFG2_FLASH_CE_SEL_Pos     (0)
#define FLASH_CFG2_FLASH_CE_SEL         (0x01U << FLASH_CFG2_FLASH_CE_SEL_Pos)  /*!< flash ip CE tie high */
#define FLASH_CFG2_FLASH_FWUP_Pos       (1)
#define FLASH_CFG2_FLASH_FWUP           (0x01U << FLASH_CFG2_FLASH_FWUP_Pos)    /*!< flash ip enable fast wake up */

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

