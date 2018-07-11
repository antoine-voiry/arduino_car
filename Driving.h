#include "Arduino.h"
#ifndef Driving_H
#define Driving_H

/*
A class to handle the led of the Annunicator
*/

class Driving
{
  public:    
    Driving();// constructor
    void front(int speed);
    void rear(int speed);
  private:

};

#endif
