# STM32-FreeRTOS-Sensor-Logger
## Overview
A real-time embedded systems project using STM32, FreeRTOS, and a DS18B20 temperature sensor.

The system is planned to collect temperature readings periodically, process sensor data using separate RTOS tasks, and transmit the readings to a computer through UART.

## Objectives

* Understand FreeRTOS task scheduling.
* Interface a digital temperature sensor with STM32.
* Implement inter-task communication using RTOS queues.
* Transmit sensor readings using UART.
* Develop debugging and testing skills for embedded firmware.

## Planned Architecture

1. Sensor Task
2. RTOS Queue
3. Data Processing Task
4. UART Logging Task
5. Serial Terminal

## Hardware Requirements

* Compatible STM32 development board
* DS18B20 temperature sensor
* 4.7 kΩ pull-up resistor
* Breadboard and jumper wires
* USB cable

## Software Requirements

* STM32CubeIDE
* FreeRTOS
* Git and GitHub
* Serial terminal software

## Project Status

**Status:** Initial repository setup.

Firmware implementation, hardware integration, and testing are pending.

## Future Improvements

* Add error detection and recovery.
* Record timestamps for sensor readings.
* Add SD card logging.
* Optimize task scheduling and resource usage.
