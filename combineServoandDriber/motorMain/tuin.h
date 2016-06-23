
#include <Arduino.h>


class tuin
{

  public:
    int speedTuin;

  public:
    tuin()
    {
      speedTuin = 150;
      analogWrite(tuinEN, speedTuin);
    }

    void brake() // 000
    {

      digitalWrite(tuinFrontA, 0);
      digitalWrite(tuinFrontB, 0);
      digitalWrite(tuinBackA, 0);
      digitalWrite(tuinBackB, 0);
      Serial.println("Brake tuin");
    }

    void discBrake() // 001
    {
      digitalWrite(tuinFrontA, 1);
      digitalWrite(tuinFrontB, 1);
      digitalWrite(tuinBackA, 1);
      digitalWrite(tuinBackB, 1);
      Serial.println("Disc Brake tuin");
    }

    void grab() // 010
    {

      digitalWrite(ML1, 1);
      digitalWrite(ML2, 0);
      digitalWrite(MR1, 0);
      digitalWrite(MR2, 1);
      Serial.println("Tuin grab ");

    }

    void drop() // 011
    {
      digitalWrite(ML1, 0);
      digitalWrite(ML2, 1);
      digitalWrite(MR1, 1);
      digitalWrite(MR2, 0);
      Serial.println("Tuin Realease");
    }



};
