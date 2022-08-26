#include <msp430.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"


#define tst_bit(y,bit) (y&(1<<bit))


/**
 * main.c
 */
void vApplicationSetupTimerInterrupt()
{
    const uint16_t ACLK_Freq = 32768;

    // Stop the timer.
    TA0CTL = 0;

    // Set the compare value
    TA0CCR0 = ACLK_Freq / configTICK_RATE_HZ;

    // Timer interrupt enabled
    TA0CCTL0 = CCIE;

    // Start with up mode and ACLK as clock source
    TA0CTL |= TACLR + MC_1 + TASSEL_1;
}

void vBlinkREDLED(void * pvParameters)
{
    // this section will execute once
    TickType_t xDelay = 500 / portTICK_PERIOD_MS;
    uint8_t estado1 = 0;
    int i;

    while(1){
        switch(estado1){
        case 0:
            if(!tst_bit(P2IN,1)){
                for(i = 0;i<50;i++);
                while(!tst_bit(P2IN,1));
                estado1 = 1;
            }
            xDelay = 500 / portTICK_PERIOD_MS;
            break;
        case 1:
            if(!tst_bit(P2IN,1)){
                for(i = 0;i<50;i++);
                while(!tst_bit(P2IN,1));
                estado1 = 0;
            }
            xDelay = 1000 / portTICK_PERIOD_MS;
            break;
        }
        P1OUT^=BIT0;
        vTaskDelay( xDelay );
    }
}
void vBlinkGREENLED(void * pvParameters)
{
    // this section will execute once
    TickType_t xDelay = 500 / portTICK_PERIOD_MS;
    uint8_t estado1 = 0;
    int i;

     while(1){
        switch(estado1){
        case 0:
            if(!tst_bit(P1IN,1)){
                for(i = 0;i<50;i++);
                while(!tst_bit(P1IN,1));
                estado1 = 1;
            }
            xDelay = 500 / portTICK_PERIOD_MS;
            break;
        case 1:
            if(!tst_bit(P1IN,1)){
                for(i = 0;i<50;i++);
                while(!tst_bit(P1IN,1));
                estado1 = 0;
            }
            xDelay = 1000 / portTICK_PERIOD_MS;
            break;
        }
        P4OUT^=BIT7;
        vTaskDelay( xDelay );
    }
}

void vHardwareSetup()
{

    // Stop watchdog timer (classic at msp430)
    WDTCTL = WDTPW + WDTHOLD;

    // P1.0 as output
    P1DIR |= BIT0;
    // P4.7 as output
    P4DIR |= BIT7;
    //configura botões
    P2DIR&= ~(1<<1);
    P2REN |= 1<<1;
    P1DIR&= ~(1<<1);
    P1REN |= 1<<1;

    // The tick timer setup
    vApplicationSetupTimerInterrupt();

    // Enable the interrupts
    taskENABLE_INTERRUPTS();
}

int main(void)
{

  // each hardware needs its own setup
  vHardwareSetup();

  //Each task should have a handler
  static xTaskHandle BlinkREDLED_Handler;
  static xTaskHandle BlinkGREENLED_Handler;

  //task creation
  xTaskCreate( vBlinkREDLED, "Blink P1.0", configMINIMAL_STACK_SIZE, NULL, 1, &BlinkREDLED_Handler);
  xTaskCreate( vBlinkGREENLED, "Blink P4.7", configMINIMAL_STACK_SIZE, NULL, 1, &BlinkGREENLED_Handler);

  //scheduler initialization
  vTaskStartScheduler();

  // should never reach here
  return 0;
}

