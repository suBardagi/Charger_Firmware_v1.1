/*
created by suBardagi
*/

#ifndef _DCDC_CONTROL_H_
#define _DCDC_CONTROL_H_

#include "stdint.h"
#include "pid/pid.h"

typedef enum
{
    CHARGE_MODE_CC = 0,
    CHARGE_MODE_CV,
    CHARGE_DONE,
}Charge_Mode_e;

typedef struct 
{
    float v_dc_ref;
    float i_dc_ref;

    float duty_S1;
    float duty_S2;
    float duty_S3;
    float duty_S4;
    float duty_S5;
    float duty_S6;
    float duty_S7;
    float duty_S8;

    PID_controller volt_pid;
    PID_controller current_pid;

    float Ts;

    Charge_Mode_e charge_mode;
    float vbat_max_limit;
    float ibat_cutoff_limit;

}DCDC_Control_t;

extern DCDC_Control_t dcdc_controller; 

void DCDC_Control_Init(DCDC_Control_t *dcdc);
void DCDC_Control_CV_Mode(DCDC_Control_t *dcdc, float i_ind_meas, float vbat_meas, float ibat_meas);
void DCDC_Control_CC_Mode(DCDC_Control_t *dcdc, float i_ind_meas, float vbat_meas, float ibat_meas);

#endif
