/*
Keith Ouellette					    PIC 10B Intermediate Programming
ID: 123456789          		  		Winter 2015
Email: kouellet@pic.ucla.edu		Assignment #2
Section: 1A
Honesty Pledge:

I, Keith Ouellette, pledge that this is my own independent
work,which conforms to the guidelines of academic honesty as
described in the course syllabus.
List of known bugs: None.
*/
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

#include "Set.h"
using namespace std;

int main(){
	
	Set s;  //initially empty set
	istringstream in("{1 2 3 4 5 6 7 8 9 10}");
	in >> s;
	
	Set t;
	cout << "Enter a set of integers eg {1 2 3}\n";
    cin >> t;

	cout << "You entered set:\n"  << t << endl;
	cout << "Set s:\n" << s << endl;
	cout << "Set t:\n" << t << endl;
	cout << "t[2] is: " << t[2] << endl;
	cout << "Set union s+t:\n" << s+t << endl;
	cout << "Set difference s-t:\n" << s-t << endl;
	cout << "Set intersection s*t:\n" << s*t << endl;
	cout << "s<t: " << (s<t?"true":"false") << endl;
	cout << "s>t: " << (s>t?"true":"false") << endl;
	cout << "s==t " << (s==t?"true":"false") << endl;
	cout << "s!=t: " << (s!=t?"true":"false") << endl;
	cout << "s<=t: " << (s<=t?"true":"false") << endl;
	cout << "s>=t: " << (s>=t?"true":"false") << endl;

	string filename = "sets.txt";
    cout << "Writing sets s and t to file \"" << filename << "\"..." << endl;
	ofstream o(filename.c_str());
	o << s << " " << t;
	o.close();

	Set u; 
	Set v;
    cout << "Reading sets u and v from file \"" << filename << "\"..." << endl;
	ifstream infs(filename.c_str());
	infs >> u >> v;
	infs.close();

	cout << "Set u:\n" << u << endl;
	cout << "Set v:\n" << v << endl;

	system("PAUSE");
	return 0;
}