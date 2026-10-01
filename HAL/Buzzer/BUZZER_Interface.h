/**
 * @file BUZZER_Interface.h
 * @author Ahmed Tarboush (ahmedaymantarboush@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-26
 */
#ifndef _HAL_BUZZER_BUZZER_INTERFACE_H_
#define _HAL_BUZZER_BUZZER_INTERFACE_H_

#include <stdint.h>

#define BUZZER_ACTIVE_HIGH    1  // Source
#define BUZZER_ACTIVE_LOW     2  // Sink

typedef struct {
    uint8_t GroupName;
    uint8_t PinNo;
    uint8_t ConnectionType;
} Buzzer_Config_t;

/**
 * @brief 
 * 
 * @param Config 
 */
void BUZZER_Init(const Buzzer_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void BUZZER_TurnOn(const Buzzer_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void BUZZER_TurnOff(const Buzzer_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void BUZZER_Toggle(const Buzzer_Config_t *Config);

#endif // _HAL_BUZZER_BUZZER_INTERFACE_H_
