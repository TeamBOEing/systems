/* 
 *  LED Test Software
 *  Author: Corbin Murrow, Cody Crossley
 *  Date: 28 September 2015
 *  Version: 1.3
 *  
 *  This software does turns a red and green LED 
 *  on that are connected to physical pins 18 and 19 
 *  (digital output 12 and 13). Also outputs to the serial
 *  monitor when the LEDs turn on or off.
 *  
 *  ====== VERSION HISTORY ======
 *  Version 1.3: Updated consts to defines for pin #s - CM - 28 September 2015
 *  Version 1.2: Included use of constants and updated pin number - CC - 28 September 2015
 *  Version 1.1: Updated file header - CM - 25 September 2015
 *  Version 1.0: Created project - CM - 20 September 2015
 */

#define LED_PIN_GREEN 7
#define LED_PIN_RED 8
#define BAUD_RATE 115200

const int BLINK_SPEED = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(BAUD_RATE);
  // initialize digital pins for Red and Green LEDs as outputs
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(LED_PIN_RED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN_GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Green On");
  delay(BLINK_SPEED);              // wait for a second
  digitalWrite(LED_PIN_GREEN, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("Green Off");
  delay(BLINK_SPEED);              // wait for a second

  // Perform same as above with the red LED
  digitalWrite(LED_PIN_RED, HIGH);
  Serial.println("Red On");
  delay(BLINK_SPEED);
  digitalWrite(LED_PIN_RED, LOW);
  Serial.println("Red Off");
  delay(BLINK_SPEED);
}
