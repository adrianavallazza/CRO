#pragma once
#include "Encoder.h"
#include <atomic>
#include <thread>
#include <wiringPi.h>
#include <chrono>

using namespace std;

class RPiEncoder : public Encoder
{
private:
	int BCM_pin;
	atomic<bool> stop_thread;
	atomic<long> ticks;
	thread worker_thread;

public:
	RPiEncoder(int BCM_pin);
	~RPiEncoder();
	long get_ticks();
	void run();
};

