/*
 *******************************************************************************
    @file     hal_i2c.c
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
#define _HAL_I2C_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_i2c.h"


/*I2c Enable disable*/
#define IC_ENABLE_Reset         ((uint16_t)0xFFFE)
#define IC_ENABLE_Set           ((uint16_t)0x0001)
#define IC_CON_RESET			((uint16_t)0xFE8A)
#define INTR_MASK               ((uint16_t)0xC000)

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup I2C_HAL
  * @{
  */

/** @addtogroup I2C_Exported_Functions
  * @{
  */

/**
  * @brief  Deinitializes the i2c peripheral registers to their default
  *         reset values.
  * @param  i2c: where n can be 1 or 2 to select the I2C peripheral.
  * @retval None.
  */
void I2C_DeInit(I2C_TypeDef* i2c)
{
    switch (*(uint32_t*)&i2c)
    {
    case I2C1_BASE:
        /* Enable I2C1 reset state */
        RCC_APB1PeriphResetCmd(RCC_APB1ENR_I2C1, ENABLE);
        /* Release I2C1 from reset state */
        RCC_APB1PeriphResetCmd(RCC_APB1ENR_I2C1, DISABLE);
        break;

    default:
        break;
    }
}

/**
  * @brief  Initializes the i2c peripheral according to the specified
  *         parameters in the init_struct.
  * @param  i2c: select the I2C peripheral.
  * @param  init_struct: pointer to a I2C_InitTypeDef structure that
  *         contains the configuration information for the specified
  *         I2C peripheral.
  * @retval None.
  */
void I2C_Init(I2C_TypeDef* i2c, I2C_InitTypeDef* init_struct)
{
    uint16_t tmpreg = 0;
    uint32_t pclk1 = 8000000;
    /* uint32_t minSclLowTime = 0; */
    uint32_t i2cPeriod = 0;
    uint32_t pclk1Period = 0;
    RCC_ClocksTypeDef  rcc_clocks;

    /*---------------------------- i2c ENR Configuration ------------------------*/
    /* Disable the selected I2C peripheral */
    i2c->ENR &= IC_ENABLE_Reset;

    /* Get pclk1 frequency value */
    RCC_GetClocksFreq(&rcc_clocks);
    pclk1 = rcc_clocks.PCLK1_Frequency;

    /* Set pclk1 period value */
    pclk1Period = 1000000000/pclk1;

    i2cPeriod = 1000000000/init_struct->I2C_ClockSpeed; /* ns unit */
    tmpreg = 0;
    /* Configure speed in standard mode */
    if (init_struct->I2C_ClockSpeed <= 100000)
    {
        /* Standard mode speed calculate */
        /* minSclLowTime = 4700;  */ /* ns unit */
        /* tmpreg = minSclLowTime/pclk1Period; */
        /* Write to i2c SSLR */
        /* i2c->SSLR = tmpreg; */
        /* tmpreg = (i2cPeriod - pclk1Period*i2c->SSLR)/pclk1Period; */
        /* Write to i2c SSHR */
        /* i2c->SSHR = tmpreg; */
        /* tmpreg = (i2cPeriod/pclk1Period)*0.5; */
        tmpreg = (i2cPeriod/pclk1Period)/2;
        i2c->SSLR = tmpreg;
        tmpreg = (i2cPeriod - pclk1Period*i2c->SSLR)/pclk1Period;
        /* Write to i2c SSHR */
        i2c->SSHR = tmpreg;


    }
    else /*(init_struct->I2C_ClockSpeed <= 400000)*/
    {
        /* Configure speed in fast mode */
        /* minSclLowTime = 1300; */ /* ns unit */
        /* tmpreg = minSclLowTime/pclk1Period; */
        /* Write to i2c FSLR */
        /* i2c->FSLR = tmpreg; */
        /* tmpreg = (i2cPeriod - pclk1Period*i2c->FSLR)/pclk1Period; */
        /* Write to i2c FSHR */
        /* i2c->FSHR = tmpreg; */
        /* tmpreg = (i2cPeriod/pclk1Period)*0.5; */
        tmpreg = (i2cPeriod/pclk1Period)/2;
        i2c->FSLR = tmpreg;
        tmpreg = (i2cPeriod - pclk1Period*i2c->FSLR)/pclk1Period;
        /* Write to i2c FSHR */
        i2c->FSHR = tmpreg;
    }

        i2c->FSLR = 0x2C;/* test OK: master: 263k 48M(HSI) SDA,SCL 5.1Kpull up slave: i2c->FSLR = 0x15; i2c->FSHR = 0x08; ->188k 8M(HSI) */
        i2c->FSHR = 0x1E;

/*        i2c->FSLR = 0x3F; */ /* 200k 48M SCL 1K pull up /188K 48M SCL 5.11K pull up */
/*        i2c->FSHR = 0x30;	*/

/*        i2c->FSLR = 0x26; */ /* 307k 48M SCL 1K pull up */
/*        i2c->FSHR = 0x1C; */

/*        i2c->FSLR = 0x15; */ /* 576k 48M */
/*        i2c->FSHR = 0x08; */

/*        i2c->FSLR = 0x15; */  /* 188k 8M */
/*        i2c->FSHR = 0x08; */

/*        i2c->FSLR = 0x20; */  /* 133k 8M */
/*        i2c->FSHR = 0x10; */

/*        i2c->FSLR = 0x2a; */ /* 105k 8M */
/*        i2c->FSHR = 0x16; */

    /*Get the i2c CR value */
    tmpreg = i2c->CR;
    /*Clear TX_EMPTY_CTRL,IC_SLAVE_DISABLE,IC_RESTART_EN,IC_10BITADDR_SLAVE,SPEED,MASTER_MODE bits*/
    tmpreg &= IC_CON_RESET;
		if(init_struct->I2C_Mode == I2C_Mode_SLAVE)
		{
			tmpreg = TX_EMPTY_CTRL | IC_RESTART_EN |IC_7BITADDR_MASTER | init_struct->I2C_Speed | init_struct->I2C_Mode;
		}
		else
		{
		 /*Set TX_EMPTY_CTRL,IC_SLAVE_DISABLE,IC_RESTART_EN,IC_10BITADDR_SLAVE,SPEED,MASTER_MODE bits*/
    tmpreg = TX_EMPTY_CTRL | IC_SLAVE_DISABLE | IC_RESTART_EN |IC_7BITADDR_MASTER | init_struct->I2C_Speed | init_struct->I2C_Mode;
		}
   /* Write to i2c CR */
    i2c->CR= tmpreg;

    /*---------------------------- i2c IMR Configuration ------------------------*/
    /* Get the i2c IMR value */
    tmpreg = i2c->IMR;
    /* clear the i2c IMR value */
    tmpreg &= INTR_MASK;
    /* Write to IMR */
    i2c->IMR = tmpreg;

    /* Write to RXTLR  */
    i2c->RXTLR = 0x0; /* rxfifo depth is 1 */
    /* Write to TXTLR  */
    i2c->TXTLR = 0x1; /* tcfifo depth is 1 */
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to an I2C_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void I2C_StructInit(I2C_InitTypeDef* init_struct)
{
    init_struct->I2C_Mode       = I2C_CR_MASTER;
    init_struct->I2C_OwnAddress = I2C_OWN_ADDRESS;
    init_struct->I2C_Speed      = I2C_CR_SPEED_STD;
    init_struct->I2C_ClockSpeed = 100000;
}

/**
  * @brief  Enables or disables the specified I2C peripheral.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the i2c peripheral. This parameter
  *         can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_Cmd(I2C_TypeDef* i2c, FunctionalState state)
{
    (state) ? (i2c->ENR |= I2C_ENR_ENABLE) : (i2c->ENR &= ~I2C_ENR_ENABLE);
}

/**
  * @brief  Enables or disables the specified I2C DMA requests.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C DMA transfer.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_DMACmd(I2C_TypeDef* i2c, FunctionalState state)
{
    if (state) {
        if (I2C_DMA_DIR == TDMAE_SET)
            i2c->DMA |= TDMAE_SET;

        else
            i2c->DMA |= RDMAE_SET;
    }
    else
        i2c->DMA &= ~(I2C_DMA_RXEN | I2C_DMA_TXEN);
}

/**
  * @brief  Generates i2c communication START condition.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C START condition generation.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GenerateSTART(I2C_TypeDef* i2c, FunctionalState state)
{
    (state) ? (i2c->CR |= I2C_CR_REPEN) : (i2c->CR &= ~I2C_CR_REPEN);
}

/**
  * @brief  Generates i2c communication STOP condition.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C STOP condition generation.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GenerateSTOP(I2C_TypeDef* i2c, FunctionalState state)
{
    uint16_t overTime = 6000;

    i2c->ENR |= I2C_ENR_ABORT;

    while (i2c->ENR & I2C_ENR_ABORT) {
        if (overTime-- == 0)
            break;
    }
    i2c->TX_ABRT;
}

/**
  * @brief  Configures the specified I2C own address2.
  * @param  i2c: select the I2C peripheral.
  * @param  addr: specifies the 7bit I2C own address2.
  * @retval None.
  */
void I2C_OwnAddress2Config(I2C_TypeDef* i2c, uint8_t addr)
{
    MODIFY_REG(i2c->TAR, (uint16_t)I2C_TAR_ADDR, (uint16_t)(addr >> 1));
}

/**
  * @brief  Enables or disables the specified I2C dual addressing mode.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C dual addressing mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_DualAddressCmd(I2C_TypeDef* i2c, FunctionalState state)
{
    (state) ? (i2c->TAR |= IC_TAR_ENDUAL_Set) : (i2c->TAR &= IC_TAR_ENDUAL_Reset);
}

/**
  * @brief  Enables or disables the specified I2C general call feature.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C General call.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GeneralCallCmd(I2C_TypeDef* i2c, FunctionalState state)
{
    (state) ? (i2c->TAR |= I2C_TAR_SPECIAL) : (i2c->TAR &= ~I2C_TAR_SPECIAL);
}

/**
  * @brief  Enables or disables the specified I2C interrupts.
  * @param  i2c: select the I2C peripheral.
  * @param  it: specifies the I2C interrupts sources to be enabled
  *         or disabled.
  *         This parameter can be any combination of the following values:
  * @arg    I2C_IT_RX_UNDER   : Rx Buffer is empty interrupt mask
  * @arg    I2C_IT_RX_OVER    : RX  Buffer Overrun interrupt mask
  * @arg    I2C_IT_RX_FULL    : Rx buffer full interrupt mask
  * @arg    I2C_IT_TX_OVER    : TX  Buffer Overrun interrupt mask
  * @arg    I2C_IT_TX_EMPTY   : TX_FIFO empty interrupt mask
  * @arg    I2C_IT_RD_REQ     : I2C work as slave or master interrupt mask
  * @arg    I2C_IT_TX_ABRT    : TX error interrupt  mask(Master mode)
  * @arg    I2C_IT_RX_DONE    : Master not ack interrupt mask(slave mode)
  * @arg    I2C_IT_ACTIVITY   : I2C activity interrupt mask
  * @arg    I2C_IT_STOP_DET   : stop condition  interrupt mask
  * @arg    I2C_IT_START_DET  : start condition  interrupt mask
  * @arg    I2C_IT_GEN_CALL   : a general call address and ack interrupt mask
  * @param  state: new state of the specified I2C interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_ITConfig(I2C_TypeDef* i2c, uint16_t it, FunctionalState state)
{
    if (it == I2C_IT_RX_FULL)
        I2C_ReadCmd(i2c);
    (state) ? SET_BIT(i2c->IMR, it) : CLEAR_BIT(i2c->IMR, (uint16_t)it);
}

/**
  * @brief  Sends a data byte through the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @param  dat: Byte to be transmitted..
  * @retval None.
  */
void I2C_SendData(I2C_TypeDef* i2c, uint8_t dat)
{
    i2c->DR = dat;
}

/**
  * @brief  Returns the most recent received data by the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @retval The value of the received data.
  */
void I2C_ReadCmd(I2C_TypeDef* i2c)
{
    i2c->DR = I2C_DR_CMD;
}

/**
  * @brief  Returns the most recent received data by the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @retval The value of the received data.
  */
uint8_t I2C_ReceiveData(I2C_TypeDef* i2c)
{
    I2C_CMD_DIR = 0;
    return (uint8_t)i2c->DR;
}

/**
  * @brief  Transmits the address byte to select the slave device.
  * @param  i2c: select the I2C peripheral.
  * @param  addr: specifies the slave address which will be transmitted
  * @param  dir: specifies whether the I2C device will be a
  *   Transmitter or a Receiver.
  *   This parameter can be one of the following values
  * @arg  I2C_Direction_Transmitter: Transmitter mode
  * @arg  I2C_Direction_Receiver: Receiver mode
  * @retval None.
  */
void I2C_Send7bitAddress(I2C_TypeDef* i2c, uint8_t addr)
{
    i2c->TAR = addr >> 1;
}

/**
  * @brief  Reads the specified I2C register and returns its value.
  * @param  i2c: select the I2C peripheral.
  * @param  reg: specifies the register to read.
  *         This parameter can be one of the following values:
  * @retval The value of the read register.
  */
uint16_t I2C_ReadRegister(I2C_TypeDef* i2c, uint8_t reg)
{
    return (*(__IO uint16_t*)(*((uint32_t*)&i2c) + reg));
}

/**
  * @brief  Returns the last i2c Event.
  * @param  i2c: select the I2C peripheral.
  * @retval The last event
  */
uint32_t I2C_GetLastEvent(I2C_TypeDef* i2c)
{
    return (uint32_t)i2c->RAWISR & FLAG_Mask;
}

/**
  * @brief  Checks whether the last i2c Event is equal to the one passed
  *   as parameter.
  * @param  i2c: select the I2C peripheral.
  * @param  event: specifies the event to be checked.
  *   This parameter can be one of the following values:
  * @arg  I2C_EVENT_RX_UNDER : Rx Buffer is empty event
  * @arg  I2C_EVENT_RX_OVER  : RX  Buffer Overrun event
  * @arg  I2C_EVENTT_RX_FULL : Rx buffer full event
  * @arg  I2C_EVENT_TX_OVER  : TX  Buffer Overrun event
  * @arg  I2C_EVENT_TX_EMPTY : TX_FIFO empty event
  * @arg  I2C_EVENT_RD_REQ   : I2C work as slave or master event
  * @arg  I2C_EVENT_TX_ABRT  : TX error event(Master mode)
  * @arg  I2C_EVENT_RX_DONE  : Master not ack event(slave mode)
  * @arg  I2C_EVENT_ACTIVITY : I2C activity event
  * @arg  I2C_EVENT_STOP_DET : stop condition  event
  * @arg  I2C_EVENT_START_DET: start condition  event
  * @arg  I2C_EVENT_GEN_CALL : a general call address and ack event
  * - SUCCESS: Last event is equal to the I2C_EVENT
  * - ERROR: Last event is different from the I2C_EVENT
  */
ErrorStatus I2C_CheckEvent(I2C_TypeDef* i2c, uint32_t event)
{
    if ((event == I2C_EVENT_RX_FULL) && (I2C_CMD_DIR == 0)) {
        i2c->DR = I2C_DR_CMD;
        I2C_CMD_DIR       = 1;
    }

    return (ErrorStatus)((i2c->RAWISR & event) == event);
}

/**
  * @brief  Checks whether the specified I2C flag is set or not.
  * @param  i2c: select the I2C peripheral.
  * @param  flag: specifies the flag to check.
  *   This parameter can be one of the following values:
  * @arg  I2C_FLAG_RX_UNDER : Rx Buffer is empty flag
  * @arg  I2C_FLAG_RX_OVER  : RX  Buffer Overrun flag
  * @arg  I2C_FLAG_RX_FULL  : Rx buffer full flag
  * @arg  I2C_FLAG_TX_OVER  : TX  Buffer Overrun flag
  * @arg  I2C_FLAG_TX_EMPTY : TX_FIFO empty flag
  * @arg  I2C_FLAG_RD_REQ   : I2C work as slave or master flag
  * @arg  I2C_FLAG_TX_ABRT  : TX error flag(Master mode)
  * @arg  I2C_FLAG_RX_DONE  : Master not ack flag(slave mode)
  * @arg  I2C_FLAG_ACTIVITY : I2C activity flag
  * @arg  I2C_FLAG_STOP_DET : stop condition  flag
  * @arg  I2C_FLAG_START_DET: start condition  flag
  * @arg  I2C_FLAG_GEN_CALL : a general call address and ack flag
  * @retval The new state of I2C_FLAG (SET or RESET).
  */
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* i2c, uint32_t flag)
{
    if (flag & 0x8000)
        return ((i2c->SR & flag) ? SET : RESET);

    return (((i2c->RAWISR & flag)) ? SET : RESET);
}

/**
  * @brief  Clears the i2c's pending flags.
  * @param  i2c: select the I2C peripheral.
  * @param  flag: specifies the flag to clear.
  *   This parameter can be any combination of the following values:
  * @arg  I2C_FLAG_RX_UNDER : Rx Buffer is empty flag
  * @arg  I2C_FLAG_RX_OVER  : RX  Buffer Overrun flag
  * @arg  I2C_FLAG_RX_FULL  : Rx buffer full flag
  * @arg  I2C_FLAG_TX_OVER  : TX  Buffer Overrun flag
  * @arg  I2C_FLAG_TX_EMPTY : TX_FIFO empty flag
  * @arg  I2C_FLAG_RD_REQ   : I2C work as slave or master flag
  * @arg  I2C_FLAG_TX_ABRT  : TX error flag(Master mode)
  * @arg  I2C_FLAG_RX_DONE  : Master not ack flag(slave mode)
  * @arg  I2C_FLAG_ACTIVITY : I2C activity flag
  * @arg  I2C_FLAG_STOP_DET : stop condition  flag
  * @arg  I2C_FLAG_START_DET: start condition  flag
  * @arg  I2C_FLAG_GEN_CALL : a general call address and ack flag
  * @retval None.
  */
void I2C_ClearFlag(I2C_TypeDef* i2c, uint32_t flag)
{
    __IO uint32_t temp = 0;

    temp = temp;
    if ((flag & I2C_FLAG_RX_UNDER) == I2C_FLAG_RX_UNDER)
        temp = i2c->RX_UNDER;
    if ((flag & I2C_FLAG_RX_OVER) == I2C_FLAG_RX_OVER)
        temp = i2c->RX_OVER;
    if ((flag & I2C_FLAG_TX_OVER) == I2C_FLAG_TX_OVER)
        temp = i2c->TX_OVER;
    if ((flag & I2C_FLAG_RD_REQ) == I2C_FLAG_RD_REQ)
        temp = i2c->RD_REQ;
    if ((flag & I2C_FLAG_TX_ABRT) == I2C_FLAG_TX_ABRT)
        temp = i2c->TX_ABRT;
    if ((flag & I2C_FLAG_RX_DONE) == I2C_FLAG_RX_DONE)
        temp = i2c->RX_DONE;
    if ((flag & I2C_FLAG_ACTIVITY) == I2C_FLAG_ACTIVITY)
        temp = i2c->ACTIV;
    if ((flag & I2C_FLAG_STOP_DET) == I2C_FLAG_STOP_DET)
        temp = i2c->STOP;
    if ((flag & I2C_FLAG_START_DET) == I2C_FLAG_START_DET)
        temp = i2c->START;
    if ((flag & I2C_FLAG_GEN_CALL) == I2C_FLAG_GEN_CALL)
        temp = i2c->GC;
}

/**
  * @brief  Checks whether the specified I2C interrupt has occurred or not.
  * @param  i2c: select the I2C peripheral.
  * @param  it: specifies the interrupt source to check.
  *   This parameter can be one of the following values:
  * @arg  I2C_IT_RX_UNDER : Rx Buffer is empty interrupt
  * @arg  I2C_IT_RX_OVER  : RX  Buffer Overrun interrupt
  * @arg  I2C_IT_RX_FULL  : Rx buffer full interrupt
  * @arg  I2C_IT_TX_OVER  : TX  Buffer Overrun interrupt
  * @arg  I2C_IT_TX_EMPTY : TX_FIFO empty interrupt
  * @arg  I2C_IT_RD_REQ   : I2C work as slave or master interrupt
  * @arg  I2C_IT_TX_ABRT  : TX error interrupt  (Master mode)
  * @arg  I2C_IT_RX_DONE  : Master not ack interrupt (slave mode)
  * @arg  I2C_IT_ACTIVITY : I2C activity interrupt
  * @arg  I2C_IT_STOP_DET : stop condition  interrupt
  * @arg  I2C_IT_START_DET: start condition  interrupt
  * @arg  I2C_IT_GEN_CALL : a general call address and ack interrupt
  * @retval The new state of I2C_IT (SET or RESET).
  */
ITStatus I2C_GetITStatus(I2C_TypeDef* i2c, uint32_t it)
{
    return ((i2c->RAWISR & it) ? SET : RESET);
}

/**
  * @brief  Clears the i2c interrupt pending bits.
  * @param  i2c: select the I2C peripheral.
  * @param  it: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  * @arg  I2C_IT_RX_UNDER : Rx Buffer is empty interrupt
  * @arg  I2C_IT_RX_OVER  : RX  Buffer Overrun interrupt
  * @arg  I2C_IT_RX_FULL  : Rx buffer full interrupt
  * @arg  I2C_IT_TX_OVER  : TX  Buffer Overrun interrupt
  * @arg  I2C_IT_TX_EMPTY : TX_FIFO empty interrupt
  * @arg  I2C_IT_RD_REQ   : I2C work as slave or master interrupt
  * @arg  I2C_IT_TX_ABRT  : TX error interrupt  (Master mode)
  * @arg  I2C_IT_RX_DONE  : Master not ack interrupt (slave mode)
  * @arg  I2C_IT_ACTIVITY : I2C activity interrupt
  * @arg  I2C_IT_STOP_DET : stop condition  interrupt
  * @arg  I2C_IT_START_DET: start condition  interrupt
  * @arg  I2C_IT_GEN_CALL : a general call address and ack interrupt
  * @retval None.
  */
void I2C_ClearITPendingBit(I2C_TypeDef* i2c, uint32_t it)
{
    if ((it & I2C_IT_RX_UNDER) == I2C_FLAG_RX_UNDER)
        i2c->RX_UNDER;
    if ((it & I2C_IT_RX_OVER) == I2C_FLAG_RX_OVER)
        i2c->RX_OVER;
    if ((it & I2C_IT_TX_OVER) == I2C_FLAG_TX_OVER)
        i2c->TX_OVER;
    if ((it & I2C_IT_RD_REQ) == I2C_FLAG_RD_REQ)
        i2c->RD_REQ;
    if ((it & I2C_IT_TX_ABRT) == I2C_FLAG_TX_ABRT)
        i2c->TX_ABRT;
    if ((it & I2C_IT_RX_DONE) == I2C_FLAG_RX_DONE)
        i2c->RX_DONE;
    if ((it & I2C_IT_ACTIVITY) == I2C_FLAG_ACTIVITY)
        i2c->ACTIV;
    if ((it & I2C_IT_STOP_DET) == I2C_FLAG_STOP_DET)
        i2c->STOP;
    if ((it & I2C_IT_START_DET) == I2C_FLAG_START_DET)
        i2c->START;
    if ((it & I2C_IT_GEN_CALL) == I2C_FLAG_GEN_CALL)
        i2c->GC;
}


/* New Function Interface ----------------------------------------------------*/



/**
  * @brief  Configures slave address.
  * @param  i2c: select the I2C peripheral.
  * @param  addr: specifies the slave address which will be transmitted
  *   This parameter can be one of the following values
  * @retval None.
  */
void I2C_SendSlaveAddress(I2C_TypeDef* i2c, uint8_t addr)
{
    WRITE_REG(i2c->SAR, addr >> 1);
}

/**
  * @brief  Enables or disables the I2C slave mode.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the specified I2C interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_SlaveConfigure(I2C_TypeDef* i2c, FunctionalState state)
{
    (state) ? CLEAR_BIT(i2c->CR, I2C_CR_DISSLAVE) : SET_BIT(i2c->CR, I2C_CR_DISSLAVE);
}

/**
  * @brief  Configures the specified I2C DMA requests.
  * @param  i2c: select the I2C peripheral.
  * @param  dir : TDMAE_SET,RDMAE_SET
  *   This parameter can be any combination of the following values:
  * @arg  TDMAE_SET: DMA TX set
  * @arg  RDMAE_SET: DMA RX set
  * @arg  TRDMA_RESET:DMA TX and RX reset
  * @retval None.
  */
void I2C_DMAConfigure(I2C_TypeDef* i2c, I2C_DMA_Dir_TypeDef dir)
{
    MODIFY_REG(i2c->DMA, (I2C_DMA_RXEN | I2C_DMA_TXEN), ((uint32_t)dir));
}

/**
  * @brief  Configures slave address mask.
  * @param  i2c: select the I2C peripheral.
  * @param  mask: specifies the slave address mask
  * @retval None.
  */
void I2C_SlaveReceivedAddressMask(I2C_TypeDef* i2c, uint16_t  mask)
{
    WRITE_REG(i2c->SLVMASK, mask);
}

/**
  * @brief  Returns the last i2c Event.
  * @param  i2c: select the I2C peripheral.
  * @retval The last event
  */
uint32_t I2C_GetSlaveReceivedAddr(I2C_TypeDef* i2c)
{
    return (uint32_t)i2c->SLVRCVADDR;
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


