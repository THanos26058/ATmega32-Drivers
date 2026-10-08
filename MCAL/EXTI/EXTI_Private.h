/**
 * @file    EXTI_Private.h
 * @brief   Private bit-name enumerations and type definitions for the EXTI driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @warning Do not include this file directly — include @ref EXTI_Interface.h.
 */

#ifndef _MCAL_EXTI_EXTI_PRIVATE_H_
#define _MCAL_EXTI_EXTI_PRIVATE_H_

/**
 * @defgroup EXTI_Types EXTI Driver Private Type Definitions
 * @{
 */

/**
 * @enum  Exti_BitName_t
 * @brief Bit positions inside MCUCR, MCUCSR, GICR, and GIFR registers
 *        that are used exclusively by the EXTI driver.
 */
typedef enum
{
    /* MCUCR — Interrupt Sense Control for INT0 and INT1 */
    ISC00 = 0, /**< INT0 Sense Control bit 0.                              */
    ISC01 = 1, /**< INT0 Sense Control bit 1.                              */
    ISC10 = 2, /**< INT1 Sense Control bit 0.                              */
    ISC11 = 3, /**< INT1 Sense Control bit 1.                              */

    /* MCUCSR — Interrupt Sense Control for INT2 */
    ISC2  = 6, /**< INT2 Sense Control bit (falling=0, rising=1).         */

    /* GICR — General Interrupt Control Register */
    INT2  = 5, /**< External Interrupt 2 enable bit.                      */
    INT0  = 6, /**< External Interrupt 0 enable bit.                      */
    INT1  = 7, /**< External Interrupt 1 enable bit.                      */

    /* GIFR — General Interrupt Flag Register */
    INTF2 = 5, /**< External Interrupt Flag 2.                            */
    INTF0 = 6, /**< External Interrupt Flag 0.                            */
    INTF1 = 7  /**< External Interrupt Flag 1.                            */
} Exti_BitName_t;

/**
 * @enum  Exti_SensControl_t
 * @brief Trigger / sense condition for an external interrupt line.
 *
 * @note  INT2 only supports @c Exti_Falling and @c Exti_Rising.
 */
typedef enum
{
    Exti_LowLevel = 0, /**< Low level on INTx pin triggers the interrupt.  */
    Exti_AnyLogic = 1, /**< Any logical change on INTx triggers (INT0/1).  */
    Exti_Falling  = 2, /**< Falling edge on INTx triggers the interrupt.   */
    Exti_Rising   = 3  /**< Rising  edge on INTx triggers the interrupt.   */
} Exti_SensControl_t;

/**
 * @enum  Exti_Numbers_t
 * @brief Logical identifier for each external interrupt line.
 */
typedef enum
{
    Exti0 = 0, /**< External Interrupt 0 (PD2 / INT0).                    */
    Exti1 = 1, /**< External Interrupt 1 (PD3 / INT1).                    */
    Exti2 = 2  /**< External Interrupt 2 (PB2 / INT2, edge-triggered only).*/
} Exti_Numbers_t;

/** @} */ /* end of EXTI_Types */

#endif /* _MCAL_EXTI_EXTI_PRIVATE_H_ */
