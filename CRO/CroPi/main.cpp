#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include "DifferentialDrive.h"
#include "Odometry.h"
#include "Compass.h"
#include "RPiCompassEncoder.h"
#include "RPiCompassI2C.h"
#include "RPiMotor.h"
#include "RPiEncoder.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

#define	LED	17

#define MOTOR_RIGHT_POS 19
#define MOTOR_RIGHT_NEG 20
#define MOTOR_LEFT_POS 21
#define MOTOR_LEFT_NEG 26

#define ENCODER_RIGHT 22
#define ENCODER_LEFT 23

const int LEDs_BCM[] = { 4, 17, 27, 5 };
// const int Motor_BCM[] = { 19, 20, 21, 26 };
// const int Encoder_BCM[] = { 22, 23 };


void setup_explorer_hat() {
	wiringPiSetupGpio();
	for (int i = 0; i < 4; i++) {
		pinMode(LEDs_BCM[i], OUTPUT);
		// Motor-pins as PWM-pins with a value range between 0 and 100
		//softPwmCreate(Motor_BCM[i], 0, 100);	
	}

	pinMode(MOTOR_RIGHT_POS, OUTPUT);
	pinMode(MOTOR_RIGHT_NEG, OUTPUT);
	pinMode(MOTOR_LEFT_POS, OUTPUT);
	pinMode(MOTOR_LEFT_NEG, OUTPUT);
	softPwmCreate(MOTOR_RIGHT_POS, 0, 100);
	softPwmCreate(MOTOR_RIGHT_NEG, 0, 100);
	softPwmCreate(MOTOR_LEFT_POS, 0, 100);
	softPwmCreate(MOTOR_LEFT_NEG, 0, 100);

	// pinMode(Encoder_BCM[0], INPUT);
	// pinMode(Encoder_BCM[1], INPUT);
	 pinMode(ENCODER_RIGHT, INPUT);
	 pinMode(ENCODER_LEFT, INPUT);
}


void move_forward(DifferentialDrive* drive, Odometry* odometry, double distance) {
	int dist = 0;
	
	// Odometry reset
	odometry->reset();
	drive->moveLinear(5);
	this_thread::sleep_for(chrono::milliseconds(1));
	drive->stop();
	// dist = odometry->getDistance();
	// cout << "Distance traveled: " << dist << "mm " << endl;
	// Drive move forward
	// until the distance is not reached:
	/*while (odometry->getDistance() != distance) {
		drive->moveForward();
		this_thread::sleep_for(chrono::milliseconds(1));
	}
	drive->stop();
	*/
}


void turn(DifferentialDrive* drive, Compass* compass, double direction) {
	// while robot's orientation deviates more than 3 degrees from the direction parameter
	// Drive turn right or turn left
}

void testDriveForwardBackwards(DifferentialDrive* drive, Odometry* odometry) {

	int dist = 0;
	odometry->reset();
	drive->moveLinear(10);
	this_thread::sleep_for(chrono::milliseconds(1000));
	drive->stop();
	dist = odometry->getDistance();
	cout << "Distance traveled: " << dist << "mm " << endl;

	delay(1000);

	odometry->reset();
	drive->moveLinear(-10);
	this_thread::sleep_for(chrono::milliseconds(1000));
	drive->stop();
	dist = odometry->getDistance();
	cout << "Distance traveled: " << dist << "mm " << endl;
	// RPiMotor::turnOffAll();
}

int main(void)
{
	setup_explorer_hat();

	// create objects
	RPiMotor* motorRight = new RPiMotor(MOTOR_RIGHT_POS, MOTOR_RIGHT_NEG);
	RPiMotor* motorLeft = new RPiMotor(MOTOR_LEFT_POS, MOTOR_LEFT_NEG);
	RPiEncoder* encoderRight = new RPiEncoder(ENCODER_RIGHT);
	RPiEncoder* encoderLeft = new RPiEncoder(ENCODER_LEFT);

	Odometry* odometry = new Odometry(encoderLeft, encoderRight);
	DifferentialDrive* drive = new DifferentialDrive(motorLeft, motorRight);


	// create compass
	//Compass* compass;
	//int I2C_fd_compass = wiringPiI2CSetup(0x60);
	//if (wiringPiI2CReadReg8(I2C_fd_compass, 1) != -1) {
	//	// I2C compass available
	//	compass = new RPiCompassI2C(I2C_fd_compass);
	//	cout << "I2C compass" << endl;
	//}
	//else {
	//	compass = new RPiCompassEncoder(odometry);
	//	cout << "Encoder compass" << endl;
	//}

	//main loop
	// endless loop
	//while (true) {

	//}
	// align robot at 0 deg with function turn
	// drive 500 mm distance forward with function move_forward
	move_forward(drive, odometry, 500);
	// testDriveForwardBackwards();
	// align robot at 180 deg with function turn
	// drive 500 mm distance backwards with function move_forward

	return 0;
}