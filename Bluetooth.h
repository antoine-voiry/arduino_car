#include "Arduino.h"
#ifndef Bluetooth_H
#define Bluetooth_H



class Bluetooth
{

  public:
    Bluetooth();
    String readFromBT();
    void sendtoBT(String command) ;
    

};
#endif
