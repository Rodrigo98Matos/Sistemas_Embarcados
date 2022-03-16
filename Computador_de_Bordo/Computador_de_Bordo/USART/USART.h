#ifndef _USART_H
#define _USART_H
#include "def_principais.h"
#define MYUBRR F_CPU/16/BAUD-1
#define tam 8 //número de digitos individuais para a conversão por ident_num()
void USART_Inic(unsigned int ubbr0);
void USART_Transmite(unsigned char dado);
unsigned char USART_Recebe();
void escreve_USART(char *c);
void escreve_USART_Flash(const char *c);
void envia_int(unsigned int valor);
void envia_double(double n);
#endif