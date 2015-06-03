/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#include "Simulation.h"
#include "Arrival.h"
#include<ctime>
#include<iostream>
#include<iomanip>
using namespace std;

Simulation::Simulation(){
	srand(static_cast<int>(time(NULL)));
	int customerArrivals = 4; //rand()%26;
	int counter = 0;
	while(customerArrivals>counter){
		counter++;
		this->event_queue.push(new Arrival(new Customer(), this, 1.0*rand()/RAND_MAX + 0.1, "Customer is seated"));
	};
}

void Simulation::run(){
	while (event_queue.size() > 0){
		Event* next_event = event_queue.top();
		current_time = next_event->get_time();
		next_event->act();
		delete next_event;
		event_queue.pop();
	}
	cout << "Hot dog orders\n" << "time dogs\n";
	map<double, int>::iterator i;
	int totalDogs = 0;
	for(i=hot_dog_orders.begin(); i != hot_dog_orders.end(); i++){
		cout << fixed << setprecision(2) << (*i).first << " " << (*i).second << endl;
		totalDogs += (*i).second;
	}
	cout << "Total: " << totalDogs << endl;
}

