#ifndef DATE_H
#define DATE_H

#include<string>
using namespace std;

class Date{

  public:
	Date(int month, int day, int year);

	int getMonth() const;
	int getDay() const; 
	int getYear() const;

  private:
	int month;
	int day;
	int year;
};

#endif