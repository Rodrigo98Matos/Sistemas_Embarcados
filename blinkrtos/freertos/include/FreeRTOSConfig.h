#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
* Application specific definitions.
*
* These definitions should be adjusted for your particular hardware and
* application requirements.
*
* THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
* FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
*
* See http://www.freertos.org/a00110.html.
*----------------------------------------------------------*/

#define configUSE_PREEMPTION           1
#define configUSE_IDLE_HOOK            0
#define configUSE_TICK_HOOK            0
#define configCPU_CLOCK_HZ             ( 1200000UL )
#define configLFXT_CLOCK_HZ            ( 32768 )
#define configTICK_RATE_HZ             ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES           ( 5 )
#define configTOTAL_HEAP_SIZE          ( ( size_t ) ( 7 * 1024 ) )
#define configMAX_TASK_NAME_LEN        ( 10 )
#define configUSE_TRACE_FACILITY       0
#define configUSE_16_BIT_TICKS         1
#define configIDLE_SHOULD_YIELD        1
#define configUSE_MUTEXES              0
#define configQUEUE_REGISTRY_SIZE      0
#define configGENERATE_RUN_TIME_STATS  0
#define configCHECK_FOR_STACK_OVERFLOW 0
#define configUSE_RECURSIVE_MUTEXES    0
#define configUSE_MALLOC_FAILED_HOOK   0
#define configUSE_APPLICATION_TASK_TAG 0
#define configUSE_COUNTING_SEMAPHORES  0

#ifdef __LARGE_DATA_MODEL__
#define configMINIMAL_STACK_SIZE       ( ( unsigned short ) 80 )
#else
    #define configMINIMAL_STACK_SIZE   ( ( unsigned short ) 120 )
#endif

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES           0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Software timer definitions. */
#define configUSE_TIMERS               0
#define configTIMER_TASK_PRIORITY      ( 3 )
#define configTIMER_QUEUE_LENGTH       10
#define configTIMER_TASK_STACK_DEPTH   ( configMINIMAL_STACK_SIZE )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet       0
#define INCLUDE_uxTaskPriorityGet      0
#define INCLUDE_vTaskDelete            0
#define INCLUDE_vTaskCleanUpResources  0
#define INCLUDE_vTaskSuspend           0
#define INCLUDE_vTaskDelayUntil        1
#define INCLUDE_vTaskDelay             1

/* The MSP430X port uses a callback function to configure its tick interrupt.
This allows the application to choose the tick interrupt source.
configTICK_VECTOR must also be set in FreeRTOSConfig.h to the correct interrupt
vector for the chosen tick interrupt source.  This implementation of
vApplicationSetupTimerInterrupt() generates the tick from timer A0, so in this
case configTICK_VECTOR is set to TIMER0_A0_VECTOR. */
#define configTICK_VECTOR          TIMER0_A0_VECTOR

#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#endif /* FREERTOS_CONFIG_H */
