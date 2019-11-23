#include "RPiEncoder.h"

RPiEncoder::RPiEncoder(int BCM_pin)
{
	this->BCM_pin = BCM_pin;
}

RPiEncoder::~RPiEncoder()
{
	stop_thread = true;
	worker_thread.join();
}

long RPiEncoder::get_ticks()
{
	return ticks;
}

void RPiEncoder::run()
{
	int edge = 0;
	while (!stop_thread) {
		edge = digitalRead(BCM_pin);
		if (edge == 1) {
			ticks++;	// rising edge
		}

		this_thread::sleep_for(chrono::milliseconds(1));
	}
}
