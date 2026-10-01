/**
 * @file LM35_Interface.h
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#ifndef _HAL_LM35_LM35_INTERFACE_H_
#define _HAL_LM35_LM35_INTERFACE_H_

#include <stdint.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"

#include "LM35_Config.h"
#include "LM35_Private.h"

/* Initialize LM35 Pin as Input */
void LM35_Init(ADC_Channel_t Channel);

/* Read Temperature in Celsius */
void LM35_GetTemperature(ADC_Channel_t Channel, uint8_t *Temperature);

#endif // _HAL_LM35_LM35_INTERFACE_H_
