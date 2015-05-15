#include "OneTime.h"
#include "Date.h"
#include <iostream>
#include<string>
using namespace std;

OneTime::OneTime(string description, int month, int day, int yr, int hr, int min)
	: Appointment(description, month, day, yr, hr, min)
{
}
	
bool OneTime::occurs_on(int month, int day, int year) const{
	Date d = getDate();
	return (month == d.getMonth() && day == d.getDay() && year == d.getYear());
}

void OneTime::print() const{
	Appointment::print();
	cout << " (One Time)\n";
}