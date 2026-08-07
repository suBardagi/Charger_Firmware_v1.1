/*
created by suBardagi
*/

#ifndef _PWM_DRIVER_H_
#define _PWM_DRIVER_H_

#include "device.h"
#include "hal/pwm_driver.h"
#include "pfc-control/pfc_control.h"
#include "dcdc-control/dcdc_control.h"

#define PWM_PERIOD 250

void PWM_Driver_Update_PFC(PFC_Control_t *pfc);
void PWM_Driver_Update_DCDC(DCDC_Control_t *dcdc);

#endif
