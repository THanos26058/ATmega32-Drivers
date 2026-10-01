/**
 * @file LED_Interface.h
 * @brief 
 * @version 0.1
 * @date 2026-08-26
 */
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include <stdint.h>

#define LED_ACTIVE_HIGH    1  // Source
#define LED_ACTIVE_LOW     2  // Sink

typedef struct {
    uint8_t GroupName;
    uint8_t PinNo;
    uint8_t ConnectionType;
} LED_Config_t;

/**
 * @brief 
 * 
 * @param Config 
 */
void LED_Init(const LED_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void LED_TurnOn(const LED_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void LED_TurnOff(const LED_Config_t *Config);

/**
 * @brief 
 * 
 * @param Config 
 */
void LED_Toggle(const LED_Config_t *Config);

#endif // _LED_INTERFACE_H_
