/**
 * @file T1_Program.c
 * @brief Implementation of ATmega32 Timer1 (16-bit) driver
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date 2026-10-08
 * @version 0.1
 */

#include "../../Common/Config.h"

#if Timer1_Driver

#include "T1_Interface.h"
#include "../DIO/DIO_Interface.h"

#if T1_Normal
static void (*T1_NormalPF)(void) = NULL;
static uint16_t T1_PreloadValue = T1_InitPreloadValue;

void T1_NormalInit(void)
{
    // Normal Mode: WGM13:10 = 0000
    TCCR1A_Reg = 0;
    TCCR1B_Reg = (T1_ClockSelect & 0x07);

    TCNT1_Reg = T1_InitPreloadValue;

    // Enable Overflow Interrupt
    SetBit(TIMSk_Reg, TOIE1);
    SetBit(SREG_Reg, GIE);
}

void T1_SetPreLoad(uint16_t PreloadValue)
{
    TCNT1_Reg = PreloadValue;
    T1_PreloadValue = PreloadValue;
}

void T1_NormalCallBack(void(*PF)(void))
{
    if (PF != NULL)
    {
        T1_NormalPF = PF;
    }
}

void __vector_9(void)
{
    static uint32_t count = 0;
    count++;
    if (count >= T1_NoOfOVFCount)
    {
        if (T1_NormalPF != NULL)
        {
            T1_NormalPF();
        }
        count = 0;
        TCNT1_Reg = T1_PreloadValue;
    }
}
#endif // T1_Normal

#if T1_CTC
static void (*T1_COMPA_PF)(void) = NULL;
static void (*T1_COMPB_PF)(void) = NULL;

void T1_CTCInit(void)
{
#if (T1_CTC_OC1AAction != OC1_Disconnect)
    // Configure OC1A (PD5) as output
    DIO_DirectionSelectForPin(DIO_GroupD, DIO_Pin5, DIO_Output);
#endif

    // CTC Mode 4 (TOP = OCR1A): WGM13:10 = 0100
    TCCR1A_Reg = (uint8_t)(T1_CTC_OC1AAction << COM1A0);
    TCCR1B_Reg = (uint8_t)((1 << WGM12) | (T1_ClockSelect & 0x07));

    OCR1A_Reg = T1_OCR1AValue;
    TCNT1_Reg = 0;

    SetBit(TIMSk_Reg, OCIE1A);
    SetBit(SREG_Reg, GIE);
}

void T1_SetCompareValueChannelA(uint16_t CompareValue)
{
    OCR1A_Reg = CompareValue;
}

void T1_SetCompareValueChannelB(uint16_t CompareValue)
{
    OCR1B_Reg = CompareValue;
}

void T1_CTCCallBackChannelA(void(*PF)(void))
{
    if (PF != NULL)
    {
        T1_COMPA_PF = PF;
    }
}

void T1_CTCCallBackChannelB(void(*PF)(void))
{
    if (PF != NULL)
    {
        T1_COMPB_PF = PF;
    }
}

void __vector_7(void)
{
    static uint32_t count = 0;
    count++;
    if (count >= T1_NoOfCompareMatchCount)
    {
        if (T1_COMPA_PF != NULL)
        {
            T1_COMPA_PF();
        }
        count = 0;
    }
}

void __vector_8(void)
{
    if (T1_COMPB_PF != NULL)
    {
        T1_COMPB_PF();
    }
}
#endif // T1_CTC

#if T1_PWM
void T1_PwmInit(void)
{
#if (T1_PWM_ChannelAAction != OC1_Disconnect)
    // Configure OC1A (PD5) as Output
    DIO_DirectionSelectForPin(DIO_GroupD, DIO_Pin5, DIO_Output);
#endif

#if (T1_PWM_ChannelBAction != OC1_Disconnect)
    // Configure OC1B (PD4) as Output
    DIO_DirectionSelectForPin(DIO_GroupD, DIO_Pin4, DIO_Output);
#endif

    // Mode 14: Fast PWM with TOP in ICR1 (WGM13:10 = 1110)
    TCCR1A_Reg = (uint8_t)((T1_PWM_ChannelAAction << COM1A0) |
                           (T1_PWM_ChannelBAction << COM1B0) |
                           (1 << WGM11));
    TCCR1B_Reg = (uint8_t)((1 << WGM13) | (1 << WGM12) | (T1_ClockSelect & 0x07));

    ICR1_Reg   = T1_PWM_TopValue;
    OCR1A_Reg  = 0;
    OCR1B_Reg  = 0;
}

void T1_SetTopValue(uint16_t TopValue)
{
    ICR1_Reg = TopValue;
}

#if !T1_CTC
void T1_SetCompareValueChannelA(uint16_t CompareValue)
{
    OCR1A_Reg = CompareValue;
}

void T1_SetCompareValueChannelB(uint16_t CompareValue)
{
    OCR1B_Reg = CompareValue;
}
#endif

#endif // T1_PWM

#if T1_ICU
static void (*T1_ICU_PF)(void) = NULL;

void T1_ICU_Init(void)
{
    // Configure ICP1 (PD6) as Input
    DIO_DirectionSelectForPin(DIO_GroupD, DIO_Pin6, DIO_Input);

    // Set Initial Trigger Edge
#if (T1_ICU_InitialEdge == T1_ICU_Trigger_Rising)
    SetBit(TCCR1B_Reg, ICES1);
#else
    ClearBit(TCCR1B_Reg, ICES1);
#endif

    // Enable ICU Interrupt
    SetBit(TIMSk_Reg, TICIE1);
    SetBit(SREG_Reg, GIE);
}

void T1_ICU_SetTriggerEdge(T1_ICU_Edge_t Edge)
{
    if (Edge == T1_ICU_Trigger_Rising)
    {
        SetBit(TCCR1B_Reg, ICES1);
    }
    else
    {
        ClearBit(TCCR1B_Reg, ICES1);
    }
}

uint16_t T1_ICU_GetCaptureValue(void)
{
    return ICR1_Reg;
}

void T1_ICU_InterruptEnable(void)
{
    SetBit(TIMSk_Reg, TICIE1);
}

void T1_ICU_InterruptDisable(void)
{
    ClearBit(TIMSk_Reg, TICIE1);
}

void T1_ICU_SetCallBack(void(*PF)(void))
{
    if (PF != NULL)
    {
        T1_ICU_PF = PF;
    }
}

void __vector_6(void)
{
    if (T1_ICU_PF != NULL)
    {
        T1_ICU_PF();
    }
}
#endif // T1_ICU

void T1_SetClock(uint8_t ClockSelect)
{
    TCCR1B_Reg = (TCCR1B_Reg & 0xF8) | (ClockSelect & 0x07);
}

void T1_Stop(void)
{
    TCCR1B_Reg = (TCCR1B_Reg & 0xF8) | T1_Disable;
}

#endif // Timer1_Driver
