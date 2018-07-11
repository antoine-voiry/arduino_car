#include "Arduino.h"
#ifndef Debug_H
#define Debug_H

const int SERIAL_BAUD_RATE= 9600;

class Debug
{

  public:
    
    ~Debug();
    static void start();
    static void println(String logMessage);
  
  private:
    

};
#endif
