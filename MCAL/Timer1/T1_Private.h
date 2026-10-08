/**
 * @file T1_Private.h
 * @brief Private definitions, registers, and bit mappings for Timer1 (16-bit) driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#ifndef _MCAL_TIMER1_T1_PRIVATE_H
#define _MCAL_TIMER1_T1_PRIVATE_H

#include "../../Common/Config.h"
#include "../Atmega32Registers.h"



#if Timer1_Driver

typedef enum
{
    // TCCR1A Bits
    WGM10  = 0,
    WGM11  = 1,
    FOC1B  = 2,
    FOC1A  = 3,
    COM1B0 = 4,
    COM1B1 = 5,
    COM1A0 = 6,
    COM1A1 = 7,
    // TCCR1B Bits
    CS10   = 0,
    CS11   = 1,
    CS12   = 2,
    WGM12  = 3,
    WGM13  = 4,
    ICES1  = 6,
    ICNC1  = 7,
    // TIMSK Bits
    TOIE1  = 2,
    OCIE1B = 3,
    OCIE1A = 4,
    TICIE1 = 5,
    // TIFR Bits
    TOV1   = 2,
    OCF1B  = 3,
    OCF1A  = 4,
    ICF1   = 5,
    // SREG Bits
    GIE    = 7
} T1_BitName_t;

typedef enum
{
    T1_Disable,
    T1_NoPrescaller,
    T1_Prescaller_8,
    T1_Prescaller_64,
    T1_Prescaller_256,
    T1_Prescaller_1024,
    T1_ExternalFalling,
    T1_ExternalRising
} T1_ClockSelectOption_t;

typedef enum 
{
    OC1_Disconnect   = 0x00,
    OC1_Toggle       = 0x01,
    OC1_Clear        = 0x02,
    OC1_Set          = 0x03,
    /* PWM Actions */
    OC1_NonInverting = 0x02,
    OC1_Inverting    = 0x03
} T1_OutputCompare_t;

typedef enum
{
    T1_Normal_Mode                 = 0,
    T1_PWM_PhaseCorrect_8bit       = 1,
    T1_PWM_PhaseCorrect_9bit       = 2,
    T1_PWM_PhaseCorrect_10bit      = 3,
    T1_CTC_OCR1A_Mode              = 4,
    T1_FastPWM_8bit                = 5,
    T1_FastPWM_9bit                = 6,
    T1_FastPWM_10bit               = 7,
    T1_PWM_PhaseAndFreq_ICR1       = 8,
    T1_PWM_PhaseAndFreq_OCR1A      = 9,
    T1_PWM_PhaseCorrect_ICR1       = 10,
    T1_PWM_PhaseCorrect_OCR1A      = 11,
    T1_CTC_ICR1_Mode               = 12,
    T1_FastPWM_ICR1                = 14,
    T1_FastPWM_OCR1A               = 15
} T1_TimerMode_t;

typedef enum
{
    T1_ICU_Trigger_Falling = 0,
    T1_ICU_Trigger_Rising  = 1
} T1_ICU_Edge_t;

/* ISR Declarations */
void __vector_6(void) __attribute__((signal)); /* Timer1 Capture Event */
void __vector_7(void) __attribute__((signal)); /* Timer1 Compare Match A */
void __vector_8(void) __attribute__((signal)); /* Timer1 Compare Match B */
void __vector_9(void) __attribute__((signal)); /* Timer1 Overflow */

#endif // Timer1_Driver

#endif // _MCAL_TIMER1_T1_PRIVATE_H
