#pragma once
class Encoder
{
public:
	virtual ~Encoder() {};
	virtual long get_ticks() = 0;
};

