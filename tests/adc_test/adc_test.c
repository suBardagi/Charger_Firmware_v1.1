/*
created by suBardagi
*/

#include "adc_test.h"
#include "adc.h"
#include "board.h"
#include "inc/hw_memmap.h"

void ADC_Test_Init(void)
{

}

void ADC_Test_Run(MeasuredData_t *data)
{
    float conv_factor = 3.3f / 4095.0f;

    data->pfc_current = ((float)ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0)*conv_factor);
    data->dc_bus_volt = ((float)ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER1)*conv_factor);
    data->ac_input_volt = ((float)ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER2)*conv_factor)-1.65f;
    data->dab_primary_i = ((float)ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER3)*conv_factor);
    data->dab_output_i = ((float)ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER4)*conv_factor);
    data->dab_output_v = ((float)ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER5)*conv_factor);

}
