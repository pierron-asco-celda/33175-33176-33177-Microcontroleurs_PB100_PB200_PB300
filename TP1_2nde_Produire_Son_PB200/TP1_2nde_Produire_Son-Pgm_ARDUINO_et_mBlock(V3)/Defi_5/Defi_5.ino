/*******************************************************
Nom ......... : Defi_5.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
        défi n°5 :
                Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, j’entends la sirène de la Police !
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
    if( digitalRead(pin_bp_bleu) == HIGH )
    {
        tone(pin_buzzer,435,500);
        delay(500);
        tone(pin_buzzer,580,500);
        delay(500);
    }
}
