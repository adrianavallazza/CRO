#pragma once
#include "Motor.h"

class DifferentialDrive
{
private:
	 Motor* motorLeft;
	 Motor* motorRight;

public:
	DifferentialDrive(Motor* motor_left, Motor* motor_right);
	void moveLinear(int power);
	void stop();
	void turnLeft();
	void turnRight();
};

