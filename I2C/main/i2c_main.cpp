/*   Includes   */
#include "i2c_main.h"

void app_main(void){

    xTaskCreate(&i2c_setup, "I2C Setup", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
    vTaskDelay(100/portTICK_PERIOD_MS);
    xTaskCreate(&mpu_one_setup, "MPU sensor one setup", configMINIMAL_STACK_SIZE, NULL, 4, NULL);
    
}

