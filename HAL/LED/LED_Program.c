/**
 * @file LED_Program.c
 * @brief
 * @version 0.1
 * @date 2026-08-26
 */
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Config.h"
#include "LED_Private.h"
#include "LED_Interface.h"

/**
 * @brief 
 * 
 * 
 * @param Config 
 */
void LED_Init(const LED_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_DirectionSelectForPin(Config->GroupName, Config->PinNo, DIO_Output);
    LED_TurnOff(Config);
}

/**
 * @brief
 *
 * @param Config
 */
void LED_TurnOn(const LED_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Config->ConnectionType == LED_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_High);
    }
    else if (Config->ConnectionType == LED_ACTIVE_LOW)
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
void LED_TurnOff(const LED_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }


    if (Config->ConnectionType == LED_ACTIVE_HIGH)
    {
        DIO_WriteForPin(Config->GroupName, Config->PinNo, DIO_Low);
    }
    else if (Config->ConnectionType == LED_ACTIVE_LOW)
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
void LED_Toggle(const LED_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_ToggleForPin(Config->GroupName, Config->PinNo);
}