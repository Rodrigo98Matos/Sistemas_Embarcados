/*
 * Sonar.c
 *
 * Created: 12/01/2022 10:22:22
 * Author : Rodrigo Matos
 */ 
#include "def_principais.h"

int digito[10] = {
	0x3F,  //DIGITO 0
	0x06,  //DIGITO 1
	0x5B,  //DIGITO 2
	0x4F,  //DIGITO 3
	0x66,  //DIGITO 4
	0x6D,  //DIGITO 5
	0x7D,  //DIGITO 6
	0x07,  //DIGITO 7
	0x7F,  //DIGITO 8
	0x6F   //DIGITO 9
};

//Rotinas para display de 7 segmentos
void PulsaEn() {
	set_bit(PORTD,latchPin);
	clr_bit(PORTD,latchPin);
}

void PulsaClock() {
	set_bit(PORTD,clockPin);
	clr_bit(PORTD,clockPin);
}

void escreve(int valor) {
	for (int i = 0; i < 8; i++) {
		digitalWrite(dataPin, valor & 0x80);
		PulsaClock();
		valor <<= 1;
	}
	PulsaEn();
}

int main(void){
    /* Replace with your application code */
	set_bit(DDRD,latchPin);
	set_bit(DDRD,dataPin);
	set_bit(DDRD,clockPin);
	DDRC = 0b00000111;
    while (1){
		PORTC = 0b00000110;
		for (int i = 0; i <= 9; i++){
			escreve(digito[i]);
			_delay_ms(500);
		}
    }
}

