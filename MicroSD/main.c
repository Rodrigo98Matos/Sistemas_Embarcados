#include <msp430.h> 


/**
 * Rodrigo Matos
 * main.c
 */
#define set_bit(y,bit) (y|=(1<<bit)) //coloca em 1 o bit x da variável Y
#define clr_bit(y,bit) (y&=~(1<<bit)) //coloca em 0 o bit x da variável Y
void SPI_begin(){
    //Definir os pinos dos LEDs como saída
        P1DIR = 0x01;
        P4DIR = 0x80;
        //Definir pino CS como saída
        P1DIR |= 0x02;  //Define o pino P1.2 como saída para ser o CS
        //Configurar os pinos para a comunicação SPI
        P3SEL |= BIT3|BIT4;  //P3.3 MOSI e P3.4 MISO
        P2SEL |= BIT7;          //P2.7 CLk
        P2SEL2 |= BIT7;

        UCA0CTL1 |= USCWRTS;

        UCA0CTL1 |= UCSSEL_2;
        UCA0BR0 = 4;
        UCA0BR1 = 0x00;
        UCA0CTL0 |= UCSYNC;

        UCA0CTL0 |= UCMST;
        UCA0CTL1 &= ~UCSWRST;    //Inicializa USCI
}
unsigned char Enviar(unsigned char m){
    while(!(UCA0IFG & UCTXIFG));
    UCA0TXBUF = m;
    return UCA0TXBUF;
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	/*aloca 512 bytes da RAM para poder escrever em blocos, como necessário para o
	trabalho com o SD card*/
	unsigned char dados[512];
	SPI_begin();

	return 0;
}
