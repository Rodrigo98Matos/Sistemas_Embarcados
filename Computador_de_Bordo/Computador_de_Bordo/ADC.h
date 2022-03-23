#ifndef ADC_H_
#define ADC_H_

#include "def_principais.h"

unsigned int conv;

void ADC_begin();
int lerAnalog(unsigned char);
float tensao(unsigned char);
double R1(unsigned char pin);
double R2(unsigned char pin);
double ntc_10k(unsigned char pin);



#endif /*ADC_H_ */