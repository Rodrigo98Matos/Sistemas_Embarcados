/*
 * Computador_de_Bordo.c
 *
 * Created: 12/02/2022 22:25:26
 * Author : Rodrigo Matos
 */ 

#include "def_principais.h"
#include "USART.h"
#include "ADC.h"



void setup() {
  USART_Inic(9600);
  mag.initialize();


}

void loop() {
  HMC5883L mag;
  GY273 
  mag.getHeading(&mx, &my, &mz);
  //Serial.println(ntc_10k(2));
    char t1[] = "Temperatura:  ";
    char b1[] = "\tBateria1:  ";
    char b2[] = "\tBateria2:  ";
    char fim[] = "\n";
    double bateria1 = tensao(1);
    //escreve_USART(t1);  envia_double(ntc_10k(3));
    escreve_USART(b1);  envia_double(bateria1);
    escreve_USART(b2);  envia_double(bat2(6, bateria1));
    escreve_USART(fim);
    _delay_ms(1000);

}
