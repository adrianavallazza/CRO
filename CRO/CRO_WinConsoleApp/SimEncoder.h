#pragma once
#include <thread>
#include <atomic>
#include <chrono>
#include "SimMotor.h"
#include "Encoder.h"

class SimEncoder : public Encoder
{
private:
	std::atomic<double> ticks; // aktueller Zählerstand
	SimMotor* motor; // Motor, der den Drehgeber bewegt
	const long sim_enc_cycle_time = 100; // Zykluszeit der Simulation in Millisekunden
	const double max_rps = 1; // Maximale Drehzahl des Motors in Umdrehungen pro Sekunde
	const long resolution = 20; // Auflösung des Drehgebers
	std::thread worker_thread;
	std::atomic<bool> stop_thread; // wenn stop_thread == true, soll der Thread enden

public:
	SimEncoder(SimMotor* motor);
	~SimEncoder();
	void run();
	long get_ticks();
	void test_SimEncoder();
};

