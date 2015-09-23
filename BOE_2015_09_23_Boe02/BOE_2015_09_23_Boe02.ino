// Cody Crossley
// Systems II - Team BOEing
// 23 Sept. 2015

#include "BOE02.h"



void setup() {
  Serial.begin(115200);
  
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedG, OUTPUT);
}

void loop() {
  pulsePinHigh(pinLedG, SECOND);
  delay(SECOND);
  
  pulsePinHigh(pinLedG, SECOND);
  delay(SECOND);
}
