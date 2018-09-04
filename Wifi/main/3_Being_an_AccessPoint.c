#include "main.h"
/*   STATUS : COMPLETE   */

#ifdef __USE_THREE_ // main control
#include "GPIO_task.h"


void app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(wifi_ap_handler, NULL));
    ESP_ERROR_CHECK(wifi_setup());

    //A never ending blink loop!
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 5, NULL);

}
#endif // main control