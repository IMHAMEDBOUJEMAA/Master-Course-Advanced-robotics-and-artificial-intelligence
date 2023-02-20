// déclaration de l'afficheur LCD avec I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


int in1 = 9;
int in2 = 10;
int in3 = 11;
int in4 = 6;

//int M_A = 4;
//int marche_button = 0;

int speedv1 = 0;
int speedv2 = 0;

int sondetemp = A0;
int temp_hors_norme = 70;
int tempMax = 69; 
int tempMin = 40; 
int voltage1LCD;
int voltage2LCD;
int lcd_marche = 2;
int lcd_arret = 3;

void setup(){
  
//pinMode(M_A,INPUT);

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(lcd_marche,OUTPUT);
pinMode(lcd_arret,OUTPUT);

pinMode(sondetemp,INPUT);

lcd.init();                      
lcd.init();                  
lcd.backlight();
Serial.begin(9600);

}
void loop(){
//marche_button = digitalRead(M_A);

  int valeur_brute = analogRead(A0);
  int temperature_celcius = valeur_brute * (5.0 / 1023.0 * 100.0);
  analogWrite(in2,0);
  analogWrite(in4,0);
digitalWrite(lcd_marche,LOW);  
digitalWrite(lcd_arret,LOW);

if(temperature_celcius < tempMin) 
{
  digitalWrite(lcd_marche,HIGH); 
speedv1 = 0;
speedv2 = 0;
voltage1LCD = 0;
voltage2LCD = 0;

analogWrite(in1,speedv1);
analogWrite(in3,speedv2);

lcd.print("TEMP_CEL=");
lcd.print(temperature_celcius); 
lcd.setCursor(0,1); 
lcd.print("VENTILLATEUR1=");
lcd.print(voltage1LCD); 
lcd.print("V");
delay(1000);
lcd.clear();
lcd.print("TEMP_CEL=");
lcd.print(temperature_celcius); 
lcd.setCursor(0,1); 
lcd.print("VENTILLATEUR2=");
lcd.print(voltage2LCD); 
lcd.print("V");
delay(1000);
lcd.clear();
lcd.print("TEMPERATURE SOUS ");
lcd.setCursor(3,1);
lcd.print("CONTROLE ");
delay(1000);
lcd.clear();
}


if((temperature_celcius >= tempMin) && (temperature_celcius <= tempMax)) 
{
  digitalWrite(lcd_marche,HIGH); 
voltage1LCD = map(temperature_celcius, tempMin, tempMax, 1, 10);
voltage2LCD = map(temperature_celcius, tempMin, tempMax, 1, 10);
speedv1 = voltage1LCD*25.5;
speedv2 = voltage2LCD*25.5;
analogWrite(in1,speedv1);
analogWrite(in3,speedv2);

lcd.print("TEMP_CEL=");
lcd.print(temperature_celcius); 
lcd.setCursor(0,1); 
lcd.print("VENTILLATEUR1=");
lcd.print(voltage1LCD); 
lcd.print("V");
delay(1000);
lcd.clear();
lcd.print("TEMP_CEL=");
lcd.print(temperature_celcius); 
lcd.setCursor(0,1); 
lcd.print("VENTILLATEUR2=");
lcd.print(voltage2LCD); 
lcd.print("V");
delay(1000);
lcd.clear();
lcd.print("EN COURS DE ");
lcd.setCursor(0,1);
lcd.print("REFROIDISSEMENT ");
delay(1000);
lcd.clear();
}
if(temperature_celcius >= temp_hors_norme)
{
analogWrite(in1,0);
analogWrite(in3,0);  
  digitalWrite(lcd_marche,LOW);
  digitalWrite(lcd_arret,HIGH);
  delay(200);
  digitalWrite(lcd_arret,LOW);
  delay(200);
}
}



