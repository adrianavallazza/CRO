#pragma once
class DifferentialDrive
{
private:
	Motor* motorLeft;
	Motor* motorRight;

public:
	DifferentialDrive(Motor* motor_left, Motor* motor_right);
	void moveForward();
	void stop();
	void turnLeft();
	void turnRight();
};

