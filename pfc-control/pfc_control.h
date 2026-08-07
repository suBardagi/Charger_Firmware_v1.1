/*
created by suBardagi
*/

#ifndef _PFC_CONTROL_H_
#define _PFC_CONTROL_H_

#include "stdint.h"
#include "pid/pid.h"

typedef struct
{
    float v_dc_ref;
    float i_ac_ref;

    float duty_S1;
    float duty_S2;
    float duty_S3;
    float duty_S4;

    PID_controller volt_pid;
    PID_controller current_pid;

    float Ts_fast;
    float Ts_slow;
}PFC_Control_t;

extern PFC_Control_t pfc_controller;

void PFC_Control_Init(PFC_Control_t *pfc);
void PFC_Control_Voltage_Loop(PFC_Control_t *pfc, float v_dc_meas, float sin_theta);
void PFC_Control_Current_Loop(PFC_Control_t *pfc, float i_ac_meas, uint8_t zcd);

#endif
