//
// Created by Wiktor on 13.07.2026.
//
#include <cstdio>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "../lib/BH1750/BH1750.h"
#include "../lib/BME280/BME280.h"

#define BLINK_GPIO GPIO_NUM_15

void init_i2c();
void i2c_scanner(i2c_master_bus_handle_t bus_handle);

static const char *TAG = "FireBeetle 2 ESP32-C6 Weather Station";

extern "C" void app_main(void) {
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    init_i2c();
    i2c_master_bus_handle_t i2c_bus_handle;
    i2c_master_get_bus_handle(I2C_NUM_0, &i2c_bus_handle);

    BH1750 *light_intensity_sensor = new BH1750();
    BME280 *temperature_sensor = new BME280();

    uint8_t led_state = 0;

    light_intensity_sensor->begin(i2c_bus_handle);
    temperature_sensor->begin(i2c_bus_handle);

    temperature_sensor->read_calib_data();

    while (true) {
        i2c_scanner(i2c_bus_handle);

        led_state = !led_state;
        // gpio_set_level(BLINK_GPIO, led_state);

        uint32_t result = light_intensity_sensor->read_light_intensity();

        ESP_LOGI(TAG, "LED: %s", (led_state == 1 ? "ON" : "OFF"));
        ESP_LOGI(TAG, "ILLUMINANCE: %u", result);

        temperature_sensor->read_weather_data();
        // temperature_sensor->print_calib_data();

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void init_i2c() {
    i2c_master_bus_handle_t bus_handle;

    constexpr i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = GPIO_NUM_19,
        .scl_io_num = GPIO_NUM_20,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .intr_priority = 0,
        .trans_queue_depth = 0,
        .flags = {},
    };

    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));
}

void i2c_scanner(i2c_master_bus_handle_t bus_handle) {
    for (uint8_t address = 0x08; address < 0x78; address++) {
        esp_err_t check_result = i2c_master_probe(bus_handle, address, -1);
        if (check_result == ESP_OK) {
            ESP_LOGI(TAG, "Found device at 0x%02X", address);
        }
    }
}
