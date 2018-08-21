#ifndef _I2C_CONFIG_H
#define _I2C_CONFIG_H

/*   Defines   */
#define         MAX_DATA_LENGTH             65536
#define         TEST_RW_LENGTH              320
#define         DELAY                       500
#define         I2C_MASTER_ONE_I2C_NUM      I2C_NUM_0
#define         I2C_MASTER_ONE_SCL          19
#define         I2C_MASTER_ONE_SDA          18
#define         I2C_MASTER_TWO_I2C_NUM      I2C_NUM_1
#define         I2C_MASTER_TWO_SCL          26
#define         I2C_MASTER_TWO_SDA          25
#define         I2C_MASTER_SPEED            100000
#define         I2C_MASTER_RX_BUFFER_LEN    0
#define         I2C_MASTER_TX_BUFFER_LEN    0

/*   Includes   */
#include "driver/i2c.h"
#include "i2c_task.h"

/*   Private declarations   */

/*   Insert Functions Here   */
void i2c_setup(void);

#endif