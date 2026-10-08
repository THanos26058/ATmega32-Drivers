/**
 * @file    GIE_Interface.h
 * @brief   Public API for the Global Interrupt Enable (GIE) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides inline-like functions to enable and disable the I-bit
 *          in the ATmega32 Status Register (SREG), allowing or preventing
 *          all maskable interrupts globally.
 */

#ifndef _MCAL_GIE_GIE_INTERFACE_H_
#define _MCAL_GIE_GIE_INTERFACE_H_

#include "../../Common/Config.h"

#if GIE_Driver

/**
 * @defgroup GIE_API GIE Driver Public API
 * @{
 */

/**
 * @brief  Enable global interrupts.
 * @details Sets the Global Interrupt Enable (I) bit 7 in the Status Register (SREG).
 *          Equivalent to the `sei()` macro in AVR Libc.
 */
void GIE_Enable(void);

/**
 * @brief  Disable global interrupts.
 * @details Clears the Global Interrupt Enable (I) bit 7 in the Status Register (SREG).
 *          Equivalent to the `cli()` macro in AVR Libc.
 */
void GIE_Disable(void);

/** @} */ /* end of GIE_API */

#endif /* GIE_Driver */
#endif /* _MCAL_GIE_GIE_INTERFACE_H_ */
