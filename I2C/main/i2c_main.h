#ifndef _I2C_MAIN_H_
#define _I2C_MAIN_H_

/*  Includes   */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "mpu_config.h"
#include "i2c_config.h"

/*   Insert Functions Here   */
extern void i2c_setup(void);
extern void mpu_one_setup(void);

#endif