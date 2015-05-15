/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef SET_H
#define SET_H

#include<iostream>
#include<vector>


using namespace std;

class Set{
	friend ostream& operator<<(ostream& out, const Set& z); //Output for class Set
	friend istream& operator>>(istream& in, Set& z); //Input for class Set

public:

	Set(); //Default constructor
	Set(int element); //Constructor for single element specified
	Set(const Set& s); //Copy constructor

	~Set(); //Destructor

	bool contains(int element) const; //Returns true if the set contains the element
	unsigned int getSize() const; //Returns the number of elements in the set

	int operator[](unsigned int index) const; //Returns the element at the specified index
	Set& operator=(const Set& s); //Calls the copy function to set the right-hand set equal to the left-hand set
	Set& operator+=(const Set& s); //Adds the elements in the right-hand set to the elements in the calling set and returns the calling set
	Set& operator-=(const Set& s); //Returns the calling set as a set which contains all of the elements of the left-hand set not contained in the right-hand set
	Set& operator*=(const Set& s); //Returns the calling set as a set which contains all of the elements of both the right-hand set and the left-hand set

private:
	int* elements; //Array which contains the integers in the set
	unsigned int size; //Number of elements in the set

	Set& copy(const Set& s); //Deep copies the set
	Set& resize(unsigned int new_size); //Changes the size of the calling set

};

Set operator+(const Set& a, const Set& b); //Returns the union of the two sets
Set operator-(const Set& a, const Set& b); //Returns the difference of the two sets
Set operator*(const Set& a, const Set& b); //Returns the intersection of the two sets

#endif