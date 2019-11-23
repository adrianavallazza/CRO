#pragma once
#include "Motor.h"

class RPiMotor : public Motor
{
private:
	int BCM_pin1;
	int BCM_pin2;
	double power;
public:
	RPiMotor(int BCM_pin1, int BCM_pin2);
	double get_power();
	void set_power(double power);
};

