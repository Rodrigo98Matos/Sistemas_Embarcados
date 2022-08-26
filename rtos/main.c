#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>
#include <msp430.h> 


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

void vBlinkLED(void * pvParameters)
{
    // this section will execute once
    const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

    while(1){
        P1OUT^=BIT0;
        vTaskDelay( xDelay );
    }
}

void vHardwareSetup()
{

    // Stop watchdog timer (classic at msp430)
    WDTCTL = WDTPW + WDTHOLD;

    // P1.0 as output
    P1DIR |= BIT0;

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
  static xTaskHandle BlinkLED_Handler;

  //task creation
  xTaskCreate( vBlinkLED, "Blink P1.0", configMINIMAL_STACK_SIZE, NULL, 1, &BlinkLED_Handler);

  //scheduler initialization
  vTaskStartScheduler();

  // should never reach here
  return 0;
}

