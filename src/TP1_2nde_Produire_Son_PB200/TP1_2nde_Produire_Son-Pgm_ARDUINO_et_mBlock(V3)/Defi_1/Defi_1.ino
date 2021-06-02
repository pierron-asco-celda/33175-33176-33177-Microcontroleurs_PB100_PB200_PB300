/*******************************************************
Nom ......... : Defi_1.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB200 : Sons et lumières
Role ........ : Programme pour maquette PB200
      défi n°1 :
              Lorsque j’appuie sur le bouton poussoir (BP) jaune relié à la broche 3 de la carte ArduinoTM , la led jaune reliée à la boche 10 s’allume.
              Lorsque je n’appuie plus sur le BP, la led s’éteint.
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/


const int pin_led_jaune = 10;
const int pin_bp_jaune = 3;


void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_led_jaune,OUTPUT);
}

void loop(){
    if(digitalRead(pin_bp_jaune)==HIGH)
    {
        digitalWrite(pin_led_jaune,HIGH);
    }
    else
    {
        digitalWrite(pin_led_jaune,LOW);
    }
}
