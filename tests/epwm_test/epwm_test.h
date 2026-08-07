/*
created by suBardagi
*/

#ifndef _EPWM_TEST_H_
#define _EPWM_TEST_H_

#include "stdint.h"
#include "driverlib.h"

#define PWM_PERIOD 250

typedef struct 
{
    float pfc_duty;
    float dab_duty;
    float dab_phase;
}duty_test_t;

void EPWM_Test_Init(duty_test_t *duty);
void EPWM_Test_Run(duty_test_t *duty);

#endif
