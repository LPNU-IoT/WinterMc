#ifndef POT_H
#define POT_H
#include <Arduino.h>
#include "debugSerial.h"
#include "fan.h"

uin16_t lastPotVoltage = 0;

uin16_t getPotValue()
{
    return analogRead(potPin);
}

void handlePotReading()
{
    uin16_t newVoltage = getPotValue();

    if( abs(lastPotVoltage - newVoltage) > 5) // cut off noize
    {
        PRINT("Last V: "); PRINT(lastPotVoltage);
        PRINT(" New V: "); PRINTLN(newVoltage);
        lastPotVoltage = newVoltage;
        
        // setFanSpeed(static_cast<uint8>)
        fanSpd = static_cast<uint8_t>map(lastPotVoltage, 0 , 1024, 0, 255);
    }

}
#endif