#ifndef APP_FREERTOS_H
#define APP_FREERTOS_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Initialize the FreeRTOS application */
void MX_FREERTOS_Init(void);

/* Create application tasks and communication queues */
void App_FreeRTOS_Init(void);

#endif /* APP_FREERTOS_H */
