#include "Arduino.h"
#ifndef Bluetooth_H
#define Bluetooth_H
const int RX_PIN = 9;
const int TX_PIN = 10;
const int BT_BAUD_RATE= 115200;


const String GREEN_LIGHT_ON="GREEN_LIGHT_ON";
const String GREEN_LIGHT_OFF="GREEN_LIGHT_OFF";
const String MACUMBA="MACUMBA";

class Bluetooth
{

  public:
    Bluetooth();
    String readFromBT();
    void sendtoBT(String command) ;
    

};
#endif
