// #include <IRremote.hpp>

#include <Arduino.h>
#include "mcoreTypes.h"
#include "debugSerial.h"
#include "pinsSetup.h"
#include "btnLogic.h"
#include "tacho.h"
#include "fan.h"
#include "pot.h"
#include "server.h"

//todo ir in 

void setup()
{ 
  setupPins();
  debugSetup();
#ifdef USE_TACHO
  attachInterrupt(digitalPinToInterrupt(tachoPin), ISR_Tacho, RISING);
#endif
  setupWebServer();
}

void loop() {
  static uint32_t timeNow = millis();
  server.handleClient();

  debBtnLedChange();
  handlePotReading();

  setFanSpeed(fanSpd);


}
