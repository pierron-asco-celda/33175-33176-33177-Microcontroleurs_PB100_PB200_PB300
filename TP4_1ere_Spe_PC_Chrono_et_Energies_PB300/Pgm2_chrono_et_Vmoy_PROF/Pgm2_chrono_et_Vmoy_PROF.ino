/*******************************************************
Nom ......... : Pgm2_chrono_et_Vmoy_PROF.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes Vmoy , Vitesses instantanées Vi , Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm2 :
                Affichage d'un message d'acceuil
                Attente de l'obstruction du capteur 1
                Mesure du temps entre l'obstruction du capteur 1 et l'obstruction du capteur2
                Affichage des résultats dont la vitesse moyenne.
Auteur ...... : Patrice Buffet (professeur de physique-chimie)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V3 du 25/05/2019
Licence ..... : CeCILL
********************************************************/



#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C EcranLCD(0x20,20,4);        // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB300 (20 colonnes et 4 lignes).

const int pin_capteur1 = A0;
const int pin_capteur2 = A1;
const int pin_led_rouge = 4;
const int pin_led_verte = 2;
const int pin_buzzer = 6;

const float d = 0.80;   // distance entre les deux capteurs en m


void setup(){
    pinMode(pin_capteur1,INPUT);  // entrée analogique capteur 1
    pinMode(pin_capteur2,INPUT);  // entrée analogique capteur 2
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);

    EcranLCD.init();
    EcranLCD.backlight();
    EcranLCD.clear();
    EcranLCD.setCursor(2, 0);
    EcranLCD.print("Chronometrer et");
    EcranLCD.setCursor(2, 1);
    EcranLCD.print("en deduire Vmoy");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("  Lachez l'objet !");
}

void loop(){
    float top_depart;
    float t;
    float v;

    if(analogRead(pin_capteur1) < 900){
        top_depart = millis();                   // top chrono
        digitalWrite(pin_led_verte,1);
        digitalWrite(pin_led_rouge,0);
        tone(pin_buzzer,600,100);
        while(analogRead(pin_capteur2) > 900){
                                                 // Attente passage objet devant le capteur 2
        }
                                                 // arrêt chrono
        t =(millis() - top_depart) / 1000.0;     // ainsi définie l'unité de t est la seconde.
        v = d / t;                               // vitesse en m/s
        tone(pin_buzzer,600,100);

        EcranLCD.clear();
        EcranLCD.setCursor(3, 0);
        EcranLCD.print(" t = " + String(t,3) + " ms");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("  Vmoy = " + String(v,3) + " m/s");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("* Relachez l'objet *");
       }
    else{
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        }
}
