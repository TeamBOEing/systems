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

#include <BOEbot.h>
#include <Servo.h>

void setup() 
{
  initialize();
}

int shortDelay = 100; //let motors stop spinning before sending new commands
int longDelay = 1000; //how long any given motor rotation should be
int pauseDelay = 3000;//definite pause between sections of motor test
int speed = 200;

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


  Serial.println("individual directions tested, pausing");
  delay(pauseDelay);
  Serial.println("begin simultaneous operaton test");

  //both forward
  Serial.println("Both Forward");
  turnRightMotorForward(speed);
  turnLeftMotorForward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

  //both backward
  Serial.println("Both Backward");
  turnRightMotorBackward(speed);
  turnLeftMotorBackward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

  //left forward right backward
  Serial.println("Left Forward Right Backward");
  turnRightMotorBackward(speed);
  turnLeftMotorForward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();
  
  //right forward left backard
  Serial.println("Right Forward Left Backward");
  turnRightMotorForward(speed);
  turnLeftMotorBackward(speed);
  delay(longDelay); // let run for a moment
  Serial.println("Stop");
  stopLeftMotor();
  stopRightMotor();
  delay(shortDelay);

  Serial.println();

  Serial.println("simultaneous operation test complete, pausing");
  delay(pauseDelay);
  Serial.println("begin motor operation interference test");

  //start both forward
  Serial.println("start both forward");
  turnRightMotorForward(speed);
  turnLeftMotorForward(speed);
  delay(longDelay);

  //reverse left and return
  Serial.println("reverse left");
  stopLeftMotor();
  delay(shortDelay);
  turnLeftMotorBackward(speed);
  delay(longDelay);
  stopLeftMotor();
  delay(shortDelay);
  turnLeftMotorForward(speed);
  
  delay(pauseDelay);
  
  //reverse right and return
  Serial.println("reverse right");
  stopRightMotor();
  delay(shortDelay);
  turnRightMotorBackward(speed);
  delay(longDelay);
  stopRightMotor();
  delay(shortDelay);
  turnRightMotorForward(speed);

  delay(pauseDelay);

  Serial.println("stop all");
  stopLeftMotor();
  stopRightMotor();
  
  Serial.println("all testing complete, halt.");
  halt();
}

