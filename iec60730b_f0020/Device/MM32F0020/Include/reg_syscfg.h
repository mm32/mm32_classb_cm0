////////////////////////////////////////////////////////////////////////////////
/// @file     reg_syscfg.h
/// @author   AE TEAM
/// @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
///           MM32 FIRMWARE LIBRARY.
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

#ifndef __REG_SYSCFG_H
#define __REG_SYSCFG_H

// Files includes

#include <stdint.h>
#include <stdbool.h>
#include "types.h"




#if defined ( __CC_ARM )
#pragma anon_unions
#endif









#define SYSCFG_BASE                     (APB1PERIPH_BASE + 0x010000)            ///< Base Address: 0x40010000





////////////////////////////////////////////////////////////////////////////////
/// @brief SysTem Configuration Register Structure Definition
////////////////////////////////////////////////////////////////////////////////
typedef struct {
    union {
        __IO u32 CFGR;                                                          ///< SYSCFG configuration register                  offset: 0x00
        __IO u32 CFGR1;
    };
    __IO u32 RESERVED0x04;                                                      ///< RESERVED register                              offset: 0x04
    __IO u32 EXTICR[4];                                                         ///< EXTI Control register                          offset: 0x08-0x14
    __IO u32 PADHYS;                                                            ///< PADHYS register                                offset: 0x18
} SYSCFG_TypeDef;


#define SYSCFG                          ((SYSCFG_TypeDef *) SYSCFG_BASE)



////////////////////////////////////////////////////////////////////////////////
///@brief System Configuration (SYSCFG)
////////////////////////////////////////////////////////////////////////////////

/// @brief SYSCFG_CFGR Register Bit definition
#define SYSCFG_CFGR_MEM_MODE_Pos        (0)
#define SYSCFG_CFGR_MEM_MODE            ((u32)0x00000003)                       ///< SYSCFG_Memory Remap Config
#define SYSCFG_CFGR_MEM_MODE_0          ((u32)0x00000001)                       ///< SYSCFG_Memory Remap Config Bit 0
#define SYSCFG_CFGR_MEM_MODE_1          ((u32)0x00000002)                       ///< SYSCFG_Memory Remap Config Bit 1
///



/// @brief SYSCFG_EXTICR1 Register Bit definition
#define SYSCFG_EXTICR1_EXTI0            ((u16)0x000F)                           ///< EXTI 0 configuration
#define SYSCFG_EXTICR1_EXTI1            ((u16)0x00F0)                           ///< EXTI 1 configuration
#define SYSCFG_EXTICR1_EXTI2            ((u16)0x0F00)                           ///< EXTI 2 configuration
#define SYSCFG_EXTICR1_EXTI3            ((u16)0xF000)                           ///< EXTI 3 configuration

///  @brief  EXTI0 configuration
#define SYSCFG_EXTICR1_EXTI0_PA         ((u16)0x0000)                           ///< PA[0] pin
#define SYSCFG_EXTICR1_EXTI0_PB         ((u16)0x0001)                           ///< PB[0] pin


///  @brief  EXTI1 configuration
#define SYSCFG_EXTICR1_EXTI1_PA         ((u16)0x0000)                           ///< PA[1] pin
#define SYSCFG_EXTICR1_EXTI1_PB         ((u16)0x0010)                           ///< PB[1] pin


///  @brief  EXTI2 configuration
#define SYSCFG_EXTICR1_EXTI2_PA         ((u16)0x0000)                           ///< PA[2] pin
#define SYSCFG_EXTICR1_EXTI2_PB         ((u16)0x0100)                           ///< PB[2] pin



///  @brief  EXTI3 configuration
#define SYSCFG_EXTICR1_EXTI3_PA         ((u16)0x0000)                           ///< PA[3] pin



/// @brief SYSCFG_EXTICR2 Register Bit definition
#define SYSCFG_EXTICR2_EXTI4            ((u16)0x000F)                           ///< EXTI 4 configuration
#define SYSCFG_EXTICR2_EXTI5            ((u16)0x00F0)                           ///< EXTI 5 configuration
#define SYSCFG_EXTICR2_EXTI6            ((u16)0x0F00)                           ///< EXTI 6 configuration
#define SYSCFG_EXTICR2_EXTI7            ((u16)0xF000)                           ///< EXTI 7 configuration

/// @brief  EXTI4 configuration
#define SYSCFG_EXTICR2_EXTI4_PA         ((u16)0x0000)                           ///< PA[4] pin




/// @brief  EXTI5 configuration
#define SYSCFG_EXTICR2_EXTI5_PA         ((u16)0x0000)                           ///< PA[5] pin



/// @brief  EXTI6 configuration

#define SYSCFG_EXTICR2_EXTI6_PA         ((u16)0x0000)                           ///< PA[6] pin




/// @brief  EXTI7 configuration
#define SYSCFG_EXTICR2_EXTI7_PA         ((u16)0x0000)                           ///< PA[7] pin



/// @brief SYSCFG_EXTICR3 Register Bit definition
#define SYSCFG_EXTICR3_EXTI8            ((u16)0x000F)                           ///< EXTI 8 configuration
#define SYSCFG_EXTICR3_EXTI9            ((u16)0x00F0)                           ///< EXTI 9 configuration
#define SYSCFG_EXTICR3_EXTI10           ((u16)0x0F00)                           ///< EXTI 10 configuration
#define SYSCFG_EXTICR3_EXTI11           ((u16)0xF000)                           ///< EXTI 11 configuration

///  @brief  EXTI8 configuration
#define SYSCFG_EXTICR3_EXTI8_PA         ((u16)0x0000)                           ///< PA[8] pin



///  @brief  EXTI9 configuration

#define SYSCFG_EXTICR3_EXTI9_PA         ((u16)0x0000)                           ///< PA[9] pin


///  @brief  EXTI10 configuration
#define SYSCFG_EXTICR3_EXTI10_PA        ((u16)0x0000)                           ///< PA[10] pin


///  @brief  EXTI11 configuration
#define SYSCFG_EXTICR3_EXTI11_PA        ((u16)0x0000)                           ///< PA[11] pin



/// @brief SYSCFG_EXTICR4 Register Bit definition
#define SYSCFG_EXTICR4_EXTI12           ((u16)0x000F)                           ///< EXTI 12 configuration
#define SYSCFG_EXTICR4_EXTI13           ((u16)0x00F0)                           ///< EXTI 13 configuration
#define SYSCFG_EXTICR4_EXTI14           ((u16)0x0F00)                           ///< EXTI 14 configuration
#define SYSCFG_EXTICR4_EXTI15           ((u16)0xF000)                           ///< EXTI 15 configuration

#define SYSCFG_EXTICR4_EXTI12_PA        ((u16)0x0000)                           ///< PA[12] pin for EXTI12


#define SYSCFG_EXTICR4_EXTI13_PA        ((u16)0x0000)                           ///< PA[13] pin for EXTI13


#define SYSCFG_EXTICR4_EXTI14_PA        ((u16)0x0000)                           ///< PA[14] pin for EXTI14


#define SYSCFG_EXTICR4_EXTI15_PA        ((u16)0x0000)                           ///< PA[15] pin for EXTI15


/// @brief SYSCFG_PADHYS Register Bit definition
#define SYSCFG_PADHYS_I2C1_MODE_SEL_Pos (16)
#define SYSCFG_PADHYS_I2C1_MODE_SEL     (0x01U  << SYSCFG_PADHYS_I2C1_MODE_SEL_Pos)                   ///< I2C1 Enable PushPull mode





/// @}

/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
