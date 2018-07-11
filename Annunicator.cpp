#include "Arduino.h"
#include "Annunicator.h"
#include "Led.h"



Annunicator::Annunicator(){
}

/*
Init led
*/
void Annunicator::init() {
  for(int i = 0; i< 4; i++) {
    _leds[i].init();
  }
}
/*
    Led(led_red),
    Led(led_white),
    Led(led_blue),
    Led(led_green),

*/

void Annunicator::flashRedLed(int duration, int flashDuration) {
   _leds[0].flash(duration, flashDuration);
}
void Annunicator::flashWhitedLed(int duration, int flashDuration) {
  _leds[1].flash(duration, flashDuration);
}
void Annunicator::flashBlueLed(int duration, int flashDuration) {
  _leds[2].flash(duration, flashDuration);
}
void Annunicator::flashGreenLed(int duration, int flashDuration) {
  _leds[3].flash(duration, flashDuration);
}


void Annunicator::checkLedStatus() {

    for(int i = 0; i< 4; i++) {
    _leds[i].checkLedStatus();
  }
}
