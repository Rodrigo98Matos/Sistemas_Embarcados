#ifndef TWI_H_
#define TWI_H_
#include "def_principais.h"

typedef struct{
 int16_t x, y, z;
} HMC5883L;

typedef struct{
 int16_t ax, ay, az, t, gx, gy, gz;
} MPU6050;




#endif
