#ifndef DEPARTURE_H
#define DEPARTURE_H

#include "Event.h"
#include "Customer.h"
#include "Simulation.h"

/**
 * Models a customer departure.
 */
class Departure : public Event {
	public:
		Departure(Customer* c, Simulation* s, double time, string description);
		~Departure(); // deallocates its customer
        
		// performs an action
		virtual void act();
		
	private:
		Customer* c;
		Simulation* s;
		
		
};

#endif