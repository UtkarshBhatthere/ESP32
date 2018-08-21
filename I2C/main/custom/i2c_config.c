/*   Includes   */
#include "i2c_config.h"

/*   Insert Functions Here   */
void i2c_setup_task(void){

    /*   Private config variables   */
    i2c_config_t i2c_conf_one, i2c_conf_two; 

    /*   Setup for Master one   */
    i2c_conf_one.scl_io_num = I2C_MASTER_ONE_SCL;
    i2c_conf_one.sda_io_num = I2C_MASTER_ONE_SDA;
    i2c_conf_one.sda_pullup_en = GPIO_PULLDOWN_ENABLE;
    i2c_conf_one.scl_pullup_en = GPIO_PULLDOWN_ENABLE;
    i2c_conf_one.mode = I2C_MODE_MASTER;
    i2c_conf_one.master.clk_speed = I2C_MASTER_SPEED;

    /*   Setup for Master two   */
    i2c_conf_two.scl_io_num = I2C_MASTER_ONE_SCL;
    i2c_conf_two.sda_io_num = I2C_MASTER_ONE_SDA;
    i2c_conf_two.sda_pullup_en = GPIO_PULLDOWN_ENABLE;
    i2c_conf_two.scl_pullup_en = GPIO_PULLDOWN_ENABLE;
    i2c_conf_two.mode = I2C_MODE_MASTER;
    i2c_conf_two.master.clk_speed = I2C_MASTER_SPEED;

    /*   Parmaeter configutration   */
    ESP_ERROR_CHECK(i2c_param_config(I2C_MASTER_ONE_I2C_NUM, &i2c_conf_one));
    ESP_ERROR_CHECK(i2c_param_config(I2C_MASTER_TWO_I2C_NUM, &i2c_conf_two));

    /*   Installing Master One Drivers   */
    ESP_ERROR_CHECK(i2c_driver_install(I2C_MASTER_ONE_I2C_NUM, I2C_MODE_MASTER, 0, 0, 0));

    /*   Installing Master Two Drivers   */
    ESP_ERROR_CHECK(i2c_driver_install(I2C_MASTER_TWO_I2C_NUM, I2C_MODE_MASTER, 0, 0, 0));

    /*   Deleting task for one time scheduling   */
    vTaskDelete(NULL);
}