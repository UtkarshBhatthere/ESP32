#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "GPIO_task.h"


void app_main()
{
    xTaskCreate(&gpio_task, "Blink task", 2048, NULL, 4, NULL);
}
