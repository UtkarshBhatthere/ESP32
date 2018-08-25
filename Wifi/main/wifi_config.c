/*   Includes   */
#include "wifi_config.h"

/*   Static API's   */

static void print_avaiable_AP(uint16_t num){
    wifi_ap_record_t *records = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t)*num);
        ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&num, records));

        for(int i = 0; i<num; i++){
            printf(" WIFI_NAME : %s, WIFI_RSSI: %d, WIFI_AUTHMODE: %d\n", records[i].bssid, records[i].rssi, records[i].authmode); 
        }
    free(records);
}

static wifi_config_t set_station(void){
    wifi_config_t sta_conf = {
        .sta = {
        .ssid = "Test",
        .password = "qwertyuiop",
        .bssid_set = 0
        }
    };
    return sta_conf;
}



/*   API's   */

//Initialises the wifi_scan_config_t to default values.
wifi_scan_config_t wifi_scan_initialiser(void){
    wifi_scan_config_t def = {
    .ssid = NULL,
    .bssid = NULL,
    .channel = 0,
    .show_hidden = 1};
    return def;
}

// Initializes the wifi!
esp_err_t wifi_setup(void){
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    wifi_config_t station = set_station();
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &station));
    ESP_ERROR_CHECK(esp_wifi_start());
    return ESP_OK;
}

//Is a callback when a wifi event happens.
// Event Includes :-
//    a)  Connecting/Disconnecting to a Access Point.
//    b)  Some device connecting/disconnecting in AP mode.
//    c)  Wifi Scan complete.
//    d)  Auth mode change.
esp_err_t wifi_scan_handler(void *ctx, system_event_t *event){
    if(event->event_id == SYSTEM_EVENT_SCAN_DONE){

        //Storing number of available wifi Access Points.
        uint16_t num = event->event_info.scan_done.number;
        printf(" Total number of Wifi AP's found is : %d\n", num);
        print_avaiable_AP(event->event_info.scan_done.number);
    }
    return ESP_OK;
}

esp_err_t wifi_connect_handler(void *ctx, system_event_t *event){
    if(event->event_id == SYSTEM_EVENT_SCAN_DONE){
        if(event->event_info.scan_done.number){
            printf("%d Wifi Hotspots found\n", event->event_info.scan_done.number);
            print_avaiable_AP(event->event_info.scan_done.number);
            ESP_ERROR_CHECK(esp_wifi_connect());
        }else
            printf("Sorry, No Wifi Hotspots found");
    }
    if((event->event_id == SYSTEM_EVENT_STA_CONNECTED)){
        printf("System Connected to given WiFi Hotspot.");
    }
    if(event->event_id == SYSTEM_EVENT_STA_GOT_IP){
        printf("Our IP address is " IPSTR "\n",IP2STR(&event->event_info.got_ip.ip_info.ip));
        printf("Happy Surfing!\n");
    }
    return ESP_OK;
}

esp_err_t start_scan(wifi_scan_config_t scancon){
    // First Parameter is scan config var next param is block_bool if true it will block the caller until the scan is done.
    ESP_ERROR_CHECK(esp_wifi_scan_start(&scancon, 1));
    return ESP_OK;
}


/*   Tasks   */

TaskFunction_t task_scan(void){
   ESP_ERROR_CHECK(start_scan(wifi_scan_initialiser()));
    return NULL;
}