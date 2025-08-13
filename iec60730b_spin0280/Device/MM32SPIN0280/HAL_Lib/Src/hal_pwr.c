////////////////////////////////////////////////////////////////////////////////
/// @file     hal_pwr.c
/// @author   AE TEAM
/// @brief    THIS FILE PROVIDES ALL THE PWR FIRMWARE FUNCTIONS.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion
#define __HAL_PWR_C_

// Files includes
#include "hal_pwr.h"
#include "hal_rcc.h"
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup PWR_HAL
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup PWR_Exported_Functions
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  Deinitializes the PWR peripheral registers to their default reset
/// values.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_DeInit(void)
{
    exRCC_APB1PeriphReset(RCC_APB1ENR_PWR);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Enables or disables access to the RTC and backup registers.
/// @param  state: new state of the access to the RTC and backup
///         registers. This parameter can be: ENABLE or DISABLE.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_BackupAccessCmd(FunctionalState state)
{
    (state) ? (PWR->CR |= PWR_CR_DBP) : (PWR->CR &= ~PWR_CR_DBP);
}
////////////////////////////////////////////////////////////////////////////////
/// @brief  Enables or disables the Power Voltage Detector(PVD).
/// @param  state: new state of the PVD.
///         This parameter can be: ENABLE or DISABLE.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_PVDCmd(FunctionalState state)
{
    (state) ? (PWR->CR |= PWR_CR_PVDE) : (PWR->CR &= ~PWR_CR_PVDE);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Configures the voltage threshold detected by the Power Voltage
///         Detector(PVD).
/// @param  pvd_level: specifies the PVD detection level
///         This parameter can be one of the following values:
/// @arg    emPVD_LEVEL0 : PVD detection level set to 1.8V
/// @arg    emPVD_LEVEL1 : PVD detection level set to 2.1V
/// @arg    emPVD_LEVEL2 : PVD detection level set to 2.4V
/// @arg    emPVD_LEVEL3 : PVD detection level set to 2.7V
/// @arg    emPVD_LEVEL4 : PVD detection level set to 3.0V
/// @arg    emPVD_LEVEL5 : PVD detection level set to 3.3V
/// @arg    emPVD_LEVEL6 : PVD detection level set to 3.6V
/// @arg    emPVD_LEVEL7 : PVD detection level set to 3.9V
/// @arg    emPVD_LEVEL8 : PVD detection level set to 4.2V
/// @arg    emPVD_LEVEL9 : PVD detection level set to 4.5V
/// @arg    emPVD_LEVEL10: PVD detection level set to 4.8V
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_PVDLevelConfig(emPVD_Level_Typedef pvd_level)
{
    PWR->CR = (PWR->CR & (~PWR_CR_PLS)) | pvd_level;
}

/**
  * @brief  Enables or disables the WakeUp Pin functionality.
  * @param  pin: slect wakeup pin
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN0
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @param  state: new state of the WakeUp Pin functionality.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_WakeUpPinXCmd(uint8_t pin, FunctionalState state)
{
    (state) ? \
    (PWR->CSR |=  (pin<<8)) : \
    (PWR->CSR &= ~(pin<<8));
}

/**
  * @brief  Configure the edge detection polarity of the wakeup pin.
  * @param  pin: slect wakeup pin
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN0
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @param  edge: The edge detection configuration of the wakeup pin.
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_EDGE_RISE
  * @arg    WAKEUP_EDGE_FALL
  * @retval None.
  */
void PWR_WakeUpPinXEdgeConfig(uint8_t pin, uint8_t edge)
{
    switch(pin)
    {
        case WAKEUP_PIN0:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP1, (edge << PWR_CR3_WP1_Pos));
            break;
        case WAKEUP_PIN1:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP2, (edge << PWR_CR3_WP2_Pos));
            break;
        case WAKEUP_PIN2:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP3, (edge << PWR_CR3_WP3_Pos));
            break;
        case WAKEUP_PIN3:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP4, (edge << PWR_CR3_WP4_Pos));
            break;
        case WAKEUP_PIN4:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP5, (edge << PWR_CR3_WP5_Pos));
            break;
        case WAKEUP_PIN5:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP6, (edge << PWR_CR3_WP6_Pos));
            break;
        default:
            break; 
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Enables or disables the WakeUp Pin functionality.
/// @param  state: new state of the WakeUp Pin functionality.
///         This parameter can be: ENABLE or DISABLE.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_WakeUpPinCmd(FunctionalState state)
{
    (state != DISABLE) ? (PWR->CSR |= PWR_CSR_EWUP) : (PWR->CSR &= ~PWR_CSR_EWUP);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Enters STOP mode.
/// @param  regulator: specifies the regulator state in STOP mode.
///         This parameter can be one of the following values:
/// @arg    PWR_Regulator_ON: STOP mode with regulator ON
/// @arg    PWR_Regulator_LowPower: STOP mode with regulator in low power mode.
/// @param  stop_entry: specifies if STOP mode in entered with WFI or  WFE
///         instruction.
///         This parameter can be one of the following values:
/// @arg    PWR_STOPEntry_WFI: enter STOP mode with WFI instruction
/// @arg    PWR_STOPEntry_WFE: enter STOP mode with WFE instruction
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_EnterSTOPMode(emPWR_Reg_Stop_mode_Typedef regulator, emPWR_STOP_ModeEn_Typedef stop_entry)
{
    uint32_t tmpreg1 = 0;
    uint32_t tmpreg2 = 0;
	
    MODIFY_REG(PWR->CR, PWR_CR_PDDS | PWR_CR_LDPS, regulator);
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

	tmpreg1 = RCC->CFGR;
    tmpreg2 = FLASH->ACR;

    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR &= ~(RCC_CFGR_HPRE | RCC_CFGR_SW);
    FLASH->ACR &= ~FLASH_ACR_LATENCY;

    FLASH->ACR &= ~FLASH_ACR_PRFTBE;
    while((FLASH->ACR & FLASH_ACR_PRFTBS) != 0)
    {
    }   
	
    if(stop_entry == PWR_STOPEntry_WFI) {
        __WFI();
    }
    else {
        __SEV();
        __WFE();
        __WFE();
    }
    CLEAR_BIT(SCB->SCR, ((u32)SCB_SCR_SLEEPDEEP_Msk));
	
	FLASH->ACR = tmpreg2 & FLASH_ACR_PRFTBE;
    FLASH->ACR = tmpreg2;
    RCC->CFGR = tmpreg1 & 0xFFFFFFF0;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Enters STANDBY mode.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_EnterSTANDBYMode(void)
{
    PWR->CR |= PWR_CR_PDDS;
//    PWR->SCR |= PWR_SCR_CWUF1 | PWR_SCR_CWUF2 | PWR_SCR_CWUF3 | PWR_SCR_CWUF4 | PWR_SCR_CWUF5 | PWR_SCR_CWUF6;

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
#if defined(__CC_ARM)
    __force_stores();
#endif
    __WFI();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Checks whether the specified PWR flag is set or not.
/// @param  flag: specifies the flag to check.
///         This parameter can be one of the following values:
/// @arg    PWR_FLAG_WU: Wake Up flag
/// @arg    PWR_FLAG_SB: StandBy flag
/// @arg    PWR_FLAG_PVDO: PVD Output
/// @retval The new state of PWR_FLAG (SET or RESET).
////////////////////////////////////////////////////////////////////////////////
FlagStatus PWR_GetFlagStatus(u32 flag)
{
    return (FlagStatus)(PWR->CSR & flag);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Clears the PWR's pending flags.
/// @param  flag: specifies the flag to clear.
///         This parameter can be one of the following values:
/// @arg    PWR_FLAG_WU: Wake Up flag
/// @arg    PWR_FLAG_SB: StandBy flag
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void PWR_ClearFlag(u32 flag)
{
    PWR->CR |= flag << 2;
}
//////////////////////////////////////////////////////////////////////////////////
///// @brief  Enters STANDBY mode.
///// @param  None.
///// @retval None.
//////////////////////////////////////////////////////////////////////////////////
//void exPWR_EnterLowPowerMode(emPWR_LP_Mode_Typedef lp_mode, emPWR_Wait_Mode_Typedef wait_mode)
//{
//    if (lp_mode != LP_SLEEP_MODE) {
//        PWR->CR |= lp_mode | PWR_CR_CWUF;
//        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
//        if (wait_mode == LP_WFE) {
//            __WFE();        //  stop & standby
//            return;
//        }
//    }
//    __WFI();        // sleep &  stop & standby

//}

/// @}

/// @}

/// @}
