#ifndef _BLINK_H_
#define _BLINK_H_

/*   Includes   */
#include "driver/gpio.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "esp_event.h"



/*   API's   */
void blink_forever(void){
    int level = 0;
    while (true) {
        gpio_set_level(GPIO_NUM_2, level);
        level = !level;
        vTaskDelay( 1000 / portTICK_PERIOD_MS);
    }
}

#endif