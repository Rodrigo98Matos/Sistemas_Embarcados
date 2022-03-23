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
	ADMUX = 0b01000000 + pin; // tens�o de refer�ncia AVCC e pin como entrada do ADC (REFS)
	if (conv) {
		set_bit(ADCSRA,ADSC); // iniciar leitura
		conv = 0;
	}
	if (!(ADCSRA & (1<<ADSC))) {
		conv = 1;
		return (ADC);
	}
}

float tensao(unsigned char pin){			//retorna a tens�o em Volts lido na porta anal�gica 
	int leitura = lerAnalog(pin);
	return (5.0*leitura)/1023.00;
}

double R1(unsigned char pin){				//Em um divisor de tens�o com 10000 Ohm no resistor superior, retorna o valor ohmico
	float Vadc = tensao(pin);
	return (10000*5.0-Vadc*10000)/Vadc;
}

double R2(unsigned char pin){				//Em um divisor de tens�o com 10000 Ohm no resistor superior, retorna o valor ohmico
	float Vadc = tensao(pin);
	return Vadc * (10000/(5.0-Vadc));
}

double ntc_10k(unsigned char pin){
	double	Rd0 = 10000.0,                          //Resistencia do NTC a 25�C
			T0 = 298.15,                            //25�C em Kelvin
			T1 = 273.15,                            //Temperatura de refer�ncia 1
			T2 = 373.15,                            //Temperatura de refer�cia 2
			RT1 = 35563.0,                          //Reseist�ncia do NTC em T1
			RT2 = 549.4,                            //Resist�ncia do NTC em T2
			beta = log(RT1/RT2)/((1/T1)-(1/T2)),    //Constante do termistor
			Rinf = Rd0*exp(-beta/T0),               //Par�metro de resist�ncia
			Rntc = R1(pin),							//Resistencia do NTC
			temp;									
	temp = beta/log(Rntc/Rinf);				//Temperatura em Kelvin
	return temp - 273.15;					//Retorna Temperatura em Celsius
}