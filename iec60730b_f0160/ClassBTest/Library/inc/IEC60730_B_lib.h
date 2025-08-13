/**
 ******************************************************************************
 * @file    IEC60730_B_lib.h
 * @author
 * @version V1.2.0
 * @date    19-June-2019
 * @brief   This file references all header files of the Self Test Library
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
#ifndef __IEC60730_B_LIB_H
#define __IEC60730_B_LIB_H

/* Includes ------------------------------------------------------------------*/
#include "IEC60730_B_param.h"

/* Include Class B variables */
/* ==============================================================================*/
/* MISRA violation of rule 8.5 - alocation of variables done via header file jus at this place */
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pm123
#endif /* __IAR_SYSTEMS_ICC__ */
#include "IEC60730_B_var.h"
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm123
#endif /* __IAR_SYSTEMS_ICC__ */
/* ==============================================================================*/
/* Self Test library routines main flow after initialization and at run */
#include "IEC60730_B_startup.h"
#include "IEC60730_B_init.h"

/* Cortex-M0 CPU test */
#include "IEC60730_B_cpu.h"

/* Clock frequency test */
#include "IEC60730_B_clock.h"

/* Invariable memory test */
#include "IEC60730_B_crc32.h"

/* Variable memory test */
#include "IEC60730_B_Ram.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __IEC60730_B_LIB_H */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
