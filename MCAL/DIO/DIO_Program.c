/**
 * @file    DIO_Program.c
 * @brief   Implementation of the ATmega32 Digital I/O (DIO) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Uses switch-case dispatch on the port group name so that the
 *          compiler can generate a tight jump table.  No dynamic arrays are
 *          used, keeping the driver reentrant and stack-friendly.
 */

#include "DIO_Interface.h"

/* ── Direction ───────────────────────────────────────────────────────────── */

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_DirectionSelectForPin(uint8_t GroupName, uint8_t PinNo,
                               uint8_t DirectionState)
{
    if (PinNo > DIO_Pin7) { return; }

    if (DirectionState == DIO_Output)
    {
        switch (GroupName)
        {
            case DIO_GroupA: SetBit(DDRA_REG, PinNo); break;
            case DIO_GroupB: SetBit(DDRB_REG, PinNo); break;
            case DIO_GroupC: SetBit(DDRC_REG, PinNo); break;
            case DIO_GroupD: SetBit(DDRD_REG, PinNo); break;
            default: break; /* Invalid group — silently ignored */
        }
    }
    else if (DirectionState == DIO_Input)
    {
        switch (GroupName)
        {
            case DIO_GroupA: ClearBit(DDRA_REG, PinNo); break;
            case DIO_GroupB: ClearBit(DDRB_REG, PinNo); break;
            case DIO_GroupC: ClearBit(DDRC_REG, PinNo); break;
            case DIO_GroupD: ClearBit(DDRD_REG, PinNo); break;
            default: break;
        }
    }
    /* else: invalid DirectionState — silently ignored */
}

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_DirectionSelectForGroup(uint8_t GroupName, uint8_t DirectionState)
{
    switch (GroupName)
    {
        case DIO_GroupA: DDRA_REG = DirectionState; break;
        case DIO_GroupB: DDRB_REG = DirectionState; break;
        case DIO_GroupC: DDRC_REG = DirectionState; break;
        case DIO_GroupD: DDRD_REG = DirectionState; break;
        default: break;
    }
}

/* ── Output ──────────────────────────────────────────────────────────────── */

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_WriteForPin(uint8_t GroupName, uint8_t PinNo, uint8_t OutputValue)
{
    if (PinNo > DIO_Pin7) { return; }

    if (OutputValue == DIO_High)
    {
        switch (GroupName)
        {
            case DIO_GroupA: SetBit(PORTA_REG, PinNo); break;
            case DIO_GroupB: SetBit(PORTB_REG, PinNo); break;
            case DIO_GroupC: SetBit(PORTC_REG, PinNo); break;
            case DIO_GroupD: SetBit(PORTD_REG, PinNo); break;
            default: break;
        }
    }
    else if (OutputValue == DIO_Low)
    {
        switch (GroupName)
        {
            case DIO_GroupA: ClearBit(PORTA_REG, PinNo); break;
            case DIO_GroupB: ClearBit(PORTB_REG, PinNo); break;
            case DIO_GroupC: ClearBit(PORTC_REG, PinNo); break;
            case DIO_GroupD: ClearBit(PORTD_REG, PinNo); break;
            default: break;
        }
    }
}

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_WriteForGroup(uint8_t GroupName, uint8_t OutputValue)
{
    switch (GroupName)
    {
        case DIO_GroupA: PORTA_REG = OutputValue; break;
        case DIO_GroupB: PORTB_REG = OutputValue; break;
        case DIO_GroupC: PORTC_REG = OutputValue; break;
        case DIO_GroupD: PORTD_REG = OutputValue; break;
        default: break;
    }
}

/* ── Input ───────────────────────────────────────────────────────────────── */

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_ReadInputForPin(uint8_t GroupName, uint8_t PinNo,
                         uint8_t *InputState)
{
    if (InputState == NULL) { return; }
    if (PinNo > DIO_Pin7)   { return; }

    switch (GroupName)
    {
        case DIO_GroupA: *InputState = ReadBit(PINA_REG, PinNo); break;
        case DIO_GroupB: *InputState = ReadBit(PINB_REG, PinNo); break;
        case DIO_GroupC: *InputState = ReadBit(PINC_REG, PinNo); break;
        case DIO_GroupD: *InputState = ReadBit(PIND_REG, PinNo); break;
        default: break;
    }
}

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_ReadInputForGroup(uint8_t GroupName, uint8_t *InputState)
{
    if (InputState == NULL) { return; }

    switch (GroupName)
    {
        case DIO_GroupA: *InputState = PINA_REG; break;
        case DIO_GroupB: *InputState = PINB_REG; break;
        case DIO_GroupC: *InputState = PINC_REG; break;
        case DIO_GroupD: *InputState = PIND_REG; break;
        default: break;
    }
}

/* ── Toggle ──────────────────────────────────────────────────────────────── */

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_ToggleForPin(uint8_t GroupName, uint8_t PinNo)
{
    if (PinNo > DIO_Pin7) { return; }

    switch (GroupName)
    {
        case DIO_GroupA: ToggleBit(PORTA_REG, PinNo); break;
        case DIO_GroupB: ToggleBit(PORTB_REG, PinNo); break;
        case DIO_GroupC: ToggleBit(PORTC_REG, PinNo); break;
        case DIO_GroupD: ToggleBit(PORTD_REG, PinNo); break;
        default: break;
    }
}

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_ToggleForGroup(uint8_t GroupName)
{
    switch (GroupName)
    {
        case DIO_GroupA: PORTA_REG = ~PORTA_REG; break;
        case DIO_GroupB: PORTB_REG = ~PORTB_REG; break;
        case DIO_GroupC: PORTC_REG = ~PORTC_REG; break;
        case DIO_GroupD: PORTD_REG = ~PORTD_REG; break;
        default: break;
    }
}

/* ── Internal Pull-Up ────────────────────────────────────────────────────── */

/**
 * @brief See DIO_Interface.h for full documentation.
 */
void DIO_InternalPullUpControl(uint8_t GroupName, uint8_t PinNo,
                               uint8_t PullUpState)
{
    DIO_WriteForPin(GroupName, PinNo, PullUpState);
}
