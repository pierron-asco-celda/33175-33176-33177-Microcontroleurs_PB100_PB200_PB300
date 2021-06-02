/*******************************************************
Nom ......... : Pgm4_Em1_Em2-PROF.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes Vmoy , Vitesses instantanées Vi , Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm4_Em1_Em2 :
                Affichage d'un message d'accueil
                Quand obstruction du capteur 1
                Mesure du temps d'obstruction du capteur 1
                Quand obstruction du capteur 2
                Mesure du temps d'obstruction du capteur 2
                Calcul de l'énergie mécanique au niveau de chaque capteur
                Calcul de la différence d'énergie mécanique.
                Affichages.
Auteur ...... : Patrice Buffet (professeur de physique-chimie)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 06/05/2019
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
const float g = 9.81 ;
const float h = 0.25 ;   // dénivelé entre les deux capteurs en mètre.

float top_depart_1;
float t1;
float v1;
float Ec1;
float Epp1;
float Em1;
float top_depart_2;
float t2;
float v2;
float Ec2;
float Epp2;
float Em2;
float delta_Em;

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
    EcranLCD.print("  Bilan d'ENERGIE");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print(" Affiche Em1 et Em2");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("   Lance l'objet !");

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
        Ec1 = 0.5 * m * v1 * v1;                        // Energie Cinétique en Joules
        Epp1 = m * g * h;                               // Energie potentielle en Joules. Choix des origines de Epp au niveau du capteur 1
        Em1 = Ec1 + Epp1;                               // Energie Mécanique en Joules

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("Ec1=");
        EcranLCD.print(Ec1);
        EcranLCD.print("J ");
        EcranLCD.print("Epp1=");
        EcranLCD.print(Epp1);
        EcranLCD.print("J ");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("    Em1 = ");
        EcranLCD.print(Em1);
        EcranLCD.print(" J");

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
        v2 = L/t2;                                    // en m/s
        Ec2 = 0.5 * m * v2 * v2;                      // Energie Cinétique en Joules
        Epp2 = 0;                                     // Energie potentielle en Joules
        Em2 = Ec2 + Epp2;                             // Energie Mécanique en Joules

        delta_Em = Em2 - Em1;                         // Différence d'energie mécanique en Joules

        EcranLCD.setCursor(0, 2);
        EcranLCD.print("Ec2=");
        EcranLCD.print(Ec2);
        EcranLCD.print("J ");
        EcranLCD.print("Epp2=");
        EcranLCD.print(Epp2);
        EcranLCD.print("J ");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("    Em2 = ");
        EcranLCD.print(Em2);
        EcranLCD.print(" J");
    }
    else{
      digitalWrite(pin_led_verte,1);
      digitalWrite(pin_led_rouge,0);
    }
}
