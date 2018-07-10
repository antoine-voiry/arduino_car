#include "Arduino.h"
#include "Annunicator.h"


Annunicator::Annunicator()
{
  
  pinMode(led_red,OUTPUT);
  pinMode(led_white,OUTPUT);
  pinMode(led_blue,OUTPUT);
  pinMode(led_green,OUTPUT);
  
}

/*
Init led
*/
void Annunicator::initled() {
}


void Annunicator::flashRedLed(int duration, int flashDuration) {
  if(duration >0 && flashDuration >0 ) {
    _led_red_start=millis();
    _led_red_next_check=_led_red_start+ flashDuration;
    _led_red_duration = duration;
    _led_red_flashDuration = flashDuration;
    _led_red_status = true;

    digitalWrite(led_red,HIGH); 
  }
}

void Annunicator::checkLedStatus(Print  &print ) {
  long currentTime = millis();
  
  if(_led_red_start >= 0 && _led_red_duration >=0) {
    long endTime = _led_red_duration+_led_red_start;
    if(currentTime >= (endTime) ) {//stops
      print.println("-  time to stop");  
      digitalWrite(led_red,LOW); 
      _led_red_start=0;
      _led_red_next_check=0;
      _led_red_duration = 0;
      _led_red_flashDuration = 0;
      _led_red_status = false;

    }else if(currentTime >= (_led_red_next_check) ) {//invert
      
      if(_led_red_status) {
        digitalWrite(led_red,LOW); 
        _led_red_status = false;
      }else {
        digitalWrite(led_red,HIGH); 
        _led_red_status = true;
      }
      _led_red_next_check=currentTime + _led_red_flashDuration;
      print.println(" - time to blink");
    } else {
      print.println(" - nothing to do ");

    }

  }else {
    print.println(" - led is not started");
  }

}
