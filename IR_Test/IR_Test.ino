/*
 * IR Test
 * Author: Corbin Murrow, Cody Crossley
 * Date: 30 September 2015
 * Version: 1.2
 * 
 * This software will test the left and right IR sensors. The 
 * softwre will check each sensor every half second and when
 * a sensor detects something it will print out to the serial
 * monitor: "<Left/Right> IR: 1".
 * 
 * ======= VERSION HISTORY =======
 * Version 1.2: Tone works to continuously send signal - CM & CC - 30 September 2015
 * Version 1.1: Attempted to use Servo.h, regular PWM, etc. but unsuccessful - CC - 28 September 2015
 * Version 1.0: Created file, added header - CM - 25 September 2015
 */

#define IR_PIN_SEND 9             // PWM 38.5kHz signal to two IR LEDs
#define IR_PIN_LEFT_RECEIVE 13    // IR receiver on left side of BOEbot
#define IR_PIN_RIGHT_RECEIVE 12   // IR receiver on right side of BOEbot

#define LED_PIN_GREEN 7           // Lights up when object detected on left side
#define LED_PIN_RED 8             // Lights up when object detected on right side

#define BAUD_RATE 115200          // Speed which Serial monitor transmits
#define IR_SEND_FREQ 38500        // Hz signal of IR LEDs
#define LOOP_DELAY_TIME 1000      // Wait 1 second between object detections

void setup() {
  Serial.begin(BAUD_RATE);        // Set up Serial monitor

  // Set up user feedback LEDs as output
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(LED_PIN_RED, OUTPUT);

  // Set up IR receivers as input pins
  pinMode(IR_PIN_RIGHT_RECEIVE, INPUT);
  pinMode(IR_PIN_LEFT_RECEIVE, INPUT);

  // Send out IR signals continuously
  Serial.println("Sending IR continuously\n");
  delay(5);
  tone(IR_PIN_SEND, IR_SEND_FREQ);
}

bool leftIrDetected, rightIrDetected;   // HIGH when object is detected

void loop() {
  // Capture reflected signals (LOW when object detected,
  // so inverse of reading gives boolean value wanted)
  leftIrDetected = !digitalRead(IR_PIN_LEFT_RECEIVE);
  rightIrDetected = !digitalRead(IR_PIN_RIGHT_RECEIVE);

  // Detect IR signals bouncing off objects
  Serial.print("Left IR: ");
  
  // If IR sensor detects object, the boolean will be HIGH
  if ( leftIrDetected ) {
    digitalWrite(LED_PIN_GREEN, HIGH);      // Turn green LED on if detected
    Serial.print("1");
  }
  else {
    digitalWrite(LED_PIN_GREEN, LOW);       // Turn green LED off if not detected
    Serial.print("0");
  }

  // If IR sensor detects object, the boolean will be HIGH
  Serial.print("\tRight IR: ");
  if ( rightIrDetected ) {
    digitalWrite(LED_PIN_RED, HIGH);        // Turn red LED on if detected
    Serial.println("1");
  }
  else {
    digitalWrite(LED_PIN_RED, LOW);         // Turn red LED off if not detected
    Serial.println("0");
  }
  
  delay(LOOP_DELAY_TIME);
}
