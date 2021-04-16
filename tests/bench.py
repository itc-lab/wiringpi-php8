import RPi.GPIO as GPIO
import time

pin = 11
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pin,GPIO.IN,GPIO.PUD_DOWN)

t = time.time()
for i in range(0,100000,1):
    #pass
    GPIO.input(pin)
print( "%f"%(time.time() - t ) )
exit()
