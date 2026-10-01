#include "DcMotor_Interface.h"

void DC_Init(const Dc_Config_t *Config)
{
    if (Config == NULL)
    {
        return;
    }
    
    if (Config->ConnectionType == Dc_WithoutHBridge)
    {
        DIO_DirectionSelectForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_Output);
    }
    else if (Config->ConnectionType == Dc_WithHBridge)
    {
        DIO_DirectionSelectForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_Output);
        DIO_DirectionSelectForPin(Config->DC_M2Group, Config->DC_M2Pin, DIO_Output);
    }
}

void DC_On(const Dc_Config_t *Config)
{
    if (Config == NULL) return;
    if (Config->ConnectionType == Dc_WithoutHBridge)
    {
        DIO_WriteForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_High);
    }
    else if (Config->ConnectionType == Dc_WithHBridge)
    {
        DC_OnCW(Config);
    }
}

void DC_Off(const Dc_Config_t *Config)
{
    if (Config == NULL) return;
    if (Config->ConnectionType == Dc_WithoutHBridge)
    {
        DIO_WriteForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_Low);
    }
    else if (Config->ConnectionType == Dc_WithHBridge)
    {
        DIO_WriteForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_Low);
        DIO_WriteForPin(Config->DC_M2Group, Config->DC_M2Pin, DIO_Low);
    }
}

void DC_Toggle(const Dc_Config_t *Config)
{
    if (Config == NULL) return;
    if (Config->ConnectionType == Dc_WithoutHBridge)
    {
        DIO_ToggleForPin(Config->DC_M1Group, Config->DC_M1Pin);
    }
    else if (Config->ConnectionType == Dc_WithHBridge)
    {
        DIO_WriteForPin(Config->DC_M2Group, Config->DC_M2Pin, DIO_Low);
        DIO_ToggleForPin(Config->DC_M1Group, Config->DC_M1Pin);
    }
}

void DC_OnCW(const Dc_Config_t *Config)
{
    if (Config == NULL || Config->ConnectionType != Dc_WithHBridge) return;
    DIO_WriteForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_High);
    DIO_WriteForPin(Config->DC_M2Group, Config->DC_M2Pin, DIO_Low);
}

void DC_OnCCW(const Dc_Config_t *Config)
{
    if (Config == NULL || Config->ConnectionType != Dc_WithHBridge) return;
    DIO_WriteForPin(Config->DC_M1Group, Config->DC_M1Pin, DIO_Low);
    DIO_WriteForPin(Config->DC_M2Group, Config->DC_M2Pin, DIO_High);
}