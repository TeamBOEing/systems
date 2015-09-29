/*
 * IR Test
 * Author: Corbin Murrow, Cody Crossley
 * Date: 28 September 2015
 * Version: 1.1
 * 
 * This software will test the left and right IR sensors. The 
 * softwre will check each sensor every half second and when
 * a sensor detects something it will print out to the serial
 * monitor: "<Left/Right> IR: 1".
 * 
 * ======= VERSION HISTORY =======
 * Version 1.1:  - CC - 28 September 2015
 * Version 1.0: Created file, added header - CM - 25 September 2015
 */

#include <Servo.h>

#define IR_PIN_LEFT_SEND 10
#define IR_PIN_RIGHT_SEND 9
#define IR_PIN_LEFT_RECEIVE 13
#define IR_PIN_RIGHT_RECEIVE 12

#define LED_PIN_GREEN 7
#define LED_PIN_RED 8

#define BAUD_RATE 115200
#define IR_SEND_FREQ 26
#define IR_DELAY_TIME 1
#define LOOP_DELAY_TIME 1000

Servo irSendLeft;
Servo irSendRight;

void setup() {
  // Set up IR
  irSendLeft.attach(IR_PIN_LEFT_SEND);    // Pin 10 is where left IR is attached
  irSendRight.attach(IR_PIN_RIGHT_SEND);  // Pin 9 is where right IR is attached
  
  Serial.begin(BAUD_RATE);
  //pinMode(IR_PIN_RIGHT_SEND, OUTPUT);     // Send IR signals to be picked up be receivers
  //pinMode(IR_PIN_LEFT_SEND, OUTPUT);   
  pinMode(IR_PIN_RIGHT_RECEIVE, INPUT);   // Read input from the IR sensors
  pinMode(IR_PIN_LEFT_RECEIVE, INPUT);    

}

bool leftIrDetected, rightIrDetected;

void loop() {
  // Send out IR signals
  Serial.print("Sending IR\t");

  irSendLeft.writeMicroseconds(IR_SEND_FREQ);
  //delay(IR_DELAY_TIME);
  leftIrDetected = digitalRead(IR_PIN_LEFT_RECEIVE);
  irSendRight.writeMicroseconds(IR_SEND_FREQ);
  //delay(IR_DELAY_TIME);
  rightIrDetected = digitalRead(IR_PIN_RIGHT_RECEIVE);
  
  // Detect IR signals bouncing off objects
  Serial.print("Left IR: ");
  
  // If IR sensor detects object, the reading will be HIGH
  if ( !leftIrDetected ) {
    digitalWrite(LED_PIN_GREEN, HIGH);        // Turn green LED on if detected
    Serial.print("1");
  }
  else {
    digitalWrite(LED_PIN_GREEN, LOW);         // Turn green LED off if not detected
    Serial.print("0");
  }
  
  Serial.print("\tRight IR: ");
  if ( !rightIrDetected ) {
    digitalWrite(LED_PIN_RED, HIGH);        // Turn red LED on if detected
    Serial.println("1");
  }
  else {
    digitalWrite(LED_PIN_RED, LOW);         // Turn red LED off if not detected
    Serial.println("0");
  }
  
  delay(LOOP_DELAY_TIME);
}
