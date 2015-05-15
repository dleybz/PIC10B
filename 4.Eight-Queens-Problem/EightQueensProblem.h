/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#ifndef EIGHTQUEENSPROBLEM_H
#define EIGHTQUEENSGAME_H

#include <iostream>

using namespace std;

class EightQueensProblem{
public:
	EightQueensProblem();

	void clear_board(); //Sets all the values on the board to 0 and resets the number of queens on the board variable to 0
	void display_board(ostream& os) const; //Prints the board and saves the solution in a text file

	bool queen_under_attack(int row, int column); //Tests to see if the queen can be safely put there
	bool start_game(int row); //Clears the board, then places a queen on the board at the specified row and begins looking for solutions

private:
	static const unsigned int CHESSBOARD_SIZE = 8; //Vertical and horizontal lenghth of the chessboard
	int chessboard[CHESSBOARD_SIZE][CHESSBOARD_SIZE]; //Array which holds the chessboard
	const int NUM_QUEENS; //Total number of queens that should be on the board by the end
	int num_queens_on_board; //Running total of the number of queens on the board

	void place_queen_on_board(int row, int column); //Adds queen to specified point and raises the number of queens on the board by one
	void remove_queen_from_square(int row, int column); //Removes queen from specified point and lowers the number of queens on the board by one
	bool place_next_queen(); //Recursive function

};

#endif