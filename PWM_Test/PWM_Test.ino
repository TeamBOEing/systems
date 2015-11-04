/*
 * PWM Test
 * Author: Corbin Murrow, Cody Crossley
 * Date: 28 September 2015
 * Version: 1.3
 * 
 * This software tests PWM output to turn the continuous 
 * rotation servos that the BOEbot uses as motors. Left and 
 * right motor will turn forward and backward simultaneously 
 * as well as left forward/right backward and vice versa.
 * 
 * ======= VERSION HISTORY =======
 * Version 1.3: Updated comments, added more defines - CC - 28 September 2015
 * Version 1.2: Updated base values for servos - CM - 26 September 2015
 * Version 1.1: Coded in setup and main - CM - 25 September 2015
 * Version 1.0: Created file - CM - 25 September 2015
 */

#include <Servo.h>
#include <BOEbot.h>

#define DELAY 1000

void setup() 
{
  initialize();
}

int speed = 100;

void loop() 
{
  Serial.println("\nMotor Test Start\n");
  
  //Both Forward
  Serial.println("Both Forward");
  leftMotor(speed);
  rightMotor(speed);
  
  delay(DELAY); //pause for 1 second
  Serial.println("Both Stop");
  leftMotor(0);
  rightMotor(0);
  delay(5*DELAY);

  Serial.println();

  //Both Backward
  Serial.println("Both Backward");
  leftMotor(-speed);
  rightMotor(-speed);
  delay(DELAY); //pause for 1 second
  
  Serial.println("Both Stop");
  leftMotor(0);
  rightMotor(0);
  delay(5*DELAY);

  Serial.println();

  //Left Forward/Right Backward
  Serial.println("Left Forward/Right Backward");
  leftMotor(speed);
  rightMotor(-speed);
  delay(DELAY); //pause for 1 second
  Serial.println("Both Stop");
  leftMotor(0);
  rightMotor(0);
  delay(5*DELAY);

  Serial.println();

  //Left Backward/Right Forward
  Serial.println("Left Backward/Right Forward");
  leftMotor(-speed);
  rightMotor(speed);
  delay(DELAY); //pause for 1 second
  Serial.println("Both Stop");
  leftMotor(0);
  rightMotor(0);
  delay(5*DELAY);

  Serial.println();
}

