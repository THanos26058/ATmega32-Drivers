/**
 * @file BUZZER_Program.c
 * @author Ahmed Tarboush (ahmedaymantarboush@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-26
 */
#include "../../MCAL/DIO/DIO_Interface.h"

#include "BUZZER_Config.h"
#include "BUZZER_Private.h"
#include "BUZZER_Interface.h"

/**
 * @brief 
 * 
 * @param Config 
 */
void BUZZER_Init(const Buzzer_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_DirectionSelectForPin(Config->GroupName, Config->PinNo, DIO_Output);
    BUZZER_TurnOff(Config);
}

/**
 * @brief
 *
 * @param Config
 */
void BUZZER_TurnOn(const Buzzer_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->ConnectionType == BUZZER_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
    else if (Config->ConnectionType == BUZZER_ACTIVE_LOW)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
    else
    {
        // TODO: Handle Error Here;
        return;
    }
}

/**
 * @brief
 *
 * @param Config
 */
void BUZZER_TurnOff(const Buzzer_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }


    if (Config->ConnectionType == BUZZER_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
    else if (Config->ConnectionType == BUZZER_ACTIVE_LOW)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
    else
    {
        // TODO: Handle Error Here;
        return;
    }
}

/**
 * @brief
 *
 * @param Config
 */
void BUZZER_Toggle(const Buzzer_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_ToggleForPin(Config->GroupName, Config->PinNo);
}