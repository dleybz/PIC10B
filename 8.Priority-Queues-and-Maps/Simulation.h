#ifndef SIMULATION_H
#define SIMULATION_H

#include<vector>
#include<queue>
#include<map>
#include <functional>  
#include "Event.h"
#include "Customer.h"

using namespace std;

/**
 *  Models a discrete event simulation of customers arriving and departing
 *  from a hot dog stand with a fixed number of seats. 
 */
class Simulation {
	friend class Departure;
	friend class Arrival;

    public:
        // constructs a Simulation object and generates a rqandom number of Arrival events to add to the event_queue
		Simulation(); 
        
        // runs the siumulation by processing the events in an "event loop" in chronological order
		void run();

	private:
		double current_time;  // "system clock" holding the current time 
		vector<Customer*> seat;  // a collection of seats for the hot dog stand 
		
        /* holds arrival and departure events and compares Event* variables according 
		   to the function operator() of class mycomparison */
		priority_queue<Event*, vector<Event*>, mycomparison> event_queue;  
		
        // keeps track of when when a customer sits and how many hot dogs ordered
        // key: double: time customer seated   
        // value: int: num hot dogs purchased by that customer
        map<double, int> hot_dog_orders;
};


#endif