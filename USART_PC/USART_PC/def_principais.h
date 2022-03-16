#ifndef _DEF_PRINCIPAIS_H
#define _DEF_PRINCIPAIS_H
#define F_CPU 16000000UL //define a frequ�ncia do microcontrolador - 16MHz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
//Defini��es de macros para o trabalho com bits
#define set_bit(y,bit) (y|=(1<<bit))
#define clr_bit(y,bit) (y&=~(1<<bit))
#define cpl_bit(y,bit) (y^=(1<<bit))
#define tst_bit(y,bit) (y&(1<<bit))
#endif