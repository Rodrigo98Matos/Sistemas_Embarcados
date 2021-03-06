#include "TWI.h"

void HMC5883L_config() {
    // write CONFIG_A register
    Wire.begin();
    compass.setScale(1.3);
    compass.setMeasurementMode(MEASUREMENT_CONTINUOUS);
    
    
    Wire.beginTransmission(0x1E);
    Wire.write(0x00);
    Wire.write((0x03 << 5)|(0x04 << 2));

    // write CONFIG_B register
    Wire.write(0x01);
    Wire.write(0x00);
    Wire.endTransmission();
}
MagnetometerScaled HMC5883L_read() {  
  return compass.readScaledAxis();
}
MPU6050 MPU6050_read(){
  MPU6050 mpu;
  //Começa uma transmissão com o sensor
    Wire.beginTransmission(0x68);
  
    //Enfilera os bytes a ser transmitidos para o sensor
    //Começando com o registor 0x3B
    Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  
    //Finaliza e transmite os dados para o sensor. O false fará com que seja enviado uma mensagem 
    //de restart e o barramento não será liberado
    Wire.endTransmission(false);
    
    //Solicita os dados do sensor, solicitando 14 bytes, o true fará com que o barramento seja liberado após a solicitação 
    //(o valor padrão deste parâmetro é true)
    Wire.requestFrom(0x68, 14, true);  
    
    //Armazena o valor dos sensores nas variaveis correspondentes
    mpu.ax = Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  
    mpu.ay = Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)  
    mpu.az = Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)  
   
    mpu.t = Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  
    mpu.gx = Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)     
    mpu.gy = Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    mpu.gz = Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
    return mpu;
}
