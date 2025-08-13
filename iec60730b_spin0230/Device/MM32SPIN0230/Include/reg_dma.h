/***********************************************************************************************************************
    @file     reg_dma.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __REG_DMA_H
#define __REG_DMA_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0.h>


/**
  * @brief DMA Base Address Definition
  */
#define DMA1_BASE                       (AHBPERIPH_BASE + 0x0000) /*!< Base Address: 0x40020000 */
#define DMA1_Channel1_BASE              (AHBPERIPH_BASE + 0x0008) /*!< Base Address: 0x40020008 */
#define DMA1_Channel2_BASE              (AHBPERIPH_BASE + 0x001C) /*!< Base Address: 0x4002001C */

/**
  * @brief DMA Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CCR;                 /*!< DMA channel x configuration register           offset: 0x00 */
    __IO uint32_t CNDTR;               /*!< DMA channel x number of data register          offset: 0x04 */
    __IO uint32_t CPAR;                /*!< DMA channel x peripheral address register      offset: 0x08 */
    __IO uint32_t CMAR;                /*!< DMA channel x memory address register          offset: 0x0C */
} DMA_Channel_TypeDef;

typedef struct
{
    __IO uint32_t ISR;                 /*!< Interrupt Status Register                      offset: 0x00 */
    __IO uint32_t IFCR;                /*!< Interrupt Flag Clear Register                  offset: 0x04 */
} DMA_TypeDef;

/**
  * @brief DMA type pointer Definition
  */
#define DMA1                            ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_Channel1                   ((DMA_Channel_TypeDef *)DMA1_Channel1_BASE)
#define DMA1_Channel2                   ((DMA_Channel_TypeDef *)DMA1_Channel2_BASE)

/**
  * @brief DMA_ISR Register Bit Definition
  */
#define DMA_ISR_GIF1_Pos                (0)
#define DMA_ISR_GIF1_Msk                (0x01U << DMA_ISR_GIF1_Pos)             /*!< Channel 1 Global interrupt flag */
#define DMA_ISR_TCIF1_Pos               (1)
#define DMA_ISR_TCIF1_Msk               (0x01U << DMA_ISR_TCIF1_Pos)            /*!< Channel 1 Transfer Complete flag */
#define DMA_ISR_HTIF1_Pos               (2)
#define DMA_ISR_HTIF1_Msk               (0x01U << DMA_ISR_HTIF1_Pos)            /*!< Channel 1 Half Transfer flag */
#define DMA_ISR_TEIF1_Pos               (3)
#define DMA_ISR_TEIF1_Msk               (0x01U << DMA_ISR_TEIF1_Pos)            /*!< Channel 1 Transfer Error flag */
#define DMA_ISR_GIF2_Pos                (4)
#define DMA_ISR_GIF2_Msk                (0x01U << DMA_ISR_GIF2_Pos)             /*!< Channel 2 Global interrupt flag */
#define DMA_ISR_TCIF2_Pos               (5)
#define DMA_ISR_TCIF2_Msk               (0x01U << DMA_ISR_TCIF2_Pos)            /*!< Channel 2 Transfer Complete flag */
#define DMA_ISR_HTIF2_Pos               (6)
#define DMA_ISR_HTIF2_Msk               (0x01U << DMA_ISR_HTIF2_Pos)            /*!< Channel 2 Half Transfer flag */
#define DMA_ISR_TEIF2_Pos               (7)
#define DMA_ISR_TEIF2_Msk               (0x01U << DMA_ISR_TEIF2_Pos)            /*!< Channel 2 Transfer Error flag */

/**
  * @brief DMA_IFCR Register Bit Definition
  */
#define DMA_IFCR_CGIF1_Pos              (0)
#define DMA_IFCR_CGIF1_Msk              (0x01U << DMA_IFCR_CGIF1_Pos)           /*!< Channel 1 Global interrupt clear */
#define DMA_IFCR_CTCIF1_Pos             (1)
#define DMA_IFCR_CTCIF1_Msk             (0x01U << DMA_IFCR_CTCIF1_Pos)          /*!< Channel 1 Transfer Complete clear */
#define DMA_IFCR_CHTIF1_Pos             (2)
#define DMA_IFCR_CHTIF1_Msk             (0x01U << DMA_IFCR_CHTIF1_Pos)          /*!< Channel 1 Half Transfer clear */
#define DMA_IFCR_CTEIF1_Pos             (3)
#define DMA_IFCR_CTEIF1_Msk             (0x01U << DMA_IFCR_CTEIF1_Pos)          /*!< Channel 1 Transfer Error clear */
#define DMA_IFCR_CGIF2_Pos              (4)
#define DMA_IFCR_CGIF2_Msk              (0x01U << DMA_IFCR_CGIF2_Pos)           /*!< Channel 2 Global interrupt clear */
#define DMA_IFCR_CTCIF2_Pos             (5)
#define DMA_IFCR_CTCIF2_Msk             (0x01U << DMA_IFCR_CTCIF2_Pos)          /*!< Channel 2 Transfer Complete clear */
#define DMA_IFCR_CHTIF2_Pos             (6)
#define DMA_IFCR_CHTIF2_Msk             (0x01U << DMA_IFCR_CHTIF2_Pos)          /*!< Channel 2 Half Transfer clear */
#define DMA_IFCR_CTEIF2_Pos             (7)
#define DMA_IFCR_CTEIF2_Msk             (0x01U << DMA_IFCR_CTEIF2_Pos)          /*!< Channel 2 Transfer Error clear */

/**
  * @brief DMA_CCR Register Bit Definition
  */
#define DMA_CCR_EN_Pos                  (0)
#define DMA_CCR_EN_Msk                  (0x01U << DMA_CCR_EN_Pos)               /*!< Channel enable */
#define DMA_CCR_TCIE_Pos                (1)
#define DMA_CCR_TCIE_Msk                (0x01U << DMA_CCR_TCIE_Pos)             /*!< Transfer complete interrupt enable */
#define DMA_CCR_HTIE_Pos                (2)
#define DMA_CCR_HTIE_Msk                (0x01U << DMA_CCR_HTIE_Pos)             /*!< Half Transfer interrupt enable */
#define DMA_CCR_TEIE_Pos                (3)
#define DMA_CCR_TEIE_Msk                (0x01U << DMA_CCR_TEIE_Pos)             /*!< Transfer error interrupt enable */
#define DMA_CCR_DIR_Pos                 (4)
#define DMA_CCR_DIR_Msk                 (0x01U << DMA_CCR_DIR_Pos)              /*!< Data transfer direction */
#define DMA_CCR_CIRC_Pos                (5)
#define DMA_CCR_CIRC_Msk                (0x01U << DMA_CCR_CIRC_Pos)             /*!< Circular mode */
#define DMA_CCR_PINC_Pos                (6)
#define DMA_CCR_PINC_Msk                (0x01U << DMA_CCR_PINC_Pos)             /*!< Peripheral increment mode */
#define DMA_CCR_MINC_Pos                (7)
#define DMA_CCR_MINC_Msk                (0x01U << DMA_CCR_MINC_Pos)             /*!< Memory increment mode */

#define DMA_CCR_PSIZE_Pos               (8)
#define DMA_CCR_PSIZE_Msk               (0x03U << DMA_CCR_PSIZE_Pos)            /*!< PSIZE[1:0] bits (Peripheral size) */
#define DMA_CCR_PSIZE_BYTE              (0x00U << DMA_CCR_PSIZE_Pos)            /*!< DMA Peripheral Data Size Byte */
#define DMA_CCR_PSIZE_HALFWORD          (0x01U << DMA_CCR_PSIZE_Pos)            /*!< DMA Peripheral Data Size HalfWord */
#define DMA_CCR_PSIZE_WORD              (0x02U << DMA_CCR_PSIZE_Pos)            /*!< DMA Peripheral Data Size Word */

#define DMA_CCR_MSIZE_Pos               (10)
#define DMA_CCR_MSIZE_Msk               (0x03U << DMA_CCR_MSIZE_Pos)            /*!< MSIZE[1:0] bits (Memory size) */
#define DMA_CCR_MSIZE_BYTE              (0x00U << DMA_CCR_MSIZE_Pos)            /*!< DMA Memory Data Size Byte */
#define DMA_CCR_MSIZE_HALFWORD          (0x01U << DMA_CCR_MSIZE_Pos)            /*!< DMA Memory Data Size HalfWord */
#define DMA_CCR_MSIZE_WORD              (0x02U << DMA_CCR_MSIZE_Pos)            /*!< DMA Memory Data Size Word */

#define DMA_CCR_PL_Pos                  (12)
#define DMA_CCR_PL_Msk                  (0x03U << DMA_CCR_PL_Pos)               /*!< PL[1:0] bits(Channel Priority level) */
#define DMA_CCR_PL_Low                  (0x00U << DMA_CCR_PL_Pos)               /*!< DMA Priority Low */
#define DMA_CCR_PL_Medium               (0x01U << DMA_CCR_PL_Pos)               /*!< DMA Priority Medium */
#define DMA_CCR_PL_High                 (0x02U << DMA_CCR_PL_Pos)               /*!< DMA Priority High */
#define DMA_CCR_PL_VeryHigh             (0x03U << DMA_CCR_PL_Pos)               /*!< DMA Priority VeryHigh */
#define DMA_CCR_MEM2MEM_Pos             (14)
#define DMA_CCR_MEM2MEM_Msk             (0x01U << DMA_CCR_MEM2MEM_Pos)          /*!< Memory to memory mode */

#define DMA_CCR_ARE_Pos                 (15)
#define DMA_CCR_ARE_Msk                 (0x01U << DMA_CCR_ARE_Pos)              /*!< Auto-Reload Enable bit */

/**
  * @brief DMA_CNDTR Register Bit Definition
  */
#define DMA_CNDTR_NDT_Pos               (0)
#define DMA_CNDTR_NDT_Msk               (0xFFFFU << DMA_CNDTR_NDT_Pos)          /*!< Number of data to Transfer */

/**
  * @brief DMA_CPAR Register Bit Definition
  */
#define DMA_CPAR_PA_Pos                 (0)
#define DMA_CPAR_PA_Msk                 (0xFFFFFFFFU << DMA_CPAR_PA_Pos)        /*!< Peripheral Address */

/**
  * @brief DMA_CMAR Register Bit Definition
  */
#define DMA_CMAR_MA_Pos                 (0)
#define DMA_CMAR_MA_Msk                 (0xFFFFFFFFU << DMA_CMAR_MA_Pos)        /*!< Peripheral Address */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/

