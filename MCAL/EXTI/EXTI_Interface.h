/**
 * @file    EXTI_Interface.h
 * @brief   Public API for the ATmega32 External Interrupt (EXTI) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Manages the three external interrupt lines available on the
 *          ATmega32:
 *
 *          | Line  | Pin | Register bits             |
 *          |-------|-----|---------------------------|
 *          | INT0  | PD2 | MCUCR ISC01:ISC00         |
 *          | INT1  | PD3 | MCUCR ISC11:ISC10         |
 *          | INT2  | PB2 | MCUCSR ISC2 (edge only)   |
 *
 *          Typical usage:
 *          @code
 *          EXTI_Init(Exti0, Exti_Rising);
 *          EXTI_CallBackFunction(Exti0, myISRHandler);
 *          EXTI_Enable(Exti0);
 *          GIE_Enable();
 *          @endcode
 */

#ifndef _MCAL_EXTI_EXTI_INTERFACE_H_
#define _MCAL_EXTI_EXTI_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"

#if EXTI_Driver

/**
 * @defgroup EXTI_API EXTI Driver Public API
 * @{
 */

/**
 * @brief  Configure the sense (trigger) condition for an external interrupt.
 *
 * @details Writes the ISCxx bits in MCUCR (INT0, INT1) or MCUCSR (INT2).
 *          Call this before @ref EXTI_Enable().
 *
 * @param[in] InterruptNumber  Interrupt line — one of @ref Exti_Numbers_t
 *                             (Exti0, Exti1, Exti2).
 * @param[in] SensControl      Trigger type — one of @ref Exti_SensControl_t.
 *                             @note INT2 only accepts @c Exti_Falling or
 *                             @c Exti_Rising; other values are ignored.
 */
void EXTI_Init(uint8_t InterruptNumber, uint8_t SensControl);

/**
 * @brief  Enable a specific external interrupt line (set INTx bit in GICR).
 *
 * @param[in] InterruptNumber  Interrupt line — one of @ref Exti_Numbers_t.
 */
void EXTI_Enable(uint8_t InterruptNumber);

/**
 * @brief  Disable a specific external interrupt line (clear INTx in GICR).
 *
 * @param[in] InterruptNumber  Interrupt line — one of @ref Exti_Numbers_t.
 */
void EXTI_Disable(uint8_t InterruptNumber);

/**
 * @brief  Register a callback function that is invoked inside the ISR.
 *
 * @details The callback is called from within the interrupt service routine
 *          so it should be kept short and must not re-enable interrupts.
 *          Passing @c NULL clears any previously registered callback.
 *
 * @param[in] InterruptNumber  Interrupt line — one of @ref Exti_Numbers_t.
 * @param[in] PF               Pointer to the callback @c void(*)(void).
 *                             Pass @c NULL to unregister.
 */
void EXTI_CallBackFunction(uint8_t InterruptNumber, void (*PF)(void));

/** @} */ /* end of EXTI_API */

#endif /* EXTI_Driver */

#endif /* _MCAL_EXTI_EXTI_INTERFACE_H_ */
