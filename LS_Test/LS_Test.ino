/*
 * Light Sensor Test
 * Author: Corbin Murrow, Adam Clothier
 * Date: 30 September 2015
 * Version: 1.1
 * 
 * This software will test the photoresistors by reading the
 * value from an analog input pin and printing the value to the
 * serial monitor in the format "<Left/Right> Light: <value>".
 * 
 * ======= VERSION HISTORY =======
 * Version 1.1: Wrote code for LS test, verified using only Serial Monitor - AC - 29 September 2015
 * Version 1.0: Created file and added header - CM - 25 September 2015
 */

int LDRL = 5;
int LDRR = 4;
void setup()
{
    Serial.begin(115200);  //Begin serial communcation
    pinMode( 7, OUTPUT );
    pinMode( LDRL, INPUT);
    pinMode( LDRR, INPUT);
}

 void loop() {
   int v = analogRead(LDRL);
   int w = analogRead(LDRR);
   Serial.print("Left Photo-Resistor: ");
   Serial.println(v);
   Serial.print("Right Photo-Resistor: ");
   Serial.println(w);
   delay(1000);
 }
