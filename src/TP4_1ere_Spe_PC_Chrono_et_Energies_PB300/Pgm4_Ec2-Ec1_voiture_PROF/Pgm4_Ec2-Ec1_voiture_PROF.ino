/*******************************************************
Nom ......... : Pgm4_Ec2-Ec1_voiture_PROF.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes Vmoy , Vitesses instantanées Vi , Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm4_Ec2-Ec1_voiture :
                Affichage d'un message d'accueil
                Quand obstruction du capteur 1
                Mesure du temps d'obstruction du capteur 1
                Quand obstruction du capteur 2
                Mesure du temps d'obstruction du capteur 2
                Calcul de l'énergie cinétique au niveau de chaque capteur
                Calcul de la différence d'énergie cinétique.
                Affichages.
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

const float m = 0.031 ;  // masse de l'objet en kg (ici objet = petite voiture bleue métallique !)
const float L = 0.070 ;  // Longueur de l'objet en m (ici objet = petite voiture bleue métallique !)

float top_depart_1;
float t1;
float v1;
float Ec1;
float top_depart_2;
float t2;
float v2;
float Ec2;
float delta_Ec;

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
    EcranLCD.print("  Mesurer V1 et V2");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print(" Afficher Ec2 - Ec1");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" Lance la voiture !");

   }

void loop(){

    if(analogRead(pin_capteur1) < 900){
        top_depart_1 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(pin_capteur1) < 900){
          // Attente passage objet devant le capteur 1
        }
        t1 = (millis() - top_depart_1) / 1000.0;        // en secondes
        v1 = L / t1;                                    // en m/s
        Ec1 = 0.5 * m * v1 * v1;                        // en Joules
       
        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("    Ec1 = " + String(Ec1,3) + " J");
    }
    
    else if(analogRead(pin_capteur2) < 900){
        top_depart_2 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(pin_capteur2) < 900){
          // Attente passage objet devant le capteur 2
        }
        t2 = (millis() - top_depart_2) /1000.0;       // en secondes
        v2 = L / t2;                                  // en m/s
        Ec2 = 0.5 * m * v2 * v2;                      // en Joules
        delta_Ec = Ec2 - Ec1;

        EcranLCD.setCursor(0, 1);
        EcranLCD.print("    Ec2 = " + String(Ec2,3) + " J");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("Ec2 - Ec1 = " + String(delta_Ec,3) + " J");
    }
    else{
      digitalWrite(pin_led_verte,1);
      digitalWrite(pin_led_rouge,0);
    }
}
