/*
 *******************************************************************************
    @file     reg_spi.h
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

#ifndef __REG_SPI_H
#define __REG_SPI_H

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
  * @brief SPI Base Address Definition
  */
#define SPI2_BASE                       (APB1PERIPH_BASE + 0x3800)              /*!< Base Address: 0x40003800 */
#define SPI1_BASE                       (APB2PERIPH_BASE + 0x3000)              /*!< Base Address: 0x40013000 */

/**
  * @brief SPI Register Structure Definition
  */
typedef struct {
    __IO uint32_t TXREG;                                                        /*!< SPI transmit data register,        offset: 0x00 */
    __IO uint32_t RXREG;                                                        /*!< SPI receive data register,         offset: 0x04 */
    __IO uint32_t CSTAT;                                                        /*!< SPI current state register,        offset: 0x08 */
    __IO uint32_t INTSTAT;                                                      /*!< SPI interruput state register,     offset: 0x0C */
    __IO uint32_t INTEN;                                                        /*!< SPI interruput enable register,    offset: 0x10 */
    __IO uint32_t INTCLR;                                                       /*!< SPI interruput control register,   offset: 0x14 */
    __IO uint32_t GCTL;                                                         /*!< SPI global control register,       offset: 0x18 */
    __IO uint32_t CCTL;                                                         /*!< SPI common control register,       offset: 0x1C */
    __IO uint32_t SPBRG;                                                        /*!< SPI baud rate control register,    offset: 0x20 */
    __IO uint32_t RXDNR;                                                        /*!< SPI receive data number register,  offset: 0x24 */
    __IO uint32_t NSSR;                                                         /*!< SPI chip select register,          offset: 0x28 */
    __IO uint32_t EXTCTL;                                                       /*!< SPI extand control register,       offset: 0x2C */
    __IO uint32_t I2SCFGR;                                                      /*!< I2S configuration register,        offset: 0x30 */
} SPI_TypeDef;

/**
  * @brief SPI type pointer Definition
  */
#define SPI2                            ((SPI_TypeDef*) SPI2_BASE)
#define SPI1                            ((SPI_TypeDef*) SPI1_BASE)
/**
  * @brief SPI_TXREG Register Bit Definition
  */
#define SPI_TXREG_Pos                   (0)
#define SPI_TXREG                       (0xFFFFFFFFU << SPI_TXREG_Pos)          /*!< Transmit data register */

/**
  * @brief SPI_RXREG Register Bit Definition
  */
#define SPI_RXREG_Pos                   (0)
#define SPI_RXREG                       (0xFFFFFFFFU << SPI_RXREG_Pos)          /*!< Receive data register */

/**
  * @brief SPI_CSTAT Register Bit Definition
  */
#define SPI_CSTAT_TXEPT_Pos             (0)
#define SPI_CSTAT_TXEPT                 (0x01U << SPI_CSTAT_TXEPT_Pos)          /*!< Transmitter empty bit */
#define SPI_CSTAT_RXAVL_Pos             (1)
#define SPI_CSTAT_RXAVL                 (0x01U << SPI_CSTAT_RXAVL_Pos)          /*!< Receive available byte data message */
#define SPI_CSTAT_TXFULL_Pos            (2)
#define SPI_CSTAT_TXFULL                (0x01U << SPI_CSTAT_TXFULL_Pos)         /*!< Transmitter FIFO full status bit */
#define SPI_CSTAT_RXAVL_4BYTE_Pos       (3)
#define SPI_CSTAT_RXAVL_4BYTE           (0x01U << SPI_CSTAT_RXAVL_4BYTE_Pos)    /*!< Receive available 4 byte data message */
#define SPI_CSTAT_TXFADDR_Pos           (4)
#define SPI_CSTAT_TXFADDR               (0x0FU << SPI_CSTAT_TXFADDR_Pos)        /*!< Transmit FIFO address */
#define SPI_CSTAT_RXFADDR_Pos           (8)
#define SPI_CSTAT_RXFADDR               (0x0FU << SPI_CSTAT_RXFADDR_Pos)        /*!< Receive FIFO address */
#define SPI_CSTAT_BUSY_Pos              (12)
#define SPI_CSTAT_BUSY                  (0x01U << SPI_CSTAT_BUSY_Pos)           /*!< Data transfer flag */
#define SPI_CSTAT_CHSIDE_Pos            (13)
#define SPI_CSTAT_CHSIDE                (0x01U << SPI_CSTAT_CHSIDE_Pos)         /*!< transmission channel */

/**
  * @brief SPI_INTSTAT Register Bit Definition
  */
#define SPI_INTSTAT_TX_INTF_Pos         (0)
#define SPI_INTSTAT_TX_INTF             (0x01U << SPI_INTSTAT_TX_INTF_Pos)      /*!< Transmit FIFO available interrupt flag bit */
#define SPI_INTSTAT_RX_INTF_Pos         (1)
#define SPI_INTSTAT_RX_INTF             (0x01U << SPI_INTSTAT_RX_INTF_Pos)      /*!< Receive data available interrupt flag bit */
#define SPI_INTSTAT_UNDERRUN_INTF_Pos   (2)
#define SPI_INTSTAT_UNDERRUN_INTF       (0x01U << SPI_INTSTAT_UNDERRUN_INTF_Pos)/*!< SPI underrun interrupt flag bit */
#define SPI_INTSTAT_RXOERR_INTF_Pos     (3)
#define SPI_INTSTAT_RXOERR_INTF         (0x01U << SPI_INTSTAT_RXOERR_INTF_Pos)  /*!< Receive overrun error interrupt flag bit */
#define SPI_INTSTAT_RXMATCH_INTF_Pos    (4)
#define SPI_INTSTAT_RXMATCH_INTF        (0x01U << SPI_INTSTAT_RXMATCH_INTF_Pos) /*!< Receive data match the RXDNR number, the receive process will be completed and generate the interrupt */
#define SPI_INTSTAT_RXFULL_INTF_Pos     (5)
#define SPI_INTSTAT_RXFULL_INTF         (0x01U << SPI_INTSTAT_RXFULL_INTF_Pos)  /*!< RX FIFO full interrupt flag bit */
#define SPI_INTSTAT_TXEPT_INTF_Pos      (6)
#define SPI_INTSTAT_TXEPT_INTF          (0x01U << SPI_INTSTAT_TXEPT_INTF_Pos)   /*!< Transmitter empty interrupt flag bit */
#define SPI_INTSTAT_FRE_INTF_Pos        (7)
#define SPI_INTSTAT_FRE_INTF            (0x01U << SPI_INTSTAT_FRE_INTF_Pos)     /*!< I2S frame transmission error flag bit */

/**
  * @brief SPI_INTEN Register Bit Definition
  */
#define SPI_INTEN_TX_IEN_Pos            (0)
#define SPI_INTEN_TX_IEN                (0x01U << SPI_INTEN_TX_IEN_Pos)         /*!< Transmit FIFO empty interrupt enable bit */
#define SPI_INTEN_RX_IEN_Pos            (1)
#define SPI_INTEN_RX_IEN                (0x01U << SPI_INTEN_RX_IEN_Pos)         /*!< Receive FIFO interrupt enable bit */
#define SPI_INTEN_UNDERRUN_IEN_Pos      (2)
#define SPI_INTEN_UNDERRUN_IEN          (0x01U << SPI_INTEN_UNDERRUN_IEN_Pos)   /*!< Transmitter underrun interrupt enable bit */
#define SPI_INTEN_RXOERR_IEN_Pos        (3)
#define SPI_INTEN_RXOERR_IEN            (0x01U << SPI_INTEN_RXOERR_IEN_Pos)     /*!< Overrun error interrupt enable bit */
#define SPI_INTEN_RXMATCH_IEN_Pos       (4)
#define SPI_INTEN_RXMATCH_IEN           (0x01U << SPI_INTEN_RXMATCH_IEN_Pos)    /*!< Receive data complete interrupt enable bit */
#define SPI_INTEN_RXFULL_IEN_Pos        (5)
#define SPI_INTEN_RXFULL_IEN            (0x01U << SPI_INTEN_RXFULL_IEN_Pos)     /*!< Receive FIFO full interrupt enable bit */
#define SPI_INTEN_TXEPT_IEN_Pos         (6)
#define SPI_INTEN_TXEPT_IEN             (0x01U << SPI_INTEN_TXEPT_IEN_Pos)      /*!< Transmit empty interrupt enable bit */
#define SPI_INTEN_FRE_IEN_Pos           (7)
#define SPI_INTEN_FRE_IEN               (0x01U << SPI_INTEN_FRE_IEN_Pos)        /*!< I2S frame transmission interrupt enable bit */


/**
  * @brief SPI_INTCLR Register Bit Definition
  */
#define SPI_INTCLR_TX_ICLR_Pos          (0)
#define SPI_INTCLR_TX_ICLR              (0x01U << SPI_INTCLR_TX_ICLR_Pos)       /*!< Transmitter FIFO empty interrupt clear bit */
#define SPI_INTCLR_RX_ICLR_Pos          (1)
#define SPI_INTCLR_RX_ICLR              (0x01U << SPI_INTCLR_RX_ICLR_Pos)       /*!< Receive interrupt clear bit */
#define SPI_INTCLR_UNDERRUN_ICLR_Pos    (2)
#define SPI_INTCLR_UNDERRUN_ICLR        (0x01U << SPI_INTCLR_UNDERRUN_ICLR_Pos) /*!< Transmitter underrun interrupt clear bit */
#define SPI_INTCLR_RXOERR_ICLR_Pos      (3)
#define SPI_INTCLR_RXOERR_ICLR          (0x01U << SPI_INTCLR_RXOERR_ICLR_Pos)   /*!< Overrun error interrupt clear bit */
#define SPI_INTCLR_RXMATCH_ICLR_Pos     (4)
#define SPI_INTCLR_RXMATCH_ICLR         (0x01U << SPI_INTCLR_RXMATCH_ICLR_Pos)  /*!< Receive completed interrupt clear bit */
#define SPI_INTCLR_RXFULL_ICLR_Pos      (5)
#define SPI_INTCLR_RXFULL_ICLR          (0x01U << SPI_INTCLR_RXFULL_ICLR_Pos)   /*!< Receiver buffer full interrupt clear bit */
#define SPI_INTCLR_TXEPT_ICLR_Pos       (6)
#define SPI_INTCLR_TXEPT_ICLR           (0x01U << SPI_INTCLR_TXEPT_ICLR_Pos)    /*!< Transmitter empty interrupt clear bit */
#define SPI_INTCLR_FRE_ICLR_Pos         (7)
#define SPI_INTCLR_FRE_ICLR             (0x01U << SPI_INTCLR_FRE_ICLR_Pos)      /*!< I2S frame transmission interrupt clear bit */

/**
  * @brief SPI_GCTL Register Bit Definition
  */
#define SPI_GCTL_SPIEN_Pos              (0)
#define SPI_GCTL_SPIEN                  (0x01U << SPI_GCTL_SPIEN_Pos)           /*!< SPI select bit */
#define SPI_GCTL_INTEN_Pos              (1)
#define SPI_GCTL_INTEN                  (0x01U << SPI_GCTL_INTEN_Pos)           /*!< SPI interrupt enable bit */
#define SPI_GCTL_MODE_Pos               (2)
#define SPI_GCTL_MODE                   (0x01U << SPI_GCTL_MODE_Pos)            /*!< Master mode bit */
#define SPI_GCTL_TXEN_Pos               (3)
#define SPI_GCTL_TXEN                   (0x01U << SPI_GCTL_TXEN_Pos)            /*!< Transmit enable bit */
#define SPI_GCTL_RXEN_Pos               (4)
#define SPI_GCTL_RXEN                   (0x01U << SPI_GCTL_RXEN_Pos)            /*!< Receive enable bit */
#define SPI_GCTL_RXTLF_Pos               (5)
#define SPI_GCTL_RXTLF                   (0x03U << SPI_GCTL_RXTLF_Pos)          /*!< RX FIFO trigger level bit */
#define SPI_GCTL_RXTLF_One               (0x00U << SPI_GCTL_RXTLF_Pos)
#define SPI_GCTL_RXTLF_Half              (0x01U << SPI_GCTL_RXTLF_Pos)
#define SPI_GCTL_TXTLF_Pos               (7)
#define SPI_GCTL_TXTLF                   (0x03U << SPI_GCTL_TXTLF_Pos)          /*!< TX FIFO trigger level bit */
#define SPI_GCTL_TXTLF_One               (0x00U << SPI_GCTL_TXTLF_Pos)
#define SPI_GCTL_TXTLF_Half              (0x01U << SPI_GCTL_TXTLF_Pos)
#define SPI_GCTL_DMAMODE_Pos            (9)
#define SPI_GCTL_DMAMODE                (0x01U << SPI_GCTL_DMAMODE_Pos)         /*!< DMA access mode enable */
#define SPI_GCTL_NSS_Pos                (10)
#define SPI_GCTL_NSS                    (0x01U << SPI_GCTL_NSS_Pos)             /*!< NSS select signal that from software or hardware */
#define SPI_GCTL_DW_8_32_Pos            (11)
#define SPI_GCTL_DW_8_32                (0x01U << SPI_GCTL_DW_8_32_Pos)         /*!< Valid byte or double-word data select signal */
#define SPI_GCTL_PAD_SEL_Pos            (13)
#define SPI_GCTL_PAD_SEL                (0x1FU << SPI_GCTL_PAD_SEL_Pos)         /*!< Bus mapping transformation */

/**
  * @brief SPI_CCTL Register Bit Definition
  */
#define SPI_CCTL_CPHA_Pos               (0)
#define SPI_CCTL_CPHA                   (0x01U << SPI_CCTL_CPHA_Pos)            /*!< Clock phase select bit */
#define SPI_CCTL_CPOL_Pos               (1)
#define SPI_CCTL_CPOL                   (0x01U << SPI_CCTL_CPOL_Pos)            /*!< Clock polarity select bit */
#define SPI_CCTL_LSBFE_Pos              (2)
#define SPI_CCTL_LSBFE                  (0x01U << SPI_CCTL_LSBFE_Pos)           /*!< LSI first enable bit */
#define SPI_CCTL_SPILEN_Pos             (3)
#define SPI_CCTL_SPILEN                 (0x01U << SPI_CCTL_SPILEN_Pos)          /*!< SPI character length bit */
#define SPI_CCTL_RXEDGE_Pos             (4)
#define SPI_CCTL_RXEDGE                 (0x01U << SPI_CCTL_RXEDGE_Pos)          /*!< Receive data edge select */
#define SPI_CCTL_TXEDGE_Pos             (5)
#define SPI_CCTL_TXEDGE                 (0x01U << SPI_CCTL_TXEDGE_Pos)          /*!< Transmit data edge select */
#define SPI_CCTL_CPHASEL_Pos            (6)
#define SPI_CCTL_CPHASEL                (0x01U << SPI_CCTL_CPHASEL_Pos)         /*!< CPHA polarity select */


/**
  * @brief SPI_SPBRG Register Bit Definition
  */
#define SPI_SPBRG_Pos                   (0)
#define SPI_SPBRG                       (0xFFFFU << SPI_SPBRG_Pos)              /*!< SPI baud rate control register for baud rate */

/**
  * @brief SPI_RXDNR Register Bit Definition
  */
#define SPI_RXDNR_Pos                   (0)
#define SPI_RXDNR                       (0xFFFFU << SPI_RXDNR_Pos)              /*!< The register is used to hold a count of to be received bytes in next receive process */

/**
  * @brief SPI_NSSR Register Bit Definition
  */
#define SPI_NSSR_NSS_Pos                (0)
#define SPI_NSSR_NSS                    (0x01U << SPI_NSSR_NSS_Pos)             /*!< Chip select output signal in Master mode */

/**
  * @brief SPI_EXTCTL Register Bit Definition
  */
#define SPI_EXTCTL_EXTLEN_Pos           (0)
#define SPI_EXTCTL_EXTLEN               (0x1FU << SPI_EXTCTL_EXTLEN_Pos)        /*!< control SPI data length */

/**
  * @brief SPI_I2SCFGR Register Bit Definition
  */
#define SPI_I2SCFGR_CLEAR_Mask          ((u32)0xFE00F388)
#define SPI_I2SCFGR_CHLEN_Pos           (0)
#define SPI_I2SCFGR_CHLEN               (0x01U << SPI_I2SCFGR_CHLEN_Pos)        /*!< Vocal tract length */
#define SPI_I2SCFGR_DATLEN_Pos          (1)
#define SPI_I2SCFGR_DATLEN_16           (0x00U << SPI_I2SCFGR_DATLEN_Pos)       /*!< Audio data width 16 */
#define SPI_I2SCFGR_DATLEN_24           (0x01U << SPI_I2SCFGR_DATLEN_Pos)       /*!< Audio data width 24 */
#define SPI_I2SCFGR_DATLEN_32           (0x02U << SPI_I2SCFGR_DATLEN_Pos)       /*!< Audio data width 32 */

#define SPI_I2SCFGR_I2SSTD_Pos          (4)
#define SPI_I2SCFGR_I2SSTD_Philips      (0x00U << SPI_I2SCFGR_I2SSTD_Pos)       /*!< I2S selection Philips standard */
#define SPI_I2SCFGR_I2SSTD_MSB_L        (0x01U << SPI_I2SCFGR_I2SSTD_Pos)       /*!< I2S selection Left aligned (MSB) standard */
#define SPI_I2SCFGR_I2SSTD_MSB_R        (0x02U << SPI_I2SCFGR_I2SSTD_Pos)       /*!< I2S selection Right alignment (MSB) standard */
#define SPI_I2SCFGR_I2SSTD_PCM          (0x03U << SPI_I2SCFGR_I2SSTD_Pos)       /*!< I2S selection PCM standard */

#define SPI_I2SCFGR_PCMSYNC_Pos         (6)
#define SPI_I2SCFGR_PCMSYNC             (0x01U << SPI_I2SCFGR_PCMSYNC_Pos)      /*!< PCM frame synchronization mode */

#define SPI_I2SCFGR_SPI_I2S_Pos         (10)
#define SPI_I2SCFGR_SPI_I2S             (0x01U << SPI_I2SCFGR_SPI_I2S_Pos)      /*!< SPI/I2S module function selection */
#define SPI_I2SCFGR_MCKOE_Pos           (11)
#define SPI_I2SCFGR_MCKOE               (0x01U << SPI_I2SCFGR_MCKOE_Pos)        /*!< I2S master clock output enable */
#define SPI_I2SCFGR_I2SDIV_Pos          (16)
#define SPI_I2SCFGR_I2SDIV              (0x1FFU << SPI_I2SCFGR_I2SDIV_Pos)      /*!< The frequency division */

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
