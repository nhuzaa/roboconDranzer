/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include "servoExtend.h"
#define servoPinBase  11

#define servoPinA  10
#define servoPinB  9




servoExtend servoBase, servoA, servoB;



// variable to store the servo position

void setup() {
  Serial.begin(115200);
  servoBase.setter(servoPinBase, 30 , 150 , 30 ); servoA.setter(servoPinA , 90 , 180 , 90 ); servoB.setter(servoPinB , 1 , 90 , 90 ) ; // A is base then moving up D is the hand
  
}

void keyControl() {

  if (Serial.available()) {
    char c = Serial.read();
    Serial.println(c);
    Serial.write(c);
    switch (c)
    {

      case 'q':
        servoBase.increasePos();
        Serial.write(servoA.getPos());
        break;
      case 'a':
        servoBase.decreasePos();
        Serial.write(servoA.getPos());
        break;
      case 'w':
        servoA.increasePos();
        servoB.decreasePos();
        break;
      case 's':
        servoA.decreasePos();
        servoB.increasePos();
        break;
    }

    Serial.print( " ServoBase: " );
    Serial.print( servoBase.getPos());

    Serial.print( "## servoA: " );
    Serial.print( servoA.getPos());

    Serial.print( "## servoB: " );
    Serial.println( servoB.getPos());


  }
 
}

void loop() {

keyControl();

}

