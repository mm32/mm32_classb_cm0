/*
 *******************************************************************************
    @file     reg_uart.h
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

#ifndef __REG_UART_H
#define __REG_UART_H

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
  * @brief UART Base Address Definition
  */
#define UART1_BASE                      (APB2PERIPH_BASE + 0x3800)              /*!< Base Address: 0x40013800 */
#define UART2_BASE                      (APB1PERIPH_BASE + 0x4400)              /*!< Base Address: 0x40004400 */
#define UART3_BASE                      (APB1PERIPH_BASE + 0x4800)              /*!< Base Address: 0x40004800 */
#define UART4_BASE                      (APB1PERIPH_BASE + 0x4C00)              /*!< Base Address: 0x40004C00 */

/**
  * @brief UART Register Structure Definition
  */
typedef struct {
    __IO uint32_t TDR;                                                          /*!< Transmit Data Register,                        offset: 0x00 */
    __IO uint32_t RDR;                                                          /*!< Receive Data Register,                         offset: 0x04 */
    __IO uint32_t CSR;                                                          /*!< Current Status Register,                       offset: 0x08 */
    __IO uint32_t ISR;                                                          /*!< Interrupt Status Register,                     offset: 0x0C */
    __IO uint32_t IER;                                                          /*!< Interrupt Enable Register,                     offset: 0x10 */
    __IO uint32_t ICR;                                                          /*!< Interrupt Clear Register,                      offset: 0x14 */
    __IO uint32_t GCR;                                                          /*!< Global Control Register,                       offset: 0x18 */
    __IO uint32_t CCR;                                                          /*!< Config Control Register,                       offset: 0x1C */
    __IO uint32_t BRR;                                                          /*!< Baud Rate Register,                            offset: 0x20 */
    __IO uint32_t FRA;                                                          /*!< Fraction Register,                             offset: 0x24 */
    __IO uint32_t RXADDR;                                                       /*!< Receive Address Register,                      offset: 0x28 */
    __IO uint32_t RXMASK;                                                       /*!< Receive Address Mask Register,                 offset: 0x2C */
    __IO uint32_t SCR;                                                          /*!< Smart Card Register,                           offset: 0x30 */
    __IO uint32_t IDLR;                                                         /*!< Data length register                           offset: 0x34 */
    __IO uint32_t ABRCR;                                                        /*!< automatic Baud rate control delivery           offset: 0x38 */
    __IO uint32_t IRDA;                                                         /*!< Infrared function control register             offset: 0x3C */
} UART_TypeDef;

/**
  * @brief UART type pointer Definition
  */
#define UART1                           ((UART_TypeDef*) UART1_BASE)
#define UART2                           ((UART_TypeDef*) UART2_BASE)
#define UART3                           ((UART_TypeDef*) UART3_BASE)
#define UART4                           ((UART_TypeDef*) UART4_BASE)
/**
  * @brief UART_TDR Register Bit Definition
  */
#define UART_TDR_TXREG_Pos              (0)
#define UART_TDR_TXREG                  (0x1FFU << UART_TDR_TXREG_Pos)          /*!< Transmit data register */

/**
  * @brief UART_RDR Register Bit Definition
  */
#define UART_RDR_RXREG_Pos              (0)
#define UART_RDR_RXREG                  (0x1FFU << UART_RDR_RXREG_Pos)          /*!< Receive data register */

/**
  * @brief UART_CSR Register Bit Definition
  */
#define UART_CSR_TXC_Pos                (0)
#define UART_CSR_TXC                    (0x01U << UART_CSR_TXC_Pos)             /*!< Transmit complete flag bit */
#define UART_CSR_RXAVL_Pos              (1)
#define UART_CSR_RXAVL                  (0x01U << UART_CSR_RXAVL_Pos)           /*!< Receive valid data flag bit */
#define UART_CSR_TXFULL_Pos             (2)
#define UART_CSR_TXFULL                 (0x01U << UART_CSR_TXFULL_Pos)          /*!< Transmit buffer full flag bit */
#define UART_CSR_TXEPT_Pos              (3)
#define UART_CSR_TXEPT                  (0x01U << UART_CSR_TXEPT_Pos)           /*!< Transmit buffer empty flag bit */

/**
  * @brief UART_ISR Register Bit Definition
  */
#define UART_ISR_TX_INTF_Pos            (0)
#define UART_ISR_TX_INTF                (0x01U << UART_ISR_TX_INTF_Pos)         /*!< Transmit buffer empty interrupt flag bit */
#define UART_ISR_RX_INTF_Pos            (1)
#define UART_ISR_RX_INTF                (0x01U << UART_ISR_RX_INTF_Pos)         /*!< Receive valid data interrupt flag bit */
#define UART_ISR_TXC_INTF_Pos           (2)
#define UART_ISR_TXC_INTF               (0x01U << UART_ISR_TXC_INTF_Pos)        /*!< Transmit complete interrupt flag bit */

#define UART_ISR_RXOERR_INTF_Pos        (3)
#define UART_ISR_RXOERR_INTF            (0x01U << UART_ISR_RXOERR_INTF_Pos)     /*!< Receive overflow error interrupt flag bit */
#define UART_ISR_RXPERR_INTF_Pos        (4)
#define UART_ISR_RXPERR_INTF            (0x01U << UART_ISR_RXPERR_INTF_Pos)     /*!< Parity error interrupt flag bit */
#define UART_ISR_RXFERR_INTF_Pos        (5)
#define UART_ISR_RXFERR_INTF            (0x01U << UART_ISR_RXFERR_INTF_Pos)     /*!< Frame error interrupt flag bit */
#define UART_ISR_RXBRK_INTF_Pos         (6)
#define UART_ISR_RXBRK_INTF             (0x01U << UART_ISR_RXBRK_INTF_Pos)      /*!< Receive frame break interrupt flag bit */

#define UART_ISR_TXBRK_INTF_Pos         (7)
#define UART_ISR_TXBRK_INTF             (0x01U << UART_ISR_TXBRK_INTF_Pos)      /*!< Transmit Break Frame Interrupt Flag Bit */
#define UART_ISR_RXB8_INTF_Pos          (8)
#define UART_ISR_RXB8_INTF              (0x01U << UART_ISR_RXB8_INTF_Pos)       /*!< Receive Bit 8 Interrupt Flag Bit */

#define UART_ISR_RXIDLE_INTF_Pos        (9)
#define UART_ISR_RXIDLE_INTF            (0x01U << UART_ISR_RXIDLE_INTF_Pos)     /*!< Receive IDLE Frame Interrupt flag Bit */
#define UART_ISR_ABREND_INTF_Pos        (10)
#define UART_ISR_ABREND_INTF            (0x01U << UART_ISR_ABREND_INTF_Pos)     /*!< Auto baud rate end interrupt flag bit */
#define UART_ISR_ABRERR_INTF_Pos        (11)
#define UART_ISR_ABRERR_INTF            (0x01U << UART_ISR_ABRERR_INTF_Pos)     /*!< Auto baud rate error interrupt flag bit */


/**
  * @brief UART_IER Register Bit Definition
  */
#define UART_IER_TX_IEN_Pos             (0)
#define UART_IER_TX_IEN                 (0x01U << UART_IER_TX_IEN_Pos)          /*!< Transmit buffer empty interrupt enable bit */
#define UART_IER_RX_IEN_Pos             (1)
#define UART_IER_RX_IEN                 (0x01U << UART_IER_RX_IEN_Pos)          /*!< Receive buffer interrupt enable bit */

#define UART_IER_TXC_IEN_Pos            (2)
#define UART_IER_TXC_IEN                (0x01U << UART_IER_TXC_IEN_Pos)         /*!< Transmit complete interrupt enable bit */

#define UART_IER_RXOERR_IEN_Pos         (3)
#define UART_IER_RXOERR_IEN             (0x01U << UART_IER_RXOERR_IEN_Pos)      /*!< Receive overflow error interrupt enable bit */
#define UART_IER_RXPERR_IEN_Pos         (4)
#define UART_IER_RXPERR_IEN             (0x01U << UART_IER_RXPERR_IEN_Pos)      /*!< Parity error interrupt enable bit */
#define UART_IER_RXFERR_IEN_Pos         (5)
#define UART_IER_RXFERR_IEN             (0x01U << UART_IER_RXFERR_IEN_Pos)      /*!< Frame error interrupt enable bit */
#define UART_IER_RXBRK_IEN_Pos          (6)
#define UART_IER_RXBRK_IEN              (0x01U << UART_IER_RXBRK_IEN_Pos)       /*!< Receive frame break interrupt enable bit */

#define UART_IER_TXBRK_IEN_Pos          (7)
#define UART_IER_TXBRK_IEN              (0x01U << UART_IER_TXBRK_IEN_Pos)       /*!< Transmit Break Frame Interrupt Enable Bit */
#define UART_IER_RXB8_IEN_Pos           (8)
#define UART_IER_RXB8_IEN               (0x01U << UART_IER_RXB8_IEN_Pos)        /*!< Receive Bit 8 Interrupt Enable Bit */

#define UART_IER_RXIDLE_IEN_Pos         (9)
#define UART_IER_RXIDLE_IEN             (0x01U << UART_IER_RXIDLE_IEN_Pos)      /*!< Receive IDLE Frame Interrupt enable bit */
#define UART_IER_ABREND_IEN_Pos         (10)
#define UART_IER_ABREND_IEN             (0x01U << UART_IER_ABREND_IEN_Pos)      /*!< Auto baud rate end enable bit */
#define UART_IER_ABRERR_IEN_Pos         (11)
#define UART_IER_ABRERR_IEN             (0x01U << UART_IER_ABRERR_IEN_Pos)      /*!< Auto baud rate error enable bit */


/**
  * @brief UART_ICR Register Bit Definition
  */
#define UART_ICR_TX_ICLR_Pos            (0)
#define UART_ICR_TX_ICLR                (0x01U << UART_ICR_TX_ICLR_Pos)         /*!< Transmit buffer empty interrupt clear bit */
#define UART_ICR_RX_ICLR_Pos            (1)
#define UART_ICR_RX_ICLR                (0x01U << UART_ICR_RX_ICLR_Pos)         /*!< Receive interrupt clear bit */

#define UART_ICR_TXC_ICLR_Pos           (2)
#define UART_ICR_TXC_ICLR               (0x01U << UART_ICR_TXC_ICLR_Pos)        /*!< Transmit complete interrupt clear bit */

#define UART_ICR_RXOERR_ICLR_Pos        (3)
#define UART_ICR_RXOERR_ICLR            (0x01U << UART_ICR_RXOERR_ICLR_Pos)     /*!< Receive overflow error interrupt clear bit */
#define UART_ICR_RXPERR_ICLR_Pos        (4)
#define UART_ICR_RXPERR_ICLR            (0x01U << UART_ICR_RXPERR_ICLR_Pos)     /*!< Parity error interrupt clear bit */

#define UART_ICR_RXFERR_ICLR_Pos        (5)
#define UART_ICR_RXFERR_ICLR            (0x01U << UART_ICR_RXFERR_ICLR_Pos)     /*!< Frame error interrupt clear bit */
#define UART_ICR_RXBRK_ICLR_Pos         (6)
#define UART_ICR_RXBRK_ICLR             (0x01U << UART_ICR_RXBRK_ICLR_Pos)      /*!< Receive frame break interrupt clear bit */

#define UART_ICR_TXBRK_ICLR_Pos         (7)
#define UART_ICR_TXBRK_ICLR             (0x01U << UART_ICR_TXBRK_ICLR_Pos)      /*!< Transmit Break Frame Interrupt clear Bit */
#define UART_ICR_RXB8_ICLR_Pos          (8)
#define UART_ICR_RXB8_ICLR              (0x01U << UART_ICR_RXB8_ICLR_Pos)       /*!< Receive Bit 8 Interrupt clear Bit */

#define UART_ICR_RXIDLE_ICLR_Pos        (9)
#define UART_ICR_RXIDLE_ICLR            (0x01U << UART_ICR_RXIDLE_ICLR_Pos)     /*!< Receive IDLE Frame Interrupt clear Bit */
#define UART_ICR_ABREND_ICLR_Pos        (10)
#define UART_ICR_ABREND_ICLR            (0x01U << UART_ICR_ABREND_ICLR_Pos)     /*!< Auto baud rate end clear bit */
#define UART_ICR_ABRERR_ICLR_Pos        (11)
#define UART_ICR_ABRERR_ICLR            (0x01U << UART_ICR_ABRERR_ICLR_Pos)     /*!< Auto baud rate error clear bit */


/**
  * @brief UART_GCR Register Bit Definition
  */
#define UART_GCR_UARTEN_Pos             (0)
#define UART_GCR_UARTEN                 (0x01U << UART_GCR_UARTEN_Pos)          /*!< UART mode selection bit */
#define UART_GCR_DMAMODE_Pos            (1)
#define UART_GCR_DMAMODE                (0x01U << UART_GCR_DMAMODE_Pos)         /*!< DMA mode selection bit */
#define UART_GCR_AUTOFLOWEN_Pos         (2)
#define UART_GCR_AUTOFLOWEN             (0x01U << UART_GCR_AUTOFLOWEN_Pos)      /*!< Automatic flow control enable bit */
#define UART_GCR_RXEN_Pos               (3)
#define UART_GCR_RXEN                   (0x01U << UART_GCR_RXEN_Pos)            /*!< Enable receive */
#define UART_GCR_TXEN_Pos               (4)
#define UART_GCR_TXEN                   (0x01U << UART_GCR_TXEN_Pos)            /*!< Enable transmit */

#define UART_GCR_SELB8_Pos              (7)
#define UART_GCR_SELB8                  (0x01U << UART_GCR_SELB8_Pos)           /*!< UART mode selection bit */
#define UART_GCR_SWAP_Pos               (8)
#define UART_GCR_SWAP                   (0x01U << UART_GCR_SWAP_Pos)            /*!< DMA mode selection bit */
#define UART_GCR_RXTOG_Pos              (9)
#define UART_GCR_RXTOG                  (0x01U << UART_GCR_RXTOG_Pos)           /*!< Automatic flow control enable bit */
#define UART_GCR_TXTOG_Pos              (10)
#define UART_GCR_TXTOG                  (0x01U << UART_GCR_TXTOG_Pos)           /*!< Enable receive */

/**
  * @brief UART_CCR Register Bit Definition
  */
#define UART_CCR_PEN_Pos                (0)
#define UART_CCR_PEN                    (0x01U << UART_CCR_PEN_Pos)             /*!< Parity enable bit */
#define UART_CCR_PSEL_Pos               (1)
#define UART_CCR_PSEL                   (0x01U << UART_CCR_PSEL_Pos)            /*!< Parity selection bit */

#define UART_CCR_SPB0_Pos               (2)
#define UART_CCR_SPB0                   (0x01U << UART_CCR_SPB0_Pos)            /*!< Stop bit 0 selection */
/* legacy define */
#define UART_CCR_SPB_Pos                UART_CCR_SPB0_Pos
#define UART_CCR_SPB                    UART_CCR_SPB0                           /*!< Stop bit selection */

#define UART_CCR_BRK_Pos                (3)
#define UART_CCR_BRK                    (0x01U << UART_CCR_BRK_Pos)             /*!< UART transmit frame break */
#define UART_CCR_CHAR_Pos               (4)
#define UART_CCR_CHAR                   (0x03U << UART_CCR_CHAR_Pos)            /*!< UART width bit */
#define UART_CCR_CHAR_5b                (0x00U << UART_CCR_CHAR_Pos)            /*!< UART Word Length 5b */
#define UART_CCR_CHAR_6b                (0x01U << UART_CCR_CHAR_Pos)            /*!< UART Word Length 6b */
#define UART_CCR_CHAR_7b                (0x02U << UART_CCR_CHAR_Pos)            /*!< UART Word Length 7b */
#define UART_CCR_CHAR_8b                (0x03U << UART_CCR_CHAR_Pos)            /*!< UART Word Length 8b */

#define UART_CCR_SPB1_Pos               (6)
#define UART_CCR_SPB1                   (0x01U << UART_CCR_SPB1_Pos)            /*!< Stop bit 1 selection */
#define UART_CCR_SPB_MSK                ((0x01U << UART_CCR_SPB1_Pos)+(0x01U << UART_CCR_SPB0_Pos))
#define UART_CCR_SPB_MODE_MSK           ((0x01U << UART_CCR_SPB1_Pos)+(0x01U << UART_CCR_SPB0_Pos))    /*!< set the stop bit */
#define UART_CCR_SPB_MODE_0             ((0x00U << UART_CCR_SPB1_Pos)+(0x00U << UART_CCR_SPB0_Pos))    /*!< 1 stop bit */
#define UART_CCR_SPB_MODE_1             ((0x00U << UART_CCR_SPB1_Pos)+(0x01U << UART_CCR_SPB0_Pos))    /*!< 2 stop bit */
#define UART_CCR_SPB_MODE_2             ((0x01U << UART_CCR_SPB1_Pos)+(0x00U << UART_CCR_SPB0_Pos))    /*!< 0.5 stop bit */
#define UART_CCR_SPB_MODE_3             ((0x01U << UART_CCR_SPB1_Pos)+(0x01U << UART_CCR_SPB0_Pos))    /*!< 1.5 stop bit */

#define UART_CCR_B8RXD_Pos              (7)
#define UART_CCR_B8RXD                  (0x01U << UART_CCR_B8RXD_Pos)           /*!< Synchronous frame receive */
#define UART_CCR_B8TXD_Pos              (8)
#define UART_CCR_B8TXD                  (0x01U << UART_CCR_B8TXD_Pos)           /*!< Synchronous frame transmit */
#define UART_CCR_B8POL_Pos              (9)
#define UART_CCR_B8POL                  (0x01U << UART_CCR_B8POL_Pos)           /*!< Synchronous frame polarity control bit */
#define UART_CCR_B8TOG_Pos              (10)
#define UART_CCR_B8TOG                  (0x01U << UART_CCR_B8TOG_Pos)           /*!< Synchronous frame auto toggle bit */
#define UART_CCR_B8EN_Pos               (11)
#define UART_CCR_B8EN                   (0x01U << UART_CCR_B8EN_Pos)            /*!< Synchronous frame enable bit */
#define UART_CCR_RWU_Pos                (12)
#define UART_CCR_RWU                    (0x01U << UART_CCR_RWU_Pos)             /*!< Receive wake up method */
#define UART_CCR_WAKE_Pos               (13)
#define UART_CCR_WAKE                   (0x01U << UART_CCR_WAKE_Pos)            /*!< Wake up method */

#define UART_CCR_LIN_Pos                (14)
#define UART_CCR_LIN                    (0x01U << UART_CCR_LIN_Pos)             /*!< UART LIN enable bit */

/**
  * @brief UART_BRR Register Bit Definition
  */
#define UART_BRR_MANTISSA_Pos           (0)
#define UART_BRR_MANTISSA               (0xFFFFU << UART_BRR_MANTISSA_Pos)      /*!< UART DIV MANTISSA */

/**
  * @brief UART_FRA Register Bit Definition
  */
#define UART_BRR_FRACTION_Pos           (0)
#define UART_BRR_FRACTION               (0x0FU << UART_BRR_FRACTION_Pos)        /*!< UART DIV FRACTION */

/**
  * @brief UART_RXAR Register Bit Definition
  */
#define UART_RXADDR_Pos                 (0)
#define UART_RXADDR                     (0xFFU << UART_RXADDR_Pos)              /*!< Synchronous frame match address */

/**
  * @brief UART_RXMR Register Bit Definition
  */
#define UART_RXMASK_Pos                 (0)
#define UART_RXMASK                     (0xFFU << UART_RXMASK_Pos)              /*!< Synchronous frame match address mask */

/**
  * @brief UART_SCR Register Bit Definition
  */
#define UART_SCR_SCEN_Pos               (0)
#define UART_SCR_SCEN                   (0x01U << UART_SCR_SCEN_Pos)            /*!< ISO7816 enable bit */
#define UART_SCR_SCAEN_Pos              (1)
#define UART_SCR_SCAEN                  (0x01U << UART_SCR_SCAEN_Pos)           /*!< ISO7816 check auto answer bit */
#define UART_SCR_NACK_Pos               (2)
#define UART_SCR_NACK                   (0x01U << UART_SCR_NACK_Pos)            /*!< Master receive frame answer bit */
#define UART_SCR_SCFCNT_Pos             (4)
#define UART_SCR_SCFCNT                 (0xFFU << UART_SCR_SCFCNT_Pos)          /*!< ISO7816 protection counter bit */
#define UART_SCR_HDSEL_Pos              (12)
#define UART_SCR_HDSEL                  (0x01U << UART_SCR_HDSEL_Pos)           /*!< Single-line half-duplex mode selection bit */


/**
  * @brief UART_IDLR Register Bit Definition
  */
#define UART_IDLR_Pos                   (0)
#define UART_IDLR                       (0xFFFFU << UART_IDLR_Pos)              /*!< Idle data length register */

/**
  * @brief UART_ABRCR Register Bit Definition
  */
#define UART_ABRCR_ABREN_Pos            (0)
#define UART_ABRCR_ABREN                (0x01U << UART_ABRCR_ABREN_Pos)         /*!< Auto baud rate enable */

#define UART_ABRCR_ABR_BITCNT_Pos       (1)
#define UART_ABRCR_ABR_BITCNT           (0x03U << UART_ABRCR_ABR_BITCNT_Pos)    /*!< Auto baud rate detection length */
#define UART_ABRCR_ABR_BITCNT_MODE0     (0x00U << UART_ABRCR_ABR_BITCNT_Pos)    /*!< 1 bit */
#define UART_ABRCR_ABR_BITCNT_MODE1     (0x01U << UART_ABRCR_ABR_BITCNT_Pos)    /*!< 2 bit */
#define UART_ABRCR_ABR_BITCNT_MODE2     (0x02U << UART_ABRCR_ABR_BITCNT_Pos)    /*!< 4 bit */
#define UART_ABRCR_ABR_BITCNT_MODE3     (0x03U << UART_ABRCR_ABR_BITCNT_Pos)    /*!< 8 bit */

#define UART_ABRCR_FORMER_EDGE_Pos      (3)
#define UART_ABRCR_FORMER_EDGE          (0x01U << UART_ABRCR_FORMER_EDGE_Pos)   /*!< One edge selection before the auto baud rate */
#define UART_ABRCR_LATTER_EDGE_Pos      (4)
#define UART_ABRCR_LATTER_EDGE          (0x01U << UART_ABRCR_LATTER_EDGE_Pos)   /*!< One edge selection after the auto baud rate */

/**
  * @brief UART_IRDA Register Bit Definition
  */
#define UART_IRDA_SIREN_Pos             (0)
#define UART_IRDA_SIREN                 (0x01U << UART_IRDA_SIREN_Pos)          /*!< IrDA mode enable */
#define UART_IRDA_SIRLP_Pos             (1)
#define UART_IRDA_SIRLP                 (0x01U << UART_IRDA_SIRLP_Pos)          /*!< IrDA low power */

#define UART_IRDA_PSC_REG_Pos           (8)
#define UART_IRDA_PSC_REG               (0xFFU << UART_IRDA_PSC_REG_Pos)        /*!< Prescaler value */

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
