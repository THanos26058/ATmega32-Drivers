
#ifndef _SEVENSEGMENT_INTERFACE_H_
#define _SEVENSEGMENT_INTERFACE_H_

#include <stdint.h>

#include "SevenSegment_Config.h"

#define SEVENSEGMENT_COMMON_CATHODE   1
#define SEVENSEGMENT_COMMON_ANODE     2

typedef struct {
    uint8_t GroupName;
    uint8_t Type;
} SevenSegment_Config_t;

void SevenSegment_Init(const SevenSegment_Config_t *Config);


void SevenSegment_DisplayNumber(const SevenSegment_Config_t *Config, uint8_t Number);

#endif // _SEVENSEGMENT_INTERFACE_H_
