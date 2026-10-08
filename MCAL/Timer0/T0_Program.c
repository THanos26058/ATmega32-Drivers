/**
 * @file T0_Program.c
 * @brief Implementation of ATmega32 Timer0 driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#include "../../Common/Config.h"

#if Timer0_Driver

#include "T0_Interface.h"
#include "../DIO/DIO_Interface.h"

#if T0_Normal 
static void (*NormalPF)(void) = NULL;
static uint8_t T0_PreloadValue = T0_InitPreloadValue;

void T0_NormalInit(void)
{
    // TCCR0
    //! 1. Wave Generation Mode as Normal Mode 
    //! 2. Select Output Compare Match Disconnect 
    //! 3. Clock Select -> Prescaler 
    TCCR0_Reg = (uint8_t)(T0_NormalMode | OC0_Disconnect | T0_ClockSelect);  
    // TCNT -> Initial Value Preload 
    TCNT0_Reg = T0_InitPreloadValue;
    // TIMSK -> Enable for OVF Interrupt 
    SetBit(TIMSk_Reg, TOIE0);
    // SREG -> Enable Global Interrupt
    SetBit(SREG_Reg, GIE);
}

void T0_SetPreLoad(uint8_t PreloadValue)
{
    TCNT0_Reg = PreloadValue;
    T0_PreloadValue = PreloadValue;
}

void T0_NormalCallBack(void(*PF)(void))
{
    if (PF != NULL)
    {
        NormalPF = PF;
    }      
}

void __vector_11(void)
{
    static uint32_t count = 0;
    count++;
    if (count >= T0_NoOfOVFCount)
    {
        // Action 
        if (NormalPF != NULL)
        {
            NormalPF();
        }
        // Clear Count 
        count = 0; 
        // Update Preload  
        TCNT0_Reg = T0_PreloadValue;
    }
}
#endif // T0_Normal

#if T0_CTC
static void (*CTCPF)(void) = NULL;

void T0_CTCInit(void)
{
#if (T0_CTC_OC0Action != OC0_Disconnect)
    /* Configure OC0 (PB3) as Output Pin for hardware waveform generation */
    DIO_DirectionSelectForPin(DIO_GroupB, DIO_Pin3, DIO_Output);
#endif

    //! 1. Wave Generation Mode as CTC Mode
    //! 2. Select Output Compare Action
    //! 3. Clock Select Prescaler
    TCCR0_Reg = (uint8_t)(T0_CTCMode | T0_CTC_OC0Action | T0_ClockSelect);

    //! Initialize Output Compare Register
    OCR0_Reg = T0_OCR0Value;

    //! Clear Timer Counter Register
    TCNT0_Reg = 0;

    //! TIMSK -> Enable for Output Compare Match Interrupt
    SetBit(TIMSk_Reg, OCIE0);

    //! SREG -> Enable Global Interrupt
    SetBit(SREG_Reg, GIE);
}

void T0_SetCompareValue(uint8_t CompareValue)
{
    OCR0_Reg = CompareValue;
}

void T0_CTCCallBack(void(*PF)(void))
{
    if (PF != NULL)
    {
        CTCPF = PF;
    }
}

void __vector_10(void)
{
    static uint32_t count = 0;
    count++;
    if (count >= T0_NoOfCompareMatchCount)
    {
        // Action
        if (CTCPF != NULL)
        {
            CTCPF();
        }
        // Clear Count
        count = 0;
    }
}
#endif // T0_CTC

#if T0_PWM
void T0_PwmInit(void)
{
    //! Configure OC0 (PB3) as Output Pin
    DIO_DirectionSelectForPin(DIO_GroupB, DIO_Pin3, DIO_Output);

    //! 1. Select PWM Mode (Fast PWM or Phase Correct)
    //! 2. Select Action (Non-Inverting or Inverting)
    //! 3. Clock Select Prescaler
    TCCR0_Reg = (uint8_t)(T0_PWMMode | T0_PWMAction | T0_ClockSelect);

    //! Initialize Output Compare Register to 0 (0% duty cycle)
    OCR0_Reg = 0;
}

void T0_SetDutyCycle(uint8_t DutyCyclePre)
{
    if (DutyCyclePre <= 100)
    {
        if (T0_PWMAction == OC0_NonInverting)
        {
            // Compare value (OCR0) = (255 * DutyCycle) / 100
            OCR0_Reg = (uint8_t)((255UL * DutyCyclePre) / 100);
        }
        else if (T0_PWMAction == OC0_Inverting)
        {
            // Compare value (OCR0) = 255 - (255 * DutyCycle) / 100
            OCR0_Reg = (uint8_t)(255 - ((255UL * DutyCyclePre) / 100));
        }
    }
}
#endif // T0_PWM

void T0_SetClock(uint8_t ClockSelect)
{
    TCCR0_Reg = (TCCR0_Reg & 0xF8) | (ClockSelect & 0x07);
}

void T0_Stop(void)
{
    TCCR0_Reg = (TCCR0_Reg & 0xF8) | T0_Disable;
}

#endif // Timer0_Driver
