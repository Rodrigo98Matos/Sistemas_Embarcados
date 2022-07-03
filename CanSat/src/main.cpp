#include <Arduino.h>

#define fator 16.06 //permite que o PWM varie somente entre 0 e 255
#define PinoVelocidade 4 //Pino que define a velocidade do motor e está ligado ao pino 1 do L293D e a Digital 3 do Arduino 
#define Entrada1 15 //Entrada do terminal do motor ligado ao pino 2 do L293D e a Digital 2 do Arduino 
#define Entrada2 16 //Entrada do terminal do motor ligado ao pino 7 do L293D e a Digital 7 do Arduino 

#define ldr1 34
#define ldr2 35
int valorldr;

void setup( ) 
{  
    pinMode(PinoVelocidade, OUTPUT); 
    pinMode(Entrada1, OUTPUT); 
    pinMode(Entrada2, OUTPUT);
} 

void loop( ) 
{ 
  valorldr = analogRead(ldr1)-analogRead(ldr2);
  int velocidade = valorldr / fator;
  if (velocidade > 0) { 
    digitalWrite(Entrada1, HIGH); 
    digitalWrite(Entrada2, LOW);
    analogWrite(PinoVelocidade, velocidade); 
  } else if (velocidade < 0) {
    digitalWrite(Entrada1, LOW); 
    digitalWrite(Entrada2, HIGH);
    velocidade*=-1;
    analogWrite(PinoVelocidade, velocidade);  
  } else if (velocidade == 0) { 
    digitalWrite(Entrada1, LOW); 
    digitalWrite(Entrada2, LOW);
    analogWrite(PinoVelocidade, velocidade);  
  }
  delay (250);
}