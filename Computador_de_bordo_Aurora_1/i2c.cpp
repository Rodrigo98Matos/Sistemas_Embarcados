#include "def_principais.h"

void HMC5883L::initialize() {
    // write CONFIG_A register
    I2Cdev::writeByte(devAddr, HMC5883L_RA_CONFIG_A,
        (HMC5883L_AVERAGING_8 << (HMC5883L_CRA_AVERAGE_BIT - HMC5883L_CRA_AVERAGE_LENGTH + 1)) |
        (HMC5883L_RATE_15     << (HMC5883L_CRA_RATE_BIT - HMC5883L_CRA_RATE_LENGTH + 1)) |
        (HMC5883L_BIAS_NORMAL << (HMC5883L_CRA_BIAS_BIT - HMC5883L_CRA_BIAS_LENGTH + 1)));

    // write CONFIG_B register
    setGain(HMC5883L_GAIN_1090);
    
    // write MODE register
    setMode(HMC5883L_MODE_SINGLE);
}
void HMC5883L::getHeading(int16_t *x, int16_t *y, int16_t *z) {
    I2Cdev::readBytes(devAddr, HMC5883L_RA_DATAX_H, 6, buffer);
    if (mode == HMC5883L_MODE_SINGLE) I2Cdev::writeByte(devAddr, HMC5883L_RA_MODE, HMC5883L_MODE_SINGLE << (HMC5883L_MODEREG_BIT - HMC5883L_MODEREG_LENGTH + 1));
    *x = (((int16_t)buffer[0]) << 8) | buffer[1];
    *z = (((int16_t)buffer[2]) << 8) | buffer[3];
    *y = (((int16_t)buffer[4]) << 8) | buffer[5];
}
