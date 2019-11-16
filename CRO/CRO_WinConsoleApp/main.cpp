#include <iostream>
#include <chrono>
#include <thread>
#include "SimMotor.h"
#include "SimEncoder.h"
#include "DifferentialDrive.h"
#include "Odometry.h"

using namespace std;

// Testfunkton für DifferentialDrive und Odometry
void test_drive_odometry(DifferentialDrive* drive, Odometry* odometry) {
	odometry->reset();
	drive->moveForward();

	while (odometry->getDistance() < 100) {
		this_thread::sleep_for(chrono::milliseconds(100));
		cout << odometry->getDistance() << " mm" << endl;
	}
}


int main()
{
	/*
	SimMotor* m_left = new SimMotor();
	m_left->set_power(50);
	cout << "Power: " << m_left->get_power();
	delete m_left;
	*/

	SimMotor* motor_left = new SimMotor();
	SimEncoder* encoder_left = new SimEncoder(motor_left);

	encoder_left->test_SimEncoder();

	delete encoder_left;
	delete motor_left;

	return 0;
}
