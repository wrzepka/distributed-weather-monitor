#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define BLINK_GPIO GPIO_NUM_15

static const char *TAG = "Boilerplate Program";

void app_main(void) {
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    uint8_t led_state = 0;

    while (1) {
        led_state = !led_state;
        gpio_set_level(BLINK_GPIO, led_state);

        ESP_LOGI(TAG, "LED: %s", (led_state == 1 ? "ON" : "OFF"));

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}