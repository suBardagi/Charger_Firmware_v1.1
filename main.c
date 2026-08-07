/*

created by suBardagi

Proceed with caution. Please?

*/


//
// Included Files
//
#include "adc.h"
#include "dcdc-control/dcdc_control.h"
#include "driver_inclusive_terminology_mapping.h"
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "error-hander/error_handler.h"
#include "gpio.h"
#include "inc/hw_memmap.h"
#include "pfc-control/pfc_control.h"
#include "tests/adc_test/adc_test.h"
#include "tests/can_test/can_test.h"
#include "tests/epwm_test/epwm_test.h"
#include "sogi-pll/sogi_pll.h"
#include "stdint.h"
#include "hal/pwm_driver.h"



MeasuredData_t measured_values;
duty_test_t pwm_control;
CAN_Test_t can_bus_tester;
SOGI_PLL_t grid_pll;
PFC_Control_t pfc_controller;
System_Manager_t sys_manager;
DCDC_Control_t dcdc_controller;

#define LOG_SIZE 120 // Ekranda görmek istediğin nokta sayısı

uint16_t log_index = 0;

#pragma DATA_SECTION(adc_volt_log, ".my_large_logs")
float adc_volt_log[LOG_SIZE];

#pragma DATA_SECTION(theta_log, ".my_large_logs")
float theta_log[LOG_SIZE];

#pragma DATA_SECTION(sin_theta_log, ".my_large_logs")
float sin_theta_log[LOG_SIZE];

#pragma DATA_SECTION(pd_error_log, ".my_large_logs")
float pd_error_log[LOG_SIZE];

uint16_t pll_decimation_counter = 0;
#define PLL_DECIMATION_FACTOR 10

__interrupt void INT_ADCA_CHANNELS_1_ISR(void) 
{

    GPIO_writePin(DC_RELAY_DRIVE, 1);

    ADC_Test_Run(&measured_values);
    EPWM_Test_Run(&pwm_control);

    // pll_decimation_counter++;
    // if(pll_decimation_counter >= PLL_DECIMATION_FACTOR)
    // {
    //     SOGI_PLL_Update(&grid_pll, measured_values.ac_input_volt);

    //     if(sys_manager.current_state == STATE_RUNNING)
    //     {
    //         PFC_Control_Voltage_Loop(&pfc_controller, measured_values.dc_bus_volt, grid_pll.sin_theta);

    //         switch(dcdc_controller.charge_mode)
    //         {
    //             case CHARGE_MODE_CC:
    //                 DCDC_Control_CC_Mode(&dcdc_controller, measured_values.dab_primary_i, measured_values.dab_output_v, measured_values.dab_output_i);

    //                 if(measured_values.dab_output_v >= dcdc_controller.vbat_max_limit)
    //                 {
    //                     dcdc_controller.charge_mode = CHARGE_MODE_CV;
    //                 }
                
    //                 break;

    //             case CHARGE_MODE_CV:
    //                 DCDC_Control_CV_Mode(&dcdc_controller, measured_values.dab_primary_i, measured_values.dab_output_v, measured_values.dab_output_i);

    //                 if(measured_values.dab_output_i <= dcdc_controller.ibat_cutoff_limit)
    //                 {
    //                     dcdc_controller.charge_mode = CHARGE_DONE;
    //                 }
                
    //                 break;

    //             case CHARGE_DONE:
                    
    //                 break;
    //         }
    //         PWM_Driver_Update_DCDC(&dcdc_controller);
            
    //     }

    //     // PFC_Control_Voltage_Loop(&pfc_controller, measured_values.dc_bus_volt, grid_pll.sin_theta);

    //     pll_decimation_counter = 0;

    //     if(sys_manager.current_state == STATE_RUNNING)
    //     {
    //         PFC_Control_Current_Loop(&pfc_controller, measured_values.pfc_current, grid_pll.zcd);
    //     }
    //     else 
    //     {
    //         pfc_controller.duty_S1 = 0.0f;
    //         pfc_controller.duty_S2 = 0.0f;
    //         pfc_controller.duty_S3 = 0.0f;
    //         pfc_controller.duty_S4 = 0.0f;
    //     }

    //     //PFC_Control_Current_Loop(&pfc_controller, measured_values.pfc_current, grid_pll.zcd);

    //     PWM_Driver_Update_PFC(&pfc_controller);

    //     pwm_control.pfc_duty = pfc_controller.duty_S1;
    //     EPWM_Test_Run(&pwm_control);
    // }
    

    pll_decimation_counter++;
    if(pll_decimation_counter >= PLL_DECIMATION_FACTOR)
    {

        //float current_vac = measured_values.ac_input_volt;

        SOGI_PLL_Update(&grid_pll, measured_values.ac_input_volt);
        
        // if(current_vac > 0.0f && prev_vac <= 0.0f)
        // {
        //     is_logging = 1;
        //     log_index = 0;
        // }
        // prev_vac = current_vac;

        // if(is_logging)
        // {
        //     log_divider++;
        //     if(log_divider >=4)
        //     {
        //         adc_volt_log[log_index] = current_vac;
        //         sin_theta_log[log_index] = grid_pll.sin_theta;

        //         log_index++;
        //         log_divider = 0;
                
        //         if(log_index >= LOG_SIZE)
        //         {
        //             is_logging = 0;
        //         }
        //     }
        // }
        
        pll_decimation_counter = 0;
    }


    //ISR içinde, duty veya ADC hesaplandıktan hemen sonra:
    adc_volt_log[log_index] = measured_values.ac_input_volt;
    theta_log[log_index] = grid_pll.theta;
    sin_theta_log[log_index] = grid_pll.sin_theta;
    pd_error_log[log_index] = grid_pll.pd_error;

    log_index++;
    if(log_index >= LOG_SIZE) 
    {
        log_index = 0; // Başa dön (Dairesel buffer)
    }
        
    
        
    

    ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
    GPIO_writePin(DC_RELAY_DRIVE, 0);

}

//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();

    ADC_Test_Init();
    PFC_Control_Init(&pfc_controller);
    EPWM_Test_Init(&pwm_control);
    //CAN_Test_Init(&can_bus_tester);

    SOGI_PLL_Init(&grid_pll, 0.0001f, 15.0f, 1500.0f, 50.0f);

    Interrupt_register(INT_ADCA1, &INT_ADCA_CHANNELS_1_ISR);
    Interrupt_enable(INT_ADCA1);

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    while(1)
    {
        // 1. Gelen CAN mesajı var mı diye sürekli kontrol et (Polling)
        //CAN_Test_Receive(&can_bus_tester);

        // 2. İşlemciyi oyalayarak 500ms'de bir mesaj gönder
        //DEVICE_DELAY_US(500000); 
        
        // Mevcut okunan DC bara voltajını gönderilecek pakete yerleştir
        //can_bus_tester.tx_msg_data[0] = (uint16_t)measured_values.dc_bus_volt; 
        
        //CAN_Test_Transmit(&can_bus_tester);

    }
}

//
// End of File
//
