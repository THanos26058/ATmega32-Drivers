/**
 * @file    T1_Interface.h
 * @brief   Public API for the Timer1 (16-bit) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides functions to initialize and operate the 16-bit Timer1 in
 *          Normal (Overflow), CTC, PWM (Fast/Phase Correct), and Input Capture
 *          Unit (ICU) modes.
 */

#ifndef _MCAL_TIMER1_T1_INTERFACE_H_
#define _MCAL_TIMER1_T1_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Definition.h"
#include "../../Common/BitMath.h"
#include "../../Common/Config.h"
#include "../Atmega32Registers.h"

#include "T1_Private.h"
#include "T1_Config.h"

#if Timer1_Driver

/**
 * @defgroup Timer1_API Timer1 Driver Public API
 * @{
 */

/* ── Normal Mode (Overflow) ──────────────────────────────────────────────── */
#if T1_Normal 
/**
 * @brief  Initialize Timer1 in Normal (Overflow) Mode.
 * @details Timer1 counts from 0 to 65535 and overflows. Enables the Timer1
 *          Overflow Interrupt and applies the clock prescaler.
 */
void T1_NormalInit(void);

/**
 * @brief  Set the Preload value in the TCNT1 register.
 * @param[in] PreloadValue 16-bit value to load into TCNT1 (0 - 65535).
 */
void T1_SetPreLoad(uint16_t PreloadValue);

/**
 * @brief  Register a callback for the Timer1 Overflow Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T1_NormalCallBack(void (*PF)(void));
#endif // T1_Normal

/* ── CTC Mode ────────────────────────────────────────────────────────────── */
#if T1_CTC
/**
 * @brief  Initialize Timer1 in CTC Mode with OCR1A as the Top value.
 * @details Timer1 counts up to OCR1A and clears to 0. Compare match interrupts
 *          for both Channel A and Channel B are enabled.
 */
void T1_CTCInit(void);

/**
 * @brief  Set the Output Compare value for Channel A (OCR1A).
 * @param[in] CompareValue 16-bit compare threshold.
 */
void T1_SetCompareValueChannelA(uint16_t CompareValue);

/**
 * @brief  Set the Output Compare value for Channel B (OCR1B).
 * @param[in] CompareValue 16-bit compare threshold.
 */
void T1_SetCompareValueChannelB(uint16_t CompareValue);

/**
 * @brief  Register a callback for the Channel A Compare Match Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T1_CTCCallBackChannelA(void (*PF)(void));

/**
 * @brief  Register a callback for the Channel B Compare Match Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T1_CTCCallBackChannelB(void (*PF)(void));
#endif // T1_CTC

/* ── PWM Mode ────────────────────────────────────────────────────────────── */
#if T1_PWM
/**
 * @brief  Initialize Timer1 in PWM Mode (Fast PWM or Phase Correct).
 * @details Uses ICR1 as the Top value (ideal for servo motor control).
 *          Automatically sets OC1A (PD5) and OC1B (PD4) as output pins.
 */
void T1_PwmInit(void);

/**
 * @brief  Set the Top value (ICR1 register) for Timer1 PWM frequency control.
 * @param[in] TopValue 16-bit Top value.
 */
void T1_SetTopValue(uint16_t TopValue);

/**
 * @brief  Set the Compare value for PWM Channel A (OCR1A).
 * @param[in] CompareValue 16-bit duty cycle reference.
 */
void T1_SetCompareValueChannelA(uint16_t CompareValue);

/**
 * @brief  Set the Compare value for PWM Channel B (OCR1B).
 * @param[in] CompareValue 16-bit duty cycle reference.
 */
void T1_SetCompareValueChannelB(uint16_t CompareValue);
#endif // T1_PWM

/* ── Input Capture Unit (ICU) Mode ───────────────────────────────────────── */
#if T1_ICU
/**
 * @brief  Initialize the Input Capture Unit (ICU) on pin ICP1 (PD6).
 * @details Sets ICP1 as an input pin and applies the initial trigger edge
 *          defined in Config.h.
 */
void T1_ICU_Init(void);

/**
 * @brief  Set the active trigger edge for the ICU.
 * @param[in] Edge @c T1_ICU_Falling or @c T1_ICU_Rising.
 */
void T1_ICU_SetTriggerEdge(T1_ICU_Edge_t Edge);

/**
 * @brief  Get the captured 16-bit timer value from ICR1.
 * @return The captured timestamp (0 - 65535).
 */
uint16_t T1_ICU_GetCaptureValue(void);

/**
 * @brief  Enable the ICU Capture Event Interrupt.
 */
void T1_ICU_InterruptEnable(void);

/**
 * @brief  Disable the ICU Capture Event Interrupt.
 */
void T1_ICU_InterruptDisable(void);

/**
 * @brief  Register a callback for the ICU Capture Event Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T1_ICU_SetCallBack(void (*PF)(void));
#endif // T1_ICU

/* ── Common Control ──────────────────────────────────────────────────────── */

/**
 * @brief  Set or change the Timer1 clock prescaler dynamically.
 * @param[in] ClockSelect Prescaler selection.
 */
void T1_SetClock(uint8_t ClockSelect);

/**
 * @brief  Stop Timer1 completely.
 * @details Disconnects the clock source by setting the prescaler bits to 0.
 */
void T1_Stop(void);

/** @} */ /* end of Timer1_API */

#endif /* Timer1_Driver */
#endif /* _MCAL_TIMER1_T1_INTERFACE_H_ */
