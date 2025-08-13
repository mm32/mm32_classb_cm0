/**
  ******************************************************************************
  * @file    IEC60730_B_clock.h 
  * @author  
  * @version V1.2.0
  * @date    19-June-2019
  * @brief   This file contains the prototype of test function for
  *          clock circuitry and frequency at start-up.
  ******************************************************************************/
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IEC60730_B_CLOCK_H
#define __IEC60730_B_CLOCK_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef enum {
              LSI_START_FAIL,
              HSE_START_FAIL,
              HSI_HSE_SWITCH_FAIL,
              TEST_ONGOING,
              EXT_SOURCE_FAIL,
              XCROSS_CONFIG_FAIL,
              HSE_HSI_SWITCH_FAIL,
              PLL_OFF_FAIL,
              CLASS_B_VAR_FAIL,
              CTRL_FLOW_ERROR,
              FREQ_OK
              } ClockStatus;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
ClockStatus IEC60730_ClockStartUpTest(void);
ClockStatus IEC60730_MainClockTest(void);
ErrorStatus IEC60730_InitClock_Xcross_Measurement(void);
ClockStatus IEC60730_HSE_LSIcheck(void);
ClockStatus IEC60730_HSI_LSIcheck(void);
ClockStatus IEC60730_clockrun_valuecheck(void);
#endif /* IEC60730_B_clock.h */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
