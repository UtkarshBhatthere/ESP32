#ifndef _I2C_TASK_H
#define _I2C_TASK_H

/*   Defines   */
#define         WRITE_BIT              I2C_MASTER_WRITE
#define         READ_BIT               I2C_MASTER_READ
#define         ACK_VAL                OXO0
#define         NACK_VAL               OXO1
#define         ACK_CHECK_EN           OXO1
#define         ACK_CHECK_DIS          OXO0
#define         SENSOR_ONE_ADDR        OX68
#define         SENSOR_TWO_ADDR        OX69
#define         SENSOR_THREE_ADDR      OX68
#define         SENSOR_FOUR_ADDR       OX69

/*   Includes   */
#include "driver/i2c.h"
#include "MPU6050.h"
#include "MPU6050_9Axis_MotionApps41.h"

/*   Structures and Enumerations   */
typedef enum task_return_t {
    task_successfull = 1,
    task_unsuccessfull = !task_successfull
};

/*   Insert Functions Here   */
#if 0
/**   @brief: Fetches data from sensor one and stores in the buffer with sensor number tag.   */
task_return_t sensor_one_fetch_task();

/**   @brief: Fetches data from sensor two and stores in the buffer with sensor number tag.   */
task_return_t sensor_two_fetch_task();

/**   @brief: Fetches data from sensor three and stores in the buffer with sensor number tag.   */
task_return_t sensor_three_fetch_task();

/**   @brief: Fetches data from sensor four and stores in the buffer with sensor number tag.   */
task_return_t sensor_four_fetch_task();
#endif

#endif