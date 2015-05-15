#include "Monthly.h"
#include "Date.h"
#include<iostream>
#include<string>
using namespace std;

Monthly::Monthly(string description, int month, int day, int yr, int hr, int min)
	: Appointment(description, month, day, yr, hr, min)
{
}
	
bool Monthly::occurs_on(int month, int day, int year) const{
	Date d = getDate();
	return (day == d.getDay());
}

void Monthly::print() const{
	Appointment::print();
	cout << " (Monthly)\n";
}