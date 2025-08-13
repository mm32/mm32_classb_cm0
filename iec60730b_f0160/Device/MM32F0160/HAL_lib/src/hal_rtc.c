/*
 *******************************************************************************
    @file     hal_rtc.c
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

/* Files includes ------------------------------------------------------------*/
#include "hal_rtc.h"


/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup RTC_HAL
  * @{
  */

/**
  * @brief  Enables or disables the specified RTC interrupts.
  * @param  it: specifies the RTC interrupts sources to be enabled or
  *         disabled.
  *         This parameter can be any combination of the following values:
  * @arg    RTC_IT_OW: Overflow interrupt
  * @arg    RTC_IT_ALR: Alarm interrupt
  * @arg    RTC_IT_SEC: Second interrupt
  * @param  state: new state of the specified RTC interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RTC_ITConfig(uint16_t it, FunctionalState state)
{
    (state == ENABLE) ? (RTC->CRH |= it) : (RTC->CRL &= (uint16_t)~it);
    RTC_WaitForLastTask();
}

/**
  * @brief  Enters the RTC configuration mode.
  * @param  None.
  * @retval None.
  */
void RTC_EnterConfigMode(void)
{
	RTC->CRL |= RTC_CRL_CNF;
}

/**
  * @brief  Exits from the RTC configuration mode.
  * @param  None.
  * @retval None.
  */
void RTC_ExitConfigMode(void)
{
    RTC->CRL &= ~RTC_CRL_CNF;
    while (!(RTC->CRL & RTC_CRL_RTOFF));

}

/**
  * @brief  Gets the RTC counter value.
  * @param  None.
  * @retval RTC counter value.
  */
uint32_t RTC_GetCounter(void)
{
    uint32_t dat = RTC->CNTH << 16;
    return (RTC->CNTL | dat);
}

/**
  * @brief  Sets the RTC counter value.
  * @param  count: RTC counter new value.
  * @retval None.
  */
void RTC_SetCounter(uint32_t count)
{
    RTC_EnterConfigMode();
    RTC->CNTH = count >> 16;
    RTC->CNTL = count;
    RTC_ExitConfigMode();
}

/**
  * @brief  Sets the RTC prescaler value.
  * @param  prescaler: RTC prescaler new value.
  * @retval None.
  */
void RTC_SetPrescaler(uint32_t prescaler)
{
    RTC_EnterConfigMode();
    RTC->PRLH = prescaler >> 16;
    RTC->PRLL = prescaler;
    RTC_ExitConfigMode();
}

/**
  * @brief  Sets the RTC alarm value.
  * @param  alarm: RTC alarm new value.
  * @retval None.
  */
void RTC_SetAlarm(uint32_t alarm)
{
    RTC_EnterConfigMode();
    RTC->ALRH = alarm >> 16;
    RTC->ALRL = alarm;
    RTC_ExitConfigMode();
}

/**
  * @brief  Gets the RTC divider value.
  * @param  None.
  * @retval RTC Divider value.
  */
uint32_t RTC_GetDivider(void)
{
    uint32_t dat = ((uint32_t)(RTC->DIVH & RTC_DIVH_DIV) << 16);
    return (RTC->DIVL | dat);
}

/**
  * @brief  Waits until last write operation on RTC registers has finished.
  * @note   This function must be called before any write to RTC registers.
  * @param  None.
  * @retval None.
  */
void RTC_WaitForLastTask(void)
{
    while (!(RTC->CRL & RTC_CRL_RTOFF));
}

/**
  * @brief  Waits until the RTC registers (RTC_CNT, RTC_ALR and RTC_PRL)
  *         are synchronized with RTC APB clock.
  * @note   This function must be called before any read operation after an APB
  *         reset or an APB clock stop.
  * @param  None.
  * @retval None.
  */
void RTC_WaitForSynchro(void)
{
    RTC->CRL &= ~RTC_CRL_RSF;
    while (!(RTC->CRL & RTC_CRL_RSF));
}

/**
  * @brief  Checks whether the specified RTC flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one the following values:
  * @arg    RTC_FLAG_RTOFF: RTC Operation OFF flag
  * @arg    RTC_FLAG_RSF: Registers Synchronized flag
  * @arg    RTC_FLAG_OW: Overflow flag
  * @arg    RTC_FLAG_ALR: Alarm flag
  * @arg    RTC_FLAG_SEC: Second flag
  * @retval The state of RTC_FLAG (SET or RESET).
  */
FlagStatus RTC_GetFlagStatus(uint16_t flag)
{
    return  (FlagStatus)(RTC->CRL & flag);
}

/**
  * @brief  Clears the RTC's pending flags.
  * @param  flag: specifies the flag to clear.
  *         This parameter can be any combination of the following values:
  * @arg    RTC_FLAG_RSF: Registers Synchronized flag. This flag is cleared only
  *         after an APB reset or an APB Clock stop.
  * @arg    RTC_FLAG_OW: Overflow flag
  * @arg    RTC_FLAG_ALR: Alarm flag
  * @arg    RTC_FLAG_SEC: Second flag
  * @retval None.
  */
void RTC_ClearFlag(uint16_t flag)
{
    RTC->CRL &= ~flag;
}

/**
  * @brief  Checks whether the specified RTC interrupt has occurred or not.
  * @param  it: specifies the RTC interrupts sources to check.
  *         This parameter can be one of the following values:
  * @arg    RTC_IT_OW: Overflow interrupt
  * @arg    RTC_IT_ALR: Alarm interrupt
  * @arg    RTC_IT_SEC: Second interrupt
  * @retval The state of the RTC_IT (SET or RESET).
  */
ITStatus RTC_GetITStatus(uint16_t it)
{
    return  (ITStatus)(RTC->CRL & it);
}

/**
  * @brief  Clears the RTC's interrupt pending bits.
  * @param  it: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  * @arg    RTC_IT_OW: Overflow interrupt
  * @arg    RTC_IT_ALR: Alarm interrupt
  * @arg    RTC_IT_SEC: Second interrupt
  * @retval None.
  */
void RTC_ClearITPendingBit(uint16_t it)
{
    RTC_EnterConfigMode();
    RTC->CRL &= ~it;
    RTC_ExitConfigMode();
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
