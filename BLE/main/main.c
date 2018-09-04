#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "tcpip_adapter.h"
#include "ble_config.h"
#include "GPIO_task.h"


void app_main(void)
{
    nvs_flash_init();
    ble_setup();
    ble_advertise();

    //A never ending blink loop!
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 5, NULL);
    
}

