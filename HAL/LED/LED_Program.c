/**
 * @file    LED_Program.c
 * @brief   Implementation of the LED HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "LED_Interface.h"
#include "../../Common/Definition.h"

#if Led_Driver

/*  Public API  */

void LED_Init(const LED_Config_t *Config)
{
    if (Config == NULL) { return; }

    /* Set pin direction as Output */
    DIO_DirectionSelectForPin(Config->GroupName, Config->PinNo, DIO_Output);

    /* Start in the OFF state */
    LED_TurnOff(Config);
}

void LED_TurnOn(const LED_Config_t *Config)
{
    if (Config == NULL) { return; }

    if (Config->ConnectionType == LED_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
    else if (Config->ConnectionType == LED_ACTIVE_LOW)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
}

void LED_TurnOff(const LED_Config_t *Config)
{
    if (Config == NULL) { return; }

    if (Config->ConnectionType == LED_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
    else if (Config->ConnectionType == LED_ACTIVE_LOW)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
}

void LED_Toggle(const LED_Config_t *Config)
{
    if (Config == NULL) { return; }

    DIO_ToggleForPin(Config->GroupName, Config->PinNo);
}

#endif /* Led_Driver */