#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>
#include <stdbool.h>

/* DS18B20 driver status */
typedef enum
{
    DS18B20_OK = 0,
    DS18B20_ERROR,
    DS18B20_NOT_CONNECTED,
    DS18B20_INVALID_DATA
} DS18B20_Status_t;

/* Initialize the DS18B20 sensor interface */
DS18B20_Status_t DS18B20_Init(void);

/* Read temperature in degrees Celsius */
DS18B20_Status_t DS18B20_ReadTemperature(float *temperature);

/* Check whether the sensor is connected */
bool DS18B20_IsConnected(void);

#endif /* DS18B20_H */
