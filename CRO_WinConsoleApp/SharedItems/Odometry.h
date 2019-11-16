#pragma once
class Odometry
{
private:
	Encoder* encoderLeft;
	Encoder* encoderRight;
	long memLeftTicks;
	long memRightTicks;
	const double MM_PER_TICK = 207.0 / 20.0;
	const double PI = 3.141592654;
	const double WHEEL_DISTANCE = 131;

public:
	Odometry(Encoder* encoder_left, Encoder* encoder_right);
	double getDistance();
	double getHeading();
	void reset();
	double ticksToAngle(long ticks);
};

