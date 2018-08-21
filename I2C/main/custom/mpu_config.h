#ifndef _MPU_CONFIG_H_
#define _MPU_CONFIG_H_

/*   Includes   */
#include "MPU6050.h"
#include "MPU6050_9Axis_MotionApps41.h"
#include "mdns/test_afl_fuzz_host/esp32_compat.h"

/*   Private declarations   */


/*   Enumerations   */
typedef enum mpu_setup_return_t{
    successfull = 2,
    unsuccessful= !successfull
};

/*   Insert Functions Here   */

mpu_setup_return_t mpu_one_setup(void);

mpu_setup_return_t mpu_two_setup(void);

mpu_setup_return_t mpu_three_setup(void);

mpu_setup_return_t mpu_four_setup(void);

#endif