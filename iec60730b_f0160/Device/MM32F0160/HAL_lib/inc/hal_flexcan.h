/***********************************************************************************************************************
    @file     hal_flexcan.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE FLEXCAN FIRMWARE LIBRARY.
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
#ifndef __HAL_FLEXCAN_H
#define __HAL_FLEXCAN_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */
/** @defgroup FLEXCAN
  * @{
  */

/** @defgroup FLEXCAN_Exported_Types
  * @{
  */

/* FLEXCAN module features */
/**
  * @brief Is affected by errata with ID 5829 (FlexCAN: FlexCAN does not transmit a message
  * that is enabled to be transmitted in a specific moment during the arbitration process).
  */
#define FLEXCAN_HAS_ERRATA_5829 (0)

/**
  * @brief Is affected by errata with ID 9595 (FlexCAN: Corrupt frame possible if the Freeze Mode
  * or the Low-Power Mode are entered during a Bus-Off state)
  */
#define FLEXCAN_HAS_ERRATA_9595 (1)

/**
 * @brief Message buffer size
 */
#define FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (32)

/**
  * @brief Has a receive FIFO DMA feature (register bit field MCR[DMA]).
  */
#define FLEXCAN_HAS_RX_FIFO_DMA (0)

/**
  *@brief Is affected by errata with ID 6032 (FlexCAN: A frame with wrong ID or payload is transmitted into the CAN bus
  * when the Message Buffer under transmission is either aborted or deactivated while the CAN bus is in the Bus Idle state).
  */
#define FLEXCAN_HAS_ERRATA_6032 (0)


#define FLEXCAN_WAIT_TIMEOUT (1000U)




/* The count of CAN_WORD0 */
#define CAN_WORD0_COUNT                          (32U)
/* The count of CAN_WORD1 */
#define CAN_WORD1_COUNT                          (32U)



/**
  * @brief FlexCAN Frame ID helper macro.
  */
#define FLEXCAN_ID_STD(id) \
        (((uint32_t)(((uint32_t)(id)) << FLEXCAN_ID_STD_Pos))&FLEXCAN_ID_STD_Msk) /*!< Standard Frame ID helper macro. */
#define FLEXCAN_ID_EXT(id)                                    \
        (((uint32_t)(((uint32_t)(id)) << FLEXCAN_ID_EXT_Pos)) & \
         (FLEXCAN_ID_EXT_Msk | FLEXCAN_ID_STD_Msk))                                /*!< Extend Frame ID helper macro. */



/**
  * @brief FlexCAN Rx Message Buffer Mask helper macro.
  */
#define FLEXCAN_RX_MB_STD_MASK(id, rtr, ide)                                       \
        (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | \
         FLEXCAN_ID_STD(id))           /*!< Standard Rx Message Buffer Mask helper macro. */
#define FLEXCAN_RX_MB_EXT_MASK(id, rtr, ide)                                       \
        (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | \
         FLEXCAN_ID_EXT(id))           /*!< Extend Rx Message Buffer Mask helper macro. */

/**
  * @brief FlexCAN Rx FIFO Mask helper macro.
  */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_A(id, rtr, ide)                              \
        (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | \
         ((id << FLEXCAN_ID_STD_Pos) << 1))        /*!< Standard Rx FIFO Mask helper macro Type A helper macro. */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_HIGH(id, rtr, ide)                         \
        (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | \
         (((uint32_t)(id) & 0x7FF) << 19)) /*!< Standard Rx FIFO Mask helper macro Type B upper part helper macro. */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_LOW(id, rtr, ide)                          \
        (((uint32_t)((uint32_t)(rtr) << 15) | (uint32_t)((uint32_t)(ide) << 14)) | \
         (((uint32_t)(id) & 0x7FF) << 3))  /*!< Standard Rx FIFO Mask helper macro Type B lower part helper macro. */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_HIGH(id) \
        (((uint32_t)(id) & 0x7F8) << 21)   /*!< Standard Rx FIFO Mask helper macro Type C upper part helper macro. */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_HIGH(id) \
        (((uint32_t)(id) & 0x7F8) << 13)   /*!< Standard Rx FIFO Mask helper macro Type C mid-upper part helper macro. */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_LOW(id) \
        (((uint32_t)(id) & 0x7F8) << 5)    /*!< Standard Rx FIFO Mask helper macro Type C mid-lower part helper macro. */
#define FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_LOW(id) \
        (((uint32_t)(id) & 0x7F8) >> 3)    /*!< Standard Rx FIFO Mask helper macro Type C lower part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_A(id, rtr, ide)                              \
        (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | \
         ((id << FLEXCAN_ID_EXT_Pos) << 1))        /*!< Extend Rx FIFO Mask helper macro Type A helper macro. */
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_HIGH(id, rtr, ide)  /*!< Extend Rx FIFO Mask helper macro Type B upper part helper macro. */                           \
        (((uint32_t)((uint32_t)(rtr) << 31) | (uint32_t)((uint32_t)(ide) << 30)) | \
            (((id << FLEXCAN_ID_EXT_Pos) & 0x1FFF8000) << 1))
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_LOW(id, rtr, ide) /*!< Extend Rx FIFO Mask helper macro Type B lower part helper macro. */                          \
        (((uint32_t)((uint32_t)(rtr) << 15) | (uint32_t)((uint32_t)(ide) << 14)) | \
         (((id << FLEXCAN_ID_EXT_Pos) & 0x1FFF8000) >> 15))
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_HIGH(id) \
        (((id << FLEXCAN_ID_EXT_Pos) & 0x1FE00000) << 3)  /*!< Extend Rx FIFO Mask helper macro Type C upper part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_HIGH(id) \
        (((id << FLEXCAN_ID_EXT_Pos) & 0x1FE00000) >> 5) /*!< Extend Rx FIFO Mask helper macro Type C mid-upper part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_LOW(id) \
        (((id << FLEXCAN_ID_EXT_Pos) & 0x1FE00000) >> 13)/*!< Extend Rx FIFO Mask helper macro Type C mid-lower part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_LOW(id) \
        (((id << FLEXCAN_ID_EXT_Pos) & 0x1FE00000) >> 21) /*!< Extend Rx FIFO Mask helper macro Type C lower part helper macro. */

/**
  * @brief FlexCAN Rx FIFO Filter helper macro.
  */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_A(id, rtr, ide) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_A(id, rtr, ide) /*!< Standard Rx FIFO Filter helper macro Type A helper macro. */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_B_HIGH(id, rtr, ide) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_HIGH(id, rtr, ide) /*!< Standard Rx FIFO Filter helper macro Type B upper part helper macro. */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_B_LOW(id, rtr, ide) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_B_LOW(id, rtr, ide) /*!< Standard Rx FIFO Filter helper macro Type B lower part helper macro. */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_HIGH(id) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_HIGH(id)/*!< Standard Rx FIFO Filter helper macro Type C upper part helper macro. */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_MID_HIGH(id) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_HIGH(id) /*!< Standard Rx FIFO Filter helper macro Type C mid-upper part helper macro. */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_MID_LOW(id) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_MID_LOW(id)  /*!< Standard Rx FIFO Filter helper macro Type C mid-lower part helper macro. */
#define FLEXCAN_RX_FIFO_STD_FILTER_TYPE_C_LOW(id) \
        FLEXCAN_RX_FIFO_STD_MASK_TYPE_C_LOW(id) /*!< Standard Rx FIFO Filter helper macro Type C lower part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_A(id, rtr, ide) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_A(id, rtr, ide) /*!< Extend Rx FIFO Filter helper macro Type A helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_B_HIGH(id, rtr, ide) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_HIGH(id, rtr, ide) /*!< Extend Rx FIFO Filter helper macro Type B upper part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_B_LOW(id, rtr, ide) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_B_LOW(id, rtr, ide) /*!< Extend Rx FIFO Filter helper macro Type B lower part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_HIGH(id) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_HIGH(id)      /*!< Extend Rx FIFO Filter helper macro Type C upper part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_MID_HIGH(id) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_HIGH(id)  /*!< Extend Rx FIFO Filter helper macro Type C mid-upper part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_MID_LOW(id) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_MID_LOW(id)   /*!< Extend Rx FIFO Filter helper macro Type C mid-lower part helper macro. */
#define FLEXCAN_RX_FIFO_EXT_FILTER_TYPE_C_LOW(id) \
        FLEXCAN_RX_FIFO_EXT_MASK_TYPE_C_LOW(id)       /*!< Extend Rx FIFO Filter helper macro Type C lower part helper macro. */


/**
  * @brief Generic status return codes.
  */
#define    Status_Flexcan_Success                0x00000000    /*!< Generic status for Success. */
#define    Status_Flexcan_Fail                   0x00000001    /*!< Generic status for Fail. */
#define    Status_Flexcan_ReadOnly               0x00000002    /*!< Generic status for read only failure. */
#define    Status_Flexcan_OutOfRange             0x00000003    /*!< Generic status for out of range access. */
#define    Status_Flexcan_InvalidArgument        0x00000004    /*!< Generic status for invalid argument check. */
#define    Status_Flexcan_Timeout                0x00000005    /*!< Generic status for timeout. */
#define    Status_Flexcan_NoTransferInProgress   0x00000006    /*!< Generic status for no transfer in progress. */


/**
  * @brief FlexCAN transfer status.
  */
#define    Status_Flexcan_TxBusy                 0x00010000    /*!< Tx Message Buffer is Busy. */
#define    Status_Flexcan_TxIdle                 0x00010001    /*!< Tx Message Buffer is Idle. */
#define    Status_Flexcan_TxSwitchToRx           0x00010002    /*!< Remote Message is send out and Message buffer changed to Receive one. */
#define    Status_Flexcan_RxBusy                 0x00010003    /*!< Rx Message Buffer is Busy. */
#define    Status_Flexcan_RxIdle                 0x00010004    /*!< Rx Message Buffer is Idle. */
#define    Status_Flexcan_RxOverflow             0x00010005    /*!< Rx Message Buffer is Overflowed. */
#define    Status_Flexcan_RxFifoBusy             0x00010006    /*!< Rx Message FIFO is Busy. */
#define    Status_Flexcan_RxFifoIdle             0x00010007    /*!< Rx Message FIFO is Idle. */
#define    Status_Flexcan_RxFifoOverflow         0x00010008    /*!< Rx Message FIFO is overflowed. */
#define    Status_Flexcan_RxFifoWarning          0x00010009    /*!< Rx Message FIFO is almost overflowed. */
#define    Status_Flexcan_RxFifoDisabled         0x0001000A   /*!< Rx Message FIFO is disabled during reading. */
#define    Status_Flexcan_ErrorStatus            0x0001000B   /*!< FlexCAN Module Error and Status. */
#define    Status_Flexcan_WakeUp                 0x0001000C   /*!< FlexCAN is waken up from STOP mode. */
#define    Status_Flexcan_UnHandled              0x0001000D   /*!< UnHadled Interrupt asserted. */
#define    Status_Flexcan_RxRemote               0x0001000E   /*!< Rx Remote Message Received in Mail box. */
#define    Status_Flexcan_RxFifoUnderflow        0x0001000F   /*!< Enhanced Rx Message FIFO is underflow. */

/**
  * @brief FlexCAN frame format.
  */
typedef enum _flexcan_frame_format
{
    Enum_Flexcan_FrameFormatStandard = 0x0U, /*!< Standard frame format attribute. */
    Enum_Flexcan_FrameFormatExtend   = 0x1U  /*!< Extend frame format attribute. */
} flexcan_frame_format_t;

/**
  * @brief FlexCAN frame type.
  */
typedef enum _flexcan_frame_type
{
    Enum_Flexcan_FrameTypeData   = 0x0U, /*!< Data frame type attribute. */
    Enum_Flexcan_FrameTypeRemote = 0x1U  /*!< Remote frame type attribute. */
} flexcan_frame_type_t;

/**
  * @brief FlexCAN clock source.
  */
typedef enum _flexcan_clock_source
{
    Enum_Flexcan_ClkSrc0    = 0x0U,    /*!< FlexCAN Protocol Engine clock selected by user as SRC == 0. */
    Enum_Flexcan_ClkSrc1    = 0x1U     /*!< FlexCAN Protocol Engine clock selected by user as SRC == 1. */
} flexcan_clock_source_t;

/**
  * @brief FlexCAN wake up source.
  */
typedef enum _flexcan_wake_up_source
{
    Enum_Flexcan_WakeupSrcUnfiltered = 0x0U, /*!< FlexCAN uses unfiltered Rx input to detect edge. */
    Enum_Flexcan_WakeupSrcFiltered   = 0x1U  /*!< FlexCAN uses filtered Rx input to detect edge. */
} flexcan_wake_up_source_t;

/**
  * @brief FlexCAN Rx Fifo Filter type.
  */
typedef enum _flexcan_rx_fifo_filter_type
{
    Enum_Flexcan_RxFifoFilterTypeA = 0x0U, /*!< One full ID (standard and extended) per ID Filter element. */
    Enum_Flexcan_RxFifoFilterTypeB = 0x1U, /*!< Two full standard IDs or two partial 14-bit ID slices per ID Filter Table element. */
    Enum_Flexcan_RxFifoFilterTypeC = 0x2U, /*!< Four partial 8-bit Standard or extended ID slices per ID Filter Table element. */
    Enum_Flexcan_RxFifoFilterTypeD = 0x3U  /*!< All frames rejected. */
} flexcan_rx_fifo_filter_type_t;

/**
  * @brief FlexCAN Message Buffer Payload size.
  */
typedef enum _flexcan_mb_size
{
    FLEXCAN_8BperMB  = 0x0U,           /*!< Selects 8 bytes per Message Buffer. */
    FLEXCAN_16BperMB = 0x1U,           /*!< Selects 16 bytes per Message Buffer. */
    FLEXCAN_32BperMB = 0x2U,           /*!< Selects 32 bytes per Message Buffer. */
    FLEXCAN_64BperMB = 0x3U            /*!< Selects 64 bytes per Message Buffer. */
} flexcan_mb_size_t;


/**
  * @brief  FlexCAN Rx FIFO priority.
  * The matching process starts from the Rx MB(or Rx FIFO) with higher priority.
  * If no MB(or Rx FIFO filter) is satisfied, the matching process goes on with
  * the Rx FIFO(or Rx MB) with lower priority.
  */
typedef enum _flexcan_rx_fifo_priority
{
    Enum_Flexcan_RxFifoPrioLow  = 0x0U, /*!< Matching process start from Rx Message Buffer first */
    Enum_Flexcan_RxFifoPrioHigh = 0x1U  /*!< Matching process start from Rx FIFO first */
} flexcan_rx_fifo_priority_t;

/**
  * @brief  FlexCAN interrupt configuration structure, default settings all disabled.
  *
  * This structure contains the settings for all of the FlexCAN Module interrupt configurations.
  * Note: FlexCAN Message Buffers and Rx FIFO have their own interrupts.
  */
enum _flexcan_interrupt_enable
{
    Enum_Flexcan_BusOffInterruptEnable    = FLEXCAN_CTRL1_BOFFMSK_Msk, /*!< Bus Off interrupt. */
    Enum_Flexcan_ErrorInterruptEnable     = FLEXCAN_CTRL1_ERRMSK_Msk,  /*!< Error interrupt. */
    Enum_Flexcan_RxWarningInterruptEnable = FLEXCAN_CTRL1_RWRNMSK_Msk, /*!< Rx Warning interrupt. */
    Enum_Flexcan_TxWarningInterruptEnable = FLEXCAN_CTRL1_TWRNMSK_Msk, /*!< Tx Warning interrupt. */
    Enum_Flexcan_WakeUpInterruptEnable    = FLEXCAN_MCR_WAKMSK_Msk,     /*!< Wake Up interrupt. */
};


/**
  * @brief  FlexCAN status flags.
  *
  * This provides constants for the FlexCAN status flags for use in the FlexCAN functions.
  * Note: The CPU read action clears FlEXCAN_ErrorFlag, therefore user need to
  * read FlEXCAN_ErrorFlag and distinguish which error is occur using
  * @ref _flexcan_error_flags enumerations.
  */
enum _flexcan_flags
{
    Enum_Flexcan_SynchFlag            = FLEXCAN_ESR1_SYNCH_Msk,   /*!< CAN Synchronization Status. */
    Enum_Flexcan_TxWarningIntFlag     = FLEXCAN_ESR1_TWRNINT_Msk, /*!< Tx Warning Interrupt Flag. */
    Enum_Flexcan_RxWarningIntFlag     = FLEXCAN_ESR1_RXWRN_Msk, /*!< Rx Warning Interrupt Flag. */
    Enum_Flexcan_IdleFlag             = FLEXCAN_ESR1_IDLE_Msk,    /*!< CAN IDLE Status Flag. */
    Enum_Flexcan_FaultConfinementFlag = FLEXCAN_ESR1_FLTCONF_Msk, /*!< Fault Confinement State Flag. */
    Enum_Flexcan_TransmittingFlag     = FLEXCAN_ESR1_TX_Msk,      /*!< FlexCAN In Transmission Status. */
    Enum_Flexcan_ReceivingFlag        = FLEXCAN_ESR1_RX_Msk,      /*!< FlexCAN In Reception Status. */
    Enum_Flexcan_BusOffIntFlag        = FLEXCAN_ESR1_BOFFINT_Msk, /*!< Bus Off Interrupt Flag. */
    Enum_Flexcan_ErrorIntFlag         = FLEXCAN_ESR1_ERRINT_Msk,  /*!< Error Interrupt Flag. */
    Enum_Flexcan_ErrorFlag            = (int)(                 /*!< All FlexCAN Error Status. */
        FLEXCAN_ESR1_BIT1ERR_Msk | FLEXCAN_ESR1_BIT0ERR_Msk | FLEXCAN_ESR1_ACKERR_Msk |
        FLEXCAN_ESR1_CRCERR_Msk | FLEXCAN_ESR1_FRMERR_Msk | FLEXCAN_ESR1_STFERR_Msk)
};

/**
  * @brief  FlexCAN error status flags.
  *
  * The FlexCAN Error Status enumerations is used to report current error of the FlexCAN bus.
  * This enumerations should be used with Enum_Flexcan_ErrorFlag in @ref _flexcan_flags enumerations
  * to ditermine which error is generated.
  */
enum _flexcan_error_flags
{
    Enum_Flexcan_TxErrorWarningFlag = FLEXCAN_ESR1_TXWRN_Msk,   /*!< Tx Error Warning Status. */
    Enum_Flexcan_RxErrorWarningFlag = FLEXCAN_ESR1_RXWRN_Msk,   /*!< Rx Error Warning Status. */
    Enum_Flexcan_StuffingError      = FLEXCAN_ESR1_STFERR_Msk,  /*!< Stuffing Error. */
    Enum_Flexcan_FormError          = FLEXCAN_ESR1_FRMERR_Msk,  /*!< Form Error. */
    Enum_Flexcan_CrcError           = FLEXCAN_ESR1_CRCERR_Msk,  /*!< Cyclic Redundancy Check Error. */
    Enum_Flexcan_AckError           = FLEXCAN_ESR1_ACKERR_Msk,  /*!< Received no ACK on transmission. */
    Enum_Flexcan_Bit0Error          = FLEXCAN_ESR1_BIT0ERR_Msk, /*!< Unable to send dominant bit. */
    Enum_Flexcan_Bit1Error          = FLEXCAN_ESR1_BIT1ERR_Msk  /*!< Unable to send recessive bit. */
};


/**
  * @brief  FlexCAN Rx FIFO status flags.
  *
  * The FlexCAN Rx FIFO Status enumerations are used to determine the status of the
  * Rx FIFO. Because Rx FIFO occupy the MB0 ~ MB7 (Rx Fifo filter also occupies
  * more Message Buffer space), Rx FIFO status flags are mapped to the corresponding
  * Message Buffer status flags.
  */
enum
{
    Enum_Flexcan_RxFifoOverflowFlag = FLEXCAN_IFLAG1_BUF7I_Msk, /*!< Rx FIFO overflow flag. */
    Enum_Flexcan_RxFifoWarningFlag  = FLEXCAN_IFLAG1_BUF6I_Msk, /*!< Rx FIFO almost full flag. */
    Enum_Flexcan_RxFifoFrameAvlFlag = FLEXCAN_IFLAG1_BUF5I_Msk  /*!< Frames available in Rx FIFO flag. */
};

#if defined (__CC_ARM)
#pragma anon_unions
#endif

/**
  * @brief FlexCAN message frame structure.
  */
typedef struct _flexcan_frame
{
    struct
    {
        uint32_t timestamp : 16;       /*!< FlexCAN internal Free-Running Counter Time Stamp. */
        uint32_t length    : 4;        /*!< CAN frame payload length in bytes(Range: 0~8). */
        uint32_t type      : 1;        /*!< CAN Frame Type(DATA or REMOTE). */
        uint32_t format    : 1;        /*!< CAN Frame Identifier(STD or EXT format). */
        uint32_t           : 1;        /*!< Reserved. */
        uint32_t idhit     : 9;        /*!< CAN Rx FIFO filter hit id(This value is only used in Rx FIFO receive mode). */
    };
    struct
    {
        uint32_t id : 29;              /*!< CAN Frame Identifier. */
        uint32_t    : 3;               /*!< Reserved. */
    };
    union
    {
        struct
        {
            uint32_t dataWord0;        /*!< CAN Frame payload word0. */
            uint32_t dataWord1;        /*!< CAN Frame payload word1. */
        };
        struct
        {
            uint8_t dataByte3;         /*!< CAN Frame payload byte3. */
            uint8_t dataByte2;         /*!< CAN Frame payload byte2. */
            uint8_t dataByte1;         /*!< CAN Frame payload byte1. */
            uint8_t dataByte0;         /*!< CAN Frame payload byte0. */
            uint8_t dataByte7;         /*!< CAN Frame payload byte7. */
            uint8_t dataByte6;         /*!< CAN Frame payload byte6. */
            uint8_t dataByte5;         /*!< CAN Frame payload byte5. */
            uint8_t dataByte4;         /*!< CAN Frame payload byte4. */
        };
    };
} flexcan_frame_t;

/**
  * @brief FlexCAN FD message frame structure.
  */
typedef struct _flexcan_fd_frame
{
    struct
    {
        uint32_t timestamp  : 16;      /*!< FlexCAN internal Free-Running Counter Time Stamp. */
        uint32_t length     : 4;       /*!< CAN frame data length in bytes, range see @ref _flexcan_fd_frame_length. */
        uint32_t type       : 1;       /*!< CAN Frame Type(DATA or REMOTE). */
        uint32_t format     : 1;       /*!< CAN Frame Identifier(STD or EXT format). */
        uint32_t srr        : 1;       /*!< Substitute Remote request. */
        uint32_t RESERVED_0 : 1;
        uint32_t code       : 4;       /*!< Message Buffer Code. */
        uint32_t RESERVED_1 : 1;
        uint32_t esi        : 1;       /*!< Error State Indicator. */
        uint32_t brs        : 1;       /*!< Bit Rate Switch. */
        uint32_t edl        : 1;       /*!< Extended Data Length. */
    };
    struct
    {
        uint32_t id         : 29;      /*!< CAN Frame Identifier. */
        uint32_t RESERVED_3 : 3;       /*!< Reserved. */
    };
    union
    {
        struct
        {
            uint32_t dataWord[16];     /*!< CAN FD Frame payload, 16 double word maximum. */
        };
        struct
        {
            uint8_t dataByte3;         /*!< CAN Frame payload byte3. */
            uint8_t dataByte2;         /*!< CAN Frame payload byte2. */
            uint8_t dataByte1;         /*!< CAN Frame payload byte1. */
            uint8_t dataByte0;         /*!< CAN Frame payload byte0. */
            uint8_t dataByte7;         /*!< CAN Frame payload byte7. */
            uint8_t dataByte6;         /*!< CAN Frame payload byte6. */
            uint8_t dataByte5;         /*!< CAN Frame payload byte5. */
            uint8_t dataByte4;         /*!< CAN Frame payload byte4. */
            uint8_t dataByte11;        /*!< CAN Frame payload byte11. */
            uint8_t dataByte10;        /*!< CAN Frame payload byte10. */
            uint8_t dataByte9;         /*!< CAN Frame payload byte9. */
            uint8_t dataByte8;         /*!< CAN Frame payload byte8. */
            uint8_t dataByte15;        /*!< CAN Frame payload byte15. */
            uint8_t dataByte14;        /*!< CAN Frame payload byte14. */
            uint8_t dataByte13;        /*!< CAN Frame payload byte13. */
            uint8_t dataByte12;        /*!< CAN Frame payload byte12. */
            uint8_t dataByte19;        /*!< CAN Frame payload byte19. */
            uint8_t dataByte18;        /*!< CAN Frame payload byte18. */
            uint8_t dataByte17;        /*!< CAN Frame payload byte17. */
            uint8_t dataByte16;        /*!< CAN Frame payload byte16. */
            uint8_t dataByte23;        /*!< CAN Frame payload byte23. */
            uint8_t dataByte22;        /*!< CAN Frame payload byte22. */
            uint8_t dataByte21;        /*!< CAN Frame payload byte21. */
            uint8_t dataByte20;        /*!< CAN Frame payload byte20. */
            uint8_t dataByte27;        /*!< CAN Frame payload byte27. */
            uint8_t dataByte26;        /*!< CAN Frame payload byte26. */
            uint8_t dataByte25;        /*!< CAN Frame payload byte25. */
            uint8_t dataByte24;        /*!< CAN Frame payload byte24. */
            uint8_t dataByte31;        /*!< CAN Frame payload byte31. */
            uint8_t dataByte30;        /*!< CAN Frame payload byte30. */
            uint8_t dataByte29;        /*!< CAN Frame payload byte29. */
            uint8_t dataByte28;        /*!< CAN Frame payload byte28. */
            uint8_t dataByte35;        /*!< CAN Frame payload byte35. */
            uint8_t dataByte34;        /*!< CAN Frame payload byte34. */
            uint8_t dataByte33;        /*!< CAN Frame payload byte33. */
            uint8_t dataByte32;        /*!< CAN Frame payload byte32. */
            uint8_t dataByte39;        /*!< CAN Frame payload byte39. */
            uint8_t dataByte38;        /*!< CAN Frame payload byte38. */
            uint8_t dataByte37;        /*!< CAN Frame payload byte37. */
            uint8_t dataByte36;        /*!< CAN Frame payload byte36. */
            uint8_t dataByte43;        /*!< CAN Frame payload byte43. */
            uint8_t dataByte42;        /*!< CAN Frame payload byte42. */
            uint8_t dataByte41;        /*!< CAN Frame payload byte41. */
            uint8_t dataByte40;        /*!< CAN Frame payload byte40. */
            uint8_t dataByte47;        /*!< CAN Frame payload byte47. */
            uint8_t dataByte46;        /*!< CAN Frame payload byte46. */
            uint8_t dataByte45;        /*!< CAN Frame payload byte45. */
            uint8_t dataByte44;        /*!< CAN Frame payload byte44. */
            uint8_t dataByte51;        /*!< CAN Frame payload byte51. */
            uint8_t dataByte50;        /*!< CAN Frame payload byte50. */
            uint8_t dataByte49;        /*!< CAN Frame payload byte49. */
            uint8_t dataByte48;        /*!< CAN Frame payload byte48. */
            uint8_t dataByte55;        /*!< CAN Frame payload byte55. */
            uint8_t dataByte54;        /*!< CAN Frame payload byte54. */
            uint8_t dataByte53;        /*!< CAN Frame payload byte53. */
            uint8_t dataByte52;        /*!< CAN Frame payload byte52. */
            uint8_t dataByte59;        /*!< CAN Frame payload byte59. */
            uint8_t dataByte58;        /*!< CAN Frame payload byte58. */
            uint8_t dataByte57;        /*!< CAN Frame payload byte57. */
            uint8_t dataByte56;        /*!< CAN Frame payload byte56. */
            uint8_t dataByte63;        /*!< CAN Frame payload byte63. */
            uint8_t dataByte62;        /*!< CAN Frame payload byte62. */
            uint8_t dataByte61;        /*!< CAN Frame payload byte61. */
            uint8_t dataByte60;        /*!< CAN Frame payload byte60. */
        };
    };
} flexcan_fd_frame_t;

/**
  * @brief FlexCAN protocol timing characteristic configuration structure.
  */
typedef struct _flexcan_timing_config
{
    uint16_t      preDivider;          /*!< Clock Pre-scaler Division Factor. */
    uint8_t       rJumpwidth;          /*!< Re-sync Jump Width. */
    uint8_t       phaseSeg1;           /*!< Phase Segment 1. */
    uint8_t       phaseSeg2;           /*!< Phase Segment 2. */
    uint8_t       propSeg;             /*!< Propagation Segment. */

     /*!< FlexCAN has flexible data rate. */
    uint16_t      fpreDivider;         /*!< CAN FD data phase Clock Pre-scaler Division Factor. */
    uint8_t       frJumpwidth;         /*!< CAN FD data phase Re-sync Jump Width. */
    uint8_t       fphaseSeg1;          /*!< CAN FD data phase Phase Segment 1. */
    uint8_t       fphaseSeg2;          /*!< CAN FD data phase Phase Segment 2. */
    uint8_t       fpropSeg;            /*!< CAN FD data phase Propagation Segment. */
} flexcan_timing_config_t;


/**
  * @brief FlexCAN module configuration structure.
  */
typedef struct _flexcan_config
{
    uint32_t                 baudRate;             /*!< FlexCAN baud rate in bps. */
    uint32_t                 baudRateFD;           /*!< FlexCAN FD baud rate in bps. */
    flexcan_clock_source_t   clkSrc;               /*!< Clock source for FlexCAN Protocol Engine. */
    flexcan_wake_up_source_t wakeupSrc;            /*!< Wake up source selection. */
    uint8_t                  maxMbNum;             /*!< The maximum number of Message Buffers used by user. */
    bool                     enableLoopBack;       /*!< Enable or Disable Loop Back Self Test Mode. */
    bool                     enableTimerSync;      /*!< Enable or Disable Timer Synchronization. */
    bool                     enableSelfWakeup;     /*!< Enable or Disable Self Wakeup Mode. */
    bool                     enableIndividMask;    /*!< Enable or Disable Rx Individual Mask. */
    bool                     disableSelfReception; /*!< Enable or Disable Self Reflection. */
    bool                     enableListenOnlyMode; /*!< Enable or Disable Listen Only Mode. */

    flexcan_timing_config_t  timingConfig;         /*!< Protocol timing. */
} flexcan_config_t;

/**
  * @brief  FlexCAN Receive Message Buffer configuration structure
  *
  * This structure is used as the parameter of FLEXCAN_RxMbConfig() function.
  * The FLEXCAN_RxMbConfig() function is used to configure FlexCAN Receive
  * Message Buffer. The function abort previous receiving process, clean the
  * Message Buffer and activate the Rx Message Buffer using given Message Buffer
  * setting.
  */
typedef struct _flexcan_rx_mb_config
{
    uint32_t               id;         /*!< CAN Message Buffer Frame Identifier. */
    flexcan_frame_format_t format;     /*!< CAN Frame Identifier format(Standard of Extend). */
    flexcan_frame_type_t   type;       /*!< CAN Frame Type(Data or Remote). */
} flexcan_rx_mb_config_t;

/**
  * @brief FlexCAN Rx FIFO configuration structure.
  */
typedef struct _flexcan_rx_fifo_config
{
    uint32_t                     *idFilterTable; /*!< Pointer to the FlexCAN Rx FIFO identifier filter table. */
    uint8_t                       idFilterNum;   /*!< The quantity of filter elements. */
    flexcan_rx_fifo_filter_type_t idFilterType;  /*!< The FlexCAN Rx FIFO Filter type. */
    flexcan_rx_fifo_priority_t    priority;      /*!< The FlexCAN Rx FIFO receive priority. */
} flexcan_rx_fifo_config_t;

/**
  * @brief FlexCAN Message Buffer transfer.
  */
typedef struct _flexcan_mb_transfer
{
    flexcan_fd_frame_t      *framefd;  /*!< The buffer of CAN FD Message to be transfer. */
    flexcan_frame_t         *frame;    /*!< The buffer of CAN Message to be transfer. */
    uint8_t                  mbIdx;    /*!< The index of Message buffer used to transfer Message. */
} flexcan_mb_transfer_t;

/**
  * @brief FlexCAN Rx FIFO transfer.
  */
typedef struct _flexcan_fifo_transfer
{
    flexcan_fd_frame_t *framefd;      /*!< The buffer of CAN Message to be received from Enhanced Rx FIFO. */
    flexcan_frame_t *frame;           /*!< The buffer of CAN Message to be received from Rx FIFO. */
    uint32_t frameNum;        /*!< Number of CAN Message need to be received from Legacy or Ehanced Rx FIFO. */
} flexcan_fifo_transfer_t;

/**
  * @brief FlexCAN handle structure definition.
  */
typedef struct _flexcan_handle flexcan_handle_t;

/**
  * @brief FlexCAN transfer callback function.
  *
  * The FlexCAN transfer callback returns a value from the underlying layer.
  * If the status equals to Status_Flexcan_ErrorStatus, the result parameter is the Content of
  * FlexCAN status register which can be used to get the working status(or error status) of FlexCAN module.
  * If the status equals to other FlexCAN Message Buffer transfer status, the result is the index of
  * Message Buffer that generate transfer event.
  * If the status equals to other FlexCAN Message Buffer transfer status, the result is meaningless and should be
  * Ignored.
  */
typedef void (*flexcan_transfer_callback_t)(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, uint32_t status, uint32_t result, void *userData);

/**
  * @brief FlexCAN handle structure.
  */
struct _flexcan_handle
{
    flexcan_transfer_callback_t       callback; /*!< Callback function. */
    void                             *userData; /*!< FlexCAN callback function parameter. */
    flexcan_frame_t *volatile         mbFrameBuf[CAN_WORD1_COUNT];
    flexcan_fd_frame_t *volatile      mbFDFrameBuf[CAN_WORD1_COUNT];
    /*!< The buffer for received data from Message Buffers. ------------------*/
    flexcan_frame_t *volatile         rxFifoFrameBuf;             /*!< The buffer for received data from Rx FIFO. */
    uint32_t                          rxFifoFrameNum;         /*!< The number of CAN messages remaining to be received from Rx FIFO. */
    uint32_t                          rxFifoTransferTotalNum;  /*!< Total CAN Message number need to be received from Rx FIFO. */
    volatile uint8_t                  mbState[CAN_WORD1_COUNT];   /*!< Message Buffer transfer state. */
    volatile uint8_t                  rxFifoState;                /*!< Rx FIFO transfer state. */
    volatile uint32_t                 timestamp[CAN_WORD1_COUNT]; /*!< Mailbox transfer timestamp. */
};

/**
  * @brief FlexCAN FD Message Buffer Size.
  */
typedef enum
{
    FlexCANFD_TX_0Byte_DataLen   = 0,  /* FlexCANFD sends 0 byte of data length per frame */
    FlexCANFD_TX_1Byte_DataLen   = 1,  /* FlexCANFD sends 1 byte of data length per frame */
    FlexCANFD_TX_2Bytes_DataLen  = 2,  /* FlexCANFD sends 2 bytes of data length per frame */
    FlexCANFD_TX_3Bytes_DataLen  = 3,  /* FlexCANFD sends 3 bytes of data length per frame */
    FlexCANFD_TX_4Bytes_DataLen  = 4,  /* FlexCANFD sends 4 bytes of data length per frame */
    FlexCANFD_TX_5Bytes_DataLen  = 5,  /* FlexCANFD sends 5 bytes of data length per frame */
    FlexCANFD_TX_6Bytes_DataLen  = 6,  /* FlexCANFD sends 6 bytes of data length per frame */
    FlexCANFD_TX_7Bytes_DataLen  = 7,  /* FlexCANFD sends 7 bytes of data length per frame */
    FlexCANFD_TX_8Bytes_DataLen  = 8,  /* FlexCANFD sends 8 bytes of data length per frame */
    FlexCANFD_TX_12Bytes_DataLen = 9,  /* FlexCANFD sends 12 bytes of data length per frame */
    FlexCANFD_TX_16Bytes_DataLen = 10, /* FlexCANFD sends 16 bytes of data length per frame */
    FlexCANFD_TX_20Bytes_DataLen = 11, /* FlexCANFD sends 20 bytes of data length per frame */
    FlexCANFD_TX_24Bytes_DataLen = 12, /* FlexCANFD sends 24 bytes of data length per frame */
    FlexCANFD_TX_32Bytes_DataLen = 13, /* FlexCANFD sends 32 bytes of data length per frame */
    FlexCANFD_TX_48Bytes_DataLen = 14, /* FlexCANFD sends 48 bytes of data length per frame */
    FlexCANFD_TX_64Bytes_DataLen = 15  /* FlexCANFD sends 64 bytes of data length per frame */
} FLEXCANFD_Tx_DataLen_Type;

/**
  * @}
  */



/** @defgroup FLEXCAN_Exported_Functions
  * @{
  */
void FLEXCAN_EnterFreezeMode(FLEXCAN_TypeDef *flex_can);
void FLEXCAN_ExitFreezeMode(FLEXCAN_TypeDef *flex_can);
ErrorStatus FLEXCAN_CalculateImprovedTimingValues(uint32_t baudRate, uint32_t sourceClock_Hz, flexcan_timing_config_t *pTimingConfig);
void FLEXCAN_Init(FLEXCAN_TypeDef *flex_can, const flexcan_config_t *pConfig);
void FLEXCAN_Deinit(FLEXCAN_TypeDef *flex_can);
void FLEXCAN_GetDefaultConfig(flexcan_config_t *pConfig);
void FLEXCAN_SetTimingConfig(FLEXCAN_TypeDef *flex_can, const flexcan_timing_config_t *pConfig);
void FLEXCAN_SetRxMbGlobalMask(FLEXCAN_TypeDef *flex_can, uint32_t mask);
void FLEXCAN_SetRxFifoGlobalMask(FLEXCAN_TypeDef *flex_can, uint32_t mask);
void FLEXCAN_SetRxIndividualMask(FLEXCAN_TypeDef *flex_can, uint8_t maskIdx, uint32_t mask);
void FLEXCAN_TxMbConfig(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, FunctionalState state);
void FLEXCAN_RxMbConfig(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, const flexcan_rx_mb_config_t *pRxMbConfig, FunctionalState state);
void FLEXCAN_RxFifoConfig(FLEXCAN_TypeDef *flex_can, const flexcan_rx_fifo_config_t *pRxFifoConfig, FunctionalState state);
void FLEXCAN_EnableRxFifoDMA(FLEXCAN_TypeDef *flex_can, FunctionalState state);


/**
  * @brief  Gets the FlexCAN module interrupt flags.
  *
  * This function gets all FlexCAN status flags. The flags are returned as the logical
  * OR value of the enumerators @ref _flexcan_flags. To check the specific status,
  * compare the return value with enumerators in @ref _flexcan_flags.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @return FlexCAN status flags which are ORed by the enumerators in the _flexcan_flags.
  */
__STATIC_INLINE uint32_t FLEXCAN_GetStatusFlags(FLEXCAN_TypeDef *flex_can)
{
    return flex_can->ESR1;
}

/**
  * @brief  Clears status flags with the provided mask.
  *
  * This function clears the FlexCAN status flags with a provided mask. An automatically cleared flag
  * can't be cleared by this function.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The status flags to be cleared, it is logical OR value of @ref _flexcan_flags.
  */
__STATIC_INLINE void FLEXCAN_ClearStatusFlags(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
     /* Write 1 to clear status flag. -----------------------------------------*/
    flex_can->ESR1 = mask;
}

/**
  * @brief  Gets the FlexCAN Bus Error Counter value.
  *
  * This function gets the FlexCAN Bus Error Counter value for both Tx and
  * Rx direction. These values may be needed in the upper layer error handling.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param txErrBuf Buffer to store Tx Error Counter value.
  * @param rxErrBuf Buffer to store Rx Error Counter value.
  */
__STATIC_INLINE void FLEXCAN_GetBusErrCount(FLEXCAN_TypeDef *flex_can, uint8_t *txErrBuf, uint8_t *rxErrBuf)
{
    if (NULL != txErrBuf)
    {
        *txErrBuf = (uint8_t)((flex_can->ECR & FLEXCAN_ECR_TXERRCNT_Msk) >> FLEXCAN_ECR_TXERRCNT_Pos);
    }

    if (NULL != rxErrBuf)
    {
        *rxErrBuf = (uint8_t)((flex_can->ECR & FLEXCAN_ECR_RXERRCNT_Msk) >> FLEXCAN_ECR_RXERRCNT_Pos);
    }
}

/**
  * @brief  Gets the FlexCAN Message Buffer interrupt flags.
  *
  * This function gets the interrupt flags of a given Message Buffers.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The ORed FlexCAN Message Buffer mask.
  * @return The status of given Message Buffers.
  */
__STATIC_INLINE uint32_t FLEXCAN_GetMbStatusFlags(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
    return (flex_can->IFLAG1 & mask);
}

/**
  * @brief  Clears the FlexCAN Message Buffer interrupt flags.
  *
  * This function clears the interrupt flags of a given Message Buffers.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The ORed FlexCAN Message Buffer mask.
  */
__STATIC_INLINE void FLEXCAN_ClearMbStatusFlags(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
    flex_can->IFLAG1 = mask;
}

/**
  * @brief  Enables FlexCAN interrupts according to the provided mask.
  *
  * This function enables the FlexCAN interrupts according to the provided mask. The mask
  * is a logical OR of enumeration members, see @ref _flexcan_interrupt_enable.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The interrupts to enable. Logical OR of @ref _flexcan_interrupt_enable.
  */
__STATIC_INLINE void FLEXCAN_EnableInterrupts(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
     /* Solve Wake Up Interrupt. ----------------------------------------------*/
    if ((uint32_t)Enum_Flexcan_WakeUpInterruptEnable == (mask & (uint32_t)Enum_Flexcan_WakeUpInterruptEnable))
    {
        flex_can->MCR |= FLEXCAN_MCR_WAKMSK_Msk;
    }

     /* Solve others. ---------------------------------------------------------*/
    flex_can->CTRL1 |= (mask & (~((uint32_t)Enum_Flexcan_WakeUpInterruptEnable)));
}

/**
  * @brief  Disables FlexCAN interrupts according to the provided mask.
  *
  * This function disables the FlexCAN interrupts according to the provided mask. The mask
  * is a logical OR of enumeration members, see @ref _flexcan_interrupt_enable.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The interrupts to disable. Logical OR of @ref _flexcan_interrupt_enable.
  */
__STATIC_INLINE void FLEXCAN_DisableInterrupts(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
     /* Solve Wake Up Interrupt. ----------------------------------------------*/
    if ((uint32_t)Enum_Flexcan_WakeUpInterruptEnable == (mask & (uint32_t)Enum_Flexcan_WakeUpInterruptEnable))
    {
        flex_can->MCR &= ~FLEXCAN_MCR_WAKMSK_Msk;
    }

     /* Solve others. ---------------------------------------------------------*/
    flex_can->CTRL1 &= ~(mask & (~((uint32_t)Enum_Flexcan_WakeUpInterruptEnable)));
}

/**
  * @brief  Enables FlexCAN Message Buffer interrupts.
  *
  * This function enables the interrupts of given Message Buffers.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The ORed FlexCAN Message Buffer mask.
  */
__STATIC_INLINE void FLEXCAN_EnableMbInterrupts(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
    flex_can->IMASK1 |= mask;
}

/**
  * @brief  Disables FlexCAN Message Buffer interrupts.
  *
  * This function disables the interrupts of given Message Buffers.
  *
  * @param flex_can FlexCAN peripheral Struct Point.
  * @param mask The ORed FlexCAN Message Buffer mask.
  */
__STATIC_INLINE void FLEXCAN_DisableMbInterrupts(FLEXCAN_TypeDef *flex_can, uint32_t mask)
{
    flex_can->IMASK1 &= ~mask;
}

/**
  * @brief  Enables or disables the FlexCAN module operation.
  *
  * This function enables or disables the FlexCAN module.
  *
  * @param flex_can FlexCAN flex_can pointer.
  * @param  state: new state of the adc peripheral.
  */
__STATIC_INLINE void FLEXCAN_Cmd(FLEXCAN_TypeDef *flex_can, FunctionalState state)
{
    if (state)
    {
        flex_can->MCR &= ~FLEXCAN_MCR_MDIS_Msk; /*!< Enable FlexCAN */

         /* Wait FlexCAN exit from low-power mode. ----------------------------*/
        while (0U != (flex_can->MCR & FLEXCAN_MCR_LPMACK_Msk))
        {
        }
    }
    else
    {
        flex_can->MCR |= FLEXCAN_MCR_MDIS_Msk; /*!< Disable FlexCAN */

         /* Wait FlexCAN enter low-power mode. --------------------------------*/
        while (0U == (flex_can->MCR & FLEXCAN_MCR_LPMACK_Msk))
        {
        }
    }
}

int32_t FLEXCAN_WriteTxMb(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, const flexcan_frame_t *pTxFrame);
int32_t FLEXCAN_ReadRxMb(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, flexcan_frame_t *pRxFrame);
int32_t FLEXCAN_WriteFDTxMb(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, const flexcan_fd_frame_t *pTxFrame);
int32_t FLEXCAN_ReadFDRxMb(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, flexcan_fd_frame_t *pRxFrame);
int32_t FLEXCAN_ReadRxFifo(FLEXCAN_TypeDef *flex_can, flexcan_frame_t *pRxFrame);
int32_t FLEXCAN_TransferFDSendBlocking(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, flexcan_fd_frame_t *pTxFrame);
int32_t FLEXCAN_TransferFDReceiveBlocking(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, flexcan_fd_frame_t *pRxFrame);
int32_t FLEXCAN_TransferFDReceiveNonBlocking(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, flexcan_mb_transfer_t *pMbXfer);
int32_t FLEXCAN_TransferFDSendNonBlocking(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, flexcan_mb_transfer_t *pMbXfer);
void FLEXCAN_TransferFDAbortReceive(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, uint8_t mbIdx);
int32_t FLEXCAN_TransferSendBlocking(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, flexcan_frame_t *pTxFrame);
int32_t FLEXCAN_TransferReceiveBlocking(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, flexcan_frame_t *pRxFrame);
int32_t FLEXCAN_TransferReceiveFifoBlocking(FLEXCAN_TypeDef *flex_can, flexcan_frame_t *pRxFrame);
void FLEXCAN_TransferCreateHandle(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, flexcan_transfer_callback_t callback, void *userData);
int32_t FLEXCAN_TransferSendNonBlocking(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, flexcan_mb_transfer_t *pMbXfer);
int32_t FLEXCAN_TransferReceiveNonBlocking(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, flexcan_mb_transfer_t *pMbXfer);
int32_t FLEXCAN_TransferReceiveFifoNonBlocking(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, flexcan_fifo_transfer_t *pFifoXfer);
uint32_t FLEXCAN_GetTimeStamp(flexcan_handle_t *handle, uint8_t mbIdx);
void FLEXCAN_TransferAbortSend(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, uint8_t mbIdx);
void FLEXCAN_TransferAbortReceive(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle, uint8_t mbIdx);
void FLEXCAN_TransferAbortReceiveFifo(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle);
void FLEXCAN_TransferHandleIRQ(FLEXCAN_TypeDef *flex_can, flexcan_handle_t *handle);
ErrorStatus FLEXCAN_FDCalculateImprovedTimingValues(uint32_t baudRate, uint32_t baudRateFD, uint32_t sourceClock_Hz, flexcan_timing_config_t *pTimingConfig);
void FLEXCAN_FDTxMbConfig(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, FunctionalState enable);
void FLEXCAN_FDRxMbConfig(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx, const flexcan_rx_mb_config_t *pRxMbConfig, FunctionalState state);
void FLEXCAN_SetFDTimingConfig(FLEXCAN_TypeDef *flex_can, const flexcan_timing_config_t *pConfig);
void FLEXCAN_FDInit(FLEXCAN_TypeDef *flex_can, const flexcan_config_t *pConfig, flexcan_mb_size_t dataSize, FunctionalState brs);
void FLEXCAN_SetBaudRate(FLEXCAN_TypeDef *flex_can, flexcan_timing_config_t timingConfig);
void FLEXCAN_SetFDBaudRate(FLEXCAN_TypeDef *flex_can, flexcan_timing_config_t timingConfig);
uint32_t FLEXCAN_GetFDMailboxOffset(FLEXCAN_TypeDef *flex_can, uint8_t mbIdx);



#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
