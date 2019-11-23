#include "RPiCompassEncoder.h"

RPiCompassEncoder::RPiCompassEncoder(Odometry* odometry)
{
	this->odometry = odometry;
}

double RPiCompassEncoder::get_direction()
{
	return 0.0;
}
