#ifndef TACHO_H
#define TACHO_H

#include <Arduino.h>
#include "mcoreTypes.h"

volatile uint32_t tachoCountRMP = 0;

void IRAM_ATTR ISR_Tacho()
{
    tachoCountRMP++;
}

#endif // TACHO_H