/*
 * def_principais.h
 *
 * Created: 13/02/2022 14:48:57
 *  Author: Alberto.ncc
 */ 


#ifndef DEF_PRINCIPAIS_H_
#define DEF_PRINCIPAIS_H_
#define F_CPU 16000000UL //frequência de trabalho
#include <avr/io.h> //definições do componente especificado
#include <util/delay.h> //biblioteca para o uso das rotinas de delay
//Definições de macros para o trabalho com bits
#define set_bit(y,bit) (y|=(1<<bit))//coloca em 1 o bit x da variável Y
#define clr_bit(y,bit) (y&=~(1<<bit))//coloca em 0 o bit x da variável Y
#define cpl_bit(y,bit) (y^=(1<<bit))//troca o estado lógico do bit x da variável Y
#define tst_bit(y,bit) (y&(1<<bit))//retorna 0 ou 1 conforme leitura do bit




#endif /* DEF_PRINCIPAIS_H_ */