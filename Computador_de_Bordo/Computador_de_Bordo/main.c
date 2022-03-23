/*
 * Computador_de_Bordo.c
 *
 * Created: 12/02/2022 22:25:26
 * Author : Rodrigo Matos
 */ 

#include "def_principais.h"
#include "USART.h"
#include "ADC.h"

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