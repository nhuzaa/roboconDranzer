
#include <Arduino.h>
#include <Servo.h>

class servoExtend
{

  private:
    int pos;
    int speedRight;
    Servo myservo;

  public:
    servoExtend(int a, int pos_init = 90 )
    {
      myservo.attach(a);
      pos = pos_init;
    }
    void increasePos()
    {
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }
    void decreasePos()
    {
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
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

