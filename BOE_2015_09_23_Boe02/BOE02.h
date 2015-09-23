// Team BOEing
// Cody Crossley
// 23 Sept. 2015

#ifndef BOE02_h
#define BOE02_h

//#include <Time.h>
#include "Arduino.h"

#define pinLedR        13        // pin for red LED
#define pinLedG        14         // pin for green LED
#define pinLeftMotor   10   // pin for left motor
#define pinRightMotor  11   // pin for right motor

const int TEST_MOTOR_POWER = 200;
const int SECOND = 1000;

void setPinHigh(byte pin);
void setPinLow(byte pin);
void pulsePinHigh(byte pin, int milliseconds); // Turn on pin, then turn it off after milliseconds
void pulsePinLow(byte pin, int milliseconds);  // Turn off pin, then turn it on after milliseconds

// ***********************************************
int turnLeftForw(int);
int turnLeftBack(int);
int turnRightForw(int);
int turnRightBack(int);

int testMotors();
int testLightSensors();
int testInfaredSensors();

#endif
