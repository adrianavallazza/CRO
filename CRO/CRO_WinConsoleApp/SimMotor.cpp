#include "SimMotor.h"

double SimMotor::get_power()
{
	return power;
}

void SimMotor::set_power(double power)
{
	if (power >= 0 && power <= 100) {
		this->power = power;
	}
	else {
		this->power = 0.0;
	}
}
