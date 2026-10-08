/**
 * @file    SevenSegment_Interface.h
 * @brief   Public API for the Seven-Segment Display HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Drives a single 7-segment display on a full 8-bit DIO port.
 *          Supports both Common Anode and Common Cathode displays.
 */

#ifndef _HAL_SEVENSEGMENT_SEVENSEGMENT_INTERFACE_H_
#define _HAL_SEVENSEGMENT_SEVENSEGMENT_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if SevSeg_Driver

#include "../../MCAL/DIO/DIO_Interface.h"
#include "SevenSegment_Config.h"


/*  Hardware Configuration Definitions  */

#define SEVENSEGMENT_COMMON_CATHODE   1  /**< Display LEDs share a common GND. */
#define SEVENSEGMENT_COMMON_ANODE     2  /**< Display LEDs share a common VCC. */

/*  Configuration Struct  */

/**
 * @struct SevenSegment_Config_t
 * @brief  Configuration structure for a single 7-segment display.
 */
typedef struct
{
    uint8_t GroupName; /**< DIO Port connected to a-g segments (e.g., @c DIO_GroupA). */
    uint8_t Type;      /**< @c SEVENSEGMENT_COMMON_CATHODE or @c SEVENSEGMENT_COMMON_ANODE. */
} SevenSegment_Config_t;

/*  Functions  */

/**
 * @brief  Initialize the DIO port connected to the 7-segment display as output.
 * @param[in] Config Pointer to the display configuration struct.
 */
void SevenSegment_Init(const SevenSegment_Config_t *Config);

/**
 * @brief  Display a single-digit decimal number (0-9) on the 7-segment display.
 * @param[in] Config Pointer to the display configuration struct.
 * @param[in] Number The digit to display (0 to 9). Values > 9 are ignored.
 */
void SevenSegment_DisplayNumber(const SevenSegment_Config_t *Config, uint8_t Number);


#endif /* SevSeg_Driver */
#endif /* _HAL_SEVENSEGMENT_SEVENSEGMENT_INTERFACE_H_ */
