#include "Odometry.h"

Odometry::Odometry(Encoder* encoder_left, Encoder* encoder_right)
{
	this->encoderLeft = encoder_left;
	this->encoderRight = encoder_right;
}

double Odometry::getDistance()
{
	memLeftTicks = encoderLeft->get_ticks() * MM_PER_TICK;
	memRightTicks = encoderRight->get_ticks() * MM_PER_TICK;
	// ToDo - adjust return value
	return memLeftTicks;
}

double Odometry::getHeading()
{
	return 0.0;
}

void Odometry::reset()
{
	memLeftTicks = 0;
	memRightTicks = 0;
}

double Odometry::ticksToAngle(long ticks)
{
	return 0.0;
}
