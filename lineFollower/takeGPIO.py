import RPi.GPIO as GPIO
from time import sleep

# use P1 header pin numbering convention
GPIO.setmode(GPIO.BCM)

# Set up the GPIO channels
GPIO.setup(11, GPIO.IN,pull_up_down=GPIO.PUD_DOWN) # This could be used to detect a switch
GPIO.setup(26, GPIO.IN,pull_up_down=GPIO.PUD_DOWN) # This is going to supply the on/off signal

# Output to pin 12. Toggles it on/off every three seconds
while True:


# Input from pin 11
    input_value21 = GPIO.input(11)

    input_value20 = GPIO.input(26)

    if input_value21 == 1:
        print(" 21 HIGH")
    else:
        print(" 21 LOW")

    if input_value20 == 1:
        print(" 20 HIGH")
    else:
        print(" 20 LOW")

