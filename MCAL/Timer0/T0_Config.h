/**
 * @file T0_Config.h
 * @brief Configuration parameters for Timer0 driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#ifndef _MCAL_TIMER0_T0_CONFIG_H
#define _MCAL_TIMER0_T0_CONFIG_H

#include "../../Common/Config.h"

#if Timer0_Driver

/**
 * Clock Select Prescaler:
 * 1- T0_Disable
 * 2- T0_NoPrescaller
 * 3- T0_Prescaller_8
 * 4- T0_Prescaller_64
 * 5- T0_Prescaller_256
 * 6- T0_Prescaller_1024
 * 7- T0_ExternalFalling
 * 8- T0_ExternalRising
 */
#define T0_ClockSelect           T0_Prescaller_64

#if T0_Normal
/**
 * Calculations for 100ms Tick @ 8MHz F_CPU and Prescaler 64:
 * Clock Tick time = 64 / 8,000,000 = 8 us
 * Total OverFlow time = 256 * 8 us = 2048 us
 * Number of Overflows = 100,000 us / 2048 us = 48.828125
 * Total Overflows count = ceil(48.828125) = 49
 * Preload Value = 256 * (1 - 0.828125) = 44
 */
#define T0_InitPreloadValue      44
#define T0_NoOfOVFCount          49
#endif // T0_Normal

#if T0_CTC
/**
 * Compare Match Value (0 - 255)
 */
#define T0_OCR0Value             250

/**
 * Number of Compare Matches before invoking callback
 */
#define T0_NoOfCompareMatchCount 100

/**
 * Hardware Action on Pin OC0 (PB3) upon Compare Match:
 * 1- OC0_Disconnect
 * 2- OC0_Toggle
 * 3- OC0_Clear
 * 4- OC0_Set
 */
#define T0_CTC_OC0Action         OC0_Disconnect
#endif // T0_CTC

#if T0_PWM
    /**
     * PWM Mode:
     * 1- T0_PWMFast 
     * 2- T0_PWMPhase 
     */
    #define T0_PWMMode           T0_PWMFast

    /**
     * PWM Action on Pin OC0 (PB3):
     * 1- OC0_NonInverting 
     * 2- OC0_Inverting 
     */
    #define T0_PWMAction         OC0_NonInverting
#endif // T0_PWM

#endif // Timer0_Driver

#endif // _MCAL_TIMER0_T0_CONFIG_H
