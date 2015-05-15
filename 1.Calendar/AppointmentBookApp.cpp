#include<iostream>
#include<string>
#include<vector>
#include "Appointment.h"
#include "OneTime.h"
#include "Daily.h"
#include "Monthly.h"
#include "Yearly.h"
using namespace std;

void checkAppointments(vector<Appointment*>& apptbook){
	cout << "Enter a date: in the form: mm dd yyyy\n";
	int month;
	int day;
	int yr;
	cin >> month >> day >> yr;

	for(int i = 0; i < apptbook.size(); i++){
		if(apptbook[i]->occurs_on(month, day, yr)) apptbook[i]->print();
	}
}
void addAppointment(vector<Appointment*>& apptbook){
  cout << "Enter a date and time: in the form: mm dd yyyy hr min\n";
  int month;
  int day;
  int yr;
  int hr;
  int min;
  cin >> month >> day >> yr >> hr >> min;

  string trash;
  getline(cin, trash);

  cout << "Enter a description:\n";
  string description;
  getline(cin, description);

  cout << "Which type of appointment?\n";
  cout << "Enter (1) for OneTime, (2) for Daily, (3) for Monthly, (4) for Yearly: ";
  int type;
  cin >> type;

 

  if (type == 1) {
  apptbook.push_back(new OneTime(description, month, day, yr, hr, min)); 
  }

  if (type == 2) {
  apptbook.push_back(new Daily(description, month, day, yr, hr, min));
  }

  if (type == 3) {
  apptbook.push_back(new Monthly(description, month, day, yr, hr, min)); 
  }

  if (type == 4) {
  apptbook.push_back(new Yearly(description, month, day, yr, hr, min)); 
  }

}
 

int main(){

  vector<Appointment*> apptbook;
  
  char option;

  do {
     cout << "********** Appointment Book Application ************" << endl<< endl;
     cout << "(a) See all appointments on a given day." << endl;
     cout << "(b) Add an appointment." << endl << endl;
     cout << "Enter an option or 'q' to quit: ";
 
     cin >> option;
     switch(option){
	    case 'a': 
			checkAppointments(apptbook);
            break;
		case 'b':
			addAppointment(apptbook);
		     break;
		case 'q':
		     break;
		default:
			cout << "You entered an invalid option.  Try again!";    
     }
	 cout << endl;
  }
  while(option != 'q');

  // Cleaning up 

  for(int i = 0; i < apptbook.size(); i++){
    delete apptbook[i];
  }
  apptbook.clear();

  system("PAUSE");
  return 0;
}