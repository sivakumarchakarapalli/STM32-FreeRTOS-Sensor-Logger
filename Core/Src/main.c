/*
 * STM32 FreeRTOS Sensor Data Logger
 * Target: NUCLEO-F439ZI
 *
 * NOTE:
 * This file must be integrated with the
 * STM32CubeIDE-generated project.
 */

#include "main.h"
#include "app_freertos.h"

int main(void)
{
    /* Initialize HAL */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize configured peripherals */
    MX_GPIO_Init();
    MX_USART3_UART_Init();

    /* Initialize FreeRTOS application */
    MX_FREERTOS_Init();

    /*
     * Start the scheduler using the generated
     * FreeRTOS integration.
     */
    osKernelStart();

    /* Should not normally reach this loop */
    while (1)
    {
    }
}
