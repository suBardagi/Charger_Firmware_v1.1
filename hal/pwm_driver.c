/*
created by suBardagi
*/

#include "pwm_driver.h"
#include "driverlib.h"
#include "epwm.h"
#include "inc/hw_memmap.h"

void PWM_Driver_Update_PFC(PFC_Control_t *pfc)
{
    uint16_t cmpa_S1 = (uint16_t)(pfc->duty_S1 * PWM_PERIOD);
    uint16_t cmpb_S3 = (uint16_t)(pfc->duty_S3 * PWM_PERIOD);

    uint16_t cmpa_S2 = (uint16_t)(pfc->duty_S2 * PWM_PERIOD);
    uint16_t cmpb_S4 = (uint16_t)(pfc->duty_S4 * PWM_PERIOD);

    EPWM_setCounterCompareValue(EPWM6_BASE, EPWM_COUNTER_COMPARE_A, cmpa_S1);
    EPWM_setCounterCompareValue(EPWM6_BASE, EPWM_COUNTER_COMPARE_B, cmpb_S3);

    EPWM_setCounterCompareValue(EPWM5_BASE, EPWM_COUNTER_COMPARE_A, cmpa_S2);
    EPWM_setCounterCompareValue(EPWM5_BASE, EPWM_COUNTER_COMPARE_B, cmpb_S4);
}

void PWM_Driver_Update_DCDC(DCDC_Control_t *dcdc)
{
    uint16_t cmpa_S1 = (uint16_t)(dcdc->duty_S1 * PWM_PERIOD);
    uint16_t cmpa_S2 = (uint16_t)(dcdc->duty_S2 * PWM_PERIOD);
    uint16_t cmpb_S3 = (uint16_t)(dcdc->duty_S3 * PWM_PERIOD);
    uint16_t cmpb_S4 = (uint16_t)(dcdc->duty_S4 * PWM_PERIOD);

    uint16_t cmpb_S5 = (uint16_t)(dcdc->duty_S5 * PWM_PERIOD);
    uint16_t cmpa_S6 = (uint16_t)(dcdc->duty_S6 * PWM_PERIOD);
    uint16_t cmpa_S7 = (uint16_t)(dcdc->duty_S7 * PWM_PERIOD);
    uint16_t cmpb_S8 = (uint16_t)(dcdc->duty_S8 * PWM_PERIOD);

    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_A, cmpa_S1);
    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_B, cmpb_S3);
    EPWM_setCounterCompareValue(EPWM3_BASE, EPWM_COUNTER_COMPARE_A, cmpa_S2);
    EPWM_setCounterCompareValue(EPWM3_BASE, EPWM_COUNTER_COMPARE_B, cmpb_S4);

    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_B, cmpb_S5);
    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, cmpa_S6);
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, cmpa_S7);
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, cmpb_S8);
}
