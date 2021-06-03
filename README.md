# 33175 33176 33177 Microcontroleurs PB100 PB200 PB300

33175 33176 33177 Microcontroleurs PB100 PB200 PB300

Les maquettes PB100, PB200 et PB300 sont des outils pédagogiques développés dans le cadre de la réforme du Lycée 2019, formation compétences numérique.

# Microcontroleurs PB100

Cette maquette permet aux élèves de simuler le principe de fonctionnement d’un radar de recul, de déterminer la célérité d’une onde à l’aide d’un microcontrôleur, de déterminer et d’afficher une distance et d’illustrer l’influence de la température de l’air sur la célérité d’une onde.
Elle offre la possibilité aux élèves de poursuivre leur initiation à la programmation d’un microcontrôleur et de l’utiliser de manière autonome, non reliée à un ordinateur, dans différentes situations pédagogiques grâce à son alimentation 9V.
Livrée avec tous les programmes corrigés, cette maquette est un outil clé en main pour la mise en oeuvre des nouveaux programmes du collège 2016 et du lycée 2019.

![L-PB100](/img/L-PB100.jpg)

# Microcontroleurs PB200 [33176](https://www.pierron.fr/microcontroleur-arduinotm-son-et-lumiere-pb200-6451.html)

Cette maquette permet aux élèves de programmer l’émission de signaux sonores et lumineux. Elle dispose de 4 boutons-poussoirs pouvant piloter 4 LED de couleurs et un buzzer. La séance de base consiste à reproduire les sirènes des différents véhicules de secours.
Polyvalente, elle pourra être utilisée autant par des collégiens que par des lycéens. L’accessibilité au microcontrôleur de la maquette permet à l’élève d’augmenter le potentiel pédagogique du dispositif en ajoutant LED, buzzer ou autre actionneur, en plus de ceux déjà précâblés. L’élève est ainsi acteur de ses apprentissages en réalisant les connexions de base d’un microcontrôleur, en programmant son dispositif augmenté et en créant éventuellement un mini projet “son et lumière” personnalisé.

![L-PB200](/img/L-PB200.jpg)

## RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [Produire un son](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB200_TP1_2nde_Produire_Son_Fiche_ELEVES_VF.pdf).

Ressource utilisation : [Capteur de température](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB200_TP2_2nde_capteur_Temperature_Fiche_ELEVE_VF.pdf).

## Schémas :

![SCH-PB200](/img/SCH-PB200.jpg)
![BRD-PB200](/img/BRD-PB200.jpg)

## Exemple :

### mBlock
![P1-PB200](/img/P1-PB200.jpg)

### Arduino / C++
```cpp
const int pin_led_jaune = 3;
const int pin_bp_jaune = 12;
const int pin_led_rouge = 2;
const int pin_bp_rouge = 11;
const int pin_led_bleue = 5;
const int pin_bp_bleu = 10;
const int pin_led_verte = 4;
const int pin_bp_vert = 9;

void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_bp_rouge,INPUT);
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_bp_vert,INPUT);

    pinMode(pin_led_jaune,OUTPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_bleue,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
}

void loop(){
     if(digitalRead(pin_bp_jaune)==HIGH)
     {
        digitalWrite(pin_led_jaune,HIGH);
     }
     else
     {
        digitalWrite(pin_led_jaune,LOW);
     }

    if(digitalRead(pin_bp_rouge)==HIGH)
    {
        digitalWrite(pin_led_rouge,HIGH);
    }
    else
    {
        digitalWrite(pin_led_rouge,LOW);
    }

    if(digitalRead(pin_bp_bleu)==HIGH)
    {
        digitalWrite(pin_led_bleue,HIGH);
    }
    else
    {
        digitalWrite(pin_led_bleue,LOW);
    }

    if(digitalRead(pin_bp_vert)==HIGH)
    {
        digitalWrite(pin_led_verte,HIGH);
    }
    else
    {
        digitalWrite(pin_led_verte,LOW);
    }
}
```

### Python
```py
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
```

# Microcontroleurs PB300

Cette maquette permet aux élèves de modéliser et simuler le principe de chronométrage d’une course à l’aide d’un microcontrôleur, de déterminer et d’afficher la vitesse instantanée et l’énergie cinétique d’un objet, et d’estimer le travail de forces conservatives et non conservatives au cours d’un mouvement.
Livrée avec tous les programmes corrigés, cette maquette est un outil clé en main pour la mise en oeuvre des nouveaux programmes du collège 2016 (mouvements et vitesses) et du lycée 2019 (mouvements et interactions).

![L-PB300](/img/L-PB300.jpg)


## À propos :

PIERRON ASCO-CELDA (https://www.pierron.fr).

En cas de difficultés, il y a toujours possibilité de télécharger le programme d’origine à partir 
des « ressources » sur le site [www.pierron.fr](https://www.pierron.fr).

Ces maquettes à base d'Arduino nano sont commercialisées par la société Pierron (https://www.pierron.fr)
en collaboration avec Patrice Buffet qui en a conçu le principe et développé la pédagogie.
