
#include "DIO_Interface.h"

static volatile uint8_t* const DDR_Reg_Arr[4] = { &DDRA_REG, &DDRB_REG, &DDRC_REG, &DDRD_REG };
static volatile uint8_t* const PORT_Reg_Arr[4] = { &PORTA_REG, &PORTB_REG, &PORTC_REG, &PORTD_REG };
static volatile uint8_t* const PIN_Reg_Arr[4] = { &PINA_REG, &PINB_REG, &PINC_REG, &PIND_REG };

/*Direction*/


void DIO_DirectionSelectForPin(uint8_t GroupName, uint8_t PinNo, uint8_t DirectionState)
{
    if (PinNo > DIO_Pin7)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }
    
    switch (DirectionState)
    {
        case DIO_Input: ClearBit(*DDR_Reg_Arr[GroupName], PinNo); break;
        case DIO_Output: SetBit(*DDR_Reg_Arr[GroupName], PinNo); break;
        default: return; // TODO: Handle Error Here;
    }    
}

void DIO_DirectionSelectForGroup(uint8_t GroupName, uint8_t DirectionState)
{
    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }

    *DDR_Reg_Arr[GroupName] = DirectionState;
}


/* OutputValue */

void DIO_WriteForPin(uint8_t GroupName, uint8_t PinNo, uint8_t OutputValue)
{
    if (PinNo > DIO_Pin7)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }
    
    switch (OutputValue)
    {
        case DIO_Low: ClearBit(*PORT_Reg_Arr[GroupName], PinNo); break;
        case DIO_High: SetBit(*PORT_Reg_Arr[GroupName], PinNo); break;
        default: return; // TODO: Handle Error Here;
    }
}


void DIO_WriteForGroup(uint8_t GroupName, uint8_t OutputValue)
{
    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }
    
    *PORT_Reg_Arr[GroupName] = OutputValue;
}

/* InputState */


void DIO_ReadInputForPin(uint8_t GroupName, uint8_t PinNo, uint8_t *InputState)
{
    if (InputState == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (PinNo > DIO_Pin7)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }
    
    *InputState = ReadBit(*PIN_Reg_Arr[GroupName], PinNo);
}


void DIO_ReadInputForGroup(uint8_t GroupName, uint8_t *InputState)
{
    if (InputState == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }

    *InputState = *PIN_Reg_Arr[GroupName];
}

/* Toggle */


void DIO_ToggleForPin(uint8_t GroupName, uint8_t PinNo)
{
    if (PinNo > DIO_Pin7)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }

    ToggleBit(*PORT_Reg_Arr[GroupName], PinNo);
}


void DIO_ToggleForGroup(uint8_t GroupName)
{
    if (GroupName > DIO_GroupD)
    {
        // TODO: Handle Error Here;
        return;
    }

    *PORT_Reg_Arr[GroupName] = ~(*PORT_Reg_Arr[GroupName]);
}

/* Internal Pull Up */


void DIO_InternalPullUpControl(uint8_t GroupName, uint8_t PinNo, uint8_t PullUpState)
{
    DIO_WriteForPin(GroupName, PinNo, PullUpState);
}

