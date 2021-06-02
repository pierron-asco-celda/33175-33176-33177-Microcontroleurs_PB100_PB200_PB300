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
const int pin_buzzer = 6;                // Le buzzer est branché sur la broche 6 d'Arduino

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
    float top_depart;                                    // création d'une variable flottante (à virgule) top_depart
    float t;                                             // création d'une variable durée t (durée mise par l'objet entre le capteur 1 et le capteur 2)

    if(analogRead(pin_capteur1) < 900){                  // Si un objet passe devant le capteur n°1 (faible intensité lumimneuse sur le photorécepteur), alors :
        top_depart = millis();                           // top chrono (unité par défaut : milliseconde), la variable top_depart mémorise le temps t1 de passage de l'objet devant le capteur1
        digitalWrite(pin_led_verte,0);                   // la led verte s'éteint
        digitalWrite(pin_led_rouge,1);                   // la led rouge s'allume
        tone(pin_buzzer,600,100);                        // un son bref de 600 Hertz est émis pendant 100 ms : LIGNE A COMPLETER PAR L'ELEVE !!!
        while(analogRead(pin_capteur2) > 900){           
           }                                             // Attente passage objet devant le capteur 2
        
        t =(millis() - top_depart) / 1000.0;             // arrêt chrono : la variable t mémorise la durée de passage de l'objet entre les 2 capteurs
                                                         // ainsi définie l'unité de t est la seconde


              
        EcranLCD.clear();                                          // Affichage de la durée t sur l'écan LCD de la maquette PB300     
        EcranLCD.setCursor(4, 0);                                  // Position du curseur Colonne 4 ; Ligne 0
        EcranLCD.print("duree = " + String(t,3) + " s");           // 3 chiffres après la virgule
        EcranLCD.setCursor(0, 2);
        EcranLCD.print("* Relancez l'objet *");
        Serial.println(String(t,2));                               //  Affichage de la durée t sur le moniteur série, 2 chiffres après la virgule
     }
       else{
        digitalWrite(pin_led_verte,1);                    // la led verte s'allume lorsque la mesure de t est terminée et jusqu'à ce que le capteur1 détecte à nouveau un objet.
        digitalWrite(pin_led_rouge,0);                    // la led rouge s'éteint lorsque la mesure de t est terminée et jusqu'à ce que le capteur1 détecte à nouveau un objet.
        }
}
