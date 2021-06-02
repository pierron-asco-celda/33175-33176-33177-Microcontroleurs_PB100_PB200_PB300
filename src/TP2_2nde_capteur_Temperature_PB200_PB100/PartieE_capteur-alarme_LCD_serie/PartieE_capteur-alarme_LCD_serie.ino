/*******************************************************
Nom ......... : PartieE_capteur-alarme_LCD_serie.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB100 : Mesure d'une température à l'aide d'une thermistance
Role ........ : Programme pour maquette PB100
                Alarme à incendie qui se déclenche
                lorsque T>25°C environ soit N<512
                Affiche la valeur de N et Uth d'un capteur sur un écran LCD et moniteur série.
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C EcranLCD(0x20,16,2);        // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100 (16 colonnes et 2 lignes).

const int pin_led_verte = 3;
const int pin_led_rouge = 4;
const int pin_buzzer = 2;
const int pin_thermometre = A1;

void setup() {

    pinMode(pin_thermometre,INPUT);     // Entrée analogique qui reçoit une tension comprise entre 0 et 5V en fonction de la température
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);

    EcranLCD.init();                    // on initialise la communication entre l'Arduino et l'afficheur.
    Serial.begin(9600); // ouvir un port série
}

void loop()  {

    int N = analogRead(A1);
    float U = N * 5.0 / 1023;

    if(N < 512){
        digitalWrite(pin_led_verte,LOW);
        digitalWrite(pin_led_rouge,HIGH);
        tone(pin_buzzer,650,500);
        delay(500);
        digitalWrite(pin_led_rouge,LOW);
        tone(pin_buzzer,750,500);
        delay(500);
    }
    else{
        digitalWrite(pin_led_verte,HIGH);
        digitalWrite(pin_led_rouge,LOW);
    }

    Serial.print("Valeur numerique mesuree par le capteur : N = ");
    Serial.print(N);
    Serial.print("    Tension : U = ");
    Serial.print(U);
    Serial.println(" V ");

    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print(" nombre N = ");
    EcranLCD.print(N);
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("    U = ");
    EcranLCD.print(U);
    EcranLCD.print(" V");

}
