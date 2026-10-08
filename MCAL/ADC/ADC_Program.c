/**
 * @file    ADC_Program.c
 * @brief   Implementation of the ATmega32 ADC driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Implements synchronous and asynchronous analog-to-digital conversions.
 *          Features a state machine (Uninitialized -> Idle <-> Busy) to protect
 *          against concurrent access to the ADC hardware.
 */

#include "ADC_Interface.h"

#if ADC_Driver

/*  Private Variables  */

/** @brief Internal driver state to prevent concurrent access conflicts. */
static volatile uint8_t ADC_State = Adc_Uninitialized;

/** @brief Pointer to the user-supplied callback for asynchronous conversions. */
static void (*ADC_Callback)(uint16_t Result) = NULL;

/*  Private Helper Functions  */

/**
 * @brief  Configure ADMUX register for a specific channel.
 * @param[in] Channel ADC channel (0-7).
 */
static void ADC_SelectChannel(uint8_t Channel)
{
    /* Clear Channel Bits in ADMUX (4:0), apply new channel with mask */
    ADMUX_REG = (ADMUX_REG & ~Adc_ChannelMask) | (Channel & Adc_ChannelMask);
}

/*  Public API  */

void ADC_Init(void)
{
    if (ADC_State != Adc_Uninitialized)
    {
        return; /* Already initialized */
    }

    /* Configure ADMUX: Voltage Reference & Result Adjust */
    ADMUX_REG = Adc_VrefSelection | Adc_AdjustSelection;

    /* Configure ADCSRA: Enable, Mode, Interrupts, Prescaler */
    ADCSRA_REG = Adc_InitState | Adc_ModeSelect | Adc_InterrupState | Adc_DivisionFactorSelection;

    /* Configure SFIOR: Auto-trigger source (if Auto Mode is selected) */
#if Adc_ModeSelect == Adc_AutoMode
    SFIOR_REG = (SFIOR_REG & ~Adc_TriggerSourceMask) | Adc_TriggerSource;
#endif

    ADC_State = Adc_Idle;
}

void ADC_DeInit(void)
{
    ClearBit(ADCSRA_REG, ADIF); /* Clear flag */
    ClearBit(ADCSRA_REG, ADIE); /* Disable Interrupt */
    ClearBit(ADCSRA_REG, ADEN); /* Disable ADC */
    ADC_State = Adc_Uninitialized;
}

void ADC_Enable(void)
{
    SetBit(ADCSRA_REG, ADEN);
}

void ADC_Disable(void)
{
    ClearBit(ADCSRA_REG, ADEN);
}

void ADC_EnableInterrupt(void)
{
    SetBit(ADCSRA_REG, ADIE);
}

void ADC_DisableInterrupt(void)
{
    ClearBit(ADCSRA_REG, ADIE);
}

uint8_t ADC_Read(uint8_t Channel, uint16_t *DigitalValue, uint32_t MaxTimeOut)
{
    uint32_t LocalTimeOut = 0;

    if (DigitalValue == NULL)          { return Adc_NullPointerErr; }
    if (Channel > Adc_SingleEndedChannel7) { return Adc_InvalidChannelErr; }
    if (ADC_State == Adc_Uninitialized) { return Adc_NotInitializedErr; }
    if (ADC_State == Adc_Busy)         { return Adc_Busy; } /* Re-entrancy protection */

    ADC_State = Adc_Busy;
    ADC_SelectChannel(Channel);

    /* Start Conversion */
    SetBit(ADCSRA_REG, ADSC);

    /* Wait for conversion to finish (ADIF flag goes high) or timeout */
    while (ReadBit(ADCSRA_REG, ADIF) == 0)
    {
        if (LocalTimeOut >= MaxTimeOut)
        {
            ADC_State = Adc_Idle;
            return Adc_TimerOutErr;
        }
        LocalTimeOut++;
    }

    /* Clear ADIF manually by writing logical 1 to it */
    SetBit(ADCSRA_REG, ADIF);

    /* Read result based on adjustment selection */
#if Adc_AdjustSelection == Adc_LeftAdjust
    *DigitalValue = ADCH_REG;       /* 8-bit resolution */
#else
    *DigitalValue = ADC_REG;        /* 10-bit resolution */
#endif

    ADC_State = Adc_Idle;
    return Adc_Ok;
}

uint8_t ADC_StartConversion(uint8_t Channel)
{
    if (Channel > Adc_SingleEndedChannel7) { return Adc_InvalidChannelErr; }
    if (ADC_State == Adc_Uninitialized) { return Adc_NotInitializedErr; }
    if (ADC_State == Adc_Busy)         { return Adc_Busy; }

    ADC_State = Adc_Busy;
    ADC_SelectChannel(Channel);

    /* Enable ADC interrupt so ISR fires when done */
    SetBit(ADCSRA_REG, ADIE);

    /* Start Conversion */
    SetBit(ADCSRA_REG, ADSC);

    return Adc_Ok;
}

uint8_t ADC_SetCallBack(void (*ADC_PF)(uint16_t Result))
{
    if (ADC_PF == NULL) { return Adc_NullPointerErr; }
    
    ADC_Callback = ADC_PF;
    return Adc_Ok;
}

uint8_t ADC_GetStatus(void)
{
    return ADC_State;
}

/*  ISR Vector  */

/**
 * @brief  ADC Conversion Complete Interrupt Handler.
 * @details Reads the ADC data register and passes it to the user callback,
 *          then returns the driver state to Adc_Idle.
 */
void __vector_16(void)
{
    uint16_t result = 0;

#if Adc_AdjustSelection == Adc_LeftAdjust
    result = ADCH_REG;
#else
    result = ADC_REG;
#endif

    ADC_State = Adc_Idle;

    if (ADC_Callback != NULL)
    {
        ADC_Callback(result);
    }
}

#endif /* ADC_Driver */
