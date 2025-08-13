;/***********************************************************************************************************************
;    @file     startup_mm32SPIN0230_keil.s
;    @author   VV TEAM
;    @brief    THIS FILE PROVIDES ALL THE Device Startup File of MM32 Cortex-M
;              Core Device for ARM KEIL toolchain.
;  **********************************************************************************************************************
;    @attention
;
;    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>
;
;      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
;    following conditions are met:
;    1. Redistributions of source code must retain the above copyright notice,
;       this list of conditions and the following disclaimer.
;    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
;       the following disclaimer in the documentation and/or other materials provided with the distribution.
;    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
;       promote products derived from this software without specific prior written permission.
;
;      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
;    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
;    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;  *********************************************************************************************************************/


Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                                            ;       Top of Stack
                DCD     Reset_Handler                                           ;       Reset Handler
                DCD     NMI_Handler                                             ; -14   NMI Handler
                DCD     HardFault_Handler                                       ; -13   Hard Fault Handler
                DCD     0                                                       ; -12   Reserved
                DCD     0                                                       ; -11   Reserved
                DCD     0                                                       ; -10   Reserved
__vector_table_0x1c
                DCD     0                                                       ;  -9   Reserved
                DCD     0                                                       ;  -8   Reserved
                DCD     0                                                       ;  -7   Reserved
                DCD     0                                                       ;  -6   Reserved
                DCD     SVC_Handler                                             ;  -5   SVCall Handler
                DCD     0                                                       ;  -4   Reserved
                DCD     0                                                       ;  -3   Reserved
                DCD     PendSV_Handler                                          ;  -2   PendSV Handler
                DCD     SysTick_Handler                                         ;  -1   SysTick Handler

                ; External Interrupts
                DCD     IWDG_IRQHandler                                         ;   0   IWDG
                DCD     PVD_IRQHandler                                          ;   1   PVD through EXTI Line detect
                DCD     0                                                       ;   2   Reserved
                DCD     FLASH_IRQHandler                                        ;   3   FLASH
                DCD     RCC_IRQHandler                                          ;   4   RCC
                DCD     EXTI0_1_IRQHandler                                      ;   5   EXTI Line 0 and 1
                DCD     EXTI2_3_IRQHandler                                      ;   6   EXTI Line 2 and 3
                DCD     EXTI4_15_IRQHandler                                     ;   7   EXTI Line 4 to 15
                DCD     HWDIV_IRQHandler                                        ;   8   HWDIV
                DCD     DMA1_Channel1_IRQHandler                                ;   9   DMA1 Channel 1
                DCD     DMA1_Channel2_IRQHandler                                ;  10   DMA1 Channel 2
                DCD     0                                                       ;  11   Reserved
                DCD     ADC_IRQHandler                                          ;  12   ADC
                DCD     TIM1_BRK_UP_TRG_COM_IRQHandler                          ;  13   TIM1 Break, Update, Trigger and Commutation
                DCD     TIM1_CC_IRQHandler                                      ;  14   TIM1 Capture Compare
                DCD     TIM2_IRQHandler                                         ;  15   TIM2
                DCD     TIM6_IRQHandler                                         ;  16   TIM6
                DCD     0                                                       ;  17   Reserved
                DCD     0                                                       ;  18   Reserved
                DCD     0                                                       ;  19   Reserved
                DCD     TIM13_IRQHandler                                        ;  20   TIM13
                DCD     TIM14_IRQHandler                                        ;  21   TIM14
                DCD     0                                                       ;  22   Reserved
                DCD     0                                                       ;  23   Reserved
                DCD     COMP1_2_IRQHandler                                      ;  24   COMP1 and COMP2
                DCD     0                                                       ;  25   Reserved
                DCD     0                                                       ;  26   Reserved
                DCD     USART1_IRQHandler                                       ;  27   USART1
                DCD     0                                                       ;  28   Reserved
                DCD     0                                                       ;  29   Reserved
                DCD     0                                                       ;  30   Reserved
                DCD     0                                                       ;  31   Reserved

                                                                                ; Total Cortex-M0 32 Interrupts are setting
__Vectors_End
__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler                  [WEAK]
                IMPORT  __main
                IMPORT  SystemInit


                LDR     R0, =__initial_sp                                       ; set stack pointer
                MSR     MSP, R0

ApplicationStart
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                    [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler              [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                    [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                 [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler                [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  IWDG_IRQHandler                [WEAK]
                EXPORT  PVD_IRQHandler                 [WEAK]
                EXPORT  FLASH_IRQHandler               [WEAK]
                EXPORT  RCC_IRQHandler                 [WEAK]
                EXPORT  EXTI0_1_IRQHandler             [WEAK]
                EXPORT  EXTI2_3_IRQHandler             [WEAK]
                EXPORT  EXTI4_15_IRQHandler            [WEAK]
                EXPORT  HWDIV_IRQHandler               [WEAK]
                EXPORT  DMA1_Channel1_IRQHandler       [WEAK]
                EXPORT  DMA1_Channel2_IRQHandler       [WEAK]
                EXPORT  ADC_IRQHandler                 [WEAK]
                EXPORT  TIM1_BRK_UP_TRG_COM_IRQHandler [WEAK]
                EXPORT  TIM1_CC_IRQHandler             [WEAK]
                EXPORT  TIM2_IRQHandler                [WEAK]
                EXPORT  TIM6_IRQHandler                [WEAK]
                EXPORT  TIM13_IRQHandler               [WEAK]
                EXPORT  TIM14_IRQHandler               [WEAK]
                EXPORT  COMP1_2_IRQHandler             [WEAK]
                EXPORT  USART1_IRQHandler              [WEAK]


IWDG_IRQHandler
PVD_IRQHandler
FLASH_IRQHandler
RCC_IRQHandler
EXTI0_1_IRQHandler
EXTI2_3_IRQHandler
EXTI4_15_IRQHandler
HWDIV_IRQHandler
DMA1_Channel1_IRQHandler
DMA1_Channel2_IRQHandler
ADC_IRQHandler
TIM1_BRK_UP_TRG_COM_IRQHandler
TIM1_CC_IRQHandler
TIM2_IRQHandler
TIM6_IRQHandler
TIM13_IRQHandler
TIM14_IRQHandler
COMP1_2_IRQHandler
USART1_IRQHandler

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap

                LDR     R0, = Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

;*******************************************************************************
; User Checksum - must be placed at the end of memory
;*******************************************************************************
                AREA    CHECKSUM, DATA, READONLY, ALIGN=6
                EXPORT  __Check_Sum

; Alignement here must correspond to the size of tested block at FLASH run time test (16 words ~ 64 bytes)!!!
                ALIGN

__Check_Sum     DCD     0x0ac4f8a8;                 ; Check sum computed externaly

                END
