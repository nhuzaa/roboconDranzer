

#define ENL 12
#define ENR  13

#define ML1  4 //IN 1
#define ML2  5 // IN 2

#define MR1 3 // IN 3
#define MR2 2  // IN 4


#define tuinEN 8 // 5 , 6
#define tuinFrontA 36 // 7
#define tuinFrontB 34 // 8

#define tuinBackA 32 // 4
#define tuinBackB 30 // 9



#define servoPinBase  11

#define servoPinA  10
#define servoPinB  9


#include "motorDriver.h"

#include "servoExtend.h"

#include "tuin.h"




servoExtend servoBase, servoA, servoB;
tuin tuinMotor;

motorDriver motor;
servoExtend s ;

void setup()
{
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  Serial.begin(115200);
  Serial.println("Ready"); // print "Ready" once
  servoBase.setter(servoPinBase, 30 , 150 , 30 ); servoA.setter(servoPinA , 90 , 180 , 90 ); servoB.setter(servoPinB , 1 , 90 , 90 ) ; // A is base then moving up D is the hand

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
      case 't':
        servoBase.increasePos();
        Serial.write(servoA.getPos());
        break;
      case 'g':
        servoBase.decreasePos();
        Serial.write(servoA.getPos());
        break;
      case 'y':
        servoA.increasePos();
        servoB.decreasePos();
        break;
      case 'h':
        servoA.decreasePos();
        servoB.increasePos();
        break;
      case 'u':
        tuinMotor.grab();
        break;
      case 'j':
        tuinMotor.drop();
        break;
      case 'n':
        tuinMotor.brake();
        break;


    }

//    Serial.print( " ServoBase: " );
//    Serial.print( servoBase.getPos());
//
//    Serial.print( "## servoA: " );
//    Serial.print( servoA.getPos());
//
//    Serial.print( "## servoB: " );
//    Serial.println( servoB.getPos());

  }
}
