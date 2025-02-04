// #include <IRremote.hpp>

#include <Arduino.h>
#include "mcoreTypes.h"
#include "debugSerial.h"
#include "pinsSetup.h"
#include "btnLogic.h"
#include "tacho.h"
#include "fan.h"

//todo ir in 

void setup()
{ 
  setupPins();
  debugSetup();
#ifdef USE_TACHO
  attachInterrupt(digitalPinToInterrupt(tachoPin), ISR_Tacho, RISING);
#endif
}

void loop() {
  static uint32_t timeNow = millis();
  debBtnLedChange();
  handlePotReading();
  setFanSpeed(fanSpd);
}
