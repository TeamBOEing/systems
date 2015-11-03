/* 
 *  LED Test Software
 *  Author: Corbin Murrow, Cody Crossley
 *  Date: 03 November 2015
 *  Version: 1.4
 *  
 *  This software does turns a red and green LED 
 *  ON. Also outputs to the serial monitor when
 *  the LEDs turn on or off.
 *  
 *  ====== VERSION HISTORY ======
 *  Version 1.4: Updated to use the BOEbot library rev 1.0 - CC - 03 November 2015
 *  Version 1.3: Updated consts to defines for pin #s - CM - 28 September 2015
 *  Version 1.2: Included use of constants and updated pin number - CC - 28 September 2015
 *  Version 1.1: Updated file header - CM - 25 September 2015
 *  Version 1.0: Created project - CM - 20 September 2015
 */

#include <Servo.h>
#include "BOEbot.h"

#define BLINK_SPEED 1000

// The setup function runs once when you press reset or power the board
void setup() {
  initialize();
}

// The loop function runs over and over again forever
void loop() {
  turnOnGreenLED();
  Serial.println("Green On");
  delay(BLINK_SPEED);                 // wait for a second
  turnOffGreenLED();
  Serial.println("Green Off");
  delay(BLINK_SPEED);                 // wait for a second
  
  // Perform same as above with the red LED
  turnOnRedLED();
  Serial.println("Red On");
  delay(BLINK_SPEED);
  turnOffRedLED();
  Serial.println("Red Off");
  delay(BLINK_SPEED);
}
