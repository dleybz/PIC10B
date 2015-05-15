#ifndef YEARLY_H
#define YEARLY_H

#include "Date.h"
#include "Appointment.h"
#include <string>
using namespace std;

class Yearly : public Appointment{

	public:
		Yearly(string description, int month, int day, int yr, int hr, int min);

		bool occurs_on(int month, int day, int year) const;

		void print() const;

};

#endif