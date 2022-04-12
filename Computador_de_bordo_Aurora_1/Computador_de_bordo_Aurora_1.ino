/*
 * Computador_de_Bordo.c
 *
 * Created: 12/02/2022 22:25:26
 * Author : Rodrigo Matos
 */ 

#include "def_principais.h"
#include "ADC.h"
#include "TWI.h"
#include <SoftwareSerial.h>

SoftwareSerial esp01(4,5);
Adafruit_BMP280 bmp; //OBJETO DO TIPO Adafruit_BMP280 (I2C)
MechaQMC5883 bussola;

void setup() {
  Serial.begin(9600);
  MPU6050_config();
  bussola.init();
  
}

void loop() {
  int mag_x, mag_y, mag_z;
//  MPU6050 atitude;

//  atitude = MPU6050_read();
  bussola.read(&mag_x,&mag_y,&mag_z);
  float barometro = bmp.readPressure()/101325.00;
  float b1 = tensao(A1);
  float b2 = bat2(A6,b1);
  double t_b1 = ntc_10k(A2);
  double t_b2 = ntc_10k(A3);
//  Serial.println("{\"Magnetometro\":["+String(mag.x)+String(mag.y)+String(mag.z)+"],"+"\"Acelerometro\":["+String(atitude.ax)+String(atitude.ay)
//                 +String(atitude.az)+"],"+"\"Giroscopio\":["+String(atitude.gx)+String(atitude.gy)+String(atitude.gz)+"],"+"\"Temperatura\":"
//                 +String(atitude.t)+"\"Pressao\":"+String(barometro));
Serial.println("{\"Magnetometro\":["+String(mag_x)+String(mag_y)+String(mag_z)+"],"+"\"Pressao\":"+String(barometro));
//  esp01.println("\"Acelerometro\":["+String(atitude.ax)+","+String(atitude.ay)+","
//                 +String(atitude.az)+"],"+"\"Giroscopio\":["+String(atitude.gx)+String(atitude.gy)+String(atitude.gz)+"],"+"\"Temperatura\":"
//                 +String(atitude.t));
    _delay_ms(1000);

}
