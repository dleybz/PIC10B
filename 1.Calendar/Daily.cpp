#include "Daily.h"
#include "Date.h"
#include <iostream>
#include<string>
using namespace std;

Daily::Daily(string description, int month, int day, int yr, int hr, int min)
	: Appointment(description, month, day, yr, hr, min)
{
}
	
bool Daily::occurs_on(int month, int day, int year) const{
	return true;
}

void Daily::print() const{
	Appointment::print();
	cout << " (Daily)\n";
}