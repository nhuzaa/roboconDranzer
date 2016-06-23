import pygame
import serial
import signal
import sys
import threading
import io

ser = serial.Serial('/dev/ttyACM0', 19200, timeout=0.05)
sio = io.TextIOWrapper(io.BufferedRWPair(ser, ser))

def printsioSerial(chr):
    sio.write(unicode(chr))
    sio.flush()
    '''
    try:
        data = sio.readline()  # the last bit gets rid of the new-line chars
        if data:
            print('\n')
            print (data)
            print('\n')
    except ValueError:
        print ("no serial data")
    '''
def keyboardControl():
    while True:
        buttons = joy.get_numbuttons()
        event = pygame.event.wait()
        if event.type == pygame.JOYBUTTONDOWN:
            if joy.get_button(0) == 1 :
                print("forward")
                sio.write(unicode('w'))
            if joy.get_button(2) == 1:
                print("reverse")
                sio.write(unicode('s'))
            if joy.get_button(3) == 1:
                print ("left")
                sio.write(unicode('a'))
            if joy.get_button(1) == 1:
                print("right")
                sio.write(unicode('d'))

        if event.type == pygame.JOYBUTTONDOWN:
            sio.write(unicode('f'))


def untilKeyup(event):
    if event.key == pygame.K_q:
        printsioSerial('q')
        
    if event.key == pygame.K_a:
        printsioSerial('a')
        
    if event.key == pygame.K_w:
        printsioSerial('w')
        
    if event.key == pygame.K_s:
        printsioSerial('s')
        
    if event.key == pygame.K_e:
        printsioSerial('e')
        
    if event.key == pygame.K_d:
        printsioSerial('d')
        
    if event.key == pygame.K_r:
        printsioSerial('r')
    if event.key == pygame.K_f:
        printsioSerial('f')
    if event.key == pygame.K_t:
        printsioSerial('t')
    if event.key == pygame.K_g:
        printsioSerial('g')
    if event.key == pygame.K_y:
        printsioSerial('y')
    if event.key == pygame.K_h:
        printsioSerial('h')



def main():
    pygame.init()
    pygame.display.init()
    size = [700,500]
    screen = pygame.display.set_mode(size)
    print ("Ready for Action\n")
    pygame.key.set_repeat(1, 50)
    #main loop which displays the pressed keys on the screen
    while True:
        #print('true')
        #event = pygame.event.get()
        for event in pygame.event.get():
            
            if event.type == pygame.KEYDOWN: 
                untilKeyup(event)
            if event.type == pygame.KEYUP:
                printsioSerial('f')    

if __name__ == "__main__":
    main()
