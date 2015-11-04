/*
 * PWM Test
 * Author: Corbin Murrow, Cody Crossley, Daniel Sheldon
 * Date: 3 november 2015
 * Version: 1.4
 * 
 * This software validates that the pcb properly controlles the motors
 * 
 * ======= VERSION HISTORY =======
 * Version 1.4: rewritten with current function calls to execute subsystem test 3 november 2015
 * Version 1.3: Updated comments, added more defines - CC - 28 September 2015
 * Version 1.2: Updated base values for servos - CM - 26 September 2015
 * Version 1.1: Coded in setup and main - CM - 25 September 2015
 * Version 1.0: Created file - CM - 25 September 2015
 */

#include <Servo.h>
#include "BOEbot.h"

void setup() 
{
  initialize();
}
int shortDelay = 100;
int longDelay = 1000;
int pauseDelay = 3000;
int speed = 250;

void loop() 
{
  Serial.println("\nMotor Test Program Start\n");
  
  //Left Forward
  Serial.println("Left Forward");
  turnLeftMotorForward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

  //Left Backward
  Serial.println("Left Backward");
  turnLeftMotorBackward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

  //Right Forward
  Serial.println("Right Forward");
  turnRightMotorForward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

  //Right Backward
  Serial.println("Right Backward");
  turnRightMotorBackward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

}

