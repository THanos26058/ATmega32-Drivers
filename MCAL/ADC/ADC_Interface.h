/**
 * @file ADC_Interface.h
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#ifndef _MCAL_ADC_ADC_INTERFACE_H_
#define _MCAL_ADC_ADC_INTERFACE_H_

#include <stdint.h>
#include "../Atmega32Registers.h"
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"

#include "ADC_Private.h"
#include "ADC_Config.h"

typedef enum
{
    ADC_Channel0 = 0,
    ADC_Channel1,
    ADC_Channel2,
    ADC_Channel3,
    ADC_Channel4,
    ADC_Channel5,
    ADC_Channel6,
    ADC_Channel7
} ADC_Channel_t;

/* Initialization */
void ADC_Init(void);

/* Enable / Disable */
void ADC_Enable(void);
void ADC_Disable(void);

/* Interrupt Control */
void ADC_InterruptEnable(void);
void ADC_InterruptDisable(void);

/* Synchronous Read - blocks until conversion done */
void ADC_ReadChannelSync(ADC_Channel_t Channel, uint16_t *ADC_Value);

/* Asynchronous Read - returns immediately, calls NotificationFunction when done */
void ADC_StartConversionAsync(ADC_Channel_t Channel, uint16_t *ADC_Value, void (*NotificationFunction)(void));

/* Set Callback for async conversion */
void ADC_SetCallback(void (*NotificationFunction)(void));

#endif // _MCAL_ADC_ADC_INTERFACE_H_
