/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#include "Arrival.h"
#include "Simulation.h"
#include "Departure.h"
#include<iostream>
#include<iomanip>
#include<map>
#include<cstdlib>
using namespace std;

const int HOTDOG_STAND_SIZE = 3; //the number of seats at the stand

Arrival::Arrival(Customer* c, Simulation* s, double time, string description): Event(time, description){
	this->c = c;
	this->s = s;
}

void Arrival::act(){

	if(HOTDOG_STAND_SIZE > s->seat.size()){ //checks if the hot dog stand is full
		cout << "time: " << fixed << setprecision(2) << get_time() << " Customer is seated." << endl; //prints out the time that the customer was seated and that they were seated
		int numberOfDogs = (rand() % 4) + 1; //creates a random number of dogs that the customer ordered
		s->hot_dog_orders[get_time()] = numberOfDogs; //adds the number of dogs ordered to the map as the value, with its associated time as the key 
		s->seat.push_back(c); //adds Customer c to the hot dog stand
		s->event_queue.push(new Departure(c, s, get_time_later(), "Customer finishes eating, leaves")); //pushes the departure associated with that customer into the event queue
	} else {
		s->event_queue.push(new Departure(c, s, get_time_later(), "Customer unable to find a seat, leaves.")); //if the stand is full when the customer arrives, pushes the customer's departure into the event queue
	}
}