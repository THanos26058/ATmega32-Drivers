/**
 * @file    LED_Interface.h
 * @brief   Public API for the LED HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Controls single-color Light Emitting Diodes (LEDs). Abstracts
 *          away active-high vs. active-low wiring configurations.
 */

#ifndef _HAL_LED_LED_INTERFACE_H_
#define _HAL_LED_LED_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Led_Driver

#include "../../MCAL/DIO/DIO_Interface.h"

/**
 * @defgroup LED_API LED Driver Public API
 * @{
 */

/* ── Connection Type Definitions ─────────────────────────────────────────── */

#define LED_ACTIVE_HIGH    1  /**< MCU sources current (LED anode to MCU pin). */
#define LED_ACTIVE_LOW     2  /**< MCU sinks current (LED cathode to MCU pin). */

/* ── Configuration Struct ────────────────────────────────────────────────── */

/**
 * @struct LED_Config_t
 * @brief  Configuration structure for a single LED instance.
 */
typedef struct
{
    uint8_t GroupName;      /**< DIO Port (e.g., @c DIO_GroupA). */
    uint8_t PinNo;          /**< DIO Pin (e.g., @c DIO_Pin0).    */
    uint8_t ConnectionType; /**< @c LED_ACTIVE_HIGH or @c LED_ACTIVE_LOW. */
} LED_Config_t;

/* ── Functions ───────────────────────────────────────────────────────────── */

/**
 * @brief  Initialize the LED hardware pin as an output.
 * @details Drives the pin to its OFF state initially.
 *
 * @param[in] Config Pointer to the LED configuration struct.
 */
void LED_Init(const LED_Config_t *Config);

/**
 * @brief  Turn the LED ON.
 * @param[in] Config Pointer to the LED configuration struct.
 */
void LED_TurnOn(const LED_Config_t *Config);

/**
 * @brief  Turn the LED OFF.
 * @param[in] Config Pointer to the LED configuration struct.
 */
void LED_TurnOff(const LED_Config_t *Config);

/**
 * @brief  Toggle the LED state.
 * @param[in] Config Pointer to the LED configuration struct.
 */
void LED_Toggle(const LED_Config_t *Config);

/** @} */ /* end of LED_API */

#endif /* Led_Driver */
#endif /* _HAL_LED_LED_INTERFACE_H_ */
