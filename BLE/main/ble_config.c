#include "ble_config.h"

#define UUIDTOPOINTER(u128, p) for(int k = 0;k<16;k++){ *(p++) = (uint8_t)u128; u128 = (uint8_t)((u128) >> 8)} 

esp_err_t ble_setup(void){
    //Default configuration for bluetooth initialisation.
    esp_bt_controller_config_t ble_config = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    //Initialising the hardware with the above configuration.
    esp_bt_controller_init(&ble_config);
    //Enabling the hardware.
    esp_bt_controller_enable(ESP_BT_MODE_BLE);
    //Releasing the memory for unused bt harware (BT_CLASSIC).
    esp_bt_controller_mem_release(ESP_BT_MODE_BTDM);
    //Setting up device name.
    esp_ble_gap_set_device_name("ESP");

    return ESP_OK;
}

esp_err_t ble_setup_advertising(void){

    esp_ble_gap_register_callback(setup_handler);
    static esp_ble_adv_data_t adv_conf = {
        .set_scan_rsp = false,
        .include_name = true,
        .include_txpower = true,
        .min_interval = 0x20,
        .max_interval = 0x40,
        .appearance = 0x00,
        .manufacturer_len = 0,
        .p_manufacturer_data = NULL,
        .service_data_len = 0,
        .p_service_data = NULL,
        .service_uuid_len = 32, 
        .p_service_uuid = 0x04
    };

    esp_ble_gap_config_adv_data(&adv_conf);
    return ESP_OK;
}

esp_err_t ble_advertise(void){
    esp_ble_adv_params_t adv = {
        .adv_type = ADV_TYPE_IND,
        .adv_int_min = 0X20,
        .adv_int_max = 0x40,
        .channel_map = ADV_CHNL_ALL,
        .own_addr_type = BLE_ADDR_TYPE_PUBLIC,
        .peer_addr_type = BLE_ADDR_TYPE_PUBLIC,
        .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
        .peer_addr = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85}
    };
    esp_ble_gap_start_advertising(&adv);

    return ESP_OK;
}

esp_gap_ble_cb_t setup_handler(){
    printf("The setup process is complete.");
    return ESP_GAP_BLE_ADV_START_COMPLETE_EVT;
}