
#include <Arduino.h>
#include <Servo.h>

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
    }
    void increasePos()
    {
      if (pos >= minPos & pos <= maxPos)
      {
        pos++;

        myservo.write(pos);
        delay(15);
      }
      myservo.write(pos);
    }
    void decreasePos()
    {
      if (pos <= minPos & pos >= maxPos)
      {
        pos--;
        myservo.write(pos);
        delay(15);
      }
       myservo.write(pos);
    }
    int getPos()
    {
      return pos;
    }
    int setpos(int pos_init)
    {
      pos = pos_init;
      myservo.write(pos);
    }

};

