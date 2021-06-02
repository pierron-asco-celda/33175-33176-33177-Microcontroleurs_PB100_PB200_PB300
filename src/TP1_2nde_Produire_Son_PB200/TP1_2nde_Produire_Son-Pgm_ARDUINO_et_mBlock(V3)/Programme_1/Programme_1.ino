/*******************************************************
Nom ......... : Programme_1.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
        Programme n°1 :
                J’entends un son de 440 Hz après avoir téléversé le programme.
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/

const int pin_buzzer = 12;

void setup(){
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    tone(pin_buzzer,440);
}
