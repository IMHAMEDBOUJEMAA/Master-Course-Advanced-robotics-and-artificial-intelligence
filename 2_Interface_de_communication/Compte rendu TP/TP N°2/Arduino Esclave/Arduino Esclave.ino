#include <Wire.h> // Librairie pour la communication I2C
const int L1 = 2; // broche 2 du microcontrôleur se nomme maintenant : L1
void setup()
{
Wire.begin(4); // Rejoindre le bus à l'adresse #4
Wire.onReceive(receiveEvent); // Préparer une fonction spécifique à la réception de
Serial.begin(9600); // Démarrer la liaison série avec le PC
pinMode(L1,OUTPUT); // L1 est une broche de sortie
}
void loop()
{
delay(1000);
}
// Fonction qui s’exécute si quelque chose est présent sur l’interface
void receiveEvent(int howMany)
{
int x = Wire.read(); // recevoir un chiffre
Serial.println(x); // afficher ce chiffre sur l'interface série
if(x == 1)
{
digitalWrite(L1,HIGH); // allumer L1
}
if(x == 0)
{
digitalWrite(L1,LOW); // éteindre L1
}
}
