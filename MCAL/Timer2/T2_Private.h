/**
 * @file T2_Private.h
 * @brief Private definitions, registers, and bit mappings for Timer2 driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#ifndef _MCAL_TIMER2_T2_PRIVATE_H
#define _MCAL_TIMER2_T2_PRIVATE_H

#include "../../Common/Config.h"
#include "../Atmega32Registers.h"



#if Timer2_Driver

typedef enum
{
    // TCCR2 Bits
    CS20 = 0,
    CS21,
    CS22,
    WGM21,
    COM20,
    COM21,
    WGM20,
    FOC2,
    // TIMSK Bits
    TOIE2 = 6,
    OCIE2 = 7,
    // TIFR Bits
    TOV2  = 6,
    OCF2  = 7,
    // ASSR Bits
    TCR2UB = 0,
    OCR2UB = 1,
    TCN2UB = 2,
    AS2    = 3,
    // SREG Bits
    GIE    = 7
} T2_BitName_t;

typedef enum
{
    T2_Disable,
    T2_NoPrescaller,
    T2_Prescaller_8,
    T2_Prescaller_32,
    T2_Prescaller_64,
    T2_Prescaller_128,
    T2_Prescaller_256,
    T2_Prescaller_1024
} T2_ClockSelectOption_t;

typedef enum 
{
    OC2_Disconnect   = 0x00,
    OC2_Toggle       = 0x10,
    OC2_Clear        = 0x20,
    OC2_Set          = 0x30,
    /* PWM Actions */
    OC2_NonInverting = 0x20,
    OC2_Inverting    = 0x30
} T2_OutputCompare_t;

typedef enum 
{
    T2_NormalMode = 0x00,
    T2_PWMPhase   = 0x40,
    T2_CTCMode    = 0x08,
    T2_PWMFast    = 0x48
} T2_TimerMode_t;

typedef enum
{
    T2_ClockSource_Internal,
    T2_ClockSource_AsynchronousTOSC1
} T2_AsynchronousMode_t;

/* ISR Declarations */
void __vector_4(void) __attribute__((signal)); /* Timer2 Compare Match */
void __vector_5(void) __attribute__((signal)); /* Timer2 Overflow */

#endif // Timer2_Driver

#endif // _MCAL_TIMER2_T2_PRIVATE_H
