#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "tcpip_adapter.h"
#include "wifi_config.h"
#include "blink.h"



void app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(wifi_connect_handler, NULL));

    ESP_ERROR_CHECK(wifi_setup());
    ESP_ERROR_CHECK(start_scan(wifi_scan_initialiser()));
    //A never ending blink loop!
    blink_forever();
}