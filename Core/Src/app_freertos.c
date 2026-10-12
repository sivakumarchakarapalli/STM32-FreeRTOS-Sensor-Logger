#include "app_freertos.h"
#include "app_config.h"
#include "ds18b20.h"

#include <stdio.h>

/* RTOS queue for temperature measurements */
static QueueHandle_t temperatureQueue = NULL;

/* Structure for sensor measurements */
typedef struct
{
    float temperature;
    uint32_t timestamp_ms;
    DS18B20_Status_t status;
} SensorData_t;

/* Sensor acquisition task */
static void SensorTask(void *argument)
{
    SensorData_t data;

    (void)argument;

    for (;;)
    {
        data.status = DS18B20_ReadTemperature(&data.temperature);
        data.timestamp_ms = (uint32_t)xTaskGetTickCount()
                          * (uint32_t)portTICK_PERIOD_MS;

        if (temperatureQueue != NULL)
        {
            (void)xQueueSend(temperatureQueue, &data, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(SENSOR_SAMPLE_PERIOD_MS));
    }
}

/* Data processing task */
static void ProcessingTask(void *argument)
{
    SensorData_t data;

    (void)argument;

    for (;;)
    {
        if (xQueueReceive(temperatureQueue, &data, portMAX_DELAY) == pdPASS)
        {
            /* Validate sensor status before further processing. */
            if (data.status == DS18B20_OK)
            {
                /* Valid measurement received.
                 * Forwarding to UART will be implemented next.
                 */
            }
        }
    }
}

/* Initialize application tasks and queue */
void App_FreeRTOS_Init(void)
{
    temperatureQueue = xQueueCreate(
        SENSOR_QUEUE_LENGTH,
        sizeof(SensorData_t)
    );

    if (temperatureQueue == NULL)
    {
        return;
    }

    xTaskCreate(
        SensorTask,
        "Sensor",
        256,
        NULL,
        tskIDLE_PRIORITY + 2,
        NULL
    );

    xTaskCreate(
        ProcessingTask,
        "Processing",
        256,
        NULL,
        tskIDLE_PRIORITY + 1,
        NULL
    );
}

/* STM32CubeMX-compatible initialization entry point */
void MX_FREERTOS_Init(void)
{
    App_FreeRTOS_Init();
}
