/**
 ******************************************************************************
 * @file    IEC60730_B_flashtest.c
 * @author
 * @version V1.2.0
 * @date    19-Jun-2019
 * @brief   Contains the functions performing run time invariable
 *          memory checks based on 32-bit CRC
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

/** @addtogroup 
 * @{
 */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
extern uint32_t App_ROM_START;
extern uint32_t App_CODE_END;
extern uint32_t App_ROM_END;
extern uint32_t App_ROM_SIZEinWORDS;
extern uint32_t App_STEPS_NUMBER;
extern uint32_t App_FLASH_BLOCK_WORDS;
extern uint32_t App_REF_CRC32;
static uint32_t crc_result;

#ifdef USE_SOFTWARE_CRC
// Software CRC32 table, Polynomial = 0x04c11db7
static const uint32_t crc32_table[256]=
{
    0x00000000, 0x04c11db7, 0x09823b6e, 0x0d4326d9, 0x130476dc, 0x17c56b6b, 0x1a864db2, 0x1e475005, 0x2608edb8,
    0x22c9f00f, 0x2f8ad6d6, 0x2b4bcb61, 0x350c9b64, 0x31cd86d3, 0x3c8ea00a, 0x384fbdbd, 0x4c11db70, 0x48d0c6c7,
    0x4593e01e, 0x4152fda9, 0x5f15adac, 0x5bd4b01b, 0x569796c2, 0x52568b75, 0x6a1936c8, 0x6ed82b7f, 0x639b0da6,
    0x675a1011, 0x791d4014, 0x7ddc5da3, 0x709f7b7a, 0x745e66cd, 0x9823b6e0, 0x9ce2ab57, 0x91a18d8e, 0x95609039,
    0x8b27c03c, 0x8fe6dd8b, 0x82a5fb52, 0x8664e6e5, 0xbe2b5b58, 0xbaea46ef, 0xb7a96036, 0xb3687d81, 0xad2f2d84,
    0xa9ee3033, 0xa4ad16ea, 0xa06c0b5d, 0xd4326d90, 0xd0f37027, 0xddb056fe, 0xd9714b49, 0xc7361b4c, 0xc3f706fb,
    0xceb42022, 0xca753d95, 0xf23a8028, 0xf6fb9d9f, 0xfbb8bb46, 0xff79a6f1, 0xe13ef6f4, 0xe5ffeb43, 0xe8bccd9a,
    0xec7dd02d, 0x34867077, 0x30476dc0, 0x3d044b19, 0x39c556ae, 0x278206ab, 0x23431b1c, 0x2e003dc5, 0x2ac12072,
    0x128e9dcf, 0x164f8078, 0x1b0ca6a1, 0x1fcdbb16, 0x018aeb13, 0x054bf6a4, 0x0808d07d, 0x0cc9cdca, 0x7897ab07,
    0x7c56b6b0, 0x71159069, 0x75d48dde, 0x6b93dddb, 0x6f52c06c, 0x6211e6b5, 0x66d0fb02, 0x5e9f46bf, 0x5a5e5b08,
    0x571d7dd1, 0x53dc6066, 0x4d9b3063, 0x495a2dd4, 0x44190b0d, 0x40d816ba, 0xaca5c697, 0xa864db20, 0xa527fdf9,
    0xa1e6e04e, 0xbfa1b04b, 0xbb60adfc, 0xb6238b25, 0xb2e29692, 0x8aad2b2f, 0x8e6c3698, 0x832f1041, 0x87ee0df6,
    0x99a95df3, 0x9d684044, 0x902b669d, 0x94ea7b2a, 0xe0b41de7, 0xe4750050, 0xe9362689, 0xedf73b3e, 0xf3b06b3b,
    0xf771768c, 0xfa325055, 0xfef34de2, 0xc6bcf05f, 0xc27dede8, 0xcf3ecb31, 0xcbffd686, 0xd5b88683, 0xd1799b34,
    0xdc3abded, 0xd8fba05a, 0x690ce0ee, 0x6dcdfd59, 0x608edb80, 0x644fc637, 0x7a089632, 0x7ec98b85, 0x738aad5c,
    0x774bb0eb, 0x4f040d56, 0x4bc510e1, 0x46863638, 0x42472b8f, 0x5c007b8a, 0x58c1663d, 0x558240e4, 0x51435d53,
    0x251d3b9e, 0x21dc2629, 0x2c9f00f0, 0x285e1d47, 0x36194d42, 0x32d850f5, 0x3f9b762c, 0x3b5a6b9b, 0x0315d626,
    0x07d4cb91, 0x0a97ed48, 0x0e56f0ff, 0x1011a0fa, 0x14d0bd4d, 0x19939b94, 0x1d528623, 0xf12f560e, 0xf5ee4bb9,
    0xf8ad6d60, 0xfc6c70d7, 0xe22b20d2, 0xe6ea3d65, 0xeba91bbc, 0xef68060b, 0xd727bbb6, 0xd3e6a601, 0xdea580d8,
    0xda649d6f, 0xc423cd6a, 0xc0e2d0dd, 0xcda1f604, 0xc960ebb3, 0xbd3e8d7e, 0xb9ff90c9, 0xb4bcb610, 0xb07daba7,
    0xae3afba2, 0xaafbe615, 0xa7b8c0cc, 0xa379dd7b, 0x9b3660c6, 0x9ff77d71, 0x92b45ba8, 0x9675461f, 0x8832161a,
    0x8cf30bad, 0x81b02d74, 0x857130c3, 0x5d8a9099, 0x594b8d2e, 0x5408abf7, 0x50c9b640, 0x4e8ee645, 0x4a4ffbf2,
    0x470cdd2b, 0x43cdc09c, 0x7b827d21, 0x7f436096, 0x7200464f, 0x76c15bf8, 0x68860bfd, 0x6c47164a, 0x61043093,
    0x65c52d24, 0x119b4be9, 0x155a565e, 0x18197087, 0x1cd86d30, 0x029f3d35, 0x065e2082, 0x0b1d065b, 0x0fdc1bec,
    0x3793a651, 0x3352bbe6, 0x3e119d3f, 0x3ad08088, 0x2497d08d, 0x2056cd3a, 0x2d15ebe3, 0x29d4f654, 0xc5a92679,
    0xc1683bce, 0xcc2b1d17, 0xc8ea00a0, 0xd6ad50a5, 0xd26c4d12, 0xdf2f6bcb, 0xdbee767c, 0xe3a1cbc1, 0xe760d676,
    0xea23f0af, 0xeee2ed18, 0xf0a5bd1d, 0xf464a0aa, 0xf9278673, 0xfde69bc4, 0x89b8fd09, 0x8d79e0be, 0x803ac667,
    0x84fbdbd0, 0x9abc8bd5, 0x9e7d9662, 0x933eb0bb, 0x97ffad0c, 0xafb010b1, 0xab710d06, 0xa6322bdf, 0xa2f33668,
    0xbcb4666d, 0xb8757bda, 0xb5365d03, 0xb1f740b4
};
#endif

/* ==============================================================================*/
/* MISRA violation of rule 10.3,11.3,11.4,17.4 - pointer arithmetic & casting is used for RAM area testing */
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pm088, Pm136, Pm140, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */
/**
 * @brief  Initializes the pointers to the Flash memory required during run-time
 * @param  : None
 * @retval : None
 */
void IEC60730_FlashCrc32Init(void)
{
    pRunCrc32Chk = (uint32_t *)App_ROM_START;
    pRunCrc32ChkInv = ((uint32_t *)(~(uint32_t)(App_ROM_START)));

#ifdef USE_HARDWARE_CRC
    RCC_AHBPeriphClockCmd(RCC_AHBENR_CRC, ENABLE);
    CRC_ResetDR();
#else
    crc_result = 0xFFFFFFFF;
#endif
    
}

#ifdef USE_SOFTWARE_CRC
/**
 * @brief  IEC60730_SoftCRC32
 * @param  : crc data register
 * @param  : data addr point
 * @param  : date length
 * @retval : crc result
 */
uint32_t IEC60730_SoftCRC32(uint32_t crc_dr, unsigned char *data, uint8_t len)
{
   uint8_t i, index;
   uint32_t crc;

   crc = crc_dr;

    for (i = 0; i < len; i++)
    {
        index = (crc >> 24) ^ (data[i] & 0xff);
        crc = crc32_table[index] ^ (crc << 8);
    }

    return crc; // don't complement crc on output
}
#endif

/**
 * @brief  IEC60730_B_FullFlash_test
 * @param  : None
 * @retval : ErrorStatus (SUCCESS, ERROR)
 */
ErrorStatus IEC60730_B_FullFlash_test(void)
{
    ErrorStatus result = SUCCESS;
    uint32_t index;

    /*--------------------------------------------------------------------------*/
    /*--------------------- Invariable memory CRC check ------------------------*/
    /*--------------------------------------------------------------------------*/
    control_flow_call(CRC32_TEST_CALLER);
    /* Compute the 32-bit crc of the whole Flash by CRC unit except the checksum
       pattern stored at top of FLASH */
    RCC_AHBPeriphClockCmd(RCC_AHBENR_CRC, ENABLE);
#ifdef USE_HARDWARE_CRC
    CRC_ResetDR();
#endif

#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
/* ==============================================================================*/
/* MISRA violation of rule 11.4, 17.4 - pointer arithmetic is used for
   CRC calculation */
#pragma diag_suppress = Pm088, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */

    /* the next lines replaces the standard HAL function call
       crc_result = HAL_CRC_Calculate(&CrcHandle, (uint32_t *)ROM_START, (uint32_t)ROM_SIZEinWORDS);
      due to bug at IAR linker - check sum computation can't support both big & little endian  */

#ifdef USE_HARDWARE_CRC
    for (index = 0; index < (uint32_t)App_ROM_SIZEinWORDS; index++)
    {
        CRC_CalcCRC(__REV(*((uint32_t *)App_ROM_START + index)));
    }
    crc_result = CRC_GetCRC();
#else
    crc_result = 0xFFFFFFFF;
    for (index = 0; index < (uint32_t)App_ROM_SIZEinWORDS; index++)
    {
        crc_result = IEC60730_SoftCRC32(crc_result, (uint8_t *)(App_ROM_START + (index * 4)), 4);
    }
#endif

/* ==============================================================================*/
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm088, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */

    control_flow_resume(CRC32_TEST_CALLER);

    /* Store pattern for regular 32-bit crc computation */
    control_flow_call(CRC_TEST_CALLER);
    /* ==============================================================================*/
    /* MISRA violation of rule 10.1, 11.3 and 11.4: integral casting and pointer arithmetic
     is used here to manage the crc computation and Check Class B var integrity */

#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_suppress = Pm129, Pm140, Pm141
  if (crc_result != (*(uint32_t *)App_REF_CRC32))
#pragma diag_default = Pm129, Pm140, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */
  /* ==============================================================================*/

#if defined(__CC_ARM) || defined(__GNUC__) /* KEIL or GCC Compiler */
                                           /* Computed 32-bit crc check is temporary stored at crc_result. This value must be copied
                                              into __Check_Sum address placed at the end of Flash area (see file startup_mm32fxx.s)
                                              Condition here can be reversed for debugging */
    if (crc_result != (*(uint32_t *)App_REF_CRC32))
#endif /* __CC_ARM */
    {
      result = ERROR;
    }
    else
    {
      /* Test OK */
      /* If else statement is not executed, it will be detected by control flow monitoring */
      control_flow_resume(CRC_TEST_CALLER);
    }

#ifdef USE_HARDWARE_CRC
    CRC_ResetDR();
#endif

    return (result);
}

/**
 * @brief  Store data and resets the CRC data register (DR)
 * @param  : None
 * @retval : None
 */
void IEC60730_B_CRC_StoreclassBData(void)
{
    control_flow_call(CRC_STORE_CALLER);
    /* restore destroyed content of HAL structure for CRC */
#ifdef USE_HARDWARE_CRC
    CRC_ResetDR();
    RefCrc32 = CRC_CalcBlockCRC(0u, 0u);
#else
    RefCrc32 = 0;
#endif
    RefCrc32Inv = ~RefCrc32;
    control_flow_resume(CRC_STORE_CALLER);
}

/**
 * @brief  Computes the crc in multiple steps and compare it with the
 *   ref value when the whole memory has been tested
 * @param  : None
 * @retval : ClassBTestStatus (TEST_RUNNING, CLASS_B_DATA_FAIL,
 *   TEST_FAILURE, TEST_OK)
 */
ClassBTestStatus IEC60730_crc32Run(void)
{
  ClassBTestStatus result = CTRL_FLW_ERROR; /* In case of abnormal func exit*/

  CtrlFlowCnt += CRC32_RUN_TEST_CALLEE;

  /* Check Class B var integrity */
  if ((((uint32_t)pRunCrc32Chk) ^ ((uint32_t)pRunCrc32ChkInv)) == 0xFFFFFFFFuL)
  {
    if (pRunCrc32Chk < (uint32_t *)App_ROM_END)
    {
      uint32_t index;
      for(index = 0; index < (uint32_t)App_FLASH_BLOCK_WORDS; index++)
      {
#ifdef USE_HARDWARE_CRC
       CRC_CalcCRC(__REV(*(pRunCrc32Chk + index)));
#else
       crc_result = IEC60730_SoftCRC32(crc_result, (uint8_t *)(pRunCrc32Chk + index), 4);
#endif
      }
      pRunCrc32Chk += App_FLASH_BLOCK_WORDS; /* Increment pointer to next block */
      pRunCrc32ChkInv = ((uint32_t *)~((uint32_t)pRunCrc32Chk));

      result = TEST_RUNNING;
    }
    else
    {
      if ((RefCrc32 ^ RefCrc32Inv) == 0xFFFFFFFFuL)
      {
        CtrlFlowCnt += CRC32_INIT_CALLER;
#ifdef USE_HARDWARE_CRC
        if (CRC_GetCRC() == (*(uint32_t *)App_REF_CRC32))
#else
        if(crc_result == (*(uint32_t *)App_REF_CRC32))
#endif
        {
          result = TEST_OK;
        }
        else
        {
          result = TEST_FAILURE;
        }
        IEC60730_FlashCrc32Init(); /* Prepare next test (or redo it if this one failed) */

        CtrlFlowCntInv -= CRC32_INIT_CALLER;
      }
      else /* Class B error on RefCrc32 */
      {
        result = CLASS_B_DATA_FAIL;
      }
    }
  }
  else /* Class B error pRunCrc32Chk */
  {
    result = CLASS_B_DATA_FAIL;
  }

  CtrlFlowCntInv -= CRC32_RUN_TEST_CALLEE;

  return (result);
}
#ifdef __IAR_SYSTEMS_ICC__ /* IAR Compiler */
#pragma diag_default = Pm088, Pm136, Pm140, Pm141
#endif /* __IAR_SYSTEMS_ICC__ */

/* ==============================================================================*/

/**
 * @}
 */
/******************* (C) COPYRIGHT Mindmotion *****END OF FILE****/
