#include "RPiCompassI2C.h"

RPiCompassI2C::RPiCompassI2C(int I2C_fd_compass)
{
	this->I2C_fd_compass = I2C_fd_compass;
}

double RPiCompassI2C::get_direction()
{
	return 0.0;
}
