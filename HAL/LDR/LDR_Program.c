/**
 * @file    LDR_Program.c
 * @brief   Implementation of the LDR (Light Dependent Resistor) HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "LDR_Interface.h"
#include "../../Common/Definition.h"

#if Ldr_Driver

/*  Internal Helper  */

/**
 * @brief Calculates light intensity percentage from raw ADC value.
 */
static inline uint8_t LDR_CalcIntensity(uint16_t RawValue, uint8_t ConnectionType)
{
    if (RawValue > LDR_MAX_ADC_VALUE)
    {
        RawValue = LDR_MAX_ADC_VALUE;
    }

    if (ConnectionType == LDR_PULL_DOWN)
    {
        /* Voltage rises with light -> higher raw = brighter */
        return (uint8_t)(((uint32_t)RawValue * 100UL) / LDR_MAX_ADC_VALUE);
    }
    else
    {
        /* Voltage drops with light -> lower raw = brighter */
        return (uint8_t)(((uint32_t)(LDR_MAX_ADC_VALUE - RawValue) * 100UL) / LDR_MAX_ADC_VALUE);
    }
}

/*  Public API  */

void LDR_Init(const LDR_Config_t *Config)
{
    if (Config == NULL) { return; }
    if (Config->Channel > Adc_SingleEndedChannel7) { return; }

    /* ADC channels map to Port A */
    DIO_DirectionSelectForPin(DIO_GroupA, Config->Channel, DIO_Input);
}

void LDR_GetAnalogValue(const LDR_Config_t *Config, uint16_t *AnalogValue)
{
    if (Config == NULL || AnalogValue == NULL) { return; }
    if (Config->Channel > Adc_SingleEndedChannel7) { return; }

    /* Use 50,000 loop timeout for blocking ADC read */
    ADC_Read(Config->Channel, AnalogValue, 50000);
}

void LDR_GetLightIntensity(const LDR_Config_t *Config, uint8_t *Intensity)
{
    uint16_t RawValue = 0;

    if (Config == NULL || Intensity == NULL) { return; }
    if (Config->Channel > Adc_SingleEndedChannel7) { return; }
    if (Config->ConnectionType != LDR_PULL_DOWN && Config->ConnectionType != LDR_PULL_UP) { return; }

    if (ADC_Read(Config->Channel, &RawValue, 50000) == Adc_Ok)
    {
        *Intensity = LDR_CalcIntensity(RawValue, Config->ConnectionType);
    }
}

void LDR_GetLightLevel(const LDR_Config_t *Config, LDR_LightLevel_t *LightLevel)
{
    uint16_t RawValue = 0;
    uint8_t Intensity = 0;

    if (Config == NULL || LightLevel == NULL) { return; }
    if (Config->Channel > Adc_SingleEndedChannel7) { return; }
    if (Config->ConnectionType != LDR_PULL_DOWN && Config->ConnectionType != LDR_PULL_UP) { return; }

    if (ADC_Read(Config->Channel, &RawValue, 50000) == Adc_Ok)
    {
        Intensity = LDR_CalcIntensity(RawValue, Config->ConnectionType);

        if (Intensity < LDR_DARK_THRESHOLD)
        {
            *LightLevel = LDR_Dark;
        }
        else if (Intensity < LDR_DIM_THRESHOLD)
        {
            *LightLevel = LDR_Dim;
        }
        else if (Intensity < LDR_NORMAL_THRESHOLD)
        {
            *LightLevel = LDR_Normal;
        }
        else
        {
            *LightLevel = LDR_Bright;
        }
    }
}

#endif /* Ldr_Driver */
