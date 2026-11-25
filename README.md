# DaisySeed blink example FreeRTOS

FreeRTOS version of the [blink](https://github.com/daisyaudio/DaisyExamples/tree/master/seed/Blink) example 

## How to use
make a small change to the `system.cpp` inside LibDaisy

change:
```C++
    void SysTick_Handler(void)
    {
        HAL_IncTick();
        HAL_SYSTICK_IRQHandler();
    }
```

to:
```C++
    void __attribute__((weak)) SysTick_Handler(void)
    {
        HAL_IncTick();
        HAL_SYSTICK_IRQHandler();
    }
```
to make the SysTick_Handler weak so that the handler inside the `freertos_hooks.cpp` can take over
