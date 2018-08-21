/*   Includes   */
#include "mpu_config.h"

/*   Defines   */
#define  PACKET_SIZE    42

/*   Private declarations   */

    // Vars for containing the Init statuses for mpu's
uint8_t     mpu_one_IntStatus;
float       data[3];
VectorFloat gravity;
uint8_t     buffer[64];
uint16_t    fifoCount;
Quaternion  q;

//uint8_t mpu_two_IntStatus;
//uint8_t mpu_three_IntStatus;
//uint8_t mpu_four_IntStatus;


/*   Insert Functions Here   */

mpu_setup_return_t mpu_one_setup(void){

    MPU6050 mpu_one = MPU6050();
    mpu_one.initialize();
    mpu_one.dmpInitialize();


    	// This need to be setup individually
	mpu_one.setXGyroOffset(220);
	mpu_one.setYGyroOffset(76);
	mpu_one.setZGyroOffset(-85);
	mpu_one.setZAccelOffset(1788);

	mpu_one.setDMPEnabled(true);

    mpu_one_IntStatus = mpu_one.getIntStatus();
    fifoCount = mpu_one.getFIFOCount();

    if(mpu_one_IntStatus & 0x10 || fifoCount == 1024){
        mpu_one.resetFIFO();
    }else if(mpu_one_IntStatus & 0x02){
        // Short wait for the FIFO to fill.
        while (fifoCount < PACKET_SIZE) fifoCount = mpu_one.getFIFOCount();

            mpu_one.getFIFOBytes(buffer, PACKET_SIZE);
	 		mpu_one.dmpGetQuaternion(&q, buffer);
			mpu_one.dmpGetGravity(&gravity, &q);
			mpu_one.dmpGetYawPitchRoll(data, &q, &gravity);
			printf("YAW: %3.1f, ", data[0] * 180/M_PI);
			printf("PITCH: %3.1f, ", data[1] * 180/M_PI);
			printf("ROLL: %3.1f \n", data[2] * 180/M_PI);
    }


	vTaskDelete(NULL);


}

mpu_setup_return_t mpu_two_setup(void){

}

mpu_setup_return_t mpu_three_setup(void){

}

mpu_setup_return_t mpu_four_setup(void){

}