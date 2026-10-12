/*
 * STM32 FreeRTOS Sensor Data Logger
 * Main application entry point
 *
 * NOTE:
 * This is a preliminary scaffold.
 * STM32 initialization must be adapted to the
 * selected development board using STM32CubeIDE.
 */

#include "main.h"
#include "app_freertos.h"

int main(void)
{
    /* Initialize the STM32 Hardware Abstraction Layer. */
    HAL_Init();

    /* TODO: Configure the system clock. */
    /* TODO: Initialize GPIO. */
    /* TODO: Initialize UART. */
    /* TODO: Initialize the sensor interface. */

    /* Initialize the FreeRTOS application. */
    MX_FREERTOS_Init();

    /* TODO: Start the FreeRTOS scheduler using
       the board's configured FreeRTOS integration. */

    while (1)
    {
        /* The scheduler should manage application tasks. */
    }
}
