/**
 * @file    LDR_Interface.h
 * @brief   Public API for the Light Dependent Resistor (LDR) sensor HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Reads analog voltage values via the ADC to determine ambient light
 *          levels. Supports both Pull-Up (LDR to GND) and Pull-Down (LDR to VCC)
 *          voltage divider configurations.
 */

#ifndef _HAL_LDR_LDR_INTERFACE_H_
#define _HAL_LDR_LDR_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Ldr_Driver

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

#include "LDR_Config.h"
#include "LDR_Private.h"


/*  Connection Type Definitions  */

#define LDR_PULL_DOWN 1 /**< LDR connected to VCC, fixed resistor to GND. */
#define LDR_PULL_UP   2 /**< LDR connected to GND, fixed resistor to VCC. */

/*  Enums & Structs  */

/**
 * @enum  LDR_LightLevel_t
 * @brief Discrete ambient light categories based on intensity percentage.
 */
typedef enum
{
    LDR_Dark = 0, /**< Almost no ambient light. */
    LDR_Dim,      /**< Low ambient light.       */
    LDR_Normal,   /**< Normal indoor lighting.  */
    LDR_Bright    /**< Strong / direct light.   */
} LDR_LightLevel_t;

/**
 * @struct LDR_Config_t
 * @brief  Configuration structure for a single LDR sensor instance.
 */
typedef struct
{
    uint8_t Channel;        /**< ADC channel number (e.g. @c Adc_SingleEndedChannel0). */
    uint8_t ConnectionType; /**< @c LDR_PULL_DOWN or @c LDR_PULL_UP.                   */
} LDR_Config_t;

/*  Functions  */

/**
 * @brief  Initialize the LDR sensor hardware pin.
 *
 * @details Sets the selected ADC channel pin's direction to Input via the
 *          DIO driver. Ensure @ref ADC_Init() is called at the system level.
 *
 * @param[in] Config Pointer to the LDR configuration struct.
 */
void LDR_Init(const LDR_Config_t *Config);

/**
 * @brief  Get the raw ADC value from the LDR's voltage divider.
 *
 * @param[in]  Config      Pointer to the LDR configuration struct.
 * @param[out] AnalogValue Pointer to store the 10-bit raw ADC value (0–1023).
 */
void LDR_GetAnalogValue(const LDR_Config_t *Config, uint16_t *AnalogValue);

/**
 * @brief  Calculate the relative light intensity (0% to 100%).
 *
 * @details Automatically compensates for Pull-Up vs. Pull-Down configurations
 *          so that 0% always means dark and 100% always means bright.
 *
 * @param[in]  Config    Pointer to the LDR configuration struct.
 * @param[out] Intensity Pointer to store the computed intensity percentage.
 */
void LDR_GetLightIntensity(const LDR_Config_t *Config, uint8_t *Intensity);

/**
 * @brief  Categorize the ambient light into a discrete @ref LDR_LightLevel_t.
 *
 * @param[in]  Config     Pointer to the LDR configuration struct.
 * @param[out] LightLevel Pointer to store the resulting discrete light category.
 */
void LDR_GetLightLevel(const LDR_Config_t *Config, LDR_LightLevel_t *LightLevel);


#endif /* Ldr_Driver */
#endif /* _HAL_LDR_LDR_INTERFACE_H_ */
