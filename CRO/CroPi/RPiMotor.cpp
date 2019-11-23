#include "RPiMotor.h"
#include "wiringPi.h"
#include "softPwm.h"

RPiMotor::RPiMotor(int BCM_pin1, int BCM_pin2)
{
	this->BCM_pin1 = BCM_pin1;
	this->BCM_pin2 = BCM_pin2;
	// digitalWrite(BCM_pin1, 0)
	// softPwmWrite(BCM_pin2, (int)power)
}

double RPiMotor::get_power()
{
	return power;
}

void RPiMotor::set_power(double power)
{
	this->power = power;
}
