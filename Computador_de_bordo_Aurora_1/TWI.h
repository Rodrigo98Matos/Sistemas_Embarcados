#ifndef TWI_H_
#define TWI_H_
#include "def_principais.h"
#include <Adafruit_Sensor.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h> //INCLUSÃO DE BIBLIOTECA
#include <HMC5883L.h>

typedef struct{
 int x, y, z;
} MAG;

typedef struct{
 int16_t ax, ay, az, t, gx, gy, gz;
} MPU6050;

HMC5883L compass;
int error = 0;

void HMC5883L_config();
void HMC5883L_read(MAG *mag);
void MPU6050_config();
MPU6050 MPU6050_read();



#endif
