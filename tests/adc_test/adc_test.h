/*
created by suBardagi
*/

#ifndef _ADC_TEST_H_
#define _ADC_TEST_H_

#include "stdint.h"
#include "driverlib.h"

typedef struct 
{

    float pfc_current;     // SOC0: PFC Akım Ölçümü
    float dc_bus_volt;     // SOC1: Orta Nokta / DC Barası Gerilimi
    float ac_input_volt;   // SOC2: AC Gerilim Ölçümü
    float dab_primary_i;   // SOC3: DAB İndüktör Akımı
    float dab_output_i;    // SOC4: DAB Çıkış Akımı
    float dab_output_v;    // SOC5: DAB Çıkış Gerilimi

}MeasuredData_t;

void ADC_Test_Init(void);
void ADC_Test_Run(MeasuredData_t *data);

#endif
