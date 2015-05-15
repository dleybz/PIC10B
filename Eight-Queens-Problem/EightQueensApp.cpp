/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#include "EightQueensProblem.h"

using namespace std;

int main(){
	char quit;
	int row;
	EightQueensProblem object;
	do{
		cout << "*************************** Eight Queens Problem *************************** \n \n" << "Position the first queen on the chessboard: \n \n" << "Enter the row for the first queen (from 1 to 8): ";
		cin >> row;
		if (object.start_game(row)){
		cout << "From the position (" << row << ", 1), the EightQueensProblem has solution: \n";
		object.display_board(cout);
		}else{
			cout << "Nah";
		}
		cout << "\n \n" << "Finished? Type 'q' to quit or any other key to try again:";
		cin >> quit;
	}while(quit != 'q');

	cout << "Thanks for playing.";

	return 0;
};