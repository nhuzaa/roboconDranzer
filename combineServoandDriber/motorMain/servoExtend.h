
#include <Arduino.h>
<<<<<<< HEAD
#include <Servo.h>
=======

>>>>>>> 93ed62edc576656f1e119fbfdbcfd06fdf4c5fef

class servoExtend
{

<<<<<<< HEAD
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
=======
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
>>>>>>> 93ed62edc576656f1e119fbfdbcfd06fdf4c5fef
      {
        pos = pos +2 ;

        myservo.write(pos);
<<<<<<< HEAD
        //delay(5);
      }else
      {
        pos = maxPos;
      }
      myservo.write(pos);
    }
    void decreasePos()
    {
     if (pos >= minPos )
=======
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
>>>>>>> 93ed62edc576656f1e119fbfdbcfd06fdf4c5fef
      {
        pos = pos -2 ;
        myservo.write(pos);
        //delay(5);
<<<<<<< HEAD
      }else
      {
        pos = minPos;
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

=======
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






>>>>>>> 93ed62edc576656f1e119fbfdbcfd06fdf4c5fef
