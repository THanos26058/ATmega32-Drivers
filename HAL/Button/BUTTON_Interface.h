/**
 * @file    BUTTON_Interface.h
 * @brief   Public API for the Push-Button HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Reads the physical state of a push button, abstracting whether
 *          the button is wired in a Pull-Up (active low) or Pull-Down
 *          (active high) configuration.
 */

#ifndef _HAL_BUTTON_BUTTON_INTERFACE_H_
#define _HAL_BUTTON_BUTTON_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Button_Driver

#include "../../MCAL/DIO/DIO_Interface.h"


/*  Connection Type Definitions  */

#define BUTTON_PULL_UP      1  /**< Button to GND (Active Low).  */
#define BUTTON_PULL_DOWN    2  /**< Button to VCC (Active High). */

/*  Button State Definitions  */

#define BUTTON_RELEASED     0  /**< Button is not pressed. */
#define BUTTON_PRESSED      1  /**< Button is pressed.     */

/*  Configuration Struct  */

/**
 * @struct Button_Config_t
 * @brief  Configuration structure for a single push button instance.
 */
typedef struct
{
    uint8_t GroupName;      /**< DIO Port (e.g., @c DIO_GroupA). */
    uint8_t PinNo;          /**< DIO Pin (e.g., @c DIO_Pin0).    */
    uint8_t ConnectionType; /**< @c BUTTON_PULL_UP or @c BUTTON_PULL_DOWN. */
} Button_Config_t;

/*  Functions  */

/**
 * @brief  Initialize the button's hardware pin as an input.
 *
 * @details If configured as @c BUTTON_PULL_UP, this automatically enables the
 *          internal pull-up resistor via the DIO driver.
 *
 * @param[in] Config Pointer to the button configuration struct.
 */
void BUTTON_Init(const Button_Config_t *Config);

/**
 * @brief  Read the logical state of the button (pressed or released).
 *
 * @details Automatically compensates for Pull-Up / Pull-Down wiring so that
 *          @c BUTTON_PRESSED is consistently returned when physically pressed.
 *
 * @param[in]  Config     Pointer to the button configuration struct.
 * @param[out] InputValue Pointer to store the result (@c BUTTON_PRESSED or @c BUTTON_RELEASED).
 */
void BUTTON_ReadInputValue(const Button_Config_t *Config, uint8_t *InputValue);

/**
 * @brief  Check if the button is physically clicked (with debouncing context).
 *
 * @param[in]  Config     Pointer to the button configuration struct.
 * @param[out] InputValue Pointer to store the logical state.
 */
void BUTTON_IsPhysacillyClicked(const Button_Config_t *Config, uint8_t *InputValue);


#endif /* Button_Driver */
#endif /* _HAL_BUTTON_BUTTON_INTERFACE_H_ */
