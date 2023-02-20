// Moteur 1
int IN1 = 5;
int IN2 = 6;
// Moteur 2
int IN3 = 10;
int IN4 = 11;
void setup() {
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT); 
}
void loop() {
 // Marche Avant
 digitalWrite(IN2, 1);
 digitalWrite(IN1, 0);
 digitalWrite(IN3, 1);
 digitalWrite(IN4, 0);
 // Attente 2s
  delay(2000) ;
 // Arrêt des moteurs
 digitalWrite(IN2, 0);
 digitalWrite(IN1, 0);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 0);
 // Attente 1s
delay(1000) ;
 // Marche arrière
 digitalWrite(IN2, 0);
 digitalWrite(IN1, 1);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 1);
 // Attente 2s
delay(2000);
 // Arrêt des moteurs
 digitalWrite(IN2, 0);
 digitalWrite(IN1, 0);
 digitalWrite(IN3, 0);
 digitalWrite(IN4, 0);
 // Attente 1s
 delay(1000);
}