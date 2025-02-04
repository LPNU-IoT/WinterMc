#pragma once

#include "mcoreTypes.h"
#include "fan.h"

bool ledStateToChange = false;
bool ledState = false;
bool stateRelay = false;

// variables will change:
uint8_t buttonStateLast = 0;  // variable for reading the pushbutton status
uint8_t buttonStateCurr = 0;  // variable for reading the pushbutton status


unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void debBtnLedChange()
{
  u8 reading = digitalRead(buttonPin);
  if (reading != buttonStateLast) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  { 
    if (reading != buttonStateCurr) {
      buttonStateCurr = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonStateCurr == HIGH) {
        ledState = !ledState;
        fanSpd+=10;
        if(fanSpd > 240)
        {
          fanSpd = 0;
        }
      }
    }
  }
}