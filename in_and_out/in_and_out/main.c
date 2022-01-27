/*
 * in_and_out.c
 *
 * Created: 04/09/2021 15:52:40
 * Author : Rodrigo Matos
 */ 

#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>

#define set_bit(reg,bit) (reg |= (1<<bit))
#define reset_bit(reg,bit) (reg &= ~(1<<bit))

int main(void)
{
	set_bit(DDRB,5);
    while (1) 
    {
		set_bit(PORTB,5); _delay_ms(500);
		reset_bit(PORTB,5); _delay_ms(500);
    }
}

