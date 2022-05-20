#include <Arduino.h>

#include <ESP32Servo.h>

#define servoPin 13

Servo myservo;
int pos = 90;



void setup() {
  // put your setup code here, to run once:
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lux = analogRead(12) - analogRead(13);
  if (lux < -10 && pos >=0){
    pos--;
  }else if(lux > 10 && pos <=180){
    pos++;
  }

}