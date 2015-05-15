#include "Yearly.h"
#include "Date.h"
#include <iostream>
#include<string>
using namespace std;

Yearly::Yearly(string description, int month, int day, int yr, int hr, int min)
	: Appointment(description, month, day, yr, hr, min)
{
}
	
bool Yearly::occurs_on(int month, int day, int year) const{
	Date d = getDate();
	return (month == d.getMonth() && day == d.getDay());
}

void Yearly::print() const{
	Appointment::print();
	cout << " (Yearly)\n";
}