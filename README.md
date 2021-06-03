# 33175 33176 33177 Microcontroleurs PB100 PB200 PB300

33175 33176 33177 Microcontroleurs PB100 PB200 PB300

<div style="text-align: justify">Les maquettes PB100, PB200 et PB300 sont des outils pédagogiques développés dans le cadre de la réforme du Lycée 2019, formation compétences numérique.</div>

# Microcontrôleur PB100 [33175](https://www.pierron.fr/microcontroleur-arduinotm-radar-de-recul-pb100-6450.html)

<div style="text-align: justify">Cette maquette permet aux élèves de simuler le principe de fonctionnement d’un radar de recul, de déterminer la célérité d’une onde à l’aide d’un microcontrôleur, de déterminer et d’afficher une distance et d’illustrer l’influence de la température de l’air sur la célérité d’une onde.
Elle offre la possibilité aux élèves de poursuivre leur initiation à la programmation d’un microcontrôleur et de l’utiliser de manière autonome, non reliée à un ordinateur, dans différentes situations pédagogiques grâce à son alimentation 9V.
Livrée avec tous les programmes corrigés, cette maquette est un outil clé en main pour la mise en oeuvre des nouveaux programmes du collège 2016 et du lycée 2019.</div>

![L-PB100](/img/L-PB100.jpg)

## RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [Radar de recul séance 1](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB100_TP3_1ere_Spe_PC_Radar_de_recul_PB100-S_ance_1_ELEVE_VF.pdf).

Ressource utilisation : [Radar de recul séance 2](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB100_TP3_1ere_Spe_PC_Radar_de_recul_PB100-S_ance_2_ELEVE_VF.pdf).

Ressource utilisation : [Radar de recul séance 3](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB100_TP3_1ere_Spe_PC_Radar_de_recul_PB100-S_ance_3_ELEVE_VF.pdf).

Ressource utilisation : [Radar de recul séance 4](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB100_TP3_1ere_Spe_PC_Radar_de_recul_PB100-S_ance_4_ELEVE_VF.pdf).


## Schémas :

![SCH-PB100](/img/SCH-PB100.jpg)
![BRD-PB100](/img/BRD-PB100.jpg)

## Exemple :

### mBlock
![P1-PB200](/img/P1-PB100.jpg)

### Arduino / C++
```cpp
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}

void setup(){
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(13,OUTPUT);
}

void loop(){
    if((getDistance(8,9)) < (20)){
        digitalWrite(6,1);
        digitalWrite(7,0);
        tone(13,650,125); 
        delay(125);
    }else{
        if((getDistance(8,9)) < (40)){
            digitalWrite(6,1);
            digitalWrite(7,0);
        }else{
            tone(13,550,250); 
            delay(250);
            digitalWrite(6,0);
            digitalWrite(7,1);
        }
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}
```

# Microcontrôleur PB200 [33176](https://www.pierron.fr/microcontroleur-arduinotm-son-et-lumiere-pb200-6451.html)

<div style="text-align: justify"> Cette maquette permet aux élèves de programmer l’émission de signaux sonores et lumineux. Elle dispose de 4 boutons-poussoirs pouvant piloter 4 LED de couleurs et un buzzer. La séance de base consiste à reproduire les sirènes des différents véhicules de secours.
Polyvalente, elle pourra être utilisée autant par des collégiens que par des lycéens. L’accessibilité au microcontrôleur de la maquette permet à l’élève d’augmenter le potentiel pédagogique du dispositif en ajoutant LED, buzzer ou autre actionneur, en plus de ceux déjà précâblés. L’élève est ainsi acteur de ses apprentissages en réalisant les connexions de base d’un microcontrôleur, en programmant son dispositif augmenté et en créant éventuellement un mini projet “son et lumière” personnalisé. </div>

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

print("Appuyer sur le bouton XX pour que la LED XX s'allume.")

try:
    while True:
        arduino.iterate() 
        for index in range(4):
            if arduino.digital[pin_pbs[index]].read()==1:
                arduino.digital[pin_leds[index]].write(1)
            else:
                arduino.digital[pin_leds[index]].write(0)
except KeyboardInterrupt:
    arduino.exit()
```

# Microcontrôleur PB300 [33177](https://www.pierron.fr/microcontroleur-arduinotm-chronometre-pb300-6452.html)

<div style="text-align: justify">Cette maquette permet aux élèves de modéliser et simuler le principe de chronométrage d’une course à l’aide d’un microcontrôleur, de déterminer et d’afficher la vitesse instantanée et l’énergie cinétique d’un objet, et d’estimer le travail de forces conservatives et non conservatives au cours d’un mouvement.
Livrée avec tous les programmes corrigés, cette maquette est un outil clé en main pour la mise en oeuvre des nouveaux programmes du collège 2016 (mouvements et vitesses) et du lycée 2019 (mouvements et interactions).</div>

![L-PB300](/img/L-PB300.jpg)

## RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [Chronomètre séance 1](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB300_TP4_1ere_Ski_S_ance_1_ELEVES_VF.pdf).

Ressource utilisation : [Chronomètre séance 2](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB300_TP4_1ere_Ski_S_ance_2_ELEVES.pdf).

Ressource utilisation : [Chronomètre séance 3](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB300_TP4_1ere_Ski_S_ance_3_ELEVES_VF.pdf).

Ressource utilisation : [Chronomètre séance 4](https://www.pierron.fr/fileuploader/download/download/?d=0&file=custom%2Fupload%2FPB300_TP4_1ere_Ski_S_ance_4_ELEVES_VF.pdf).

## Schémas :

![SCH-PB300](/img/SCH-PB300.jpg)
![BRD-PB300](/img/BRD-PB300.jpg)

## Exemple :

### mBlock
![P1-PB300](/img/P1-PB300.jpg)

### Arduino / C++
```cpp
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C EcranLCD(0x20,20,4); 

const int pin_capteur1 = A0;
const int pin_capteur2 = A1;
const int pin_led_rouge = 2;
const int pin_led_verte = 4;
const int pin_buzzer = 6;

void setup(){
    pinMode(pin_capteur1,INPUT);        
    pinMode(pin_capteur2,INPUT);        
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);

Serial.begin(9600);

    EcranLCD.init();          
    EcranLCD.backlight();
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("   CHRONOMETREZ");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("  une course avec");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print(" le microcontroleur");
    EcranLCD.setCursor(6, 3);
    EcranLCD.print("ARDUINO");
    delay(4000);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("   Lachez l'objet   ");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("    sur la rampe    ");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("   de la maquette ");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("       PB300    ");
}

void loop(){
    float top_depart;
    float t;

    if(analogRead(pin_capteur1) < 900){
        top_depart = millis();                           
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);                        
        while(analogRead(pin_capteur2) > 900){
                                                         
        }
                                                         
        t =(millis() - top_depart) / 1000.0;             
        
        tone(pin_buzzer,600,100);                        
        
        EcranLCD.clear();
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   duree = " + String(t,3) + " s");        
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("* Relancez l'objet *");
        Serial.println(String(t,3));
     }
       else{
        digitalWrite(pin_led_verte,1);
        digitalWrite(pin_led_rouge,0);
        }
}
```
## À propos :

<div style="text-align: justify">PIERRON ASCO-CELDA (https://www.pierron.fr).

En cas de difficultés, il y a toujours possibilité de télécharger le programme d’origine à partir 
des « ressources » sur le site [www.pierron.fr](https://www.pierron.fr).

Ces maquettes à base d'Arduino nano sont commercialisées par la société Pierron (https://www.pierron.fr)
en collaboration avec Patrice Buffet qui en a conçu le principe et développé la pédagogie.</div>
