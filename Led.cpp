#include "Arduino.h"
#include "Led.h"
#include "Debug.h"
const boolean DEBUG=false;

Led::Led(int pin, String name)
{
  _pin=pin;
  _name = name;
     
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
  
  if(_start > 0 && _duration >0) {
    long endTime = _duration+_start;
    if(currentTime >= (endTime) ) {//stops
     debug("led "+_name+" -  time to stop");  
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
      debug("led "+_name+" -  time to blink");  
    } else {
      debug("led "+_name+" -  nothing to do");  
    }

  }

}
/**
 * DEBUG MESSAGE
 */
void Led::debug(String message) {
  Debug::println(message);
}
