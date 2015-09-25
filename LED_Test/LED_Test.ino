/* 
 *  LED Test Software
 *  Author: Corbin Murrow
 *  Date: 25 September 2015
 *  Version: 1.1
 *  
 *  This software does turns a red and green LED 
 *  on that are connected to physical pins 18 and 19 
 *  (digital output 12 and 13). Also outputs to the serial
 *  monitor when the LEDs turn on or off.
 *  
 *  ====== VERSION HISTORY ======
 *  Version 1.1: Updated file header - CM - 25 September 2015
 *  Version 1.0: Created project - CM - 20 September 2015
 */

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("Green On");
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  Serial.println("Green Off");
  delay(1000);              // wait for a second
  
  digitalWrite(12, HIGH);
  Serial.println("Red On");
  delay(1000);
  digitalWrite(12, LOW);
  Serial.println("Red Off");
  delay(1000);
}
