#include <stdio.h>
#include "test.h"
#include "RTIMULib.h"

int main(int arc, char* args[]) {
	RTIMUSettings* settings = new RTIMUSettings("RTIMULib");
	RTIMU *imu = RTIMU::createIMU(settings);
	RTIMU_DATA imuData;
	if ((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL)) {
        	printf("No IMU found\n");
        	exit(1);
	}
	imu->IMUInit();
	imu->setSlerpPower(0.02);
	imu->setGyroEnable(true);
	imu->setAccelEnable(true);
	imu->setCompassEnable(true);
	imu->IMURead();
	imuData = imu->getIMUData();
	printf("roll: %f\n", imuData.fusionPose.x());
}
