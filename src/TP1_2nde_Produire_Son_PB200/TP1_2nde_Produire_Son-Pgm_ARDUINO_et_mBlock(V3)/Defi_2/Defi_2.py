"""
Nom ......... : Defi_2.py
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°2 :
              Lorsque j’appuie sur le BP JAUNE, la led JAUNE s’allume.
              Lorsque j’appuie sur le BP ROUGE, la led ROUGE s’allume.
              Lorsque j’appuie sur le BP BLEU, la led BLEUE s’allume.
              Lorsque j’appuie sur le BP VERT, la led VERTE s’allume.
Auteur ...... : Patrice Buffet (professeur de physique-chimie)
coAuteur .... : Frédéric Thomé (fthome@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V1 du 29/05/2019
Licence ..... : CeCILL
"""
from pyfirmata import *

print("PIERRON - PB200 : Défi 2")
print("Connection à l'Arduino ...")

arduino = Arduino('COM12')

pin_led_jaune = 3
pin_bp_jaune = 12
pin_led_rouge = 2
pin_bp_rouge = 11
pin_led_bleue = 5
pin_bp_bleu = 10
pin_led_verte = 4
pin_bp_vert = 9

pin_leds = [pin_led_verte, pin_led_jaune, pin_led_rouge,pin_led_bleue]
pin_pbs = [pin_bp_vert, pin_bp_jaune, pin_bp_rouge, pin_bp_bleu]

for pin in pin_leds:
    arduino.digital[pin].mode = OUTPUT
for pin in pin_pbs:
    arduino.digital[pin].mode = INPUT

print("Appuyer sur le bouton XX pour que la led XX s'allume.")

try:
    while True:
        arduino.iterate() # Lecture de l'état de l'arduino
        for index in range(4):
            if arduino.digital[pin_pbs[index]].read()==1:
                arduino.digital[pin_leds[index]].write(1)
            else:
                arduino.digital[pin_leds[index]].write(0)
except KeyboardInterrupt:
    arduino.exit()
