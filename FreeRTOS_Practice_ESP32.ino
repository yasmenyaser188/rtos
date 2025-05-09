#include <Arduino.h>

#define LED_PIN 2  // Built-in LED for ESP32

void TaskBlink(void *pvParameters) {
  pinMode(LED_PIN, OUTPUT);
  while (1) {
    digitalWrite(LED_PIN, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED_PIN, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void TaskSerialPrint(void *pvParameters) {
  while (1) {
    Serial.println("Task 2: Sending message...");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);

  xTaskCreate(TaskBlink, "LED Blink", 1024, NULL, 1, NULL);
  xTaskCreate(TaskSerialPrint, "Serial Print", 1024, NULL, 1, NULL);
}

void loop() {
  // Empty. Tasks run independently.
}
