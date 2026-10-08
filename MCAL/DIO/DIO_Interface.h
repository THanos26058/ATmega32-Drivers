/**
 * @file    DIO_Interface.h
 * @brief   Public API for the ATmega32 Digital I/O (DIO) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides functions for configuring and controlling all four 8-bit
 *          I/O ports (A, B, C, D) of the ATmega32 at both the individual-pin
 *          and whole-port (group) level.  Typical usage:
 *
 *          @code
 *          // Set PB3 as output and drive it HIGH
 *          DIO_DirectionSelectForPin(DIO_GroupB, DIO_Pin3, DIO_Output);
 *          DIO_WriteForPin(DIO_GroupB, DIO_Pin3, DIO_High);
 *          @endcode
 */

#ifndef _MCAL_DIO_DIO_INTERFACE_H_
#define _MCAL_DIO_DIO_INTERFACE_H_

#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"

#include "DIO_Private.h"
#include "DIO_Config.h"

/**
 * @defgroup DIO_API DIO Driver Public API
 * @{
 */

/* ── Direction ───────────────────────────────────────────────────────────── */

/**
 * @brief  Configure the direction (input / output) of a single I/O pin.
 *
 * @details Writes to the corresponding DDR register bit.
 *          Silently ignores invalid @p GroupName or @p PinNo values.
 *
 * @param[in] GroupName      Port identifier — one of @ref DIO_GroupName_t
 *                           (DIO_GroupA … DIO_GroupD).
 * @param[in] PinNo          Pin number — one of @ref DIO_PinNo_t
 *                           (DIO_Pin0 … DIO_Pin7).
 * @param[in] DirectionState Direction — @c DIO_Input or @c DIO_Output.
 */
void DIO_DirectionSelectForPin(uint8_t GroupName, uint8_t PinNo,
                               uint8_t DirectionState);

/**
 * @brief  Configure the direction of an entire 8-pin port at once.
 *
 * @details Writes @p DirectionState directly to the DDR register of the
 *          selected port.  Use @c DIO_AllOutput (0xFF) for all outputs or
 *          @c DIO_Input (0x00) for all inputs, or any bitmask.
 *
 * @param[in] GroupName      Port identifier — one of @ref DIO_GroupName_t.
 * @param[in] DirectionState Bitmask: 1 = output, 0 = input for each bit.
 */
void DIO_DirectionSelectForGroup(uint8_t GroupName, uint8_t DirectionState);

/* ── Output ──────────────────────────────────────────────────────────────── */

/**
 * @brief  Write a logic level (HIGH or LOW) to a single output pin.
 *
 * @param[in] GroupName   Port identifier.
 * @param[in] PinNo       Pin number (DIO_Pin0 … DIO_Pin7).
 * @param[in] OutputValue @c DIO_High or @c DIO_Low.
 */
void DIO_WriteForPin(uint8_t GroupName, uint8_t PinNo, uint8_t OutputValue);

/**
 * @brief  Write a byte value to an entire output port at once.
 *
 * @param[in] GroupName   Port identifier.
 * @param[in] OutputValue 8-bit value written directly to the PORT register.
 *                        Use @c DIO_AllHigh (0xFF) or any bitmask.
 */
void DIO_WriteForGroup(uint8_t GroupName, uint8_t OutputValue);

/* ── Input ───────────────────────────────────────────────────────────────── */

/**
 * @brief  Read the logic level of a single input pin.
 *
 * @param[in]  GroupName  Port identifier.
 * @param[in]  PinNo      Pin number (DIO_Pin0 … DIO_Pin7).
 * @param[out] InputState Pointer to the variable that receives the bit value
 *                        (0 = LOW, 1 = HIGH).  Must not be NULL.
 */
void DIO_ReadInputForPin(uint8_t GroupName, uint8_t PinNo,
                         uint8_t *InputState);

/**
 * @brief  Read the entire byte value of an input port.
 *
 * @param[in]  GroupName  Port identifier.
 * @param[out] InputState Pointer to the variable that receives the PIN
 *                        register value.  Must not be NULL.
 */
void DIO_ReadInputForGroup(uint8_t GroupName, uint8_t *InputState);

/* ── Toggle ──────────────────────────────────────────────────────────────── */

/**
 * @brief  Toggle the output level of a single pin (HIGH→LOW or LOW→HIGH).
 *
 * @param[in] GroupName Port identifier.
 * @param[in] PinNo     Pin number (DIO_Pin0 … DIO_Pin7).
 */
void DIO_ToggleForPin(uint8_t GroupName, uint8_t PinNo);

/**
 * @brief  Toggle all 8 pins of a port simultaneously.
 *
 * @param[in] GroupName Port identifier.
 */
void DIO_ToggleForGroup(uint8_t GroupName);

/* ── Internal Pull-Up ────────────────────────────────────────────────────── */

/**
 * @brief  Enable or disable the internal pull-up resistor on an input pin.
 *
 * @details On ATmega32, writing HIGH to a pin configured as input activates
 *          the internal ~47 kΩ pull-up resistor.  This function wraps
 *          @ref DIO_WriteForPin for a more descriptive call site.
 *
 * @param[in] GroupName  Port identifier.
 * @param[in] PinNo      Pin number (DIO_Pin0 … DIO_Pin7).
 * @param[in] PullUpState @c DIO_High to enable pull-up, @c DIO_Low to
 *                        disable (tri-state / high-Z) the resistor.
 */
void DIO_InternalPullUpControl(uint8_t GroupName, uint8_t PinNo,
                               uint8_t PullUpState);

/** @} */ /* end of DIO_API */

#endif /* _MCAL_DIO_DIO_INTERFACE_H_ */
