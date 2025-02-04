#ifndef DEBUG_SERIAL_H
#define DEBUG_SERIAL_H

#include <Arduino.h>

#define DEBUG 1

#ifdef DEBUG
#define PRINT(x) Serial.print(x)
#define PRINTLN(x) Serial.println(x)
#else
#define DEBUG(x)
#define PRINTLN(x)
#endif

// void debugPRINTLN(const String &message)
// {
// #ifdef DEBUG
//     Serial.PRINTLNln(message);
// #endif
// }

void debugSetup()
{
    #if (DEBUG>0)

    Serial.begin(112500);
    delay(100);
    PRINTLN();
    PRINTLN("BEGIN");


    #endif
}

#endif // DEBUG_SERIAL_H