#include "Event.h"
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<sstream>

Event::Event(double time, string description){  
	this->time = time;
	this->description = description;
}

Event::~Event(){}

double Event::get_time()const{
	return time;
}

string Event::get_description()const{
	ostringstream os;
    os << fixed << setprecision(2);
	os << "time: " << time << " " << description;
	return os.str();
}

// will be overridden in the subclasses to do more
void Event::act(){}

double Event::get_time_later()const {
	return 1.0*rand()/RAND_MAX + time;
}

