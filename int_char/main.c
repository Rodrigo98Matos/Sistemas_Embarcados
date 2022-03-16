/*
    Autor: Rodrigo Matos
    27/02/2022

 */
#define F_CPU 16000000UL //define a frequência do microcontrolador - 16MHz
#include <avr/io.h>
#include <util/delay.h>

//Definições de macros para o trabalho com bits
#define set_bit(y,bit) (y|=(1<<bit))
#define clr_bit(y,bit) (y&=~(1<<bit))
#define cpl_bit(y,bit) (y^=(1<<bit))
#define tst_bit(y,bit) (y&(1<<bit))

#define BAUD 9600 //taxa de 9600 bps MYUBRR
#define MYUBRR F_CPU/16/BAUD-1
#define tam_vetor 5 //número de digitos individuais para a conversão por ident_num()
#define conv_ascii 48 /*48 se ident_num() deve retornar um número no formato ASCII
(0 para formato normal)*/
void USART_Inic(unsigned int ubbr0);
void USART_Transmite(unsigned char dado);
unsigned char USART_Recebe();
void escreve_USART(char *c);
void escreve_USART_Flash(const char *c);
void ident_num(unsigned int valor, unsigned char *disp);

char primeira_msg[] = "Transmitindo primeira mensagem para o computador! Digite agora - Para sair <*>\n\0";

int main(void)
{

    // Insert code
    UBRR0H = (unsigned char)(MYUBRR>>8); //Ajusta a taxa de transmissão
    UBRR0L = (unsigned char)MYUBRR;
    UCSR0A = 0;//desabilitar velocidade dupla (no Arduino é habilitado por padrão)
    UCSR0B = (1<<RXEN0)|(1<<TXEN0); //Habilita a transmissão e a recepção
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);/*modo assíncrono, 8 bits de dados, 1 bit de parada, sem paridade*/

    escreve_USART_Flash(&primeira_msg);

    do
    {
        dado_recebido= USART_Recebe(); //recebe caractere
        USART_Transmite('-');
        USART_Transmite('>');
        USART_Transmite(dado_recebido); //envia o caractere recebido
    }while(dado_recebido!='*');
    //escreve_USART_Flash(segunda_msg);

    while(1){

    }
    ;

    return 0;
}

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
void escreve_USART_Flash(const char *c) //escreve String (Flash)
{
for (;pgm_read_byte(&(*c))!=0;c++) USART_Transmite(pgm_read_byte(&(*c)));
}
//------------------------------------------------------------------------------------
//Conversão de um número em seus digitos individuais
//------------------------------------------------------------------------------------
void ident_num(unsigned int valor, unsigned char *disp)
{
unsigned char n;
for(n=0; n<tam_vetor; n++)
disp[n] = 0 + conv_ascii; //limpa vetor para armazenagem dos digitos
do
{
*disp = (valor%10) + conv_ascii; //pega o resto da divisão por 10
valor /=10; //pega o inteiro da divisão por 10
disp++;
}while (valor!=0);
}
//-----------------------------------------------------------------------------------
