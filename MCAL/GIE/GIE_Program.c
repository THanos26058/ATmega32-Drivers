/**
 * @file    GIE_Program.c
 * @brief   Implementation of the Global Interrupt Enable (GIE) driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "GIE_Interface.h"
#include "../../Common/BitMath.h"
#include "../Atmega32Registers.h"

#if GIE_Driver

void GIE_Enable(void)
{
    /* Bit 7 in SREG is the Global Interrupt Enable (I) flag */
    SetBit(SREG_REG, 7);
}

void GIE_Disable(void)
{
    /* Clear bit 7 in SREG to disable all interrupts globally */
    ClearBit(SREG_REG, 7);
}

#endif /* GIE_Driver */
