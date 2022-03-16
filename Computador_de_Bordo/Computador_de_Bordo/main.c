/*
 * Computador_de_Bordo.c
 *
 * Created: 12/02/2022 22:25:26
 * Author : Rodrigo Matos
 */ 

#include "def_principais.h"
#include "USART\USART.h"
#include "ADC\ADC.h"


void ntc_10k(char pin){
	double  Rsup = 10000.0,                 //Resistor superior
	Rd0 = 10000.0,                          //Resistencia do NTC a 25°C
	T0 = 298.15,                            //25°C em Kelvin
	T1 = 273.15,                            //Temperatura de referência 1
	T2 = 373.15,                            //Temperatura de referêcia 2
	RT1 = 35563.0,                          //Reseistência do NTC em T1
	RT2 = 549.4,                            //Resistência do NTC em T2
	beta = log(RT1/RT2)/((1/T1)-(1/T2)),    //Constante do termistor
	Rinf = Rd0*exp(-beta/T0),               //Parâmetro de resistência
	Vadc = 0.0,                             //Tensão lida pelo ADC
	Rntc = 0.0,
	temp;									//Resistencia do NTC

	Vadc = tensao(pin);
	Rntc = (Rsup*Vadc)/(5.0-Vadc);
	temp = beta/log(Rntc/Rinf);				//Temperatura em Kelvin
	return temp - 273.15;					//Retorna Temperatura em Celsius
}

double bat2(unsigned char pin){
	return tensao(pin)/(330/(330+330));
}

int main(void)
{
	ADC_begin();
	USART_Inic(9600);
    while (1) 
    {
		char t1[] = "Temperatura:\t",
			 b1[] = "Bateria1:\t",
			 b2[] = "Bateria2:\t",
			 fim[] = "\n";
		escreve_USART(&t1);
		envia_double(ntc_10k(3));
		escreve_USART(&b1);	envia_double(tensao(1));
		escreve_USART(&b2);	envia_double(bat2(6));
		escreve_USART(&fim);
		_delay_ms(1000);
    }
}

