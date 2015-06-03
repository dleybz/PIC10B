/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#include "Learner.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
	Learner* l = new Learner();
	l->learn();
	cout << endl;
    delete l;
    l = NULL;
	system("PAUSE");
	return 0;
}