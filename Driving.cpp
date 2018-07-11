#include "Arduino.h"
#include "Driving.h"
// motor one
int enA = 5;
int in1 = 4;
int in2 = 7;
// motor two
int enB = 3;
int in3 = 8;
int in4 = 6;


/**
 * Default constructor
 */
Driving::Driving() {
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void Driving::front(int speed)
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
   // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // set speed to 200 out of possible range 0~255 
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  /*delay(2000);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); */
}


void Driving::rear(int speed)
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
   // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // set speed to 200 out of possible range 0~255 
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  delay(2000);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}