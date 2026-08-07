/*
created by suBardagi
*/

#include "error_handler.h"
#include "board.h"
#include "device.h"
#include "gpio.h"
#include "pfc-control/pfc_control.h"
#include "sogi-pll/sogi_pll.h"

extern System_Manager_t sys_manager;
extern PFC_Control_t pfc_controller;
extern SOGI_PLL_t grid_pll;

void System_Manager_Init(void)
{
    sys_manager.current_state = STATE_INIT;
    sys_manager.global_fault_active = false;

    sys_manager.flags.can_rx_timeout = 0;
    sys_manager.flags.can_tx_error = 0;
    
    sys_manager.flags.dc_bus_ovp = 0;
    
    sys_manager.flags.grid_ovp = 0;
    sys_manager.flags.grid_uvp = 0;
    sys_manager.flags.pfc_ocp = 0;
}

void System_Manager_Update(void)
{
    if(sys_manager.flags.can_rx_timeout || sys_manager.flags.can_tx_error || sys_manager.flags.dc_bus_ovp || sys_manager.flags.pfc_ocp)
    {
        sys_manager.global_fault_active = true;
        sys_manager.current_state = STATE_FAULT;
    }

    switch(sys_manager.current_state)
    {
    case STATE_INIT:

        GPIO_writePin(AC_RELAY_DRIVE, 0);
        sys_manager.state_timer = 0;

        sys_manager.current_state = STATE_GRID_SYNCH;
        break;

    case STATE_GRID_SYNCH:

        sys_manager.state_timer++;

        if(sys_manager.state_timer> 100 && grid_pll.is_locked == 1)
        {
            sys_manager.state_timer = 0;
            sys_manager.current_state = STATE_PRECHARGE;
        }


        break;

    case STATE_PRECHARGE:

        GPIO_writePin(AC_RELAY_DRIVE, 1);
        sys_manager.state_timer++;

        if(sys_manager.state_timer > 500)
        {
            GPIO_writePin(DC_RELAY_DRIVE, 0);
            sys_manager.state_timer = 0;
            sys_manager.current_state = STATE_RUNNING;
        }        

        break;

    case STATE_RUNNING:
        
        GPIO_writePin(DC_RELAY_DRIVE, 1);

        break;

    case STATE_FAULT:

        // trip-zone denenebilir
        pfc_controller.duty_S1 = 0;
        pfc_controller.duty_S2 = 0;
        pfc_controller.duty_S3 = 0;
        pfc_controller.duty_S4 = 0;
        pfc_controller.v_dc_ref = 0;
        pfc_controller.i_ac_ref = 0;

        GPIO_writePin(AC_RELAY_DRIVE, 0);
        DEVICE_DELAY_US(50000);
        GPIO_writePin(DC_RELAY_DRIVE, 0);

        sys_manager.current_state = STATE_SHUTDOWN;
        break;

    case STATE_SHUTDOWN:

      break;
    }

}
