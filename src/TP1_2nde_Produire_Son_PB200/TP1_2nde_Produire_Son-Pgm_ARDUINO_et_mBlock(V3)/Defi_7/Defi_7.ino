/*******************************************************
Nom ......... : Defi_7.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
          défi n°7 :
                Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, je joue une mélodie bien connue.
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/


const int pin_bp_bleu = 5;
const int pin_buzzer = 12;

void setup(){
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    if(digitalRead(pin_bp_bleu) == HIGH){
        tone(pin_buzzer,262,500);
        delay(500);
        tone(pin_buzzer,262,500);
        delay(500);
        tone(pin_buzzer,294,500);
        delay(500);
        tone(pin_buzzer,262,500);
        delay(500);
        tone(pin_buzzer,349,500);
        delay(500);
        tone(pin_buzzer,330,500);
        delay(500);
        tone(pin_buzzer,262,500);
        delay(500);
        tone(pin_buzzer,262,500);
        delay(500);
        tone(pin_buzzer,294,500);
        delay(500);
        tone(pin_buzzer,262,500);
        delay(500);
        tone(pin_buzzer,392,500);
        delay(500);
        tone(pin_buzzer,349,500);
        delay(2000);
    }
}
