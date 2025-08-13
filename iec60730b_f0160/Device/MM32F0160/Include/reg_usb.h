/*
 *******************************************************************************
    @file     reg_core.h
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

#ifndef __REG_USB_H
#define __REG_USB_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if 0
/* IP_USB_FS_DesignSpec_v11_EN_MZ3291_uniformed */
#endif

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


/*!
 * @brief USB Base Address Definition
 */
#define USB_BASE                        (0x50000000)              /*!< Base Address: 0x50000000 */


/*!
 * @brief USB Register Structure Definition
 */

typedef struct {
    __IO uint32_t Reserved55[4];                                                  /*!< Reserved                                                  */
    __IO uint32_t FSOTGISTAT;                                                     /*!< OTG Interrupt Status Register                offset: 0x10 */
    __IO uint32_t FSOTGICTRL;                                                     /*!< OTG Interrupt Control Register               offset: 0x14 */
    __IO uint32_t FSOTGSTAT;                                                      /*!< OTG Status Register                          offset: 0x18 */
    __IO uint32_t FSOTGCTRL;                                                      /*!< OTG Control Register                         offset: 0x1C */
    __IO uint32_t Reserved56[24];                                                 /*!< Reserved                                                  */
    __IO uint32_t FSINTSTAT;                                                      /*!< Interrupt Status Register                    offset: 0x80 */
    __IO uint32_t FSINTENB;                                                       /*!< Interrupt Enable Register                    offset: 0x84 */
    __IO uint32_t FSERRSTAT;                                                      /*!< Error Interrupt Status Register              offset: 0x88 */
    __IO uint32_t FSERRENB;                                                       /*!< Error Interrupt Enable Register              offset: 0x8C */
    __IO uint32_t FSSTAT;                                                         /*!< Status Register                              offset: 0x90 */
    __IO uint32_t FSCTL;                                                          /*!< Control Register                             offset: 0x94 */
    __IO uint32_t FSADDR;                                                         /*!< Address Register                             offset: 0x98 */
    __IO uint32_t FSBDTPAGE1;                                                     /*!< BDT Page Register 1                          offset: 0x9C */
    __IO uint32_t FSFRMNUML;                                                      /*!< Frame Number Register                        offset: 0xA0 */
    __IO uint32_t FSFRMNUMH;                                                      /*!< Frame Number Register                        offset: 0xA4 */
    __IO uint32_t FSTOKEN;                                                        /*!< Token Register                               offset: 0xA8 */
    __IO uint32_t FSSOFTHLD;                                                      /*!< SOF Threshold Register                       offset: 0xAC */
    __IO uint32_t FSBDTPAGE2;                                                     /*!< BDT Page Register 2                          offset: 0xB0 */
    __IO uint32_t FSBDTPAGE3;                                                     /*!< BDT Page Register 3                          offset: 0xB4 */
    __IO uint32_t Reserved57[2];                                                  /*!< Reserved                                                  */
    __IO uint32_t FSEPCTL[16];                                                    /*!< Endpoint control register 0 ~15              offset: 0xC0 */
    __IO uint32_t FSUSBCTRL;                                                      /*!< USB control register                         offset 0x100 */
} USB_Type;


/*******************************************************************************
 * USB Type
 ******************************************************************************/

/*!
 * @addtogroup USB_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief USB_FS_OTGISTAT Register Bit Definition
 */

#define USB_FSOTGISTAT_IDCHG_SHIFT              (7)
#define USB_FSOTGISTAT_IDCHG_MASK               (0x01U << USB_FSOTGISTAT_IDCHG_SHIFT)
#define USB_FSOTGISTAT_IDCHG(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSOTGISTAT_IDCHG_SHIFT)) & USB_FSOTGISTAT_IDCHG_MASK)

#define USB_FSOTGISTAT_1MSEC_SHIFT              (6)
#define USB_FSOTGISTAT_1MSEC_MASK               (0x01U << USB_FSOTGISTAT_1MSEC_SHIFT)
#define USB_FSOTGISTAT_1MSEC(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSOTGISTAT_1MSEC_SHIFT)) & USB_FSOTGISTAT_1MSEC_MASK)

#define USB_FSOTGISTAT_LINESTATECHG_SHIFT       (5)
#define USB_FSOTGISTAT_LINESTATECHG_MASK        (0x01U << USB_FSOTGISTAT_LINESTATECHG_SHIFT)
#define USB_FSOTGISTAT_LINESTATECHG(x)          (((uint32_t)(((uint32_t)(x)) << USB_FSOTGISTAT_LINESTATECHG_SHIFT)) & USB_FSOTGISTAT_LINESTATECHG_MASK)

#define USB_FSOTGISTAT_SESSVLDCHG_SHIFT         (2)
#define USB_FSOTGISTAT_SESSVLDCHG_MASK          (0x01U << USB_FSOTGISTAT_SESSVLDCHG_SHIFT)
#define USB_FSOTGISTAT_SESSVLDCHG(x)            (((uint32_t)(((uint32_t)(x)) << USB_FSOTGISTAT_SESSVLDCHG_SHIFT)) & USB_FSOTGISTAT_SESSVLDCHG_MASK)

#define USB_FSOTGISTAT_BSESSENDCHG_SHIFT        (2)
#define USB_FSOTGISTAT_BSESSENDCHG_MASK         (0x01U << USB_FSOTGISTAT_BSESSENDCHG_SHIFT)
#define USB_FSOTGISTAT_BSESSENDCHG(x)           (((uint32_t)(((uint32_t)(x)) << USB_FSOTGISTAT_BSESSENDCHG_SHIFT)) & USB_FSOTGISTAT_BSESSENDCHG_MASK)

#define USB_FSOTGISTAT_AVBUSVLDCHG_SHIFT        (0)
#define USB_FSOTGISTAT_AVBUSVLDCHG_MASK         (0x01U << USB_FSOTGISTAT_AVBUSVLDCHG_SHIFT)
#define USB_FSOTGISTAT_AVBUSVLDCHG(x)           (((uint32_t)(((uint32_t)(x)) << USB_FSOTGISTAT_AVBUSVLDCHG_SHIFT)) & USB_FSOTGISTAT_AVBUSVLDCHG_MASK)

/*!
 * @brief USB_FS_OTGICTRL Register Bit Definition
 */

#define USB_FSOTGICTRL_IDEN_SHIFT               (7)
#define USB_FSOTGICTRL_IDEN_MASK                (0x01U << USB_FSOTGICTRL_IDEN_SHIFT)
#define USB_FSOTGICTRL_IDEN(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSOTGICTRL_IDEN_SHIFT)) & USB_FSOTGICTRL_IDEN_MASK)

#define USB_FSOTGICTRL_1MSECEN_SHIFT            (6)
#define USB_FSOTGICTRL_1MSECEN_MASK             (0x01U << USB_FSOTGICTRL_1MSECEN_SHIFT)
#define USB_FSOTGICTRL_1MSECEN(x)               (((uint32_t)(((uint32_t)(x)) << USB_FSOTGICTRL_1MSECEN_SHIFT)) & USB_FSOTGICTRL_1MSECEN_MASK)

#define USB_FSOTGICTRL_LINESTATEEN_SHIFT        (5)
#define USB_FSOTGICTRL_LINESTATEEN_MASK         (0x01U << USB_FSOTGICTRL_LINESTATEEN_SHIFT)
#define USB_FSOTGICTRL_LINESTATEEN(x)           (((uint32_t)(((uint32_t)(x)) << USB_FSOTGICTRL_LINESTATEEN_SHIFT)) & USB_FSOTGICTRL_LINESTATEEN_MASK)

#define USB_FSOTGICTRL_SESSVLDEN_SHIFT          (3)
#define USB_FSOTGICTRL_SESSVLDEN_MASK           (0x01U << USB_FSOTGICTRL_SESSVLDEN_SHIFT)
#define USB_FSOTGICTRL_SESSVLDEN(x)             (((uint32_t)(((uint32_t)(x)) << USB_FSOTGICTRL_SESSVLDEN_SHIFT)) & USB_FSOTGICTRL_SESSVLDEN_MASK)

#define USB_FSOTGICTRL_BSESSENDEN_SHIFT         (2)
#define USB_FSOTGICTRL_BSESSENDEN_MASK          (0x01U << USB_FSOTGICTRL_BSESSENDEN_SHIFT)
#define USB_FSOTGICTRL_BSESSENDEN(x)            (((uint32_t)(((uint32_t)(x)) << USB_FSOTGICTRL_BSESSENDEN_SHIFT)) & USB_FSOTGICTRL_BSESSENDEN_MASK)

#define USB_FSOTGICTRL_AVBUSVLDEN_SHIFT         (0)
#define USB_FSOTGICTRL_AVBUSVLDEN_MASK          (0x01U << USB_FSOTGICTRL_AVBUSVLDEN_SHIFT)
#define USB_FSOTGICTRL_AVBUSVLDEN(x)            (((uint32_t)(((uint32_t)(x)) << USB_FSOTGICTRL_AVBUSVLDEN_SHIFT)) & USB_FSOTGICTRL_AVBUSVLDEN_MASK)

/*!
 * @brief USB_FS_OTGSTAT Register Bit Definition
 */

#define USB_FSOTGSTAT_ID_SHIFT                  (7)
#define USB_FSOTGSTAT_ID_MASK                   (0x01U << USB_FSOTGSTAT_ID_SHIFT)
#define USB_FSOTGSTAT_ID(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSOTGSTAT_ID_SHIFT)) & USB_FSOTGSTAT_ID_MASK)

#define USB_FSOTGSTAT_LINESTATESTABLE_SHIFT     (5)
#define USB_FSOTGSTAT_LINESTATESTABLE_MASK      (0x01U << USB_FSOTGSTAT_LINESTATESTABLE_SHIFT)
#define USB_FSOTGSTAT_LINESTATESTABLE(x)        (((uint32_t)(((uint32_t)(x)) << USB_FSOTGSTAT_LINESTATESTABLE_SHIFT)) & USB_FSOTGSTAT_LINESTATESTABLE_MASK)

#define USB_FSOTGSTAT_SESSVLD_SHIFT             (3)
#define USB_FSOTGSTAT_SESSVLD_MASK              (0x01U << USB_FSOTGSTAT_SESSVLD_SHIFT)
#define USB_FSOTGSTAT_SESSVLD(x)                (((uint32_t)(((uint32_t)(x)) << USB_FSOTGSTAT_SESSVLD_SHIFT)) & USB_FSOTGSTAT_SESSVLD_MASK)

#define USB_FSOTGSTAT_BSESSEND_SHIFT            (2)
#define USB_FSOTGSTAT_BSESSEND_MASK             (0x01U << USB_FSOTGSTAT_BSESSEND_SHIFT)
#define USB_FSOTGSTAT_BSESSEND(x)               (((uint32_t)(((uint32_t)(x)) << USB_FSOTGSTAT_BSESSEND_SHIFT)) & USB_FSOTGSTAT_BSESSEND_MASK)

#define USB_FSOTGSTAT_AVBUSVLD_SHIFT            (0)
#define USB_FSOTGSTAT_AVBUSVLD_MASK             (0x01U << USB_FSOTGSTAT_AVBUSVLD_SHIFT)
#define USB_FSOTGSTAT_AVBUSVLD(x)               (((uint32_t)(((uint32_t)(x)) << USB_FSOTGSTAT_AVBUSVLD_SHIFT)) & USB_FSOTGSTAT_AVBUSVLD_MASK)

/*!
 * @brief USB_FS_OTGCTRL Register Bit Definition
 */

#define USB_FSOTGCTRL_DPHIGH_SHIFT              (7)
#define USB_FSOTGCTRL_DPHIGH_MASK               (0x01U << USB_FSOTGCTRL_DPHIGH_SHIFT)
#define USB_FSOTGCTRL_DPHIGH(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_DPHIGH_SHIFT)) & USB_FSOTGCTRL_DPHIGH_MASK)

#define USB_FSOTGCTRL_DMHIGH_SHIFT              (6)
#define USB_FSOTGCTRL_DMHIGH_MASK               (0x01U << USB_FSOTGCTRL_DMHIGH_SHIFT)
#define USB_FSOTGCTRL_DMHIGH(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_DMHIGH_SHIFT)) & USB_FSOTGCTRL_DMHIGH_MASK)

#define USB_FSOTGCTRL_DPLOW_SHIFT               (5)
#define USB_FSOTGCTRL_DPLOW_MASK                (0x01U << USB_FSOTGCTRL_DPLOW_SHIFT)
#define USB_FSOTGCTRL_DPLOW(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_DPLOW_SHIFT)) & USB_FSOTGCTRL_DPLOW_MASK)

#define USB_FSOTGCTRL_DMLOW_SHIFT               (4)
#define USB_FSOTGCTRL_DMLOW_MASK                (0x01U << USB_FSOTGCTRL_DMLOW_SHIFT)
#define USB_FSOTGCTRL_DMLOW(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_DMLOW_SHIFT)) & USB_FSOTGCTRL_DMLOW_MASK)

#define USB_FSOTGCTRL_VBUSON_SHIFT              (3)
#define USB_FSOTGCTRL_VBUSON_MASK               (0x01U << USB_FSOTGCTRL_VBUSON_SHIFT)
#define USB_FSOTGCTRL_VBUSON(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_VBUSON_SHIFT)) & USB_FSOTGCTRL_VBUSON_MASK)

#define USB_FSOTGCTRL_OTGEN_SHIFT               (2)
#define USB_FSOTGCTRL_OTGEN_MASK                (0x01U << USB_FSOTGCTRL_OTGEN_SHIFT)
#define USB_FSOTGCTRL_OTGEN(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_OTGEN_SHIFT)) & USB_FSOTGCTRL_OTGEN_MASK)

#define USB_FSOTGCTRL_VBUSCHG_SHIFT             (1)
#define USB_FSOTGCTRL_VBUSCHG_MASK              (0x01U << USB_FSOTGCTRL_VBUSCHG_SHIFT)
#define USB_FSOTGCTRL_VBUSCHG(x)                (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_VBUSCHG_SHIFT)) & USB_FSOTGCTRL_VBUSCHG_MASK)

#define USB_FSOTGCTRL_VBUSDSCHG_SHIFT           (0)
#define USB_FSOTGCTRL_VBUSDSCHG_MASK            (0x01U << USB_FSOTGCTRL_VBUSDSCHG_SHIFT)
#define USB_FSOTGCTRL_VBUSDSCHG(x)              (((uint32_t)(((uint32_t)(x)) << USB_FSOTGCTRL_VBUSDSCHG_SHIFT)) & USB_FSOTGCTRL_VBUSDSCHG_MASK)

/*!
 * @brief USB_FS_INTSTAT Register Bit Definition
 */

#define USB_FSINTSTAT_STALL_SHIFT               (7)
#define USB_FSINTSTAT_STALL_MASK                (0x01U << USB_FSINTSTAT_STALL_SHIFT)
#define USB_FSINTSTAT_STALL(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_STALL_SHIFT)) & USB_FSINTSTAT_STALL_MASK)

#define USB_FSINTSTAT_ATTACH_SHIFT              (6)
#define USB_FSINTSTAT_ATTACH_MASK               (0x01U << USB_FSINTSTAT_ATTACH_SHIFT)
#define USB_FSINTSTAT_ATTACH(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_ATTACH_SHIFT)) & USB_FSINTSTAT_ATTACH_MASK)

#define USB_FSINTSTAT_RESUME_SHIFT              (5)
#define USB_FSINTSTAT_RESUME_MASK               (0x01U << USB_FSINTSTAT_RESUME_SHIFT)
#define USB_FSINTSTAT_RESUME(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_RESUME_SHIFT)) & USB_FSINTSTAT_RESUME_MASK)

#define USB_FSINTSTAT_SLEEP_SHIFT               (4)
#define USB_FSINTSTAT_SLEEP_MASK                (0x01U << USB_FSINTSTAT_SLEEP_SHIFT)
#define USB_FSINTSTAT_SLEEP(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_SLEEP_SHIFT)) & USB_FSINTSTAT_SLEEP_MASK)

#define USB_FSINTSTAT_TOKDNE_SHIFT              (3)
#define USB_FSINTSTAT_TOKDNE_MASK               (0x01U << USB_FSINTSTAT_TOKDNE_SHIFT)
#define USB_FSINTSTAT_TOKDNE(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_TOKDNE_SHIFT)) & USB_FSINTSTAT_TOKDNE_MASK)

#define USB_FSINTSTAT_SOFTOK_SHIFT              (2)
#define USB_FSINTSTAT_SOFTOK_MASK               (0x01U << USB_FSINTSTAT_SOFTOK_SHIFT)
#define USB_FSINTSTAT_SOFTOK(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_SOFTOK_SHIFT)) & USB_FSINTSTAT_SOFTOK_MASK)

#define USB_FSINTSTAT_ERROR_SHIFT               (1)
#define USB_FSINTSTAT_ERROR_MASK                (0x01U << USB_FSINTSTAT_ERROR_SHIFT)
#define USB_FSINTSTAT_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_ERROR_SHIFT)) & USB_FSINTSTAT_ERROR_MASK)

#define USB_FSINTSTAT_USBRST_SHIFT              (0)
#define USB_FSINTSTAT_USBRST_MASK               (0x01U << USB_FSINTSTAT_USBRST_SHIFT)
#define USB_FSINTSTAT_USBRST(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSINTSTAT_USBRST_SHIFT)) & USB_FSINTSTAT_USBRST_MASK)

/*!
 * @brief USB_FS_INTENB Register Bit Definition
 */

#define USB_FSINTENB_STALL_SHIFT                (7)
#define USB_FSINTENB_STALL_MASK                 (0x01U << USB_FSINTENB_STALL_SHIFT)
#define USB_FSINTENB_STALL(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_STALL_SHIFT)) & USB_FSINTENB_STALL_MASK)

#define USB_FSINTENB_ATTACH_SHIFT               (6)
#define USB_FSINTENB_ATTACH_MASK                (0x01U << USB_FSINTENB_ATTACH_SHIFT)
#define USB_FSINTENB_ATTACH(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_ATTACH_SHIFT)) & USB_FSINTENB_ATTACH_MASK)

#define USB_FSINTENB_RESUME_SHIFT               (5)
#define USB_FSINTENB_RESUME_MASK                (0x01U << USB_FSINTENB_RESUME_SHIFT)
#define USB_FSINTENB_RESUME(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_RESUME_SHIFT)) & USB_FSINTENB_RESUME_MASK)

#define USB_FSINTENB_SLEEP_SHIFT                (4)
#define USB_FSINTENB_SLEEP_MASK                 (0x01U << USB_FSINTENB_SLEEP_SHIFT)
#define USB_FSINTENB_SLEEP(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_SLEEP_SHIFT)) & USB_FSINTENB_SLEEP_MASK)

#define USB_FSINTENB_TOKDNE_SHIFT               (3)
#define USB_FSINTENB_TOKDNE_MASK                (0x01U << USB_FSINTENB_TOKDNE_SHIFT)
#define USB_FSINTENB_TOKDNE(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_TOKDNE_SHIFT)) & USB_FSINTENB_TOKDNE_MASK)

#define USB_FSINTENB_SOFTOK_SHIFT               (2)
#define USB_FSINTENB_SOFTOK_MASK                (0x01U << USB_FSINTENB_SOFTOK_SHIFT)
#define USB_FSINTENB_SOFTOK(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_SOFTOK_SHIFT)) & USB_FSINTENB_SOFTOK_MASK)

#define USB_FSINTENB_ERROR_SHIFT                (1)
#define USB_FSINTENB_ERROR_MASK                 (0x01U << USB_FSINTENB_ERROR_SHIFT)
#define USB_FSINTENB_ERROR(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_ERROR_SHIFT)) & USB_FSINTENB_ERROR_MASK)

#define USB_FSINTENB_USBRST_SHIFT               (0)
#define USB_FSINTENB_USBRST_MASK                (0x01U << USB_FSINTENB_USBRST_SHIFT)
#define USB_FSINTENB_USBRST(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSINTENB_USBRST_SHIFT)) & USB_FSINTENB_USBRST_MASK)

/*!
 * @brief USB_FS_ERRSTAT Register Bit Definition
 */

#define USB_FSERRSTAT_BTSERR_SHIFT              (7)
#define USB_FSERRSTAT_BTSERR_MASK               (0x01U << USB_FSERRSTAT_BTSERR_SHIFT)
#define USB_FSERRSTAT_BTSERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_BTSERR_SHIFT)) & USB_FSERRSTAT_BTSERR_MASK)

#define USB_FSERRSTAT_DMAERR_SHIFT              (5)
#define USB_FSERRSTAT_DMAERR_MASK               (0x01U << USB_FSERRSTAT_DMAERR_SHIFT)
#define USB_FSERRSTAT_DMAERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_DMAERR_SHIFT)) & USB_FSERRSTAT_DMAERR_MASK)

#define USB_FSERRSTAT_BTOERR_SHIFT              (4)
#define USB_FSERRSTAT_BTOERR_MASK               (0x01U << USB_FSERRSTAT_BTOERR_SHIFT)
#define USB_FSERRSTAT_BTOERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_BTOERR_SHIFT)) & USB_FSERRSTAT_BTOERR_MASK)

#define USB_FSERRSTAT_DFN8_SHIFT                (3)
#define USB_FSERRSTAT_DFN8_MASK                 (0x01U << USB_FSERRSTAT_DFN8_SHIFT)
#define USB_FSERRSTAT_DFN8(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_DFN8_SHIFT)) & USB_FSERRSTAT_DFN8_MASK)

#define USB_FSERRSTAT_CRC16_SHIFT               (2)
#define USB_FSERRSTAT_CRC16_MASK                (0x01U << USB_FSERRSTAT_CRC16_SHIFT)
#define USB_FSERRSTAT_CRC16(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_CRC16_SHIFT)) & USB_FSERRSTAT_CRC16_MASK)

#define USB_FSERRSTAT_CRC5EOF_SHIFT            (1)
#define USB_FSERRSTAT_CRC5EOF_MASK             (0x01U << USB_FSERRSTAT_CRC5EOF_SHIFT)
#define USB_FSERRSTAT_CRC5EOF(x)               (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_CRC5EOF_SHIFT)) & USB_FSERRSTAT_CRC5EOF_MASK)

#define USB_FSERRSTAT_PIDERR_SHIFT              (0)
#define USB_FSERRSTAT_PIDERR_MASK               (0x01U << USB_FSERRSTAT_PIDERR_SHIFT)
#define USB_FSERRSTAT_PIDERR(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSERRSTAT_PIDERR_SHIFT)) & USB_FSERRSTAT_PIDERR_MASK)

/*!
 * @brief USB_FS_ERRENB Register Bit Definition
 */

#define USB_FSERRENB_BTSERR_SHIFT               (7)
#define USB_FSERRENB_BTSERR_MASK                (0x01U << USB_FSERRENB_BTSERR_SHIFT)
#define USB_FSERRENB_BTSERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_BTSERR_SHIFT)) & USB_FSERRENB_BTSERR_MASK)

#define USB_FSERRENB_DMAERR_SHIFT               (5)
#define USB_FSERRENB_DMAERR_MASK                (0x01U << USB_FSERRENB_DMAERR_SHIFT)
#define USB_FSERRENB_DMAERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_DMAERR_SHIFT)) & USB_FSERRENB_DMAERR_MASK)

#define USB_FSERRENB_BTOERR_SHIFT               (4)
#define USB_FSERRENB_BTOERR_MASK                (0x01U << USB_FSERRENB_BTOERR_SHIFT)
#define USB_FSERRENB_BTOERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_BTOERR_SHIFT)) & USB_FSERRENB_BTOERR_MASK)

#define USB_FSERRENB_DFN8_SHIFT                 (3)
#define USB_FSERRENB_DFN8_MASK                  (0x01U << USB_FSERRENB_DFN8_SHIFT)
#define USB_FSERRENB_DFN8(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_DFN8_SHIFT)) & USB_FSERRENB_DFN8_MASK)

#define USB_FSERRENB_CRC16_SHIFT                (2)
#define USB_FSERRENB_CRC16_MASK                 (0x01U << USB_FSERRENB_CRC16_SHIFT)
#define USB_FSERRENB_CRC16(x)                   (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_CRC16_SHIFT)) & USB_FSERRENB_CRC16_MASK)

#define USB_FSERRENB_CRC5EOF_SHIFT             (1)
#define USB_FSERRENB_CRC5EOF_MASK              (0x01U << USB_FSERRENB_CRC5EOF_SHIFT)
#define USB_FSERRENB_CRC5EOF(x)                (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_CRC5EOF_SHIFT)) & USB_FSERRENB_CRC5EOF_MASK)

#define USB_FSERRENB_PIDERR_SHIFT               (0)
#define USB_FSERRENB_PIDERR_MASK                (0x01U << USB_FSERRENB_PIDERR_SHIFT)
#define USB_FSERRENB_PIDERR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSERRENB_PIDERR_SHIFT)) & USB_FSERRENB_PIDERR_MASK)

/*!
 * @brief USB_FS_STAT Register Bit Definition
 */

#define USB_FSSTAT_ENDP_SHIFT                   (4)
#define USB_FSSTAT_ENDP_MASK                    (0xFU << USB_FSSTAT_ENDP_SHIFT)
#define USB_FSSTAT_ENDP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSSTAT_ENDP_SHIFT)) & USB_FSSTAT_ENDP_MASK)

#define USB_FSSTAT_TX_SHIFT                     (3)
#define USB_FSSTAT_TX_MASK                      (0x01U << USB_FSSTAT_TX_SHIFT)
#define USB_FSSTAT_TX(x)                        (((uint32_t)(((uint32_t)(x)) << USB_FSSTAT_TX_SHIFT)) & USB_FSSTAT_TX_MASK)

#define USB_FSSTAT_ODD_SHIFT                    (2)
#define USB_FSSTAT_ODD_MASK                     (0x01U << USB_FSSTAT_ODD_SHIFT)
#define USB_FSSTAT_ODD(x)                       (((uint32_t)(((uint32_t)(x)) << USB_FSSTAT_ODD_SHIFT)) & USB_FSSTAT_ODD_MASK)

/*!
 * @brief USB_FS_CTL Register Bit Definition
 */

#define USB_FSCTL_JSTATE_SHIFT                  (7)
#define USB_FSCTL_JSTATE_MASK                   (0x01U << USB_FSCTL_JSTATE_SHIFT)
#define USB_FSCTL_JSTATE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_JSTATE_SHIFT)) & USB_FSCTL_JSTATE_MASK)

#define USB_FSCTL_SE0_SHIFT                     (6)
#define USB_FSCTL_SE0_MASK                      (0x01U << USB_FSCTL_SE0_SHIFT)
#define USB_FSCTL_SE0(x)                        (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_SE0_SHIFT)) & USB_FSCTL_SE0_MASK)

#define USB_FSCTL_TXDSUSPENDTOKENBUSY_SHIFT     (5)
#define USB_FSCTL_TXDSUSPENDTOKENBUSY_MASK      (0x01U << USB_FSCTL_TXDSUSPENDTOKENBUSY_SHIFT)
#define USB_FSCTL_TXDSUSPENDTOKENBUSY(x)        (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_TXDSUSPENDTOKENBUSY_SHIFT)) & USB_FSCTL_TXDSUSPENDTOKENBUSY_MASK)

#define USB_FSCTL_RESET_SHIFT                   (4)
#define USB_FSCTL_RESET_MASK                    (0x01U << USB_FSCTL_RESET_SHIFT)
#define USB_FSCTL_RESET(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_RESET_SHIFT)) & USB_FSCTL_RESET_MASK)

#define USB_FSCTL_HOSTMODEEN_SHIFT              (3)
#define USB_FSCTL_HOSTMODEEN_MASK               (0x01U << USB_FSCTL_HOSTMODEEN_SHIFT)
#define USB_FSCTL_HOSTMODEEN(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_HOSTMODEEN_SHIFT)) & USB_FSCTL_HOSTMODEEN_MASK)

#define USB_FSCTL_RESUME_SHIFT                  (2)
#define USB_FSCTL_RESUME_MASK                   (0x01U << USB_FSCTL_RESUME_SHIFT)
#define USB_FSCTL_RESUME(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_RESUME_SHIFT)) & USB_FSCTL_RESUME_MASK)

#define USB_FSCTL_ODDRST_SHIFT                  (1)
#define USB_FSCTL_ODDRST_MASK                   (0x01U << USB_FSCTL_ODDRST_SHIFT)
#define USB_FSCTL_ODDRST(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_ODDRST_SHIFT)) & USB_FSCTL_ODDRST_MASK)

#define USB_FSCTL_USBEN_SHIFT                   (0)
#define USB_FSCTL_USBEN_MASK                    (0x01U << USB_FSCTL_USBEN_SHIFT)
#define USB_FSCTL_USBEN(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSCTL_USBEN_SHIFT)) & USB_FSCTL_USBEN_MASK)

/*!
 * @brief USB_FS_ADDR Register Bit Definition
 */

#define USB_FSADDR_LSEN_SHIFT                   (7)
#define USB_FSADDR_LSEN_MASK                    (0x01U << USB_FSADDR_LSEN_SHIFT)
#define USB_FSADDR_LSEN(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSADDR_LSEN_SHIFT)) & USB_FSADDR_LSEN_MASK)

#define USB_FSADDR_ADDR_SHIFT                   (0)
#define USB_FSADDR_ADDR_MASK                    (0x7FU << USB_FSADDR_ADDR_SHIFT)
#define USB_FSADDR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_FSADDR_ADDR_SHIFT)) & USB_FSADDR_ADDR_MASK)

/*!
 * @brief USB_FS_BDTPAGE1 Register Bit Definition
 */

#define USB_FSBDTPAGE1_BDTBA_SHIFT              (1)
#define USB_FSBDTPAGE1_BDTBA_MASK               (0x7FU << USB_FSBDTPAGE1_BDTBA_SHIFT)
#define USB_FSBDTPAGE1_BDTBA(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSBDTPAGE1_BDTBA_SHIFT)) & USB_FSBDTPAGE1_BDTBA_MASK)

/*!
 * @brief USB_FS_FRMNUML Register Bit Definition
 */

#define USB_FSFRMNUML_FRM_SHIFT                 (0)
#define USB_FSFRMNUML_FRM_MASK                  (0xFFU << USB_FSFRMNUML_FRM_SHIFT)
#define USB_FSFRMNUML_FRM(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSFRMNUML_FRM_SHIFT)) & USB_FSFRMNUML_FRM_MASK)

/*!
 * @brief USB_FS_FRMNUMH Register Bit Definition
 */

#define USB_FSFRMNUMH_FRM_SHIFT                 (0)
#define USB_FSFRMNUMH_FRM_MASK                  (0x7U << USB_FSFRMNUMH_FRM_SHIFT)
#define USB_FSFRMNUMH_FRM(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSFRMNUMH_FRM_SHIFT)) & USB_FSFRMNUMH_FRM_MASK)

/*!
 * @brief USB_FS_TOKEN Register Bit Definition
 */

#define USB_FSTOKEN_TOKENPID_SHIFT              (4)
#define USB_FSTOKEN_TOKENPID_MASK               (0xFU << USB_FSTOKEN_TOKENPID_SHIFT)
#define USB_FSTOKEN_TOKENPID(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSTOKEN_TOKENPID_SHIFT)) & USB_FSTOKEN_TOKENPID_MASK)

#define USB_FSTOKEN_TOKENENDPT_SHIFT            (0)
#define USB_FSTOKEN_TOKENENDPT_MASK             (0xFU << USB_FSTOKEN_TOKENENDPT_SHIFT)
#define USB_FSTOKEN_TOKENENDPT(x)               (((uint32_t)(((uint32_t)(x)) << USB_FSTOKEN_TOKENENDPT_SHIFT)) & USB_FSTOKEN_TOKENENDPT_MASK)

/*!
 * @brief USB_FS_SOFTHLD Register Bit Definition
 */

#define USB_FSSOFTHLD_CNT_SHIFT                 (0)
#define USB_FSSOFTHLD_CNT_MASK                  (0xFFU << USB_FSSOFTHLD_CNT_SHIFT)
#define USB_FSSOFTHLD_CNT(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSSOFTHLD_CNT_SHIFT)) & USB_FSSOFTHLD_CNT_MASK)

/*!
 * @brief USB_FS_BDTPAGE2 Register Bit Definition
 */

#define USB_FSBDTPAGE2_BDTBA_SHIFT              (0)
#define USB_FSBDTPAGE2_BDTBA_MASK               (0xFFU << USB_FSBDTPAGE2_BDTBA_SHIFT)
#define USB_FSBDTPAGE2_BDTBA(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSBDTPAGE2_BDTBA_SHIFT)) & USB_FSBDTPAGE2_BDTBA_MASK)

/*!
 * @brief USB_FS_BDTPAGE3 Register Bit Definition
 */

#define USB_FSBDTPAGE3_BDTBA_SHIFT              (0)
#define USB_FSBDTPAGE3_BDTBA_MASK               (0xFFU << USB_FSBDTPAGE3_BDTBA_SHIFT)
#define USB_FSBDTPAGE3_BDTBA(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSBDTPAGE3_BDTBA_SHIFT)) & USB_FSBDTPAGE3_BDTBA_MASK)

/*!
 * @brief USB_FS_EPCTL0 Register Bit Definition
 */

#define USB_FSEPCTL_HOSTWOHUB_SHIFT            (7)
#define USB_FSEPCTL_HOSTWOHUB_MASK             (0x01U << USB_FSEPCTL_HOSTWOHUB_SHIFT)
#define USB_FSEPCTL_HOSTWOHUB(x)               (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_HOSTWOHUB_SHIFT)) & USB_FSEPCTL_HOSTWOHUB_MASK)

#define USB_FSEPCTL_RETRYDIS_SHIFT             (6)
#define USB_FSEPCTL_RETRYDIS_MASK              (0x01U << USB_FSEPCTL_RETRYDIS_SHIFT)
#define USB_FSEPCTL_RETRYDIS(x)                (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_RETRYDIS_SHIFT)) & USB_FSEPCTL_RETRYDIS_MASK)

#define USB_FSEPCTL_EPCTLDISEPRXENEPTXEN_SHIFT (2)
#define USB_FSEPCTL_EPCTLDISEPRXENEPTXEN_MASK  (0x7U << USB_FSEPCTL_EPCTLDISEPRXENEPTXEN_SHIFT)
#define USB_FSEPCTL_EPCTLDISEPRXENEPTXEN(x)    (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPCTLDISEPRXENEPTXEN_SHIFT)) & USB_FSEPCTL_EPCTLDISEPRXENEPTXEN_MASK)

#define USB_FSEPCTL_EPSTALL_SHIFT              (1)
#define USB_FSEPCTL_EPSTALL_MASK               (0x01U << USB_FSEPCTL_EPSTALL_SHIFT)
#define USB_FSEPCTL_EPSTALL(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPSTALL_SHIFT)) & USB_FSEPCTL_EPSTALL_MASK)


#define USB_FSEPCTL_DIS_SHIFT                  (4)
#define USB_FSEPCTL_DIS_MASK                   (0x01U << USB_FSEPCTL_DIS_SHIFT)
#define USB_FSEPCTL_DIS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_DIS_SHIFT)) & USB_FSEPCTL_DIS_MASK)

#define USB_FSEPCTL_RXEN_SHIFT                 (3)
#define USB_FSEPCTL_RXEN_MASK                  (0x01U << USB_FSEPCTL_RXEN_SHIFT)
#define USB_FSEPCTL_RXEN(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_RXEN_SHIFT)) & USB_FSEPCTL_RXEN_MASK)
                                               
#define USB_FSEPCTL_TXEN_SHIFT                 (2)
#define USB_FSEPCTL_TXEN_MASK                  (0x01U << USB_FSEPCTL_TXEN_SHIFT)
#define USB_FSEPCTL_TXEN(x)                    (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_TXEN_SHIFT)) & USB_FSEPCTL_TXEN_MASK)

#define USB_FSEPCTL_EPHSHK_SHIFT               (0)
#define USB_FSEPCTL_EPHSHK_MASK                (0x01U << USB_FSEPCTL_EPHSHK_SHIFT)
#define USB_FSEPCTL_EPHSHK(x)                  (((uint32_t)(((uint32_t)(x)) << USB_FSEPCTL_EPHSHK_SHIFT)) & USB_FSEPCTL_EPHSHK_MASK)
/*!
 * @brief USB_FS_USBCTRL Register Bit Definition
 */

#define USB_FSUSBCTRL_SUSPE_SHIFT              (7)
#define USB_FSUSBCTRL_SUSPE_MASK               (0x01U << USB_FSUSBCTRL_SUSPE_SHIFT)
#define USB_FSUSBCTRL_SUSPE(x)                 (((uint32_t)(((uint32_t)(x)) << USB_FSUSBCTRL_SUSPE_SHIFT)) & USB_FSUSBCTRL_SUSPE_MASK)

/*!
 * @}
 */ /* end of group USB_Register_Masks */
/******************************************************************************
 *USB Instance
*******************************************************************************/

#define USB                  ((USB_Type*)USB_BASE)
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


