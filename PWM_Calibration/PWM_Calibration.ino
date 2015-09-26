/*
 * PWM Calibration
 * Author: Corbin Murrow
 * Date: 26 September 2015
 * Version: 1.0
 * 
 * This software can be run to find the stop value to pass to the
 * Servo.writeMicroseconds() function to generate a 1.5ms pulse
 * that will stop the continuous rotation servo.
 * 
 * ======= VERSION HISTORY =======
 * Version 1.0: Created file - CM - 26 September 2015
 */

#include <Servo.h>

#define LEFTPIN 5
#define RIGHTPIN 6

Servo leftServo;
Servo rightServo;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("Begin Motor Calibration\n");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println("Left Motor Calibration - watch/listen to the left motor.");
  Serial.println("When it stops, record the value on the screen.");
  Serial.println("Note: There may be a range of 3 or 4 values, any will work.\n");

  leftServo.attach(LEFTPIN);
  
  for (int leftSpeed = 1475; leftSpeed <= 1525; leftSpeed++)
  {
    leftServo.writeMicroseconds(leftSpeed);
    Serial.print("Left speed: ");
    Serial.println(leftSpeed);
    delay(1000);
  }

  leftServo.detach();

  Serial.println("\nRight Motor Calibration - watch/listen to the right motor.");
  Serial.println("When the motor stops, record the value on the screen.");
  Serial.println("Note: There may be a range of 3 or 4 values, any will work.\n");

  delay(3000);

  rightServo.attach(RIGHTPIN);

  for (int rightSpeed = 1475; rightSpeed <= 1525; rightSpeed++)
  {
    rightServo.writeMicroseconds(rightSpeed);
    Serial.print("Right speed: ");
    Serial.println(rightSpeed);
    delay(1000);
  }

  rightServo.detach();

  while(1);
}
