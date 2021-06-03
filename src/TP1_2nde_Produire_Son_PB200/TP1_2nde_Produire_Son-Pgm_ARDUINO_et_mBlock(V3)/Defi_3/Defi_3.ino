/*******************************************************
Nom ......... : Defi_3.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°3 :
                Réalise un chenillard
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/



const int pin_led_jaune = 3;
const int pin_bp_jaune = 12;
const int pin_led_rouge = 2;
const int pin_bp_rouge = 11;
const int pin_led_bleue = 5;
const int pin_bp_bleu = 10;
const int pin_led_verte = 4;
const int pin_bp_vert = 9;

void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_bp_rouge,INPUT);
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_bp_vert,INPUT);

    pinMode(pin_led_jaune,OUTPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_bleue,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
}


void loop(){
    if(digitalRead(pin_bp_bleu)==HIGH){

        digitalWrite(pin_led_bleue,HIGH);
        delay(100);

        digitalWrite(pin_led_bleue,LOW);
        digitalWrite(pin_led_rouge,HIGH);
        delay(100);

        digitalWrite(pin_led_rouge,LOW);
        digitalWrite(pin_led_jaune,HIGH);
        delay(100);

        digitalWrite(pin_led_jaune,LOW);
        digitalWrite(pin_led_verte,HIGH);
        delay(100);

        digitalWrite(pin_led_verte,LOW);
    }
    else
    {
        digitalWrite(pin_led_jaune,LOW);
        digitalWrite(pin_led_verte,LOW);
        digitalWrite(pin_led_rouge,LOW);
        digitalWrite(pin_led_bleue,LOW);
    }
}
