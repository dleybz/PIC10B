#ifndef ARRIVAL_H
#define ARRIVAL_H

#include<string>
#include "Event.h"
#include "Customer.h"
#include "Simulation.h"
using namespace std;

/**
 * Models a customer arrival.
 */
class Arrival: public Event {

	public:
		Arrival(Customer* c, Simulation* s, double time, string description);

        // performs an action
		virtual void act();

	private:
		Simulation* s;
		Customer* c;
};

#endif