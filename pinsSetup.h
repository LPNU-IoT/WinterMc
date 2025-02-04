#ifndef PINS_SETUP_H
#define PINS_SETUP_H

#include <Arduino.h>



#ifdef USE_TACHO
const pin_t tachoPin = D6; 
const pin_t buttonPin = D5;  // the number of the pushbutton pin
const pin_t ledPin = LED_BUILTIN;    // the number of the LED pin
const pin_t fanPin = D7;

#else
// const pin_t tachoPin = 0;
const pin_t buttonPin = D8;  // the number of the pushbutton pin
const pin_t ledPin = D6;    // the number of the LED pin
const pin_t fanPin = D7;
#endif 

const pin_t potPin = A0;

void setupPins()
{
  pinMode(buttonPin, INPUT);

#ifdef USE_TACHO
  pinMode(tachoPin, INPUT);
#endif

  pinMode(potPin, INPUT);
  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, 10); //! UINT8_MAX

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); //on

  
}


#endif