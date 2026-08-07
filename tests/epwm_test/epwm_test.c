/*
created by suBardagi
*/

#include "epwm_test.h"
#include "board.h"
#include "epwm.h"
#include "inc/hw_memmap.h"
#include "stdint.h"

void EPWM_Test_Init(duty_test_t *duty)
{
    duty->pfc_duty = 0.0f;
    duty->dab_duty = 0.0f;
    duty->dab_phase = 0.0f;
}

void EPWM_Test_Run(duty_test_t *duty)
{
    
    // PFC duty 
    uint16_t pfc_period = PWM_PERIOD;
    uint16_t pfc_cmp = (uint16_t)(pfc_period*(1.0f-duty->pfc_duty));

    EPWM_setCounterCompareValue(EPWM_1_BASE, EPWM_COUNTER_COMPARE_A, pfc_cmp);

    // DAB duty
    uint16_t dab_period = EPWM_getTimeBasePeriod(EPWM_4_BASE);
    uint16_t dab_cmp = (uint16_t)(dab_period*duty->dab_duty);

    EPWM_setCounterCompareValue(EPWM_4_BASE, EPWM_COUNTER_COMPARE_A, dab_cmp);

}
