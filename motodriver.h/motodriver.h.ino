
#include <Arduino.h>


class motorDriver
{

  public:
    int speedLeft;
    int speedRight;
  public:
    motorDriver()
    {
      speedLeft = 255;
      speedRight = 255;
      analogWrite(ENL, speedLeft);
      analogWrite(ENR, speedRight);
    }
  public:
    void forward(char m)
    {
     
        digitalWrite(ML1, 1);
        digitalWrite(ML2, 0);
        digitalWrite(MR1, 1);
        digitalWrite(MR2, 0);
      
    }

    void reverse(char m)
    {
        digitalWrite(ML1, 0);
        digitalWrite(ML2, 1);
        digitalWrite(MR1, 0);
        digitalWrite(MR2, 1);
    }
    }


    void brake(char m)
    {
      
        digitalWrite(ML1, 0);
        digitalWrite(ML2, 0);

     
        digitalWrite(MR1, 0);
        digitalWrite(MR2, 0);
 
    }

    void discBrake()
    {
      digitalWrite(ML1, 1);
      digitalWrite(ML2, 1);
      digitalWrite(MR1, 1);
      digitalWrite(MR2, 1);
    }

    void right()
    {

      //hard right
      speedRight = 255 ;
      speedLeft = 255 ;
      analogWrite(ENL, speedLeft);
      analogWrite(ENR, speedRight);
      forwardMotor('L');
      reverseMotor('R');
      //  Serial.println(" Hard right");
    }

    void left()
    {
      //Hard Left
      speedRight = 255 ;
      speedLeft = 255 ;
      analogWrite(ENL, speedLeft);
      analogWrite(ENR, speedRight);
      reverseMotor('L');
      forwardMotor('R');
      // Serial.println("Hard Left");
    }


    void speedSetter()
    {

      analogWrite(ENR, speedRight);
      analogWrite(ENL, speedLeft);
      forwardMotor('L');
      forwardMotor('R');

    }

};

