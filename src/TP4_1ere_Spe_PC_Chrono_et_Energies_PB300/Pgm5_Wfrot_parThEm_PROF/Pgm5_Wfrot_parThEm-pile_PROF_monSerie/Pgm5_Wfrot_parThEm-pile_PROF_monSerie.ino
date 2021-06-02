/*******************************************************
Nom ......... : Pgm5_Wfrot_parThEm_voiture_PROF_monSerie.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes Vmoy , Vitesses instantanées Vi , Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm5_Wfrot_parThEm_pile_habillée :
                Affichage d'un message d'accueil
                Quand obstruction du capteur 1
                Mesure du temps d'obstruction du capteur 1
                Quand obstruction du capteur 2
                Mesure du temps d'obstruction du capteur 2
                Bilan énergétique
                Calcul de la perte d'énergie mécanique
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

const float m = 0.049 ;  // masse de l'ojet en kg (ici objet = pile habillée bois/papier !)
const float L = 0.045 ;  // Longueur de l'objet en m (ici objet = pile habillée bois/papier !)
const float g = 9.81 ;   // intensité de la pesanteur en m/s^2
const float h = 0.35 ;   // hauteur de chute en m

float top_depart_1 = 0;
float t1;
float v1;
float Ec1;
float Epp1;
float Em1;
float top_depart_2 = 0;
float t2;
float v2;
float Ec2;
float Epp2;
float Em2;
float DeltaEm;

void setup(){
    pinMode(pin_capteur1,INPUT);  // entrée analogique capteur 1
    pinMode(pin_capteur2,INPUT);  // entrée analogique capteur 2
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);

    Serial.begin(9600);

    EcranLCD.init();
    EcranLCD.backlight();
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("W Travail des forces");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("   de frottements");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("    d'un objet.");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" Lance la pile !");

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
        t1 = ( millis() - top_depart_1 ) /1000.0 ;
        v1 = L / t1;
        Ec1 = 0.5 * m * v1 * v1;
        Epp1 = m * g * h;
        Em1 = Ec1 + Epp1;

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("   Em1 = " + String(Em1,3) + " J");

    }
    else if(analogRead(pin_capteur2) < 900){
        top_depart_2 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(pin_capteur2) < 900){
          // Attente passage objet devant le capteur 2
        }
        t2 = ( millis() - top_depart_2 ) /1000.0 ;
        v2 = L / t2;
        Ec2 = 0.5 * m * v2 * v2;
        Epp2 = 0;
        Em2 = Ec2 + Epp2;
        DeltaEm = Em2 - Em1;

        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   Em2 = " + String(Em2,3) + " J");

        EcranLCD.setCursor(0, 2);
        EcranLCD.print("Em2 - Em1 = " + String(DeltaEm,3) + " J");

        EcranLCD.setCursor(0, 3);
        EcranLCD.print("   -->  W = " + String(DeltaEm,3) + " J");

        Serial.println(String(DeltaEm,3));
    }
    else{
      digitalWrite(pin_led_verte,1);
      digitalWrite(pin_led_rouge,0);
    }
}
