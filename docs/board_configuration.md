# STM32F439ZI Nucleo Board Configuration

## 1. Target Hardware

- Development board: NUCLEO-F439ZI
- Microcontroller: STM32F439ZI
- Processor: ARM Cortex-M4
- Programming language: Embedded C
- Development environment: STM32CubeIDE
- Real-time operating system: FreeRTOS

## 2. Planned Peripheral Configuration

| Peripheral | Purpose |
|---|---|
| GPIO | DS18B20 1-Wire communication |
| UART | Transmit sensor readings to a computer |
| System clock | Configure MCU operation |
| FreeRTOS queue | Transfer sensor measurements |
| FreeRTOS tasks | Manage sensor acquisition and data processing |

## 3. Planned RTOS Tasks

1. Sensor Task: Read temperature every second.
2. Processing Task: Validate sensor measurements.
3. UART Task: Transmit formatted readings.

## 4. Configuration Status

The target board has been selected.

Exact GPIO pins, UART settings, clock configuration, and FreeRTOS parameters will be finalized during STM32CubeIDE development.

## 5. Current Status

The project documentation and initial source-code scaffolds are being prepared.

Hardware integration, firmware compilation, and testing are pending.
