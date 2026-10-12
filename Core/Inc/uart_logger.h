#ifndef UART_LOGGER_H
#define UART_LOGGER_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

/*
 * Initialize the UART logger with the configured
 * STM32 UART peripheral.
 */
void UARTLogger_Init(UART_HandleTypeDef *huart);

/* Log a valid temperature measurement. */
HAL_StatusTypeDef UARTLogger_LogTemperature(
    uint32_t timestamp_ms,
    float temperature
);

/* Log a sensor error. */
HAL_StatusTypeDef UARTLogger_LogSensorError(
    uint32_t timestamp_ms
);

#endif /* UART_LOGGER_H */
