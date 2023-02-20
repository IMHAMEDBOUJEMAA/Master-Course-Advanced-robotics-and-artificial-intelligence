#include "SPI.h"
#define LED 4
#define ipbutton 2
int buttonvalue;
int x;
void setup () {
 pinMode(ipbutton,INPUT);
 pinMode(LED,OUTPUT);

 SPI.begin();
 SPI.setClockDivider(SPI_CLOCK_DIV8);
 digitalWrite(SS, HIGH);
}
void loop() {
 byte Mastersend, Mastereceive;
 buttonvalue = digitalRead(ipbutton);
 if(buttonvalue ==1) { x = 1; }
 else { x = 0; }

 digitalWrite(SS, LOW);
 Mastersend = x;
 Mastereceive = SPI.transfer(Mastersend);

 if(Mastereceive == 1) { digitalWrite(LED,HIGH); }
 else { digitalWrite(LED,LOW); }
 delay(100);
}