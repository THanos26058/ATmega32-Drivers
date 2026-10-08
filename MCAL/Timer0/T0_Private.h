/**
 * @file T0_Private.h
 * @brief Private definitions, registers, and bit mappings for Timer0 driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#ifndef _MCAL_TIMER0_T0_PRIVATE_H
#define _MCAL_TIMER0_T0_PRIVATE_H

#include "../../Common/Config.h"
#include "../Atmega32Registers.h"

/* Register Aliases for compatibility */
#ifndef TCCR0_Reg
#define TCCR0_Reg    TCCR0_REG
#endif
#ifndef TCNT0_Reg
#define TCNT0_Reg    TCNT0_REG
#endif
#ifndef OCR0_Reg
#define OCR0_Reg     OCR0_REG
#endif
#ifndef TIMSk_Reg
#define TIMSk_Reg    TIMSK_REG
#endif
#ifndef TIFR_Reg
#define TIFR_Reg     TIFR_REG
#endif
#ifndef SREG_Reg
#define SREG_Reg     SREG_REG
#endif

#if Timer0_Driver

typedef enum
{
    // TCCR0 Bits
    CS00 = 0,
    CS01,
    CS02,
    WGM01,
    COM00,
    COM01,
    WGM00,
    FOC0,
    // TIMSK Bits
    TOIE0 = 0,
    OCIE0 = 1,
    // TIFR Bits
    TOV0 = 0,
    OCF0 = 1,
    // SREG Bits
    GIE  = 7
} T0_BitName_t;

typedef enum
{
    T0_Disable,
    T0_NoPrescaller,
    T0_Prescaller_8,
    T0_Prescaller_64,
    T0_Prescaller_256,
    T0_Prescaller_1024,
    T0_ExternalFalling,
    T0_ExternalRising
} T0_ClockSelectOption_t;

typedef enum 
{
    OC0_Disconnect   = 0x00,
    OC0_Toggle       = 0x10,
    OC0_Clear        = 0x20,
    OC0_Set          = 0x30,
    /* PWM Actions */
    OC0_NonInverting = 0x20,
    OC0_Inverting    = 0x30
} T0_OutputCompare_t;

typedef enum 
{
    T0_NormalMode = 0x00,
    T0_PWMPhase   = 0x40,
    T0_CTCMode    = 0x08,
    T0_PWMFast    = 0x48
} T0_TimerMode_t;

typedef enum 
{
    T0_TOVInterruptDisable = 0x00,
    T0_TOVFInterruptEnable = 0x01,
    T0_OCMInterruptDisable = 0x00,
    T0_OCMInterruptEnable  = 0x02
} T0_InterruptState_t;

/* ISR Declarations */
void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));

#endif // Timer0_Driver

#endif // _MCAL_TIMER0_T0_PRIVATE_H
