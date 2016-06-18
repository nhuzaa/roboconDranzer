/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include "servoExtend.h"
#define servoPinA  7
#define servoPinB  3

#define servoPinC  4
#define servoPinD  5


servoExtend servoA(servoPinA), servoB(servoPinB), servoC(servoPinC) , servoD(servoPinD); // A is base then moving up D is the hand




// variable to store the servo position

void setup() {

}

void keyControl() {

  if (Serial.available()) {
    char c = Serial.read();
    Serial.println(c);
    Serial.write(c);
    switch (c)
    {

      case 'q':
        servoA.increasePos();
        Serial.write(servoA.getPos());
        break;
      case 'a':
        servoA.decreasePos();
        Serial.write(servoA.getPos());
        break;
      case 'w':
        servoB.increasePos();
        break;
      case 's':
        servoB.decreasePos();
        break;
      case 'e':
        servoC.increasePos();
        break;
      case 'd':
        servoC.decreasePos();
        break;
      case 'r':
        servoD.increasePos();
        break;
      case 'f':
        servoD.decreasePos();
        break;
    }

  }
}
void loop() {


  void keyControl();
}

