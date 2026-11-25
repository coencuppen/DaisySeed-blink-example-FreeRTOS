#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* ===== Core ===== */
#define configUSE_PREEMPTION                    1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configCPU_CLOCK_HZ                      480000000UL
#define configTICK_RATE_HZ                      1000
#define configUSE_TIME_SLICING                  1
#define configUSE_TICKLESS_IDLE                 0

#define configMAX_PRIORITIES                    5
#define configMINIMAL_STACK_SIZE                256
#define configTOTAL_HEAP_SIZE                   (32 * 1024)

#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1

/* ===== Hooks ===== */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     1

#define configUSE_MALLOC_FAILED_HOOK            1
#define configCHECK_FOR_STACK_OVERFLOW          2

/* ===== Timers ===== */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               (configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            256

/* ===== Cortex-M7 ===== */
#define configPRIO_BITS                         4

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

#define configKERNEL_INTERRUPT_PRIORITY \
    (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/* ===== API inclusion ===== */
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_xTaskGetSchedulerState          1

/* ===== Interrupt handler mapping ===== */
#define xPortPendSVHandler PendSV_Handler
#define vPortSVCHandler SVC_Handler
// #define xPortSysTickHandler SysTick_Handler

/* ===== Debug ===== */
#define configASSERT(x)                         \
    if((x) == 0)                               \
    {                                          \
        taskDISABLE_INTERRUPTS();              \
        for(;;);                               \
    }

#endif /* FREERTOS_CONFIG_H */