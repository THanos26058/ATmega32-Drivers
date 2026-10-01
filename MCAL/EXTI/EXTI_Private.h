#ifndef _MCAL_EXTI_EXTI_PRIVATE_H_
#define _MCAL_EXTI_EXTI_PRIVATE_H_

typedef enum
{
//MCUCR
    ISC00,
    ISC01,
    ISC10,
    ISC11,
//MCUCSR
    ISC2=6,
//GICR
    INT2=5,
    INT0,
    INT1,
//GIFR
    INTF2=5,
    INTF0,
    INTF1,
//SREG
    GIE=7

}EXTI_Bitname_t;

typedef enum
{
    Exti0,
    Exti1,
    Exti2
}EXTI_Numbers_t;


typedef enum
{
    EXTI_LowLevel,
    EXTI_Anylogic,
    EXTI_Falling,
    EXTI_Rising
}EXTI_SensControl_t;

//typedef enum
//{
//    Exti0_LowLevel  =0x00,
//    Exti0_Anylogic  =0x01,
//    Exti0_Falling   =0x02,    
//    Exti0_Rising    =0x03,
//
//    Exti1_LowLevel  =0x00,
//    Exti1_Anylogic  =0x04,
//    Exti1_Falling   =0x08,    
//    Exti1_Rising    =0x0C,
//
//    Exti2_Falling   =0x00,    
//    Exti2_Rising    =0x40
//}EXTI_EventType_t;

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#endif // _MCAL_EXTI_EXTI_PRIVATE_H_
