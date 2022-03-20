/*
 * Computador_de_Bordo.c
 *
 * Created: 12/02/2022 22:25:26
 * Author : Rodrigo Matos
 */ 

#include "def_principais.h"
#include "USART.h"
#include "ADC.h"


double ntc_10k(char pin){
	double  R2 = 10000.0,                 //Resistor inferior
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
	Rntc = (R2*5.0-Vadc*R2)/Vadc;
	temp = beta/log(Rntc/Rinf);				//Temperatura em Kelvin
	return temp - 273.15;					//Retorna Temperatura em Celsius
}

double bat2(unsigned char pin, double b1){
	return (tensao(pin)/(0.5))-b1; //tensão/(R1/(R1+R2)) retorna a tensão de entrada do divisor de tensão menos a tensão da primeira bateria
}

int main(void)
{
	ADC_begin();
	USART_Inic(9600);
    while (1) 
    {
		char t1[] = "Temperatura:  ";
		char b1[] = "\tBateria1:  ";
		char b2[] = "\tBateria2:  ";
		char fim[] = "\n";
		double bateria1 = tensao(1);
		escreve_USART(t1);
		envia_double(ntc_10k(3));
		escreve_USART(b1);	envia_double(bateria1);
		escreve_USART(b2);	envia_double(bat2(6, bateria1));
		escreve_USART(fim);
		_delay_ms(1000);
    }
	return 0;
}

