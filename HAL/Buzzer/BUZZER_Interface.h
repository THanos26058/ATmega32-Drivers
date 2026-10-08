/**
 * @file    BUZZER_Interface.h
 * @brief   Public API for the Buzzer HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Controls a piezoelectric or magnetic buzzer. Handles active-high
 *          (sourcing current) and active-low (sinking current) wiring
 *          transparently.
 */

#ifndef _HAL_BUZZER_BUZZER_INTERFACE_H_
#define _HAL_BUZZER_BUZZER_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Buzzer_Driver

#include "../../MCAL/DIO/DIO_Interface.h"

/**
 * @defgroup BUZZER_API Buzzer Driver Public API
 * @{
 */

/* ── Connection Type Definitions ─────────────────────────────────────────── */

#define BUZZER_ACTIVE_HIGH    1  /**< MCU sources current to buzzer. */
#define BUZZER_ACTIVE_LOW     2  /**< MCU sinks current from buzzer. */

/* ── Configuration Struct ────────────────────────────────────────────────── */

/**
 * @struct Buzzer_Config_t
 * @brief  Configuration structure for a single buzzer instance.
 */
typedef struct
{
    uint8_t GroupName;      /**< DIO Port (e.g., @c DIO_GroupA). */
    uint8_t PinNo;          /**< DIO Pin (e.g., @c DIO_Pin0).    */
    uint8_t ConnectionType; /**< @c BUZZER_ACTIVE_HIGH or @c BUZZER_ACTIVE_LOW. */
} Buzzer_Config_t;

/* ── Functions ───────────────────────────────────────────────────────────── */

/**
 * @brief  Initialize the buzzer's hardware pin as an output.
 * @details Drives the pin to its inactive state immediately to prevent chirps.
 *
 * @param[in] Config Pointer to the buzzer configuration struct.
 */
void BUZZER_Init(const Buzzer_Config_t *Config);

/**
 * @brief  Turn the buzzer ON.
 * @param[in] Config Pointer to the buzzer configuration struct.
 */
void BUZZER_TurnOn(const Buzzer_Config_t *Config);

/**
 * @brief  Turn the buzzer OFF.
 * @param[in] Config Pointer to the buzzer configuration struct.
 */
void BUZZER_TurnOff(const Buzzer_Config_t *Config);

/**
 * @brief  Toggle the buzzer state (ON -> OFF -> ON).
 * @param[in] Config Pointer to the buzzer configuration struct.
 */
void BUZZER_Toggle(const Buzzer_Config_t *Config);

/** @} */ /* end of BUZZER_API */

#endif /* Buzzer_Driver */
#endif /* _HAL_BUZZER_BUZZER_INTERFACE_H_ */
