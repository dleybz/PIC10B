/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#include "Set.h"

using namespace std;

Set perform(const Set& a, const Set& b, Set (*op) (const Set&, const Set&)){
	return op(a, b);
}

int main(){
	Set (*op[3]) (const Set&, const Set&) = { operator+, operator*, operator- };

	char choice;

	do{
	cout << "Set Calculator\n\n";
	cout << "Enter a set of integers:\n";

	Set sets;
	cin	>> sets;

	cout << "Enter another set of integers:\n";
	Set sett;
	cin >> sett;

	cout << "You entered set:\n"  << sets << endl;
	cout << "You entered set:\n"  << sett << endl;

	cout << "Enter '+' to compute union. \n" << "Enter '*' to compute intersection. \n" << "Enter '-' to compute difference. \n" << "Enter 'a' to compute all three sets. \n" << "Enter any outer key to quit. \n \n" << "Enter an option: ";
	cin >> choice;

	switch (choice) {
	case '+': cout << "\n" << "Set union s+t:\n" << perform(sets, sett, op[0]) << "\n \n \n";
		break;

	case '*': cout << "\n" << "Set intersection s*t:\n" << perform(sets, sett, op[1]) << "\n \n \n";
		break;

	case '-': cout << "\n" << "Set difference s-t:\n" << perform(sets, sett, op[2]) << "\n \n \n";
		break;

	case 'a': cout << "\n" <<  perform(sets, sett, op[0]) << " " << perform(sets, sett, op[1]) << " " << perform(sets, sett, op[2]) << "\n \n \n";
		break;
	}
	}while(choice == '+' || choice == '*' || choice == '-' || choice == 'a');
	cout << "Thank you for playing! \n \n";

	return 0;
}