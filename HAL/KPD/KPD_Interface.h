/**
 * @file    KPD_Interface.h
 * @brief   Public API for the Matrix Keypad (KPD) HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Reads a 4x4 or 3x4 matrix keypad by multiplexing row and column
 *          pins. Column pins are driven low one by one while row pins are
 *          read using internal pull-ups.
 */

#ifndef _HAL_KPD_KPD_INTERFACE_H_
#define _HAL_KPD_KPD_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Kpd_Driver

#include "KPD_Private.h"
#include "KPD_Config.h"


/**
 * @brief  Initialize the keypad GPIO pins.
 * @details Configures row pins as inputs with internal pull-ups enabled,
 *          and column pins as outputs driven HIGH initially.
 */
void KPD_Init(void);

/**
 * @brief  Scan the keypad and return the pressed key.
 *
 * @param[out] KPD_Value Pointer to store the value of the pressed key.
 *                       If no key is pressed, returns the unpressed state
 *                       defined in Config.h.
 */
void KPD_GetKPDValue(uint8_t *KPD_Value);


#endif /* Kpd_Driver */
#endif /* _HAL_KPD_KPD_INTERFACE_H_ */
