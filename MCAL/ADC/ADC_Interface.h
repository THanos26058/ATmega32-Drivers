/**
 * @file    ADC_Interface.h
 * @brief   Public API for the ATmega32 Analog-to-Digital Converter (ADC) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides both synchronous (polling) and asynchronous (interrupt-driven)
 *          methods to read analog voltages on channels ADC0..ADC7.
 *          Typical synchronous usage:
 *          @code
 *          uint16_t reading = 0;
 *          ADC_Init();
 *          ADC_Read(Adc_SingleEndedChannel0, &reading, 50000);
 *          @endcode
 */

#ifndef _MCAL_ADC_ADC_INTERFACE_H_
#define _MCAL_ADC_ADC_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"
#if ADC_Driver

#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"

#include "ADC_Private.h"
#include "ADC_Config.h"

/**
 * @defgroup ADC_API ADC Driver Public API
 * @{
 */

/* ── Initialization ──────────────────────────────────────────────────────── */

/**
 * @brief  Initialize the ADC peripheral based on build-time configuration.
 *
 * @details Configures voltage reference, result alignment, prescaler, mode,
 *          and trigger source.  Sets internal driver state to @c Adc_Idle.
 *          Must be called before any other ADC function.
 */
void ADC_Init(void);

/**
 * @brief  De-initialize the ADC peripheral.
 *
 * @details Disables the ADC, clears interrupts, and resets the driver state
 *          to @c Adc_Uninitialized.
 */
void ADC_DeInit(void);

/* ── Control ─────────────────────────────────────────────────────────────── */

/**
 * @brief  Enable the ADC peripheral (sets ADEN in ADCSRA).
 */
void ADC_Enable(void);

/**
 * @brief  Disable the ADC peripheral (clears ADEN).
 */
void ADC_Disable(void);

/**
 * @brief  Enable the ADC Conversion Complete interrupt (sets ADIE).
 */
void ADC_EnableInterrupt(void);

/**
 * @brief  Disable the ADC Conversion Complete interrupt (clears ADIE).
 */
void ADC_DisableInterrupt(void);

/* ── Synchronous (Polling) ───────────────────────────────────────────────── */

/**
 * @brief  Perform a blocking (synchronous) ADC conversion.
 *
 * @param[in]  Channel      ADC channel to read (e.g., @c Adc_SingleEndedChannel0).
 * @param[out] DigitalValue Pointer to store the 10-bit or 8-bit result.
 * @param[in]  MaxTimeOut   Maximum polling loops before returning a timeout error.
 *
 * @return @c Adc_Ok on success.
 * @return @c Adc_NullPointerErr if @p DigitalValue is NULL.
 * @return @c Adc_InvalidChannelErr if @p Channel > 7.
 * @return @c Adc_NotInitializedErr if @ref ADC_Init() was not called.
 * @return @c Adc_TimerOutErr if the conversion did not complete in time.
 */
uint8_t ADC_Read(uint8_t Channel, uint16_t *DigitalValue, uint32_t MaxTimeOut);

/* ── Asynchronous (Interrupt) ────────────────────────────────────────────── */

/**
 * @brief  Start a non-blocking ADC conversion.
 *
 * @details The result will be passed to the callback function registered
 *          via @ref ADC_SetCallBack() when the conversion completes.
 *
 * @param[in] Channel ADC channel to read.
 *
 * @return @c Adc_Ok on success, or an error code on failure.
 */
uint8_t ADC_StartConversion(uint8_t Channel);

/**
 * @brief  Register a callback function for asynchronous conversions.
 *
 * @param[in] ADC_PF Pointer to the callback function @c void(*)(uint16_t).
 *                   The 10-bit or 8-bit result is passed as the argument.
 *
 * @return @c Adc_Ok on success, @c Adc_NullPointerErr if @p ADC_PF is NULL.
 */
uint8_t ADC_SetCallBack(void (*ADC_PF)(uint16_t Result));

/* ── Status ──────────────────────────────────────────────────────────────── */

/**
 * @brief  Get the current state of the ADC driver.
 *
 * @return One of @ref Adc_DriverState_t (@c Adc_Uninitialized, @c Adc_Idle, @c Adc_Busy).
 */
uint8_t ADC_GetStatus(void);

/** @} */ /* end of ADC_API */

#endif /* ADC_Driver */
#endif /* _MCAL_ADC_ADC_INTERFACE_H_ */
