/*
 * Reg_deslocamento_sn74hc595n.c
 *
 * Created: 18/02/2022 19:03:25
 * Author : Rodrigo Matos
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define set_bit(y,bit) (y|=(1<<bit))
#define clr_bit(y,bit) (y&=~(1<<bit))
#define cpl_bit(y,bit) (y^=(1<<bit))
#define tst_bit(y,bit) (y&(1<<bit))
#define D 3			// ( DS [S1] no 14 do 74HC595
#define SCK 4		//  ST_CP [RCK] no 12 do 74HC595
#define CLK 5		//  SH_CP [SCK] no 11 do 74HC595
void pulso_CLK();
void pulso_SCK();
void escreve(unsigned int c);
int main(void){
	DDRB = 0b00111000; //pinos PB0:2 como saídas
	PORTB = 0b11000111; //zera saídas
    while (1){
		for(unsigned int j = 0; j<16;j++){
			escreve(j);	_delay_ms(1000);
		}
    }
}
void escreve(unsigned int c){
	unsigned char Dados[] = {0b11111100,0b01100000,0b11011010,0b11110011,0b01100110,0b10110111,0b10111110,0b11100001,0b11111110,0b11110110,0b11101110,0b00111110,0b10011100,0b01111010,0b10011110,0b10001110};
	for(unsigned char i=0;i!=8;i++)	{
		if(!(tst_bit(Dados[c],i))) //se o bit for 1, ativa o pino de DADOS
			set_bit(PORTB,D);
		else //se não, o zera
			clr_bit(PORTB,D);
		pulso_CLK();
	}
	pulso_SCK();
}
void pulso_CLK(){set_bit(PORTB,CLK); clr_bit(PORTB,CLK);}
void pulso_SCK(){set_bit(PORTB,SCK); clr_bit(PORTB,SCK);}