#include "uart_logger.h"
#include "app_config.h"

#include <stdio.h>
#include <stdint.h>

/* UART peripheral handle */
static UART_HandleTypeDef *logger_uart = NULL;

/* Initialize UART logger */
void UARTLogger_Init(UART_HandleTypeDef *huart)
{
    logger_uart = huart;
}

/* Log temperature measurement */
HAL_StatusTypeDef UARTLogger_LogTemperature(
    uint32_t timestamp_ms,
    float temperature)
{
    char buffer[100];
    int32_t temp_centi;
    int32_t whole;
    int32_t fraction;
    int length;

    if (logger_uart == NULL)
    {
        return HAL_ERROR;
    }

    /* Convert temperature to hundredths of a degree.
       This avoids requiring floating-point printf support. */
    temp_centi = (int32_t)(temperature * 100.0f);
    whole = temp_centi / 100;
    fraction = temp_centi % 100;

    if (fraction < 0)
    {
        fraction = -fraction;
    }

    length = snprintf(
        buffer,
        sizeof(buffer),
        "Time: %lu ms | Temperature: %ld.%02ld C\r\n",
        (unsigned long)timestamp_ms,
        (long)whole,
        (long)fraction
    );

    if (length < 0 || length >= (int)sizeof(buffer))
    {
        return HAL_ERROR;
    }

    return HAL_UART_Transmit(
        logger_uart,
        (uint8_t *)buffer,
        (uint16_t)length,
        UART_TX_TIMEOUT_MS
    );
}

/* Log sensor error */
HAL_StatusTypeDef UARTLogger_LogSensorError(uint32_t timestamp_ms)
{
    char buffer[80];
    int length;

    if (logger_uart == NULL)
    {
        return HAL_ERROR;
    }

    length = snprintf(
        buffer,
        sizeof(buffer),
        "Time: %lu ms | ERROR: Sensor reading failed\r\n",
        (unsigned long)timestamp_ms
    );

    if (length < 0 || length >= (int)sizeof(buffer))
    {
        return HAL_ERROR;
    }

    return HAL_UART_Transmit(
        logger_uart,
        (uint8_t *)buffer,
        (uint16_t)length,
        UART_TX_TIMEOUT_MS
    );
}
