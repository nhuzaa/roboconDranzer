
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

    void brake() // 000 
    {
      
        digitalWrite(ML1, 0);
        digitalWrite(ML2, 0);
        digitalWrite(MR1, 0);
        digitalWrite(MR2, 0);
        Serial.println("/n Brake");
    }

    void discBrake() // 001 
    {
      digitalWrite(ML1, 1);
      digitalWrite(ML2, 1);
      digitalWrite(MR1, 1);
      digitalWrite(MR2, 1);
      Serial.println("/n Disc Brake");
    }
    
    void forward() // 010
    {
     
        digitalWrite(ML1, 1);
        digitalWrite(ML2, 0);
        digitalWrite(MR1, 1);
        digitalWrite(MR2, 0);
        Serial.println("/n Forward");
      
    }

    void reverse() // 011
    {
        digitalWrite(ML1, 0);
        digitalWrite(ML2, 1);
        digitalWrite(MR1, 0);
        digitalWrite(MR2, 1);
        Serial.println("/n Reverse");
    }
    
    void left()  // 100
    {
        digitalWrite(ML1, 0);
        digitalWrite(ML2, 0);
        digitalWrite(MR1, 1);
        digitalWrite(MR2, 0);
        Serial.println("/n Left");
    }

    void hardLeft() // 101
    {
        digitalWrite(ML1, 0);
        digitalWrite(ML2, 1);
        digitalWrite(MR1, 1);
        digitalWrite(MR2, 0);
        Serial.println("/n Hard Left");
    }

    void right()
    {
        digitalWrite(ML1, 1);
        digitalWrite(ML2, 0);
        digitalWrite(MR1, 0);
        digitalWrite(MR2, 0);
        Serial.println("/n Right");
    }

    void hardRight()
    {
        digitalWrite(ML1, 1);
        digitalWrite(ML2, 0);
        digitalWrite(MR1, 0);
        digitalWrite(MR2, 1);
        Serial.println("/n Hard Right");
    }

};

