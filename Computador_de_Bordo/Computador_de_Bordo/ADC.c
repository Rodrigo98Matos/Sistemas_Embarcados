/*
 * ADC.c
 *
 * Created: 12/03/2022 14:35:26
 * Author : Rodrigo Matos
 */ 

#include "ADC.h"


/* Replace with your library code */
void ADC_begin()
{
	ADCSRA = 0b10000111; // Enable ADC, prescaler = 128
	conv = 1;
}

int lerAnalog(unsigned char pin){//pin 0 a 7
	ADMUX = 0b01000000 + pin; // tensão de referência AVCC e pin como entrada do ADC (REFS)
	if (conv) {
		set_bit(ADCSRA,ADSC); // iniciar leitura
		conv = 0;
	}
	if (!(ADCSRA & (1<<ADSC))) {
		conv = 1;
		return (ADC);
	}
}

float tensao(char pin){
	int leitura = lerAnalog(pin);
	return (5.0*leitura)/1023.00;
}