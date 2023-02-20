#include <Wire.h>
void setup()
{
Wire.begin(); // Rejoindre le bus I2C (Pas besoin d’adresse pour le maitre)
}
void loop()
{
//contenu du programme
Wire.beginTransmission(4); // Envoyer vers device #4
Wire.write(HIGH); // Envoi un 1
Wire.endTransmission(); // Arrêter la transmission
delay(1000); // Attendre 1s
Wire.beginTransmission(4); // Envoyer vers device #4
Wire.write(LOW); // Envoi un 0
Wire.endTransmission(); // Arrêter la transmission
delay(2000); // Attendre 2s
}