/***********************************************************************************************************************
    @file     hal_i3c.c
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

/* Files Includes ----------------------------------------------------------------------------------------------------*/
#include "hal_i3c.h"

/** @addtogroup StdPeriph_Driver
  * @{
  */

/** @defgroup I3C
  * @brief I3C driver modules
  * @{
  */

/** @defgroup I3C_Private_TypesDefinitions
  * @{
  */

/**
  * @brief  Deinitializes the i3c peripheral registers to their default reset values.
  * @param  i3c: Select the I3C peripheral.
  * @retval None
  */
void I3C_DeInit(I3C_TypeDef *i3c)
{
    if (i3c == I3C1)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1ENR_I3C, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1ENR_I3C, DISABLE);
    }
}

/**
  * @brief  Configure the I3C slave request event.
  * @param  i3c: Select the I3C peripheral.
  * @param  event: Select I3C slave event.
  *         This parameter can be one of the following values:
  * @arg    I3C_EVENT_Normal
  * @arg    I3C_EVENT_IBI
  * @arg    I3C_EVENT_HotJoin
  * @retval None
  */
void I3C_RequestEventConfig(I3C_TypeDef *i3c, uint32_t event)
{
    MODIFY_REG(i3c->CTRL, I3C_CTRL_EVENT, event);
}

/**
  * @brief  Configure the I3C slave IBI data.
  * @param  i3c: Select the I3C peripheral.
  * @param  data: The Specified IBI data.
  * @retval None
  */
void I3C_IBIDataConfig(I3C_TypeDef *i3c, uint8_t data)
{
    MODIFY_REG(i3c->CTRL, I3C_CTRL_IBIDATA, data << I3C_CTRL_IBIDATA_Pos);
}

/**
  * @brief  Configure the return value of the Vendor
  *         reserved field of the GETSTATUS CCC command.
  * @param  i3c: Select the I3C peripheral.
  * @param  value: The Specified Vendor information.
  * @retval None
  */
void I3C_VendorInfoConfig(I3C_TypeDef *i3c, uint8_t value)
{
    MODIFY_REG(i3c->CTRL, I3C_CTRL_VENDINFO, value << I3C_CTRL_VENDINFO_Pos);
}

/**
  * @brief  Configure the return value of the Pending
  *         interrupt field of the GETSTATUS CCC command.
  * @param  i3c: Select the I3C peripheral.
  * @param  value: The Specified return value.
  * @retval None
  */
void I3C_PendITConfig(I3C_TypeDef *i3c, uint8_t value)
{
    MODIFY_REG(i3c->CTRL, I3C_CTRL_PENDINT, value << I3C_CTRL_PENDINT_Pos);
}

/**
  * @brief  Configure the Activity state of the device as the
  *         activity Mode field of the GETSTATUS CCC command return value.
  * @param  i3c: Select the I3C peripheral.
  * @param  value: The Specified Activity state.
  * @retval None
  */
void I3C_ActStateConfig(I3C_TypeDef *i3c, uint8_t value)
{
    MODIFY_REG(i3c->CTRL, I3C_CTRL_ACTSTATE, value << I3C_CTRL_ACTSTATE_Pos);
}

/**
  * @brief  Enables or disables continue sending extended data
  *         from the TX FIFO after IBI sends IBIDATA.
  * @param  adc: select the ADC peripheral.
  * @param  state: new state of the sending extended data.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I3C_ExtDataCmd(I3C_TypeDef *i3c, FunctionalState state)
{
    (state) ?                                        \
    (i3c->CTRL |= (0x01U << I3C_CTRL_EXTDATA_Pos)) : \
    (i3c->CTRL &= ~(0x01U << I3C_CTRL_EXTDATA_Pos));
}

/**
  * @brief  Enables or disables the specified I3C peripheral.
  * @param  i3c: Select the I3C peripheral.
  * @param  state: new state of the i3c peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I3C_Cmd(I3C_TypeDef *i3c, FunctionalState state)
{
    (state) ?                                           \
    (i3c->CONFIG |= (0x01U << I3C_CONFIG_SLVENA_Pos)) : \
    (i3c->CONFIG &= ~(0x01U << I3C_CONFIG_SLVENA_Pos));
}

/**
  * @brief  Configure the specified I3C DMA transfers mode.
  * @param  i3c: Select the I3C peripheral.
  * @param  rxq: Select DMA read Enable configuration mode.
  *         This parameter can be one of the following values:
  * @arg    I3C_DMARX_Disable
  * @arg    I3C_DMARX_OneFrameEnable
  * @arg    I3C_DMARX_ContinueEnable
  * @param  txq: Select DMA write Enable configuration mode.
  *         This parameter can be one of the following values:
  * @arg    I3C_DMATX_Disable
  * @arg    I3C_DMATX_OneFrameEnable
  * @arg    I3C_DMATX_ContinueEnable
  * @param  wth: Select DMA transfers data bit width.
  *         This parameter can be one of the following values:
  * @arg    I3C_DMAWTH_Byte
  * @arg    I3C_DMAWTH_HalfWord
  * @retval None
  */
void I3C_DMAConfig(I3C_TypeDef *i3c, uint32_t rxq, uint32_t txq, uint32_t wth)
{
    MODIFY_REG(i3c->DMACTRL, (I3C_DMACTRL_DMAFB | I3C_DMACTRL_DMATB | I3C_DMACTRL_DMAWIDTH), (rxq | txq | wth));
}

/**
  * @brief  Checks whether the specified I3C flag is set or not.
  * @param  i3c: select the I3C peripheral.
  * @param  flag: specifies the flag to check.
  * @arg    I3C_FLAG_STNOTSTOP
  * @arg    I3C_FLAG_STMSG
  * @arg    I3C_FLAG_STCCCH
  * @arg    I3C_FLAG_STREQRD
  * @arg    I3C_FLAG_STREQWR
  * @arg    I3C_FLAG_STDAA
  * @arg    I3C_FLAG_STHDR
  * @arg    I3C_FLAG_START
  * @arg    I3C_FLAG_MATCHED
  * @arg    I3C_FLAG_STOP
  * @arg    I3C_FLAG_RXPEND
  * @arg    I3C_FLAG_TXNOTFULL
  * @arg    I3C_FLAG_DACHG
  * @arg    I3C_FLAG_CCC
  * @arg    I3C_FLAG_ERWAR
  * @arg    I3C_FLAG_CHANDLED
  * @arg    I3C_FLAG_EVENT
  * @arg    I3C_FLAG_IBIDIS
  * @arg    I3C_FLAG_MRDIS
  * @arg    I3C_FLAG_HJDIS
  * @retval The New state of flag (SET or RESET).
  */
FlagStatus I3C_GetFlagStatus(I3C_TypeDef *i3c, uint32_t flag)
{
    return ((i3c->STATUS & flag) ? SET : RESET);
}

/**
  * @brief  Checks the specified I3C activity status.
  * @param  i3c: select the I3C peripheral.
  * @retval The New state of activity status.
  */
I3C_ActStatus I3C_GetActStatus(I3C_TypeDef *i3c)
{
    return ((I3C_ActStatus)((i3c->STATUS & I3C_STATUS_ACTSTATE) >> I3C_STATUS_ACTSTATE_Pos));
}

/**
  * @brief  Checks the current status of the pending event.
  * @param  i3c: select the I3C peripheral.
  * @retval The New state of the pending event.
  */
I3C_EvdetStatus I3C_GetEvdetStatus(I3C_TypeDef *i3c)
{
    return ((I3C_EvdetStatus)((i3c->STATUS & I3C_STATUS_EVDET) >> I3C_STATUS_EVDET_Pos));
}

/**
  * @brief  Clears the I3C pending flags.
  * @param  i3c: select the I3C peripheral.
  * @param  flag: specifies the flag to clear.
  * @arg    I3C_FLAG_START
  * @arg    I3C_FLAG_MATCHED
  * @arg    I3C_FLAG_STOP
  * @arg    I3C_FLAG_DACHG
  * @arg    I3C_FLAG_CCC
  * @arg    I3C_FLAG_CHANDLED
  * @arg    I3C_FLAG_EVENT
  * @retval None.
  */
void I3C_ClearFlag(I3C_TypeDef *i3c, uint32_t flag)
{
    i3c->STATUS = flag;
}

/**
  * @brief  Gets the I3C slave error status flags.
  * @param  i3c: select the I3C peripheral.
  * @retval The New error status flags.
  */
uint32_t I3C_GetErrorFlagStatus(I3C_TypeDef *i3c)
{
    return (i3c->ERRWARN);
}

/**
  * @brief  Enables or disables the specified I3C interrupts.
  * @param  i3c: select the I3C peripheral.
  * @param  it: specifies the I3C interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    I3C_IT_START     
  * @arg    I3C_IT_MATCHED   
  * @arg    I3C_IT_STOP      
  * @arg    I3C_IT_RXPEND    
  * @arg    I3C_IT_TXSEND    
  * @arg    I3C_IT_DACHG     
  * @arg    I3C_IT_CCC       
  * @arg    I3C_IT_ERRWARN   
  * @arg    I3C_IT_CHANDLED  
  * @arg    I3C_IT_EVENT     
  * @param  state: New state of the specified I3C interrupts.
  * @retval None.
  */
void I3C_ITConfig(I3C_TypeDef *i3c, uint32_t it, FunctionalState state)
{
    (state) ?             \
    (i3c->INTSET |= it) : \
    (i3c->INTSET &= ~it);
}

/**
  * @brief  Disable the specific I3C interrupt sources.
  * @param  i3c: select the I3C peripheral.
  * @param  it: specifies the I3C interrupt sources.
  *         This parameter can be one of the following values:
  * @arg    I3C_IT_START     
  * @arg    I3C_IT_MATCHED   
  * @arg    I3C_IT_STOP      
  * @arg    I3C_IT_RXPEND    
  * @arg    I3C_IT_TXSEND    
  * @arg    I3C_IT_DACHG     
  * @arg    I3C_IT_CCC       
  * @arg    I3C_IT_ERRWARN   
  * @arg    I3C_IT_CHANDLED  
  * @arg    I3C_IT_EVENT     
  * @param  state: New state of the specified I3C interrupts.
  * @retval None.
  */
void I3C_ITClearConfig(I3C_TypeDef *i3c, uint32_t it)
{
    i3c->INTCLR = it;
}

/**
  * @brief  Checks whether the specified adc's interrupt has occurred or not.
  * @param  i3c: select the I3C peripheral.
  * @param  it: specifies the I3C interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    I3C_IT_START     
  * @arg    I3C_IT_MATCHED   
  * @arg    I3C_IT_STOP      
  * @arg    I3C_IT_RXPEND    
  * @arg    I3C_IT_TXSEND    
  * @arg    I3C_IT_DACHG     
  * @arg    I3C_IT_CCC       
  * @arg    I3C_IT_ERRWARN   
  * @arg    I3C_IT_CHANDLED  
  * @arg    I3C_IT_EVENT     
  * @retval The new state of the specified I3C interrupts(SET or RESET).
  */
ITStatus I3C_GetITStatus(I3C_TypeDef *i3c, uint32_t it)
{
    return ((i3c->INTMSK & it) ? SET : RESET);
}

/**
  * @brief  Clears the I3C interrupt pending bits.
  * @param  i3c: select the I3C peripheral.
  * @param  it: specifies the I3C interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    I3C_IT_START     
  * @arg    I3C_IT_MATCHED   
  * @arg    I3C_IT_STOP      
  * @arg    I3C_IT_RXPEND    
  * @arg    I3C_IT_TXSEND    
  * @arg    I3C_IT_DACHG     
  * @arg    I3C_IT_CCC       
  * @arg    I3C_IT_ERRWARN   
  * @arg    I3C_IT_CHANDLED  
  * @arg    I3C_IT_EVENT     
  * @retval None.
  */
void I3C_ClearITPendingBit(I3C_TypeDef *i3c, uint32_t it)
{
    i3c->INTMSK = it;
}

/**
  * @brief  Configure the specified I3C RX FIFO and TX FIFO.
  * @param  i3c: Select the I3C peripheral.
  * @param  txLvl: Select TX FIFO trigger level.
  *         This parameter can be one of the following values:
  * @arg    I3C_TXFIFO_TRIG_Level0
  * @arg    I3C_TXFIFO_TRIG_Level1
  * @arg    I3C_TXFIFO_TRIG_Level2
  * @arg    I3C_TXFIFO_TRIG_Level3
  * @param  rxLvl: Select RX FIFO trigger level.
  *         This parameter can be one of the following values:
  * @arg    I3C_RXFIFO_TRIG_Level0
  * @arg    I3C_RXFIFO_TRIG_Level1
  * @arg    I3C_RXFIFO_TRIG_Level2
  * @arg    I3C_RXFIFO_TRIG_Level3
  * @param  flushTx: Whether to refresh TX FIFO, select true or false.
  * @param  flushRx: Whether to refresh RX FIFO, select true or false.
  * @retval None
  */
void I3C_FifoConfig(I3C_TypeDef *i3c, uint32_t txLvl, uint32_t rxLvl, bool flushTx, bool flushRx)
{
    i3c->DATACTRL &= ~(0x01U << I3C_DATACTRL_UNLOCK_Pos);
    MODIFY_REG(i3c->DATACTRL, (I3C_DATACTRL_FLUSHTB | I3C_DATACTRL_FLUSHFB | I3C_DATACTRL_TXTRIG | I3C_DATACTRL_RXTRIG),
               ((flushTx ? (0x01U << I3C_DATACTRL_FLUSHTB_Pos) : (0x00U << I3C_DATACTRL_FLUSHTB_Pos)) | \
                (flushRx ? (
                     0x01U
    << I3C_DATACTRL_FLUSHFB_Pos) : (0x00U << I3C_DATACTRL_FLUSHFB_Pos)) | \
                txLvl |
                rxLvl));
}

/**
  * @brief  Gets the current number of bytes in the I3C slave FIFO.
  * @param  i3c: Select the I3C peripheral.
  * @param  fifo: Select the specified FIFO.
  *         This parameter can be one of the following values:
  * @arg    I3C_TXFIFO
  * @arg    I3C_RXFIFO
  * @retval Value: The current number of bytes in the FIFO.
  */
uint8_t I3C_GetFifoCounts(I3C_TypeDef *i3c, uint8_t fifo)
{
    if (fifo == I3C_TXFIFO)
    {
        return ((uint8_t)((i3c->DATACTRL & I3C_DATACTRL_TXCOUNT) >> I3C_DATACTRL_TXCOUNT_Pos));
    }
    else
    {
        return ((uint8_t)((i3c->DATACTRL & I3C_DATACTRL_RXCOUNT) >> I3C_DATACTRL_RXCOUNT_Pos));
    }
}

/**
  * @brief  Checks whether the specified FIFO flag is set or not.
  * @param  i3c: Select the I3C peripheral.
  * @param  flag: specifies the flag to check.
  * @arg    I3C_TXFIFO_Full
  * @arg    I3C_RXFIFO_Empty
  * @retval The New state of flag (SET or RESET).
  */
FlagStatus I3C_GetFifoFlagStatus(I3C_TypeDef *i3c, uint32_t flag)
{
    return ((i3c->DATACTRL & flag) ? SET : RESET);
}

/**
  * @brief  Read byte register.
  * @param  i3c: Select the I3C peripheral.
  * @retval data: The content of the read byte register.
  */
uint8_t I3C_ReadByte(I3C_TypeDef *i3c)
{
    uint8_t byte;

    if (I3C_GetFlagStatus(i3c, I3C_FLAG_RXPEND))
    {
        byte = (uint8_t)(i3c->RDATAB & I3C_RDATAB_DATA0);
    }

    return (byte);
}

/**
  * @brief  Read half word register.
  * @param  i3c: Select the I3C peripheral.
  * @retval data: The content of the read half word register.
  */
uint16_t I3C_ReadHalfWord(I3C_TypeDef *i3c)
{
    uint16_t halfword;

    if (I3C_GetFifoCounts(i3c, I3C_RXFIFO) >= 0x02)
    {
        halfword = (uint16_t)(i3c->RDATAH & (I3C_RDATAH_MSB | I3C_RDATAH_LSB));
    }

    return (halfword);
}

/**
  * @brief  Write byte data register.
  * @param  byte: Specifies the byte data.
  * @param  end:  Whether more bytes are waiting to be sent, true or false.
  * @retval None.
  */
void I3C_WriteByte(I3C_TypeDef *i3c, uint8_t byte, bool end)
{
    if (I3C_GetFlagStatus(i3c, I3C_FLAG_TXNOTFULL))
    {
        i3c->WDATAB = (uint32_t)((end << I3C_WDATAB_END_Pos) | byte);
    }
}

/**
  * @brief  Write the end byte data register.
  * @param  byte: Specifies the byte data.
  * @retval None.
  */
void I3C_WriteEndByte(I3C_TypeDef *i3c, uint8_t byte)
{
    if (I3C_GetFlagStatus(i3c, I3C_FLAG_TXNOTFULL))
    {
        i3c->WDATABE = (uint32_t)byte;
    }
}

/**
  * @brief  Write half word register.
  * @param  halfword: Specifies the byte data.
  * @param  end:  Whether more bytes are waiting to be sent, true or false.
  * @retval None.
  */
void I3C_WriteHalfWord(I3C_TypeDef *i3c, uint16_t halfword, bool end)
{
    if ((8 - I3C_GetFifoCounts(i3c, I3C_TXFIFO)) >= 0x02)
    {
        i3c->WDATAH = (uint32_t)((end << I3C_WDATAH_END_Pos) | halfword);
    }
}

/**
  * @brief  Write the end half word register.
  * @param  halfword: Specifies the byte data.
  * @retval None.
  */
void I3C_WriteEndHalfWord(I3C_TypeDef *i3c, uint16_t halfword)
{
    if ((8 - I3C_GetFifoCounts(i3c, I3C_TXFIFO)) >= 0x02)
    {
        i3c->WDATAHE = (uint32_t)halfword;
    }
}

/**
  * @brief  Only write the byte data register,
  *         It is used only by DMA using the APB bit [7:0].
  * @param  byte: Specifies the byte data.
  * @retval None.
  */
void I3C_WriteOnlyByte(I3C_TypeDef *i3c, uint8_t byte)
{
    if (I3C_GetFlagStatus(i3c, I3C_FLAG_TXNOTFULL))
    {
        i3c->WDATAB1 = (uint32_t)byte;
    }
}

/**
  * @brief  Configure the specified I3C filter.
  * @param  i3c: Select the I3C peripheral.
  * @param  spklen: Select the number of valid samples.
  *         This parameter value ranges from 0 to 255.
  * @param  state: new state of the I3C peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void I3C_FilterConfig(I3C_TypeDef *i3c, uint8_t spklen, FunctionalState state)
{
    MODIFY_REG(i3c->SPKLEN, I3C_SPKLEN_SPKLEN, spklen << I3C_SPKLEN_SPKLEN_Pos);

    (state) ?                                           \
    (i3c->SPKLEN |= (0x01U << I3C_SPKLEN_FLT_EN_Pos)) : \
    (i3c->SPKLEN &= ~(0x01U << I3C_SPKLEN_FLT_EN_Pos));
}

/**
  * @brief  Gets the dynamic address assigned to the I3C slave device.
  * @param  i3c: Select the I3C peripheral.
  * @retval Value: The dynamic address.
  */
uint8_t I3C_GetDynamicAddr(I3C_TypeDef *i3c)
{
    i3c->DYNADDR |= (0x01U << I3C_DYNADDR_DAVALID_Pos);
    return ((uint8_t)((i3c->DYNADDR & I3C_DYNADDR_DADDR) >> I3C_DYNADDR_DADDR_Pos));
}

/**
  * @brief  Configures the specified I3C Static Address.
  * @param  i3c: Select the I3C peripheral.
  * @param  addr: specifies the 7bit I3C Static Address.
  * @retval None.
  */
void I3C_StaticAddressConfig(I3C_TypeDef *i3c, uint8_t addr)
{
    MODIFY_REG(i3c->CONFIG, I3C_CONFIG_SADDR, (addr >> 1) << I3C_CONFIG_SADDR_Pos);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

