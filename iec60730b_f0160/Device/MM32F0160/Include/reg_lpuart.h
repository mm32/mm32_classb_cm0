/*
 *******************************************************************************
    @file     reg_lpuart.h
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

#ifndef __REG_LPUART_H
#define __REG_LPUART_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>

#if 0
/* IP_LPUART_DesignSpec_v1.2 */
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
/* anonymous unions are enabled by default */
#else
#warning Not supported compiler type
#endif



/**
  * @brief LPUART Base Address Definition
  */
#define LPUART_BASE                     (APB2PERIPH_BASE + 0x0800)              /*!< Base Address: 0x40010800 */

/**
  * @brief LPUART Register Structure Definition
  */
typedef struct {
    __IO uint32_t LPUBAUD;                                                      /*!< Baud rate register                                offset: 0x00 */
    __IO uint32_t MODU;                                                         /*!< Baud rate module control register                 offset: 0x04 */
    __IO uint32_t LPUIF;                                                        /*!< Interrupt flag register                           offset: 0x08 */
    __IO uint32_t LPUSTA;                                                       /*!< Status register                                   offset: 0x0C */
    __IO uint32_t LPUCON;                                                       /*!< Control register                                  offset: 0x10 */
    __IO uint32_t LPUEN;                                                        /*!< Receive enable register                           offset: 0x14 */
    __IO uint32_t LPURXD;                                                       /*!< Receive data register                             offset: 0x18 */
    __IO uint32_t LPUTXD;                                                       /*!< Send data register                                offset: 0x1C */
    __IO uint32_t COMPARE;                                                      /*!< Data match register                               offset: 0x20 */
    __IO uint32_t WKCKE;                                                        /*!< Wakeup  register                                  offset: 0x24 */
} LPUART_TypeDef;

/**
  * @brief LPUART type pointer Definition
  */
#define LPUART1                         ((LPUART_TypeDef*) LPUART_BASE)

/**
  * @brief LPUART_LPUBAUD Register Bit Definition
  */
#define LPUART_LPUBAUD_BAUD_Pos         (0)
#define LPUART_LPUBAUD_BAUD_Msk         (0x07U << LPUART_LPUBAUD_BAUD_Pos)      /*!< LPUART Baud Msk */
#define LPUART_LPUBAUD_BAUD_0           (0x00U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 9600 bps */
#define LPUART_LPUBAUD_BAUD_1           (0x01U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 4800 bps */
#define LPUART_LPUBAUD_BAUD_2           (0x02U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 2400 bps */
#define LPUART_LPUBAUD_BAUD_3           (0x03U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 1200 bps */
#define LPUART_LPUBAUD_BAUD_4           (0x04U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 600  bps */
#define LPUART_LPUBAUD_BAUD_5           (0x05U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 300  bps */
#define LPUART_LPUBAUD_BAUD_6           (0x06U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 300  bps */
#define LPUART_LPUBAUD_BAUD_7           (0x07U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 300  bps */

#define LPUART_LPUBAUD_BAUD_9600        (0x00U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 9600 bps */
#define LPUART_LPUBAUD_BAUD_4800        (0x01U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 4800 bps */
#define LPUART_LPUBAUD_BAUD_2400        (0x02U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 2400 bps */
#define LPUART_LPUBAUD_BAUD_1200        (0x03U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 1200 bps */
#define LPUART_LPUBAUD_BAUD_600         (0x04U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 600  bps */
#define LPUART_LPUBAUD_BAUD_300         (0x05U << LPUART_LPUBAUD_BAUD_Pos)      /*!< Baud is 300  bps */

#define LPUART_LPUBAUD_BREN_Pos         (8)
#define LPUART_LPUBAUD_BREN             (0x01U << LPUART_LPUBAUD_BREN_Pos)      /*!< Baud rate division enable */

#define LPUART_LPUBAUD_BR_Pos           (16)
#define LPUART_LPUBAUD_BR               (0xFFFFU << LPUART_LPUBAUD_BR_Pos)      /*!< Baud rate division */

/**
  * @brief LPUART_MODU Register Bit Definition
  */
#define LPUART_MODU_MCTL_Pos            (0)
#define LPUART_MODU_MCTL                (0xFFFU << LPUART_MODU_MCTL_Pos)        /*!< Bit modulation control signal */

/**
  * @brief LPUART_LPUIF Register Bit Definition
  */
#define LPUART_LPUIF_RXIF_Pos           (0)
#define LPUART_LPUIF_RXIF               (0x01U << LPUART_LPUIF_RXIF_Pos)        /*!< Receive data finish interrupt flag */
#define LPUART_LPUIF_TXIF_Pos           (1)
#define LPUART_LPUIF_TXIF               (0x01U << LPUART_LPUIF_TXIF_Pos)        /*!< Transmit buffer empty interrupt flag */
#define LPUART_LPUIF_RXNEGIF_Pos        (2)
#define LPUART_LPUIF_RXNEGIF            (0x01U << LPUART_LPUIF_RXNEGIF_Pos)     /*!< Received falling edge interrupt flag */
#define LPUART_LPUIF_TCIF_Pos           (3)
#define LPUART_LPUIF_TCIF               (0x01U << LPUART_LPUIF_TCIF_Pos)        /*!< Transmit complete interrupt complete flag */

/**
  * @brief LPUART_LPUSTA Register Bit Definition
  */
#define LPUART_LPUSTA_RXOV_Pos          (0)
#define LPUART_LPUSTA_RXOV              (0x01U << LPUART_LPUSTA_RXOV_Pos)       /*!< Receive buffer overflow flag */
#define LPUART_LPUSTA_FERR_Pos          (1)
#define LPUART_LPUSTA_FERR              (0x01U << LPUART_LPUSTA_FERR_Pos)       /*!< Frame format error flag */
#define LPUART_LPUSTA_MATCH_Pos         (2)
#define LPUART_LPUSTA_MATCH             (0x01U << LPUART_LPUSTA_MATCH_Pos)      /*!< Data is matched flag */
#define LPUART_LPUSTA_RXF_Pos           (3)
#define LPUART_LPUSTA_RXF               (0x01U << LPUART_LPUSTA_RXF_Pos)        /*!< Receive buffer is fulled flag */
#define LPUART_LPUSTA_TXE_Pos           (4)
#define LPUART_LPUSTA_TXE               (0x01U << LPUART_LPUSTA_TXE_Pos)        /*!< Transmit buffer empty flag */
#define LPUART_LPUSTA_TC_Pos            (5)
#define LPUART_LPUSTA_TC                (0x01U << LPUART_LPUSTA_TC_Pos)         /*!< Transmit data completed flag */
#define LPUART_LPUSTA_PERR_Pos          (6)
#define LPUART_LPUSTA_PERR              (0x01U << LPUART_LPUSTA_PERR_Pos)       /*!< Check bit error flag */
#define LPUART_LPUSTA_START_Pos         (7)
#define LPUART_LPUSTA_START             (0x01U << LPUART_LPUSTA_START_Pos)      /*!< Start bit detected flag */

/**
  * @brief LPUART_LPUCON Register Bit Definition
  */
#define LPUART_LPUCON_RXIE_Pos          (0)
#define LPUART_LPUCON_RXIE              (0x01U << LPUART_LPUCON_RXIE_Pos)       /*!< Receive interrupt enable */
#define LPUART_LPUCON_NEDET_Pos         (1)
#define LPUART_LPUCON_NEDET             (0x01U << LPUART_LPUCON_NEDET_Pos)      /*!< Falling edge sample enable bit */
#define LPUART_LPUCON_TXIE_Pos          (2)
#define LPUART_LPUCON_TXIE              (0x01U << LPUART_LPUCON_TXIE_Pos)       /*!< Transmit buffer empty interrupt enable */
#define LPUART_LPUCON_TCIE_Pos          (3)
#define LPUART_LPUCON_TCIE              (0x01U << LPUART_LPUCON_TCIE_Pos)       /*!< Transmit complete interrupt enable */
#define LPUART_LPUCON_ERRIE_Pos         (4)
#define LPUART_LPUCON_ERRIE             (0x01U << LPUART_LPUCON_ERRIE_Pos)      /*!< Receive error interrupt enable */
#define LPUART_LPUCON_RXEV_Pos          (5)
#define LPUART_LPUCON_RXEV              (0x03U << LPUART_LPUCON_RXEV_Pos)
#define LPUART_LPUCON_RXEV_0            (0x00U << LPUART_LPUCON_RXEV_Pos)       /*!< START bit detection wake-up */
#define LPUART_LPUCON_RXEV_1            (0x01U << LPUART_LPUCON_RXEV_Pos)       /*!< One byte data reception completed */
#define LPUART_LPUCON_RXEV_2            (0x02U << LPUART_LPUCON_RXEV_Pos)       /*!< Received data matched successfully */
#define LPUART_LPUCON_RXEV_3            (0x03U << LPUART_LPUCON_RXEV_Pos)       /*!< Falling edge detection wake up */
#define LPUART_LPUCON_DL_Pos            (7)
#define LPUART_LPUCON_DL                (0x01U << LPUART_LPUCON_DL_Pos)         /*!< Data length */
#define LPUART_LPUCON_SL_Pos            (8)
#define LPUART_LPUCON_SL                (0x01U << LPUART_LPUCON_SL_Pos)         /*!< Stop bit length */
#define LPUART_LPUCON_PTYP_Pos          (9)
#define LPUART_LPUCON_PTYP              (0x01U << LPUART_LPUCON_PTYP_Pos)       /*!< Odd parity */
#define LPUART_LPUCON_PAREN_Pos         (10)
#define LPUART_LPUCON_PAREN             (0x01U << LPUART_LPUCON_PAREN_Pos)      /*!< Check bit enable */
#define LPUART_LPUCON_RXPOL_Pos         (11)
#define LPUART_LPUCON_RXPOL             (0x01U << LPUART_LPUCON_RXPOL_Pos)      /*!< Receive data polarity */
#define LPUART_LPUCON_TXPOL_Pos         (12)
#define LPUART_LPUCON_TXPOL             (0x01U << LPUART_LPUCON_TXPOL_Pos)      /*!< Transmit data polarity */


/**
  * @brief LPUART_LPUEN Register Bit Definition
  */
#define LPUART_LPUEN_TXEN_Pos           (0)
#define LPUART_LPUEN_TXEN               (0x01U << LPUART_LPUEN_TXEN_Pos)        /*!< Transmit enable */
#define LPUART_LPUEN_RXEN_Pos           (1)
#define LPUART_LPUEN_RXEN               (0x01U << LPUART_LPUEN_RXEN_Pos)        /*!< Receive enable */
#define LPUART_LPUEN_DMAT_Pos           (2)
#define LPUART_LPUEN_DMAT               (0x01U << LPUART_LPUEN_DMAT_Pos)        /*!< DMA transmission for LPUART enable */
#define LPUART_LPUEN_DMAR_Pos           (3)
#define LPUART_LPUEN_DMAR               (0x01U << LPUART_LPUEN_DMAR_Pos)        /*!< DMA receive enable */

/**
  * @brief LPUART_LPURXD Register Bit Definition
  */
#define LPUART_LPURXD_DATA_Pos          (0)
#define LPUART_LPURXD_DATA              (0xFFU << LPUART_LPURXD_DATA_Pos)       /*!< Receive data buffer */

/**
  * @brief LPUART_LPUTXD Register Bit Definition
  */
#define LPUART_LPUTXD_DATA_Pos          (0)
#define LPUART_LPUTXD_DATA              (0xFFU << LPUART_LPUTXD_DATA_Pos)       /*!< send data buffer */

/**
  * @brief LPUART_COMPARE Register Bit Definition
  */
#define LPUART_COMPARE_Pos              (0)
#define LPUART_COMPARE                  (0xFFU << LPUART_COMPARE_Pos)           /*!< compare data */

/**
  * @brief LPUART_WKCKE Register Bit Definition
  */
#define LPUART_WKCKE_Pos                (0)
#define LPUART_WKCKE                    (0x01U << LPUART_WKCKE_Pos)             /*!< Wakeup mode setting */

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
