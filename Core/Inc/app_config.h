#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/* Sensor sampling interval */
#define SENSOR_SAMPLE_PERIOD_MS    1000U

/* UART transmission timeout */
#define UART_TX_TIMEOUT_MS         100U

/* FreeRTOS queue length */
#define SENSOR_QUEUE_LENGTH        5U

/* Invalid temperature marker */
#define SENSOR_INVALID_TEMP        (-999.0f)

#endif /* APP_CONFIG_H */
