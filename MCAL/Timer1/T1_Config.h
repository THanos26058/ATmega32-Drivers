/**
 * @file T1_Config.h
 * @brief Configuration parameters for Timer1 (16-bit) driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#ifndef _MCAL_TIMER1_T1_CONFIG_H
#define _MCAL_TIMER1_T1_CONFIG_H

#include "../../Common/Config.h"

#if Timer1_Driver

/**
 * Clock Select Prescaler for Timer1:
 * 1- T1_Disable
 * 2- T1_NoPrescaller
 * 3- T1_Prescaller_8
 * 4- T1_Prescaller_64
 * 5- T1_Prescaller_256
 * 6- T1_Prescaller_1024
 * 7- T1_ExternalFalling
 * 8- T1_ExternalRising
 */
#define T1_ClockSelect           T1_Prescaller_64

#if T1_Normal
#define T1_InitPreloadValue      0
#define T1_NoOfOVFCount          1
#endif // T1_Normal

#if T1_CTC
/**
 * Compare Match Value for OCR1A
 */
#define T1_OCR1AValue            1000
#define T1_NoOfCompareMatchCount 1

/**
 * Hardware Action on Pin OC1A (PD5):
 * 1- OC1_Disconnect
 * 2- OC1_Toggle
 * 3- OC1_Clear
 * 4- OC1_Set
 */
#define T1_CTC_OC1AAction        OC1_Disconnect
#endif // T1_CTC

#if T1_PWM
/**
 * Fast PWM Mode (e.g. T1_FastPWM_ICR1 for Servo control with ICR1 as Top)
 */
#define T1_PWMMode               T1_FastPWM_ICR1

/**
 * Top Value in ICR1 (e.g. 20000 for 50Hz / 20ms period with 1MHz timer tick)
 */
#define T1_PWM_TopValue          20000U

/**
 * Action on Channel A (PD5) & Channel B (PD4):
 * 1- OC1_Disconnect
 * 2- OC1_NonInverting
 * 3- OC1_Inverting
 */
#define T1_PWM_ChannelAAction    OC1_NonInverting
#define T1_PWM_ChannelBAction    OC1_Disconnect
#endif // T1_PWM

#if T1_ICU
/**
 * Initial ICU Trigger Edge:
 * T1_ICU_Trigger_Rising
 * T1_ICU_Trigger_Falling
 */
#define T1_ICU_InitialEdge       T1_ICU_Trigger_Rising
#endif // T1_ICU

#endif // Timer1_Driver

#endif // _MCAL_TIMER1_T1_CONFIG_H
