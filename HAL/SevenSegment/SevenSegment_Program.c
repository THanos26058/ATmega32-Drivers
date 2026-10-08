/**
 * @file    SevenSegment_Program.c
 * @brief   Implementation of the Seven-Segment Display HAL driver.
 * @author  Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @date    2026-10-08
 * @version 0.1
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#if SevSeg_Driver

#include "SevenSegment_Config.h"
#include "SevenSegment_Private.h"
#include "SevenSegment_Interface.h"

static const uint8_t SEVENSEGMENT_DISPLAY_NUMBERS[10] = {
    SEVENSEGMENT_ZERO,
    SEVENSEGMENT_ONE,
    SEVENSEGMENT_TWO,
    SEVENSEGMENT_THREE,
    SEVENSEGMENT_FOUR,
    SEVENSEGMENT_FIVE,
    SEVENSEGMENT_SIX,
    SEVENSEGMENT_SEVEN,
    SEVENSEGMENT_EIGHT,
    SEVENSEGMENT_NINE
};

void SevenSegment_Init(const SevenSegment_Config_t *Config)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    DIO_DirectionSelectForGroup(Config->GroupName, DIO_AllOutput);
}

/**
 * @brief
 *
 * @param Config
 * @param Number
 */
void SevenSegment_DisplayNumber(const SevenSegment_Config_t *Config, uint8_t Number)
{
    if (Config == NULL)
    {
        // TODO: Handle Error Here;
        return;
    }

    if (Number > 9)
    {
        // TODO: Handle Error Here;
        return;
    }

    switch (Config->Type)
    {
    case SEVENSEGMENT_COMMON_ANODE:
        DIO_WriteForGroup(Config->GroupName, SEVENSEGMENT_DISPLAY_NUMBERS[Number]);
        break;
    case SEVENSEGMENT_COMMON_CATHODE:
        DIO_WriteForGroup(Config->GroupName, ~SEVENSEGMENT_DISPLAY_NUMBERS[Number]);
        break;

    default:
        // TODO: Handle Error Here;
        break;
    }
}
#endif /* SevSeg_Driver */

