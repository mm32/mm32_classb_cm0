;******************** (C) COPYRIGHT 2023 MindMotion ********************
;* File Name          : startup_mm32f0160.s
;* Author             : AE Team
;* Version            : V1.5.0
;* Date               : 07/09/2023
;* Description        : MM32F031 Medium-density devices vector table for EWARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == __iar_program_start,
;*                      - Set the vector table entries with the exceptions ISR
;*                        address
;*                      - Configure the system clock
;*                      - Branches to main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the Cortex-M0 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;*******************************************************************************
;
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler                    ; NMI Handler
        DCD     HardFault_Handler              ; Hard Fault Handler
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     SVC_Handler                    ; SVCall Handler
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     PendSV_Handler                 ; PendSV Handler
        DCD     SysTick_Handler                ; SysTick Handler

        ; External Interrupts
        DCD     WWDG_IWDG_IRQHandler           ; Window Watchdog
        DCD     PVD_IRQHandler                 ; PVD through EXTI Line detect
        DCD     RTC_BKP_IRQHandler             ; RTC_BKP
        DCD     FLASH_IRQHandler               ; FLASH
        DCD     RCC_IRQHandler                 ; RCC & CRS
        DCD     EXTI0_1_IRQHandler             ; EXTI Line 0 and 1
        DCD     EXTI2_3_IRQHandler             ; EXTI Line 2 and 3
        DCD     EXTI4_15_IRQHandler            ; EXTI Line 4 to 15
        DCD     HWDIV_IRQHandler               ; HWDIV
        DCD     DMA1_Channel1_IRQHandler       ; DMA1 Channel 1
        DCD     DMA1_Channel2_3_IRQHandler     ; DMA1 Channel 2 to Channel 3
        DCD     DMA1_Channel4_7_IRQHandler     ; DMA1 Channel 4 to Channel 7
        DCD     ADC_COMP_IRQHandler            ; ADC1 & COMP
        DCD     TIM1_BRK_UP_TRG_COM_IRQHandler ; TIM1 Break, Update, Trigger and Commutation
        DCD     TIM1_CC_IRQHandler             ; TIM1 Capture Compare
        DCD     TIM2_IRQHandler                ; TIM2
        DCD     TIM3_IRQHandler                ; TIM3
        DCD     LPUART1_IRQHandler             ; LPUART
        DCD     LPTIM1_IRQHandler              ; LPTIM
        DCD     TIM14_IRQHandler               ; TIM14
        DCD     0                              ; Reserved
        DCD     TIM16_IRQHandler               ; TIM16
        DCD     TIM17_IRQHandler               ; TIM17
        DCD     I2C1_IRQHandler                ; I2C1
        DCD     I3C1_IRQHandler                ; I3C1
        DCD     SPI1_IRQHandler                ; SPI1
        DCD     SPI2_IRQHandler                ; SPI2
        DCD     UART1_IRQHandler               ; UART1
	    DCD     UART2_IRQHandler               ; UART2
	    DCD	    UART3_UART4_IRQHandler	       ; UART3 UART4
	    DCD	    FlexCAN_IRQHandler             ; FlexCAN
	    DCD	    USB_IRQHandler                 ; USB_OTG_FS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0
        PUBWEAK NMI_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK WWDG_IWDG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WWDG_IWDG_IRQHandler
        B WWDG_IWDG_IRQHandler

        PUBWEAK PVD_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
PVD_IRQHandler
        B PVD_IRQHandler

        PUBWEAK RTC_BKP_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RTC_BKP_IRQHandler
        B RTC_BKP_IRQHandler

        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
FLASH_IRQHandler
        B FLASH_IRQHandler


        PUBWEAK RCC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RCC_IRQHandler
        B RCC_IRQHandler

        PUBWEAK EXTI0_1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI0_1_IRQHandler
        B EXTI0_1_IRQHandler

        PUBWEAK EXTI2_3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI2_3_IRQHandler
        B EXTI2_3_IRQHandler

        PUBWEAK EXTI4_15_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTI4_15_IRQHandler
        B EXTI4_15_IRQHandler


        PUBWEAK HWDIV_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
HWDIV_IRQHandler
        B HWDIV_IRQHandler


        PUBWEAK DMA1_Channel1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA1_Channel1_IRQHandler
        B DMA1_Channel1_IRQHandler


        PUBWEAK DMA1_Channel2_3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA1_Channel2_3_IRQHandler
        B DMA1_Channel2_3_IRQHandler


        PUBWEAK DMA1_Channel4_7_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA1_Channel4_7_IRQHandler
        B DMA1_Channel4_7_IRQHandler

        PUBWEAK ADC_COMP_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ADC_COMP_IRQHandler
        B ADC_COMP_IRQHandler

        PUBWEAK TIM1_BRK_UP_TRG_COM_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM1_BRK_UP_TRG_COM_IRQHandler
        B TIM1_BRK_UP_TRG_COM_IRQHandler

        PUBWEAK TIM1_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM1_CC_IRQHandler
        B TIM1_CC_IRQHandler

        PUBWEAK TIM2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM2_IRQHandler
        B TIM2_IRQHandler

        PUBWEAK TIM3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM3_IRQHandler
        B TIM3_IRQHandler

	PUBWEAK LPUART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPUART1_IRQHandler
        B LPUART1_IRQHandler

        PUBWEAK LPTIM1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPTIM1_IRQHandler
        B LPTIM1_IRQHandler

        PUBWEAK TIM14_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM14_IRQHandler
        B TIM14_IRQHandler

        PUBWEAK TIM16_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM16_IRQHandler
        B TIM16_IRQHandler

        PUBWEAK TIM17_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM17_IRQHandler
        B TIM17_IRQHandler

        PUBWEAK I2C1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C1_IRQHandler
        B I2C1_IRQHandler

        PUBWEAK I3C1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I3C1_IRQHandler
        B I3C1_IRQHandler

        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_IRQHandler
        B SPI1_IRQHandler

        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI2_IRQHandler
        B SPI2_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK UART3_UART4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART3_UART4_IRQHandler
        B UART3_UART4_IRQHandler

        PUBWEAK FlexCAN_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
FlexCAN_IRQHandler
        B FlexCAN_IRQHandler

	PUBWEAK USB_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
USB_IRQHandler
        B USB_IRQHandler

        END
;******************** (C) COPYRIGHT 2016 MindMotion ********************
