#ifndef _WIFI_CONFIG_H_
#define _WIFI_CONFIG_H_

/*   Includes   */
#include "esp_wifi.h"
#include "main.h"
#include <string.h>
#include "tcpip_adapter.h"


#ifndef __USE_ONE_
    #ifndef __USE_TWO_
            #ifndef __USE_THREE_
                #ifndef __USE_FOUR_
                    #ifndef __USE_FIVE_
                        // Fill this.
                    #endif
                    #ifdef __USE_FIVE_
                        #define __CONNECT
                        #define __STATION
                    #endif
                #endif
                #ifdef __USE_FOUR_
                    #define __CONNECT
                    #define __STATION
                #endif
            #endif
            #ifdef __USE_THREE_
                #define __BROADCAST
                #define __ACCESSPOINT
            #endif
    #endif
    #ifdef __USE_TWO_
        #define __CONNECT
        #define __STATION
    #endif
#endif
#ifdef __USE_ONE_
    #define __SCAN
    #define __STATION
#endif

/*   Static API's   */
static void wifi_print_avaiable_AP(uint16_t num);
static wifi_config_t wifi_set_station(void);
static wifi_config_t wifi_set_accesspoint(void);
static void wifi_check_required_AP(wifi_ap_record_t *records, int number, wifi_config_t param);

/*   API's   */

//Initialises the wifi_scan_config_t to default values.
wifi_scan_config_t wifi_scan_initialiser(void);

// Initializes the wifi!
esp_err_t wifi_setup(void);
esp_err_t start_scan(wifi_scan_config_t scancon);

//Is a callback when a wifi event happens.
// Event Includes :-
//    a)  Connecting/Disconnecting to a Access Point.
//    b)  Some device connecting/disconnecting in AP mode.
//    c)  Wifi Scan complete.
//    d)  Auth mode change.
esp_err_t wifi_scan_handler(void *ctx, system_event_t *event);

esp_err_t wifi_connect_handler(void *ctx, system_event_t *event);

esp_err_t wifi_ap_handler(void *ctx, system_event_t *event);

esp_err_t wifi_http_req_handler(void *ctx, system_event_t *event);


/*   Tasks   */

TaskFunction_t task_scan(void);

#endif  //_WIFI_CONFIG_H_