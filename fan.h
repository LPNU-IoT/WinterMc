#ifndef FAN_H
#define FAN_H

#include <Arduino.h>
#include "mcoreTypes.h"
#include "pinsSetup.h"

u8 fanSpd = 0;
u8 fanSpdLast = fanSpd;

void setFanSpeed(uint8_t new_speed)
{
    if (new_speed != fanSpdLast)
    {
        fanSpdLast = new_speed;
       // PRINT("Fan speed: "); PRINTLN(fanSpdLast);  
        // constrain();
        analogWrite(fanPin, fanSpdLast);
    }
    
    #if (DEBUG > 0 )
    uint8_t speedPercent = new_speed;
    map(speedPercent, 0, 255, 0, 100);
   // PRINT("Fan speed: "); PRINTLN(speedPercent);
    #endif
}

#endif // FAN_H