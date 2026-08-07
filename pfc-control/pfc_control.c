/*
created by suBardagi
*/

#include "pfc_control.h"
#include "math.h"
#include "pid/pid.h"

void PFC_Control_Init(PFC_Control_t *pfc)
{
    pfc->v_dc_ref = 400.0f;
    pfc->i_ac_ref = 0.0f;

    pfc->duty_S1 = 0.0f;
    pfc->duty_S2 = 0.0f;
    pfc->duty_S3 = 0.0f;
    pfc->duty_S4 = 0.0f;

    pfc->Ts_fast = 0.000005f;
    pfc->Ts_slow = 0.00005f;

    pid_init(&(pfc->volt_pid), 0.1f, 1.5f, 0.0f, 1, 1, -20.0f, 20.0f, -20.0f, 20.0f, pfc->Ts_slow, 0.0f);

    pid_init(&(pfc->current_pid), 0.01599f, 693.0f, 0.0f, 1, 1, -1.0f, 1.0f, -1.0f, 1.0f, pfc->Ts_fast, 0.0f);
}

void PFC_Control_Voltage_Loop(PFC_Control_t *pfc, float v_dc_meas, float sin_theta)
{
    float i_amplitude = pid_compute(&(pfc->volt_pid), pfc->v_dc_ref, v_dc_meas);

    pfc->i_ac_ref = i_amplitude *sin_theta;
}

void PFC_Control_Current_Loop(PFC_Control_t *pfc, float i_ac_meas, uint8_t zcd)
{
    float duty_out = pid_compute(&(pfc->current_pid), pfc->i_ac_ref, i_ac_meas);

    if(zcd==1) //Slow leg
    {
        pfc->duty_S2 = 0.0f;
        pfc->duty_S4 = 1.0f;

        if(duty_out >= 0.0f)
        {
            pfc->duty_S1 = duty_out;
            pfc->duty_S3 = 1.0f - duty_out;
        }
        else
        {
            pfc->duty_S1 = 0.0f;
            pfc->duty_S3 = 1.0f;
        }
    }

    if(zcd==0)
    {
        pfc->duty_S2 = 1.0f;
        pfc->duty_S4 = 0.0f;

        float absduty = fabs(duty_out);
        
        if(duty_out >= 0.0f)
        {
            pfc->duty_S1 = absduty;
            pfc->duty_S3 = 1.0f - absduty;
        }
        else
        {
            pfc->duty_S1 = 1.0f;
            pfc->duty_S3 = 0.0f;
        }

    }
    
}
