/*
 * ADC.c
 *
 * Created: 12/03/2022 14:35:26
 * Author : Rodrigo Matos
 */ 

#include "ADC.h"


/* Replace with your library code */


float tensao(uint8_t pin){      //retorna a tensão em Volts lido na porta analógica 
  int leitura = analogRead(pin);
  return (5.0*leitura)/1023.00;
}

double R1(uint8_t pin){       //Em um divisor de tensão com 10000 Ohm no resistor superior, retorna o valor ohmico
  float Vadc = tensao(pin);
  return ((10000*5.0)-(Vadc*10000))/Vadc;
}

double R2(uint8_t pin){       //Em um divisor de tensão com 10000 Ohm no resistor superior, retorna o valor ohmico
  float Vadc = tensao(pin);
  return Vadc * (10000/(5.0-Vadc));
}

double ntc_10k(uint8_t pin){
  double  Rd0 = 10000.0,                          //Resistencia do NTC a 25°C
      T0 = 298.15,                            //25°C em Kelvin
      T1 = 273.15,                            //Temperatura de referência 1
      T2 = 373.15,                            //Temperatura de referêcia 2
      RT1 = 35563.0,                          //Reseistência do NTC em T1
      RT2 = 549.4,                            //Resistência do NTC em T2
      beta = log(RT1/RT2)/((1/T1)-(1/T2)),    //Constante do termistor
      Rinf = Rd0*exp(-beta/T0),               //Parâmetro de resistência
      Rntc,             //Resistencia do NTC
      temp; 
  Rntc = R1(pin);                
  temp = beta/log(Rntc/Rinf);       //Temperatura em Kelvin
  return temp - 273.15;         //Retorna Temperatura em Celsius
}
double bat2(uint8_t pin, double b1){
  return (tensao(pin)/(0.5))-b1; //tensão/(R1/(R1+R2)) retorna a tensão de entrada do divisor de tensão menos a tensão da primeira bateria
}
double tensao_mv(uint8_t pin){//Tensão em mV
  int leitura = analogRead(pin);
  return (5000.0*leitura)/1023.00;
}
double ah49e(uint8_t pin){//Sensor de efeito Hall 49e
  return (tensao_mv(pin)-2500)/17; //retorna a leitura do sensor em mT
}
