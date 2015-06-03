#include "Departure.h"
#include<iostream>
using namespace std;

Departure::Departure(Customer* c, Simulation* s, double time, string description): Event(time, description)  {
  this->c = c;
  this->s = s;
}

Departure::~Departure(){
   delete c;
}

void Departure::act(){
	for(int i = 0; i < s->seat.size(); i++){
		if(c == s->seat[i]){
			int last = s->seat.size()-1;
			// swap customer with the last seat
			s->seat[i] = s->seat[last];
			s->seat[last] = c;
			// remove customer from the seats
			s->seat.pop_back();
		}
	}
    // print the time and reason for departure
	cout << get_description() << endl;
}