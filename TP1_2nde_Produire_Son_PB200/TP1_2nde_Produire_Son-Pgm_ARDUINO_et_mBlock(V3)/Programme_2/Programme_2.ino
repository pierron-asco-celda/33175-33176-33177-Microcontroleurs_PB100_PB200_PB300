/*******************************************************
Nom ......... : Programme_2.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
        Programme n°2 :
                J’entends la sirène des pompiers indéfiniment !
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
    tone(pin_buzzer,435);
    delay(500);
    tone(pin_buzzer,488);
    delay(500);
}
