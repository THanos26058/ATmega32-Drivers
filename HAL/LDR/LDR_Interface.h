/**
 * @file LDR_Interface.h
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#ifndef _HAL_LDR_LDR_INTERFACE_H_
#define _HAL_LDR_LDR_INTERFACE_H_

#include <stdint.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

#include "LDR_Config.h"
#include "LDR_Private.h"

/* Connection Type */
#define LDR_PULL_DOWN             1   // LDR to VCC, Fixed Resistor to GND
#define LDR_PULL_UP               2   // LDR to GND, Fixed Resistor to VCC

typedef enum
{
    LDR_Dark = 0,
    LDR_Dim,
    LDR_Normal,
    LDR_Bright
} LDR_LightLevel_t;

typedef struct
{
    ADC_Channel_t Channel;      // ADC channel (ADC_Channel0 .. ADC_Channel7)
    uint8_t       ConnectionType; // LDR_PULL_DOWN or LDR_PULL_UP
} LDR_Config_t;

/* Initialize LDR Sensor */
void LDR_Init(const LDR_Config_t *Config);

/* Get Raw ADC Value (0 - 1023) */
void LDR_GetAnalogValue(const LDR_Config_t *Config, uint16_t *AnalogValue);

/* Get Light Intensity (0% - 100%) */
void LDR_GetLightIntensity(const LDR_Config_t *Config, uint8_t *Intensity);

/* Get Discrete Light Category */
void LDR_GetLightLevel(const LDR_Config_t *Config, LDR_LightLevel_t *LightLevel);

#endif // _HAL_LDR_LDR_INTERFACE_H_
