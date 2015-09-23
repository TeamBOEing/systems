//#include <iostream>
#include "BOE02.h"

const int TEST_TIME = 500;

// ********** Micro Functions **********

bool isPinHigh(byte pin) {
  bool stateIsHigh = false;

  if (digitalRead(pin) == HIGH) 
    stateIsHigh = true;

  return stateIsHigh;
}

void setPinHigh(byte pin) {
  digitalWrite(pin, HIGH);
}

void setPinLow(byte pin) {
  digitalWrite(pin, LOW); 
}

// Turn on pin, then turn it off after milliseconds
void pulsePinHigh(byte pin, int milliSec) {
  setPinHigh(pin);
  Serial.println("Pin " + (String)pin + " ON.");
  
  delay(milliSec);
  
  setPinLow(pin);
  Serial.println("Pin " + (String)pin + " OFF after " + (String)milliSec);
}

// Turn off pin, then turn it on after milliseconds
void pulsePinLow(byte pin, int milliSec) {
  setPinLow(pin);
  Serial.println("Pin " + (String)pin + " OFF.");
  
  delay(milliSec);
  
  setPinHigh(pin);
  Serial.println("Pin " + (String)pin + " ON after " + (String)milliSec);
}

// **********************************************

void leftMotorOff() {
  setPinLow(pinLeftMotor);
}

void rightMotorOff() {
  setPinLow(pinRightMotor);
}

// ********** Basic Functions **********

int turnLeftForw(int power) {


	return 1;
}

int turnLeftBack(int power) {


	return 1;
}

int turnRightForw(int power) {


	return 1;
}

int turnRightBack(int power) {

	/*
	left_servo             CON 15           'left servo pin
	right_servo            CON 13           'right servo pin
	loopnum                CON 100
	speed                  CON 50
	
	x VAR Word
	
	FOR x=1 TO loopnum                      'begin routine
		PULSOUT right_servo, 750-speed
		PULSOUT left_servo, 750+speed
		PAUSE 20                              'pause for 20 ms
	NEXT                                    'continue for loop
	
	STOP                                    'stop until reset
	*/

	return 1;
}

// ********** Test Functions **********

int testMotors() {
	turnLeftForw(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	leftMotorOff();

	turnLeftBack(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	leftMotorOff();

	turnRightForw(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	rightMotorOff();

	turnRightBack(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	rightMotorOff();

	turnLeftForw(TEST_MOTOR_POWER);
	turnRightForw(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	leftMotorOff();
	rightMotorOff();

	turnLeftBack(TEST_MOTOR_POWER);
	turnRightBack(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	leftMotorOff();
	rightMotorOff();

	turnLeftForw(TEST_MOTOR_POWER);
	turnRightBack(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	leftMotorOff();
	rightMotorOff();

	turnLeftBack(TEST_MOTOR_POWER);
	turnRightForw(TEST_MOTOR_POWER);
	delay(TEST_TIME);
	leftMotorOff();
	rightMotorOff();

	return 1;	
}

int testLightSensors() {


	return 1;
}

int testInfaredSensors() {


	return 1;
}
