/**
 * @file    EXTI_Program.c
 * @brief   Implementation of the ATmega32 External Interrupt (EXTI) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Implements sense-control configuration, enable/disable control,
 *          and callback registration for INT0, INT1, and INT2.
 *          ISR vectors:  __vector_1 = INT0,  __vector_2 = INT1,
 *                        __vector_3 = INT2.
 *
 * @note    Bit-mask rule used throughout:
 *          @code  REG = (REG & ~MASK) | NEW_VALUE  @endcode
 */

#include "EXTI_Interface.h"

/*  Private Callback Pointers  */

/** @brief Callback registered for INT0 (PD2). */
static void (*GINT0)(void) = NULL;

/** @brief Callback registered for INT1 (PD3). */
static void (*GINT1)(void) = NULL;

/** @brief Callback registered for INT2 (PB2). */
static void (*GINT2)(void) = NULL;

/*  Public API  */

/**
 * @brief See EXTI_Interface.h for full documentation.
 */
void EXTI_Init(uint8_t InterruptNumber, uint8_t SensControl)
{
    if (InterruptNumber == Exti0)
    {
        /* ISC01:ISC00 in MCUCR[1:0] */
        MCUCR_REG = (MCUCR_REG & ~0x03u) | ((uint8_t)(SensControl << ISC00));
    }
    else if (InterruptNumber == Exti1)
    {
        /* ISC11:ISC10 in MCUCR[3:2] */
        MCUCR_REG = (MCUCR_REG & ~0x0Cu) | ((uint8_t)(SensControl << ISC10));
    }
    else if (InterruptNumber == Exti2)
    {
        /* ISC2 in MCUCSR[6] — only bit 0 of SensControl is relevant */
        MCUCSR_REG = (MCUCSR_REG & ~0x40u) | ((uint8_t)((SensControl & 0x01u) << ISC2));
    }
}

/**
 * @brief See EXTI_Interface.h for full documentation.
 */
void EXTI_Enable(uint8_t InterruptNumber)
{
    if      (InterruptNumber == Exti0) { SetBit(GICR_REG, INT0); }
    else if (InterruptNumber == Exti1) { SetBit(GICR_REG, INT1); }
    else if (InterruptNumber == Exti2) { SetBit(GICR_REG, INT2); }
}

/**
 * @brief See EXTI_Interface.h for full documentation.
 */
void EXTI_Disable(uint8_t InterruptNumber)
{
    if      (InterruptNumber == Exti0) { ClearBit(GICR_REG, INT0); }
    else if (InterruptNumber == Exti1) { ClearBit(GICR_REG, INT1); }
    else if (InterruptNumber == Exti2) { ClearBit(GICR_REG, INT2); }
}

/**
 * @brief See EXTI_Interface.h for full documentation.
 */
void EXTI_CallBackFunction(uint8_t InterruptNumber, void (*PF)(void))
{
    if (InterruptNumber == Exti0)      { GINT0 = PF; }
    else if (InterruptNumber == Exti1) { GINT1 = PF; }
    else if (InterruptNumber == Exti2) { GINT2 = PF; }
}

/*  ISR Vectors  */

/** @brief INT0 ISR — vector 1. Calls GINT0 callback if registered. */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (GINT0 != NULL) { GINT0(); }
}

/** @brief INT1 ISR — vector 2. Calls GINT1 callback if registered. */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (GINT1 != NULL) { GINT1(); }
}

/** @brief INT2 ISR — vector 3. Calls GINT2 callback if registered. */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (GINT2 != NULL) { GINT2(); }
}
