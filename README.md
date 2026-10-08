# ATmega32 Drivers

A layered embedded driver library for ATmega32 microcontroller, written in C.

## Architecture

```
WorkSpace/
├── Common/                  # Shared macros and definitions
│   ├── BitMath.h            # SetBit, ClearBit, ToggleBit, ReadBit
│   ├── Definition.h         # NULL, true/false, Enable/Disable, etc.
│   └── Config.h             # Shared driver configuration and switches
│
├── MCAL/                    # Microcontroller Abstraction Layer
│   ├── Atmega32Registers.h  # All ATmega32 register definitions
│   ├── DIO/                 # Digital I/O driver
│   ├── EXTI/                # External Interrupt driver
│   ├── GIE/                 # Global Interrupt Enable driver
│   ├── ADC/                 # Analog-to-Digital Converter driver
│   ├── Timer0/              # 8-bit Timer0 (Normal, CTC, Fast/Phase PWM)
│   ├── Timer1/              # 16-bit Timer1 (Normal, CTC, PWM, ICU)
│   └── Timer2/              # 8-bit Timer2 (Normal, CTC, Fast/Phase PWM, Async RTC)
│
├── HAL/                     # Hardware Abstraction Layer
│   ├── LED/                 # LED driver
│   ├── Button/              # Push Button driver
│   ├── Buzzer/              # Buzzer driver
│   ├── LCD/                 # LCD 16x2 driver (4-bit & 8-bit)
│   ├── KPD/                 # Keypad driver
│   ├── SevenSegment/        # Seven Segment driver
│   ├── DcMotor/             # DC Motor driver (with/without H-Bridge)
│   ├── LDR/                 # LDR Light Sensor driver
│   └── LM35/                # LM35 Temperature Sensor driver
│
└── main.c                   # Application entry point
```

## Drivers

| Driver | Layer | Description |
|--------|-------|-------------|
| DIO | MCAL | Digital Input/Output (pin & group) |
| EXTI | MCAL | External Interrupts (INT0, INT1, INT2) |
| GIE | MCAL | Global Interrupt Enable (SREG I-bit) |
| ADC | MCAL | 10-bit ADC with sync/async modes |
| Timer0 | MCAL | 8-bit Timer0 (Normal OVF, CTC, Fast PWM, Phase Correct PWM) |
| Timer1 | MCAL | 16-bit Timer1 (Normal, CTC, Fast/Phase PWM, Input Capture Unit) |
| Timer2 | MCAL | 8-bit Timer2 (Normal, CTC, Fast/Phase PWM, Asynchronous RTC) |
| LED | HAL | Active-High / Active-Low LED |
| Button | HAL | Pull-Up / Pull-Down button with debounce |
| Buzzer | HAL | Active-High / Active-Low buzzer |
| LCD | HAL | 16x2 LCD in 4-bit and 8-bit mode |
| KPD | HAL | Matrix Keypad (configurable size) |
| SevenSegment | HAL | Common Anode / Common Cathode |
| DcMotor | HAL | With and without H-Bridge |
| LDR | HAL | Light intensity (0-100%) and level detection |
| LM35 | HAL | Temperature reading in Celsius |

## Toolchain

- **Compiler:** avr-gcc 15.1.0
- **Target MCU:** ATmega32 @ 8 MHz
- **Standard:** C11

## Author

Mahmoud Abdallah — nt123456789123456789@gmail.com
