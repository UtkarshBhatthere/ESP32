#include "main.h"
/*   STATUS : COMPLETE   */

#ifdef __USE_TWO_ //main Control
#include "GPIO_task.h"

void app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(wifi_connect_handler, NULL));

    ESP_ERROR_CHECK(wifi_setup());
    ESP_ERROR_CHECK(start_scan(wifi_scan_initialiser()));
    //A never ending blink loop!
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 5, NULL);

}

#endif //main Control