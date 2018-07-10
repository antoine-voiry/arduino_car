#include "Bluetooth.h"



Bluetooth::Bluetooth(){

}

/*
Init led
*/
String Bluetooth::readFromBT() {
 String message = "";
  
 /* 
  if (btSerial.available()>0) {
     while(btSerial.available()>0) { // While there is more to be read, keep reading.
       message  += (char)btSerial.read();
     }
     message.trim();
     message.toUpperCase();
     Serial.print("received :");
     Serial.println(message );
   }*/
   return message;

}

void Bluetooth::sendtoBT(String command) {
    /*
  btSerial.print("playing ");
  btSerial.println(command);
  */
}



/*
void readAndSendFromBT   () {
     // Read device output if available.
   if (btSerial.available()) {
     //Serial.println("Something received from BT!");
     while(btSerial.available()) { // While there is more to be read, keep reading.
       command += (char)btSerial.read();
     }
     Serial.println(command);
     command = ""; // No repeats
   }
  
   // Read user input if available.
   if (Serial.available()){
       delay(10); // The DELAY!
       btSerial.write(Serial.read());
       Serial.println("Something sent to BT!");
   }
}*/
