/**
 ******************************************************************************
 * @file    IEC60730_B_transpRam.c
 * @author
 * @version V1.2.0
 * @date    19-Jun-2019
 * @brief   This module contains functions for transparent RAM functional
 *          testing March C- & X algorithms, to be done during run-time.
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

/* Includes ------------------------------------------------------------------*/
#include "IEC60730_B_lib.h"
extern uint32_t RAMRunTimetest_start;
extern uint32_t RAMRunTimetest_end;
extern uint32_t RAM_endadd_run;

/** @addtogroup
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Initializes the pointer to the RAM for the run-time
 *   transparent functional test.
 * @param  : None
 * @retval : None
 */
void IEC60730_B_TranspMarchInit(void)
{
  /* start address of the test has to be aligned to 16 address range */
  Ramtest_config();
  pRunTimeRamChk = (uint32_t *)((uint32_t)RAMRunTimetest_start & 0xFFFFFFFCuL);
  pRunTimeRamChkInv = (uint32_t *)(uint32_t)(~(uint32_t)pRunTimeRamChk);
}

/**
 * @brief  This function verifies that 6 words of RAM are functional,
 *   overlapping) using the March C- or March X algorithm.
 * @param  :
 * @retval : ClassBTestStatus (TEST_RUNNING, CLASS_B_DATA_FAIL,
 *   TEST_FAILURE, TEST_OK)
 */
ClassBTestStatus IEC60730_B_TranspMarch(uint32_t startadd, uint32_t endadd, uint32_t MCU_endadd)
{
  ClassBTestStatus result = TEST_RUNNING;
  uint32_t RAMTest_start_run = startadd;
  uint32_t RAMTest_end_run = endadd;
  uint32_t MCU_endadd_run = MCU_endadd;

  /* Check Class B var integrity */
  if ((((uint32_t)pRunTimeRamChk) ^ ((uint32_t)pRunTimeRamChkInv)) == 0xFFFFFFFFuL)
  {
    if (pRunTimeRamChk >= (uint32_t *)RAMTest_end_run)
    {
      /*------------- March test applied on the RAM Buffer itself --------------- */
      if (IEC60730_B_TranspRamMarchCXStep(&aRunTimeRamBuf[0], &aRunTimeRamBuf[0], BCKGRND) == MARCH_STEP_SUCCESS)
      {
        /* All the RAM test is completed successfully */
        result = TEST_OK;
      }
      else /* Buffer is not functional */
      {
        result = TEST_FAILURE;
      }
      /* Init next cycle of the transparent RAM test starting from the begin of the Class B area */
      pRunTimeRamChk = (uint32_t *)RAMTest_start_run;
      pRunTimeRamChkInv = ((uint32_t *)~((uint32_t)RAMTest_start_run));
    }
    else
    {
      if (pRunTimeRamChk >= ((uint32_t *)(MCU_endadd_run - 15)))
      {

        pRunTimeRamChk = ((uint32_t *)(MCU_endadd_run - 19));
      }
      /* ------------- March test applied on Class B data area ------------------ */
      /* !!! Application has to ensure that no write or read operation
               is performed within Class B RAM area during this test !!!      */
      if (IEC60730_B_TranspRamMarchCXStep(pRunTimeRamChk, &aRunTimeRamBuf[1], BCKGRND) == MARCH_STEP_SUCCESS)
      {
        if (pRunTimeRamChk == ((uint32_t *)(MCU_endadd_run - 19)))
        {
          pRunTimeRamChk = (uint32_t *)(MCU_endadd_run - 15);
        }
        /* Prepare next Row Transparent RAM test */
        pRunTimeRamChk += RT_RAM_BLOCKSIZE - (2u * RT_RAM_BLOCK_OVERLAP);
        pRunTimeRamChkInv = (uint32_t *)(uint32_t)(~(uint32_t)pRunTimeRamChk);
      }
      else
      {
        result = TEST_FAILURE; /* Word line under test was not functional */
      }
    }
  }
  else /* Class B error on pRunTimeRamChk */
  {
    result = CLASS_B_DATA_FAIL;
  }
  return (result);
}


/**
 * @}
 */

/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
