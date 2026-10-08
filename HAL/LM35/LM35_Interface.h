/**
 * @file    LM35_Interface.h
 * @brief   Public API for the LM35 Temperature Sensor HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Reads the analog voltage from an LM35 sensor via the ADC and
 *          converts it into a Celsius temperature value (10mV / degree C).
 */

#ifndef _HAL_LM35_LM35_INTERFACE_H_
#define _HAL_LM35_LM35_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Lm35_Driver

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

#include "LM35_Config.h"
#include "LM35_Private.h"

/**
 * @defgroup LM35_API LM35 Sensor Driver Public API
 * @{
 */

/**
 * @brief  Initialize the LM35 sensor pin as an ADC input.
 *
 * @details Sets the corresponding PORTA pin to Input. @ref ADC_Init() must
 *          be called separately at the system level.
 *
 * @param[in] Channel ADC channel (e.g., @c Adc_SingleEndedChannel0).
 */
void LM35_Init(uint8_t Channel);

/**
 * @brief  Read the current temperature in Celsius from the LM35.
 *
 * @details Performs a blocking ADC read and mathematically converts the 10-bit
 *          raw value to degrees Celsius.
 *
 * @param[in]  Channel     ADC channel to read from.
 * @param[out] Temperature Pointer to store the calculated temperature (0–150 C).
 */
void LM35_GetTemperature(uint8_t Channel, uint8_t *Temperature);

/** @} */ /* end of LM35_API */

#endif /* Lm35_Driver */
#endif /* _HAL_LM35_LM35_INTERFACE_H_ */
