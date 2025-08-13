/**
 ******************************************************************************
 * @file    IEC60730_B_cpu.h
 * @author
 * @version V1.0.0
 * @date    19-June-2019
 * @brief   This file contains start-up CPU test function prototype
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
#ifndef __IEC60730_B_CPU_H
#define __IEC60730_B_CPU_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* This is to be sure that tested value is in-line with code returned by the
   with assembly routine. */
#define CPUTEST_SUCCESS ((uint32_t)0x00000001uL)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
ErrorStatus IEC60730_B_StartUpCPUTest(void);
ErrorStatus IEC60730_B_RunTimeCPUTest(void);

#endif /* IEC60730_B_cpu.h  */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
