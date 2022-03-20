#ifndef ADC_H_
#define ADC_H_

#include "def_principais.h"

unsigned int conv;

void ADC_begin();
int lerAnalog(unsigned char);
float tensao(char);



#endif /*ADC_H_ */