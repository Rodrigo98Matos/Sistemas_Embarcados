#ifndef TWI_H_
#define TWI_H_
#include "def_principais.h"
#include <Adafruit_Sensor.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h> //INCLUSÃO DE BIBLIOTECA

typedef struct{
 int16_t x, y, z;
} HMC5883L;

typedef struct{
 int16_t ax, ay, az, t, gx, gy, gz;
} MPU6050;

void HMC5883L_config();
void HMC5883L_read(HMC5883L *mag);
void MPU6050_config();
MPU6050 MPU6050_read();



#endif
