#include "daisy_seed.h"

extern "C"
{
#include "FreeRTOS.h"
#include "task.h"
}
using namespace daisy;

DaisySeed hardware;

TaskHandle_t ledTaskHandle = nullptr;

// LED task
void LedTask(void *argument)
{
    hardware.PrintLine("LED Task Started");
    (void)argument;

    bool led_state = true;

    for(;;)
    {
        hardware.PrintLine("LED State: %s", led_state ? "ON" : "OFF");
        hardware.SetLed(led_state);
        led_state = !led_state;

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(void)
{
    hardware.Configure();
    hardware.Init();
    hardware.StartLog();

    // Create task
    xTaskCreate(LedTask,
                "ledTask",
                2048,
                nullptr,
                tskIDLE_PRIORITY + 1,
                &ledTaskHandle);

    hardware.PrintLine("LED Task Created");

    // Start scheduler
    vTaskStartScheduler();
    hardware.PrintLine("Scheduler Started");

    // Should never reach here
    for(;;)
    {
        hardware.PrintLine("in main loop");
        System::Delay(1000);
    }
}