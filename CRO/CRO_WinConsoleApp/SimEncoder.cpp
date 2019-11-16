// SimEncoder
// - simuliert einen Drehgeber.
// - hat einen zugehörigen Motor und einen Zählerstand.
// - aktualisiert abhängig von der eingestellten Leistung
// des Motors seinen Zählerstand.
// - nutzt einen Thread, um den Zählerstand im 100ms-Takt zu aktualisieren.

#include <iostream>
#include "SimEncoder.h"

using namespace std;

	// Parameter motor: Motor, der den Drehgeber bewegt
	SimEncoder::SimEncoder(SimMotor* motor) {
		stop_thread = false;
		ticks = 0;
		this->motor = motor;
		worker_thread = thread(&SimEncoder::run, this); // start thread
	}

	// Der Destruktor setzt stop_thread auf true und wartet
	// bis die run()-Methode des Thread beendet ist.
	SimEncoder::~SimEncoder() {
		stop_thread = true;
		worker_thread.join();
	}

	// run() - Methode des Threads
	// Thread läuft, bis stop_thread (vom Destruktor) auf false gesetzt wird.
	void SimEncoder::run() {
		while (!stop_thread) {
			this_thread::sleep_for(
				chrono::milliseconds(sim_enc_cycle_time));
			ticks = ticks + (((this->motor->get_power() / 100) * resolution) * ((double)sim_enc_cycle_time / 1000));
		}
	}

	// Rückgabewert: aktueller Zählerstand
	long SimEncoder::get_ticks() {
		return (long)ticks; // Typwandlung des Zählerstandes (ganze Zahl)
	}

	void SimEncoder::test_SimEncoder() {
		// Zähler von 1 bis 30
		// this_thread::sleep_for 100 Millisekunden 
		// Konsolenausgabe der verstrichenen Zeit in Millisekunden und des Zählerstandes des Encoders
		// Wenn der Zählerstand == 10, dann soll die Power des Motors auf 50 gesetzt werden
		// Wenn der Zählerstand == 20, dann soll die Power des Motors auf 100 gesetzt werden
		int elapsedTime = 0;
		int timeSteps = sim_enc_cycle_time;

		for (int i = 1; i <= 30; i++) {
			elapsedTime += timeSteps;
			cout << elapsedTime << ": " << this->get_ticks() << " ticks" << endl;

			if (i == 10) {
				motor->set_power(50);
			}

			if (i == 20) {
				motor->set_power(100);
			}

			this_thread::sleep_for(
				chrono::milliseconds(timeSteps));
		}
	}




