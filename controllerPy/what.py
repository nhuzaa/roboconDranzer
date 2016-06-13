import serial
import pygame
pygame.init()
pygame.joystick.init()
arduino = serial.Serial('/dev/ttyACM0', 9600)


while True:
	# -------- Main Program Loop -----------
    # EVENT PROCESSING STEP
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked close
            done=True # Flag that we are done so we exit this loop

        # Possible joystick actions: JOYAXISMOTION JOYBALLMOTION JOYBUTTONDOWN JOYBUTTONUP JOYHATMOTION
        if event.type == pygame.JOYBUTTONDOWN:
            print("Joystick button pressed.")
        if event.type == pygame.JOYBUTTONUP:
            print("Joystick button released.")
	
#			data = arduino.readline() #the last bit gets rid of the new-line chars
#			if data:
#				print (data)

