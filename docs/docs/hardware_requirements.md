# Hardware Requirements

## 1. Main Components

| Component                  |    Quantity | Purpose                  |
| -------------------------- | ----------: | ------------------------ |
| STM32 development board    |           1 | Main controller          |
| DS18B20 temperature sensor |           1 | Temperature measurement  |
| 4.7 kΩ resistor            |           1 | Sensor data-line pull-up |
| Breadboard                 |           1 | Circuit prototyping      |
| Jumper wires               | As required | Electrical connections   |
| USB cable                  |           1 | Programming and power    |

## 2. Optional Equipment

* Multimeter for voltage and continuity checks.
* Logic analyzer for debugging digital communication.
* Oscilloscope for inspecting signal timing.
* SD card module for future data logging.

## 3. Software Requirements

* STM32CubeIDE for firmware development.
* FreeRTOS for real-time task scheduling.
* Git for version control.
* GitHub for source-code hosting.
* Serial terminal software for UART monitoring.

## 4. Important Note

The exact STM32 board, GPIO pins, voltage levels, and UART configuration must be confirmed before connecting the sensor.

This document lists the planned requirements. Hardware availability and compatibility have not yet been verified.
