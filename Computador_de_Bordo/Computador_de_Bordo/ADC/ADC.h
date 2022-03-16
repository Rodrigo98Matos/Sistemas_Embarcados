#ifndef ADC_H_
#define ADC_H_

#include "def_principais.h"

char convertido = 1;

int ADC_begin();
int lerAnalog(char);
float tensao(char);



#endif /*ADC_H_ */