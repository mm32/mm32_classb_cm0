/***********************************************************************************************************************
    @file     hal_flash.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE FLASH FIRMWARE FUNCTIONS.
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
#define _HAL_FLASH_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_flash.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup FLASH_HAL
  * @{
  */

/** @addtogroup FLASH_Exported_Functions
  * @{
  */

/**
  * @brief  Sets the code latency value.
  * @note   This function can be used for all MM32 devices.
  * @param  latency: specifies the FLASH Latency value.
  *         This parameter can be one of the following values:
  * @arg    FLASH_Latency_0: FLASH Zero Latency cycle
  * @arg    FLASH_Latency_1: FLASH One Latency cycle
  * @arg    FLASH_Latency_2: FLASH Two Latency cycles
  * @arg    FLASH_Latency_3: FLASH Three Latency cycles
  * @retval None.
  */
void FLASH_SetLatency(uint32_t latency)
{
    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY_Msk, latency);
}

/**
  * @brief  Enables or disables the Prefetch Buffer.
  * @note   This function can be used for all MM32 devices.
  * @param  prefetch_buffer: specifies the Prefetch buffer status.
  *         This parameter can be one of the following values:
  * @arg    FLASH_PrefetchBuffer_Enable: FLASH Prefetch Buffer Enable
  * @arg    FLASH_PrefetchBuffer_Disable: FLASH Prefetch Buffer Disable
  * @retval None.
  */
void FLASH_PrefetchBufferCmd(uint32_t prefetch_buffer)
{
    MODIFY_REG(FLASH->ACR, FLASH_ACR_PRFTBE_Msk, prefetch_buffer);
}

/**
  * @brief  Locks the FLASH Program Erase Controller.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval None.
  */
void FLASH_Lock(void)
{
    FLASH->CR |= (0x01U << FLASH_CR_LOCK_Pos);
}

/**
  * @brief  Unlocks the FLASH Program Erase Controller.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval None.
  */
void FLASH_Unlock(void)
{
    FLASH->KEYR = FLASH_KEY1;
    FLASH->KEYR = FLASH_KEY2;
}

/**
  * @brief  Enable to program the FLASH Option Byte.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval None.
  */
void FLASH_OPTB_Enable(void)
{
    FLASH->OPTKEYR = FLASH_KEY1;
    FLASH->OPTKEYR = FLASH_KEY2;
}

/**
  * @brief  Erases a specified FLASH page.
  * @note   This function can be used for all MM32 devices.
  * @param  page_address: The page address to be erased.
  * @retval FLASH Status: The returned value can be: FLASH_BUSY,
  *         FLASH_ERROR_PG, FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_ErasePage(uint32_t page_address)
{
    FLASH->CR |= (0x01U << FLASH_CR_PER_Pos);
    FLASH->AR  = page_address;
    FLASH->CR |= (0x01U << FLASH_CR_STRT_Pos);
    return FLASH_WaitForLastOperation(EraseTimeout);
}

/**
  * @brief  Erases all FLASH pages.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_EraseAllPages(void)
{
    FLASH->AR = FLASH_BASE;
    FLASH->CR |= (0x01U << FLASH_CR_MER_Pos);
    FLASH->CR |= (0x01U << FLASH_CR_STRT_Pos);

    return FLASH_WaitForLastOperation(EraseTimeout);
}

/**
  * @brief  Erases the FLASH option bytes.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_EraseOptionBytes(void)
{
    FLASH_OPTB_Enable();
    FLASH->AR = OB_BASE;
    FLASH->CR |= (0x01U << FLASH_CR_OPTER_Pos);
    FLASH->CR |= (0x01U << FLASH_CR_STRT_Pos);

    return FLASH_WaitForLastOperation(EraseTimeout);
}

/**
  * @brief  Programs a half word at a specified address.
  * @note   This function can be used for all MM32 devices.
  * @param  address: specifies the address to be programmed.
  * @param  data: specifies the data to be programmed.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_ProgramHalfWord(uint32_t address, uint16_t data)
{
    FLASH->CR |= (0x01U << FLASH_CR_PG_Pos);

    *(__IO uint16_t*)address = data;

    return FLASH_WaitForLastOperation(ProgramTimeout);
}

/**
  * @brief  Programs a word at a specified address.
  * @note   This function can be used for all MM32 devices.
  * @param  address: specifies the address to be programmed.
  * @param  data: specifies the data to be programmed.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_ProgramWord(uint32_t address, uint32_t data)
{
    FLASH_Status ret = FLASH_ProgramHalfWord(address, data);

    if (ret == FLASH_COMPLETE)
    {
        ret = FLASH_ProgramHalfWord(address + 2, data >> 16);
    }
    return ret;
}

/**
  * @brief  Programs a byte at a specified Option Byte Data address.
  * @note   This function can be used for all MM32 devices.
  * @param  address: specifies the address to be programmed.
  *         This parameter can be 0x1FFFF804 or 0x1FFFF806.
  * @param  data: specifies the data to be programmed.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_ProgramOptionByteData(uint32_t address, uint8_t data)
{
    FLASH_Status ret;

    FLASH_OPTB_Enable();
    FLASH->CR |= (0x01U << FLASH_CR_OPTPG_Pos);

    *(__IO uint16_t*)address = (uint16_t)data;

    ret = FLASH_WaitForLastOperation(ProgramTimeout);

    return ret;
}

/**
  * @brief  Programs a half word at a specified Option Byte Data address.
  * @note   This function can be used for all MM32 devices.
  * @param  address: specifies the address to be programmed.
  *         This parameter can be 0x1FFFF804 or 0x1FFFF806.
  * @param  data: specifies the data to be programmed.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_ProgramOptionHalfWord(uint32_t address, uint16_t data)
{
    FLASH_Status ret;

    FLASH_OPTB_Enable();
    FLASH->CR |= (0x01U << FLASH_CR_OPTPG_Pos);

    *(__IO uint16_t*)address = data;

    ret = FLASH_WaitForLastOperation(ProgramTimeout);

    return ret;
}

/**
  * @brief  Write protection for the specified address
  * @note   This function can be used for all MM32 devices.
  * @param  page: specifies the address of the pages to be write
  *         protected.
  *         This parameter is (0x01 << ((Absolute address - 0x08000000)/0x1000))
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_EnableWriteProtection(uint32_t page)
{
    FLASH_Status ret;
    uint8_t i;

    for (i = 0; i < 4; i++) 
    {
        ret = FLASH_ProgramOptionHalfWord((OB_BASE + 8 + i * 2), ~(page >> (i * 8)));

        if (ret != FLASH_COMPLETE) 
        {
            break;
        }
    }

    return ret;
}

/**
  * @brief  Programs the FLASH User Option Byte: IWDG_SW / RST_STOP / RST_STDBY.
  * @param  ob_iwdg: Selects the IWDG mode
  *    @arg OB_IWDG_SW       Software IWDG selected
  *    @arg OB_IWDG_HW       Hardware IWDG selected 
  * @param  ob_stop: Reset event when entering STOP mode.
  *    @arg OB_STOP_NoRST    No reset generated when entering in STOP
  *    @arg OB_STOP_RST      Reset generated when entering in STOP 
  * @param  standby: Reset event when entering Standby mode.
  *    @arg OB_STDBY_NoRST   No reset generated when entering in STANDBY
  *    @arg OB_STDBY_RST     Reset generated when entering in STANDBY
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_UserOptionByteConfig(uint32_t ob_iwdg, uint32_t ob_stop, uint32_t standby)
{
    FLASH_OPTB_Enable();

    FLASH->CR |= (0x01U << FLASH_CR_OPTPG_Pos);

    OB->USER |= ob_iwdg;
    OB->USER |= ob_stop;
    OB->USER |= standby;

    return FLASH_WaitForLastOperation(ProgramTimeout);
}

/**
  * @brief  Returns the FLASH User Option Bytes values.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval The FLASH User Option Bytes values:IWDG_SW(Bit0), RST_STOP(Bit1)
  *         and RST_STDBY(Bit2).
  */
uint32_t FLASH_GetUserOptionByte(void)
{
    return (FLASH->OBR >> 2);
}

/**
  * @brief  Returns the FLASH Write Protection Option Bytes Register value.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval The FLASH Write Protection  Option Bytes Register value.
  */
uint32_t FLASH_GetWriteProtectionOptionByte(void)
{
    return (FLASH->WRPR);
}

/**
  * @brief  Checks whether the FLASH Prefetch Buffer status is set or not.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval FLASH Prefetch Buffer Status (SET or RESET).
  */
FlagStatus FLASH_GetPrefetchBufferStatus(void)
{
    return (FLASH->ACR & FLASH_ACR_PRFTBS_Msk) ? SET : RESET;
}

/**
  * @brief  Checks whether the specified FLASH flag is set or not.
  * @note   This function can be used for all MM32 devices.
  * @param  flag: specifies the FLASH flags to clear.
  *         This parameter can be one of the following values:
  * @arg    FLASH_FLAG_BSY: FLASH Busy flag
  * @arg    FLASH_FLAG_PGERR: FLASH Program error flag
  * @arg    FLASH_FLAG_WRPRTERR: FLASH Write protected error flag
  * @arg    FLASH_FLAG_EOP: FLASH End of Operation flag
  * @arg    FLASH_FLAG_OPTERR:  FLASH Option Byte error flag
  * @retval The new state of FLASH_FLAG (SET or RESET).
  */
FlagStatus FLASH_GetFlagStatus(uint16_t flag)
{
    return ((flag == FLASH_FLAG_OPTERR) ? (FLASH->OBR & FLASH_FLAG_OPTERR) : (FLASH->SR & flag)) ? SET : RESET;
}

/**
  * @brief  Clears the FLASH's pending flags.
  * @note   This function can be used for all MM32 devices.
  * @param  flag: specifies the FLASH flags to clear.
  *         This parameter can be any combination of the following values:
  * @arg    FLASH_FLAG_PGERR: FLASH Program error flag
  * @arg    FLASH_FLAG_WRPRTERR: FLASH Write protected error flag
  * @arg    FLASH_FLAG_EOP: FLASH End of Operation flag
  * @retval None.
  */
void FLASH_ClearFlag(uint16_t flag)
{
    FLASH->SR = flag;
}

/**
  * @brief  Returns the FLASH Status.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval FLASH Status: The returned value can be: FLASH_BUSY,
  *         FLASH_ERROR_PG, FLASH_ERROR_WRP or FLASH_COMPLETE.
  */
FLASH_Status FLASH_GetStatus(void)
{
    return (FLASH_Status)((FLASH->SR & FLASH_FLAG_BSY))
           ? FLASH_BUSY
           : ((FLASH->SR & FLASH_FLAG_PGERR) ? FLASH_ERROR_PG
              : ((FLASH->SR & FLASH_FLAG_WRPRTERR) ? FLASH_ERROR_WRP : FLASH_COMPLETE));
}

/**
  * @brief  Waits for a Flash operation to complete or a TIMEOUT to occur.
  * @note   This function can be used for all MM32 devices
  * @param  time_out: FLASH programming time_out
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_WaitForLastOperation(uint32_t time_out)
{
    uint32_t i;
    FLASH_Status ret = FLASH_COMPLETE;

    do 
    {
        ret = FLASH_GetStatus();
        time_out--;

        for (i = 0xFF; i != 0; i--)
        {;}
    } while ((ret == FLASH_BUSY) && (time_out != 0x00));

    FLASH->CR &= ~(FLASH_CR_PG_Msk | FLASH_CR_PER_Msk | FLASH_CR_MER_Msk | FLASH_CR_OPTPG_Msk | FLASH_CR_OPTER_Msk | FLASH_CR_STRT_Msk);
    FLASH->SR  = (0x01U << FLASH_SR_EOP_Pos) | (0x01U << FLASH_SR_WRPRTERR_Pos) | (0x01U << FLASH_SR_PGERR_Pos);

    return (FLASH_Status)((time_out == 0x00) ? FLASH_TIMEOUT : ret);
}

/**
  * @brief  Erases a specified DataArea page.
  * @note   This function can be used for all MM32 devices.
  * @param  page_address: The DataArea page address to be erased.
  * @retval FLASH Status: The returned value can be: FLASH_BUSY,
  *         FLASH_ERROR_PG, FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_EraseDataAreaPage(uint32_t page_address)
{
	FLASH_OPTB_Enable();
    FLASH->AR  = page_address;
    FLASH->CR |= (0x01U << FLASH_CR_OPTER_Pos);
    FLASH->CR |= (0x01U << FLASH_CR_STRT_Pos);

    return (FLASH_WaitForLastOperation(EraseTimeout));
}

/**
  * @brief  Programs a half word at a specified DataArea address.
  * @note   This function can be used for all MM32 devices.
  * @param  address: specifies the DataArea address to be programmed.
  * @param  data: specifies the data to be programmed.
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_PG,
  *         FLASH_ERROR_WRP, FLASH_COMPLETE or FLASH_TIMEOUT.
  */
FLASH_Status FLASH_ProgramDataAreaHalfWord(uint32_t address, uint16_t data)
{
    FLASH_Status ret;

    FLASH_OPTB_Enable();

    FLASH->CR |= (0x01U << FLASH_CR_OPTPG_Pos);

    *(__IO uint16_t *)address = data;

    ret = FLASH_WaitForLastOperation(ProgramTimeout);

    return (ret);
}

/**
  * @brief  Disable to program the FLASH Option Byte.
  * @note   This function can be used for all MM32 devices.
  * @param  None.
  * @retval None.
  */
void FLASH_OPTB_Disable(void)
{
    FLASH->CR &= ~(0x01U << FLASH_CR_OPTWRE_Pos);
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

