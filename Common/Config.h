/**
 * @file    Config.h
 * @brief   Project-wide configuration switches for the ATmega32 driver library.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Central header that:
 *          - Defines the CPU frequency (@ref F_CPU) used by delay utilities.
 *          - Enables / disables each MCAL and HAL driver via preprocessor
 *            switches so unused drivers are excluded from the build.
 *          - Selects the operating mode (Normal / CTC / PWM) for each timer.
 *
 * @note    Edit only the defines in this file to configure the project;
 *          never modify the individual driver source files for build-level
 *          settings.
 */

#ifndef _COMMON_CONFIG_H
#define _COMMON_CONFIG_H

#include "Definition.h"

/*  CPU Frequency  */

/**
 * @def    F_CPU
 * @brief  ATmega32 system clock frequency in Hz.
 *         Override at the compiler command line with -DF_CPU=<value> if needed.
 */
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

/*  MCAL Driver Switches  */

/**
 * @defgroup McalSwitches MCAL Driver Enable/Disable Switches
 * @brief    Set to @c Enable to include a driver in the build, @c Disable to
 *           exclude it and reduce code size.
 * @{
 */
#define ADC_Driver          Enable  /**< Analog-to-Digital Converter driver   */
#define DIO_Driver          Enable  /**< Digital I/O driver                   */
#define EXTI_Driver         Enable  /**< External Interrupt driver            */
#define GIE_Driver          Enable  /**< Global Interrupt Enable driver       */
#define InternalEEPROM      Enable  /**< Internal EEPROM driver (stub)        */
#define SPI_Driver          Enable  /**< SPI driver (stub)                    */
#define Timer0_Driver       Enable  /**< 8-bit Timer0 driver                  */
#define Timer1_Driver       Enable  /**< 16-bit Timer1 driver                 */
#define Timer2_Driver       Enable  /**< 8-bit Timer2 driver                  */
#define TWI_Driver          Enable  /**< TWI / I²C driver (stub)              */
#define Usart_Driver        Enable  /**< USART driver (stub)                  */

/*  HAL Driver Switches  */

#define Button_Driver       Enable  /**< Push-button driver                   */
#define Buzzer_Driver       Enable  /**< Buzzer driver                        */
#define DcMotor_Driver      Enable  /**< DC motor driver                      */
#define Kpd_Driver          Enable  /**< Matrix keypad driver                 */
#define Lcd_Driver          Enable  /**< LCD 16×2 driver                      */
#define Led_Driver          Enable  /**< LED driver                           */
#define SevSeg_Driver       Enable  /**< Seven-segment display driver         */
#define Ldr_Driver          Enable  /**< LDR light-sensor driver              */
#define Lm35_Driver         Enable  /**< LM35 temperature-sensor driver       */

/*  Timer0 Mode Switches  */

#if Timer0_Driver
/**
 * @defgroup Timer0Modes Timer0 Operating Mode Switches
 * @brief    Enable all modes simultaneously; the application selects which
 *           init function to call at run time.
 * @{
 */
#define T0_Normal           Enable  /**< Overflow  (Normal) mode              */
#define T0_CTC              Enable  /**< Clear Timer on Compare Match mode    */
#define T0_PWM              Enable  /**< Fast PWM / Phase-Correct PWM mode    */
#endif /* Timer0_Driver */

/*  Timer1 Mode Switches  */

#if Timer1_Driver
#define T1_Normal           Enable  /**< Overflow  (Normal) mode              */
#define T1_CTC              Enable  /**< CTC mode (TOP = OCR1A)               */
#define T1_PWM              Enable  /**< Fast PWM / Phase-Correct PWM mode    */
#define T1_ICU              Enable  /**< Input Capture Unit mode              */
#endif /* Timer1_Driver */

/*  Timer2 Mode Switches  */

#if Timer2_Driver
#define T2_Normal           Enable  /**< Overflow  (Normal) mode              */
#define T2_CTC              Enable  /**< Clear Timer on Compare Match mode    */
#define T2_PWM              Enable  /**< Fast PWM / Phase-Correct PWM mode    */
#endif /* Timer2_Driver */

#endif /* _COMMON_CONFIG_H */
