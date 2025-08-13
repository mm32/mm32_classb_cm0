////////////////////////////////////////////////////////////////////////////////
/// @file     SYSTEM_MM32.C
/// @author   AE TEAM
/// @brief    THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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
#define _SYSTEM_MM32_C_

// Files includes

/// @addtogroup CMSIS
/// @{

#include "mm32_device.h"
#include "system_mm32spin0280.h"

/// @}

/// @}

/// Uncomment the line corresponding to the desired System clock (SYSCLK)
/// frequency (after reset the HSI is used as SYSCLK source)
///
/// IMPORTANT NOTE:
/// ==============
/// 1. After each device reset the HSI is used as System clock source.
///
/// 2. Please make sure that the selected System clock doesn't exceed your device's
/// maximum frequency.
///
/// 3. If none of the define below is enabled, the HSI is used as System clock
/// source.
///
/// 4. The System clock configuration functions provided within this file assume that:
/// - For Low, Medium and High density Value line devices an external 8MHz
/// crystal is used to drive the System clock.
/// - For Low, Medium and High density devices an external 8MHz crystal is
/// used to drive the System clock.
/// - For Connectivity line devices an external 25MHz crystal is used to drive
/// the System clock.
/// If you are using different crystal you have to adapt those functions accordingly.

//refer the CUSTOM_HSE_FREQ value must match HSE_VALUE is define in reg_common.h
//customer define value
//start {
//#define CUSTOM_HSE_FREQ                    8000000                 //!!! if MCU has not HSE, must comment this line or set CUSTOM_HSE_FREQ as 0

#if (defined(CUSTOM_HSE_FREQ)) && (CUSTOM_HSE_FREQ != 0)
//#define CUSTOM_SYSCLK_FREQ               120000000//(CUSTOM_HSE_FREQ*1)      //  8000000 based CUSTOM_HSE_FREQ = 8000000 *  1  =   8000000
//#define CUSTOM_SYSCLK_FREQ               (CUSTOM_HSE_FREQ*3)      // 24000000 based CUSTOM_HSE_FREQ = 8000000 *  3  =  24000000
//#define CUSTOM_SYSCLK_FREQ               (CUSTOM_HSE_FREQ*9/2)    // 36000000 based CUSTOM_HSE_FREQ = 8000000 * 9/2 =  36000000
#define CUSTOM_SYSCLK_FREQ               (CUSTOM_HSE_FREQ*12)     // 96000000 based CUSTOM_HSE_FREQ = 8000000 * 12  =  96000000

#else
// no define CUSTOM_HSE_FREQ or set CUSTOM_HSE_FREQ = 0
//#define CUSTOM_SYSCLK_FREQ               (HSI_SYSCLKSRC_VALUE*1)            //  8000000 based HSI_SYSCLKSRC_VALUE       = 8000000 *  1  =   8000000
//#define CUSTOM_SYSCLK_FREQ               (HSI_SYSCLKSRC_VALUE*3)            // 24000000 based HSI_SYSCLKSRC_VALUE       = 8000000 *  3  =  24000000
//#define CUSTOM_SYSCLK_FREQ               (HSI_SYSCLKSRC_VALUE*9/2)          // 36000000 based HSI_SYSCLKSRC_VALUE       = 8000000 * 9/2 =  36000000
#define CUSTOM_SYSCLK_FREQ               (HSI_SYSCLKSRC_VALUE*12)           // 96000000 based HSI_SYSCLKSRC_VALUE       = 8000000 * 12  =  96000000
#endif
// } end
//  ---------------------------- Sample 1  -----------------------------
// use HSE + PLL
// use HSE/2 + PLL
// use HSE direct as SYSCLK
// use HSI + PLL
// use HSI direct as SYSCLK

#define FLASH_ACR_LATENCY_FREQ_VALUE     24000000

#define MIN_HSE_FREQ_VALUE                2000000
#define MAX_HSE_FREQ_VALUE               24000000

#define MAX_SYSCLK_FREQ_VALUE            96000000

#if defined(CUSTOM_HSE_FREQ) && (CUSTOM_HSE_FREQ>0)

#if (CUSTOM_HSE_FREQ<MIN_HSE_FREQ_VALUE)
#error "External Frequency to low"

#elif (CUSTOM_HSE_FREQ>MAX_HSE_FREQ_VALUE)
#error "External Frequency to high"
#elif (CUSTOM_HSE_FREQ != HSE_VALUE)

#error "Must redefine HSE_VALUE in reg_common.h to be equal real Ext HSE Freq(CUSTOM_HSE_FREQ)"
//HSE_VALUE is in reg_common.h Line 48, HSE_VALUE == CUSTOM_HSE_FREQ  then will move this error

#else

#if (CUSTOM_HSE_FREQ==CUSTOM_SYSCLK_FREQ)
#define SYSCLK_FREQ_USING_HSE_ONLY
#warning "Use External HSE as clock source directly,this message can be moved by comment this line"
#else
#define SYSCLK_FREQ_USING_HSE_WITH_PLL
#endif

#endif

#elif !defined(CUSTOM_HSE_FREQ) || (CUSTOM_HSE_FREQ==0)

#if (HSI_SYSCLKSRC_VALUE!=CUSTOM_SYSCLK_FREQ)
#define SYSCLK_FREQ_USING_HSI_WITH_PLL
#else
#define SYSCLK_FREQ_USING_HSI_ONLY
#warning "Use External HSI as clock source directly, this message can be moved by comment this line"
#endif

#else
#error "defined CUSTOM_SYSCLK_FREQ is wrong"
#endif

#if (CUSTOM_SYSCLK_FREQ>MAX_SYSCLK_FREQ_VALUE)
#error "CUSTOM_SYSCLK_FREQ value is too high, must be under or equal Max Frequence "
#endif

/// @}

///////////////////////////////////////////////////////////////
///Clock Definitions
///////////////////////////////////////////////////////////////

u32 SystemCoreClock         = CUSTOM_SYSCLK_FREQ;

__I u8 AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

/// @}
void SystemCoreClockUpdate (void);

static void SetSysClock(void);

#if defined(SYSCLK_FREQ_USING_HSE_ONLY)
static s32 SetSysClockToHseOnly(void);
#elif defined(SYSCLK_FREQ_USING_HSE_WITH_PLL)
static s32 SetSysClockWithHsePLL(void);
#elif defined(SYSCLK_FREQ_USING_HSI_WITH_PLL)
static s32 SetSysClockWithHsiPLL(void);
#endif

#if defined(SYSCLK_FREQ_USING_HSE_WITH_PLL) || defined(SYSCLK_FREQ_USING_HSI_WITH_PLL) || defined(SYSCLK_FREQ_USING_HSE_ONLY)
////////////////////////////////////////////////////////////////////////////////
/// @brief  Set the count as delay counter, it is break until counter goes to 0.
/// @note   None.
/// @param  count specifies the delay tick number
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
static void delay_x_cycle(u32 count)
{
    vu32 i = 0, j = 0;
    vu32 sDelayNopNumber = 100;
    for(i = 0; i < count; i++) {
        for(j = 0; j < sDelayNopNumber; j++) {
            __NOP(); //
        }
    }
}
#endif
/// @brief  Setup the microcontroller system clock to HSI
/// @param  None
/// @retval None

static void SetSysClockToDefaultHSI(void)
{
    //Reset the RCC clock configuration to the default reset state(for debug purpose)
    //Set HSION bit
    RCC->CR |= (u32)RCC_CR_HSION;

    //Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits
    RCC->CFGR &= (u32)0xF8FFC00C;

    //Reset HSEON, CSSON and PLLON bits
    RCC->CR &= (u32)0xFEF6FFFF;

    //Reset HSEBYP bit
    RCC->CR &= (u32)0xFFFBFFFF;
    //Reset USBPRE/OTGFSPRE bits
    RCC->CFGR &= (u32)0xFF3CFFFF;
    //Reset RCC_CR_PLLON
    RCC->CR &= (u32)0x008FFFFF;
    //Reset PLLSRC, PLLXTPRE, PLL_DP, PLL_DN
    RCC->PLLCFGR &= ~((u32)(RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLXTPRE | RCC_PLLCFGR_PLL_DP | RCC_PLLCFGR_PLL_DN));

    //Disable all interrupts and clear pending bits
    RCC->CIR = 0x009F0000;
}

/// @brief  Setup the microcontroller system
///         Initialize the Embedded Flash Interface, the PLL and update the
///         SystemCoreClock variable.
/// @note   This function should be used only after reset.
/// @param  None
/// @retval None

void SystemInit (void)
{
    //Reset the RCC clock configuration to the default reset state(for debug purpose)
    SetSysClockToDefaultHSI();
    //Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers
    //Configure the Flash Latency cycles and enable prefetch buffer
    SetSysClock();
}

/// @brief  use to return the pllm&plln.
/// @param  pllclkSourceFrq : PLL source clock frquency;
///         pllclkFrq : Target PLL clock frquency;
///         plln : PLL factor PLLN
///         pllm : PLL factor PLLM
/// @retval amount of error
u32 AutoCalPllFactor(u32 pllclkSourceFrq, u32 pllclkFrq, u32* plln, u32* pllm)
{
    u32 n, m;
    u32 tempFrq;
    u32 minDiff = pllclkFrq;
    u8  flag = 0;

    for(m = 0; m <= ((RCC_PLLCFGR_PLL_DP) >> RCC_PLLCFGR_PLL_DP_Pos) ; m++) {
        for(n = 0; n <= (((u32)RCC_PLLCFGR_PLL_DN) >> RCC_PLLCFGR_PLL_DN_Pos) ; n++) {
            tempFrq =  pllclkSourceFrq * (n + 1) / (m + 1);
            tempFrq = (tempFrq >  pllclkFrq) ? (tempFrq - pllclkFrq) : (pllclkFrq - tempFrq) ;

            if(minDiff > tempFrq) {
                minDiff =  tempFrq;
                *plln = n;
                *pllm = m;
            }
            if(minDiff == 0) {
                flag = 1;
                break;
            }
        }
        if(flag != 0) {
            break;
        }
    }
    return  minDiff;
}

/// @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
/// @param  None
/// @retval None

static void SetSysClock(void)
{

#if defined(SYSCLK_FREQ_USING_HSE_ONLY)
    SetSysClockToHseOnly();
#elif defined(SYSCLK_FREQ_USING_HSE_WITH_PLL)
    SetSysClockWithHsePLL();
#elif defined(SYSCLK_FREQ_USING_HSI_WITH_PLL)
    SetSysClockWithHsiPLL();
#elif defined(SYSCLK_FREQ_USING_HSI_ONLY)
    //If none of the define above is enabled, the HSI is used as System clock
    //source (default after reset)
#else
#error "clock config error"
#endif

}

////////////////////////////////////////////////////////////////////////////////
/// @brief  System Core Clock update function
///         caculate the system clock frequency best different setting and check.
/// @param  None.
/// @retval None
////////////////////////////////////////////////////////////////////////////////
void SystemCoreClockUpdate (void)
{

    u32 result, temp;
    u32 clock, mul, div;
    temp = (RCC->CFGR & RCC_CFGR_SWS);
    if(temp == RCC_CFGR_SWS_HSE) {
        result = HSE_VALUE;
    }
    else if(temp == RCC_CFGR_SWS_PLL) {
        clock = READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC) ? (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLXTPRE) ? (HSE_VALUE >> 1) : HSE_VALUE)
                : HSI_PLLSRC_VALUE;
        mul = ((RCC->PLLCFGR & (u32)RCC_PLLCFGR_PLL_DN) >> RCC_PLLCFGR_PLL_DN_Pos) + 1;
        div = ((RCC->PLLCFGR & RCC_PLLCFGR_PLL_DP) >> RCC_PLLCFGR_PLL_DP_Pos) + 1;
        result = clock * mul / div;
    }
    else if(temp == RCC_CFGR_SWS_LSI) {
        result = LSI_VALUE;
    }
    else {
        result =  HSI_SYSCLKSRC_VALUE;
    }
    SystemCoreClock = result; //update System clock frequency
//    if(CUSTOM_SYSCLK_FREQ!=SystemCoreClock)
//    {
//        while(1){
//            __NOP();
//        };
//    }
}

#if defined(SYSCLK_FREQ_USING_HSE_ONLY)

/// @brief  Selects HSE as System clock source and configure HCLK, PCLK2
///         and PCLK1 prescalers.
/// @note   This function should be used only after reset.
/// @param  None
/// @retval None

static s32 SetSysClockToHseOnly(void)
{
    u32 temp;
    vu32 StartUpCounter = 0;
    s32 HSEStatus = 0;

    RCC->CR |= RCC_CR_HSION;
    while(!(RCC->CR & RCC_CR_HSIRDY));

    //SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------
    //Enable HSE
    RCC->CR |= ((u32)RCC_CR_HSEON);

    delay_x_cycle(5);

    //Wait till HSE is ready and if Time out is reached exit
    while(1) {
        temp = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
        if(StartUpCounter < (3 * HSE_STARTUP_TIMEOUT))
            continue;
        if(temp != 0) {
            break;
        }
        if(StartUpCounter >= (10 * HSE_STARTUP_TIMEOUT)) {
            //timeout
            SetSysClockToDefaultHSI();
            HSEStatus = 0x02;
            return HSEStatus;
        }
    }
    delay_x_cycle(5);
    if ((RCC->CR & RCC_CR_HSERDY) == RESET) {
        //If HSE fails to start-up, the application will have wrong clock
        //configuration. User can add here some code to deal with this error
        HSEStatus = (u32)0x03;
        return HSEStatus;
    }

    HSEStatus = 0x00;

    //Enable Prefetch Buffer
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    //Flash 0 wait state ,bit0~2
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    //HCLK = SYSCLK
    RCC->CFGR |= (u32)RCC_CFGR_HPRE_DIV1;

    //PCLK2 = HCLK
    RCC->CFGR |= (u32)RCC_CFGR_PPRE2_DIV1;

    //PCLK1 = HCLK
    RCC->CFGR |= (u32)RCC_CFGR_PPRE1_DIV1;

    //Select HSE as system clock source
    RCC->CFGR &= (u32)((u32)~(RCC_CFGR_SW));
    RCC->CFGR |= (u32)RCC_CFGR_SW_HSE;

    //Wait till HSE is used as system clock source
    while ((RCC->CFGR & (u32)RCC_CFGR_SWS) != (u32)0x04) {
    }

    return HSEStatus;
}

#elif defined(SYSCLK_FREQ_USING_HSE_WITH_PLL)
/// @brief  Sets System clock frequency to XXMHz and configure HCLK, PCLK2
///         and PCLK1 prescalers.
/// @note   This function should be used only after reset.
/// @param  None
/// @retval None
static s32 SetSysClockWithHsePLL(void)
{
    u32 temp;
    u32 plln, pllm, tn, tm;
    u32 StartUpCounter = 0;
    s32 HSEStatus = 0;

    RCC->CR |= RCC_CR_HSION;
    while(!(RCC->CR & RCC_CR_HSIRDY));

    //PLL SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------
    //Enable HSE
    RCC->CR |= ((u32)RCC_CR_HSEON);

    delay_x_cycle(5);

    //Wait till HSE is ready and if Time out is reached exit
    while(1) {
        temp = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
        if(StartUpCounter < (3 * HSE_STARTUP_TIMEOUT))
            continue;
        if(temp != 0) {
            break;
        }
        if(StartUpCounter >= (10 * HSE_STARTUP_TIMEOUT)) {
            //timeout
            SetSysClockToDefaultHSI();
            HSEStatus = 0x02;
            return HSEStatus;
        }
    }
    delay_x_cycle(5);
    if ((RCC->CR & RCC_CR_HSERDY) == RESET) {
        //If HSE fails to start-up, the application will have wrong clock
        //configuration. User can add here some code to deal with this error
        HSEStatus = (u32)0x03;
        return HSEStatus;
    }

    HSEStatus = 0x00;

    SystemCoreClock         = CUSTOM_SYSCLK_FREQ;
    //Enable Prefetch Buffer
    FLASH->ACR |= FLASH_ACR_PRFTBE;
    //Flash 0 wait state ,bit0~2
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    temp = (CUSTOM_SYSCLK_FREQ - 1) / FLASH_ACR_LATENCY_FREQ_VALUE;

    FLASH->ACR |= (temp & FLASH_ACR_LATENCY);

    //config AHB div
    RCC->CFGR &= (~RCC_CFGR_HPRE);
    //HCLK = AHB = FCLK = SYSCLK divided by 4
    RCC->CFGR |= (u32)RCC_CFGR_HPRE_DIV4;

    //config APB2 div, APB2 is high APB CLK
    RCC->CFGR &= ( ~RCC_CFGR_PPRE2);
    //PCLK2 = APB2 = HCLK divided by 1
    RCC->CFGR |= (u32)RCC_CFGR_PPRE2_DIV1;
    ////config APB1 div, APB1 is low APB CLK
    RCC->CFGR &= ( ~RCC_CFGR_PPRE1);
    if(SystemCoreClock >= 96000000) {
        //PCLK1 = APB1 = HCLK divided by 4
        RCC->CFGR |= (u32)RCC_CFGR_PPRE1_DIV4;
    }
    else if(SystemCoreClock >= 48000000) {
        //PCLK1 = APB1 = HCLK divided by 2, APB1 is low APB CLK
        RCC->CFGR |= (u32)RCC_CFGR_PPRE1_DIV2;
    }
    temp = HSE_VALUE;
    AutoCalPllFactor(temp, CUSTOM_SYSCLK_FREQ, &plln, &pllm);

    RCC->CR &= ~((u32)RCC_CR_PLLON );
    RCC->PLLCFGR &= ~((u32 ) RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLXTPRE) ;

    RCC->PLLCFGR |= (u32 ) RCC_PLLCFGR_PLLSRC  ;

    tm = (((u32)pllm << RCC_PLLCFGR_PLL_DP_Pos) & RCC_PLLCFGR_PLL_DP);
    tn = (((u32)plln << RCC_PLLCFGR_PLL_DN_Pos) & RCC_PLLCFGR_PLL_DN);
    RCC->PLLCFGR &= (u32)((~RCC_PLLCFGR_PLL_DN) & (~RCC_PLLCFGR_PLL_DP));
    RCC->PLLCFGR |= tn | tm;
    RCC->PLLCFGR &= ~((u32 ) RCC_PLLCFGR_PLL_ICTRL) ;
    RCC->PLLCFGR |= (u32 ) RCC_PLLCFGR_PLL_ICTRL_3;
    //Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    //Wait till PLL is ready
    while((RCC->CR & RCC_CR_PLLRDY) == 0) {
        __NOP();//__ASM ("nop") ;//
    }
    //Select PLL as system clock source
    RCC->CFGR &= (u32)((u32)~(RCC_CFGR_SW));
    RCC->CFGR |= (u32)RCC_CFGR_SW_PLL;

    //Wait till PLL is used as system clock source
    while ((RCC->CFGR & (u32)RCC_CFGR_SWS) != (u32)RCC_CFGR_SWS_PLL) {
        __NOP();//__ASM ("nop") ;//
    }

    delay_x_cycle(1);
    // set HCLK = AHB = FCLK = SYSCLK divided by 2
    RCC->CFGR &= (~(RCC_CFGR_PPRE_0));
    delay_x_cycle(1);

    // set HCLK = AHB = FCLK = SYSCLK divided by 1
    RCC->CFGR &= (~(RCC_CFGR_PPRE_3));

    delay_x_cycle(1);
    return HSEStatus;
}

#elif defined(SYSCLK_FREQ_USING_HSI_WITH_PLL)

static s32 SetSysClockWithHsiPLL(void)
{
    vu32 temp, tn, tm;
    u32 plln, pllm;
    s32 HSEStatus = 0;

    RCC->CR |= RCC_CR_HSION;
    while(!(RCC->CR & RCC_CR_HSIRDY));


    SystemCoreClock         = CUSTOM_SYSCLK_FREQ;
    //Enable Prefetch Buffer
    FLASH->ACR |= FLASH_ACR_PRFTBE;
    //Flash 0 wait state ,bit0~2
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    temp = (CUSTOM_SYSCLK_FREQ - 1) / FLASH_ACR_LATENCY_FREQ_VALUE;

    FLASH->ACR |= (temp & FLASH_ACR_LATENCY);

    //config AHB div
    RCC->CFGR &= (~RCC_CFGR_HPRE);
    //HCLK = AHB = FCLK = SYSCLK divided by 4
    RCC->CFGR |= (u32)RCC_CFGR_HPRE_DIV4;

    //config APB2 div, APB2 is high APB CLK
    RCC->CFGR &= ( ~RCC_CFGR_PPRE2);
    //PCLK2 = APB2 = HCLK divided by 1
    RCC->CFGR |= (u32)RCC_CFGR_PPRE2_DIV1;
    ////config APB1 div, APB1 is low APB CLK
    RCC->CFGR &= ( ~RCC_CFGR_PPRE1);
    if(SystemCoreClock >= 96000000) {
        //PCLK1 = APB1 = HCLK divided by 4
        RCC->CFGR |= (u32)RCC_CFGR_PPRE1_DIV4;
    }
    else if(SystemCoreClock >= 48000000) {
        //PCLK1 = APB1 = HCLK divided by 2, APB1 is low APB CLK
        RCC->CFGR |= (u32)RCC_CFGR_PPRE1_DIV2;
    }
    temp = HSI_PLLSRC_VALUE;
    AutoCalPllFactor(temp, CUSTOM_SYSCLK_FREQ, &plln, &pllm);

    RCC->CR &= ~((u32)RCC_CR_PLLON );
    RCC->PLLCFGR &= ~((u32 ) RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLXTPRE) ;

    tm = (((u32)pllm << RCC_PLLCFGR_PLL_DP_Pos) & RCC_PLLCFGR_PLL_DP);
    tn = (((u32)plln << RCC_PLLCFGR_PLL_DN_Pos) & RCC_PLLCFGR_PLL_DN);
    RCC->PLLCFGR &= (u32)((~RCC_PLLCFGR_PLL_DN) & (~RCC_PLLCFGR_PLL_DP));
    RCC->PLLCFGR |= tn | tm;

    RCC->PLLCFGR &= ~((u32 ) RCC_PLLCFGR_PLL_ICTRL) ;
    RCC->PLLCFGR |= (u32 ) RCC_PLLCFGR_PLL_ICTRL_3;
    //Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    //Wait till PLL is ready
    while((RCC->CR & RCC_CR_PLLRDY) == 0) {
        __NOP();//__ASM ("nop") ;//
    }
    //Select PLL as system clock source
    RCC->CFGR &= (u32)((u32)~(RCC_CFGR_SW));
    RCC->CFGR |= (u32)RCC_CFGR_SW_PLL;

    //Wait till PLL is used as system clock source
    while ((RCC->CFGR & (u32)RCC_CFGR_SWS) != (u32)RCC_CFGR_SWS_PLL) {
        __NOP();//__ASM ("nop") ;//
    }

    delay_x_cycle(1);
    // set HCLK = AHB = FCLK = SYSCLK divided by 2
    RCC->CFGR &= (~(RCC_CFGR_PPRE_0));
    delay_x_cycle(1);

    // set HCLK = AHB = FCLK = SYSCLK divided by 1
    RCC->CFGR &= (~(RCC_CFGR_PPRE_3));

    delay_x_cycle(1);
    return HSEStatus;

}
#endif

/// @}

/// @}

/// @}

