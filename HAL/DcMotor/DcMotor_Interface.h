/**
 * @file    DcMotor_Interface.h
 * @brief   Public API for the DC Motor HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Controls DC motors via H-bridge modules (e.g. L298N). Supports
 *          basic on/off control as well as bidirectional (Clockwise /
 *          Counter-Clockwise) rotation using two control pins.
 */

#ifndef _HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define _HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if DcMotor_Driver

#include "../../MCAL/DIO/DIO_Interface.h"
#include "DcMotor_Private.h"
#include "DcMotor_Config.h"

/**
 * @defgroup DCMOTOR_API DC Motor Driver Public API
 * @{
 */

/* ── Functions ───────────────────────────────────────────────────────────── */

/**
 * @brief  Initialize the motor control pins as outputs.
 * @param[in] Config Pointer to the DC Motor configuration struct.
 */
void DC_Init(const Dc_Config_t *Config);

/**
 * @brief  Turn the motor ON (default direction based on config).
 * @param[in] Config Pointer to the DC Motor configuration struct.
 */
void DC_On(const Dc_Config_t *Config);

/**
 * @brief  Turn the motor OFF (freewheel or brake depending on H-bridge logic).
 * @param[in] Config Pointer to the DC Motor configuration struct.
 */
void DC_Off(const Dc_Config_t *Config);

/**
 * @brief  Toggle the motor state (ON -> OFF -> ON).
 * @param[in] Config Pointer to the DC Motor configuration struct.
 */
void DC_Toggle(const Dc_Config_t *Config);

/**
 * @brief  Turn the motor ON in the Clockwise (CW) direction.
 * @param[in] Config Pointer to the DC Motor configuration struct.
 */
void DC_OnCW(const Dc_Config_t *Config);

/**
 * @brief  Turn the motor ON in the Counter-Clockwise (CCW) direction.
 * @param[in] Config Pointer to the DC Motor configuration struct.
 */
void DC_OnCCW(const Dc_Config_t *Config);

/** @} */ /* end of DCMOTOR_API */

#endif /* DcMotor_Driver */
#endif /* _HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
