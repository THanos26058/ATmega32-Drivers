#include "LCD_Interface.h"
#include <util/delay.h>

void LCD_Init()
{
    #if LCD_Mode== Lcd_8BitMode
        DIO_DirectionSelectForPin(RSGroup,RSPin,DIO_Output);
        DIO_DirectionSelectForPin(RWGroup,RWPin,DIO_Output);
        DIO_DirectionSelectForPin(EGroup,EPin,DIO_Output);
        DIO_DirectionSelectForGroup(DataGroup,DIO_AllHigh);
        /*Init*/
        // 1- wait for 30 msec 
            _delay_ms(35);
        // 2- sent the function set 
            LCD_SendCommand(Lcd_FunctionSet);
        // 3- wait for 1msec
            _delay_ms(1);
        // 4- Sent the Display on Off 
            LCD_SendCommand(Lcd_DisplayOnOff);
        // 5- wait for 1msec
             _delay_ms(1);
        // 6- Sent Clear  
            LCD_SendCommand(Lcd_Clear);
        // 7- wait for 2msec
             _delay_ms(2);
        // 8- Entry Mode sent 
            LCD_SendCommand(Lcd_EntryMode);
    #elif LCD_Mode==Lcd_4BitMode
        DIO_DirectionSelectForPin(RSGroup,RSPin,DIO_Output);
        DIO_DirectionSelectForPin(RWGroup,RWPin,DIO_Output);
        DIO_DirectionSelectForPin(EGroup,EPin,DIO_Output);
        DIO_DirectionSelectForPin(D4Group,D4Pin,DIO_Output);
        DIO_DirectionSelectForPin(D5Group,D5Pin,DIO_Output);
        DIO_DirectionSelectForPin(D6Group,D6pin,DIO_Output);
        DIO_DirectionSelectForPin(D7Group,D7Pin,DIO_Output);
        /*Init*/
        // 1- wait for 30 msec 
            _delay_ms(35);
        // 2- send the first half of function set (0x20) to set 4-bit mode
            DIO_WriteForPin(RSGroup,RSPin,DIO_Low);
            DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
            DIO_WriteForPin(D4Group,D4Pin,DIO_Low);
            DIO_WriteForPin(D5Group,D5Pin,DIO_High);
            DIO_WriteForPin(D6Group,D6pin,DIO_Low);
            DIO_WriteForPin(D7Group,D7Pin,DIO_Low);
            DIO_WriteForPin(EGroup,EPin,DIO_High);
            _delay_ms(1);
            DIO_WriteForPin(EGroup,EPin,DIO_Low);
            _delay_ms(1);
        // 3- sent the function set 
            LCD_SendCommand(Lcd_FunctionSet);
        // 4- wait for 1msec
            _delay_ms(1);
        // 5- Sent the Display on Off 
            LCD_SendCommand(Lcd_DisplayOnOff);
        // 6- wait for 1msec
             _delay_ms(1);
        // 7- Sent Clear  
            LCD_SendCommand(Lcd_Clear);
        // 8- wait for 2msec
             _delay_ms(2);
        // 9- Entry Mode sent 
            LCD_SendCommand(Lcd_EntryMode);
    #else 
            #error "Invalid Lcd Mode"
    #endif
}
void LCD_SendCommand(uint8_t Command)
{
    #if LCD_Mode==Lcd_8BitMode
        //RS -> 0 
        DIO_WriteForPin(RSGroup,RSPin,DIO_Low);
        //RW -> 0 
        DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
        //Data =  Command 
        DIO_WriteForGroup(DataGroup,Command);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
    #elif LCD_Mode==Lcd_4BitMode
        //RS -> 0 
        DIO_WriteForPin(RSGroup,RSPin,DIO_Low);
        //RW -> 0 
        DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
        
        //Send high nibble
        DIO_WriteForPin(D4Group,D4Pin,(Command>>4)&1);
        DIO_WriteForPin(D5Group,D5Pin,(Command>>5)&1);
        DIO_WriteForPin(D6Group,D6pin,(Command>>6)&1);
        DIO_WriteForPin(D7Group,D7Pin,(Command>>7)&1);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
        _delay_ms(1);
        
        //Send low nibble
        DIO_WriteForPin(D4Group,D4Pin,(Command>>0)&1);
        DIO_WriteForPin(D5Group,D5Pin,(Command>>1)&1);
        DIO_WriteForPin(D6Group,D6pin,(Command>>2)&1);
        DIO_WriteForPin(D7Group,D7Pin,(Command>>3)&1);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
    #else 
            #error "Invalid Lcd Mode"
    #endif
        
}
void LCD_WriteCharacter(uint8_t Character)
{
    #if LCD_Mode==Lcd_8BitMode
        //RS -> 1 
        DIO_WriteForPin(RSGroup,RSPin,DIO_High);
        //RW -> 0 
        DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
        //Data =  Character
        DIO_WriteForGroup(DataGroup,Character);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
    #elif LCD_Mode==Lcd_4BitMode
        //RS -> 1 
        DIO_WriteForPin(RSGroup,RSPin,DIO_High);
        //RW -> 0 
        DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
        
        //Send high nibble
        DIO_WriteForPin(D4Group,D4Pin,(Character>>4)&1);
        DIO_WriteForPin(D5Group,D5Pin,(Character>>5)&1);
        DIO_WriteForPin(D6Group,D6pin,(Character>>6)&1);
        DIO_WriteForPin(D7Group,D7Pin,(Character>>7)&1);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
        _delay_ms(1);
        
        //Send low nibble
        DIO_WriteForPin(D4Group,D4Pin,(Character>>0)&1);
        DIO_WriteForPin(D5Group,D5Pin,(Character>>1)&1);
        DIO_WriteForPin(D6Group,D6pin,(Character>>2)&1);
        DIO_WriteForPin(D7Group,D7Pin,(Character>>3)&1);
        //E-> 1 
        DIO_WriteForPin(EGroup,EPin,DIO_High);
        // Wait 1msec
        _delay_ms(1);
        // E-> 0 
        DIO_WriteForPin(EGroup,EPin,DIO_Low);
    #else 
        #error "Invalid Lcd Mode"
    #endif

}
void LCD_WriteString(uint8_t *String)
{
    if(String!=NULL)
    {
        uint8_t Index = 0 ;
        while(String[Index]!=NullChar)
        {
            LCD_WriteCharacter(String[Index]);
            Index++;
        }
    }
}
void LCD_WriteNumber(int32_t Number)
{
    uint8_t buffer[10];
    uint8_t i = 0;
    uint8_t isNegative = 0;
    
    if (Number == 0)
    {
        LCD_WriteCharacter('0');
        return;
    }
    
    if (Number < 0)
    {
        isNegative = 1;
        Number = -Number;
    }
    
    while (Number > 0)
    {
        buffer[i++] = (Number % 10) + '0';
        Number /= 10;
    }
    
    if (isNegative)
    {
        buffer[i++] = '-';
    }
    
    // String is in reverse order, print it backwards
    while (i > 0)
    {
        i--;
        LCD_WriteCharacter(buffer[i]);
    }
}

void LCD_MoveTo(uint8_t Line, uint8_t Digit)
{
    uint8_t DDRAM_Address = 0 ;
    switch(Line)
    {
        case Lcd_Line1: DDRAM_Address = Lcd_Line1Address+Digit;break;
        case Lcd_Line2: DDRAM_Address = Lcd_Line2Address+Digit;break;
        default:break;
    }
    LCD_SendCommand(0x80|DDRAM_Address);
}

void LCD_StoreSpecialCharacter(uint8_t * SpecialCharacter , uint8_t Location)
{
    uint8_t i;
    if(SpecialCharacter==NULL||Location > 8)
    {
        return;
    }
       // Set CGRAM Address: 0x40 + (Location * 8)
        LCD_SendCommand(0x40 | (Location * 8));
        for(i = 0; i < 8; i++)
        {
            LCD_WriteCharacter(SpecialCharacter[i]);
        }
        LCD_MoveTo(Lcd_Line1,0);
}