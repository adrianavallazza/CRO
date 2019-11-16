#pragma once
class Motor
{
public:
	virtual ~Motor() {};
	virtual void set_power(double power) = 0;
	virtual double get_power() = 0;
};

