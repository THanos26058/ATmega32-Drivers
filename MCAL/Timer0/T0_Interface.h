/**
 * @file    T0_Interface.h
 * @brief   Public API for the Timer0 (8-bit) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides functions to initialize and operate the 8-bit Timer0 in
 *          Normal (Overflow), CTC (Clear Timer on Compare Match), and PWM modes.
 *          Compile-time switches in Config.h enable or disable specific modes
 *          to save flash memory.
 */

#ifndef _MCAL_TIMER0_T0_INTERFACE_H_
#define _MCAL_TIMER0_T0_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Definition.h"
#include "../../Common/BitMath.h"
#include "../../Common/Config.h"
#include "../Atmega32Registers.h"

#include "T0_Private.h"
#include "T0_Config.h"

#if Timer0_Driver


/*  Normal Mode (Overflow)  */
#if T0_Normal 
/**
 * @brief  Initialize Timer0 in Normal (Overflow) Mode.
 * @details Configures Timer0 to count up to 255 and overflow. Enables the
 *          Overflow Interrupt and applies the prescaler defined in Config.h.
 */
void T0_NormalInit(void);

/**
 * @brief  Set the Preload value in the TCNT0 register.
 * @param[in] PreloadValue Value to load into TCNT0 (0 - 255).
 */
void T0_SetPreLoad(uint8_t PreloadValue);

/**
 * @brief  Register a callback function for the Timer0 Overflow Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T0_NormalCallBack(void (*PF)(void));
#endif // T0_Normal

/*  CTC Mode  */
#if T0_CTC
/**
 * @brief  Initialize Timer0 in CTC Mode.
 * @details Configures Timer0 to count up to OCR0 and then clear to 0.
 *          Enables the Compare Match Interrupt and applies the prescaler.
 */
void T0_CTCInit(void);

/**
 * @brief  Set the Output Compare value in the OCR0 register.
 * @param[in] CompareValue Compare threshold value (0 - 255) that resets the timer.
 */
void T0_SetCompareValue(uint8_t CompareValue);

/**
 * @brief  Register a callback function for the Timer0 Compare Match Interrupt.
 * @param[in] PF Pointer to the callback function @c void(*)(void).
 */
void T0_CTCCallBack(void (*PF)(void));
#endif // T0_CTC

/*  PWM Mode  */
#if T0_PWM
/**
 * @brief  Initialize Timer0 in PWM Mode.
 * @details Automatically configures OC0 (PB3) as an output pin. Hardware PWM
 *          generation runs continuously based on the duty cycle set.
 */
void T0_PwmInit(void);

/**
 * @brief  Set the PWM Duty Cycle on the OC0 pin.
 * @param[in] DutyCyclePre Duty cycle percentage (0 - 100).
 */
void T0_SetDutyCycle(uint8_t DutyCyclePre);
#endif // T0_PWM

/*  Common Control  */

/**
 * @brief  Set or change the Timer0 clock prescaler dynamically.
 * @param[in] ClockSelect Prescaler selection (e.g., @c T0_Prescaler_64).
 *                        Use @c T0_NoClock to stop the timer.
 */
void T0_SetClock(uint8_t ClockSelect);

/**
 * @brief  Stop Timer0 completely.
 * @details Disconnects the clock source by setting the prescaler bits to 0.
 */
void T0_Stop(void);


#endif /* Timer0_Driver */
#endif /* _MCAL_TIMER0_T0_INTERFACE_H_ */
