/*******************************************************
Nom ......... : Defi_4.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°4 :
              Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, un son de 440 Hz est émis par le buzzer relié à la broche 12.
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
        tone(pin_buzzer,440,500);    // durée du son 500 ms
    }
}
