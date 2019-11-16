#pragma once
#include "Motor.h"

class SimMotor : public Motor
{
private:
	double power = 0.0;
public:
	double get_power();
	void set_power(double power);
};

