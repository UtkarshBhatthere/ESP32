#ifndef _WIFI_CONFIG_H_
#define _WIFI_CONFIG_H_

/*   Includes   */
#include "esp_wifi.h"

/*   API's   */

// Initializes the wifi!
esp_err_t wifi_setup(void){
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
    return ESP_OK;
}

//Is a callback when a wifi event happens.
// Event Includes :-
//    a)  Connecting/Disconnecting to a Access Point.
//    b)  Some device connecting/disconnecting in AP mode.
//    c)  Wifi Scan complete.
//    d)  Auth mode change.
esp_err_t wifi_event_handler(void *ctx, system_event_t *event){
    if(event->event_id == SYSTEM_EVENT_SCAN_DONE){

        //Storing number of available wifi Access Points.
        int num = event->event_info.scan_done.number;
        printf(" Total number of Wifi AP's found is : %d\n", num);

        wifi_ap_record_t *records = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t)*num);
        ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&num, records));

        for(int i = 0; i<num; i++){
            printf(" WIFI_NAME : %s, WIFI_RSSI: %d, WIFI_AUTHMODE: %d\n", records[i].bssid, records[i].rssi, records[i].authmode);
          #if 0 
            if(records[i].authmode = WIFI_AUTH_OPEN){
                printf("\t\tTrying to connect to this wifi since it's open");
                wifi_ap
                ESP_ERROR_CHECK();
            }
          #endif //Connect_Control.  
        }
        free(records);

    }
    return ESP_OK;
}

TaskFunction_t start_scan(void){
    wifi_scan_config_t scancon = {
        .ssid = NULL,
        .bssid = NULL,
        .channel = 0,
        .show_hidden = 1
    };
    // First Parameter is scan config var next param is block_bool if true it will block the caller until the scan is done.
    ESP_ERROR_CHECK(esp_wifi_scan_start(&scancon, 1));
    return NULL;
}

/*   Tasks   */


#endif  //_WIFI_CONFIG_H_