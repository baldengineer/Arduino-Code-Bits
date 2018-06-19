#EEPROM-get-put
Arduino EEPROM get / put float example

Demonstrates how to use the Arduino library's .get() and .put() functions to save any value to EEPROM.
   
As of writing, the ESP32 does not support these functions, but does have an alternative. SAM21D / Cortex / M0 based boards do not support EEPROM at all.
   
 Code is setup for AVR or Teensy boards, uncomment and change led variable for ESP12 and 32 boards. Send the '!' character over serial to see the value read from EEPROM.
   
The blinking LED is just an indicator to let you know if the board has been programmed successfully.

More information at: https://www.baldengineer.com/arduino-eeprom-stores-any-datatype.html