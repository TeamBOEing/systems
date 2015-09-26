/*
 * Speaker Test
 * Author: Corbin Murrow
 * Date: 26 September 2015
 * Version: 1.1
 * 
 * This software will output multiple tones via an analog output 
 * pin from the ATmega microprocessor. This test is necessary to
 * verify that the final requirement of the BOEbot project
 * can be fulfilled.
 * 
 * ======= VERSION HISTORY =======
 * Version 1.1: Played C Major Scale - CM - 26 September 2015
 * Version 1.0: Created file and header - CM - 25 September 2015
 */

#define SPEAKERPIN 17

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Play a scale!\n");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println("Speaker on.");
  tone(SPEAKERPIN, 262, 500); //C4
  delay(500);
  tone(SPEAKERPIN, 294, 500); //D4
  delay(500);
  tone(SPEAKERPIN, 330, 500); //E4
  delay(500);
  tone(SPEAKERPIN, 349, 500); //F4
  delay(500);
  tone(SPEAKERPIN, 392, 500); //G4
  delay(500);
  tone(SPEAKERPIN, 440, 500); //A4
  delay(500);
  tone(SPEAKERPIN, 494, 500); //B4
  delay(500);
  tone(SPEAKERPIN, 523, 500); //C4
  delay(500);
  Serial.println("Speaker off.");

  delay(5000);
}
