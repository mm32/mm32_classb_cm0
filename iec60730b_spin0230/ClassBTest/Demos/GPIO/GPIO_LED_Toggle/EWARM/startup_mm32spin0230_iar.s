;/***********************************************************************************************************************
;    @file     startup_mm32SPIN0230_iar.s
;    @author   VV TEAM
;    @brief    THIS FILE PROVIDES ALL THE Device Startup File of MM32 Cortex-M
;              Core Device for IAR EWARM toolchain.
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

                MODULE  ?cstartup

                                                                                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                EXTERN  __low_level_init
                EXTERN  __iar_data_init3
                EXTERN  IEC60730_B_startup
                PUBLIC  __vector_table
                PUBLIC  __vector_table_0x1c
                PUBLIC  __Vectors
                PUBLIC  __Vectors_End
                PUBLIC  __Vectors_Size

                DATA
__vector_table
                DCD     sfe(CSTACK)                                             ;       Top of Stack
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

__Vectors       EQU     __vector_table
__Vectors_Size  EQU     __Vectors_End - __Vectors



                THUMB

; Reset Handler

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__low_level_init
                BLX     R0
                CMP     R0, #0
                BEQ.N   _call_startup
                LDR     R0, =__iar_data_init3
                BLX     R0
_call_startup:
                LDR     R0, =IEC60730_B_startup    //=__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                PUBWEAK HardFault_Handler
                PUBWEAK SVC_Handler
                PUBWEAK PendSV_Handler
                PUBWEAK SysTick_Handler
                PUBWEAK IWDG_IRQHandler
                PUBWEAK PVD_IRQHandler
                PUBWEAK FLASH_IRQHandler
                PUBWEAK RCC_IRQHandler
                PUBWEAK EXTI0_1_IRQHandler
                PUBWEAK EXTI2_3_IRQHandler
                PUBWEAK EXTI4_15_IRQHandler
                PUBWEAK HWDIV_IRQHandler
                PUBWEAK DMA1_Channel1_IRQHandler
                PUBWEAK DMA1_Channel2_IRQHandler
                PUBWEAK ADC_IRQHandler
                PUBWEAK TIM1_BRK_UP_TRG_COM_IRQHandler
                PUBWEAK TIM1_CC_IRQHandler
                PUBWEAK TIM2_IRQHandler
                PUBWEAK TIM6_IRQHandler
                PUBWEAK TIM13_IRQHandler
                PUBWEAK TIM14_IRQHandler
                PUBWEAK COMP1_2_IRQHandler
                PUBWEAK USART1_IRQHandler

                SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
HardFault_Handler
SVC_Handler
PendSV_Handler
SysTick_Handler
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

Default_Handler
                B       .
                END

