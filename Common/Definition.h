/**
 * @file    Definition.h
 * @brief   Common type aliases, boolean values, and logic-level definitions.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details This header provides a set of portable, self-documenting aliases
 *          for frequently used constants in embedded C code.  Including this
 *          file removes the need for magic numbers and makes intent clear at
 *          the call site (e.g., @c Enable instead of @c 1).
 */

#ifndef DEFINITION_H
#define DEFINITION_H

/**
 * @defgroup CommonDefs Common Definitions and Aliases
 * @brief    Portable constant aliases used across all driver layers.
 * @{
 */

/** @brief Null pointer constant, cast to (void *). */
#define NULL            ((void*)0)

/** @brief Alias for NULL — identical semantics, different capitalisation. */
#define Null            ((void*)0)

/** @brief Null character terminator for C strings. */
#define NullChar        '\0'

/* ── Boolean ─────────────────────────────────────────────────────────────── */

/** @brief Boolean true  (1). */
#define true            1

/** @brief Boolean false (0). */
#define false           0

/* ── Enable / Disable ────────────────────────────────────────────────────── */

/** @brief Peripheral or feature enabled. Equals @c true. */
#define Enable          true

/** @brief Peripheral or feature disabled. Equals @c false. */
#define Disable         false

/* ── On / Off ────────────────────────────────────────────────────────────── */

/** @brief Output or switch is on.  Equals @c true. */
#define On              true

/** @brief Output or switch is off. Equals @c false. */
#define Off             false

/* ── Set / Reset ─────────────────────────────────────────────────────────── */

/** @brief Bit or flag is set.   Equals @c true. */
#define Set             true

/** @brief Bit or flag is reset. Equals @c false. */
#define Reset           false

/* ── Active / Inactive ───────────────────────────────────────────────────── */

/** @brief Signal or peripheral is active.   Equals @c true. */
#define Active          true

/** @brief Signal or peripheral is inactive. Equals @c false. */
#define Inactive        false

/* ── Logic Level ─────────────────────────────────────────────────────────── */

/** @brief Active-High logic: a HIGH voltage activates the peripheral. */
#define ActiveHigh      true

/** @brief Active-Low  logic: a LOW  voltage activates the peripheral. */
#define ActiveLow       false

/** @} */ /* end of CommonDefs group */

#endif /* DEFINITION_H */
