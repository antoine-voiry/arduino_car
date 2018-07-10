#include "Arduino.h"
#include "Led.h"


Led::Led(int pin)
{
  _pin=pin;
  
    
}

/*
Init led
*/
void Led::init() {
  pinMode(_pin,OUTPUT);
}

/*
flash
*/
void Led::flash(int duration, int flashDuration) {
  if(duration >0 && flashDuration >0 ) {
    _start=millis();
    _next_check=_start+ flashDuration;
    _duration = duration;
    _flashDuration = flashDuration;
    _status = true;

    digitalWrite(_pin,HIGH); 
  }
}

void Led::checkLedStatus() {
  long currentTime = millis();
  
  if(_start >= 0 && _duration >=0) {
    long endTime = _duration+_start;
    if(currentTime >= (endTime) ) {//stops
      Serial.println("-  time to stop");  
      digitalWrite(_pin,LOW); 
      _start=0;
      _next_check=0;
      _duration = 0;
      _flashDuration = 0;
      _status = false;

    }else if(currentTime >= (_next_check) ) {//invert
      
      if(_status) {
        digitalWrite(_pin,LOW); 
        _status = false;
      }else {
        digitalWrite(_pin,HIGH); 
        _status = true;
      }
      _next_check=currentTime + _flashDuration;
      Serial.println(" - time to blink");
    } else {
      Serial.println(" - nothing to do ");

    }

  }else {
    Serial.println(" - led is not started");
  }

}
