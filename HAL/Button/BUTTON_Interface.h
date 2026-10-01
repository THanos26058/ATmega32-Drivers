/**
 * @file BUTTON_Interface.h
 * @author Ahmed Tarboush (ahmedaymantarboush@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-26
 */
#ifndef _HAL_BUTTON_BUTTON_INTERFACE_H_
#define _HAL_BUTTON_BUTTON_INTERFACE_H_

#include <stdint.h>

#define BUTTON_PULL_UP      1  // Active Low
#define BUTTON_PULL_DOWN    2  // Active High

#define BUTTON_RELEASED     0
#define BUTTON_PRESSED      1

typedef struct
{
    uint8_t GroupName;
    uint8_t PinNo;
    uint8_t ConnectionType;
} Button_Config_t;

/**
 * @brief 
 * 
 * @param Config 
 */
void BUTTON_Init(const Button_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void BUTTON_ReadInputValue(const Button_Config_t *Config, uint8_t *InputValue);

/**
 * @brief 
 * 
 * @param Config 
 * @param InputValue 
 */
void BUTTON_IsPhysacillyClicked(const Button_Config_t *Config, uint8_t *InputValue);

#endif // _HAL_BUTTON_BUTTON_INTERFACE_H_
