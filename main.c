/**
 * @file main.c
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief LDR controls a group of LEDs based on ambient light level
 *
 * Schematic:
 * - LDR connected in PULL_DOWN config on ADC Channel 0 (PA0)
 *   (LDR between VCC and PA0, 10K resistor between PA0 and GND)
 *
 * - 4 LEDs connected Active-High on Group B:
 *     LED1 -> PB0
 *     LED2 -> PB1
 *     LED3 -> PB2
 *     LED4 -> PB3
 *
 * Light Logic:
 *   Dark   (0% - 24%)  -> 4 LEDs ON  (maximum brightness)
 *   Dim    (25% - 49%) -> 3 LEDs ON
 *   Normal (50% - 74%) -> 2 LEDs ON
 *   Bright (75% - 100%)-> All LEDs OFF (enough ambient light)
 *
 * @version 0.1
 * @date 2026-10-01
 */

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LDR/LDR_Interface.h"
#include "HAL/LED/LED_Interface.h"

/* LDR Configuration */
const LDR_Config_t LightSensor = {
    .Channel        = Adc_SingleEndedChannel0,   /* PA0 */
    .ConnectionType = LDR_PULL_DOWN   /* LDR to VCC, Resistor to GND */
};

/* LED Configurations */
const LED_Config_t LED1 = { .GroupName = DIO_GroupB, .PinNo = DIO_Pin0, .ConnectionType = LED_ACTIVE_HIGH };
const LED_Config_t LED2 = { .GroupName = DIO_GroupB, .PinNo = DIO_Pin1, .ConnectionType = LED_ACTIVE_HIGH };
const LED_Config_t LED3 = { .GroupName = DIO_GroupB, .PinNo = DIO_Pin2, .ConnectionType = LED_ACTIVE_HIGH };
const LED_Config_t LED4 = { .GroupName = DIO_GroupB, .PinNo = DIO_Pin3, .ConnectionType = LED_ACTIVE_HIGH };


int main(void)
{
    /* Initialize ADC */
    ADC_Init();

    /* Initialize LDR */
    LDR_Init(&LightSensor);

    /* Initialize LEDs */
    LED_Init(&LED1);
    LED_Init(&LED2);
    LED_Init(&LED3);
    LED_Init(&LED4);

    LDR_LightLevel_t LightLevel = LDR_Bright;

    while (1)
    {
        /* Read Ambient Light Level */
        LDR_GetLightLevel(&LightSensor, &LightLevel);

        switch (LightLevel)
        {
            case LDR_Dark:
                /* Very dark -> turn on all 4 LEDs */
                LED_TurnOn(&LED1);
                LED_TurnOn(&LED2);
                LED_TurnOn(&LED3);
                LED_TurnOn(&LED4);
                break;

            case LDR_Dim:
                /* Dim -> turn on 3 LEDs */
                LED_TurnOn(&LED1);
                LED_TurnOn(&LED2);
                LED_TurnOn(&LED3);
                LED_TurnOff(&LED4);
                break;

            case LDR_Normal:
                /* Normal -> turn on 2 LEDs */
                LED_TurnOn(&LED1);
                LED_TurnOn(&LED2);
                LED_TurnOff(&LED3);
                LED_TurnOff(&LED4);
                break;

            case LDR_Bright:
                /* Bright -> turn off all LEDs */
                LED_TurnOff(&LED1);
                LED_TurnOff(&LED2);
                LED_TurnOff(&LED3);
                LED_TurnOff(&LED4);
                break;

            default:
                // TODO: Handle Error Here;
                break;
        }
    }

    return 0;
}
