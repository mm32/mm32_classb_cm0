/**
 ******************************************************************************
 * @file    IEC60730_B_crc32.h
 * @author
 * @version V1.2.0
 * @date    19-June-2019
 * @brief   Contains the prototypes of the functions performing
 *          run time invariable memory checks based on 32-bit CRC
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
#ifndef __IEC60730_B_CRC32_H
#define __IEC60730_B_CRC32_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  TEST_RUNNING,
  CLASS_B_DATA_FAIL,
  CTRL_FLW_ERROR,
  TEST_FAILURE,
  TEST_OK
} ClassBTestStatus;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void IEC60730_FlashCrc32Init(void);
ClassBTestStatus IEC60730_crc32Run(void);

#endif /* __IEC60730_B_CRC32_H */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
