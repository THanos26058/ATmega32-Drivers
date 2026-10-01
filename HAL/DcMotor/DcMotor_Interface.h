#ifndef DCMOTOR_INTERFACE
#define DCMOTOR_INTERFACE

#include "DcMotor_Private.h"
#include "DcMotor_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void DC_Init(const Dc_Config_t *Config);

void DC_On(const Dc_Config_t *Config);
void DC_Off(const Dc_Config_t *Config);
void DC_Toggle(const Dc_Config_t *Config);

void DC_OnCW(const Dc_Config_t *Config);
void DC_OnCCW(const Dc_Config_t *Config);

#endif /* DCMOTOR_INTERFACE */
