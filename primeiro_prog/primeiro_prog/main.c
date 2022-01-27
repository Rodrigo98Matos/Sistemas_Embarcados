/*
 * primeiro_prog.c
 *
 * Created: 03/09/2021 12:47:01
 * Author : Rodrigo Matos
 */ 

#include <avr/io.h>
#include <util/twi.h> //definições para o uso da interface i2c
//-------------------------------------------------------------------------------- //
// DS1307 - RTC com LCD 16 x 2 utilizando I2C //
//--------------------------------------------------------------------------------//
#include "def_principais.h"
#include "LCD.h"
extern unsigned char flag_pontos, cont;
...
//------------------------------------------------------------------------------------
// Definições para o uso da comunicação I2C
//------------------------------------------------------------------------------------
#define start_bit() TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN)
#define stop_bit() TWCR = (1<<TWINT)|(1<<TWEN)| (1<<TWSTO)
#define espera_envio() while (!(TWCR & (1<<TWINT)))
#define envia_byte() TWCR = (1<<TWINT) | (1<<TWEN)
#define recebe_byte() TWCR = (1<<TWINT) | (1<<TWEN)
#define espera_recebimento() while (!(TWCR & (1<<TWINT)))
#define recebe_byte_ret_nack() TWCR = (1<<TWINT) | (1<<TWEN)
//A rotina de tratamento de erro é por conta do programador e da sua lógica de programação
#define teste_envio_start() if((TWSR & 0xF8) != TW_START)
trata_erro();
#define teste_envio_end_escrita() if((TWSR & 0xF8) != TW_MT_SLA_ACK)
trata_erro();
#define teste_envio_dado() if((TWSR & 0xF8) != TW_MT_DATA_ACK)
trata_erro();
#define teste_envio_restart() if((TWSR & 0xF8) != TW_REP_START)
trata_erro();
#define teste_envio_end_leitura() if((TWSR & 0xF8) != TW_MR_SLA_ACK)
trata_erro();
#define teste_recebe_byte_ret_nack() if((TWSR & 0xF8) != TW_MR_DATA_NACK)
trata_erro();
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//Sub-rotina para ler apenas um byte do barramento I2C do DS1307
//-----------------------------------------------------------------------------------
unsigned char le_RTC(unsigned char endereco)
{
	start_bit();
	espera_envio();
	teste_envio_start();
	TWDR = 0xD0; //carrega o endereço para acesso do DS1307 (bit0 = 0, escrita)
	//para outro CI basta trocar este endereço
	envia_byte();
	espera_envio();
	teste_envio_end_escrita();
	TWDR = endereco; //ajuste do ponteiro de endereço para a leitura do DS1307
	envia_byte();
	espera_envio();
	teste_envio_dado();
	start_bit(); //reinício
	espera_envio();
	teste_envio_restart();
	TWDR = 0xD1; //carrega o endereço para acesso do DS1307 (bit0 = 1 é leitura)
	//automaticamente o ATmega chaveia para o estado de recepção
	envia_byte();
	espera_envio();
	teste_envio_end_leitura();
	recebe_byte_ret_nack(); //só lê um byte, por isso retorna um NACK
	espera_recebimento();
	teste_recebe_byte_ret_nack();
	stop_bit();
	return TWDR; //retorna byte recebido
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//Sub-rotina para ler apenas um byte do barramento I2C do DS1307
//-----------------------------------------------------------------------------------
unsigned char le_RTC(unsigned char endereco)
{
	start_bit();
	espera_envio();
	teste_envio_start();
	TWDR = 0xD0; //carrega o endereço para acesso do DS1307 (bit0 = 0, escrita)
	//para outro CI basta trocar este endereço
	envia_byte();
	espera_envio();
	teste_envio_end_escrita();
	TWDR = endereco; //ajuste do ponteiro de endereço para a leitura do DS1307
	envia_byte();
	espera_envio();
	teste_envio_dado();
	start_bit(); //reinício
	espera_envio();
	teste_envio_restart();
	TWDR = 0xD1; //carrega o endereço para acesso do DS1307 (bit0 = 1 é leitura)
	//automaticamente o ATmega chaveia para o estado de recepção
	envia_byte();
	espera_envio();
	teste_envio_end_leitura();
	recebe_byte_ret_nack(); //só lê um byte, por isso retorna um NACK
	espera_recebimento();
	teste_recebe_byte_ret_nack();
	stop_bit();
	return TWDR; //retorna byte recebido
}
//-----------------------------------------------------------------------------------

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

