#include "DifferentialDrive.h"

DifferentialDrive::DifferentialDrive(Motor* motor_left, Motor* motor_right)
{
  motorLeft = motor_left;
  motorRight = motor_right;
}

void DifferentialDrive::moveLinear(int p)
{
	// ToDo power as parameter
	// int absPower = p * (-1);
	if (p >= -100 && p <= 100) 
	{
		motorLeft->set_power(p);
		motorRight->set_power(p);
	}
}

void DifferentialDrive::stop()
{
	motorLeft->set_power(0);
	motorRight->set_power(0);
}

void DifferentialDrive::turnLeft()
{
	int power = 50;
	motorRight->set_power(power);
	motorLeft->set_power(-power);
	// ToDo stop
}

void DifferentialDrive::turnRight()
{
	int power = 50;
	motorLeft->set_power(power);
	motorRight->set_power(-power);
	// ToDo stop
}
