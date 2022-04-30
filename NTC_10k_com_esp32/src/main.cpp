#include <Arduino.h>

double temp[3] = {0.0, 0.0, 0.0};
void ler_temp(uint8_t pin){
  double  Rsup = 10000.0,                         //Resistor superior
          Rd0 = 10000.0,                          //Resistencia do NTC a 25°C
          T0 = 298.15,                            //25°C em Kelvin
          T1 = 273.15,                             //Temperatura de referência 1
          T2 = 373.15,                             //Temperatura de referêcia 2
          RT1 = 35563.0,                          //Reseistência do NTC em T1
          RT2 = 549.4,                            //Resistência do NTC em T2
          beta = log(RT1/RT2)/((1/T1)-(1/T2)),    //Constante do termistor
          Rinf = Rd0*exp(-beta/T0),               //Parâmetro de resistência
          Vadc = 0.0,                             //Tensão lida pelo ADC
          Rntc = 0.0;                             //Resistencia do NTC                           

  float leitura = analogRead(pin);// lerAnalog(A0);
  Vadc = (3.3*leitura)/4095;
  Rntc = ((10000*3.3)-(Vadc*10000))/Vadc;
  temp[0] = beta/log(Rntc/Rinf);                  //Temperatura em Kelvin
  temp[1] = temp[0] - 273.15;                     //Remperatura em Celsius
  temp[2] = (temp[1] * 9/5) + 32;
}
void setup() {
  Serial.begin(9600);
  pinMode(36,INPUT);

}

void loop() {
  char escala[] = "KCF";
  ler_temp(12);
  Serial.print("Temp_bat_1:\t");
  //for(int i = 0; i <= 2; i++){
    Serial.print(temp[1]);Serial.print("\t");
  //}
  ler_temp(14);
  Serial.print("Temp_bat_2:\t");
  //for(int i = 0; i <= 2; i++){
    Serial.print(temp[1]);Serial.print("\t");
  //}
  Serial.println();
  delay(500);
}