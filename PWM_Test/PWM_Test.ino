/*
 * PWM Test
 * Author: Corbin Murrow
 * Date: 25 September 2015
 * Version: 1.1
 * 
 * This software tests PWM output to turn the continuous 
 * rotation servos that the BOEbot uses as motors. Left and 
 * right motor will turn forward and backward simultaneously 
 * as well as left forward/right backward and vice versa.
 * 
 * ======= VERSION HISTORY =======
 * Version 1.1: Coded in setup and main - CM - 25 September 2015
 * Version 1.0: Created file - CM - 25 September 2015
 */

#include <Servo.h>

#define LEFTPIN 5
#define RIGHTPIN 6
#define LEFTSTOP 1505 //these have to be determined experimentally per motor
#define RIGHTSTOP 1490 //these have to be determined experimentally per motor
#define GO 1500 //the nominal stop value

Servo leftServo;
Servo rightServo;

void setup() {
  //This code runs once

  //Set up servos
  leftServo.attach(LEFTPIN); //Physical pin 11 to left servo
  rightServo.attach(RIGHTPIN); //Physical pin 12 to right servo

  //Set up Serial Monitor
  Serial.begin(115200); //115200 baud
}

int speed = 100;

void loop() {

  //Both Forward
  Serial.println("Both Forward");
  leftServo.write(GO+speed);
  rightServo.write(GO-speed);
  delay(5000); //pause for 5 seconds
  Serial.println("Both Stop");
  leftServo.write(LEFTSTOP);
  rightServo.write(RIGHTSTOP);
  delay(5000);

  Serial.println();

  //Both Backward
  Serial.println("Both Backward");
  leftServo.write(GO-speed);
  rightServo.write(GO+speed);
  delay(5000); //pause for 5 seconds
  Serial.println("Both Stop");
  leftServo.write(LEFTSTOP);
  rightServo.write(RIGHTSTOP);
  delay(5000);

  Serial.println();

  //Left Forward/Right Backward
  Serial.println("Left Forward/Right Backward");
  leftServo.write(GO+speed);
  rightServo.write(GO+speed);
  delay(5000); //pause for 5 seconds
  Serial.println("Both Stop");
  leftServo.write(LEFTSTOP);
  rightServo.write(RIGHTSTOP);
  delay(5000);

  Serial.println();

  //Left Backward/Right Forward
  Serial.println("Left Backward/Right Forward");
  leftServo.write(GO-speed);
  rightServo.write(GO-speed);
  delay(5000); //pause for 5 seconds
  Serial.println("Both Stop");
  leftServo.write(LEFTSTOP);
  rightServo.write(RIGHTSTOP);
  delay(5000);

  Serial.println();
}
