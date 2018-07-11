#include "Arduino.h"
#ifndef Led_H
#define Led_H

/*
A class to handle the led of the Annunicator
*/

class Led
{
  public:    
    Led(int pin,String name);// constructor
    void init();
    void flash(int duration, int flashDuration);
    void checkLedStatus();
  private:
    long _duration =0;
    long _flashDuration =0;
    long _start =0;
    long _next_check =0;
    boolean _status = false;
    int _pin =0;
    String _name="";
    void debug(String message);
   // Print & _print;
    

};
#endif
