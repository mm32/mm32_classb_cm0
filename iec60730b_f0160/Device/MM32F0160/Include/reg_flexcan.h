/***********************************************************************************************************************
    @file     reg_flexcan.h
    @author   VV TEAM
    @brief    This flie contains all the FLEXCAN's register and its field definition.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/

#ifndef __REG_FLEXCAN_H
#define __REG_FLEXCAN_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0.h>



/**
  * @brief FLEXCAN Base Address Definition
  */
#define  FLEXCAN_BASE                              0x4000C000                                       /*!<Base Address: 0x4000C000*/

/**
  * @brief FLEXCAN Register Structure Definition
  */
typedef struct
{
    __IO uint32_t MCR;                            /*!<FLEXCAN Module Configuration Register          offset: 0x00       */
    __IO uint32_t CTRL1;                          /*!<FLEXCAN Control Register 1                     offset: 0x04       */
    __IO uint32_t TIMER;                          /*!<FLEXCAN Free Running Timer Register            offset: 0x08       */
    __IO uint32_t RESERVED0x0C[1];                /*!<                                               offset: 0x0C       */
    __IO uint32_t RXMGMASK;                       /*!<FLEXCAN Rx Mailboxes Global Mask Register      offset: 0x10       */
    __IO uint32_t RX14MASK;                       /*!<FLEXCAN Rx 14 Mask Registe                     offset: 0x14       */
    __IO uint32_t RX15MASK;                       /*!<FLEXCAN Rx 15 Mask Register                    offset: 0x18       */
    __IO uint32_t ECR;                            /*!<FLEXCAN Error Counter Register                 offset: 0x1C       */
    __IO uint32_t ESR1;                           /*!<FLEXCAN Error and Status Register 1            offset: 0x20       */
    __IO uint32_t RESERVED0x24[1];                /*!<                                               offset: 0x24       */
    __IO uint32_t IMASK1;                         /*!<FLEXCAN Interrupt Mask Register 1              offset: 0x28       */
    __IO uint32_t RESERVED0x2C[1];                /*!<                                               offset: 0x2C       */
    __IO uint32_t IFLAG1;                         /*!<FLEXCAN Interrupt Flag Register 1              offset: 0x30       */
    __IO uint32_t CTRL2;                          /*!<FLEXCAN Control Register 2                     offset: 0x34       */
    __IO uint32_t ESR2;                           /*!<FLEXCAN Error and Status Register 2            offset: 0x38       */
    __IO uint32_t RESERVED0x3C[2];                /*!<                                               offset: 0x3C~0x40  */
    __IO uint32_t CRCR;                           /*!<FLEXCAN CRC Register                           offset: 0x44       */
    __IO uint32_t RXFGMASK;                       /*!<FLEXCAN Rx FIFO Global Mask Register           offset: 0x48       */
    __IO uint32_t RXFIR;                          /*!<FLEXCAN Rx FIFO Information Register           offset: 0x4C       */
    __IO uint32_t CBT;                            /*!<FLEXCAN CAN Bit Timing Register                offset: 0x50       */
    __IO uint32_t RESERVED_4[11];

    struct                                        /*!< offset: 0x80 array step: 0x10 x 128bit */
    {
        __IO uint32_t CS;                         /*!< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x80, array step: 0x10 */
        __IO uint32_t ID;                         /*!< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x84, array step: 0x10 */
        __IO uint32_t WORD0;                      /*!< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x88, array step: 0x10 */
        __IO uint32_t WORD1;                      /*!< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
    }MB[32];

    __IO uint32_t RESERVED_5[384];
    __IO uint32_t RXIMR[32];                      /*!<FLEXCAN Rx Individual Mask Registers           offset: 0x880      */
    __IO uint32_t RESERVED0x900[192];             /*!<                                               offset: 0x900~0xBFC*/
    __IO uint32_t FDCTRL;                         /*!<FLEXCAN CAN FD Control Register                offset: 0xC00      */
    __IO uint32_t FDCBT;                          /*!<FLEXCAN CAN FD Bit Timing Register             offset: 0xC04      */
    __IO uint32_t FDCRC;                          /*!<FLEXCAN CAN FD CRC Register                    offset: 0xC08      */
    __IO uint32_t ERFCR;                          /*!<FLEXCAN Enhanced Rx FIFO Control Register      offset: 0xC0C      */
    __IO uint32_t ERFIER;                         /*!<FLEXCAN Enhanced Rx FIFO Interrupt Enable      offset: 0xC10
                                                      Register                                                          */
    __IO uint32_t ERFSR;                          /*!<FLEXCAN Enhanced Rx FIFO Status Register       offset: 0xC14      */
    __IO uint32_t RESERVED0xC18[1274];                  /*!<                                                      offset: 0xC18~0x1FFC */
    struct
    {
        __IO uint32_t ERFCS;                            /*!< Enhanced Rx FIFO Buffer 0 CS Register                offset: 0x2000 */
        __IO uint32_t ERFDID;                           /*!< Enhanced Rx FIFO Buffer 0 ID Register                offset: 0x2004 */
        __IO uint32_t ERFDWORD[16];                     /*!< Enhanced Rx FIFO Buffer 0 WORD Register              offset: 0x2008 */
        __IO uint32_t IHOFF;                            /*!< Identifier receive filter hit indication             offset: 0x2048 */
        __IO uint32_t RESERVED0x204C[1];                /*!<                                                      offset: 0x204C */
    }ERFMB[6];                                          /*!<                                                      offset: 0x2000~0x21DC */
    __IO uint32_t RESERVED0x21E0[904];                  /*!<                                                      offset: 0x21E0~0x2FFC */
    __IO uint32_t ERFFEL[2];                      /*!<FLEXCAN Enhanced Rx FIFO Filter Element        offset: 0x3000
                                                      Registers                                                         */
} FLEXCAN_TypeDef;

/**
  * @brief FLEXCAN type pointer Definition
  */
#define FLEXCAN                                   ((FLEXCAN_TypeDef *)FLEXCAN_BASE)


/**
  * @brief FLEXCAN_MCR Register Bit Definition
  */
#define  FLEXCAN_MCR_MAXMB_Pos                    (0)
#define  FLEXCAN_MCR_MAXMB_Msk                    (0x7FU << FLEXCAN_MCR_MAXMB_Pos)                  /*!<The number of the last MB that will take part in the matching and arbitration processes*/
#define  FLEXCAN_MCR_MAXMB                        FLEXCAN_MCR_MAXMB_Msk
#define  FLEXCAN_MCR_MAXMB_0                      (0x01U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_MAXMB_1                      (0x02U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_MAXMB_2                      (0x04U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_MAXMB_3                      (0x08U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_MAXMB_4                      (0x10U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_MAXMB_5                      (0x20U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_MAXMB_6                      (0x40U << FLEXCAN_MCR_MAXMB_Pos)
#define  FLEXCAN_MCR_IDAM_Pos                     (8)
#define  FLEXCAN_MCR_IDAM_Msk                     (0x3U << FLEXCAN_MCR_IDAM_Pos)                    /*!<The format of the Rx FIFO ID Filter Table elements*/
#define  FLEXCAN_MCR_IDAM                         FLEXCAN_MCR_IDAM_Msk
#define  FLEXCAN_MCR_IDAM_0                       (0x1U << FLEXCAN_MCR_IDAM_Pos)
#define  FLEXCAN_MCR_IDAM_1                       (0x2U << FLEXCAN_MCR_IDAM_Pos)
#define  FLEXCAN_MCR_FDEN_Pos                     (11)
#define  FLEXCAN_MCR_FDEN_Msk                     (0x1U << FLEXCAN_MCR_FDEN_Pos)                    /*!<*/
#define  FLEXCAN_MCR_FDEN                         FLEXCAN_MCR_FDEN_Msk
#define  FLEXCAN_MCR_AEN_Pos                      (12)
#define  FLEXCAN_MCR_AEN_Msk                      (0x1U << FLEXCAN_MCR_AEN_Pos)                     /*!<1: Enable abort*/
#define  FLEXCAN_MCR_AEN                          FLEXCAN_MCR_AEN_Msk
#define  FLEXCAN_MCR_LPRIOEN_Pos                  (13)
#define  FLEXCAN_MCR_LPRIOEN_Msk                  (0x1U << FLEXCAN_MCR_LPRIOEN_Pos)                 /*!<1: Enable Local Priority*/
#define  FLEXCAN_MCR_LPRIOEN                      FLEXCAN_MCR_LPRIOEN_Msk
#define  FLEXCAN_MCR_DMA_Pos                      (15)
#define  FLEXCAN_MCR_DMA_Msk                      (0x1U << FLEXCAN_MCR_DMA_Pos)                     /*!<1: Enable DMA feature for Rx FIFO*/
#define  FLEXCAN_MCR_DMA                          FLEXCAN_MCR_DMA_Msk
#define  FLEXCAN_MCR_IRMQ_Pos                     (16)
#define  FLEXCAN_MCR_IRMQ_Msk                     (0x1U << FLEXCAN_MCR_IRMQ_Pos)                    /*!<1: Enable individual Rx masking and queue feature*/
#define  FLEXCAN_MCR_IRMQ                         FLEXCAN_MCR_IRMQ_Msk
#define  FLEXCAN_MCR_SRXDIS_Pos                   (17)
#define  FLEXCAN_MCR_SRXDIS_Msk                   (0x1U << FLEXCAN_MCR_SRXDIS_Pos)                  /*!<1: Disable self reception*/
#define  FLEXCAN_MCR_SRXDIS                       FLEXCAN_MCR_SRXDIS_Msk
#define  FLEXCAN_MCR_LPMACK_Pos                   (20)
#define  FLEXCAN_MCR_LPMACK_Msk                   (0x1U << FLEXCAN_MCR_LPMACK_Pos)                  /*!<Low-Power Mode Acknowledge*/
#define  FLEXCAN_MCR_LPMACK                       FLEXCAN_MCR_LPMACK_Msk
#define  FLEXCAN_MCR_WRNEN_Pos                    (21)
#define  FLEXCAN_MCR_WRNEN_Msk                    (0x1U << FLEXCAN_MCR_WRNEN_Pos)                   /*!<Warning Interrupt Enable*/
#define  FLEXCAN_MCR_WRNEN                        FLEXCAN_MCR_WRNEN_Msk
#define  FLEXCAN_MCR_SUPV_Pos                     (23)
#define  FLEXCAN_MCR_SUPV_Msk                     (0x1U << FLEXCAN_MCR_SUPV_Pos)                    /*!<1: FlexCAN is in Supervisor mode. Affected registers allow only Supervisor access.*/
#define  FLEXCAN_MCR_SUPV                         FLEXCAN_MCR_SUPV_Msk
#define  FLEXCAN_MCR_FRZACK_Pos                   (24)
#define  FLEXCAN_MCR_FRZACK_Msk                   (0x1U << FLEXCAN_MCR_FRZACK_Pos)                  /*!<Freeze Mode Acknowledge*/
#define  FLEXCAN_MCR_FRZACK                       FLEXCAN_MCR_FRZACK_Msk
#define  FLEXCAN_MCR_SOFTRST_Pos                  (25)
#define  FLEXCAN_MCR_SOFTRST_Msk                  (0x1U << FLEXCAN_MCR_SOFTRST_Pos)                 /*!<Soft reset*/
#define  FLEXCAN_MCR_SOFTRST                      FLEXCAN_MCR_SOFTRST_Msk
#define  FLEXCAN_MCR_WAKMSK_Pos                   (26)
#define  FLEXCAN_MCR_WAKMSK_Msk                   (0x1U << FLEXCAN_MCR_WAKMSK_Pos)                  /*!<1: FlexCAN is either in Disable or Freeze mode*/
#define  FLEXCAN_MCR_WAKMSK                       FLEXCAN_MCR_WAKMSK_Msk
#define  FLEXCAN_MCR_NOTRDY_Pos                   (27)
#define  FLEXCAN_MCR_NOTRDY_Msk                   (0x1U << FLEXCAN_MCR_NOTRDY_Pos)                  /*!<1: FlexCAN is either in Disable or Freeze mode*/
#define  FLEXCAN_MCR_NOTRDY                       FLEXCAN_MCR_NOTRDY_Msk
#define  FLEXCAN_MCR_HALT_Pos                     (28)
#define  FLEXCAN_MCR_HALT_Msk                     (0x1U << FLEXCAN_MCR_HALT_Pos)                    /*!<1: Enter Freeze mode if the FRZ bit is asserted*/
#define  FLEXCAN_MCR_HALT                         FLEXCAN_MCR_HALT_Msk
#define  FLEXCAN_MCR_RFEN_Pos                     (29)
#define  FLEXCAN_MCR_RFEN_Msk                     (0x1U << FLEXCAN_MCR_RFEN_Pos)                    /*!<1: Enable Rx FIFO*/
#define  FLEXCAN_MCR_RFEN                         FLEXCAN_MCR_RFEN_Msk
#define  FLEXCAN_MCR_FRZ_Pos                      (30)
#define  FLEXCAN_MCR_FRZ_Msk                      (0x1U << FLEXCAN_MCR_FRZ_Pos)                     /*!<1: Enabled to enter Freeze mode*/
#define  FLEXCAN_MCR_FRZ                          FLEXCAN_MCR_FRZ_Msk
#define  FLEXCAN_MCR_MDIS_Pos                     (31)
#define  FLEXCAN_MCR_MDIS_Msk                     (0x1U << FLEXCAN_MCR_MDIS_Pos)                    /*!<1: Disable the FlexCAN module as well as the clocks to the PE and CHI submodules*/
#define  FLEXCAN_MCR_MDIS                         FLEXCAN_MCR_MDIS_Msk

/**
  * @brief FLEXCAN_CTRL1 Register Bit Definition
  */
#define  FLEXCAN_CTRL1_PROPSEG_Pos                (0)
#define  FLEXCAN_CTRL1_PROPSEG_Msk                (0x7U << FLEXCAN_CTRL1_PROPSEG_Pos)               /*!<Propagation Segment � Defines the length of the Propagation Segment in the bit time*/
#define  FLEXCAN_CTRL1_PROPSEG                    FLEXCAN_CTRL1_PROPSEG_Msk
#define  FLEXCAN_CTRL1_PROPSEG_0                  (0x1U << FLEXCAN_CTRL1_PROPSEG_Pos)
#define  FLEXCAN_CTRL1_PROPSEG_1                  (0x2U << FLEXCAN_CTRL1_PROPSEG_Pos)
#define  FLEXCAN_CTRL1_PROPSEG_2                  (0x4U << FLEXCAN_CTRL1_PROPSEG_Pos)
#define  FLEXCAN_CTRL1_LOM_Pos                    (3)
#define  FLEXCAN_CTRL1_LOM_Msk                    (0x1U << FLEXCAN_CTRL1_LOM_Pos)                   /*!<Configures the FlexCAN to operate in Listen-Only mode*/
#define  FLEXCAN_CTRL1_LOM                        FLEXCAN_CTRL1_LOM_Msk
#define  FLEXCAN_CTRL1_LBUF_Pos                   (4)
#define  FLEXCAN_CTRL1_LBUF_Msk                   (0x1U << FLEXCAN_CTRL1_LBUF_Pos)                  /*!<The ordering mechanism for message buffer transmission*/
#define  FLEXCAN_CTRL1_LBUF                       FLEXCAN_CTRL1_LBUF_Msk
#define  FLEXCAN_CTRL1_TSYN_Pos                   (5)
#define  FLEXCAN_CTRL1_TSYN_Msk                   (0x1U << FLEXCAN_CTRL1_TSYN_Pos)                  /*!<Timer Sync � a mechanism that resets the free-running timer each time a message is received in MB0*/
#define  FLEXCAN_CTRL1_TSYN                       FLEXCAN_CTRL1_TSYN_Msk
#define  FLEXCAN_CTRL1_BOFFREC_Pos                (6)
#define  FLEXCAN_CTRL1_BOFFREC_Msk                (0x1U << FLEXCAN_CTRL1_BOFFREC_Pos)               /*!<Defines how the FlexCAN recovers from Bus Off state*/
#define  FLEXCAN_CTRL1_BOFFREC                    FLEXCAN_CTRL1_BOFFREC_Msk
#define  FLEXCAN_CTRL1_SMP_Pos                    (7)
#define  FLEXCAN_CTRL1_SMP_Msk                    (0x1U << FLEXCAN_CTRL1_SMP_Pos)                   /*!<The sampling mode of CAN bits at the Rx input*/
#define  FLEXCAN_CTRL1_SMP                        FLEXCAN_CTRL1_SMP_Msk
#define  FLEXCAN_CTRL1_RWRNMSK_Pos                (10)
#define  FLEXCAN_CTRL1_RWRNMSK_Msk                (0x1U << FLEXCAN_CTRL1_RWRNMSK_Pos)               /*!<Rx Warning Interrupt (CAN_ESR1.RWRNINT) Mask*/
#define  FLEXCAN_CTRL1_RWRNMSK                    FLEXCAN_CTRL1_RWRNMSK_Msk
#define  FLEXCAN_CTRL1_TWRNMSK_Pos                (11)
#define  FLEXCAN_CTRL1_TWRNMSK_Msk                (0x1U << FLEXCAN_CTRL1_TWRNMSK_Pos)               /*!<Tx Warning Interrupt (CAN_ESR1.TWRNINT) Mask*/
#define  FLEXCAN_CTRL1_TWRNMSK                    FLEXCAN_CTRL1_TWRNMSK_Msk
#define  FLEXCAN_CTRL1_LPB_Pos                    (12)
#define  FLEXCAN_CTRL1_LPB_Msk                    (0x1U << FLEXCAN_CTRL1_LPB_Pos)                   /*!<1: Loop-Back enabled*/
#define  FLEXCAN_CTRL1_LPB                        FLEXCAN_CTRL1_LPB_Msk
#define  FLEXCAN_CTRL1_CLKSRC_Pos                 (13)
#define  FLEXCAN_CTRL1_CLKSRC_Msk                 (0x1U << FLEXCAN_CTRL1_CLKSRC_Pos)                /*!<Selects the clock source*/
#define  FLEXCAN_CTRL1_CLKSRC                     FLEXCAN_CTRL1_CLKSRC_Msk
#define  FLEXCAN_CTRL1_ERRMSK_Pos                 (14)
#define  FLEXCAN_CTRL1_ERRMSK_Msk                 (0x1U << FLEXCAN_CTRL1_ERRMSK_Pos)                /*!<Error Interrupt (CAN_ESR1.ERRINT) Mask*/
#define  FLEXCAN_CTRL1_ERRMSK                     FLEXCAN_CTRL1_ERRMSK_Msk
#define  FLEXCAN_CTRL1_BOFFMSK_Pos                (15)
#define  FLEXCAN_CTRL1_BOFFMSK_Msk                (0x1U << FLEXCAN_CTRL1_BOFFMSK_Pos)               /*!<Bus Off Interrupt (CAN_ESR1.BOFFINT) Mask*/
#define  FLEXCAN_CTRL1_BOFFMSK                    FLEXCAN_CTRL1_BOFFMSK_Msk
#define  FLEXCAN_CTRL1_PSEG2_Pos                  (16)
#define  FLEXCAN_CTRL1_PSEG2_Msk                  (0x7U << FLEXCAN_CTRL1_PSEG2_Pos)                 /*!<Phase Segment 2 � Defines the length of Phase Segment 2 in the bit time*/
#define  FLEXCAN_CTRL1_PSEG2                      FLEXCAN_CTRL1_PSEG2_Msk
#define  FLEXCAN_CTRL1_PSEG2_0                    (0x1U << FLEXCAN_CTRL1_PSEG2_Pos)
#define  FLEXCAN_CTRL1_PSEG2_1                    (0x2U << FLEXCAN_CTRL1_PSEG2_Pos)
#define  FLEXCAN_CTRL1_PSEG2_2                    (0x4U << FLEXCAN_CTRL1_PSEG2_Pos)
#define  FLEXCAN_CTRL1_PSEG1_Pos                  (19)
#define  FLEXCAN_CTRL1_PSEG1_Msk                  (0x7U << FLEXCAN_CTRL1_PSEG1_Pos)                 /*!<Phase Segment 1 � Defines the length of Phase Segment 1 in the bit time*/
#define  FLEXCAN_CTRL1_PSEG1                      FLEXCAN_CTRL1_PSEG1_Msk
#define  FLEXCAN_CTRL1_PSEG1_0                    (0x1U << FLEXCAN_CTRL1_PSEG1_Pos)
#define  FLEXCAN_CTRL1_PSEG1_1                    (0x2U << FLEXCAN_CTRL1_PSEG1_Pos)
#define  FLEXCAN_CTRL1_PSEG1_2                    (0x4U << FLEXCAN_CTRL1_PSEG1_Pos)
#define  FLEXCAN_CTRL1_RJW_Pos                    (22)
#define  FLEXCAN_CTRL1_RJW_Msk                    (0x3U << FLEXCAN_CTRL1_RJW_Pos)                   /*!<Resync Jump Width � Defines the maximum number of Tq that a bit time can be changed by one re-synchronization*/
#define  FLEXCAN_CTRL1_RJW                        FLEXCAN_CTRL1_RJW_Msk
#define  FLEXCAN_CTRL1_RJW_0                      (0x1U << FLEXCAN_CTRL1_RJW_Pos)
#define  FLEXCAN_CTRL1_RJW_1                      (0x2U << FLEXCAN_CTRL1_RJW_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_Pos                (24)
#define  FLEXCAN_CTRL1_PRESDIV_Msk                (0xFFU << FLEXCAN_CTRL1_PRESDIV_Pos)              /*!<Prescaler Division Factor � Defines the ratio between the PE clock frequency and the Serial Clock (Sclock) frequency*/
#define  FLEXCAN_CTRL1_PRESDIV                    FLEXCAN_CTRL1_PRESDIV_Msk
#define  FLEXCAN_CTRL1_PRESDIV_0                  (0x01U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_1                  (0x02U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_2                  (0x04U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_3                  (0x08U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_4                  (0x10U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_5                  (0x20U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_6                  (0x40U << FLEXCAN_CTRL1_PRESDIV_Pos)
#define  FLEXCAN_CTRL1_PRESDIV_7                  (0x80U << FLEXCAN_CTRL1_PRESDIV_Pos)

/**
  * @brief FLEXCAN_TIMER Register Bit Definition
  */
#define  FLEXCAN_TIMER_TIMER_Pos                  (0)
#define  FLEXCAN_TIMER_TIMER_Msk                  (0xFFFFU << FLEXCAN_TIMER_TIMER_Pos)              /*!<Timer Value: Contains the free-running counter value.*/
#define  FLEXCAN_TIMER_TIMER                      FLEXCAN_TIMER_TIMER_Msk
#define  FLEXCAN_TIMER_TIMER_0                    (0x0001U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_1                    (0x0002U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_2                    (0x0004U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_3                    (0x0008U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_4                    (0x0010U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_5                    (0x0020U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_6                    (0x0040U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_7                    (0x0080U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_8                    (0x0100U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_9                    (0x0200U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_10                   (0x0400U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_11                   (0x0800U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_12                   (0x1000U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_13                   (0x2000U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_14                   (0x4000U << FLEXCAN_TIMER_TIMER_Pos)
#define  FLEXCAN_TIMER_TIMER_15                   (0x8000U << FLEXCAN_TIMER_TIMER_Pos)

/**
  * @brief FLEXCAN_RXMGMASK Register Bit Definition
  */
#define  FLEXCAN_RXMGMASK_MG_Pos                  (0)
#define  FLEXCAN_RXMGMASK_MG_Msk                  (0xFFFFFFFFU << FLEXCAN_RXMGMASK_MG_Pos)          /*!<Rx Mailboxes Global Mask Bits*/
#define  FLEXCAN_RXMGMASK_MG                      FLEXCAN_RXMGMASK_MG_Msk
#define  FLEXCAN_RXMGMASK_MG_0                    (0x00000001U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_1                    (0x00000002U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_2                    (0x00000004U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_3                    (0x00000008U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_4                    (0x00000010U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_5                    (0x00000020U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_6                    (0x00000040U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_7                    (0x00000080U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_8                    (0x00000100U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_9                    (0x00000200U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_10                   (0x00000400U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_11                   (0x00000800U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_12                   (0x00001000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_13                   (0x00002000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_14                   (0x00004000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_15                   (0x00008000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_16                   (0x00010000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_17                   (0x00020000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_18                   (0x00040000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_19                   (0x00080000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_20                   (0x00100000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_21                   (0x00200000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_22                   (0x00400000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_23                   (0x00800000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_24                   (0x01000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_25                   (0x02000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_26                   (0x04000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_27                   (0x08000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_28                   (0x10000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_29                   (0x20000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_30                   (0x40000000U << FLEXCAN_RXMGMASK_MG_Pos)
#define  FLEXCAN_RXMGMASK_MG_31                   (0x80000000U << FLEXCAN_RXMGMASK_MG_Pos)

/**
  * @brief FLEXCAN_RX14MASK Register Bit Definition
  */
#define  FLEXCAN_RX14MASK_RX14M_Pos               (0)
#define  FLEXCAN_RX14MASK_RX14M_Msk               (0xFFFFFFFFU << FLEXCAN_RX14MASK_RX14M_Pos)       /*!<Rx MB14 Mask Bits*/
#define  FLEXCAN_RX14MASK_RX14M                   FLEXCAN_RX14MASK_RX14M_Msk
#define  FLEXCAN_RX14MASK_RX14M_0                 (0x00000001U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_1                 (0x00000002U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_2                 (0x00000004U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_3                 (0x00000008U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_4                 (0x00000010U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_5                 (0x00000020U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_6                 (0x00000040U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_7                 (0x00000080U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_8                 (0x00000100U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_9                 (0x00000200U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_10                (0x00000400U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_11                (0x00000800U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_12                (0x00001000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_13                (0x00002000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_14                (0x00004000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_15                (0x00008000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_16                (0x00010000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_17                (0x00020000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_18                (0x00040000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_19                (0x00080000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_20                (0x00100000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_21                (0x00200000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_22                (0x00400000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_23                (0x00800000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_24                (0x01000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_25                (0x02000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_26                (0x04000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_27                (0x08000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_28                (0x10000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_29                (0x20000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_30                (0x40000000U << FLEXCAN_RX14MASK_RX14M_Pos)
#define  FLEXCAN_RX14MASK_RX14M_31                (0x80000000U << FLEXCAN_RX14MASK_RX14M_Pos)

/**
  * @brief FLEXCAN_RX15MASK Register Bit Definition
  */
#define  FLEXCAN_RX15MASK_RX15M_Pos               (0)
#define  FLEXCAN_RX15MASK_RX15M_Msk               (0xFFFFFFFFU << FLEXCAN_RX15MASK_RX15M_Pos)       /*!<Rx MB15 Mask Bits*/
#define  FLEXCAN_RX15MASK_RX15M                   FLEXCAN_RX15MASK_RX15M_Msk
#define  FLEXCAN_RX15MASK_RX15M_0                 (0x00000001U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_1                 (0x00000002U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_2                 (0x00000004U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_3                 (0x00000008U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_4                 (0x00000010U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_5                 (0x00000020U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_6                 (0x00000040U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_7                 (0x00000080U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_8                 (0x00000100U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_9                 (0x00000200U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_10                (0x00000400U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_11                (0x00000800U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_12                (0x00001000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_13                (0x00002000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_14                (0x00004000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_15                (0x00008000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_16                (0x00010000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_17                (0x00020000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_18                (0x00040000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_19                (0x00080000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_20                (0x00100000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_21                (0x00200000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_22                (0x00400000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_23                (0x00800000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_24                (0x01000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_25                (0x02000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_26                (0x04000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_27                (0x08000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_28                (0x10000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_29                (0x20000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_30                (0x40000000U << FLEXCAN_RX15MASK_RX15M_Pos)
#define  FLEXCAN_RX15MASK_RX15M_31                (0x80000000U << FLEXCAN_RX15MASK_RX15M_Pos)

/**
  * @brief FLEXCAN_ECR Register Bit Definition
  */
#define  FLEXCAN_ECR_TXERRCNT_Pos                 (0)
#define  FLEXCAN_ECR_TXERRCNT_Msk                 (0xFFU << FLEXCAN_ECR_TXERRCNT_Pos)               /*!<Transmit Error Counter � Calculate all errors detected in transmitted messages*/
#define  FLEXCAN_ECR_TXERRCNT                     FLEXCAN_ECR_TXERRCNT_Msk
#define  FLEXCAN_ECR_TXERRCNT_0                   (0x01U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_1                   (0x02U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_2                   (0x04U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_3                   (0x08U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_4                   (0x10U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_5                   (0x20U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_6                   (0x40U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNT_7                   (0x80U << FLEXCAN_ECR_TXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_Pos                 (8)
#define  FLEXCAN_ECR_RXERRCNT_Msk                 (0xFFU << FLEXCAN_ECR_RXERRCNT_Pos)               /*!<Receive Error Counter � Calculate all errors detected in received messages*/
#define  FLEXCAN_ECR_RXERRCNT                     FLEXCAN_ECR_RXERRCNT_Msk
#define  FLEXCAN_ECR_RXERRCNT_0                   (0x01U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_1                   (0x02U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_2                   (0x04U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_3                   (0x08U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_4                   (0x10U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_5                   (0x20U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_6                   (0x40U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_RXERRCNT_7                   (0x80U << FLEXCAN_ECR_RXERRCNT_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_Pos             (16)
#define  FLEXCAN_ECR_TXERRCNTFAST_Msk             (0xFFU << FLEXCAN_ECR_TXERRCNTFAST_Pos)           /*!<Fast Bit Transfer Error Counter - counts all errors detected in the received CAN FD message data segment with the BRS bit set*/
#define  FLEXCAN_ECR_TXERRCNTFAST                 FLEXCAN_ECR_TXERRCNTFAST_Msk
#define  FLEXCAN_ECR_TXERRCNTFAST_0               (0x01U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_1               (0x02U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_2               (0x04U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_3               (0x08U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_4               (0x10U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_5               (0x20U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_6               (0x40U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_TXERRCNTFAST_7               (0x80U << FLEXCAN_ECR_TXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_Pos             (24)
#define  FLEXCAN_ECR_RXERRCNTFAST_Msk             (0xFFU << FLEXCAN_ECR_RXERRCNTFAST_Pos)           /*!<Fast Bit Receive Error Counter - counts all errors detected in the received CAN FD message data segment with the BRS bit set*/
#define  FLEXCAN_ECR_RXERRCNTFAST                 FLEXCAN_ECR_RXERRCNTFAST_Msk
#define  FLEXCAN_ECR_RXERRCNTFAST_0               (0x01U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_1               (0x02U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_2               (0x04U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_3               (0x08U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_4               (0x10U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_5               (0x20U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_6               (0x40U << FLEXCAN_ECR_RXERRCNTFAST_Pos)
#define  FLEXCAN_ECR_RXERRCNTFAST_7               (0x80U << FLEXCAN_ECR_RXERRCNTFAST_Pos)

/**
  * @brief FLEXCAN_ESR1 Register Bit Definition
  */
#define  FLEXCAN_ESR1_ERRINT_Pos                  (1)
#define  FLEXCAN_ESR1_ERRINT_Msk                  (0x1U << FLEXCAN_ESR1_ERRINT_Pos)                 /*!<Error Interrupt*/
#define  FLEXCAN_ESR1_ERRINT                      FLEXCAN_ESR1_ERRINT_Msk
#define  FLEXCAN_ESR1_BOFFINT_Pos                 (2)
#define  FLEXCAN_ESR1_BOFFINT_Msk                 (0x1U << FLEXCAN_ESR1_BOFFINT_Pos)                /*!<Bus Off Interrupt*/
#define  FLEXCAN_ESR1_BOFFINT                     FLEXCAN_ESR1_BOFFINT_Msk
#define  FLEXCAN_ESR1_RX_Pos                      (3)
#define  FLEXCAN_ESR1_RX_Msk                      (0x1U << FLEXCAN_ESR1_RX_Pos)                     /*!<1: FlexCAN is receiving a message*/
#define  FLEXCAN_ESR1_RX                          FLEXCAN_ESR1_RX_Msk
#define  FLEXCAN_ESR1_FLTCONF_Pos                 (4)
#define  FLEXCAN_ESR1_FLTCONF_Msk                 (0x3U << FLEXCAN_ESR1_FLTCONF_Pos)                /*!<*/
#define  FLEXCAN_ESR1_FLTCONF                     FLEXCAN_ESR1_FLTCONF_Msk
#define  FLEXCAN_ESR1_FLTCONF_0                   (0x1U << FLEXCAN_ESR1_FLTCONF_Pos)
#define  FLEXCAN_ESR1_FLTCONF_1                   (0x2U << FLEXCAN_ESR1_FLTCONF_Pos)
#define  FLEXCAN_ESR1_TX_Pos                      (6)
#define  FLEXCAN_ESR1_TX_Msk                      (0x1U << FLEXCAN_ESR1_TX_Pos)                     /*!<1: FlexCAN is transmitting a message*/
#define  FLEXCAN_ESR1_TX                          FLEXCAN_ESR1_TX_Msk
#define  FLEXCAN_ESR1_IDLE_Pos                    (7)
#define  FLEXCAN_ESR1_IDLE_Msk                    (0x1U << FLEXCAN_ESR1_IDLE_Pos)                   /*!<1: CAN bus is in IDLE state.*/
#define  FLEXCAN_ESR1_IDLE                        FLEXCAN_ESR1_IDLE_Msk
#define  FLEXCAN_ESR1_RXWRN_Pos                   (8)
#define  FLEXCAN_ESR1_RXWRN_Msk                   (0x1U << FLEXCAN_ESR1_RXWRN_Pos)                  /*!<Rx Error Warning � Indicates when repetitive errors are occurring during message reception*/
#define  FLEXCAN_ESR1_RXWRN                       FLEXCAN_ESR1_RXWRN_Msk
#define  FLEXCAN_ESR1_TXWRN_Pos                   (9)
#define  FLEXCAN_ESR1_TXWRN_Msk                   (0x1U << FLEXCAN_ESR1_TXWRN_Pos)                  /*!<TX Error Warning � Indicates when repetitive errors are occurring during message transmission*/
#define  FLEXCAN_ESR1_TXWRN                       FLEXCAN_ESR1_TXWRN_Msk
#define  FLEXCAN_ESR1_STFERR_Pos                  (10)
#define  FLEXCAN_ESR1_STFERR_Msk                  (0x1U << FLEXCAN_ESR1_STFERR_Pos)                 /*!<*/
#define  FLEXCAN_ESR1_STFERR                      FLEXCAN_ESR1_STFERR_Msk
#define  FLEXCAN_ESR1_FRMERR_Pos                  (11)
#define  FLEXCAN_ESR1_FRMERR_Msk                  (0x1U << FLEXCAN_ESR1_FRMERR_Pos)                 /*!<Form Error � Indicates that a Form Error was detected by the receiver node (that is, a fixed-form bit field contains at least one illegal bit)*/
#define  FLEXCAN_ESR1_FRMERR                      FLEXCAN_ESR1_FRMERR_Msk
#define  FLEXCAN_ESR1_CRCERR_Pos                  (12)
#define  FLEXCAN_ESR1_CRCERR_Msk                  (0x1U << FLEXCAN_ESR1_CRCERR_Pos)                 /*!<Cyclic Redundancy Check Error � Indicates that a CRC Error was detected by the receiver node (that is, the calculated CRC is different from the received CRC)*/
#define  FLEXCAN_ESR1_CRCERR                      FLEXCAN_ESR1_CRCERR_Msk
#define  FLEXCAN_ESR1_ACKERR_Pos                  (13)
#define  FLEXCAN_ESR1_ACKERR_Msk                  (0x1U << FLEXCAN_ESR1_ACKERR_Pos)                 /*!<Acknowledge Error � Indicates that an Acknowledge Error was detected by the transmitter node (that is, a dominant bit wasn�t detected during the ACK SLOT)*/
#define  FLEXCAN_ESR1_ACKERR                      FLEXCAN_ESR1_ACKERR_Msk
#define  FLEXCAN_ESR1_BIT0ERR_Pos                 (14)
#define  FLEXCAN_ESR1_BIT0ERR_Msk                 (0x1U << FLEXCAN_ESR1_BIT0ERR_Pos)                /*!<Bit0 Error � Indicates when an inconsistency occurs between the transmitted and the received bit in a message*/
#define  FLEXCAN_ESR1_BIT0ERR                     FLEXCAN_ESR1_BIT0ERR_Msk
#define  FLEXCAN_ESR1_BIT1ERR_Pos                 (15)
#define  FLEXCAN_ESR1_BIT1ERR_Msk                 (0x1U << FLEXCAN_ESR1_BIT1ERR_Pos)                /*!<Bit1 Error � Indicates when an inconsistency occurs between the transmitted and the received bit in a message*/
#define  FLEXCAN_ESR1_BIT1ERR                     FLEXCAN_ESR1_BIT1ERR_Msk
#define  FLEXCAN_ESR1_RWRNINT_Pos                 (16)
#define  FLEXCAN_ESR1_RWRNINT_Msk                 (0x1U << FLEXCAN_ESR1_RWRNINT_Pos)                /*!<Rx Warning Interrupt Flag*/
#define  FLEXCAN_ESR1_RWRNINT                     FLEXCAN_ESR1_RWRNINT_Msk
#define  FLEXCAN_ESR1_TWRNINT_Pos                 (17)
#define  FLEXCAN_ESR1_TWRNINT_Msk                 (0x1U << FLEXCAN_ESR1_TWRNINT_Pos)                /*!<Tx Warning Interrupt Flag*/
#define  FLEXCAN_ESR1_TWRNINT                     FLEXCAN_ESR1_TWRNINT_Msk
#define  FLEXCAN_ESR1_SYNCH_Pos                   (18)
#define  FLEXCAN_ESR1_SYNCH_Msk                   (0x1U << FLEXCAN_ESR1_SYNCH_Pos)                  /*!<CAN Synchronization Status*/
#define  FLEXCAN_ESR1_SYNCH                       FLEXCAN_ESR1_SYNCH_Msk
#define  FLEXCAN_ESR1_BOFFDONEINT_Pos             (19)
#define  FLEXCAN_ESR1_BOFFDONEINT_Msk             (0x1U << FLEXCAN_ESR1_BOFFDONEINT_Pos)            /*!<Bus Off Done Interrupt*/
#define  FLEXCAN_ESR1_BOFFDONEINT                 FLEXCAN_ESR1_BOFFDONEINT_Msk
#define  FLEXCAN_ESR1_ERRINTFAST_Pos              (20)
#define  FLEXCAN_ESR1_ERRINTFAST_Msk              (0x1U << FLEXCAN_ESR1_ERRINTFAST_Pos)             /*!<Error Interrupt for Errors Detected in the data phase of CAN FD frames with the BRS bit set*/
#define  FLEXCAN_ESR1_ERRINTFAST                  FLEXCAN_ESR1_ERRINTFAST_Msk
#define  FLEXCAN_ESR1_ERROVR_Pos                  (21)
#define  FLEXCAN_ESR1_ERROVR_Msk                  (0x1U << FLEXCAN_ESR1_ERROVR_Pos)                 /*!<Error Overrun � Indicates that an error condition occurred when any error flag is already set*/
#define  FLEXCAN_ESR1_ERROVR                      FLEXCAN_ESR1_ERROVR_Msk
#define  FLEXCAN_ESR1_STFERRFAST_Pos              (26)
#define  FLEXCAN_ESR1_STFERRFAST_Msk              (0x1U << FLEXCAN_ESR1_STFERRFAST_Pos)             /*!<Stuffing Error in the data phase of CAN FD Frames with the BRS bit set - indicates that a stuffing error has been detected in the data phase of CAN FD frames with the BRS bit set*/
#define  FLEXCAN_ESR1_STFERRFAST                  FLEXCAN_ESR1_STFERRFAST_Msk
#define  FLEXCAN_ESR1_FRMERRFAST_Pos              (27)
#define  FLEXCAN_ESR1_FRMERRFAST_Msk              (0x1U << FLEXCAN_ESR1_FRMERRFAST_Pos)             /*!<Form Error in the data phase of CAN FD Frames with the BRS bit set - indicates that a form error has been detected by the receiver node in the data phase of CAN FD frames with the BRS bit set (i.e., a fixed-form bit field contains at least one illegal bit)*/
#define  FLEXCAN_ESR1_FRMERRFAST                  FLEXCAN_ESR1_FRMERRFAST_Msk
#define  FLEXCAN_ESR1_CRCERRFAST_Pos              (28)
#define  FLEXCAN_ESR1_CRCERRFAST_Msk              (0x1U << FLEXCAN_ESR1_CRCERRFAST_Pos)             /*!<CRC check error in the CRC field of CAN FD frames with the BRS bit set - indicates that a CRC error has been detected by the receiver node in the CRC field of CAN FD frames with the BRS bit set (i.e., the calculated CRC is different from the received CRC)*/
#define  FLEXCAN_ESR1_CRCERRFAST                  FLEXCAN_ESR1_CRCERRFAST_Msk
#define  FLEXCAN_ESR1_BIT0ERRFAST_Pos             (30)
#define  FLEXCAN_ESR1_BIT0ERRFAST_Msk             (0x1U << FLEXCAN_ESR1_BIT0ERRFAST_Pos)            /*!<Bit0 Error in the data phase of CAN FD frames with the BRS bit set - indicates when an inconsistency occurs between the transmitted and the received bit in the data phase of CAN FD frames with the BRS bit set*/
#define  FLEXCAN_ESR1_BIT0ERRFAST                 FLEXCAN_ESR1_BIT0ERRFAST_Msk
#define  FLEXCAN_ESR1_BIT1ERRFAST_Pos             (31)
#define  FLEXCAN_ESR1_BIT1ERRFAST_Msk             (0x1U << FLEXCAN_ESR1_BIT1ERRFAST_Pos)            /*!<Bit1 Error in the data phase of CAN FD frames with the BRS bit set - indicates when an inconsistency occurs between the transmitted and the received bit in the data phase of CAN FD frames with the BRS bit set*/
#define  FLEXCAN_ESR1_BIT1ERRFAST                 FLEXCAN_ESR1_BIT1ERRFAST_Msk

/**
  * @brief FLEXCAN_IMASK1 Register Bit Definition
  */
#define  FLEXCAN_IMASK1_BUF31TO0M_Pos             (0)
#define  FLEXCAN_IMASK1_BUF31TO0M_Msk             (0xFFFFFFFFU << FLEXCAN_IMASK1_BUF31TO0M_Pos)     /*!<MBi Mask Bits � Each bit enables or disables the corresponding interrupt for MB15 to MB0*/
#define  FLEXCAN_IMASK1_BUF31TO0M                 FLEXCAN_IMASK1_BUF31TO0M_Msk
#define  FLEXCAN_IMASK1_BUF31TO0M_0               (0x00000001U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_1               (0x00000002U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_2               (0x00000004U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_3               (0x00000008U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_4               (0x00000010U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_5               (0x00000020U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_6               (0x00000040U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_7               (0x00000080U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_8               (0x00000100U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_9               (0x00000200U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_10              (0x00000400U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_11              (0x00000800U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_12              (0x00001000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_13              (0x00002000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_14              (0x00004000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_15              (0x00008000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_16              (0x00010000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_17              (0x00020000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_18              (0x00040000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_19              (0x00080000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_20              (0x00100000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_21              (0x00200000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_22              (0x00400000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_23              (0x00800000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_24              (0x01000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_25              (0x02000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_26              (0x04000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_27              (0x08000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_28              (0x10000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_29              (0x20000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_30              (0x40000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)
#define  FLEXCAN_IMASK1_BUF31TO0M_31              (0x80000000U << FLEXCAN_IMASK1_BUF31TO0M_Pos)

/**
  * @brief FLEXCAN_IFLAG1 Register Bit Definition
  */
#define  FLEXCAN_IFLAG1_BUF0I_Pos                 (0)
#define  FLEXCAN_IFLAG1_BUF0I_Msk                 (0x1U << FLEXCAN_IFLAG1_BUF0I_Pos)                /*!<MB0 Interrupt or Clear FIFO bit*/
#define  FLEXCAN_IFLAG1_BUF0I                     FLEXCAN_IFLAG1_BUF0I_Msk
#define  FLEXCAN_IFLAG1_BUF4TO1I_Pos              (1)
#define  FLEXCAN_IFLAG1_BUF4TO1I_Msk              (0xFU << FLEXCAN_IFLAG1_BUF4TO1I_Pos)             /*!<MB4~1 Interrupt or Reserved*/
#define  FLEXCAN_IFLAG1_BUF4TO1I                  FLEXCAN_IFLAG1_BUF4TO1I_Msk
#define  FLEXCAN_IFLAG1_BUF4TO1I_0                (0x1U << FLEXCAN_IFLAG1_BUF4TO1I_Pos)
#define  FLEXCAN_IFLAG1_BUF4TO1I_1                (0x2U << FLEXCAN_IFLAG1_BUF4TO1I_Pos)
#define  FLEXCAN_IFLAG1_BUF4TO1I_2                (0x4U << FLEXCAN_IFLAG1_BUF4TO1I_Pos)
#define  FLEXCAN_IFLAG1_BUF4TO1I_3                (0x8U << FLEXCAN_IFLAG1_BUF4TO1I_Pos)
#define  FLEXCAN_IFLAG1_BUF5I_Pos                 (5)
#define  FLEXCAN_IFLAG1_BUF5I_Msk                 (0x1U << FLEXCAN_IFLAG1_BUF5I_Pos)                /*!<MB5 Interrupt or Frames Available in Rx FIFO*/
#define  FLEXCAN_IFLAG1_BUF5I                     FLEXCAN_IFLAG1_BUF5I_Msk
#define  FLEXCAN_IFLAG1_BUF6I_Pos                 (6)
#define  FLEXCAN_IFLAG1_BUF6I_Msk                 (0x1U << FLEXCAN_IFLAG1_BUF6I_Pos)                /*!<MB6 Interrupt or Rx FIFO Warning*/
#define  FLEXCAN_IFLAG1_BUF6I                     FLEXCAN_IFLAG1_BUF6I_Msk
#define  FLEXCAN_IFLAG1_BUF7I_Pos                 (7)
#define  FLEXCAN_IFLAG1_BUF7I_Msk                 (0x1U << FLEXCAN_IFLAG1_BUF7I_Pos)                /*!<MB7 Interrupt or Rx FIFO Overflow*/
#define  FLEXCAN_IFLAG1_BUF7I                     FLEXCAN_IFLAG1_BUF7I_Msk
#define  FLEXCAN_IFLAG1_BUF31TO8I_Pos             (8)
#define  FLEXCAN_IFLAG1_BUF31TO8I_Msk             (0xFFFFFFU << FLEXCAN_IFLAG1_BUF31TO8I_Pos)       /*!<MBi Interrupt Flag Bits � Each bit flags the corresponding Message Buffer Interrupt for MB15 to MB8*/
#define  FLEXCAN_IFLAG1_BUF31TO8I                 FLEXCAN_IFLAG1_BUF31TO8I_Msk
#define  FLEXCAN_IFLAG1_BUF31TO8I_0               (0x000001U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_1               (0x000002U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_2               (0x000004U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_3               (0x000008U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_4               (0x000010U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_5               (0x000020U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_6               (0x000040U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_7               (0x000080U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_8               (0x000100U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_9               (0x000200U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_10              (0x000400U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_11              (0x000800U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_12              (0x001000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_13              (0x002000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_14              (0x004000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_15              (0x008000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_16              (0x010000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_17              (0x020000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_18              (0x040000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_19              (0x080000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_20              (0x100000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_21              (0x200000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_22              (0x400000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)
#define  FLEXCAN_IFLAG1_BUF31TO8I_23              (0x800000U << FLEXCAN_IFLAG1_BUF31TO8I_Pos)

/**
  * @brief FLEXCAN_CTRL2 Register Bit Definition
  */
#define  FLEXCAN_CTRL2_EDFLTDIS_Pos               (11)
#define  FLEXCAN_CTRL2_EDFLTDIS_Msk               (0x1U << FLEXCAN_CTRL2_EDFLTDIS_Pos)              /*!<During the bus integration state*/
#define  FLEXCAN_CTRL2_EDFLTDIS                   FLEXCAN_CTRL2_EDFLTDIS_Msk
#define  FLEXCAN_CTRL2_ISOCANFDEN_Pos             (12)
#define  FLEXCAN_CTRL2_ISOCANFDEN_Msk             (0x1U << FLEXCAN_CTRL2_ISOCANFDEN_Pos)            /*!<1: ISO CAN FD enable (ISO 11898 protocol standard)*/
#define  FLEXCAN_CTRL2_ISOCANFDEN                 FLEXCAN_CTRL2_ISOCANFDEN_Msk
#define  FLEXCAN_CTRL2_PREXCEN_Pos                (14)
#define  FLEXCAN_CTRL2_PREXCEN_Msk                (0x1U << FLEXCAN_CTRL2_PREXCEN_Pos)               /*!<*/
#define  FLEXCAN_CTRL2_PREXCEN                    FLEXCAN_CTRL2_PREXCEN_Msk
#define  FLEXCAN_CTRL2_EACEN_Pos                  (16)
#define  FLEXCAN_CTRL2_EACEN_Msk                  (0x1U << FLEXCAN_CTRL2_EACEN_Pos)                 /*!<Entire Frame Arbitration Field Comparison Enable For Rx Mailboxes*/
#define  FLEXCAN_CTRL2_EACEN                      FLEXCAN_CTRL2_EACEN_Msk
#define  FLEXCAN_CTRL2_RRS_Pos                    (17)
#define  FLEXCAN_CTRL2_RRS_Msk                    (0x1U << FLEXCAN_CTRL2_RRS_Pos)                   /*!<Remote Request Storing*/
#define  FLEXCAN_CTRL2_RRS                        FLEXCAN_CTRL2_RRS_Msk
#define  FLEXCAN_CTRL2_MRP_Pos                    (18)
#define  FLEXCAN_CTRL2_MRP_Msk                    (0x1U << FLEXCAN_CTRL2_MRP_Pos)                   /*!<Mailboxes Reception Priority*/
#define  FLEXCAN_CTRL2_MRP                        FLEXCAN_CTRL2_MRP_Msk
#define  FLEXCAN_CTRL2_TASD_Pos                   (19)
#define  FLEXCAN_CTRL2_TASD_Msk                   (0x1FU << FLEXCAN_CTRL2_TASD_Pos)                 /*!<Tx Arbitration Start Delay � Indicates how many CAN bits the Tx arbitration process start point can be delayed from the first bit of CRC field on CAN bus. See �23.3.10.6 Tx Arbitration start delay�.*/
#define  FLEXCAN_CTRL2_TASD                       FLEXCAN_CTRL2_TASD_Msk
#define  FLEXCAN_CTRL2_TASD_0                     (0x01U << FLEXCAN_CTRL2_TASD_Pos)
#define  FLEXCAN_CTRL2_TASD_1                     (0x02U << FLEXCAN_CTRL2_TASD_Pos)
#define  FLEXCAN_CTRL2_TASD_2                     (0x04U << FLEXCAN_CTRL2_TASD_Pos)
#define  FLEXCAN_CTRL2_TASD_3                     (0x08U << FLEXCAN_CTRL2_TASD_Pos)
#define  FLEXCAN_CTRL2_TASD_4                     (0x10U << FLEXCAN_CTRL2_TASD_Pos)
#define  FLEXCAN_CTRL2_RFFN_Pos                   (24)
#define  FLEXCAN_CTRL2_RFFN_Msk                   (0xFU << FLEXCAN_CTRL2_RFFN_Pos)                  /*!<The number of Rx FIFO filters, as shown in Table 23-12 RFFN must not be programmed with values that make the number of MBs occupied by Rx FIFO and ID Filter exceed the number of mailboxes defined by CAN_MCR.MAXMB.*/
#define  FLEXCAN_CTRL2_RFFN                       FLEXCAN_CTRL2_RFFN_Msk
#define  FLEXCAN_CTRL2_RFFN_0                     (0x1U << FLEXCAN_CTRL2_RFFN_Pos)
#define  FLEXCAN_CTRL2_RFFN_1                     (0x2U << FLEXCAN_CTRL2_RFFN_Pos)
#define  FLEXCAN_CTRL2_RFFN_2                     (0x4U << FLEXCAN_CTRL2_RFFN_Pos)
#define  FLEXCAN_CTRL2_RFFN_3                     (0x8U << FLEXCAN_CTRL2_RFFN_Pos)
#define  FLEXCAN_CTRL2_BOFFDONEMSK_Pos            (30)
#define  FLEXCAN_CTRL2_BOFFDONEMSK_Msk            (0x1U << FLEXCAN_CTRL2_BOFFDONEMSK_Pos)           /*!<Bus Off Done Interrupt (CAN_ESR1.BOFFDONEINT) Mask*/
#define  FLEXCAN_CTRL2_BOFFDONEMSK                FLEXCAN_CTRL2_BOFFDONEMSK_Msk
#define  FLEXCAN_CTRL2_ERRMSKFAST_Pos             (31)
#define  FLEXCAN_CTRL2_ERRMSKFAST_Msk             (0x1U << FLEXCAN_CTRL2_ERRMSKFAST_Pos)            /*!<Reserved, must be kept at reset value*/
#define  FLEXCAN_CTRL2_ERRMSKFAST                 FLEXCAN_CTRL2_ERRMSKFAST_Msk

/**
  * @brief FLEXCAN_ESR2 Register Bit Definition
  */
#define  FLEXCAN_ESR2_IMB_Pos                     (13)
#define  FLEXCAN_ESR2_IMB_Msk                     (0x1U << FLEXCAN_ESR2_IMB_Pos)                    /*!<Inactive Mailbox*/
#define  FLEXCAN_ESR2_IMB                         FLEXCAN_ESR2_IMB_Msk
#define  FLEXCAN_ESR2_VPS_Pos                     (14)
#define  FLEXCAN_ESR2_VPS_Msk                     (0x1U << FLEXCAN_ESR2_VPS_Pos)                    /*!<Indicates whether CAN_ESR2.IMB and CAN_ESR2.LPTM contents are currently valid or not*/
#define  FLEXCAN_ESR2_VPS                         FLEXCAN_ESR2_VPS_Msk
#define  FLEXCAN_ESR2_LPTM_Pos                    (16)
#define  FLEXCAN_ESR2_LPTM_Msk                    (0x7FU << FLEXCAN_ESR2_LPTM_Pos)                  /*!<Lowest Priority Tx Mailbox*/
#define  FLEXCAN_ESR2_LPTM                        FLEXCAN_ESR2_LPTM_Msk
#define  FLEXCAN_ESR2_LPTM_0                      (0x01U << FLEXCAN_ESR2_LPTM_Pos)
#define  FLEXCAN_ESR2_LPTM_1                      (0x02U << FLEXCAN_ESR2_LPTM_Pos)
#define  FLEXCAN_ESR2_LPTM_2                      (0x04U << FLEXCAN_ESR2_LPTM_Pos)
#define  FLEXCAN_ESR2_LPTM_3                      (0x08U << FLEXCAN_ESR2_LPTM_Pos)
#define  FLEXCAN_ESR2_LPTM_4                      (0x10U << FLEXCAN_ESR2_LPTM_Pos)
#define  FLEXCAN_ESR2_LPTM_5                      (0x20U << FLEXCAN_ESR2_LPTM_Pos)
#define  FLEXCAN_ESR2_LPTM_6                      (0x40U << FLEXCAN_ESR2_LPTM_Pos)

/**
  * @brief FLEXCAN_CRCR Register Bit Definition
  */
#define  FLEXCAN_CRCR_TXCRC_Pos                   (0)
#define  FLEXCAN_CRCR_TXCRC_Msk                   (0x7FFFU << FLEXCAN_CRCR_TXCRC_Pos)               /*!<Transmitted CRC Value � Indicates the CRC value of the last transmitted message*/
#define  FLEXCAN_CRCR_TXCRC                       FLEXCAN_CRCR_TXCRC_Msk
#define  FLEXCAN_CRCR_TXCRC_0                     (0x0001U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_1                     (0x0002U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_2                     (0x0004U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_3                     (0x0008U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_4                     (0x0010U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_5                     (0x0020U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_6                     (0x0040U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_7                     (0x0080U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_8                     (0x0100U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_9                     (0x0200U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_10                    (0x0400U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_11                    (0x0800U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_12                    (0x1000U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_13                    (0x2000U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_TXCRC_14                    (0x4000U << FLEXCAN_CRCR_TXCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_Pos                   (16)
#define  FLEXCAN_CRCR_MBCRC_Msk                   (0x7FU << FLEXCAN_CRCR_MBCRC_Pos)                 /*!<CRC Mailbox � Indicates the number of the mailbox corresponding to the value in the CAN_CRCR.TXCRC field*/
#define  FLEXCAN_CRCR_MBCRC                       FLEXCAN_CRCR_MBCRC_Msk
#define  FLEXCAN_CRCR_MBCRC_0                     (0x01U << FLEXCAN_CRCR_MBCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_1                     (0x02U << FLEXCAN_CRCR_MBCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_2                     (0x04U << FLEXCAN_CRCR_MBCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_3                     (0x08U << FLEXCAN_CRCR_MBCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_4                     (0x10U << FLEXCAN_CRCR_MBCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_5                     (0x20U << FLEXCAN_CRCR_MBCRC_Pos)
#define  FLEXCAN_CRCR_MBCRC_6                     (0x40U << FLEXCAN_CRCR_MBCRC_Pos)

/**
  * @brief FLEXCAN_RXFGMASK Register Bit Definition
  */
#define  FLEXCAN_RXFGMASK_FGM_Pos                 (0)
#define  FLEXCAN_RXFGMASK_FGM_Msk                 (0xFFFFFFFFU << FLEXCAN_RXFGMASK_FGM_Pos)         /*!<Rx FIFO Global Mask Bits � Mask the ID Filter Table elements bits*/
#define  FLEXCAN_RXFGMASK_FGM                     FLEXCAN_RXFGMASK_FGM_Msk
#define  FLEXCAN_RXFGMASK_FGM_0                   (0x00000001U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_1                   (0x00000002U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_2                   (0x00000004U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_3                   (0x00000008U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_4                   (0x00000010U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_5                   (0x00000020U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_6                   (0x00000040U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_7                   (0x00000080U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_8                   (0x00000100U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_9                   (0x00000200U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_10                  (0x00000400U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_11                  (0x00000800U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_12                  (0x00001000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_13                  (0x00002000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_14                  (0x00004000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_15                  (0x00008000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_16                  (0x00010000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_17                  (0x00020000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_18                  (0x00040000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_19                  (0x00080000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_20                  (0x00100000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_21                  (0x00200000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_22                  (0x00400000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_23                  (0x00800000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_24                  (0x01000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_25                  (0x02000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_26                  (0x04000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_27                  (0x08000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_28                  (0x10000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_29                  (0x20000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_30                  (0x40000000U << FLEXCAN_RXFGMASK_FGM_Pos)
#define  FLEXCAN_RXFGMASK_FGM_31                  (0x80000000U << FLEXCAN_RXFGMASK_FGM_Pos)

/**
  * @brief FLEXCAN_RXFIR Register Bit Definition
  */
#define  FLEXCAN_RXFIR_IDHIT_Pos                  (0)
#define  FLEXCAN_RXFIR_IDHIT_Msk                  (0x1FFU << FLEXCAN_RXFIR_IDHIT_Pos)               /*!<ID Acceptance Filter Hit Indicator � Indicates which ID Acceptance Filter (IDAF) was hit by the received message in the Rx FIFO*/
#define  FLEXCAN_RXFIR_IDHIT                      FLEXCAN_RXFIR_IDHIT_Msk
#define  FLEXCAN_RXFIR_IDHIT_0                    (0x001U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_1                    (0x002U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_2                    (0x004U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_3                    (0x008U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_4                    (0x010U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_5                    (0x020U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_6                    (0x040U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_7                    (0x080U << FLEXCAN_RXFIR_IDHIT_Pos)
#define  FLEXCAN_RXFIR_IDHIT_8                    (0x100U << FLEXCAN_RXFIR_IDHIT_Pos)

/**
  * @brief FLEXCAN_CBT Register Bit Definition
  */
#define  FLEXCAN_CBT_EPSEG2_Pos                   (0)
#define  FLEXCAN_CBT_EPSEG2_Msk                   (0x1FU << FLEXCAN_CBT_EPSEG2_Pos)                 /*!<Extended Phase Segment 2*/
#define  FLEXCAN_CBT_EPSEG2                       FLEXCAN_CBT_EPSEG2_Msk
#define  FLEXCAN_CBT_EPSEG2_0                     (0x01U << FLEXCAN_CBT_EPSEG2_Pos)
#define  FLEXCAN_CBT_EPSEG2_1                     (0x02U << FLEXCAN_CBT_EPSEG2_Pos)
#define  FLEXCAN_CBT_EPSEG2_2                     (0x04U << FLEXCAN_CBT_EPSEG2_Pos)
#define  FLEXCAN_CBT_EPSEG2_3                     (0x08U << FLEXCAN_CBT_EPSEG2_Pos)
#define  FLEXCAN_CBT_EPSEG2_4                     (0x10U << FLEXCAN_CBT_EPSEG2_Pos)
#define  FLEXCAN_CBT_EPSEG1_Pos                   (5)
#define  FLEXCAN_CBT_EPSEG1_Msk                   (0x1FU << FLEXCAN_CBT_EPSEG1_Pos)                 /*!<Extended Phase Segment 1*/
#define  FLEXCAN_CBT_EPSEG1                       FLEXCAN_CBT_EPSEG1_Msk
#define  FLEXCAN_CBT_EPSEG1_0                     (0x01U << FLEXCAN_CBT_EPSEG1_Pos)
#define  FLEXCAN_CBT_EPSEG1_1                     (0x02U << FLEXCAN_CBT_EPSEG1_Pos)
#define  FLEXCAN_CBT_EPSEG1_2                     (0x04U << FLEXCAN_CBT_EPSEG1_Pos)
#define  FLEXCAN_CBT_EPSEG1_3                     (0x08U << FLEXCAN_CBT_EPSEG1_Pos)
#define  FLEXCAN_CBT_EPSEG1_4                     (0x10U << FLEXCAN_CBT_EPSEG1_Pos)
#define  FLEXCAN_CBT_EPROPSEG_Pos                 (10)
#define  FLEXCAN_CBT_EPROPSEG_Msk                 (0x3FU << FLEXCAN_CBT_EPROPSEG_Pos)               /*!<Extended Propagation Segment*/
#define  FLEXCAN_CBT_EPROPSEG                     FLEXCAN_CBT_EPROPSEG_Msk
#define  FLEXCAN_CBT_EPROPSEG_0                   (0x01U << FLEXCAN_CBT_EPROPSEG_Pos)
#define  FLEXCAN_CBT_EPROPSEG_1                   (0x02U << FLEXCAN_CBT_EPROPSEG_Pos)
#define  FLEXCAN_CBT_EPROPSEG_2                   (0x04U << FLEXCAN_CBT_EPROPSEG_Pos)
#define  FLEXCAN_CBT_EPROPSEG_3                   (0x08U << FLEXCAN_CBT_EPROPSEG_Pos)
#define  FLEXCAN_CBT_EPROPSEG_4                   (0x10U << FLEXCAN_CBT_EPROPSEG_Pos)
#define  FLEXCAN_CBT_EPROPSEG_5                   (0x20U << FLEXCAN_CBT_EPROPSEG_Pos)
#define  FLEXCAN_CBT_ERJW_Pos                     (16)
#define  FLEXCAN_CBT_ERJW_Msk                     (0x1FU << FLEXCAN_CBT_ERJW_Pos)                   /*!<Extended Resync Jump Width*/
#define  FLEXCAN_CBT_ERJW                         FLEXCAN_CBT_ERJW_Msk
#define  FLEXCAN_CBT_ERJW_0                       (0x01U << FLEXCAN_CBT_ERJW_Pos)
#define  FLEXCAN_CBT_ERJW_1                       (0x02U << FLEXCAN_CBT_ERJW_Pos)
#define  FLEXCAN_CBT_ERJW_2                       (0x04U << FLEXCAN_CBT_ERJW_Pos)
#define  FLEXCAN_CBT_ERJW_3                       (0x08U << FLEXCAN_CBT_ERJW_Pos)
#define  FLEXCAN_CBT_ERJW_4                       (0x10U << FLEXCAN_CBT_ERJW_Pos)
#define  FLEXCAN_CBT_EPRESDIV_Pos                 (21)
#define  FLEXCAN_CBT_EPRESDIV_Msk                 (0x3FFU << FLEXCAN_CBT_EPRESDIV_Pos)              /*!<Extended Prescaler Division Factor*/
#define  FLEXCAN_CBT_EPRESDIV                     FLEXCAN_CBT_EPRESDIV_Msk
#define  FLEXCAN_CBT_EPRESDIV_0                   (0x001U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_1                   (0x002U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_2                   (0x004U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_3                   (0x008U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_4                   (0x010U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_5                   (0x020U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_6                   (0x040U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_7                   (0x080U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_8                   (0x100U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_EPRESDIV_9                   (0x200U << FLEXCAN_CBT_EPRESDIV_Pos)
#define  FLEXCAN_CBT_BTF_Pos                      (31)
#define  FLEXCAN_CBT_BTF_Msk                      (0x1U << FLEXCAN_CBT_BTF_Pos)                     /*!<Bit Timing Format � Enables the use of extended CAN bit timing fields EPRESDIV, EPROPSEG, EPSEG1, EPSEG2 and ERJW, replacing the CAN bit timing variables defined in CAN_CTRL1*/
#define  FLEXCAN_CBT_BTF                          FLEXCAN_CBT_BTF_Msk

/**
  * @brief FLEXCAN_RXIMR Register Bit Definition
  */
#define  FLEXCAN_RXIMR_MI_Pos                     (0)
#define  FLEXCAN_RXIMR_MI_Msk                     (0xFFFFFFFFU << FLEXCAN_RXIMR_MI_Pos)             /*!<Individual Mask Bits*/
#define  FLEXCAN_RXIMR_MI                         FLEXCAN_RXIMR_MI_Msk
#define  FLEXCAN_RXIMR_MI_0                       (0x00000001U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_1                       (0x00000002U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_2                       (0x00000004U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_3                       (0x00000008U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_4                       (0x00000010U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_5                       (0x00000020U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_6                       (0x00000040U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_7                       (0x00000080U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_8                       (0x00000100U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_9                       (0x00000200U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_10                      (0x00000400U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_11                      (0x00000800U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_12                      (0x00001000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_13                      (0x00002000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_14                      (0x00004000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_15                      (0x00008000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_16                      (0x00010000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_17                      (0x00020000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_18                      (0x00040000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_19                      (0x00080000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_20                      (0x00100000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_21                      (0x00200000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_22                      (0x00400000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_23                      (0x00800000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_24                      (0x01000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_25                      (0x02000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_26                      (0x04000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_27                      (0x08000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_28                      (0x10000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_29                      (0x20000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_30                      (0x40000000U << FLEXCAN_RXIMR_MI_Pos)
#define  FLEXCAN_RXIMR_MI_31                      (0x80000000U << FLEXCAN_RXIMR_MI_Pos)

/**
  * @brief FLEXCAN_FDCTRL Register Bit Definition
  */
#define  FLEXCAN_FDCTRL_TDCVAL_Pos                (0)
#define  FLEXCAN_FDCTRL_TDCVAL_Msk                (0x3FU << FLEXCAN_FDCTRL_TDCVAL_Pos)              /*!<Transceiver Delay Compensation Value - the value of the transceiver loop delay measured from the transmitted EDL to R0 transition edge to the respective received one added to the TDCOFF value*/
#define  FLEXCAN_FDCTRL_TDCVAL                    FLEXCAN_FDCTRL_TDCVAL_Msk
#define  FLEXCAN_FDCTRL_TDCVAL_0                  (0x01U << FLEXCAN_FDCTRL_TDCVAL_Pos)
#define  FLEXCAN_FDCTRL_TDCVAL_1                  (0x02U << FLEXCAN_FDCTRL_TDCVAL_Pos)
#define  FLEXCAN_FDCTRL_TDCVAL_2                  (0x04U << FLEXCAN_FDCTRL_TDCVAL_Pos)
#define  FLEXCAN_FDCTRL_TDCVAL_3                  (0x08U << FLEXCAN_FDCTRL_TDCVAL_Pos)
#define  FLEXCAN_FDCTRL_TDCVAL_4                  (0x10U << FLEXCAN_FDCTRL_TDCVAL_Pos)
#define  FLEXCAN_FDCTRL_TDCVAL_5                  (0x20U << FLEXCAN_FDCTRL_TDCVAL_Pos)
#define  FLEXCAN_FDCTRL_TDCOFF_Pos                (8)
#define  FLEXCAN_FDCTRL_TDCOFF_Msk                (0x1FU << FLEXCAN_FDCTRL_TDCOFF_Pos)              /*!<Transceiver Delay Compensation Offset - The offset is added to the measured transceiver loop delay to define the position of the delayed comparison point when bit rate switching is active.*/
#define  FLEXCAN_FDCTRL_TDCOFF                    FLEXCAN_FDCTRL_TDCOFF_Msk
#define  FLEXCAN_FDCTRL_TDCOFF_0                  (0x01U << FLEXCAN_FDCTRL_TDCOFF_Pos)
#define  FLEXCAN_FDCTRL_TDCOFF_1                  (0x02U << FLEXCAN_FDCTRL_TDCOFF_Pos)
#define  FLEXCAN_FDCTRL_TDCOFF_2                  (0x04U << FLEXCAN_FDCTRL_TDCOFF_Pos)
#define  FLEXCAN_FDCTRL_TDCOFF_3                  (0x08U << FLEXCAN_FDCTRL_TDCOFF_Pos)
#define  FLEXCAN_FDCTRL_TDCOFF_4                  (0x10U << FLEXCAN_FDCTRL_TDCOFF_Pos)
#define  FLEXCAN_FDCTRL_TDCFAIL_Pos               (14)
#define  FLEXCAN_FDCTRL_TDCFAIL_Msk               (0x1U << FLEXCAN_FDCTRL_TDCFAIL_Pos)              /*!<Transceiver Delay Compensation Fail - The TDC mechanism is out of range, unable to compensate the transceiver�s loop delay and successfully compare the delayed received bits to the transmitted ones*/
#define  FLEXCAN_FDCTRL_TDCFAIL                   FLEXCAN_FDCTRL_TDCFAIL_Msk
#define  FLEXCAN_FDCTRL_TDCEN_Pos                 (15)
#define  FLEXCAN_FDCTRL_TDCEN_Msk                 (0x1U << FLEXCAN_FDCTRL_TDCEN_Pos)                /*!<1: Transceiver Delay Compensation (TDC) enable*/
#define  FLEXCAN_FDCTRL_TDCEN                     FLEXCAN_FDCTRL_TDCEN_Msk
#define  FLEXCAN_FDCTRL_MBDSR0_Pos                (16)
#define  FLEXCAN_FDCTRL_MBDSR0_Msk                (0x3U << FLEXCAN_FDCTRL_MBDSR0_Pos)               /*!<Configuration data size*/
#define  FLEXCAN_FDCTRL_MBDSR0                    FLEXCAN_FDCTRL_MBDSR0_Msk
#define  FLEXCAN_FDCTRL_MBDSR0_0                  (0x1U << FLEXCAN_FDCTRL_MBDSR0_Pos)
#define  FLEXCAN_FDCTRL_MBDSR0_1                  (0x2U << FLEXCAN_FDCTRL_MBDSR0_Pos)
#define  FLEXCAN_FDCTRL_FDRATE_Pos                (31)
#define  FLEXCAN_FDCTRL_FDRATE_Msk                (0x1U << FLEXCAN_FDCTRL_FDRATE_Pos)               /*!<Bit rate switch enable*/
#define  FLEXCAN_FDCTRL_FDRATE                    FLEXCAN_FDCTRL_FDRATE_Msk

/**
  * @brief FLEXCAN_FDCBT Register Bit Definition
  */
#define  FLEXCAN_FDCBT_FPSEG2_Pos                 (0)
#define  FLEXCAN_FDCBT_FPSEG2_Msk                 (0x7U << FLEXCAN_FDCBT_FPSEG2_Pos)                /*!<Fast Phase Segment 2*/
#define  FLEXCAN_FDCBT_FPSEG2                     FLEXCAN_FDCBT_FPSEG2_Msk
#define  FLEXCAN_FDCBT_FPSEG2_0                   (0x1U << FLEXCAN_FDCBT_FPSEG2_Pos)
#define  FLEXCAN_FDCBT_FPSEG2_1                   (0x2U << FLEXCAN_FDCBT_FPSEG2_Pos)
#define  FLEXCAN_FDCBT_FPSEG2_2                   (0x4U << FLEXCAN_FDCBT_FPSEG2_Pos)
#define  FLEXCAN_FDCBT_FPSEG1_Pos                 (5)
#define  FLEXCAN_FDCBT_FPSEG1_Msk                 (0x7U << FLEXCAN_FDCBT_FPSEG1_Pos)                /*!<Fast Phase Segment 1*/
#define  FLEXCAN_FDCBT_FPSEG1                     FLEXCAN_FDCBT_FPSEG1_Msk
#define  FLEXCAN_FDCBT_FPSEG1_0                   (0x1U << FLEXCAN_FDCBT_FPSEG1_Pos)
#define  FLEXCAN_FDCBT_FPSEG1_1                   (0x2U << FLEXCAN_FDCBT_FPSEG1_Pos)
#define  FLEXCAN_FDCBT_FPSEG1_2                   (0x4U << FLEXCAN_FDCBT_FPSEG1_Pos)
#define  FLEXCAN_FDCBT_FPROPSEG_Pos               (10)
#define  FLEXCAN_FDCBT_FPROPSEG_Msk               (0x1FU << FLEXCAN_FDCBT_FPROPSEG_Pos)             /*!<Fast Propagation Segment*/
#define  FLEXCAN_FDCBT_FPROPSEG                   FLEXCAN_FDCBT_FPROPSEG_Msk
#define  FLEXCAN_FDCBT_FPROPSEG_0                 (0x01U << FLEXCAN_FDCBT_FPROPSEG_Pos)
#define  FLEXCAN_FDCBT_FPROPSEG_1                 (0x02U << FLEXCAN_FDCBT_FPROPSEG_Pos)
#define  FLEXCAN_FDCBT_FPROPSEG_2                 (0x04U << FLEXCAN_FDCBT_FPROPSEG_Pos)
#define  FLEXCAN_FDCBT_FPROPSEG_3                 (0x08U << FLEXCAN_FDCBT_FPROPSEG_Pos)
#define  FLEXCAN_FDCBT_FPROPSEG_4                 (0x10U << FLEXCAN_FDCBT_FPROPSEG_Pos)
#define  FLEXCAN_FDCBT_FRJW_Pos                   (16)
#define  FLEXCAN_FDCBT_FRJW_Msk                   (0x7U << FLEXCAN_FDCBT_FRJW_Pos)                  /*!<Fast Resynchronization Jump Width*/
#define  FLEXCAN_FDCBT_FRJW                       FLEXCAN_FDCBT_FRJW_Msk
#define  FLEXCAN_FDCBT_FRJW_0                     (0x1U << FLEXCAN_FDCBT_FRJW_Pos)
#define  FLEXCAN_FDCBT_FRJW_1                     (0x2U << FLEXCAN_FDCBT_FRJW_Pos)
#define  FLEXCAN_FDCBT_FRJW_2                     (0x4U << FLEXCAN_FDCBT_FRJW_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_Pos               (20)
#define  FLEXCAN_FDCBT_FPRESDIV_Msk               (0x3FFU << FLEXCAN_FDCBT_FPRESDIV_Pos)            /*!<Fast Prescaler Dividing Factor*/
#define  FLEXCAN_FDCBT_FPRESDIV                   FLEXCAN_FDCBT_FPRESDIV_Msk
#define  FLEXCAN_FDCBT_FPRESDIV_0                 (0x001U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_1                 (0x002U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_2                 (0x004U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_3                 (0x008U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_4                 (0x010U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_5                 (0x020U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_6                 (0x040U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_7                 (0x080U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_8                 (0x100U << FLEXCAN_FDCBT_FPRESDIV_Pos)
#define  FLEXCAN_FDCBT_FPRESDIV_9                 (0x200U << FLEXCAN_FDCBT_FPRESDIV_Pos)

/**
  * @brief FLEXCAN_FDCRC Register Bit Definition
  */
#define  FLEXCAN_FDCRC_FDTXCRC_Pos                (0)
#define  FLEXCAN_FDCRC_FDTXCRC_Msk                (0x1FFFFFU << FLEXCAN_FDCRC_FDTXCRC_Pos)          /*!<Extended transmission CRC value - indicates the CRC value calculated over the most recent transmitted message*/
#define  FLEXCAN_FDCRC_FDTXCRC                    FLEXCAN_FDCRC_FDTXCRC_Msk
#define  FLEXCAN_FDCRC_FDTXCRC_0                  (0x000001U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_1                  (0x000002U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_2                  (0x000004U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_3                  (0x000008U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_4                  (0x000010U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_5                  (0x000020U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_6                  (0x000040U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_7                  (0x000080U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_8                  (0x000100U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_9                  (0x000200U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_10                 (0x000400U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_11                 (0x000800U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_12                 (0x001000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_13                 (0x002000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_14                 (0x004000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_15                 (0x008000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_16                 (0x010000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_17                 (0x020000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_18                 (0x040000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_19                 (0x080000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDTXCRC_20                 (0x100000U << FLEXCAN_FDCRC_FDTXCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_Pos                (24)
#define  FLEXCAN_FDCRC_FDMBCRC_Msk                (0x7FU << FLEXCAN_FDCRC_FDMBCRC_Pos)              /*!<CRC Mailbox - indicates the number of the mailbox corresponding to the value in the FDTXCRC field, for both FD and non-FD frames*/
#define  FLEXCAN_FDCRC_FDMBCRC                    FLEXCAN_FDCRC_FDMBCRC_Msk
#define  FLEXCAN_FDCRC_FDMBCRC_0                  (0x01U << FLEXCAN_FDCRC_FDMBCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_1                  (0x02U << FLEXCAN_FDCRC_FDMBCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_2                  (0x04U << FLEXCAN_FDCRC_FDMBCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_3                  (0x08U << FLEXCAN_FDCRC_FDMBCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_4                  (0x10U << FLEXCAN_FDCRC_FDMBCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_5                  (0x20U << FLEXCAN_FDCRC_FDMBCRC_Pos)
#define  FLEXCAN_FDCRC_FDMBCRC_6                  (0x40U << FLEXCAN_FDCRC_FDMBCRC_Pos)

/**
  * @brief FLEXCAN_ERFCR Register Bit Definition
  */
#define  FLEXCAN_ERFCR_ERFWM_Pos                  (0)
#define  FLEXCAN_ERFCR_ERFWM_Msk                  (0x7U << FLEXCAN_ERFCR_ERFWM_Pos)                 /*!<Enhanced Rx FIFO Watermark - defines the minimum number of CAN messages stored in the Enhanced Rx FIFO*/
#define  FLEXCAN_ERFCR_ERFWM                      FLEXCAN_ERFCR_ERFWM_Msk
#define  FLEXCAN_ERFCR_ERFWM_0                    (0x1U << FLEXCAN_ERFCR_ERFWM_Pos)
#define  FLEXCAN_ERFCR_ERFWM_1                    (0x2U << FLEXCAN_ERFCR_ERFWM_Pos)
#define  FLEXCAN_ERFCR_ERFWM_2                    (0x4U << FLEXCAN_ERFCR_ERFWM_Pos)
#define  FLEXCAN_ERFCR_NEXIF_Pos                  (16)
#define  FLEXCAN_ERFCR_NEXIF_Msk                  (0x1U << FLEXCAN_ERFCR_NEXIF_Pos)                 /*!<Number of Extended ID Filter Elements - defines the number of Extended ID Filtering Elements used during the Enhanced Rx FIFO matching process*/
#define  FLEXCAN_ERFCR_NEXIF                      FLEXCAN_ERFCR_NEXIF_Msk
#define  FLEXCAN_ERFCR_DMALW_Pos                  (26)
#define  FLEXCAN_ERFCR_DMALW_Msk                  (0x1FU << FLEXCAN_ERFCR_DMALW_Pos)                /*!<DMA Last Word - defines the last DMA address of each Enhanced Rx FIFO element. See �Table 1-32 DMALW and number of Enhanced Rx FIFO elements transferred�.*/
#define  FLEXCAN_ERFCR_DMALW                      FLEXCAN_ERFCR_DMALW_Msk
#define  FLEXCAN_ERFCR_DMALW_0                    (0x01U << FLEXCAN_ERFCR_DMALW_Pos)
#define  FLEXCAN_ERFCR_DMALW_1                    (0x02U << FLEXCAN_ERFCR_DMALW_Pos)
#define  FLEXCAN_ERFCR_DMALW_2                    (0x04U << FLEXCAN_ERFCR_DMALW_Pos)
#define  FLEXCAN_ERFCR_DMALW_3                    (0x08U << FLEXCAN_ERFCR_DMALW_Pos)
#define  FLEXCAN_ERFCR_DMALW_4                    (0x10U << FLEXCAN_ERFCR_DMALW_Pos)
#define  FLEXCAN_ERFCR_ERFEN_Pos                  (31)
#define  FLEXCAN_ERFCR_ERFEN_Msk                  (0x1U << FLEXCAN_ERFCR_ERFEN_Pos)                 /*!<1: Enhanced Rx FIFO enable*/
#define  FLEXCAN_ERFCR_ERFEN                      FLEXCAN_ERFCR_ERFEN_Msk

/**
  * @brief FLEXCAN_ERFIER Register Bit Definition
  */
#define  FLEXCAN_ERFIER_ERFDAIE_Pos               (28)
#define  FLEXCAN_ERFIER_ERFDAIE_Msk               (0x1U << FLEXCAN_ERFIER_ERFDAIE_Pos)              /*!<1: Enhanced Rx FIFO data available interrupt (ERFSR.ERFDA) enable*/
#define  FLEXCAN_ERFIER_ERFDAIE                   FLEXCAN_ERFIER_ERFDAIE_Msk
#define  FLEXCAN_ERFIER_ERFWMIIE_Pos              (29)
#define  FLEXCAN_ERFIER_ERFWMIIE_Msk              (0x1U << FLEXCAN_ERFIER_ERFWMIIE_Pos)             /*!<1: Enhanced Rx FIFO watermark interrupt (ERFSR.ERFWM) enable*/
#define  FLEXCAN_ERFIER_ERFWMIIE                  FLEXCAN_ERFIER_ERFWMIIE_Msk
#define  FLEXCAN_ERFIER_ERFOVFIE_Pos              (30)
#define  FLEXCAN_ERFIER_ERFOVFIE_Msk              (0x1U << FLEXCAN_ERFIER_ERFOVFIE_Pos)             /*!<1: Enhanced Rx FIFO overflow interrupt (ERFSR.ERFOVF) enable*/
#define  FLEXCAN_ERFIER_ERFOVFIE                  FLEXCAN_ERFIER_ERFOVFIE_Msk
#define  FLEXCAN_ERFIER_ERFUFWIE_Pos              (31)
#define  FLEXCAN_ERFIER_ERFUFWIE_Msk              (0x1U << FLEXCAN_ERFIER_ERFUFWIE_Pos)             /*!<1: Enhanced Rx FIFO underflow interrupt (ERFSR.ERFUFW) enable*/
#define  FLEXCAN_ERFIER_ERFUFWIE                  FLEXCAN_ERFIER_ERFUFWIE_Msk

/**
  * @brief FLEXCAN_ERFSR Register Bit Definition
  */
#define  FLEXCAN_ERFSR_ERFEL_Pos                  (0)
#define  FLEXCAN_ERFSR_ERFEL_Msk                  (0x7U << FLEXCAN_ERFSR_ERFEL_Pos)                 /*!<Indicate the number of CAN messages stored in the Enhanced Rx FIFO*/
#define  FLEXCAN_ERFSR_ERFEL                      FLEXCAN_ERFSR_ERFEL_Msk
#define  FLEXCAN_ERFSR_ERFEL_0                    (0x1U << FLEXCAN_ERFSR_ERFEL_Pos)
#define  FLEXCAN_ERFSR_ERFEL_1                    (0x2U << FLEXCAN_ERFSR_ERFEL_Pos)
#define  FLEXCAN_ERFSR_ERFEL_2                    (0x4U << FLEXCAN_ERFSR_ERFEL_Pos)
#define  FLEXCAN_ERFSR_ERFF_Pos                   (16)
#define  FLEXCAN_ERFSR_ERFF_Msk                   (0x1U << FLEXCAN_ERFSR_ERFF_Pos)                  /*!<1: Enhanced Rx FIFO is full*/
#define  FLEXCAN_ERFSR_ERFF                       FLEXCAN_ERFSR_ERFF_Msk
#define  FLEXCAN_ERFSR_ERFE_Pos                   (17)
#define  FLEXCAN_ERFSR_ERFE_Msk                   (0x1U << FLEXCAN_ERFSR_ERFE_Pos)                  /*!<1: Enhanced Rx FIFO is empty*/
#define  FLEXCAN_ERFSR_ERFE                       FLEXCAN_ERFSR_ERFE_Msk
#define  FLEXCAN_ERFSR_ERFCLR_Pos                 (27)
#define  FLEXCAN_ERFSR_ERFCLR_Msk                 (0x1U << FLEXCAN_ERFSR_ERFCLR_Pos)                /*!<Enhanced Rx FIFO Clear*/
#define  FLEXCAN_ERFSR_ERFCLR                     FLEXCAN_ERFSR_ERFCLR_Msk
#define  FLEXCAN_ERFSR_ERFDA_Pos                  (28)
#define  FLEXCAN_ERFSR_ERFDA_Msk                  (0x1U << FLEXCAN_ERFSR_ERFDA_Pos)                 /*!<1: At least one message is stored in the Enhanced Rx FIFO. When CAN_ERFIER.ERFDAIE = 1, the corresponding interrupt is generated*/
#define  FLEXCAN_ERFSR_ERFDA                      FLEXCAN_ERFSR_ERFDA_Msk
#define  FLEXCAN_ERFSR_ERFWMI_Pos                 (29)
#define  FLEXCAN_ERFSR_ERFWMI_Msk                 (0x1U << FLEXCAN_ERFSR_ERFWMI_Pos)                /*!<1: The number of messages in the Enhanced Rx FIFO is greater than the setting value of CAN_ERFCR.ERFWM; when CAN_ERFIER.ERFWMIIE = 1, the corresponding interrupt is generated*/
#define  FLEXCAN_ERFSR_ERFWMI                     FLEXCAN_ERFSR_ERFWMI_Msk
#define  FLEXCAN_ERFSR_ERFOVF_Pos                 (30)
#define  FLEXCAN_ERFSR_ERFOVF_Msk                 (0x1U << FLEXCAN_ERFSR_ERFOVF_Pos)                /*!<1: Enhanced Rx FIFO overflow. When CAN_ERFIER. ERFOVFIE = 1, corresponding interrupt is generated*/
#define  FLEXCAN_ERFSR_ERFOVF                     FLEXCAN_ERFSR_ERFOVF_Msk
#define  FLEXCAN_ERFSR_ERFUFW_Pos                 (31)
#define  FLEXCAN_ERFSR_ERFUFW_Msk                 (0x1U << FLEXCAN_ERFSR_ERFUFW_Pos)                /*!<1: Enhanced Rx FIFO underflow. When CAN_ERFIER. ERFUFWIE = 1, corresponding interrupt is generated*/
#define  FLEXCAN_ERFSR_ERFUFW                     FLEXCAN_ERFSR_ERFUFW_Msk

/**
  * @brief FLEXCAN_ERFFEL Register Bit Definition
  */
#define  FLEXCAN_ERFFEL_FEL_Pos                   (0)
#define  FLEXCAN_ERFFEL_FEL_Msk                   (0xFFFFFFFFU << FLEXCAN_ERFFEL_FEL_Pos)           /*!<Each filter element is used during the match process and, if the matching criteria are met, a message is stored in the Enhanced Rx FIFO.*/
#define  FLEXCAN_ERFFEL_FEL                       FLEXCAN_ERFFEL_FEL_Msk
#define  FLEXCAN_ERFFEL_FEL_0                     (0x00000001U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_1                     (0x00000002U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_2                     (0x00000004U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_3                     (0x00000008U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_4                     (0x00000010U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_5                     (0x00000020U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_6                     (0x00000040U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_7                     (0x00000080U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_8                     (0x00000100U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_9                     (0x00000200U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_10                    (0x00000400U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_11                    (0x00000800U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_12                    (0x00001000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_13                    (0x00002000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_14                    (0x00004000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_15                    (0x00008000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_16                    (0x00010000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_17                    (0x00020000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_18                    (0x00040000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_19                    (0x00080000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_20                    (0x00100000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_21                    (0x00200000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_22                    (0x00400000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_23                    (0x00800000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_24                    (0x01000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_25                    (0x02000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_26                    (0x04000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_27                    (0x08000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_28                    (0x10000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_29                    (0x20000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_30                    (0x40000000U << FLEXCAN_ERFFEL_FEL_Pos)
#define  FLEXCAN_ERFFEL_FEL_31                    (0x80000000U << FLEXCAN_ERFFEL_FEL_Pos)

/**
  * @brief FLEXCAN_CS Register Bit Definition
  */
#define  FLEXCAN_CS_TIME_STAMP_Pos                (0)
#define  FLEXCAN_CS_TIME_STAMP_Msk                (0xFFFFU << FLEXCAN_CS_TIME_STAMP_Pos)            /*!<*/
#define  FLEXCAN_CS_TIME_STAMP                    FLEXCAN_CS_TIME_STAMP_Msk
#define  FLEXCAN_CS_TIME_STAMP_0                  (0x0001U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_1                  (0x0002U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_2                  (0x0004U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_3                  (0x0008U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_4                  (0x0010U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_5                  (0x0020U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_6                  (0x0040U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_7                  (0x0080U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_8                  (0x0100U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_9                  (0x0200U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_10                 (0x0400U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_11                 (0x0800U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_12                 (0x1000U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_13                 (0x2000U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_14                 (0x4000U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_TIME_STAMP_15                 (0x8000U << FLEXCAN_CS_TIME_STAMP_Pos)
#define  FLEXCAN_CS_DLC_Pos                       (16)
#define  FLEXCAN_CS_DLC_Msk                       (0xFU << FLEXCAN_CS_DLC_Pos)                      /*!<*/
#define  FLEXCAN_CS_DLC                           FLEXCAN_CS_DLC_Msk
#define  FLEXCAN_CS_DLC_0                         (0x1U << FLEXCAN_CS_DLC_Pos)
#define  FLEXCAN_CS_DLC_1                         (0x2U << FLEXCAN_CS_DLC_Pos)
#define  FLEXCAN_CS_DLC_2                         (0x4U << FLEXCAN_CS_DLC_Pos)
#define  FLEXCAN_CS_DLC_3                         (0x8U << FLEXCAN_CS_DLC_Pos)
#define  FLEXCAN_CS_RTR_Pos                       (20)
#define  FLEXCAN_CS_RTR_Msk                       (0x1U << FLEXCAN_CS_RTR_Pos)                      /*!<*/
#define  FLEXCAN_CS_RTR                           FLEXCAN_CS_RTR_Msk
#define  FLEXCAN_CS_IDE_Pos                       (21)
#define  FLEXCAN_CS_IDE_Msk                       (0x1U << FLEXCAN_CS_IDE_Pos)                      /*!<*/
#define  FLEXCAN_CS_IDE                           FLEXCAN_CS_IDE_Msk
#define  FLEXCAN_CS_SRR_Pos                       (22)
#define  FLEXCAN_CS_SRR_Msk                       (0x1U << FLEXCAN_CS_SRR_Pos)                      /*!<*/
#define  FLEXCAN_CS_SRR                           FLEXCAN_CS_SRR_Msk
#define  FLEXCAN_CS_CODE_Pos                      (24)
#define  FLEXCAN_CS_CODE_Msk                      (0xFU << FLEXCAN_CS_CODE_Pos)                     /*!<*/
#define  FLEXCAN_CS_CODE                          FLEXCAN_CS_CODE_Msk
#define  FLEXCAN_CS_CODE_0                        (0x1U << FLEXCAN_CS_CODE_Pos)
#define  FLEXCAN_CS_CODE_1                        (0x2U << FLEXCAN_CS_CODE_Pos)
#define  FLEXCAN_CS_CODE_2                        (0x4U << FLEXCAN_CS_CODE_Pos)
#define  FLEXCAN_CS_CODE_3                        (0x8U << FLEXCAN_CS_CODE_Pos)
#define  FLEXCAN_CS_ESI_Pos                       (29)
#define  FLEXCAN_CS_ESI_Msk                       (0x1U << FLEXCAN_CS_ESI_Pos)                      /*!<*/
#define  FLEXCAN_CS_ESI                           FLEXCAN_CS_ESI_Msk
#define  FLEXCAN_CS_BRS_Pos                       (30)
#define  FLEXCAN_CS_BRS_Msk                       (0x1U << FLEXCAN_CS_BRS_Pos)                      /*!<*/
#define  FLEXCAN_CS_BRS                           FLEXCAN_CS_BRS_Msk
#define  FLEXCAN_CS_EDL_Pos                       (31)
#define  FLEXCAN_CS_EDL_Msk                       (0x1U << FLEXCAN_CS_EDL_Pos)                      /*!<*/
#define  FLEXCAN_CS_EDL                           FLEXCAN_CS_EDL_Msk

/**
  * @brief FLEXCAN_ID Register Bit Definition
  */
#define  FLEXCAN_ID_EXT_Pos                       (0)
#define  FLEXCAN_ID_EXT_Msk                       (0x3FFFFU << FLEXCAN_ID_EXT_Pos)                  /*!<*/
//#define  FLEXCAN_ID_EXT                           FLEXCAN_ID_EXT_Msk
#define  FLEXCAN_ID_EXT_0                         (0x00001U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_1                         (0x00002U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_2                         (0x00004U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_3                         (0x00008U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_4                         (0x00010U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_5                         (0x00020U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_6                         (0x00040U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_7                         (0x00080U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_8                         (0x00100U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_9                         (0x00200U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_10                        (0x00400U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_11                        (0x00800U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_12                        (0x01000U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_13                        (0x02000U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_14                        (0x04000U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_15                        (0x08000U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_16                        (0x10000U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_EXT_17                        (0x20000U << FLEXCAN_ID_EXT_Pos)
#define  FLEXCAN_ID_STD_Pos                       (18)
#define  FLEXCAN_ID_STD_Msk                       (0x7FFU << FLEXCAN_ID_STD_Pos)                    /*!<*/
//#define  FLEXCAN_ID_STD                           FLEXCAN_ID_STD_Msk
#define  FLEXCAN_ID_STD_0                         (0x001U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_1                         (0x002U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_2                         (0x004U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_3                         (0x008U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_4                         (0x010U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_5                         (0x020U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_6                         (0x040U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_7                         (0x080U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_8                         (0x100U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_9                         (0x200U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_STD_10                        (0x400U << FLEXCAN_ID_STD_Pos)
#define  FLEXCAN_ID_PRIO_Pos                      (29)
#define  FLEXCAN_ID_PRIO_Msk                      (0x7U << FLEXCAN_ID_PRIO_Pos)                     /*!<*/
#define  FLEXCAN_ID_PRIO                          FLEXCAN_ID_PRIO_Msk
#define  FLEXCAN_ID_PRIO_0                        (0x1U << FLEXCAN_ID_PRIO_Pos)
#define  FLEXCAN_ID_PRIO_1                        (0x2U << FLEXCAN_ID_PRIO_Pos)
#define  FLEXCAN_ID_PRIO_2                        (0x4U << FLEXCAN_ID_PRIO_Pos)

/**
  * @brief FLEXCAN_WORD0 Register Bit Definition
  */
#define  FLEXCAN_WORD0_DATA_Byte0_Pos             (0)
#define  FLEXCAN_WORD0_DATA_Byte0_Msk             (0xFFU << FLEXCAN_WORD0_DATA_Byte0_Pos)           /*!<*/
#define  FLEXCAN_WORD0_DATA_Byte0                 FLEXCAN_WORD0_DATA_Byte0_Msk
#define  FLEXCAN_WORD0_DATA_Byte0_0               (0x01U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_1               (0x02U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_2               (0x04U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_3               (0x08U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_4               (0x10U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_5               (0x20U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_6               (0x40U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte0_7               (0x80U << FLEXCAN_WORD0_DATA_Byte0_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_Pos             (1)
#define  FLEXCAN_WORD0_DATA_Byte1_Msk             (0xFFU << FLEXCAN_WORD0_DATA_Byte1_Pos)           /*!<*/
#define  FLEXCAN_WORD0_DATA_Byte1                 FLEXCAN_WORD0_DATA_Byte1_Msk
#define  FLEXCAN_WORD0_DATA_Byte1_0               (0x01U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_1               (0x02U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_2               (0x04U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_3               (0x08U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_4               (0x10U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_5               (0x20U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_6               (0x40U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte1_7               (0x80U << FLEXCAN_WORD0_DATA_Byte1_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_Pos             (2)
#define  FLEXCAN_WORD0_DATA_Byte2_Msk             (0xFFU << FLEXCAN_WORD0_DATA_Byte2_Pos)           /*!<*/
#define  FLEXCAN_WORD0_DATA_Byte2                 FLEXCAN_WORD0_DATA_Byte2_Msk
#define  FLEXCAN_WORD0_DATA_Byte2_0               (0x01U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_1               (0x02U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_2               (0x04U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_3               (0x08U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_4               (0x10U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_5               (0x20U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_6               (0x40U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte2_7               (0x80U << FLEXCAN_WORD0_DATA_Byte2_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_Pos             (3)
#define  FLEXCAN_WORD0_DATA_Byte3_Msk             (0xFFU << FLEXCAN_WORD0_DATA_Byte3_Pos)           /*!<*/
#define  FLEXCAN_WORD0_DATA_Byte3                 FLEXCAN_WORD0_DATA_Byte3_Msk
#define  FLEXCAN_WORD0_DATA_Byte3_0               (0x01U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_1               (0x02U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_2               (0x04U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_3               (0x08U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_4               (0x10U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_5               (0x20U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_6               (0x40U << FLEXCAN_WORD0_DATA_Byte3_Pos)
#define  FLEXCAN_WORD0_DATA_Byte3_7               (0x80U << FLEXCAN_WORD0_DATA_Byte3_Pos)

/**
  * @brief FLEXCAN_WORD1 Register Bit Definition
  */
#define  FLEXCAN_WORD1_DATA_Byte4_Pos             (0)
#define  FLEXCAN_WORD1_DATA_Byte4_Msk             (0xFFU << FLEXCAN_WORD1_DATA_Byte4_Pos)           /*!<*/
#define  FLEXCAN_WORD1_DATA_Byte4                 FLEXCAN_WORD1_DATA_Byte4_Msk
#define  FLEXCAN_WORD1_DATA_Byte4_0               (0x01U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_1               (0x02U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_2               (0x04U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_3               (0x08U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_4               (0x10U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_5               (0x20U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_6               (0x40U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte4_7               (0x80U << FLEXCAN_WORD1_DATA_Byte4_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_Pos             (1)
#define  FLEXCAN_WORD1_DATA_Byte5_Msk             (0xFFU << FLEXCAN_WORD1_DATA_Byte5_Pos)           /*!<*/
#define  FLEXCAN_WORD1_DATA_Byte5                 FLEXCAN_WORD1_DATA_Byte5_Msk
#define  FLEXCAN_WORD1_DATA_Byte5_0               (0x01U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_1               (0x02U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_2               (0x04U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_3               (0x08U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_4               (0x10U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_5               (0x20U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_6               (0x40U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte5_7               (0x80U << FLEXCAN_WORD1_DATA_Byte5_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_Pos             (2)
#define  FLEXCAN_WORD1_DATA_Byte6_Msk             (0xFFU << FLEXCAN_WORD1_DATA_Byte6_Pos)           /*!<*/
#define  FLEXCAN_WORD1_DATA_Byte6                 FLEXCAN_WORD1_DATA_Byte6_Msk
#define  FLEXCAN_WORD1_DATA_Byte6_0               (0x01U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_1               (0x02U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_2               (0x04U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_3               (0x08U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_4               (0x10U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_5               (0x20U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_6               (0x40U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte6_7               (0x80U << FLEXCAN_WORD1_DATA_Byte6_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_Pos             (3)
#define  FLEXCAN_WORD1_DATA_Byte7_Msk             (0xFFU << FLEXCAN_WORD1_DATA_Byte7_Pos)           /*!<*/
#define  FLEXCAN_WORD1_DATA_Byte7                 FLEXCAN_WORD1_DATA_Byte7_Msk
#define  FLEXCAN_WORD1_DATA_Byte7_0               (0x01U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_1               (0x02U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_2               (0x04U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_3               (0x08U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_4               (0x10U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_5               (0x20U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_6               (0x40U << FLEXCAN_WORD1_DATA_Byte7_Pos)
#define  FLEXCAN_WORD1_DATA_Byte7_7               (0x80U << FLEXCAN_WORD1_DATA_Byte7_Pos)


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif
