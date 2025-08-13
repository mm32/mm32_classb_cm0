/***********************************************************************************************************************
    @file     hal_i3c.h
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef __HAL_I3C_H
#define __HAL_I3C_H

/* Includes ----------------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup StdPeriph_Driver
  * @{
  */

/** @addtogroup I3C
  * @{
  */

/** @defgroup I3C_Exported_Types
  * @{
  */


#define I3C_IDRandom_Disable     (0x00U << I3C_CONFIG_IDRAND_Pos)
#define I3C_IDRandom_Enable      (0x01U << I3C_CONFIG_IDRAND_Pos)

#define I3C_AllRequest_ACK       (0x00U << I3C_CONFIG_NACK_Pos)
#define I3C_CCCRequest_NAK       (0x01U << I3C_CONFIG_NACK_Pos)

#define I3C_S0S1Error_Detect     (0x00U << I3C_CONFIG_S0IGNORE_Pos)
#define I3C_S0S1Error_NoDetect   (0x01U << I3C_CONFIG_S0IGNORE_Pos)

#define I3C_StartStop_NoMatch    (0x00U << I3C_CONFIG_MATCHSS_Pos)
#define I3C_StartStop_Match      (0x01U << I3C_CONFIG_MATCHSS_Pos)

/**
  * @brief  I3C FLAG
  */
#define I3C_FLAG_STNOTSTOP       (0x01U << I3C_STATUS_STNOTSTOP_Pos) /*!< Slave status not stop flag */
#define I3C_FLAG_STMSG           (0x01U << I3C_STATUS_STMSG_Pos)     /*!< Slave status message, indicating slave is listening to the bus traffic or responding */
#define I3C_FLAG_STCCCH          (0x01U << I3C_STATUS_STCCCH_Pos)    /*!< Slave status not stop flag */
#define I3C_FLAG_STREQRD         (0x01U << I3C_STATUS_STREQRD_Pos)   /*!< Slave status required, either is master doing SDR read from slave, or is IBI pushing out. */
#define I3C_FLAG_STREQWR         (0x01U << I3C_STATUS_STREQWR_Pos)   /*!< Slave status request write, master is doing SDR write to slave, except slave in ENTDAA mode */
#define I3C_FLAG_STDAA           (0x01U << I3C_STATUS_STDAA_Pos)     /*!< I3C bus is in ENTDAA mode */
#define I3C_FLAG_STHDR           (0x01U << I3C_STATUS_STHDR_Pos)     /*!< I3C bus is in HDR mode */
#define I3C_FLAG_START           (0x01U << I3C_STATUS_START_Pos)     /*!< Start/Re-start event is seen since the bus was last cleared */
#define I3C_FLAG_MATCHED         (0x01U << I3C_STATUS_MATCHED_Pos)    /*!< Slave address(dynamic/static) matched since last cleared */
#define I3C_FLAG_STOP            (0x01U << I3C_STATUS_STOP_Pos)      /*!<Stop event is seen since the bus was last cleared */
#define I3C_FLAG_RXPEND          (0x01U << I3C_STATUS_RXPEND_Pos)    /*!< Rx data ready in rx buffer flag */
#define I3C_FLAG_TXNOTFULL       (0x01U << I3C_STATUS_TXNOTFULL_Pos) /*!< Tx buffer ready for Tx data flag */
#define I3C_FLAG_DACHG           (0x01U << I3C_STATUS_DACHG_Pos)     /*!< Slave dynamic address has been assigned, re-assigned, or lost */
#define I3C_FLAG_CCC             (0x01U << I3C_STATUS_CCC_Pos)       /*!< Slave received Common command code */
#define I3C_FLAG_ERWAR           (0x01U << I3C_STATUS_ERWAR_Pos)     /*!< Error occurred flag */
#define I3C_FLAG_CHANDLED        (0x01U << I3C_STATUS_CHANDLED_Pos)  /*!< I3C slave device has processed CCC */
#define I3C_FLAG_EVENT           (0x01U << I3C_STATUS_EVENT_Pos)     /*!< An IBI or Hot-Join has been requested. */
#define I3C_FLAG_EVDET           (0x03U << I3C_STATUS_EVDET_Pos)     /*!< The current (EVENT is 1) status of the pending event. */
#define I3C_FLAG_IBIDIS          (0x01U << I3C_STATUS_IBIDIS_Pos)    /*!< Slave in band interrupt is disabled. */
#define I3C_FLAG_MRDIS           (0x01U << I3C_STATUS_MRDIS_Pos)     /*!< Slave master request is disabled. */
#define I3C_FLAG_HJDIS           (0x01U << I3C_STATUS_HJDIS_Pos)     /*!< Slave Hot-Join is disabled. */
#define I3C_FLAG_ACTSTATE        (0x03U << I3C_STATUS_ACTSTATE_Pos)  /*!< The active state of the I3C bus controller by ENTASn CCC. */

/**
  * @brief  I3C activity Status
  */
typedef enum
{
    I3C_ACTDELAY_NONE,                 /*!< No latency, normal bus operation. */
    I3C_ACTDELAY_1ms,                  /*!< Delay 1ms. */
    I3C_ACTDELAY_100ms,                /*!< Delay 100ms */
    I3C_ACTDELAY_10s                   /*!< Delay 10s */
} I3C_ActStatus;

/**
  * @brief  I3C evdet Status
  */
typedef enum
{
    I3C_EVDET_NONE,                    /*!< No pending event status. */
    I3C_EVDET_IDLE,                    /*!< The request has not been sent. */
    I3C_EVDET_NACK,                    /*!< The request was sent but not responded to (NACK), and will be retried. */
    I3C_EVDET_ACK                      /*!< The request was sent and responded to (ACK). */
} I3C_EvdetStatus;

/**
  * @brief  I3C interrupt
  */
#define I3C_IT_START                (0x01U << I3C_INTSET_START_Pos)         /*!< The START/RESTART condition of the bus was detected. Procedure */
#define I3C_IT_MATCHED              (0x01U << I3C_INTSET_MATCHED_Pos)       /*!< Dynamic or static address matching interruption was enabled */
#define I3C_IT_STOP                 (0x01U << I3C_INTSET_STOP_Pos)          /*!< The interrupt condition of bus STOP was detected */
#define I3C_IT_RXPEND               (0x01U << I3C_INTSET_RXPEND_Pos)        /*!< Enable the receiving interrupt */
#define I3C_IT_TXSEND               (0x01U << I3C_INTSET_TXSEND_Pos)        /*!< Data sending (read) interruption is enabled */
#define I3C_IT_DACHG                (0x01U << I3C_INTSET_DACHG_Pos)         /*!< Disable dynamic address change (caused by SETDASA, ENTDAA, or RSTDAA) */
#define I3C_IT_CCC                  (0x01U << I3C_INTSET_CCC_Pos)           /*!< CCC receive interrupt function enable */
#define I3C_IT_ERRWARN              (0x01U << I3C_INTSET_ERRWARN_Pos)       /*!< Error/Warning Interrupt enable */
#define I3C_IT_CHANDLED             (0x01U << I3C_INTSET_CHANDLED_Pos)      /*!< The CCC process is complete. The interrupt function is enabled */
#define I3C_IT_EVENT                (0x01U << I3C_INTSET_EVENT_Pos)         /*!< The event request (IBI, MR, or Hot-Join) interruption function was enabled */

/**
  * @brief  I3C FIFO trigger level
  */
#define I3C_TXFIFO_TRIG_Level0           (0x00U << I3C_DATACTRL_TXTRIG_Pos) /*!< Triggered when empty */
#define I3C_TXFIFO_TRIG_Level1           (0x01U << I3C_DATACTRL_TXTRIG_Pos) /*!< Triggered when 1/4 full */
#define I3C_TXFIFO_TRIG_Level2           (0x02U << I3C_DATACTRL_TXTRIG_Pos) /*!< Triggered when 1/2 full */
#define I3C_TXFIFO_TRIG_Level3           (0x03U << I3C_DATACTRL_TXTRIG_Pos) /*!< Triggered when 1 or less than full */

#define I3C_RXFIFO_TRIG_Level0           (0x00U << I3C_DATACTRL_RXTRIG_Pos) /*!< Triggered when empty */
#define I3C_RXFIFO_TRIG_Level1           (0x01U << I3C_DATACTRL_RXTRIG_Pos) /*!< Triggered when 1/4 full */
#define I3C_RXFIFO_TRIG_Level2           (0x02U << I3C_DATACTRL_RXTRIG_Pos) /*!< Triggered when 1/2 full */
#define I3C_RXFIFO_TRIG_Level3           (0x03U << I3C_DATACTRL_RXTRIG_Pos) /*!< Triggered when 3/4 full */

/**
  * @brief  I3C FIFO Select
  */
#define I3C_TXFIFO                       0
#define I3C_RXFIFO                       1

/**
  * @brief  I3C FIFO Status
  */
#define I3C_TXFIFO_Full                  (0x01U << I3C_DATACTRL_TXFULL_Pos)
#define I3C_RXFIFO_Empty                 (0x01U << I3C_DATACTRL_RXEMPTY_Pos)

/**
  * @brief  I3C slave event
  */
#define I3C_EVENT_Normal                 (0x00U << I3C_CTRL_EVENT_Pos) /*!< Normal mode. */
#define I3C_EVENT_IBI                    (0x01U << I3C_CTRL_EVENT_Pos) /*!< In band interrupt event. */
#define I3C_EVENT_HotJoin                (0x03U << I3C_CTRL_EVENT_Pos) /*!< Hot-join event. */

/**
  * @}
  */

/** @defgroup I3C_Exported_Functions
  * @{
  */
void I3C_RequestEventConfig(I3C_TypeDef *i3c, uint32_t event);
void I3C_IBIDataConfig(I3C_TypeDef *i3c, uint8_t data);
void I3C_VendorInfoConfig(I3C_TypeDef *i3c, uint8_t value);
void I3C_PendITConfig(I3C_TypeDef *i3c, uint8_t value);
void I3C_ActStateConfig(I3C_TypeDef *i3c, uint8_t value);
void I3C_ExtDataCmd(I3C_TypeDef *i3c, FunctionalState state);
void I3C_Cmd(I3C_TypeDef *i3c, FunctionalState state);
void I3C_DMAConfig(I3C_TypeDef *i3c, uint32_t rxq, uint32_t txq, uint32_t wth);
FlagStatus I3C_GetFlagStatus(I3C_TypeDef *i3c, uint32_t flag);
I3C_ActStatus I3C_GetActStatus(I3C_TypeDef *i3c);
I3C_EvdetStatus I3C_GetEvdetStatus(I3C_TypeDef *i3c);
void I3C_ClearFlag(I3C_TypeDef *i3c, uint32_t flag);
uint32_t I3C_GetErrorFlagStatus(I3C_TypeDef *i3c);
void I3C_ITConfig(I3C_TypeDef *i3c, uint32_t it, FunctionalState state);
void I3C_ITClearConfig(I3C_TypeDef *i3c, uint32_t it);
ITStatus I3C_GetITStatus(I3C_TypeDef *i3c, uint32_t it);
void I3C_ClearITPendingBit(I3C_TypeDef *i3c, uint32_t it);
void I3C_FifoConfig(I3C_TypeDef *i3c, uint32_t txLvl, uint32_t rxLvl, bool flushTx, bool flushRx);
uint8_t I3C_GetFifoCounts(I3C_TypeDef *i3c, uint8_t fifo);
FlagStatus I3C_GetFifoFlagStatus(I3C_TypeDef *i3c, uint32_t flag);
uint8_t I3C_ReadByte(I3C_TypeDef *i3c);
uint16_t I3C_ReadHalfWord(I3C_TypeDef *i3c);
void I3C_WriteByte(I3C_TypeDef *i3c, uint8_t byte, bool end);
void I3C_WriteEndByte(I3C_TypeDef *i3c, uint8_t byte);
void I3C_WriteHalfWord(I3C_TypeDef *i3c, uint16_t halfword, bool end);
void I3C_WriteEndHalfWord(I3C_TypeDef *i3c, uint16_t halfword);
void I3C_WriteOnlyByte(I3C_TypeDef *i3c, uint8_t byte);
void I3C_FilterConfig(I3C_TypeDef *i3c, uint8_t spklen, FunctionalState state);
uint8_t I3C_GetDynamicAddr(I3C_TypeDef *i3c);
void I3C_StaticAddressConfig(I3C_TypeDef *i3c, uint8_t addr);
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
