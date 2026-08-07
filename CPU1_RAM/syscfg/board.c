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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	CAN_init();
	EPWM_init();
	GPIO_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// CANB -> CAN_COM Pinmux
	//
	GPIO_setPinConfig(CAN_COM_CANRX_PIN_CONFIG);
	GPIO_setPadConfig(CAN_COM_CANRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(CAN_COM_CANRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(CAN_COM_CANTX_PIN_CONFIG);
	GPIO_setPadConfig(CAN_COM_CANTX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(CAN_COM_CANTX_GPIO, GPIO_QUAL_ASYNC);

	//
	// EPWM1 -> EPWM_1 Pinmux
	//
	GPIO_setPinConfig(EPWM_1_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_1_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_1_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM_1_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_1_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_1_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM2 -> EPWM_2 Pinmux
	//
	GPIO_setPinConfig(EPWM_2_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_2_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_2_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM_2_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_2_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_2_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM3 -> EPWM_3 Pinmux
	//
	GPIO_setPinConfig(EPWM_3_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_3_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_3_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM_3_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_3_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_3_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM4 -> EPWM_4 Pinmux
	//
	GPIO_setPinConfig(EPWM_4_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_4_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_4_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM_4_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_4_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_4_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM5 -> EPWM_5 Pinmux
	//
	GPIO_setPinConfig(EPWM_5_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_5_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_5_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM_5_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_5_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_5_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM6 -> EPWM_6 Pinmux
	//
	GPIO_setPinConfig(EPWM_6_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_6_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_6_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(EPWM_6_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(EPWM_6_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(EPWM_6_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// GPIO22_VFBSW -> DC_RELAY_DRIVE Pinmux
	GPIO_setPinConfig(GPIO_22_GPIO22);
	// GPIO23_VSW -> AC_RELAY_DRIVE Pinmux
	GPIO_setPinConfig(GPIO_23_GPIO23);

}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	ADCA_CHANNELS_init();
}

void ADCA_CHANNELS_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(ADCA_CHANNELS_BASE, ADC_REFERENCE_EXTERNAL, ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(ADCA_CHANNELS_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(ADCA_CHANNELS_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(ADCA_CHANNELS_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(ADCA_CHANNELS_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(ADCA_CHANNELS_BASE, ADC_PRI_ALL_HIPRI);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 20 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN0, 20U);
	ADC_setInterruptSOCTrigger(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 20 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN2, 20U);
	ADC_setInterruptSOCTrigger(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN4
	//	 	Sample Window	: 20 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN4, 20U);
	ADC_setInterruptSOCTrigger(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN10
	//	 	Sample Window	: 20 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN10, 20U);
	ADC_setInterruptSOCTrigger(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 4 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 4
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN1
	//	 	Sample Window	: 20 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN1, 20U);
	ADC_setInterruptSOCTrigger(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 5 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 5
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 20 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER5, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN6, 20U);
	ADC_setInterruptSOCTrigger(ADCA_CHANNELS_BASE, ADC_SOC_NUMBER5, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		Source	: ADC_SOC_NUMBER5
	// 		Interrupt Source: enabled
	// 		Continuous Mode	: disabled
	//
	//
	ADC_setInterruptSource(ADCA_CHANNELS_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER5);
	ADC_clearInterruptStatus(ADCA_CHANNELS_BASE, ADC_INT_NUMBER1);
	ADC_disableContinuousMode(ADCA_CHANNELS_BASE, ADC_INT_NUMBER1);
	ADC_enableInterrupt(ADCA_CHANNELS_BASE, ADC_INT_NUMBER1);
}


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to external.
	//
	ASysCtl_setAnalogReferenceExternal( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
}

//*****************************************************************************
//
// CAN Configurations
//
//*****************************************************************************
void CAN_init(){
	CAN_COM_init();
}

void CAN_COM_init(){
	CAN_initModule(CAN_COM_BASE);
	//
	// Refer to the Driver Library User Guide for information on how to set
	// tighter timing control. Additionally, consult the device data sheet
	// for more information about the CAN module clocking.
	//
	CAN_setBitTiming(CAN_COM_BASE, 7, 0, 15, 7, 3);
	//
	// Enable CAN test mode
	//
	CAN_enableTestMode(CAN_COM_BASE, CAN_TEST_LBACK);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 1
	//      Message Identifier: 0
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_RX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 0 Bytes
	//
	CAN_setupMessageObject(CAN_COM_BASE, 1, CAN_COM_MessageObj1_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_RX, 0, 0,0);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 2
	//      Message Identifier: 0
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_RX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 0 Bytes
	//
	CAN_setupMessageObject(CAN_COM_BASE, 2, CAN_COM_MessageObj2_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_RX, 0, 0,0);
	//
	// Start CAN module operations
	//
	CAN_startModule(CAN_COM_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(EPWM_1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(EPWM_1_BASE, 250);	
    EPWM_setTimeBaseCounter(EPWM_1_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM_1_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_disablePhaseShiftLoad(EPWM_1_BASE);	
    EPWM_setPhaseShift(EPWM_1_BASE, 0);	
    EPWM_setSyncOutPulseMode(EPWM_1_BASE, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);	
    EPWM_setCounterCompareValue(EPWM_1_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM_1_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_1_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_1_BASE);	
    EPWM_enableADCTrigger(EPWM_1_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(EPWM_1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);	
    EPWM_setADCTriggerEventPrescale(EPWM_1_BASE, EPWM_SOC_A, 2);	
    EPWM_setClockPrescaler(EPWM_2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(EPWM_2_BASE, 250);	
    EPWM_setTimeBaseCounter(EPWM_2_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM_2_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(EPWM_2_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(EPWM_2_BASE);	
    EPWM_setPhaseShift(EPWM_2_BASE, 0);	
    EPWM_setSyncOutPulseMode(EPWM_2_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(EPWM_2_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM_2_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_2_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_2_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_2_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_2_BASE);	
    EPWM_setClockPrescaler(EPWM_3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(EPWM_3_BASE, 250);	
    EPWM_setTimeBaseCounter(EPWM_3_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM_3_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(EPWM_3_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(EPWM_3_BASE);	
    EPWM_setPhaseShift(EPWM_3_BASE, 0);	
    EPWM_setSyncOutPulseMode(EPWM_3_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(EPWM_3_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM_3_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_3_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_3_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_3_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_3_BASE);	
    EPWM_setClockPrescaler(EPWM_4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(EPWM_4_BASE, 250);	
    EPWM_setTimeBaseCounter(EPWM_4_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM_4_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(EPWM_4_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(EPWM_4_BASE);	
    EPWM_setPhaseShift(EPWM_4_BASE, 0);	
    EPWM_setSyncOutPulseMode(EPWM_4_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(EPWM_4_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM_4_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_4_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_4_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_4_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_4_BASE);	
    EPWM_setClockPrescaler(EPWM_5_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(EPWM_5_BASE, 250);	
    EPWM_setTimeBaseCounter(EPWM_5_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM_5_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(EPWM_5_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(EPWM_5_BASE);	
    EPWM_setPhaseShift(EPWM_5_BASE, 0);	
    EPWM_setSyncOutPulseMode(EPWM_5_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(EPWM_5_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_5_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM_5_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_5_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_5_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_5_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_5_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_5_BASE);	
    EPWM_setClockPrescaler(EPWM_6_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(EPWM_6_BASE, 250);	
    EPWM_setTimeBaseCounter(EPWM_6_BASE, 0);	
    EPWM_setTimeBaseCounterMode(EPWM_6_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(EPWM_6_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(EPWM_6_BASE);	
    EPWM_setPhaseShift(EPWM_6_BASE, 0);	
    EPWM_setSyncOutPulseMode(EPWM_6_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(EPWM_6_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_6_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(EPWM_6_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(EPWM_6_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(EPWM_6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_6_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(EPWM_6_BASE);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_6_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(EPWM_6_BASE);	
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	DC_RELAY_DRIVE_init();
	AC_RELAY_DRIVE_init();
}

void DC_RELAY_DRIVE_init(){
	GPIO_setPadConfig(DC_RELAY_DRIVE, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(DC_RELAY_DRIVE, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DC_RELAY_DRIVE, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(DC_RELAY_DRIVE, GPIO_CORE_CPU1);
}
void AC_RELAY_DRIVE_init(){
	GPIO_setPadConfig(AC_RELAY_DRIVE, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(AC_RELAY_DRIVE, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(AC_RELAY_DRIVE, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(AC_RELAY_DRIVE, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_ADCA_CHANNELS_1
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_ADCA_CHANNELS_1, &INT_ADCA_CHANNELS_1_ISR);
	Interrupt_disable(INT_ADCA_CHANNELS_1);
}
//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// For EPWM1, the sync input is: SYSCTL_SYNC_IN_SRC_EXTSYNCIN1
	//
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM4, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM7, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP1, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP4, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP6, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
