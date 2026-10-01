/**
 * @file LDR_Program.c
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#include "LDR_Interface.h"

/* Internal helper - calculates intensity % from raw ADC value */
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

/* Initialize */

void LDR_Init(const LDR_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_DirectionSelectForPin(DIO_GroupA, Config->Channel, DIO_Input);
}

/* Get Raw ADC Value */

void LDR_GetAnalogValue(const LDR_Config_t *Config, uint16_t *AnalogValue)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (AnalogValue == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    ADC_ReadChannelSync(Config->Channel, AnalogValue);
}

/* Get Light Intensity */

void LDR_GetLightIntensity(const LDR_Config_t *Config, uint8_t *Intensity)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Intensity == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->ConnectionType != LDR_PULL_DOWN && Config->ConnectionType != LDR_PULL_UP)
    {
        // TODO: Handle Error Here;
        return;
    }

    uint16_t RawValue = 0;
    ADC_ReadChannelSync(Config->Channel, &RawValue);

    *Intensity = LDR_CalcIntensity(RawValue, Config->ConnectionType);
}

/* Get Light Level */

void LDR_GetLightLevel(const LDR_Config_t *Config, LDR_LightLevel_t *LightLevel)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (LightLevel == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->ConnectionType != LDR_PULL_DOWN && Config->ConnectionType != LDR_PULL_UP)
    {
        // TODO: Handle Error Here;
        return;
    }

    /* Single ADC read - shared with intensity calculation via helper */
    uint16_t RawValue = 0;
    ADC_ReadChannelSync(Config->Channel, &RawValue);

    uint8_t Intensity = LDR_CalcIntensity(RawValue, Config->ConnectionType);

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
