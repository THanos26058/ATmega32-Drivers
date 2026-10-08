/**
 * @file    BitMath.h
 * @brief   Bitwise manipulation macros for ATmega32 register access.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Provides four fundamental macros that operate on any 8-bit or
 *          16-bit register variable via direct bit manipulation using shifts
 *          and logical operators. All macros evaluate their arguments only
 *          once, so register side-effects are safe.
 */

#ifndef BITMATH_H
#define BITMATH_H

/**
 * @defgroup BitMath Bit Manipulation Macros
 * @brief    Macros for single-bit register operations.
 * @{
 */

/**
 * @brief  Set (write 1 to) a specific bit in a register.
 * @param  REG  The register or variable to modify.
 * @param  BIT  Zero-based bit position to set (0 = LSB).
 */
#define SetBit(REG, BIT)    ((REG) |=  (1 << (BIT)))

/**
 * @brief  Clear (write 0 to) a specific bit in a register.
 * @param  REG  The register or variable to modify.
 * @param  BIT  Zero-based bit position to clear (0 = LSB).
 */
#define ClearBit(REG, BIT)  ((REG) &= ~(1 << (BIT)))

/**
 * @brief  Toggle (invert) a specific bit in a register.
 * @param  REG  The register or variable to modify.
 * @param  BIT  Zero-based bit position to toggle (0 = LSB).
 */
#define ToggleBit(REG, BIT) ((REG) ^=  (1 << (BIT)))

/**
 * @brief  Read the value (0 or 1) of a specific bit in a register.
 * @param  REG  The register or variable to read from.
 * @param  BIT  Zero-based bit position to read (0 = LSB).
 * @return uint8_t  1 if the bit is set, 0 if the bit is clear.
 */
#define ReadBit(REG, BIT)   (((REG) >> (BIT)) & 1)

/** @} */ /* end of BitMath group */

#endif /* BITMATH_H */