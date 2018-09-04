#ifndef _MAIN_H_
#define _MAIN_H_

/* Uncomment the #define according to the main file you wish to use. */

//#define __USE_ONE_
//#define __USE_TWO_
//#define __USE_THREE_
//#define __USE_FOUR_
#define __USE_FIVE_

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "tcpip_adapter.h"
#include "wifi_config.h"

/*   Defines   */
#define CONNECTED_BIT BIT0


/*   Events   */
EventGroupHandle_t http_handle;


#endif // _MAIN_H_