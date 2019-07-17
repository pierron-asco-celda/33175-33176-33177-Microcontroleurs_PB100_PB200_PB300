"""
Nom ......... : Defi_1.py
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°1 :
              Lorsque j’appuie sur le bouton poussoir (BP) jaune relié à la broche 3 de la carte ArduinoTM , la led jaune reliée à la boche 10 s’allume.
              Lorsque je n’appuie plus sur le BP, la led s’éteint.
Auteur ...... : Patrice Buffet (professeur de physique-chimie)
coAuteur .... : Frédéric Thomé (fthome@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V1 du 29/05/2019
Licence ..... : CeCILL
"""
from pyfirmata import *

arduino = Arduino('COM12')

pin_led_jaune = 10
pin_bp_jaune = 3

arduino.digital[pin_led_jaune].mode = OUTPUT
arduino.digital[pin_bp_jaune].mode = INPUT

print("PIERRON - PB200 : Défi 1")
print("Appuyer sur le bouton jaune pour que la led jaune s'allume.")

try:
    while True:
        arduino.iterate() # Lecture de l'état de l'arduino
        if arduino.digital[pin_bp_jaune].read()==1:
            arduino.digital[pin_led_jaune].write(1)
        else:
            arduino.digital[pin_led_jaune].write(0)
except KeyboardInterrupt:
    arduino.exit()
