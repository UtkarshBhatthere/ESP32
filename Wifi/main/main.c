#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "wifi_config.h"


void app_main(void)
{
    
    nvs_flash_init();
    tcpip_adapter_init();

    ESP_ERROR_CHECK(esp_event_loop_init(wifi_event_handler , NULL))
    wifi_setup();

    xTaskCreate(&start_scan, "Wifi Scan Task", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    int level = 0;
    while (true) {
        gpio_set_level(GPIO_NUM_2, level);
        level = !level;
        vTaskDelay( 1000 / portTICK_PERIOD_MS);
    }
}

