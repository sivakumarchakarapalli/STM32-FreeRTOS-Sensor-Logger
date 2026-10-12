# Hardware Wiring Guide

## 1. Components

* STM32 development board
* DS18B20 temperature sensor
* 4.7 kΩ pull-up resistor
* Breadboard and jumper wires

## 2. DS18B20 Connections

| DS18B20 Pin      | Connection                |
| ---------------- | ------------------------- |
| VDD              | Compatible supply voltage |
| GND              | STM32 GND                 |
| DATA             | STM32 GPIO pin            |
| Pull-up resistor | Between DATA and VDD      |

The pull-up resistor is typically 4.7 kΩ.

## 3. UART Communication

UART will be used to transmit sensor readings from the STM32 to a computer.

The exact UART pins and configuration depend on the selected STM32 board.

## 4. Safety and Compatibility

* Confirm the sensor pinout before wiring.
* Verify that the sensor supply voltage is compatible with the board.
* Select a GPIO pin that supports the required interface.
* Ensure that the sensor and STM32 share a common ground.

## 5. Project Status

This is a preliminary wiring guide. The exact pin assignments will be documented after selecting the STM32 development board.
