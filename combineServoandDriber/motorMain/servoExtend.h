
#include <Arduino.h>


class servoExtend
{

private:
  int pos;
  int minPos, maxPos;
  Servo myservo;

public:
  void  setter(int a, int x , int y , int pos_init = 90 )
  {
    myservo.attach(a);
    pos = pos_init;
    minPos = x;
    maxPos = y ;
    myservo.write(pos);
  }
  void increasePos()
  {
    if (pos <= maxPos)
    {
      while(Serial.read() != 'f')
      {
        pos = pos +2 ;

        myservo.write(pos);
      }
      //delay(5);
    }
    else
    {
      pos = maxPos;
    }
    myservo.write(pos);
  }
  void decreasePos()
  {
    if (pos >= minPos )
    {
      while(Serial.read() != 'f')
      {
        pos = pos -2 ;
        myservo.write(pos);
        //delay(5);
      }
    }
    else
    {
      pos = minPos;
    }
    myservo.write(pos);
  }
  int getPos()
  {
    return pos;
  }
  int setPos(int pos_init)
  {
    // if (pos <= maxPos & pos >= minPos)
    {

      pos = pos_init ;
      myservo.write(pos);
    }
  }

};






