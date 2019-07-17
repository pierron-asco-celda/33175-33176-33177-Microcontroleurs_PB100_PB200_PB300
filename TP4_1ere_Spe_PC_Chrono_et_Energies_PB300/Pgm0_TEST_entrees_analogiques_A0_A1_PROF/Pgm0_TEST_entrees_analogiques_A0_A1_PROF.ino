/*******************************************************
Nom ......... : Pgm0_TEST_entrees_analogiques_A0_A1_PROF.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB300 : Chronométrage, Vitesses moyennes Vmoy, Vitesses instantanées Vi, Ec, Epp, Th Ec, Th Em, W(forcres de frottement).
Role ........ : Programme pour maquette PB300
        Pgm0 :
                Affichage du niveau des entrées analogiques
                    - sur l'écran LCD
                    - sur le moniteur série
Auteur ...... : Patrice Buffet (professeur de physique-chimie)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V3 du 25/05/2019
Licence ..... : CeCILL
********************************************************/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C EcranLCD(0x20,20,4);    // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB300 (20 colonnes et 4 lignes).

const int pin_capteur1 = A0;
const int pin_capteur2 = A1;

void setup(){
    pinMode(pin_capteur1,INPUT);  // entrée analogique capteur 1
    pinMode(pin_capteur2,INPUT);  // entrée analogique capteur 2

    Serial.begin(9600);           // on initialise la communication entre l'Arduino et le PC
    EcranLCD.init();              // on initialise la communication entre l'Arduino et l'afficheur.
    EcranLCD.backlight();         // ajouter un commentaire ..................
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("TEST entree A0 et A1");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print(" sur Moniteur serie");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("  et sur ecran LCD");
}

void loop(){
    int capteur1 = analogRead(pin_capteur1);    // Lecture entrée analogique A0
    int capteur2 = analogRead(pin_capteur2);    // Lecture entrée analogique A1

    Serial.print("     Capteur1 : ");
    Serial.print(capteur1);
    Serial.print("     Capteur2 : ");
    Serial.println(capteur2);

    EcranLCD.setCursor(0, 3);
    EcranLCD.print("                    ");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" A0 = ");
    EcranLCD.print(capteur1);
    EcranLCD.setCursor(11, 3);
    EcranLCD.print("A1 = ");
    EcranLCD.print(capteur2);

    delay(1000);
}
