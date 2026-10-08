/**
 * @file    Atmega32Registers.h
 * @brief   Memory-mapped I/O register definitions for the ATmega32.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 *
 * @details Each macro dereferences the register's fixed I/O address as a
 *          @c volatile pointer so the compiler never optimises away hardware
 *          accesses.  Helper macros for 8-bit, 16-bit, and 32-bit access are
 *          also provided for use in other headers.
 *
 * @note    Register addresses are based on the ATmega32 data sheet (I/O
 *          memory map, Table 35-1).  All addresses are in the data-memory
 *          space (0x20 offset already applied).
 */

#ifndef _MCAL_ATMEGA32REGISTERS_H_
#define _MCAL_ATMEGA32REGISTERS_H_

#include <stdint.h>

/* ── Address Helpers ─────────────────────────────────────────────────────── */

/**
 * @brief Dereference @p Address as a volatile 8-bit register.
 * @param Address  Numeric I/O address.
 */
#define _SetAddress8bit(Address)   (*((volatile uint8_t  *)(Address)))

/**
 * @brief Dereference @p Address as a volatile 16-bit register pair.
 * @param Address  Numeric I/O address of the low byte.
 */
#define _SetAddress16bit(Address)  (*((volatile uint16_t *)(Address)))

/**
 * @brief Dereference @p Address as a volatile 32-bit register.
 * @param Address  Numeric I/O address.
 */
#define _SetAddress32bit(Address)  (*((volatile uint32_t *)(Address)))

/* ── CPU / Status Registers ──────────────────────────────────────────────── */

/** @brief Status Register (SREG) — I-flag is bit 7.            @addr 0x5F */
#define SREG_REG         _SetAddress8bit(0x5F)

/** @brief Stack Pointer High byte.                              @addr 0x5E */
#define SPH_REG          _SetAddress8bit(0x5E)

/** @brief Stack Pointer Low byte.                               @addr 0x5D */
#define SPL_REG          _SetAddress8bit(0x5D)

/** @brief Stack Pointer (16-bit).                               @addr 0x5D */
#define SP_REG           _SetAddress16bit(0x5D)

/* ── MCU Control Registers ───────────────────────────────────────────────── */

/** @brief MCU Control Register (sleep, interrupt sense).        @addr 0x55 */
#define MCUCR_REG        _SetAddress8bit(0x55)

/** @brief MCU Control and Status Register (INT2 sense, JTRF).   @addr 0x54 */
#define MCUCSR_REG       _SetAddress8bit(0x54)

/** @brief Special Function I/O Register.                        @addr 0x50 */
#define SFIOR_REG        _SetAddress8bit(0x50)

/* ── Interrupt Control ───────────────────────────────────────────────────── */

/** @brief General Interrupt Control Register (INT enable bits). @addr 0x5B */
#define GICR_REG         _SetAddress8bit(0x5B)

/** @brief General Interrupt Flag Register.                       @addr 0x5A */
#define GIFR_REG         _SetAddress8bit(0x5A)

/** @brief Timer/Counter Interrupt Mask Register.                 @addr 0x59 */
#define TIMSK_REG        _SetAddress8bit(0x59)

/** @brief Timer/Counter Interrupt Flag Register.                 @addr 0x58 */
#define TIFR_REG         _SetAddress8bit(0x58)

/* ── Port A ──────────────────────────────────────────────────────────────── */

/** @brief Port A Data Register.                                  @addr 0x3B */
#define PORTA_REG        _SetAddress8bit(0x3B)

/** @brief Port A Data Direction Register.                        @addr 0x3A */
#define DDRA_REG         _SetAddress8bit(0x3A)

/** @brief Port A Input Pins Register.                            @addr 0x39 */
#define PINA_REG         _SetAddress8bit(0x39)

/* ── Port B ──────────────────────────────────────────────────────────────── */

/** @brief Port B Data Register.                                  @addr 0x38 */
#define PORTB_REG        _SetAddress8bit(0x38)

/** @brief Port B Data Direction Register.                        @addr 0x37 */
#define DDRB_REG         _SetAddress8bit(0x37)

/** @brief Port B Input Pins Register.                            @addr 0x36 */
#define PINB_REG         _SetAddress8bit(0x36)

/* ── Port C ──────────────────────────────────────────────────────────────── */

/** @brief Port C Data Register.                                  @addr 0x35 */
#define PORTC_REG        _SetAddress8bit(0x35)

/** @brief Port C Data Direction Register.                        @addr 0x34 */
#define DDRC_REG         _SetAddress8bit(0x34)

/** @brief Port C Input Pins Register.                            @addr 0x33 */
#define PINC_REG         _SetAddress8bit(0x33)

/* ── Port D ──────────────────────────────────────────────────────────────── */

/** @brief Port D Data Register.                                  @addr 0x32 */
#define PORTD_REG        _SetAddress8bit(0x32)

/** @brief Port D Data Direction Register.                        @addr 0x31 */
#define DDRD_REG         _SetAddress8bit(0x31)

/** @brief Port D Input Pins Register.                            @addr 0x30 */
#define PIND_REG         _SetAddress8bit(0x30)

/* ── Timer0 (8-bit) ──────────────────────────────────────────────────────── */

/** @brief Timer/Counter0 Control Register.                       @addr 0x53 */
#define TCCR0_REG        _SetAddress8bit(0x53)

/** @brief Timer/Counter0 Register (counter value).               @addr 0x52 */
#define TCNT0_REG        _SetAddress8bit(0x52)

/** @brief Output Compare Register 0.                             @addr 0x5C */
#define OCR0_REG         _SetAddress8bit(0x5C)

/* ── Timer1 (16-bit) ─────────────────────────────────────────────────────── */

/** @brief Timer/Counter1 Control Register A.                     @addr 0x4F */
#define TCCR1A_REG       _SetAddress8bit(0x4F)

/** @brief Timer/Counter1 Control Register B.                     @addr 0x4E */
#define TCCR1B_REG       _SetAddress8bit(0x4E)

/** @brief Timer/Counter1 High byte.                              @addr 0x4D */
#define TCNT1H_REG       _SetAddress8bit(0x4D)

/** @brief Timer/Counter1 Low byte.                               @addr 0x4C */
#define TCNT1L_REG       _SetAddress8bit(0x4C)

/** @brief Timer/Counter1 (16-bit access).                        @addr 0x4C */
#define TCNT1_REG        _SetAddress16bit(0x4C)

/** @brief Output Compare Register 1A (16-bit).                   @addr 0x4A */
#define OCR1A_REG        _SetAddress16bit(0x4A)

/** @brief Output Compare Register 1B (16-bit).                   @addr 0x48 */
#define OCR1B_REG        _SetAddress16bit(0x48)

/** @brief Input Capture Register 1 (16-bit).                     @addr 0x46 */
#define ICR1_REG         _SetAddress16bit(0x46)

/* ── Timer2 (8-bit, Async capable) ──────────────────────────────────────── */

/** @brief Timer/Counter2 Control Register.                       @addr 0x45 */
#define TCCR2_REG        _SetAddress8bit(0x45)

/** @brief Timer/Counter2 Register (counter value).               @addr 0x44 */
#define TCNT2_REG        _SetAddress8bit(0x44)

/** @brief Output Compare Register 2.                             @addr 0x43 */
#define OCR2_REG         _SetAddress8bit(0x43)

/** @brief Asynchronous Status Register (Timer2 async clock).     @addr 0x42 */
#define ASSR_REG         _SetAddress8bit(0x42)

/* ── ADC ─────────────────────────────────────────────────────────────────── */

/** @brief ADC Multiplexer Selection Register.                    @addr 0x27 */
#define ADMUX_REG        _SetAddress8bit(0x27)

/** @brief ADC Control and Status Register A.                     @addr 0x26 */
#define ADCSRA_REG       _SetAddress8bit(0x26)

/** @brief ADC Data Register High byte.                           @addr 0x25 */
#define ADCH_REG         _SetAddress8bit(0x25)

/** @brief ADC Data Register Low byte.                            @addr 0x24 */
#define ADCL_REG         _SetAddress8bit(0x24)

/** @brief ADC Data Register (16-bit, right-adjusted).            @addr 0x24 */
#define ADC_REG          _SetAddress16bit(0x24)

/* ── EEPROM ──────────────────────────────────────────────────────────────── */

/** @brief EEPROM Address Register (16-bit).                      @addr 0x3E */
#define EEAR_REG         _SetAddress16bit(0x3E)

/** @brief EEPROM Data Register.                                  @addr 0x3D */
#define EEDR_REG         _SetAddress8bit(0x3D)

/** @brief EEPROM Control Register.                               @addr 0x3C */
#define EECR_REG         _SetAddress8bit(0x3C)

/* ── SPI ─────────────────────────────────────────────────────────────────── */

/** @brief SPI Data Register.                                     @addr 0x2F */
#define SPDR_REG         _SetAddress8bit(0x2F)

/** @brief SPI Status Register.                                   @addr 0x2E */
#define SPSR_REG         _SetAddress8bit(0x2E)

/** @brief SPI Control Register.                                  @addr 0x2D */
#define SPCR_REG         _SetAddress8bit(0x2D)

/* ── USART ───────────────────────────────────────────────────────────────── */

/** @brief USART I/O Data Register.                               @addr 0x2C */
#define UDR_REG          _SetAddress8bit(0x2C)

/** @brief USART Control and Status Register A.                   @addr 0x2B */
#define UCSRA_REG        _SetAddress8bit(0x2B)

/** @brief USART Control and Status Register B.                   @addr 0x2A */
#define UCSRB_REG        _SetAddress8bit(0x2A)

/** @brief USART Baud Rate Register Low (shared with UBRRH/UCSRC).@addr 0x29 */
#define UBRRL_REG        _SetAddress8bit(0x29)

/** @brief USART Baud Rate Register High.                         @addr 0x40 */
#define UBRRH_REG        _SetAddress8bit(0x40)

/** @brief USART Control and Status Register C (shared w/ UBRRH). @addr 0x40 */
#define UCSRC_REG        _SetAddress8bit(0x40)

/* ── TWI / I²C ───────────────────────────────────────────────────────────── */

/** @brief TWI Data Register.                                     @addr 0x23 */
#define TWDR_REG         _SetAddress8bit(0x23)

/** @brief TWI (Slave) Address Register.                          @addr 0x22 */
#define TWAR_REG         _SetAddress8bit(0x22)

/** @brief TWI Control Register.                                  @addr 0x56 */
#define TWCR_REG         _SetAddress8bit(0x56)

/* ── Register Aliases (Ref-Repo naming — used by Timer & ADC drivers) ────── */

/** @brief Alias for PORTA_REG — used by reference-style drivers. */
#define PORTA_Reg        PORTA_REG
/** @brief Alias for DDRA_REG. */
#define DDRA_Reg         DDRA_REG
/** @brief Alias for PINA_REG. */
#define PINA_Reg         PINA_REG

/** @brief Alias for PORTB_REG. */
#define PORTB_Reg        PORTB_REG
/** @brief Alias for DDRB_REG. */
#define DDRB_Reg         DDRB_REG
/** @brief Alias for PINB_REG. */
#define PINB_Reg         PINB_REG

/** @brief Alias for PORTC_REG. */
#define PORTC_Reg        PORTC_REG
/** @brief Alias for DDRC_REG. */
#define DDRC_Reg         DDRC_REG
/** @brief Alias for PINC_REG. */
#define PINC_Reg         PINC_REG

/** @brief Alias for PORTD_REG. */
#define PORTD_Reg        PORTD_REG
/** @brief Alias for DDRD_REG. */
#define DDRD_Reg         DDRD_REG
/** @brief Alias for PIND_REG. */
#define PIND_Reg         PIND_REG

/** @brief Alias for SREG_REG. */
#define SREG_Reg         SREG_REG
/** @brief Alias for MCUCR_REG. */
#define MCUCR_Reg        MCUCR_REG
/** @brief Alias for MCUCSR_REG. */
#define MCUCSR_Reg       MCUCSR_REG
/** @brief Alias for GICR_REG. */
#define GICR_Reg         GICR_REG
/** @brief Alias for GIFR_REG. */
#define GIFR_Reg         GIFR_REG

/** @brief Alias for ADMUX_REG. */
#define ADMUX_Reg        ADMUX_REG
/** @brief Alias for ADCSRA_REG. */
#define ADCSRA_Reg       ADCSRA_REG
/** @brief Alias for ADCH_REG. */
#define ADCH_Reg         ADCH_REG
/** @brief Alias for ADCL_REG. */
#define ADCL_Reg         ADCL_REG
/** @brief Alias for ADC_REG (16-bit). */
#define ADCData_Reg      ADC_REG
/** @brief Alias for SFIOR_REG. */
#define SFIOR_Reg        SFIOR_REG

/** @brief Alias for TCCR0_REG. */
#define TCCR0_Reg        TCCR0_REG
/** @brief Alias for TCNT0_REG. */
#define TCNT0_Reg        TCNT0_REG
/** @brief Alias for OCR0_REG. */
#define OCR0_Reg         OCR0_REG

/** @brief Alias for TCCR1A_REG. */
#define TCCR1A_Reg       TCCR1A_REG
/** @brief Alias for TCCR1B_REG. */
#define TCCR1B_Reg       TCCR1B_REG
/** @brief Alias for TCNT1_REG (16-bit). */
#define TCNT1_Reg        TCNT1_REG
/** @brief Alias for OCR1A_REG (16-bit). */
#define OCR1A_Reg        OCR1A_REG
/** @brief Alias for OCR1B_REG (16-bit). */
#define OCR1B_Reg        OCR1B_REG
/** @brief Alias for ICR1_REG (16-bit). */
#define ICR1_Reg         ICR1_REG

/** @brief Alias for TCCR2_REG. */
#define TCCR2_Reg        TCCR2_REG
/** @brief Alias for TCNT2_REG. */
#define TCNT2_Reg        TCNT2_REG
/** @brief Alias for OCR2_REG. */
#define OCR2_Reg         OCR2_REG
/** @brief Alias for ASSR_REG. */
#define ASSR_Reg         ASSR_REG
/** @brief Alias for TIMSK_REG. */
#define TIMSk_Reg        TIMSK_REG
/** @brief Alias for TIFR_REG. */
#define TIFR_Reg         TIFR_REG

#endif /* _MCAL_ATMEGA32REGISTERS_H_ */
