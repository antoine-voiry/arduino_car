#include "Arduino.h"
#ifndef Annunicator_H
#define Annunicator_H

const int led_red=A0;//RED
const int led_white=A1;//WHITE
const int led_blue=A2;// BLUE
const int led_green=A3;//GREEN


class Annunicator
{
  public:
    Annunicator();// constructor
    void initled();
    void flashRedLed(int duration, int flashDuration);
    void checkLedStatus(Print  &print);
  private:
    long _led_red_duration =0;
    long _led_red_flashDuration =0;
    long _led_red_start =0;
    long _led_red_next_check =0;
    boolean _led_red_status = false;
    

};
#endif
