# Hardware Wiring Guide

## 1. Components
- STM32 development board
- DS18B20 temperature sensor
- 4.7 kΩ pull-up resistor
- Breadboard and jumper wires

## 2. DS18B20 Connections

| Sensor Pin | Connection |
|---|---|
| VDD | Compatible supply voltage |
| GND | STM32 GND |
| DATA | STM32 GPIO pin |
| Pull-up resistor | Between DATA and VDD |

The DATA line typically requires a 4.7 kΩ pull-up resistor.

## 3. UART Communication

UART transmits sensor readings from the STM32 to a computer for monitoring.

The exact UART pins and configuration depend on the selected STM32 development board.

## 4. Wiring Precautions
- Verify the sensor pinout before connecting it.
- Confirm supply-voltage compatibility.
- Ensure the STM32 and sensor share a common ground.
- Select a suitable GPIO pin for the sensor interface.

## 5. Project Status

This is preliminary wiring documentation. Exact pin assignments will be added after selecting the STM32 development board.
