#include <Arduino.h>


#define servoPin 14

int pos = 90;
void servo(int g, int porta){
  //g é um número inteiro entre 0 e 1024
  int duty_cycle = (2000-(g/0.512))+500;
  for(int i =0;i<=10;i++){
    digitalWrite(porta,1);delayMicroseconds(duty_cycle);
    digitalWrite(porta,0);delayMicroseconds(20000-duty_cycle);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servoPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int p = 0;p<=1024;p++){
    servo(p,servoPin);
    delay(500);
  }
  for (int p = 1024;p>=0;p--){
    servo(p,servoPin);
    delay(500);
  }
  // int lux = analogRead(12) - analogRead(13);
  // if (lux < -10 && pos <=180){
  //   pos--;
  //   myservo.write(pos);
  // }else if(lux > 10 && pos  >=0){
  //   pos++;
  //   myservo.write(pos);
  // }
  // int ldr1;
  // int ldr2;
  // ldr1 = analogRead(33);
  // ldr2 = analogRead(13);
  // //Serial.print(ldr1);Serial.print("\t");Serial.println(ldr2);
  // if(-10<(ldr1-ldr2)<10){
  //   if ((ldr1>ldr2)&&(pos>0)){
  //     pos--;
  //   } else if(pos<1024){
  //     pos++;
  //   }
  //   servo(pos,servoPin);
  // }
  delay(50);
}