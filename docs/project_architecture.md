# Project Architecture

## 1. Overview

The STM32 FreeRTOS Sensor Data Logger is designed to collect temperature measurements periodically and transmit them to a computer using UART.

## 2. System Architecture

```text
DS18B20 Temperature Sensor
            |
            v
      Sensor Task
            |
            v
       RTOS Queue
            |
            v
     Processing Task
            |
            v
         UART Task
            |
            v
      Serial Terminal
```

## 3. RTOS Tasks

### Sensor Task

* Reads temperature measurements periodically.
* Sends measurements to the RTOS queue.

### Processing Task

* Receives measurements from the queue.
* Validates sensor data.

### UART Task

* Formats the measurement and timestamp.
* Transmits the record to the computer.

## 4. Inter-Task Communication

A FreeRTOS queue transfers measurements between tasks and separates sensor acquisition from UART communication.

## 5. Project Status

This architecture describes the planned implementation. Firmware development and hardware testing are pending.
