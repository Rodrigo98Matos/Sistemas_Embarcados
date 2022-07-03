#include <Arduino.h>
#include <C:\Users\USER\.platformio\packages\framework-arduinoespressif32\tools\sdk\esp32\include\freertos\include\freertos\FreeRTOS.h>

//Protótipos das Funções
void tarefa(void* parametro);
void gerenciador(void* parametro);

// Declaração dos handles das tarefas
TaskHandle_t tarefa1 = NULL;
TaskHandle_t tarefa2 = NULL;

void setup() {
  Serial.begin(300);

  xTaskCreatePinnedToCore(
    tarefa,                             //Função executada
    "Tarefa1",                          //Nome da tarefa
    1000,                               //Stack alocada para a tarefa
    NULL,                               //Parametro passado para a tarefa
    1,                                  //prioridade da tarefa
    &tarefa1,                           //Handle da tarefa
    APP_CPU_NUM                         //Processador que ira executar a tarefa
  );

  xTaskCreatePinnedToCore(
    tarefa,                             //Função executada
    "Tarefa2",                          //Nome da tarefa
    1000,                               //Stack alocada para a tarefa
    NULL,                               //Parametro passado para a tarefa
    1,                                  //prioridade da tarefa
    &tarefa2,                           //Handle da tarefa
    APP_CPU_NUM                         //Processador que ira executar a tarefa
  );

  xTaskCreatePinnedToCore(
    gerenciador,                             //Função executada
    "Gerenciador",                          //Nome da tarefa
    1000,                               //Stack alocada para a tarefa
    NULL,                               //Parametro passado para a tarefa
    2,                                  //prioridade da tarefa
    NULL,                           //Handle da tarefa
    APP_CPU_NUM                         //Processador que ira executar a tarefa
  );
}

void loop() {
  vTaskDelete(NULL);
}

void gerenciador(void* parametro){
  while(1){
    vTaskDelay(5000);
    if(tarefa1 == NULL || tarefa == NULL){
      Serial.println("Handle nulo");
    }else{
      vTaskSuspend(tarefa2);
      vTaskDelay(5000);
      vTaskSuspend(tarefa1);
      vTaskResume(tarefa2);
      vTaskDelay(5000);
      vTaskResume(tarefa1);
    }
  }
}

void tarefa(void* parametro){
  while(1){
    Serial.print(pcTaskGetTaskName(NULL));
    Serial.print(" executando no Core: ");
    Serial.print(xPortGetCoreID());
    Serial.print(". ");
    Serial.print(uxTaskGetStackHighWaterMark(NULL));
    Serial.println(" bytes livres na stack.");
    vTaskDelay(200);
  }
}