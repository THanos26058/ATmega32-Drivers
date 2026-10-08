/**
 * @file    LCD_Interface.h
 * @brief   Public API for the alphanumeric LCD (16x2 / 20x4) HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Supports 8-bit or 4-bit data mode interfaces based on HD44780
 *          controllers. Includes utility functions for sending strings,
 *          integers, and storing custom CGRAM characters.
 */

#ifndef _HAL_LCD_LCD_INTERFACE_H_
#define _HAL_LCD_LCD_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Config.h"

#if Lcd_Driver

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

/**
 * @defgroup LCD_API LCD Driver Public API
 * @{
 */

/**
 * @brief  Initialize the LCD module based on the compile-time configuration.
 * @details Sends the standard initialization sequence for 8-bit or 4-bit mode.
 */
void LCD_Init(void);

/**
 * @brief  Send a command byte to the LCD controller.
 * @param[in] Command The 8-bit command to send (e.g., clear screen, shift).
 */
void LCD_SendCommand(uint8_t Command);

/**
 * @brief  Display a single ASCII character at the current cursor position.
 * @param[in] Character The ASCII character to display.
 */
void LCD_WriteCharacter(uint8_t Character);

/**
 * @brief  Display a null-terminated string at the current cursor position.
 * @param[in] String Pointer to the character array.
 */
void LCD_WriteString(uint8_t *String);

/**
 * @brief  Display a signed 32-bit integer as text.
 * @param[in] Number The integer to display.
 */
void LCD_WriteNumber(int32_t Number);

/**
 * @brief  Move the cursor to a specific line and column.
 * @param[in] Line  The row number (e.g., 1 or 2).
 * @param[in] Digit The column number (e.g., 0 to 15 for a 16x2 LCD).
 */
void LCD_MoveTo(uint8_t Line, uint8_t Digit);

/**
 * @brief  Store a custom 5x8 pixel character pattern in CGRAM.
 * @param[in] SpecialCharacter Pointer to an array of 8 bytes representing the pattern.
 * @param[in] Location         CGRAM block location (0 to 7).
 */
void LCD_StoreSpecialCharacter(uint8_t *SpecialCharacter, uint8_t Location);

/** @} */ /* end of LCD_API */

#endif /* Lcd_Driver */
#endif /* _HAL_LCD_LCD_INTERFACE_H_ */
