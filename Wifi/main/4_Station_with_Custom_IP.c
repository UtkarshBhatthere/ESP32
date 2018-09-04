#include "main.h"
/*   STATUS : INCOMPLETE   */
/*    The device is not calling the handler, may it be that the dhcp stop did something, check.      */

#ifdef __USE_FOUR_ // main control
#include "GPIO_task.h"

void app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    tcpip_adapter_dhcpc_stop(TCPIP_ADAPTER_IF_STA); // Stops the DHCP Client.
    tcpip_adapter_ip_info_t dhcp_conf;
    IP4_ADDR(&(dhcp_conf.ip), 192,168,17,121);
    IP4_ADDR(&(dhcp_conf.gw), 192,168,1,1);
    IP4_ADDR(&(dhcp_conf.ip), 255,255,255,0);
    tcpip_adapter_set_ip_info(TCPIP_ADAPTER_IF_STA, &dhcp_conf);
    tcpip_adapter_dhcpc_start(TCPIP_ADAPTER_IF_STA);
    
    ESP_ERROR_CHECK(esp_event_loop_init(wifi_connect_handler, NULL));
    ESP_ERROR_CHECK(wifi_setup());

    //A never ending blink loop!
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 5, NULL);

}


#endif