#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(21,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Helo, World!");
  digitalWrite(21,1);
  delay(1000);
  digitalWrite(21,0);
  delay(1000);
}