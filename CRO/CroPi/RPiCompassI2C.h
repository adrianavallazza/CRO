#pragma once
#include "Compass.h"

class RPiCompassI2C : public Compass
{
private:
	int I2C_fd_compass;

public:
	RPiCompassI2C(int I2C_fd_compass);
	double get_direction();
};

