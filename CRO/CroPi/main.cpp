#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include "DifferentialDrive.h"
#include "Odometry.h"
#include "Compass.h"
#include "RPiCompassEncoder.h"
#include "RPiCompassI2C.h"
#include <iostream>

using namespace std;

#define	LED	17

const int LEDs_BCM[] = { 4, 17, 27, 5 };
const int Motor_BCM[] = { 19, 20, 21, 26 };
const int Encoder_BCM[] = { 22, 23 };


void setup_explorer_hat() {
	wiringPiSetupGpio();
	for (int i = 0; i < 4; i++) {
		pinMode(LEDs_BCM[i], OUTPUT);
		softPwmCreate(Motor_BCM[i], 0, 100);	// Motor-pins as PWM-pins with a value range between 0 and 100
	}
	pinMode(Encoder_BCM[0], INPUT);
	pinMode(Encoder_BCM[1], INPUT);
}


void move_forward(DifferentialDrive* drive, Odometry* odometry, double distance) {
	// Odometry reset
	// Drive move forward
	// until the distance is not reached:
	// this_thread::sleep(1ms)
	// Drive stop
}


void turn(DifferentialDrive* drive, Compass* compass, double direction) {
	// while robot's orientation deviates more than 3 degrees from the direction parameter
	// Drive turn right or turn left
}


int main(void)
{
	// create objects
	Odometry* odometry;

	// create compass
	Compass* compass;
	int I2C_fd_compass = wiringPiI2CSetup(0x60);
	if (wiringPiI2CReadReg8(I2C_fd_compass, 1) != -1) {
		// I2C compass available
		compass = new RPiCompassI2C(I2C_fd_compass);
		cout << "I2C compass" << endl;
	}
	else {
		compass = new RPiCompassEncoder(odometry);
		cout << "Encoder compass" << endl;
	}

	//main loop
	// endless loop
	// align robot at 0 deg with function turn
	// drive 500 mm distance forward with function move_forward
	// align robot at 180 deg with function turn
	// drive 500 mm distance backwards with function move_forward

	return 0;
}