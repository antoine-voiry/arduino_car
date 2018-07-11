#include "Arduino.h"
#ifndef Annunicator_H
#define Annunicator_H
#include "Led.h"


const int led_red=A0;//RED
const int led_white=A1;//WHITE
const int led_blue=A2;// BLUE
const int led_green=A3;//GREEN


class Annunicator
{

  public:
    Annunicator();
    void init();
    void flashRedLed(int duration, int flashDuration);
    void flashWhitedLed(int duration, int flashDuration);
    void flashBlueLed(int duration, int flashDuration);
    void flashGreenLed(int duration, int flashDuration);

    
    void checkLedStatus();
  
  private:
    Led _leds[4] = {
      Led(led_red,"RED"),
      Led(led_white,"WHITE"),
      Led(led_blue,"BLUE"),
      Led(led_green,"GREEN")
    };
    

};
#endif
