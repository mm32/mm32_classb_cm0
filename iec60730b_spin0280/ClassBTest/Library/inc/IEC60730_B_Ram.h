/**
 ******************************************************************************
 * @file    IEC60730_B_Ram.h
 * @author
 * @version V1.2.0
 * @date    19-June-2019
 * @brief   This file contains prototype of the RAM functional test
 *          to be done at start-up.
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
#ifndef __IEC60730_B_RAM_H
#define __IEC60730_B_RAM_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define MARCH_STEP_SUCCESS ((uint32_t)0x00000001uL)
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
ErrorStatus IEC60730_B_FullRamMarchC(uint32_t *beg, uint32_t *end, uint32_t pat);
ErrorStatus IEC60730_B_FullRamMarchCVA5(uint32_t *beg, uint32_t *end,uint32_t pat);
ErrorStatus IEC60730_B_TranspRamMarchCXStep(uint32_t *beg, uint32_t *buf, uint32_t pat);
void IEC60730_B_TranspMarchInit(void);
ClassBTestStatus IEC60730_B_TranspMarch(uint32_t startadd, uint32_t endadd, uint32_t MCU_endadd);
#endif /* __IEC60730_B_RAM_H */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
