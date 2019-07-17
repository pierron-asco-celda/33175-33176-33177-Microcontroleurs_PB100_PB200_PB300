/*******************************************************
Nom ......... : Pgm3_chrono_Vi2_voiture_PROF.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes Vmoy , Vitesses instantanées Vi , Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm3 :
                Affichage d'un message d'accueil
                Attente de l'obstruction du capteur 2
                Mesure du temps d'obstruction du capteur 2
                Calcul de la vitesse de la voiture au niveau du capteur 2
                Affichage.
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

const float L = 0.07 ;  // L = Longueur de la voiture bleue en m


void setup(){
    pinMode(pin_capteur1,INPUT);  // entrée analogique capteur 1
    pinMode(pin_capteur2,INPUT);  // entrée analogique capteur 2
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);

    EcranLCD.init();
    EcranLCD.backlight();
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("   Mesurer la Vi");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("      au niveau");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("    du capteur 2");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" Lachez la voiture !");

   }

void loop(){
    float top_depart_2;
    float t2;
    float v2;

    if(analogRead(pin_capteur2) < 900){
        top_depart_2 = millis();
        digitalWrite(pin_led_verte,1);
        digitalWrite(pin_led_rouge,0);
        tone(pin_buzzer,600,100);
        while(analogRead(pin_capteur2) < 900){
          // Attente passage objet devant le capteur 2
        }
        t2 = (millis() - top_depart_2) / 1000.0;        // en secondes
        v2 = L / t2;                                    // en m/s

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("    t2 = " + String(t2,3) + " ms");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   Vi2 = " + String(v2,3) + " m/s");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print(" Relachez la voiture");

    }
    else{
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
    }
}
