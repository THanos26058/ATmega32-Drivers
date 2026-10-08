/**
 * @file T2_Config.h
 * @brief Configuration parameters for Timer2 driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#ifndef _MCAL_TIMER2_T2_CONFIG_H
#define _MCAL_TIMER2_T2_CONFIG_H

#include "../../Common/Config.h"

#if Timer2_Driver

/**
 * Clock Select Prescaler for Timer2:
 * 1- T2_Disable
 * 2- T2_NoPrescaller
 * 3- T2_Prescaller_8
 * 4- T2_Prescaller_32
 * 5- T2_Prescaller_64
 * 6- T2_Prescaller_128
 * 7- T2_Prescaller_256
 * 8- T2_Prescaller_1024
 */
#define T2_ClockSelect           T2_Prescaller_64

/**
 * Clock Source Mode:
 * T2_ClockSource_Internal
 * T2_ClockSource_AsynchronousTOSC1 (for 32.768kHz watch crystal RTC)
 */
#define T2_ClockSource           T2_ClockSource_Internal

#if T2_Normal
/**
 * Initial Preload and Overflow Counts
 */
#define T2_InitPreloadValue      44
#define T2_NoOfOVFCount          49
#endif // T2_Normal

#if T2_CTC
/**
 * Compare Match Value (0 - 255)
 */
#define T2_OCR2Value             250

/**
 * Number of Compare Matches before invoking callback
 */
#define T2_NoOfCompareMatchCount 100

/**
 * Hardware Action on Pin OC2 (PD7) upon Compare Match:
 * 1- OC2_Disconnect
 * 2- OC2_Toggle
 * 3- OC2_Clear
 * 4- OC2_Set
 */
#define T2_CTC_OC2Action         OC2_Disconnect
#endif // T2_CTC

#if T2_PWM
    /**
     * PWM Mode:
     * 1- T2_PWMFast 
     * 2- T2_PWMPhase 
     */
    #define T2_PWMMode           T2_PWMFast

    /**
     * PWM Action on Pin OC2 (PD7):
     * 1- OC2_NonInverting 
     * 2- OC2_Inverting 
     */
    #define T2_PWMAction         OC2_NonInverting
#endif // T2_PWM

#endif // Timer2_Driver

#endif // _MCAL_TIMER2_T2_CONFIG_H
