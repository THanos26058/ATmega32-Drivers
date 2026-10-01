/**
 * @file BUTTON_Program.c
 * @author Ahmed Tarboush (ahmedaymantarboush@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-26
 */
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"

#include "BUTTON_Config.h"
#include "BUTTON_Private.h"
#include "BUTTON_Interface.h"

/**
 * @brief 
 * 
 * @param Config 
 */
void BUTTON_Init(const Button_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_DirectionSelectForPin(Config->GroupName, Config->PinNo, DIO_Input);
    if (Config->ConnectionType == BUTTON_PULL_UP)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
}

/**
 * @brief 
 * 
 * @param Config 
 */
void BUTTON_ReadInputValue(const Button_Config_t *Config, uint8_t *InputValue)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (InputValue == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    uint8_t PhysicalState = BUTTON_RELEASED;
    DIO_ReadInputForPin(Config->GroupName, Config->PinNo, &PhysicalState);

    switch (Config->ConnectionType)
    {
    case BUTTON_PULL_UP:
        *InputValue = PhysicalState == DIO_Low ? BUTTON_PRESSED : BUTTON_RELEASED;
        break;
    
    case BUTTON_PULL_DOWN:
        *InputValue = PhysicalState == DIO_High ? BUTTON_PRESSED : BUTTON_RELEASED;
        break;
    default:
        // TODO: Handle Error Here;
        break;
    }
}

void BUTTON_IsPhysacillyClicked(const Button_Config_t *Config, uint8_t *InputValue)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (InputValue == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    uint8_t ButtonState = BUTTON_RELEASED;
    BUTTON_ReadInputValue(Config, &ButtonState);
    if (ButtonState == BUTTON_PRESSED)
    {
        _delay_ms(PHYSICAL_CLICK_DELAY);
        BUTTON_ReadInputValue(Config, InputValue);
    }
}