/*
 * Light Sensor Test
 * Author: Corbin Murrow, Adam Clothier, Cody Crossley
 * Date: 03 November 2015
 * Version: 1.2
 * 
 * This software will test the photoresistors by reading the
 * value from an analog input pin and printing the value to the
 * serial monitor in the format "<Left/Right> Light: <value>".
 * 
 * ======= VERSION HISTORY =======
 * Version 1.2: Updated to use BOEbot library rev 1.0 - CC - 03 November 2015
 * Version 1.1: Wrote code for LS test, verified using only Serial Monitor - AC - 29 September 2015
 * Version 1.0: Created file and added header - CM - 25 September 2015
 */

#include <Servo.h>
#include "BOEbot.h"

void setup() {
  initialize();
}

void loop() {
  Serial.print("Left Photo-Resistor: ");
  Serial.println( getLeftLight() );
  
  Serial.print("Right Photo-Resistor: ");
  Serial.println( getRightLight() );
  
  delay(1000);
}
