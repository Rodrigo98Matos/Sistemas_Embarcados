#include <Arduino.h>
#include <driver/adc.h>
#include <esp_adc_cal.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_err.h>
#include <esp_log.h>

uint32_t tensao(adc_unit_t ADC,unsigned char pin);
double Vin_div_T(adc_unit_t ADC,unsigned char pin, double r1, double r2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // adc1_config_width(ADC_WIDTH_BIT_12);//Configura a resolucao
	// adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);//Configura a atenuacao
  

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
			Obtem a leitura RAW do ADC para depois ser utilizada pela API de calibracao

			Media simples de 100 leituras intervaladas com 30us
		*/
		
		Serial.printf("ADC CAL Read mV: %g\n",Vin_div_T(ADC_UNIT_1,36,200,680) );//Mostra a leitura calibrada no Serial Monitor



		vTaskDelay(pdMS_TO_TICKS(1000));//Delay 1seg
}

uint32_t tensao(adc_unit_t ADC,unsigned char pin){      // ADC_UNIT_1   ou   ADC_UNIT_2
  esp_adc_cal_characteristics_t adc_cal;//Estrutura que contem as informacoes para calibracao

  esp_adc_cal_characterize(ADC, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_cal);//Inicializa a estrutura de calibracao

  uint32_t voltage = 0;
		for (int i = 0; i < 100; i++)
		{
			voltage += analogRead(pin);//Obtem o valor RAW do ADC
			ets_delay_us(30);
		}
		voltage /= 100;


		voltage = esp_adc_cal_raw_to_voltage(voltage, &adc_cal);//Converte e calibra o valor lido (RAW) para mV
  return voltage/1000;
}
double Vin_div_T(adc_unit_t ADC,unsigned char pin, double r1, double r2){
  uint32_t tens = tensao(ADC,pin);
  double res = (r2/(r1+r2));
  return (tens/res); //tensão/(R2/(R1+R2)) retorna a tensão de entrada do divisor de tensão
}