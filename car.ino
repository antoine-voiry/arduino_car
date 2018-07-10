#include <SoftwareSerial.h>
#include "Annunicator.h"
#include "Bluetooth.h"


const String GREEN_LIGHT_ON="GREEN_LIGHT_ON";
const String GREEN_LIGHT_OFF="GREEN_LIGHT_OFF";
const String MACUMBA="MACUMBA";
const int RX_PIN = 9;
const int TX_PIN = 10;
const int BT_BAUD_RATE= 115200;
const int SERIAL_BAUD_RATE= 115200;


SoftwareSerial btSerial(RX_PIN, TX_PIN); // RX, TX

Annunicator myAnnunicator; //
boolean initLed = false;


void setup() 
{

  // Open serial communications and wait for port to open:
  Serial.begin(SERIAL_BAUD_RATE);
  btSerial.begin(BT_BAUD_RATE);
  Serial.println("Ready!");
  myAnnunicator.init();
   
}

void loop()
{
  if(initLed != true) {
    delay(100);
    Serial.print("Init " );
    long time=millis();
    Serial.println(time);
    initLed = true;
    myAnnunicator.flashRedLed(10000,5);
  }

  myAnnunicator.checkLedStatus();
  
}// END loop()




  /*
  String messageFromBT=readFromBT();
  if(messageFromBT.length()>0) {
    interpretBTCommand(messageFromBT); 
  }



void interpretBTCommand(String command) {

  if(command!= "") {
    if(command.equals(GREEN_LIGHT_ON)) {
      sendtoBT(GREEN_LIGHT_ON);
      //digitalWrite(led_green,HIGH); 
      
    }else if(command.equals(GREEN_LIGHT_OFF)) {
        sendtoBT(GREEN_LIGHT_OFF);
        //digitalWrite(led_green,LOW); 
    }else if(command.equals(MACUMBA)) {
        sendtoBT(MACUMBA);
       // myAnnunicator.macumba();
        
    }else {
      Serial.println("command unknown");
    }
  }
  
  
}
  */



