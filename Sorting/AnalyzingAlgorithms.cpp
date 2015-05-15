/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#include "Algorithms.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

const int NUM_SORT_FUNCTIONS = 6;
const int ARRAY_COL_WIDTH = 6;
const int N_COL_WIDTH = 10;
const int BN_COL_WIDTH = 10;

void set_seed(){
	// stores the current time of the computer as an int
	int seed = static_cast<int>(time(NULL));
	// sets the random number seed to that int
	srand(seed);
}

int random(int min, int max) {
	int num_values_to_pick_from = max - min + 1;
	// constructs a random integer ranging from min to max
	return (rand() % num_values_to_pick_from) + min;
}

void print_array(const int A[], const int N, ostream& os = cout){
	os << right;
	for(int i = 0; i < N; i++){
	   if(i % 10 == 0) os << endl;
		os << setw(ARRAY_COL_WIDTH) << A[i];
	}
}

void performSort(void (*sort)(int[], const int, int&), int data[], const int N, string filename, ostream& os){
	int counter = 0; //initializes the statement counter
	ofstream out(filename, ios::app); //opens the statement with the filename specified and appends to it
	print_array(data, N, out); //prints out the unsorted array
	sort(data, N, counter); //prints out the specified array using the specified sorting algorithm
	print_array(data, N, out); //prints out the sorted array
	out << "\n" << "Num statements: " << counter << "\n"; //prints out the number of statements
	out.close(); //closes the file
	os << right << setw(BN_COL_WIDTH) << counter; //sends the number of statements to the outstream
}

void makeRecord(int N, ostream& os){
	const int size = 1024; //maximum number of numbers that you'll be sorting
    int data[size]; //first array to be sorted
	int data1[size];
	int data2[size];
	int data3[size];
	int data4[size];
	int data5[size];
	for(int i = 0; i<N; i++){
		data[i]=random(1, 10000); //sets all of the elements of all of the arrays to random numbers to be sorted
		data5[i]=data4[i]=data3[i]=data2[i]=data1[i]=data[i];
	}
	os << setw(N_COL_WIDTH) << N;

	performSort(bubble_sort, data, N, "bubblesort.txt", os); //calls the performSort function with the bubble_sort function
	performSort(selection_sort, data1, N, "selectionsort.txt", os);
	performSort(insertion_sort, data2, N, "insertionsort.txt", os);
	performSort(merge_sort, data3, N, "mergesort.txt", os);
	performSort(shell_sort, data4, N, "shellsort.txt", os);
	performSort(radix_sort, data5, N, "radixsort.txt", os);
	os << endl;
}

void sortAndCount(string count_file){
	string targetFileName =  count_file;
	ofstream out(targetFileName); //opens up the specified file to edit
	out << "***Number  of  Statements  for  Various  Sorting  Algorithms***" << "\n \n" << setw(BN_COL_WIDTH) << "N" << setw(BN_COL_WIDTH) << "Bubble" << setw(BN_COL_WIDTH) << "Selection" << setw(BN_COL_WIDTH) << "Insertion" << setw(BN_COL_WIDTH) << "Merge" << setw(BN_COL_WIDTH) << "Shell" << setw(BN_COL_WIDTH) << "Radix" << "\n"; //header
	for(int i = 1; i<=1024; i *= 2) makeRecord(i, out); //calls the makerecord function for each power of two up to 1024
	out.close();
}

void analyzeCounts(string count_file, string analysis_file){
	string sourceFileName = count_file; //references the count_file
	ifstream in(sourceFileName);
	string header;
	getline(in, header); //takes in 3 trash header lines
	getline(in, header);
	getline(in, header);
	string targetFileName = analysis_file; //creates a new file with analysis_file name specified
	ofstream out(targetFileName);
	out << "*******Algorithm Analysis*******" << "\n \n" << "T(2N)/T(N)" << setw(BN_COL_WIDTH) << "Bubble" << setw(BN_COL_WIDTH) << "Selection" << setw(BN_COL_WIDTH) << "Insertion" << setw(BN_COL_WIDTH) << "Merge" << setw(BN_COL_WIDTH) << "Shell" << setw(BN_COL_WIDTH) << "Radix" << "\n \n"; //adds header to the new text file
	int n; //trash variable
	out << fixed;	
	int TN[6] ={0}; //initializes an array full of 0s of size six
	int T2N[6] = {0}; //initiaizes second array full of 0s of size six
	in >> n;
	while(!in.eof()){ //wil run until it reaches the end of the file
		out << setw(BN_COL_WIDTH) << " ";
		for(int i = 0; i<6; i++){
			TN[i] = T2N[i];//fills the first array with the elements of the second array from before
			in >> T2N[i]; //reads the line of statements into the second array with elements
			if(TN[i]!=0){ //tests to see if this is the first iteration
				out << right << setw(BN_COL_WIDTH) << static_cast<double>(T2N[i])/static_cast<double>(TN[i]); //outputs the ratio between the previous n's statements and the current n's statements
			}
		}
		in >> n;
		out << "\n";
	}
	in.close();
	out.close();
}

int main(){
	set_seed();
	string count_file = "StatementCount.txt";
	string analysis_file = "AlgorithmAnalysis.txt";
	sortAndCount(count_file);
	analyzeCounts(count_file, analysis_file);
	system("PAUSE");
	return 0;
}