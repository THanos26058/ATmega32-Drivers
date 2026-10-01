#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Registers.h"

#include "DIO_Config.h"
#include "DIO_Private.h"

/*Direction*/

/**
 * @brief 
 * 
 * @param GroupName 
 * @param PinNo 
 * @param DirectionState 
 */
void DIO_DirectionSelectForPin(uint8_t GroupName, uint8_t PinNo, uint8_t DirectionState);

/**
 * @brief 
 * 
 * @param GroupName 
 * @param DirectionState 
 */
void DIO_DirectionSelectForGroup(uint8_t GroupName, uint8_t DirectionState);


/* OutputValue */

/**
 * @brief 
 * 
 * @param GroupName 
 * @param PinNo 
 * @param OutputValue 
 */
void DIO_WriteForPin(uint8_t GroupName, uint8_t PinNo, uint8_t OutputValue);

/**
 * @brief 
 * 
 * @param GroupName 
 * @param OutputValue 
 */
void DIO_WriteForGroup(uint8_t GroupName, uint8_t OutputValue);

/* InputState */

/**
 * @brief 
 * 
 * @param GroupName 
 * @param PinNo 
 * @param InputState 
 */
void DIO_ReadInputForPin(uint8_t GroupName, uint8_t PinNo, uint8_t *InputState);

/**
 * @brief 
 * 
 * @param GroupName 
 * @param InputState 
 */
void DIO_ReadInputForGroup(uint8_t GroupName, uint8_t *InputState);

/* Toggle */

/**
 * @brief 
 * 
 * @param GroupName 
 * @param PinNo 
 */
void DIO_ToggleForPin(uint8_t GroupName, uint8_t PinNo);

/**
 * @brief 
 * 
 * @param GroupName 
 */
void DIO_ToggleForGroup(uint8_t GroupName);

/* Internal Pull Up */

/**
 * @brief 
 * 
 * @param GroupName 
 * @param PinNo 
 * @param PullUpState 
 */
void DIO_InternalPullUpControl(uint8_t GroupName, uint8_t PinNo, uint8_t PullUpState);


#endif // _DIO_INTERFACE_H_
