/*
 * STM32 FreeRTOS Sensor Data Logger
 * Target: NUCLEO-F439ZI
 *
 * Three tasks:
 * 1. Sensor acquisition
 * 2. Data processing
 * 3. UART logging
 */

#include "app_freertos.h"
#include "app_config.h"
#include "ds18b20.h"
#include "uart_logger.h"
#include "stm32f4xx_hal.h"

#include <stdint.h>

/*
 * USART3 will be configured for the board's
 * ST-LINK Virtual COM Port.
 *
 * This handle will be provided by the
 * STM32CubeIDE-generated USART initialization.
 */
extern UART_HandleTypeDef huart3;

/* Sensor measurement structure */
typedef struct
{
    float temperature;
    uint32_t timestamp_ms;
    DS18B20_Status_t status;

} SensorData_t;

/* Inter-task communication queues */
static QueueHandle_t sensorQueue = NULL;
static QueueHandle_t loggerQueue = NULL;


/* Task 1: Acquire temperature measurements */
static void SensorTask(void *argument)
{
    SensorData_t data;

    (void)argument;

    DS18B20_Status_t initStatus = DS18B20_Init();

    for (;;)
    {
        data.temperature = 0.0f;

        data.timestamp_ms =
            (uint32_t)xTaskGetTickCount()
            * (uint32_t)portTICK_PERIOD_MS;

        if (initStatus == DS18B20_OK)
        {
            data.status =
                DS18B20_ReadTemperature(&data.temperature);
        }
        else
        {
            data.status = initStatus;
        }

        if (sensorQueue != NULL)
        {
            /* A full queue causes this sample to be dropped. */
            (void)xQueueSend(sensorQueue, &data, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(
            SENSOR_SAMPLE_PERIOD_MS
        ));
    }
}


/* Task 2: Validate and forward measurements */
static void ProcessingTask(void *argument)
{
    SensorData_t data;

    (void)argument;

    for (;;)
    {
        if (xQueueReceive(
                sensorQueue,
                &data,
                portMAX_DELAY) == pdPASS)
        {
            if (data.status == DS18B20_OK)
            {
                /* DS18B20 specified operating range. */
                if (data.temperature < -55.0f ||
                    data.temperature > 125.0f)
                {
                    data.status = DS18B20_INVALID_DATA;
                }
            }

            /*
             * Forward valid measurements and errors
             * to the UART logging task.
             */
            (void)xQueueSend(
                loggerQueue,
                &data,
                portMAX_DELAY
            );
        }
    }
}


/* Task 3: Send measurements to the computer */
static void UARTTask(void *argument)
{
    SensorData_t data;

    (void)argument;

    for (;;)
    {
        if (xQueueReceive(
                loggerQueue,
                &data,
                portMAX_DELAY) == pdPASS)
        {
            if (data.status == DS18B20_OK)
            {
                (void)UARTLogger_LogTemperature(
                    data.timestamp_ms,
                    data.temperature
                );
            }
            else
            {
                (void)UARTLogger_LogSensorError(
                    data.timestamp_ms
                );
            }
        }
    }
}


/* Initialize the RTOS application */
void App_FreeRTOS_Init(void)
{
    /* Create the sensor-to-processing queue. */
    sensorQueue = xQueueCreate(
        SENSOR_QUEUE_LENGTH,
        sizeof(SensorData_t)
    );

    /* Create the processing-to-logger queue. */
    loggerQueue = xQueueCreate(
        SENSOR_QUEUE_LENGTH,
        sizeof(SensorData_t)
    );

    if (sensorQueue == NULL ||
        loggerQueue == NULL)
    {
        return;
    }

    /*
     * USART3 must already be initialized
     * before initializing the logger.
     */
    UARTLogger_Init(&huart3);

    (void)xTaskCreate(
        SensorTask,
        "Sensor",
        256,
        NULL,
        tskIDLE_PRIORITY + 2,
        NULL
    );

    (void)xTaskCreate(
        ProcessingTask,
        "Process",
        256,
        NULL,
        tskIDLE_PRIORITY + 1,
        NULL
    );

    (void)xTaskCreate(
        UARTTask,
        "UART",
        256,
        NULL,
        tskIDLE_PRIORITY + 1,
        NULL
    );
}


/* STM32CubeMX-compatible entry point */
void MX_FREERTOS_Init(void)
{
    App_FreeRTOS_Init();
}
