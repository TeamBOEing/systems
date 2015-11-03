/*
 * IR Test
 * Author: Corbin Murrow, Cody Crossley
 * Date: 03 November 2015
 * Version: 1.3
 * 
 * This software will test the left and right IR sensors. The 
 * softwre will check each sensor every second and when a
 * sensor detects something it will print out to the serial
 * monitor: "<Left/Right> IR: 1".
 * 
 * ======= VERSION HISTORY =======
 * Version 1.3: Updated to use BOEbot library rev 1.0 - CC - 03 November 2015
 * Version 1.2: Tone works to continuously send signal - CM & CC - 30 September 2015
 * Version 1.1: Attempted to use Servo.h, regular PWM, etc. but unsuccessful - CC - 28 September 2015
 * Version 1.0: Created file, added header - CM - 25 September 2015
 */

#include <Servo.h>
#include "BOEbot.h"

#define LOOP_DELAY_TIME 1000      // Wait 1 second between object detections

void setup() {
  initialize();
}

bool leftIrDetected, rightIrDetected;   // HIGH when object is detected

void loop() {
  // Detect IR signals bouncing off objects
  Serial.print("Left IR: ");
  // If IR sensor detects object, the return will be HIGH
  if ( leftObstacle() ) {
    digitalWrite(LED_PIN_GREEN, HIGH);      // Turn green LED on if detected
    Serial.print("1");
  }
  else {
    digitalWrite(LED_PIN_GREEN, LOW);       // Turn green LED off if not detected
    Serial.print("0");
  }

  // If IR sensor detects object, the return will be HIGH
  Serial.print("\tRight IR: ");
  if ( rightObstacle() ) {
    digitalWrite(LED_PIN_RED, HIGH);        // Turn red LED on if detected
    Serial.println("1");
  }
  else {
    digitalWrite(LED_PIN_RED, LOW);         // Turn red LED off if not detected
    Serial.println("0");
  }
  
  delay(LOOP_DELAY_TIME);
}
