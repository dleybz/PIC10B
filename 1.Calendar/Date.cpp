#include "Date.h"
#include<string>
using namespace std;

Date::Date(int month, int day, int year) {
	this->month = month; 
    this->day = day;
    this->year = year;
}
	
int Date::getMonth() const{
  return month;
}

int Date::getDay() const{
  return day;
}
	
int Date::getYear() const{
  return year;
}