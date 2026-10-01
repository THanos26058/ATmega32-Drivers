/**
 * @file ADC_Private.h
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#ifndef _MCAL_ADC_ADC_PRIVATE_H_
#define _MCAL_ADC_ADC_PRIVATE_H_

/* ADMUX Register Bit Positions */
typedef enum
{
    MUX0  = 0,
    MUX1  = 1,
    MUX2  = 2,
    MUX3  = 3,
    MUX4  = 4,
    ADLAR = 5,
    REFS0 = 6,
    REFS1 = 7
} ADC_ADMUX_Bit_t;

/* ADCSRA Register Bit Positions */
typedef enum
{
    ADPS0 = 0,
    ADPS1 = 1,
    ADPS2 = 2,
    ADIE  = 3,
    ADIF  = 4,
    ADATE = 5,
    ADSC  = 6,
    ADEN  = 7
} ADC_ADCSRA_Bit_t;

/* SFIOR Register Bit Positions (Auto Trigger Source) */
typedef enum
{
    ADTS0 = 5,
    ADTS1 = 6,
    ADTS2 = 7
} ADC_SFIOR_Bit_t;

/* SREG Register Bit Position */
typedef enum
{
    ADC_GIE = 7
} ADC_SREG_Bit_t;

/* Voltage Reference Selections */
#define ADC_VREF_AREF             0
#define ADC_VREF_AVCC             1
#define ADC_VREF_INTERNAL_2_56    3

/* Prescaler Division Factors */
#define ADC_PRESCALER_2           1
#define ADC_PRESCALER_4           2
#define ADC_PRESCALER_8           3
#define ADC_PRESCALER_16          4
#define ADC_PRESCALER_32          5
#define ADC_PRESCALER_64          6
#define ADC_PRESCALER_128         7

/* Result Adjust */
#define ADC_RIGHT_ADJUST          0
#define ADC_LEFT_ADJUST           1

/* Auto Trigger Sources */
#define ADC_TRIGGER_FREE_RUNNING         0
#define ADC_TRIGGER_ANALOG_COMPARATOR    1
#define ADC_TRIGGER_EXTI0                2
#define ADC_TRIGGER_TIMER0_COMPARE_MATCH 3
#define ADC_TRIGGER_TIMER0_OVERFLOW      4
#define ADC_TRIGGER_TIMER1_COMPARE_MATCH 5
#define ADC_TRIGGER_TIMER1_OVERFLOW      6
#define ADC_TRIGGER_TIMER1_CAPTURE_EVENT 7

/* Register Bit Masks */
#define ADC_CHANNEL_MASK          0xE0    /* Keep REFS1,REFS0,ADLAR  - clear MUX[4:0] */
#define ADC_VREF_MASK             0x3F    /* Keep ADLAR,MUX[4:0]     - clear REFS[1:0]*/
#define ADC_PRESCALER_MASK        0xF8    /* Keep upper 5 bits       - clear ADPS[2:0]*/
#define ADC_AUTO_TRIGGER_MASK     0x1F    /* Keep lower 5 bits       - clear ADTS[2:0]*/

/* ADC Conversion Complete ISR Prototype (vector 16) */
void __vector_16(void) __attribute__((signal));

#endif // _MCAL_ADC_ADC_PRIVATE_H_
