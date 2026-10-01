
#ifndef KPD_INTERFACE
#define KPD_INTERFACE

#include <stdint.h>

#include "KPD_Private.h"
#include "KPD_Config.h"

void KPD_Init();
void KPD_GetKPDValue(uint8_t *KPD_Value);

#endif /* KPD_INTERFACE */
