#include "EEPROM.h"

// for light blinking
// 13 for Teensy 3.2, Uno/Nano/Mega, ESP32, M0 Feather BLE
// 0 for ESP-12 Feather
const byte led = 13; 
unsigned long previousMillis = 0;
unsigned long interval = 100;
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);     
  digitalWrite(led, HIGH);
  float tempValue = 12.34;

  //EEPROM.begin(1024); // only for ESP-12 and ESP32
  EEPROM.put(0, tempValue); // not supported on esp32
  //EEPROM.writeFloat(0, tempValue);  // ESP32 only
  //EEPROM.commit(); // only for ESP-12 and ESP32
}

void loop() {
  float bankValue = 00.00;
  if (Serial.read() == '!') {
      Serial.print("Bank Value Before: ");
      Serial.println(bankValue);
      EEPROM.get(0,bankValue);   // not supported on esp32
      //bankValue = EEPROM.readFloat(0); // only for ESP32
      Serial.print("Bank Value After: ");
      Serial.println(bankValue);
  }
  
  // something to do in loop():
  if (millis() - previousMillis > interval) {
    previousMillis = millis();
    ledState = !ledState;
    digitalWrite(led, ledState);
  }

}

/*  Arduino EEPROM get / put float example
 *  Demonstrates how to use the Arduino library's .get() and .put() functions to save any value to EEPROM.
 *  
 *  As of writing, the ESP32 does not support these functions, but does have an alternative.
 *  SAM21D / Cortex / M0 based boards do not support EEPROM at all.
 *  
 *  Code is setup for AVR or Teensy boards, uncomment and change led variable for ESP12 and 32 boards. Send the '!' character over serial to see the value read from EEPROM.
 *  
 *  The blinking LED is just an indicator to let you know if the board has been programmed successfully.
 *
 *  Written by James Lewis
 *  @baldengineer.com
 *  email | www | twitter
 *  2018-06-18
 */
