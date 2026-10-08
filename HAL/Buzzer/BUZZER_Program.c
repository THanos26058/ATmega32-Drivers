/**
 * @file    BUZZER_Program.c
 * @brief   Implementation of the Buzzer HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "BUZZER_Interface.h"
#include "../../Common/Definition.h"

#if Buzzer_Driver

/* ── Public API ──────────────────────────────────────────────────────────── */

void BUZZER_Init(const Buzzer_Config_t *Config)
{
    if (Config == NULL) { return; }

    /* Configure the pin as an output */
    DIO_DirectionSelectForPin(Config->GroupName, Config->PinNo, DIO_Output);

    /* Drive the pin to its OFF state initially */
    BUZZER_TurnOff(Config);
}

void BUZZER_TurnOn(const Buzzer_Config_t *Config)
{
    if (Config == NULL) { return; }

    if (Config->ConnectionType == BUZZER_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
    else if (Config->ConnectionType == BUZZER_ACTIVE_LOW)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
}

void BUZZER_TurnOff(const Buzzer_Config_t *Config)
{
    if (Config == NULL) { return; }

    if (Config->ConnectionType == BUZZER_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
    else if (Config->ConnectionType == BUZZER_ACTIVE_LOW)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
}

void BUZZER_Toggle(const Buzzer_Config_t *Config)
{
    if (Config == NULL) { return; }

    DIO_ToggleForPin(Config->GroupName, Config->PinNo);
}

#endif /* Buzzer_Driver */