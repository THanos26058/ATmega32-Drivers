/**
 * @file    ADC_Config.h
 * @brief   Compile-time configuration for the ATmega32 ADC driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Selects voltage reference, result alignment, clock prescaler,
 *          operating mode (single / auto), auto-trigger source, and interrupt
 *          mode at build time.  Change only the `#define` values; do not
 *          modify the driver source files.
 */

#ifndef _MCAL_ADC_ADC_CONFIG_H_
#define _MCAL_ADC_ADC_CONFIG_H_

#include "ADC_Private.h"

/*  Enable State  */

/**
 * @def    Adc_InitState
 * @brief  ADC enable state applied during @ref ADC_Init().
 *         Options: @c Adc_Enable | @c Adc_Disable
 */
#define Adc_InitState              Adc_Enable

/*  Voltage Reference  */

/**
 * @def    Adc_VrefSelection
 * @brief  Voltage reference source (REFS1:REFS0 in ADMUX).
 *         Options:
 *           - @c Adc_Aref     — External AREF pin
 *           - @c Adc_Avcc     — AVCC (5 V) with cap on AREF
 *           - @c Adc_Internal — Internal 2.56 V reference
 */
#define Adc_VrefSelection          Adc_Avcc

/*  Result Adjustment  */

/**
 * @def    Adc_AdjustSelection
 * @brief  Result alignment (ADLAR bit in ADMUX).
 *         Options:
 *           - @c Adc_RightAdjust — 10-bit result in ADC_REG (default)
 *           - @c Adc_LeftAdjust  — 8-bit result in ADCH only
 */
#define Adc_AdjustSelection        Adc_RightAdjust

/*  Clock Prescaler  */

/**
 * @def    Adc_DivisionFactorSelection
 * @brief  ADC clock = F_CPU / DivisionFactor.  Must keep ADC clock 50–200 kHz.
 *         At 8 MHz: Factor 64 → 125 kHz (recommended for 10-bit accuracy).
 *         Options: @c Adc_DivisionFactor2 … @c Adc_DivisionFactor128
 */
#define Adc_DivisionFactorSelection Adc_DivisionFactor64

/*  Operating Mode  */

/**
 * @def    Adc_ModeSelect
 * @brief  ADC trigger mode.
 *         Options:
 *           - @c Adc_SingleMode — single-shot, triggered by ADC_Read()
 *           - @c Adc_AutoMode   — auto-triggered, source set below
 */
#define Adc_ModeSelect             Adc_SingleMode

/*  Auto-Trigger Source (only used when Adc_ModeSelect == Adc_AutoMode)  */

#if Adc_ModeSelect == Adc_AutoMode
/**
 * @def    Adc_TriggerSource
 * @brief  Auto-trigger source written to ADTS[2:0] in SFIOR.
 *         Options: @c Adc_FreeRunning, @c Adc_AnalogComparator,
 *                  @c Adc_EXTI0, @c Adc_CTC0, @c Adc_OVF0,
 *                  @c Adc_CTC1, @c Adc_OVF1, @c Adc_ICU1
 */
#define Adc_TriggerSource          Adc_FreeRunning
#endif

/*  Interrupt Mode  */

/**
 * @def    Adc_InterrupState
 * @brief  ADC Conversion Complete interrupt (ADIE bit in ADCSRA).
 *         Options:
 *           - @c Adc_InterruptDisable — polled / synchronous mode
 *           - @c Adc_InterruptEnable  — ISR-driven / asynchronous mode
 */
#define Adc_InterrupState          Adc_InterruptDisable

#endif /* _MCAL_ADC_ADC_CONFIG_H_ */
