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

#define BAUD_RATE 115200
#define LEFTPIN 5
#define RIGHTPIN 6
#define LEFTBASE 1504         // Use PWM_Calibration to determine this values
#define RIGHTBASE 1492        // Use PWM_Calibration to determine this values
#define BASE_STOP_VALUE 1500  // The nominal stop value
#define DELAY_TIME 5000

Servo leftServo;
Servo rightServo;

void setup() 
{
  //Set up servos
  leftServo.attach(LEFTPIN); //Physical pin 11 to left servo
  rightServo.attach(RIGHTPIN); //Physical pin 12 to right servo

  //Set up Serial Monitor
  Serial.begin(BAUD_RATE);
}

int speed = 100;

void loop() 
{
  Serial.println("\nMotor Test Start\n");
  
  //Both Forward
  Serial.println("Both Forward");
  leftServo.writeMicroseconds(BASE_STOP_VALUE + speed);
  rightServo.writeMicroseconds(BASE_STOP_VALUE - speed);
  delay(DELAY_TIME); //pause for 1 second
  Serial.println("Both Stop");
  leftServo.writeMicroseconds(LEFTBASE);
  rightServo.writeMicroseconds(RIGHTBASE);
  delay(DELAY_TIME);

  Serial.println();

  //Both Backward
  Serial.println("Both Backward");
  leftServo.writeMicroseconds(BASE_STOP_VALUE - speed);
  rightServo.writeMicroseconds(BASE_STOP_VALUE + speed);
  delay(DELAY_TIME); //pause for 1 second
  Serial.println("Both Stop");
  leftServo.writeMicroseconds(LEFTBASE);
  rightServo.writeMicroseconds(RIGHTBASE);
  delay(DELAY_TIME);

  Serial.println();

  //Left Forward/Right Backward
  Serial.println("Left Forward/Right Backward");
  leftServo.writeMicroseconds(BASE_STOP_VALUE + speed);
  rightServo.writeMicroseconds(BASE_STOP_VALUE + speed);
  delay(DELAY_TIME); //pause for 1 second
  Serial.println("Both Stop");
  leftServo.writeMicroseconds(LEFTBASE);
  rightServo.writeMicroseconds(RIGHTBASE);
  delay(DELAY_TIME);

  Serial.println();

  //Left Backward/Right Forward
  Serial.println("Left Backward/Right Forward");
  leftServo.writeMicroseconds(BASE_STOP_VALUE - speed);
  rightServo.writeMicroseconds(BASE_STOP_VALUE - speed);
  delay(DELAY_TIME); //pause for 1 second
  Serial.println("Both Stop");
  leftServo.writeMicroseconds(LEFTBASE);
  rightServo.writeMicroseconds(RIGHTBASE);
  delay(DELAY_TIME);

  Serial.println();
}

