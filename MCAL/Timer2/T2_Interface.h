/**
 * @file    T2_Interface.h
 * @brief   Public API for the Timer2 (8-bit) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides functions to initialize and operate the 8-bit Timer2 in
 *          Normal (Overflow), CTC, and PWM modes. Timer2 features an
 *          Asynchronous mode, allowing it to act as an RTC (Real-Time Clock)
 *          using an external 32.768 kHz watch crystal on TOSC1/TOSC2 pins.
 */

#ifndef _MCAL_TIMER2_T2_INTERFACE_H_
#define _MCAL_TIMER2_T2_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Definition.h"
#include "../../Common/BitMath.h"
#include "../../Common/Config.h"
#include "../Atmega32Registers.h"

#include "T2_Private.h"
#include "T2_Config.h"

#if Timer2_Driver

/**
 * @defgroup Timer2_API Timer2 Driver Public API
 * @{
 */

/* ── Normal Mode (Overflow) ──────────────────────────────────────────────── */
#if T2_Normal 
/**
 * @brief  Initialize Timer2 in Normal (Overflow) Mode.
 * @details Configures Timer2 to count up to 255 and overflow. Checks for
 *          asynchronous clock source if enabled in config.
 */
void T2_NormalInit(void);

/**
 * @brief  Set the Preload value in the TCNT2 register.
 * @param[in] PreloadValue Value to load into TCNT2 (0 - 255).
 */
void T2_SetPreLoad(uint8_t PreloadValue);

/**
 * @brief  Register a callback for the Timer2 Overflow Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T2_NormalCallBack(void (*PF)(void));
#endif // T2_Normal

/* ── CTC Mode ────────────────────────────────────────────────────────────── */
#if T2_CTC
/**
 * @brief  Initialize Timer2 in CTC (Clear Timer on Compare Match) Mode.
 * @details Configures Timer2 to count up to OCR2 and then clear to 0.
 *          Checks for asynchronous clock source if enabled in config.
 */
void T2_CTCInit(void);

/**
 * @brief  Set the Output Compare value in the OCR2 register.
 * @param[in] CompareValue Compare threshold value (0 - 255).
 */
void T2_SetCompareValue(uint8_t CompareValue);

/**
 * @brief  Register a callback for the Timer2 Compare Match Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T2_CTCCallBack(void (*PF)(void));
#endif // T2_CTC

/* ── PWM Mode ────────────────────────────────────────────────────────────── */
#if T2_PWM
/**
 * @brief  Initialize Timer2 in PWM Mode (Fast PWM or Phase Correct).
 * @details Automatically configures OC2 (PD7) as an output pin for PWM.
 */
void T2_PwmInit(void);

/**
 * @brief  Set the PWM Duty Cycle on the OC2 pin.
 * @param[in] DutyCyclePre Duty cycle percentage (0 - 100).
 */
void T2_SetDutyCycle(uint8_t DutyCyclePre);
#endif // T2_PWM

/* ── Common Control ──────────────────────────────────────────────────────── */

/**
 * @brief  Set or change the Timer2 clock prescaler dynamically.
 * @param[in] ClockSelect Prescaler selection (matches Timer2-specific prescalers).
 */
void T2_SetClock(uint8_t ClockSelect);

/**
 * @brief  Stop Timer2 completely.
 * @details Disconnects the clock source by setting the prescaler bits to 0.
 */
void T2_Stop(void);

/** @} */ /* end of Timer2_API */

#endif /* Timer2_Driver */
#endif /* _MCAL_TIMER2_T2_INTERFACE_H_ */
