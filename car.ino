#include <SoftwareSerial.h>
#define DEBUG_ENABLE 1
#include "Annunicator.h"
#include "Bluetooth.h"
#include "Debug.h"
#include "Driving.h"





//SoftwareSerial btSerial(RX_PIN, TX_PIN); // RX, TX

Annunicator myAnnunicator; //
Driving driving;
int i=0;

void setup() 
{
   Debug::start();
   Debug::println("Ready!");

  
  //btSerial.begin(BT_BAUD_RATE);
  randomSeed(analogRead(0));
  
  myAnnunicator.init();

   
}

void loop()
{
  delay(100);
  int leddNumber = random(0, 5);
  int duration =random(1000, 5000);
  int flashDuration =random(15, 200);
  
  if (i==0) {
    driving.front(250);
    i++;
  }

  switch (leddNumber) {
    case 0:
      // statements
      myAnnunicator.flashRedLed(duration,flashDuration);
      break;
    case 1:
      // statements
      myAnnunicator.flashBlueLed(duration,flashDuration);
      break;
    case 2:
      // statements
      myAnnunicator.flashWhitedLed(duration,flashDuration);
      break;    
    case 3:
      // statements
      myAnnunicator.flashGreenLed(duration,flashDuration);
      break;        
    default:
      break;
      // statements
    }
  myAnnunicator.checkLedStatus();
  /*if (i==50) {
    driving.rear(250);
    i++
  }*/

  
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



