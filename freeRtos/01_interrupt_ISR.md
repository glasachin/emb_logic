# Interrupt ISRs
Passing information from an ISR (Interrupt Service Routine) in an ESP32 application should be done in a way that minimizes latency and avoids potential conflicts. Here are several effective methods, along with considerations for ensuring reliability and responsiveness.

## 1. Using xQueueSendFromISR with FreeRTOS Queues
FreeRTOS queues are one of the most common ways to pass data from an ISR to a task. ESP-IDF and FreeRTOS provide an ISR-safe version of the queue function: xQueueSendFromISR. This allows data to be sent from the ISR to a task, where it can be processed without blocking or lengthy operations in the ISR.

Steps:

Define a queue in your main application.
Send data from the ISR to the queue using xQueueSendFromISR.
Use xQueueReceive in a task to receive and process data.

**Example:**

```
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

// Queue handle
QueueHandle_t queue;

#define BUTTON_PIN GPIO_NUM_18

// ISR for button press
void IRAM_ATTR button_isr_handler(void* arg) {
    uint32_t data = 1;  // Some data to send
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xQueueSendFromISR(queue, &data, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR();  // Yield to higher-priority task if necessary
}

void task_to_process_data(void* arg) {
    uint32_t receivedData;
    while (true) {
        if (xQueueReceive(queue, &receivedData, portMAX_DELAY)) {
            printf("Data received from ISR: %d\n", receivedData);
            // Process data
        }
    }
}

void app_main() {
    queue = xQueueCreate(10, sizeof(uint32_t));
    if (queue == NULL) {
        printf("Failed to create queue\n");
        return;
    }

    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_POSEDGE);  // Rising edge interrupt
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON_PIN, button_isr_handler, NULL);

    xTaskCreate(task_to_process_data, "ProcessDataTask", 2048, NULL, 10, NULL);
}
```

## 2. Using xTaskNotifyFromISR with Direct Task Notifications
If you only need to signal a single task (rather than sending multiple pieces of data), xTaskNotifyFromISR is very efficient. Task notifications are faster than queues because they do not require memory management, making them ideal for lightweight signaling from an ISR.

**Example:**
```
TaskHandle_t taskHandle;

// ISR
void IRAM_ATTR button_isr_handler(void* arg) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xTaskNotifyFromISR(taskHandle, 0, eIncrement, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR();
}

void task_to_process_notification(void* arg) {
    uint32_t notifyValue;
    while (1) {
        // Wait for notification
        if (xTaskNotifyWait(0, 0, &notifyValue, portMAX_DELAY)) {
            printf("Notification received from ISR, count: %d\n", notifyValue);
        }
    }
}

void app_main() {
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_POSEDGE);  // Rising edge interrupt
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON_PIN, button_isr_handler, NULL);

    xTaskCreate(task_to_process_notification, "ProcessNotificationTask", 2048, NULL, 10, &taskHandle);
}
```

## 3. Using a Ring Buffer for Large or Variable Data
If you need to pass larger or variable-sized data from an ISR, a ring buffer is efficient and can handle continuous data streams (e.g., sensor data). The ESP-IDF provides Ringbuffer APIs specifically for this purpose, which are ISR-safe.

**Example:**
```
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/ringbuf.h"

RingbufHandle_t ringbuf;

void IRAM_ATTR isr_handler(void* arg) {
    uint32_t sampleData = 1234;
    xRingbufferSendFromISR(ringbuf, &sampleData, sizeof(sampleData), NULL);
}

void task_to_process_ringbuf_data(void* arg) {
    size_t itemSize;
    uint32_t* item;
    while (1) {
        item = (uint32_t*) xRingbufferReceive(ringbuf, &itemSize, portMAX_DELAY);
        if (item != NULL) {
            printf("Received data: %d\n", *item);
            vRingbufferReturnItem(ringbuf, item);
        }
    }
}

void app_main() {
    ringbuf = xRingbufferCreate(1024, RINGBUF_TYPE_NOSPLIT);
    if (ringbuf == NULL) {
        printf("Failed to create ring buffer\n");
        return;
    }

    // Set up ISR and tasks as needed...
}
```

## 4. Using a Shared Variable with Volatile and Atomic Access
For very simple data (e.g., a boolean flag or counter), you can use a volatile variable with atomic operations. This method is low-latency but suitable only for single-value flags or counters.

**Example:**
```
volatile bool isr_flag = false;

void IRAM_ATTR button_isr_handler(void* arg) {
    isr_flag = true;  // Set flag in ISR
}

void task_to_check_flag(void* arg) {
    while (1) {
        if (isr_flag) {
            isr_flag = false;  // Reset flag after processing
            printf("Flag set by ISR\n");
        }
        vTaskDelay(pdMS_TO_TICKS(100));  // Check every 100 ms
    }
}
```

## Summary of Methods
1. `Queue` (xQueueSendFromISR): Ideal for passing structured data to a task.
2. `Task Notification (xTaskNotifyFromISR)`: Best for signaling a specific task with minimal overhead.
3. `Ring Buffer`: Use for large or variable-sized data, especially with continuous data streams.
4. `Volatile Variable`: Use for simple flags or counters but avoid complex data.