/**
 * @file    ADC_Private.h
 * @brief   Private type definitions, enumerations, and masks for the ADC driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @warning Do not include this file directly — include @ref ADC_Interface.h.
 */

#ifndef _MCAL_ADC_ADC_PRIVATE_H_
#define _MCAL_ADC_ADC_PRIVATE_H_


/*  Register Bit Positions  */

/**
 * @enum  Adc_BitName_t
 * @brief Bit positions within ADMUX, ADCSRA, and SFIOR that the ADC driver
 *        uses for configuration and control.
 */
typedef enum
{
    /* ADMUX register */
    MUX0  = 0, /**< Channel / differential MUX select bit 0. */
    MUX1  = 1, /**< Channel / differential MUX select bit 1. */
    MUX2  = 2, /**< Channel / differential MUX select bit 2. */
    MUX3  = 3, /**< Channel / differential MUX select bit 3. */
    MUX4  = 4, /**< Channel / differential MUX select bit 4. */
    ADLAR = 5, /**< ADC Left Adjust Result bit.               */
    REFS0 = 6, /**< Reference Selection bit 0.                */
    REFS1 = 7, /**< Reference Selection bit 1.                */

    /* ADCSRA register */
    ADPS0 = 0, /**< ADC Prescaler Select bit 0. */
    ADPS1 = 1, /**< ADC Prescaler Select bit 1. */
    ADPS2 = 2, /**< ADC Prescaler Select bit 2. */
    ADIE  = 3, /**< ADC Interrupt Enable.        */
    ADIF  = 4, /**< ADC Interrupt Flag.          */
    ADATE = 5, /**< ADC Auto Trigger Enable.     */
    ADSC  = 6, /**< ADC Start Conversion.        */
    ADEN  = 7, /**< ADC Enable.                  */

    /* SFIOR register (Auto Trigger Source) */
    ADTS0 = 5, /**< Auto Trigger Source bit 0.   */
    ADTS1 = 6, /**< Auto Trigger Source bit 1.   */
    ADTS2 = 7  /**< Auto Trigger Source bit 2.   */
} Adc_BitName_t;

/*  Configuration Enumerations  */

/**
 * @enum  Adc_ArefSelect_t
 * @brief Voltage reference source written to REFS1:REFS0 in ADMUX.
 */
typedef enum
{
    Adc_Aref     = 0x00, /**< External AREF pin (no internal reference).     */
    Adc_Avcc     = 0x40, /**< AVCC with external capacitor on AREF pin.      */
    Adc_Internal = 0xC0  /**< Internal 2.56 V voltage reference.             */
} Adc_ArefSelect_t;

/**
 * @enum  Adc_AdjustResult_t
 * @brief Result alignment written to ADLAR bit in ADMUX.
 */
typedef enum
{
    Adc_RightAdjust = 0x00, /**< 10-bit result in ADCL[7:0] + ADCH[1:0].    */
    Adc_LeftAdjust  = 0x20  /**< 8-bit result in ADCH[7:0] (discard ADCL).  */
} Adc_AdjustResult_t;

/**
 * @enum  Adc_PrescalerSelect_t
 * @brief ADC clock prescaler (F_CPU / divider).  ADC needs 50–200 kHz.
 */
typedef enum
{
    Adc_DivisionFactor2   = 1, /**< F_CPU / 2.   */
    Adc_DivisionFactor4   = 2, /**< F_CPU / 4.   */
    Adc_DivisionFactor8   = 3, /**< F_CPU / 8.   */
    Adc_DivisionFactor16  = 4, /**< F_CPU / 16.  */
    Adc_DivisionFactor32  = 5, /**< F_CPU / 32.  */
    Adc_DivisionFactor64  = 6, /**< F_CPU / 64.  */
    Adc_DivisionFactor128 = 7  /**< F_CPU / 128. */
} Adc_PrescalerSelect_t;

/**
 * @enum  Adc_InterruptState_t
 * @brief ADC Conversion Complete interrupt enable state (ADIE bit).
 */
typedef enum
{
    Adc_InterruptDisable = 0x00, /**< Polled / synchronous conversion mode.  */
    Adc_InterruptEnable  = 0x08  /**< ISR-driven / asynchronous mode.        */
} Adc_InterruptState_t;

/**
 * @enum  Adc_Mode_t
 * @brief ADC operating mode — free-running vs. single-shot.
 */
typedef enum
{
    Adc_SingleMode = 0x00, /**< Single conversion; manual ADSC trigger.      */
    Adc_AutoMode   = 0x20  /**< Auto-trigger; source set in SFIOR ADTS[2:0]. */
} Adc_Mode_t;

/**
 * @enum  Adc_State_t
 * @brief ADC peripheral enable state (ADEN bit in ADCSRA).
 */
typedef enum
{
    Adc_Disable = 0x00, /**< ADC peripheral powered off.                     */
    Adc_Enable  = 0x80  /**< ADC peripheral powered on.                      */
} Adc_State_t;

/**
 * @enum  Adc_TriggerSourceSelect_t
 * @brief Auto-trigger source written to ADTS[2:0] in SFIOR (used when
 *        @c Adc_AutoMode is selected).
 */
typedef enum
{
    Adc_FreeRunning       = 0x00, /**< Continuous conversions.               */
    Adc_AnalogComparator  = 0x20, /**< Triggered by Analog Comparator.       */
    Adc_EXTI0             = 0x40, /**< Triggered by External INT0.           */
    Adc_CTC0              = 0x60, /**< Triggered by Timer0 Compare Match.    */
    Adc_OVF0              = 0x80, /**< Triggered by Timer0 Overflow.         */
    Adc_CTC1              = 0xA0, /**< Triggered by Timer1 Compare Match B.  */
    Adc_OVF1              = 0xC0, /**< Triggered by Timer1 Overflow.         */
    Adc_ICU1              = 0xE0  /**< Triggered by Timer1 Input Capture.    */
} Adc_TriggerSourceSelect_t;

/**
 * @enum  Adc_Channel_t
 * @brief Single-ended ADC input channel selection (MUX[4:0] in ADMUX).
 */
typedef enum
{
    Adc_SingleEndedChannel0 = 0, /**< ADC0 — PA0. */
    Adc_SingleEndedChannel1 = 1, /**< ADC1 — PA1. */
    Adc_SingleEndedChannel2 = 2, /**< ADC2 — PA2. */
    Adc_SingleEndedChannel3 = 3, /**< ADC3 — PA3. */
    Adc_SingleEndedChannel4 = 4, /**< ADC4 — PA4. */
    Adc_SingleEndedChannel5 = 5, /**< ADC5 — PA5. */
    Adc_SingleEndedChannel6 = 6, /**< ADC6 — PA6. */
    Adc_SingleEndedChannel7 = 7  /**< ADC7 — PA7. */
} Adc_Channel_t;

/*  Mask Values  */

/**
 * @enum  Adc_MaskingValue_t
 * @brief Bitmasks used internally for register read-modify-write operations.
 */
typedef enum
{
    Adc_TriggerSourceMask = 0xE0, /**< Mask for ADTS[2:0] bits in SFIOR.    */
    Adc_ChannelMask       = 0x1F  /**< Mask for MUX[4:0] bits in ADMUX.     */
} Adc_MaskingValue_t;

/*  Driver State Machine  */

/**
 * @enum  Adc_DriverState_t
 * @brief Internal state of the ADC driver (used to prevent re-entrant calls).
 */
typedef enum
{
    Adc_Uninitialized = 0, /**< @ref ADC_Init() has not been called yet.     */
    Adc_Idle,              /**< Driver ready; no conversion in progress.      */
    Adc_Busy               /**< A conversion is currently in progress.        */
} Adc_DriverState_t;

/*  Error Codes  */

/**
 * @enum  Adc_ErrorState_t
 * @brief Return codes from ADC driver functions.
 */
typedef enum
{
    Adc_Ok               = 0, /**< Operation completed successfully.          */
    Adc_NullPointerErr,       /**< A required output pointer was NULL.        */
    Adc_InvalidChannelErr,    /**< Channel number is out of range (> 7).      */
    Adc_NotInitializedErr,    /**< @ref ADC_Init() was not called first.      */
    Adc_TimerOutErr           /**< Polling loop exceeded @c MaxTimeOut cycles.*/
} Adc_ErrorState_t;

/*  ISR Prototype  */

/** @brief ADC Conversion Complete ISR — vector 16. */
void __vector_16(void) __attribute__((signal));


#endif /* _MCAL_ADC_ADC_PRIVATE_H_ */
