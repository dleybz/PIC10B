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
#include <iostream>
#include <fstream>

EightQueensProblem::EightQueensProblem(): NUM_QUEENS(8) {
	clear_board();
}

void EightQueensProblem::clear_board(){
	for(int row=0; row < CHESSBOARD_SIZE; row++){
		for(int column = 0; column < CHESSBOARD_SIZE; column++)
			chessboard[row][column] = 0;
	}

	num_queens_on_board = 0;
}

void EightQueensProblem::display_board(ostream& os)const{
	for(int row=0; row < CHESSBOARD_SIZE; row++){ //Prints the board
		for(int column = 0; column < CHESSBOARD_SIZE; column++){
			cout << chessboard[row][column] << " ";
		}
		cout << "\n";
	}

	string targetFileName = "Solution.txt"; //Creates a file with the solution
	ofstream out(targetFileName);
	for(int row=0; row < CHESSBOARD_SIZE; row++){
		for(int column = 0; column < CHESSBOARD_SIZE; column++){
			out << chessboard[row][column] << " ";
		}
		out << "\n";
	}
	out.close();
}



bool EightQueensProblem::queen_under_attack(int row, int column){

for(int i=0; (row+i) < CHESSBOARD_SIZE && (column-i) >= 0; i++){
	if(chessboard[row+i][column-i] != 0)
		return true;
} //Moves South-West

for(int i=0; (row+i) < CHESSBOARD_SIZE && (column+i) < CHESSBOARD_SIZE; i++){
	if(chessboard[row+i][column+i] != 0)
		return true;
} //Moves South-East

for(int i=0; (row-i) >= 0 && (column+i) < CHESSBOARD_SIZE; i++){
	if(chessboard[row-i][column+i] != 0)
		return true;
} //Moves North-East

for(int i=0; (row-i) >= 0 && (column-i) >= 0; i++){
	if(chessboard[row-i][column-i] != 0)
		return true;
} //Moves North-West

for(int r=0; r < CHESSBOARD_SIZE; r++){
	if(chessboard[r][column] != 0)
		return true;
} //Checks North-South

for(int c=0; c < CHESSBOARD_SIZE; c++){
	if(chessboard[row][c] != 0)
		return true;
} //Checks East-West

return false;

}

bool EightQueensProblem::start_game(int row){
	clear_board();
	place_queen_on_board(row-1, 0);
	bool success = place_next_queen();
	return success;
}

void EightQueensProblem::place_queen_on_board(int row, int column){
	num_queens_on_board++; //Iterates the number of queens on the board
	chessboard[row][column] = num_queens_on_board;
}

void EightQueensProblem::remove_queen_from_square(int row, int column){
	chessboard[row][column] = 0;
	num_queens_on_board--;
}

bool EightQueensProblem::place_next_queen(){ //Recursive function
	if (NUM_QUEENS == num_queens_on_board) return true;

	for(int row=0; row<CHESSBOARD_SIZE; row++){
		int column = num_queens_on_board; //New integer to keep track of the number of queens at time of activation
			if(!queen_under_attack(row, column)){
				place_queen_on_board(row, column);
				bool success = place_next_queen(); //Place where recursion occurs
				if (success) return true;
				else {
					remove_queen_from_square(row, column); //Backtracks
				}
			}
		}
	return false;
}
