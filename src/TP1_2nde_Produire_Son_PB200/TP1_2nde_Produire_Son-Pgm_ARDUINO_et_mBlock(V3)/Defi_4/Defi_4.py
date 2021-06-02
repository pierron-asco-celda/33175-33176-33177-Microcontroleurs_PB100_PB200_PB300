"""
Nom ......... : Defi_4.py
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°4 :
              Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, un son de 440 Hz est émis par le buzzer relié à la broche 12.
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

pin_bp_bleu = 5
pin_buzzer = 12


arduino.digital[pin_buzzer].mode = SERVO
arduino.digital[pin_bp_bleu].mode = INPUT

print("Appuyer sur le bouton Bleu pour émettre un LA.")

try:
    while True:
        arduino.iterate() # Lecture de l'état de l'arduino
        if arduino.digital[pin_bp_bleu].read()==1:
            pass # TODO : mais pas gagné avec pyfirmata!!!

except KeyboardInterrupt:
    arduino.exit()
