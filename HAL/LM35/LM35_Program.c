/**
 * @file LM35_Program.c
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#include "LM35_Interface.h"

/* Initialize */

void LM35_Init(ADC_Channel_t Channel)
{
    if (Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_DirectionSelectForPin(DIO_GroupA, Channel, DIO_Input);
}

/* Get Temperature */

void LM35_GetTemperature(ADC_Channel_t Channel, uint8_t *Temperature)
{
    if (Temperature == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    uint16_t ADC_Value = 0;
    ADC_ReadChannelSync(Channel, &ADC_Value);

    /* Temperature (C) = (ADC_Value * Vref_mV) / (ADC_Resolution * Sensitivity_mV) */
    *Temperature = (uint8_t)(((uint32_t)ADC_Value * LM35_VREF_MV) / (LM35_ADC_RESOLUTION * LM35_SENSITIVITY_MV));
}
