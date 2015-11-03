/*
 * Speaker Test
 * Author: Corbin Murrow, Cody Crossley
 * Date: 03 November 2015
 * Version: 1.3
 * 
 * This software will output multiple tones via an analog output 
 * pin from the ATmega microprocessor. This test is necessary to
 * verify that the final requirement of the BOEbot project
 * can be fulfilled.
 * 
 * ======= VERSION HISTORY =======
 * Version 1.3: Updated to use BOEbot library rev 1.0 - CC - 03 November 2015
 * Version 1.2: Added TONE_LENGTH, improved comments - CC - 28 September 2015
 * Version 1.1: Played C Major Scale - CM - 26 September 2015
 * Version 1.0: Created file and header - CM - 25 September 2015
 */

#include <Servo.h>
#include "BOEbot.h"

#define TONE_LENGTH 500     // TONE_LENGTH ms for each freqency

void setup() 
{
  initialize();
  Serial.println("Play a scale!\n");
}

void loop() 
{
  // playSound uses (frequency, time) format
  Serial.println("Speaker on.");
  
  playSound(262, TONE_LENGTH); // C4
  delay(TONE_LENGTH);
  playSound(294, TONE_LENGTH); // D4
  delay(TONE_LENGTH);
  playSound(330, TONE_LENGTH); // E4
  delay(TONE_LENGTH);
  playSound(349, TONE_LENGTH); // F4
  delay(TONE_LENGTH);
  playSound(392, TONE_LENGTH); // G4
  delay(TONE_LENGTH);
  playSound(440, TONE_LENGTH); // A4
  delay(TONE_LENGTH);
  playSound(494, TONE_LENGTH); // B4
  delay(TONE_LENGTH);
  playSound(523, TONE_LENGTH); // C4
  delay(TONE_LENGTH);
  
  Serial.println("Speaker off.");

  delay(5000);
}
