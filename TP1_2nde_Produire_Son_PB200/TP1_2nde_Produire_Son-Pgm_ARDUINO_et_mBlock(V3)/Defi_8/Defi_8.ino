/*******************************************************
Nom ......... : Defi_8.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
          défi n°8 :
              Lorsque j’appuie sur le bouton poussoir relié à la broche 5, j’entends la sirène de la Police et je vois la
              led bleue clignoter au rythme du changement de fréquence de la sirène.
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/

const int pin_led_bleue = 8;
const int pin_bp_bleu = 5;
const int pin_buzzer = 12;

void setup(){
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_led_bleue,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    if(digitalRead(pin_bp_bleu) == HIGH){
        digitalWrite(pin_led_bleue,HIGH);
        tone(pin_buzzer,435,500);
        delay(500);
        digitalWrite(pin_led_bleue,LOW);
        tone(pin_buzzer,580,500);
        delay(500);
    }
}
