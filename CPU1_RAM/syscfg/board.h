/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// CANB -> CAN_COM Pinmux
//
//
// CANB_RX - GPIO Settings
//
#define GPIO_PIN_CANB_RX 13
#define CAN_COM_CANRX_GPIO 13
#define CAN_COM_CANRX_PIN_CONFIG GPIO_13_CANB_RX
//
// CANB_TX - GPIO Settings
//
#define GPIO_PIN_CANB_TX 12
#define CAN_COM_CANTX_GPIO 12
#define CAN_COM_CANTX_PIN_CONFIG GPIO_12_CANB_TX

//
// EPWM1 -> EPWM_1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define EPWM_1_EPWMA_GPIO 0
#define EPWM_1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define EPWM_1_EPWMB_GPIO 1
#define EPWM_1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM2 -> EPWM_2 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define EPWM_2_EPWMA_GPIO 2
#define EPWM_2_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define EPWM_2_EPWMB_GPIO 3
#define EPWM_2_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM3 -> EPWM_3 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4
#define EPWM_3_EPWMA_GPIO 4
#define EPWM_3_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5
#define EPWM_3_EPWMB_GPIO 5
#define EPWM_3_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B

//
// EPWM4 -> EPWM_4 Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 6
#define EPWM_4_EPWMA_GPIO 6
#define EPWM_4_EPWMA_PIN_CONFIG GPIO_6_EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 7
#define EPWM_4_EPWMB_GPIO 7
#define EPWM_4_EPWMB_PIN_CONFIG GPIO_7_EPWM4_B

//
// EPWM5 -> EPWM_5 Pinmux
//
//
// EPWM5_A - GPIO Settings
//
#define GPIO_PIN_EPWM5_A 8
#define EPWM_5_EPWMA_GPIO 8
#define EPWM_5_EPWMA_PIN_CONFIG GPIO_8_EPWM5_A
//
// EPWM5_B - GPIO Settings
//
#define GPIO_PIN_EPWM5_B 9
#define EPWM_5_EPWMB_GPIO 9
#define EPWM_5_EPWMB_PIN_CONFIG GPIO_9_EPWM5_B

//
// EPWM6 -> EPWM_6 Pinmux
//
//
// EPWM6_A - GPIO Settings
//
#define GPIO_PIN_EPWM6_A 10
#define EPWM_6_EPWMA_GPIO 10
#define EPWM_6_EPWMA_PIN_CONFIG GPIO_10_EPWM6_A
//
// EPWM6_B - GPIO Settings
//
#define GPIO_PIN_EPWM6_B 11
#define EPWM_6_EPWMB_GPIO 11
#define EPWM_6_EPWMB_PIN_CONFIG GPIO_11_EPWM6_B
//
// GPIO22 - GPIO Settings
//
#define DC_RELAY_DRIVE_GPIO_PIN_CONFIG GPIO_22_GPIO22
//
// GPIO23 - GPIO Settings
//
#define AC_RELAY_DRIVE_GPIO_PIN_CONFIG GPIO_23_GPIO23

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define ADCA_CHANNELS_BASE ADCA_BASE
#define ADCA_CHANNELS_RESULT_BASE ADCARESULT_BASE
#define ADCA_CHANNELS_PFC_I_SENSE ADC_SOC_NUMBER0
#define ADCA_CHANNELS_FORCE_PFC_I_SENSE ADC_FORCE_SOC0
#define ADCA_CHANNELS_SAMPLE_WINDOW_PFC_I_SENSE 200
#define ADCA_CHANNELS_TRIGGER_SOURCE_PFC_I_SENSE ADC_TRIGGER_EPWM1_SOCA
#define ADCA_CHANNELS_CHANNEL_PFC_I_SENSE ADC_CH_ADCIN0
#define ADCA_CHANNELS_PFC_V_DC_MID ADC_SOC_NUMBER1
#define ADCA_CHANNELS_FORCE_PFC_V_DC_MID ADC_FORCE_SOC1
#define ADCA_CHANNELS_SAMPLE_WINDOW_PFC_V_DC_MID 200
#define ADCA_CHANNELS_TRIGGER_SOURCE_PFC_V_DC_MID ADC_TRIGGER_EPWM1_SOCA
#define ADCA_CHANNELS_CHANNEL_PFC_V_DC_MID ADC_CH_ADCIN2
#define ADCA_CHANNELS_PFC_V_AC ADC_SOC_NUMBER2
#define ADCA_CHANNELS_FORCE_PFC_V_AC ADC_FORCE_SOC2
#define ADCA_CHANNELS_SAMPLE_WINDOW_PFC_V_AC 200
#define ADCA_CHANNELS_TRIGGER_SOURCE_PFC_V_AC ADC_TRIGGER_EPWM1_SOCA
#define ADCA_CHANNELS_CHANNEL_PFC_V_AC ADC_CH_ADCIN4
#define ADCA_CHANNELS_DAB_IND_I_SENSE ADC_SOC_NUMBER3
#define ADCA_CHANNELS_FORCE_DAB_IND_I_SENSE ADC_FORCE_SOC3
#define ADCA_CHANNELS_SAMPLE_WINDOW_DAB_IND_I_SENSE 200
#define ADCA_CHANNELS_TRIGGER_SOURCE_DAB_IND_I_SENSE ADC_TRIGGER_EPWM1_SOCA
#define ADCA_CHANNELS_CHANNEL_DAB_IND_I_SENSE ADC_CH_ADCIN10
#define ADCA_CHANNELS_DAB_I_OUT_SENSE ADC_SOC_NUMBER4
#define ADCA_CHANNELS_FORCE_DAB_I_OUT_SENSE ADC_FORCE_SOC4
#define ADCA_CHANNELS_SAMPLE_WINDOW_DAB_I_OUT_SENSE 200
#define ADCA_CHANNELS_TRIGGER_SOURCE_DAB_I_OUT_SENSE ADC_TRIGGER_EPWM1_SOCA
#define ADCA_CHANNELS_CHANNEL_DAB_I_OUT_SENSE ADC_CH_ADCIN1
#define ADCA_CHANNELS_DAB_VOUT_SENSE ADC_SOC_NUMBER5
#define ADCA_CHANNELS_FORCE_DAB_VOUT_SENSE ADC_FORCE_SOC5
#define ADCA_CHANNELS_SAMPLE_WINDOW_DAB_VOUT_SENSE 200
#define ADCA_CHANNELS_TRIGGER_SOURCE_DAB_VOUT_SENSE ADC_TRIGGER_EPWM1_SOCA
#define ADCA_CHANNELS_CHANNEL_DAB_VOUT_SENSE ADC_CH_ADCIN6
void ADCA_CHANNELS_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CAN Configurations
//
//*****************************************************************************
#define CAN_COM_BASE CANB_BASE

#define CAN_COM_MessageObj1_ID 0
#define CAN_COM_MessageObj2_ID 0
void CAN_COM_init();


//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define EPWM_1_BASE EPWM1_BASE
#define EPWM_1_TBPRD 250
#define EPWM_1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_1_TBPHS 0
#define EPWM_1_CMPA 0
#define EPWM_1_CMPB 0
#define EPWM_1_CMPC 0
#define EPWM_1_CMPD 0
#define EPWM_1_DBRED 0
#define EPWM_1_DBFED 0
#define EPWM_1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define EPWM_2_BASE EPWM2_BASE
#define EPWM_2_TBPRD 250
#define EPWM_2_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_2_TBPHS 0
#define EPWM_2_CMPA 0
#define EPWM_2_CMPB 0
#define EPWM_2_CMPC 0
#define EPWM_2_CMPD 0
#define EPWM_2_DBRED 0
#define EPWM_2_DBFED 0
#define EPWM_2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define EPWM_3_BASE EPWM3_BASE
#define EPWM_3_TBPRD 250
#define EPWM_3_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_3_TBPHS 0
#define EPWM_3_CMPA 0
#define EPWM_3_CMPB 0
#define EPWM_3_CMPC 0
#define EPWM_3_CMPD 0
#define EPWM_3_DBRED 0
#define EPWM_3_DBFED 0
#define EPWM_3_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_3_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_3_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define EPWM_4_BASE EPWM4_BASE
#define EPWM_4_TBPRD 250
#define EPWM_4_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_4_TBPHS 0
#define EPWM_4_CMPA 0
#define EPWM_4_CMPB 0
#define EPWM_4_CMPC 0
#define EPWM_4_CMPD 0
#define EPWM_4_DBRED 0
#define EPWM_4_DBFED 0
#define EPWM_4_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_4_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_4_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define EPWM_5_BASE EPWM5_BASE
#define EPWM_5_TBPRD 250
#define EPWM_5_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_5_TBPHS 0
#define EPWM_5_CMPA 0
#define EPWM_5_CMPB 0
#define EPWM_5_CMPC 0
#define EPWM_5_CMPD 0
#define EPWM_5_DBRED 0
#define EPWM_5_DBFED 0
#define EPWM_5_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_5_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_5_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define EPWM_6_BASE EPWM6_BASE
#define EPWM_6_TBPRD 250
#define EPWM_6_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define EPWM_6_TBPHS 0
#define EPWM_6_CMPA 0
#define EPWM_6_CMPB 0
#define EPWM_6_CMPC 0
#define EPWM_6_CMPD 0
#define EPWM_6_DBRED 0
#define EPWM_6_DBFED 0
#define EPWM_6_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_6_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define EPWM_6_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define DC_RELAY_DRIVE 22
void DC_RELAY_DRIVE_init();
#define AC_RELAY_DRIVE 23
void AC_RELAY_DRIVE_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_ADCA_CHANNELS_1
// ISR need to be defined for the registered interrupts
#define INT_ADCA_CHANNELS_1 INT_ADCA1
#define INT_ADCA_CHANNELS_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_ADCA_CHANNELS_1_ISR(void);

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CAN_init();
void	EPWM_init();
void	GPIO_init();
void	INTERRUPT_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
