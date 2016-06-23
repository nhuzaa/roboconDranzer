


#define ENL 12
#define ENR  13

#define ML1  4 //IN 1
#define ML2  5 // IN 2

#define MR1 3 // IN 3
#define MR2 2  // IN 4


#include "motorDriver.h"
motorDriver motor;

void setup()
{
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready"); // print "Ready" once
  
}

void loop()
{

  
  if (Serial.available()) {
    char c = Serial.read();
    Serial.println(c);
    Serial.write(c);
    switch (c)
    {

      case 'w':
        motor.forward();
        break;
      case 's':
        motor.reverse();
        break;
      case 'a':
        motor.hardLeft();
        break;
      case 'd':
        motor.hardRight();
        break;
      case 'f':
        motor.brake();
        break;
    }

  }
}
