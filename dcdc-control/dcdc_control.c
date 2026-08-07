/*
created by suBardagi
*/

#include "dcdc_control.h"
#include "pid/pid.h"
#include "math.h"

void DCDC_Control_Init(DCDC_Control_t *dcdc)
{
    dcdc->v_dc_ref = 0;
    dcdc->i_dc_ref = 0;

    dcdc->duty_S1 = 0;
    dcdc->duty_S2 = 0;
    dcdc->duty_S3 = 0;
    dcdc->duty_S4 = 0;
    dcdc->duty_S5 = 0;
    dcdc->duty_S6 = 0;
    dcdc->duty_S7 = 0;
    dcdc->duty_S8 = 0;

    dcdc->Ts = 0.000005f;

    pid_init(&(dcdc->volt_pid), 0.1f, 0.1f, 0.0f, 0, 0, dcdc->Ts, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    pid_init(&(dcdc->current_pid), 0.1f, 0.1f, 0.0f, 0, 0, dcdc->Ts, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

}

void DCDC_Control_CC_Mode(DCDC_Control_t *dcdc, float i_ind_meas, float vbat_meas, float ibat_meas)
{

}

void DCDC_Control_CV_Mode(DCDC_Control_t *dcdc, float i_ind_meas, float vbat_meas, float ibat_meas)
{

}
