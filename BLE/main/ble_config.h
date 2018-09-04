#ifndef _BLE_CONFIG_H_
#define _BLE_CONFIG_H_

#include "esp_bt.h"
#include "esp_gap_ble_api.h"

/*   API's   */
esp_err_t ble_setup(void);
esp_err_t ble_setup_advertising(void);
esp_err_t ble_advertise(void);
esp_gap_ble_cb_t setup_handler();




#endif //_BLE_CONFIG_H_