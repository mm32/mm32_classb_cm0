/**
 ******************************************************************************
 * @file    IEC60730_B_startup.h
 * @author
 * @version V1.2.0
 * @date    19-June-2019
 * @brief   This file contains the prototype of the FailSafe routines and
 *          the very first self-test function to be executed after the reset.
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
#ifndef __IEC60730_B_STARTUP_H
#define __IEC60730_B_STARTUP_H

/* Includes ------------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void IEC60730_B_startup(void);
ErrorStatus IEC60730_B_WDGSelfTest(void);
ErrorStatus IEC60730_B_FullCpu_test(void);
ErrorStatus IEC60730_B_CpuRunTime_test(void);
ErrorStatus IEC60730_Stack_Check(void);
ErrorStatus IEC60730_B_FullFlash_test(void);
void IEC60730_B_CRC_StoreclassBData(void);
void IEC60730_ClockTest_Startup(void);
void IEC60730_ClockTest_RunTime(void);
void Flashtest_config(void);
void Ramtest_config(void);
void IEC60730_B_FlashRunTime_test(void);

#endif /* __IEC60730_B_STARTUP_H */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
