// Put this as #if 1 for this main code to work, and #if 0 in the rest .c files containing app_main().
#include "main.h"
#ifdef __USE_ONE_

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
#include "GPIO_task.h"


void app_main(void)
{
    
    nvs_flash_init();
    tcpip_adapter_init();

    ESP_ERROR_CHECK(esp_event_loop_init(wifi_scan_handler , NULL))
    ESP_ERROR_CHECK(wifi_setup());
    ESP_ERROR_CHECK(start_scan(wifi_scan_initialiser()));
    //A never ending blink loop!
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 5, NULL);
    
}

#endif //Code Control.