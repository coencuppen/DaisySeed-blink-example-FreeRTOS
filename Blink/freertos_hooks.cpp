#include "FreeRTOS.h"
#include "task.h"
#include "stm32h7xx_hal.h"


extern "C"
{
    void xPortSysTickHandler(void);

    void SysTick_Handler(void)
    {
        HAL_IncTick(); // keeps System::Delay / GetNow alive
        if(xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
            xPortSysTickHandler();
    }

    void vApplicationMallocFailedHook(void)
    {
        taskDISABLE_INTERRUPTS();
        while(1) {}
    }

    void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
    {
        (void)xTask;
        (void)pcTaskName;
        taskDISABLE_INTERRUPTS();
        while(1) {}
    }

    // THIS IS CRITICAL ON DAISY / STM32
    void vApplicationTickHook(void)
    {
        // leave empty, but MUST exist
    }
}