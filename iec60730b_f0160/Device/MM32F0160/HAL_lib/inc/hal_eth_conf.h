/*
 *******************************************************************************
    @file     hal_eth_conf.h
    @author   AE TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE ADC
              FIRMWARE LIBRARY.
 *******************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its
       contributors may be used to endorse or promote products derived from this
       software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES,INCLUDING, BUT NOT LIMITED TO,
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

#ifndef __HAL_ETH_CONF_H
#define __HAL_ETH_CONF_H

/* #define USE_ENHANCED_DMA_DESCRIPTORS --------------------------------------*/
/* #define CUSTOM_DRIVER_BUFFERS_CONFIG --------------------------------------*/
#define DP83848

#ifdef CUSTOM_DRIVER_BUFFERS_CONFIG
#define ETH_RX_BUF_SIZE     ETH_MAX_PACKET_SIZE
#define ETH_TX_BUF_SIZE     ETH_MAX_PACKET_SIZE
#define ETH_RX_BUF_NUM      4
#define ETH_TX_BUF_NUM      4
#endif

/*----------------------------------------------------------------------------*/
#if defined(DP83848)
#define PHY_SR                  ((uint16_t)0x10)
#define PHY_SR_LINKSTATUS       ((uint16_t)0x0001)
#define PHY_SPEED_STATUS        ((uint16_t)0x0002)
#define PHY_DUPLEX_STATUS       ((uint16_t)0x0004)

#define PHY_MICR                ((uint16_t)0x11)
#define PHY_MICR_INT_EN         ((uint16_t)0x0002)
#define PHY_MICR_INT_OE         ((uint16_t)0x0001)

#define PHY_MISR                ((uint16_t)0x12)
#define PHY_MISR_LINK_INT_EN    ((uint16_t)0x0020)
#define PHY_LINK_STATUS         ((uint16_t)0x2000)
#endif

#endif
