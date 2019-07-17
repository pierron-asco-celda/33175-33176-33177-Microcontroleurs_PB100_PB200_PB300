/*******************************************************
Nom ......... : Programme_prof.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB100 : Déterminer la célérité d'une onde à l'aide d'un microcontrôleur
Role ........ : Programme pour maquette PB100
                Simulation d'un radar de recul à l'aide d'un microcontrôleur (demo prof)
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/


#include <LiquidCrystal_I2C.h>                   // on importe la bibliothèque.

LiquidCrystal_I2C EcranLCD(0x20,16,2);        // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100 (16 colonnes, 2 lignes)

const float VITESSE_SON = 340.0 / 10000;     // Vitesse du son en cm/µs
const int pin_Trigger = 8;
const int pin_Echo = 9;
const int TIMEOUT = 600 / VITESSE_SON;  // TIMEOUT en µs (pour 600cm aller/retour)
const int pin_led_verte = 3;
const int pin_led_rouge = 4;
const int pin_buzzer = 2;

/* Renvoie la distance mesurée en cm
*/
float getDistance()
{
  unsigned long temps1;
  unsigned long duree_ar;

  digitalWrite(pin_Trigger, HIGH);             // met la broche TRIGGER à l'état haut
  delayMicroseconds(10);                       // pendant 10 microsecondes, pour envoi une salve d'ondes ultrasonores.
  digitalWrite(pin_Trigger, LOW);              // met la broche  TRIGGER à l'état bas, en attendant la prochaine boucle.
  while(digitalRead(pin_Echo) == LOW)
  {
    // Attente ECHO passe à l'état haut : la salve d'ondes ultrasonore est partie
  }
  temps1 = micros();                      // horloge interne en µs
  while(digitalRead(pin_Echo) == HIGH and micros() - temps1 < TIMEOUT)
  {
    // Attente ECHO passe à l'état bas : la salve d'ondes ultrasonore est revenue
  }
  duree_ar = micros() - temps1;           // Durée Aller-Retour en microsecondes (µs)
  return  duree_ar * VITESSE_SON / 2;  // Distance en cm
}


void setup(){
   EcranLCD.init();                      // on initialise la communication entre l'Arduino et l'afficheur
   EcranLCD.backlight();
   pinMode(pin_Trigger, OUTPUT);               // La broche 11 de la carte Arduino est reliée à l'Emetteur "E" (déclencheur de salves d'ondes ultrasonores).
   pinMode(pin_Echo, INPUT);                // La broche 12 de la carte Arduino reliée au Récepteur "R" (reçoit et mesure le temps de vol de la salve émise par E).
   digitalWrite(pin_Trigger, LOW);
   pinMode(pin_led_rouge, OUTPUT);
   pinMode(pin_led_verte, OUTPUT);
   pinMode(pin_buzzer, OUTPUT);
}


void loop()
{

unsigned long distance;

    distance = getDistance();

    if(distance < 50)
    {
      digitalWrite(pin_led_rouge,1);
      digitalWrite(pin_led_verte,0);
      tone(pin_buzzer,600,125);
      delay(125);

      EcranLCD.clear();
      EcranLCD.setCursor(0, 0);
      EcranLCD.print(" Radar de recul");
      EcranLCD.setCursor(0, 1);
      EcranLCD.print(" d = ");
      EcranLCD.print(distance);

      EcranLCD.print(" cm");
    }
    else if(distance < 100)
    {
      digitalWrite(pin_led_rouge,1);
      digitalWrite(pin_led_verte,0);
      tone(pin_buzzer,600,125);
      delay(300);

      EcranLCD.clear();
      EcranLCD.setCursor(0, 0);
      EcranLCD.print(" Radar de recul");
      EcranLCD.setCursor(0, 1);
      EcranLCD.print(" d = ");
      EcranLCD.print(distance);

      EcranLCD.print(" cm");
    }
    else
    {
      digitalWrite(pin_led_rouge,0);
      digitalWrite(pin_led_verte,1);

      EcranLCD.clear();
      EcranLCD.setCursor(0, 0);
      EcranLCD.print(" Radar de recul");
      EcranLCD.setCursor(0, 1);
      EcranLCD.print(" d = ");
      EcranLCD.print(distance);

      EcranLCD.print(" cm");
      delay(2000);
    }
}
