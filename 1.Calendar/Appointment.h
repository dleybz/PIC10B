#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Date.h"
#include<string>
using namespace std;

class Appointment{

	public:
		Appointment(string description, int month, int day, int yr, int hr, int min);

		virtual bool occurs_on(int month, int day, int year) const = 0;

		virtual void print() const;

		

	protected:
		Date getDate() const;

	private:
		string description;
	    string convertInt(int number) const;
		int hr;
		int min;
		Date date;

};
#endif