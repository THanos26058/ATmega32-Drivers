/**
 * @file T2_Program.c
 * @brief Implementation of ATmega32 Timer2 driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#include "../../Common/Config.h"

#if Timer2_Driver

#include "T2_Interface.h"
#include "../DIO/DIO_Interface.h"

#if T2_Normal 
static void (*T2_NormalPF)(void) = NULL;
static uint8_t T2_PreloadValue = T2_InitPreloadValue;

void T2_NormalInit(void)
{
#if (T2_ClockSource == T2_ClockSource_AsynchronousTOSC1)
    /* Enable Asynchronous mode using 32.768kHz TOSC1 crystal */
    SetBit(ASSR_Reg, AS2);
#else
    ClearBit(ASSR_Reg, AS2);
#endif

    // TCCR2
    //! 1. Wave Generation Mode as Normal Mode 
    //! 2. Select Output Compare Match Disconnect 
    //! 3. Clock Select -> Prescaler 
    TCCR2_Reg = (uint8_t)(T2_NormalMode | OC2_Disconnect | T2_ClockSelect);  
    // TCNT2 -> Initial Value Preload 
    TCNT2_Reg = T2_InitPreloadValue;
    // TIMSK -> Enable for OVF Interrupt 
    SetBit(TIMSk_Reg, TOIE2);
    // SREG -> Enable Global Interrupt
    SetBit(SREG_Reg, GIE);
}

void T2_SetPreLoad(uint8_t PreloadValue)
{
    TCNT2_Reg = PreloadValue;
    T2_PreloadValue = PreloadValue;
}

void T2_NormalCallBack(void(*PF)(void))
{
    if (PF != NULL)
    {
        T2_NormalPF = PF;
    }      
}

void __vector_5(void)
{
    static uint32_t count = 0;
    count++;
    if (count >= T2_NoOfOVFCount)
    {
        // Action 
        if (T2_NormalPF != NULL)
        {
            T2_NormalPF();
        }
        // Clear Count 
        count = 0; 
        // Update Preload  
        TCNT2_Reg = T2_PreloadValue;
    }
}
#endif // T2_Normal

#if T2_CTC
static void (*T2_CTCPF)(void) = NULL;

void T2_CTCInit(void)
{
#if (T2_CTC_OC2Action != OC2_Disconnect)
    /* Configure OC2 (PD7) as Output Pin for hardware waveform generation */
    DIO_DirectionSelectForPin(DIO_GroupD, DIO_Pin7, DIO_Output);
#endif

#if (T2_ClockSource == T2_ClockSource_AsynchronousTOSC1)
    SetBit(ASSR_Reg, AS2);
#else
    ClearBit(ASSR_Reg, AS2);
#endif

    //! 1. Wave Generation Mode as CTC Mode
    //! 2. Select Output Compare Action
    //! 3. Clock Select Prescaler
    TCCR2_Reg = (uint8_t)(T2_CTCMode | T2_CTC_OC2Action | T2_ClockSelect);

    //! Initialize Output Compare Register
    OCR2_Reg = T2_OCR2Value;

    //! Clear Timer Counter Register
    TCNT2_Reg = 0;

    //! TIMSK -> Enable for Output Compare Match Interrupt
    SetBit(TIMSk_Reg, OCIE2);

    //! SREG -> Enable Global Interrupt
    SetBit(SREG_Reg, GIE);
}

void T2_SetCompareValue(uint8_t CompareValue)
{
    OCR2_Reg = CompareValue;
}

void T2_CTCCallBack(void(*PF)(void))
{
    if (PF != NULL)
    {
        T2_CTCPF = PF;
    }
}

void __vector_4(void)
{
    static uint32_t count = 0;
    count++;
    if (count >= T2_NoOfCompareMatchCount)
    {
        // Action
        if (T2_CTCPF != NULL)
        {
            T2_CTCPF();
        }
        // Clear Count
        count = 0;
    }
}
#endif // T2_CTC

#if T2_PWM
void T2_PwmInit(void)
{
    //! Configure OC2 (PD7) as Output Pin
    DIO_DirectionSelectForPin(DIO_GroupD, DIO_Pin7, DIO_Output);

    //! 1. Select PWM Mode (Fast PWM or Phase Correct)
    //! 2. Select Action (Non-Inverting or Inverting)
    //! 3. Clock Select Prescaler
    TCCR2_Reg = (uint8_t)(T2_PWMMode | T2_PWMAction | T2_ClockSelect);

    //! Initialize Output Compare Register to 0 (0% duty cycle)
    OCR2_Reg = 0;
}

void T2_SetDutyCycle(uint8_t DutyCyclePre)
{
    if (DutyCyclePre <= 100)
    {
        if (T2_PWMAction == OC2_NonInverting)
        {
            // Compare value (OCR2) = (255 * DutyCycle) / 100
            OCR2_Reg = (uint8_t)((255UL * DutyCyclePre) / 100);
        }
        else if (T2_PWMAction == OC2_Inverting)
        {
            // Compare value (OCR2) = 255 - (255 * DutyCycle) / 100
            OCR2_Reg = (uint8_t)(255 - ((255UL * DutyCyclePre) / 100));
        }
    }
}
#endif // T2_PWM

void T2_SetClock(uint8_t ClockSelect)
{
    TCCR2_Reg = (TCCR2_Reg & 0xF8) | (ClockSelect & 0x07);
}

void T2_Stop(void)
{
    TCCR2_Reg = (TCCR2_Reg & 0xF8) | T2_Disable;
}

#endif // Timer2_Driver
