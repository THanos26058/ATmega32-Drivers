/**
 * @file    DIO_Private.h
 * @brief   Private type definitions and enumerations for the DIO driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Defines all enumeration types used internally by the DIO driver
 *          and exported to upper layers (HAL) that need to refer to port
 *          groups, pin numbers, direction states, and output values.
 *
 * @warning Do not include this file directly in application code.
 *          Include @ref DIO_Interface.h instead.
 */

#ifndef _MCAL_DIO_DIO_PRIVATE_H_
#define _MCAL_DIO_DIO_PRIVATE_H_

/**
 * @defgroup DIO_Types DIO Driver Type Definitions
 * @{
 */

/**
 * @enum  DIO_Direction_t
 * @brief Pin or port direction (DDR register value).
 */
typedef enum
{
    DIO_Input     = 0,    /**< Configure pin as high-impedance digital input. */
    DIO_Output    = 1,    /**< Configure pin as push-pull digital output.     */
    DIO_AllOutput = 0xFF  /**< Set all 8 pins of a port as outputs at once.   */
} DIO_Direction_t;

/**
 * @enum  DIO_OutputValue_t
 * @brief Logic level driven on an output pin (PORT register value).
 */
typedef enum
{
    DIO_Low     = 0,    /**< Drive pin LOW  (0 V).                            */
    DIO_High    = 1,    /**< Drive pin HIGH (VCC).                            */
    DIO_AllHigh = 0xFF  /**< Drive all 8 pins of a port HIGH at once.         */
} DIO_OutputValue_t;

/**
 * @enum  DIO_GroupName_t
 * @brief Identifies one of the four 8-bit I/O ports on the ATmega32.
 *
 * @note  Values start at 1 so that 0 can be used as an "invalid port"
 *        sentinel in run-time validation.
 */
typedef enum
{
    DIO_GroupA = 1, /**< Port A — PA0..PA7 (shared with ADC channels 0-7).  */
    DIO_GroupB,     /**< Port B — PB0..PB7 (shared with SPI, timer OC pins).*/
    DIO_GroupC,     /**< Port C — PC0..PC7 (shared with TWI, JTAG).         */
    DIO_GroupD      /**< Port D — PD0..PD7 (shared with USART, EXTI, ICU).  */
} DIO_GroupName_t;

/**
 * @enum  DIO_PinNo_t
 * @brief Identifies one of the 8 pins within a port (bit position in the
 *        DDR / PORT / PIN register).
 */
typedef enum
{
    DIO_Pin0 = 0, /**< Bit 0 — least significant pin in the port byte. */
    DIO_Pin1,     /**< Bit 1. */
    DIO_Pin2,     /**< Bit 2. */
    DIO_Pin3,     /**< Bit 3. */
    DIO_Pin4,     /**< Bit 4. */
    DIO_Pin5,     /**< Bit 5. */
    DIO_Pin6,     /**< Bit 6. */
    DIO_Pin7      /**< Bit 7 — most significant pin in the port byte.  */
} DIO_PinNo_t;

/** @} */ /* end of DIO_Types */

#endif /* _MCAL_DIO_DIO_PRIVATE_H_ */