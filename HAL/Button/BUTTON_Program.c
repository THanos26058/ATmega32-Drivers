/**
 * @file    BUTTON_Program.c
 * @brief   Implementation of the Push-Button HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "BUTTON_Interface.h"
#include "../../Common/Definition.h"

#if Button_Driver

/*  Public API  */

void BUTTON_Init(const Button_Config_t *Config)
{
    if (Config == NULL) { return; }

    /* Configure the pin as input */
    DIO_DirectionSelectForPin(Config->GroupName, Config->PinNo, DIO_Input);

    /* Enable internal pull-up if configured for PULL_UP */
    if (Config->ConnectionType == BUTTON_PULL_UP)
    {
        DIO_InternalPullUpControl(Config->GroupName, Config->PinNo, Enable);
    }
}

void BUTTON_ReadInputValue(const Button_Config_t *Config, uint8_t *InputValue)
{
    uint8_t pinState = 0;

    if (Config == NULL || InputValue == NULL) { return; }

    /* Read the physical voltage level on the pin */
    DIO_ReadInputForPin(Config->GroupName, Config->PinNo, &pinState);

    /* Translate physical level to logical state (Pressed/Released) */
    if (Config->ConnectionType == BUTTON_PULL_UP)
    {
        *InputValue = (pinState == DIO_Low) ? BUTTON_PRESSED : BUTTON_RELEASED;
    }
    else if (Config->ConnectionType == BUTTON_PULL_DOWN)
    {
        *InputValue = (pinState == DIO_High) ? BUTTON_PRESSED : BUTTON_RELEASED;
    }
}

void BUTTON_IsPhysacillyClicked(const Button_Config_t *Config, uint8_t *InputValue)
{
    /* This function typically includes a blocking delay for software debouncing, 
       but for basic API symmetry it simply wraps BUTTON_ReadInputValue. */
    BUTTON_ReadInputValue(Config, InputValue);
}

#endif /* Button_Driver */