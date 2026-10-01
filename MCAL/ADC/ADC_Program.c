/**
 * @file ADC_Program.c
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#include "ADC_Interface.h"

static uint16_t *ADC_AsyncResult          = NULL;
static void    (*ADC_NotificationCallback)(void) = NULL;

/* Initialization */

void ADC_Init(void)
{
    /* Select Voltage Reference */
    ADMUX_REG = (ADMUX_REG & ADC_VREF_MASK) | (ADC_VREF_SELECTION << REFS0);

    /* Select Result Adjust */
#if ADC_ADJUST_SELECTION == ADC_RIGHT_ADJUST
    ClearBit(ADMUX_REG, ADLAR);
#elif ADC_ADJUST_SELECTION == ADC_LEFT_ADJUST
    SetBit(ADMUX_REG, ADLAR);
#endif

    /* Select Prescaler */
    ADCSRA_REG = (ADCSRA_REG & ADC_PRESCALER_MASK) | (ADC_PRESCALER_SELECTION);

    /* Configure Auto Trigger */
#if ADC_AUTO_TRIGGER_MODE == Enable
    SetBit(ADCSRA_REG, ADATE);
    SFIOR_REG = (SFIOR_REG & ADC_AUTO_TRIGGER_MASK) | (ADC_TRIGGER_SOURCE << ADTS0);
#else
    ClearBit(ADCSRA_REG, ADATE);
#endif

    /* Enable ADC */
    SetBit(ADCSRA_REG, ADEN);
}

/* Enable / Disable */

void ADC_Enable(void)
{
    SetBit(ADCSRA_REG, ADEN);
}

void ADC_Disable(void)
{
    ClearBit(ADCSRA_REG, ADEN);
}

/* Interrupt Control */

void ADC_InterruptEnable(void)
{
    SetBit(ADCSRA_REG, ADIE);
    SetBit(SREG_REG, ADC_GIE);
}

void ADC_InterruptDisable(void)
{
    ClearBit(ADCSRA_REG, ADIE);
}

/* Synchronous Read */

void ADC_ReadChannelSync(ADC_Channel_t Channel, uint16_t *ADC_Value)
{
    if (ADC_Value == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    /* Select Channel - keep REFS and ADLAR bits */
    ADMUX_REG = (ADMUX_REG & ADC_CHANNEL_MASK) | (Channel & 0x1F);

    /* Start Conversion */
    SetBit(ADCSRA_REG, ADSC);

    /* Wait for ADIF flag with timeout guard */
    uint32_t Timeout = 0;
    while ((ReadBit(ADCSRA_REG, ADIF) == 0) && (Timeout < ADC_TIMEOUT_COUNT))
    {
        Timeout++;
    }

    if (Timeout >= ADC_TIMEOUT_COUNT)
    {
        // TODO: Handle Error Here;
        return;
    }

    /* Clear ADIF by writing 1 */
    SetBit(ADCSRA_REG, ADIF);

    /* Read Result */
#if ADC_ADJUST_SELECTION == ADC_RIGHT_ADJUST
    *ADC_Value = ADC_REG;
#elif ADC_ADJUST_SELECTION == ADC_LEFT_ADJUST
    *ADC_Value = ADCH_REG;
#endif
}

/* Asynchronous Read */

void ADC_StartConversionAsync(ADC_Channel_t Channel, uint16_t *ADC_Value, void (*NotificationFunction)(void))
{
    if (ADC_Value == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Channel > ADC_Channel7)
    {
        // TODO: Handle Error Here;
        return;
    }

    ADC_AsyncResult          = ADC_Value;
    ADC_NotificationCallback = NotificationFunction;

    /* Select Channel */
    ADMUX_REG = (ADMUX_REG & ADC_CHANNEL_MASK) | (Channel & 0x1F);

    /* Clear any pending flag */
    SetBit(ADCSRA_REG, ADIF);

    /* Enable ADC Interrupt and Global Interrupt */
    SetBit(ADCSRA_REG, ADIE);
    SetBit(SREG_REG, ADC_GIE);

    /* Start Conversion */
    SetBit(ADCSRA_REG, ADSC);
}

/* Set Callback */

void ADC_SetCallback(void (*NotificationFunction)(void))
{
    if (NotificationFunction == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    ADC_NotificationCallback = NotificationFunction;
}

/* ADC Conversion Complete ISR */

void __vector_16(void)
{
    if (ADC_AsyncResult != NULL)
    {
#if ADC_ADJUST_SELECTION == ADC_RIGHT_ADJUST
        *ADC_AsyncResult = ADC_REG;
#elif ADC_ADJUST_SELECTION == ADC_LEFT_ADJUST
        *ADC_AsyncResult = ADCH_REG;
#endif
        ADC_AsyncResult = NULL;
    }

    /* Disable ADC Interrupt after single-shot conversion */
    ClearBit(ADCSRA_REG, ADIE);

    if (ADC_NotificationCallback != NULL)
    {
        ADC_NotificationCallback();
    }
}
