/*
 * USART.c
 *
 * Created: 15/03/2022 15:29:25
 * Author : Rodrigo Matos
 */ 

#include "def_principais.h"


#include "USART.h"
//------------------------------------------------------------------------------------
void USART_Inic(unsigned int BAUD)
{
	unsigned int ubrr0 = F_CPU/16/BAUD-1;
	UBRR0H = (unsigned char)(ubrr0>>8); //Ajusta a taxa de transmissão
	UBRR0L = (unsigned char)ubrr0;
	UCSR0A = 0;//desabilitar velocidade dupla (no Arduino é habilitado por padrão)
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); //Habilita a transmissão e a recepção
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);/*modo assíncrono, 8 bits de dados, 1 bit de
	parada, sem paridade*/
}
//------------------------------------------------------------------------------------
void USART_Transmite(unsigned char dado)
{
	while (!( UCSR0A & (1<<UDRE0)) ); //espera o dado ser enviado
	UDR0 = dado; //envia o dado
}
//------------------------------------------------------------------------------------
unsigned char USART_Recebe()
{
	while (!(UCSR0A & (1<<RXC0))); //espera o dado ser recebido
	return UDR0; //retorna o dado recebido
}
//------------------------------------------------------------------------------------
void escreve_USART(char *c) //escreve String (RAM)
{
	for (; *c!=0;c++) USART_Transmite(*c);
}
//------------------------------------------------------------------------------------
//Conversão de um número em seus digitos individuais
//------------------------------------------------------------------------------------
void envia_int(unsigned int valor)
{
	unsigned char disp[tam];
	unsigned char n;
	for(n=0; n<tam; n++)
	disp[n] = 0; //limpa vetor para armazenagem dos digitos
	n=0;
	do
	{
		disp[n] = (valor%10) + '0'; //pega o resto da divisão por 10
		valor /=10; //pega o inteiro da divisão por 10
		n++;
	}while (valor!=0);
	for(;n!=0;n--){
		USART_Transmite(disp[n-1]);
	}
}

void envia_double(double n){
	int i;
	int dec;
	i = n/1;
	dec = n*100;dec = dec%100;
	envia_int(i);
	USART_Transmite('.');
	envia_int(dec);
}

