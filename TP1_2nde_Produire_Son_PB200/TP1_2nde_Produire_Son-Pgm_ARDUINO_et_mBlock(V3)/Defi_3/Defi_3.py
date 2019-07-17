"""
Nom ......... : Defi_3.py
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°3 :
                Réalise un chenillard
Auteur ...... : Patrice Buffet (professeur de physique-chimie)
coAuteur .... : Frédéric Thomé (fthome@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V1 du 29/05/2019
Licence ..... : CeCILL
"""
from pyfirmata import *
import time

print("PIERRON - PB200 : Défi 2")
print("Connection à l'Arduino ...")

arduino = Arduino('COM12')

pin_led_jaune = 10
pin_bp_jaune = 3
pin_led_rouge = 9
pin_bp_rouge = 4
pin_led_bleue = 8
pin_bp_bleu = 5
pin_led_verte = 11
pin_bp_vert = 2

pin_leds = [pin_led_verte, pin_led_jaune, pin_led_rouge,pin_led_bleue]
pin_pbs = [pin_bp_vert, pin_bp_jaune, pin_bp_rouge, pin_bp_bleu]

for pin in pin_leds:
    arduino.digital[pin].mode = OUTPUT
for pin in pin_pbs:
    arduino.digital[pin].mode = INPUT

print("Appuyer sur le bouton Bleu pour que les leds s'allument successivement.")

try:
    while True:
        arduino.iterate() # Lecture de l'état de l'arduino
        if arduino.digital[pin_bp_bleu].read()==1:
            for pin_led in pin_leds:
                arduino.digital[pin_led].write(1)
                time.sleep(1)
                arduino.digital[pin_led].write(0)
except KeyboardInterrupt:
    arduino.exit()
