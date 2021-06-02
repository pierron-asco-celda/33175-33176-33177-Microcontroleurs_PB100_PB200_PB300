#!c:\Python27\python.exe

"""
Essai pour ...
"""

from pyfirmata import Arduino, util
import sys
import time

arduino = Arduino('COM12')

pin_led_vert = 11
pin_led_jaune = 10
pin_led_rouge = 9
pin_led_bleu = 8
pins = [pin_led_vert, pin_led_jaune, pin_led_rouge,pin_led_bleu]

#Chenillard
while True:
    try:
        #arduino.iterate()
        for pin in pins:
            arduino.digital[pin].write(1)
            time.sleep(1)
            arduino.digital[pin].write(0)
    except KeyboardInterrupt:
        arduino.exit()
        break
