/*
    A class to handle debug in a central place
*/
#include <Arduino.h>
#include "Debug.h"



/*
Constructor
Init the serial port


Debug::Debug() {
   
}*/

/*
start
*/
void Debug::start() {
      // Open serial communications and wait for port to open:
    Serial.begin(SERIAL_BAUD_RATE);
}

/*
Send a message to Debug
*/
void Debug::println(String logMessage) {

        Serial.println(logMessage);
}


