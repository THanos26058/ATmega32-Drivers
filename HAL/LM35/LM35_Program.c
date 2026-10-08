/**
 * @file    LM35_Program.c
 * @brief   Implementation of the LM35 Temperature Sensor HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "LM35_Interface.h"
#include "../../Common/Definition.h"

#if Lm35_Driver

/* ── Public API ──────────────────────────────────────────────────────────── */

void LM35_Init(uint8_t Channel)
{
    if (Channel > Adc_SingleEndedChannel7) { return; }

    /* LM35 output is connected to one of the ADC pins on Port A */
    DIO_DirectionSelectForPin(DIO_GroupA, Channel, DIO_Input);
}

void LM35_GetTemperature(uint8_t Channel, uint8_t *Temperature)
{
    uint16_t ADC_Value = 0;

    if (Temperature == NULL) { return; }
    if (Channel > Adc_SingleEndedChannel7) { return; }

    /* Perform a blocking read with a timeout of 50,000 loops */
    if (ADC_Read(Channel, &ADC_Value, 50000) == Adc_Ok)
    {
        /* 
         * Temperature (C) = (ADC_Value * Vref_mV) / (ADC_Resolution * Sensitivity_mV)
         * e.g., (ADC_Value * 5000) / (1024 * 10)
         */
        *Temperature = (uint8_t)(((uint32_t)ADC_Value * LM35_VREF_MV) / 
                                 (LM35_ADC_RESOLUTION * LM35_SENSITIVITY_MV));
    }
}

#endif /* Lm35_Driver */
