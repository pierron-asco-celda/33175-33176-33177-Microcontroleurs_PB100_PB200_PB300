/*******************************************************
Nom ......... : Pgm1_chrono_et_signal_sonore_depart_PROF.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes, Vitesses instantanées, Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm1 :
                Affichage d'un message d'acceuil
                Attente de l'obstruction du capteur 1
                Emission d'un petit signal sonore
                Mesure du temps entre l'obstruction du capteur 1 et l'obstruction du capteur2
                Affichage des résultats.
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
const int pin_led_rouge = 2;
const int pin_led_verte = 4;
const int pin_buzzer = 6;

void setup(){
    pinMode(pin_capteur1,INPUT);        // entrée analogique capteur 1
    pinMode(pin_capteur2,INPUT);        // entrée analogique capteur 2
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);

Serial.begin(9600);

    EcranLCD.init();          // on initialise la communication entre l'Arduino et le PC
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
        top_depart = millis();                           // top chrono (unité par défaut : milliseconde)
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);                        // Ligne à compléter par l'élève
        while(analogRead(pin_capteur2) > 900){
                                                         // Attente passage objet devant le capteur 2
        }
                                                         // arrêt chrono
        t =(millis() - top_depart) / 1000.0;             // ainsi définie l'unité de t est la seconde
        
        tone(pin_buzzer,600,100);                        // Ligne à compléter par l'élève
        
        EcranLCD.clear();
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   duree = " + String(t,3) + " s");        // 3 chiffres après la virgule
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("* Relancez l'objet *");
        Serial.println(String(t,3));
     }
       else{
        digitalWrite(pin_led_verte,1);
        digitalWrite(pin_led_rouge,0);
        }
}
