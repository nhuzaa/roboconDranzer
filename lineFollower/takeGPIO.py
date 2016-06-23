import RPi.GPIO as GPIO
from time import sleep


GPIO.setmode(GPIO.BCM)
bit0Pin = 20
bit1Pin = 21
# Set up the GPIO channels
GPIO.setup(bit0Pin, GPIO.IN,pull_up_down=GPIO.PUD_DOWN) # This could be used to detect a switch
GPIO.setup(bit1Pin, GPIO.IN,pull_up_down=GPIO.PUD_DOWN) # This is going to supply the on/off signal

# Output to pin 12. Toggles it on/off every three seconds
while True:


# Input from pin 11
    bit0 = GPIO.input(bit0Pin)
    bit1 = GPIO.input(bit1Pin)

    if bit0 == 0 and bit1 == 0:
        print(" manaul")
    elif bit0 == 0 and bit1 == 1:
        print(" Automatic")
    elif bit0 == 1 and bit1 == 0:
        print("Tuin Point")
    elif bit0 == 1 and bit1 == 1:
        print(" Salt Point")

