#include "Appointment.h"
#include "Date.h"
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

Appointment::Appointment(string description, int month, int day, int yr, int hr, int min): date(month, day, yr), description(description)
{
	this->hr = hr;
	this->min = min;
}



void Appointment::print() const{
	string stylizedHour;
	if (hr > 9){
		stylizedHour = convertInt(hr);
	}
	else
	{
		stylizedHour = "0" + convertInt(hr);
	}

	string stylizedMinute;
	if (min > 9){
		stylizedMinute = convertInt(min);
	}
	else
	{
		stylizedMinute = "0" + convertInt(min);
	}

	cout << stylizedHour + ":" + stylizedMinute + " -> " + description;
}

string Appointment::convertInt(int number) const{
	stringstream ss;
	ss << number;
	return ss.str();
}

Date Appointment::getDate() const{
	return date;
}

