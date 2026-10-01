#include "EXTI_Interface.h"

static void (*GINT0)(void) = NULL;
static void (*GINT1)(void) = NULL;
static void (*GINT2)(void) = NULL;

void EXTI_Init(uint8_t InterruptNumber , uint8_t SensControl)
{
    if (InterruptNumber == Exti0)
    {
        MCUCR_REG = (MCUCR_REG & ~0x03) | (SensControl << ISC00);
    }
    else if (InterruptNumber == Exti1)
    {
        MCUCR_REG = (MCUCR_REG & ~0x0C) | (SensControl << ISC10);
    }
    else if (InterruptNumber == Exti2)
    {
        MCUCSR_REG = (MCUCSR_REG & ~0x40) | ((SensControl & 0x01) << ISC2);
    }
}

void EXTI_Enable(uint8_t InterruptNumber )
{
    if (InterruptNumber == Exti0)
    {
        SetBit(GICR_REG, INT0);
    }
    else if (InterruptNumber == Exti1)
    {
        SetBit(GICR_REG, INT1);
    }
    else if (InterruptNumber == Exti2)
    {
        SetBit(GICR_REG, INT2);
    }
    SetBit(SREG_REG, GIE);
}

void EXTI_Disable(uint8_t InterruptNumber)
{
    if (InterruptNumber == Exti0)
    {
        ClearBit(GICR_REG, INT0);
    }
    else if (InterruptNumber == Exti1)
    {
        ClearBit(GICR_REG, INT1);
    }
    else if (InterruptNumber == Exti2)
    {
        ClearBit(GICR_REG, INT2);
    }
}

void EXTI_GlobalEnable(void)
{
    SetBit(SREG_REG, GIE);
}

void EXTI_GlobalDisable(void)
{
    ClearBit(SREG_REG, GIE);
}

void Exti_CallBackFunction(uint8_t InterruptNumber , void (*PF) (void))
{
    if (PF == NULL)
    {
        return;
    }

    if (InterruptNumber == Exti0)
    {
        GINT0 = PF;
    }
    else if (InterruptNumber == Exti1)
    {
        GINT1 = PF;
    }
    else if (InterruptNumber == Exti2)
    {
        GINT2 = PF;
    }
}

void __vector_1(void)
{
    if (GINT0 != NULL)
    {
        GINT0();
    }
}

void __vector_2(void)
{
    if (GINT1 != NULL)
    {
        GINT1();
    }
}

void __vector_3(void)
{
    if (GINT2 != NULL)
    {
        GINT2();
    }
}

