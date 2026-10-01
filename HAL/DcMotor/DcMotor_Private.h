#ifndef DCMOTOR_PRIVATE
#define DCMOTOR_PRIVATE
#include <stdint.h>

typedef enum
{
    Dc_WithoutHBridge,
    Dc_WithHBridge
} Dc_ConnectionType_t;

typedef struct
{
    uint8_t ConnectionType;
    uint8_t DC_M1Group;
    uint8_t DC_M1Pin;
    uint8_t DC_M2Group;
    uint8_t DC_M2Pin;
} Dc_Config_t;

#endif /* DCMOTOR_PRIVATE */
