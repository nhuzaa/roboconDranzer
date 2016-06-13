import pygame
import serial
import signal
import sys
import threading
import io

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=0.05)
sio = io.TextIOWrapper(io.BufferedRWPair(ser, ser))

def printsioSerial():
    sio.flush()
    data = sio.readline()  # the last bit gets rid of the new-line chars
    if data:
        print (data)

def joystickControl(joy):
    while True:
        buttons = joy.get_numbuttons()
        event = pygame.event.wait()
        if event.type == pygame.JOYBUTTONDOWN:
            for i in range(buttons):
                button = joy.get_button(i)
                print( "Button {:>2} value: {}".format(i, button))

def motionControl(joy):
    while True:
        axes = joy.get_numaxes()
        event = pygame.event.wait()
        if event.type == pygame.JOYAXISMOTION:

            if  joy.get_axis(3) <0 :
                print("forward")
                sio.write(unicode('w'))
            if joy.get_axis(3)  > 0:
                print("reverse")
                sio.write(unicode('s'))
            if joy.get_axis(0)  < 0 :
                print ("left")
                sio.write(unicode('a'))
            if joy.get_axis(0) > 0:
                print("right")
                sio.write(unicode('d'))


            printsioSerial()




def main():
    pygame.joystick.init()
    pygame.display.init()
    if not pygame.joystick.get_count():
        print "\nPlease connect a joystick and run again.\n"
        quit()
    print "\n%d joystick(s) detected." % pygame.joystick.get_count()
    joy = pygame.joystick.Joystick(0)
    joy.init()

    print "Ready for Action\n"

    motionControl(joy)

if __name__ == "__main__":
    main()