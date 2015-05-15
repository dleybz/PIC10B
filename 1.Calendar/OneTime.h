#ifndef ONETIME_H
#define ONETIME_H

#include "Date.h"
#include "Appointment.h"
#include<string>
using namespace std;

class OneTime : public Appointment{

	public:
		OneTime(string description, int month, int day, int yr, int hr, int min);

		bool occurs_on(int month, int day, int year) const;

		void print() const;
};

#endif