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
#include <sstream>

Set::Set(): elements(NULL), size(0){ //Defaults the elements to NULL and the size to 0
}

Set::Set(int element): size(1){ //Defaults the size to 1
	elements = new int[1]; //Creates a new array of size 1
	elements[0] = element; //Sets the first element of this new array to the specified element
}

Set::Set(const Set& s): elements(NULL), size(0){ //Defaults the elements to NULL and the size to 0
	copy(s); //Deep copies the set specified
}


Set::~Set(){ //Destructor for the class Set
	delete[] elements; //Deletes the elements 
}


unsigned int Set::getSize() const{
	return size; //Calls but doesn't change the size attribute and returns it
}

bool Set::contains(int element) const{
	bool c=false; //Creates an arbitrary bool defaulted to false
	for(int i=0; i < getSize(); i++){
		if(elements[i]==element){
			c=true; //Changes the bool to true if the element is contained in the calling set
			break; //Breaks the for loop
		}
	}
	return c; //Returns the arbitrary bool
}

int Set::operator[](unsigned int index) const{
	if(index < getSize()) { //Tests that the specified index is defined within the Set
		return elements[index]; //Returns the value at the specified index
	}
	else { //If the index is not specified
		cout << "Error message";
		exit(1);
	}
}

Set& Set::operator=(const Set& s){
	return copy(s); //Calls the copy function to deep copy the set
}

Set& Set::operator+=(const Set& a){
	for(int i=0; i < a.getSize(); i++){
		if (!contains(a.elements[i])){
			int* tmp = new int[getSize()+1]; //Creates a temporary array of one size larger than the previous array
			for(int j = 0; j < getSize(); ++j)
				tmp[j] = elements[j];
			tmp[getSize()] = a.elements[i];
			delete[] elements;
			size++; //Increments size
			elements = tmp; //Sets the elements array equal to the temporary array
		};
	}

	return *this;
}

Set& Set::operator-=(const Set& a){
	Set tmp; //Creates a temporary set
	for(int i=0; i < getSize(); i++){
			if(!a.contains(elements[i])) tmp+=elements[i]; //Adds elements to the temporary set if they are not contained in the Set a
	}
	*this = tmp; //Sets the calling set equal to the temporary set
	return *this;
}

Set& Set::operator*=(const Set& a){
	Set b; //Creates a temporary set
	for(int i=0; i < getSize(); i++){
			if(a.contains(elements[i])) b+=elements[i]; //Adds elements to the temporary set if they are contained in both sets
	}
	*this = b; //Sets the calling set equal to the temporary set
	return *this;
}


Set& Set::copy(const Set& s){ //Deep copies the set from the parameter 
	if(this != &s){ //Tests to make sure the calling set doesn't contain the same elements as the parameter set
		delete[] elements; //Deletes the elements
		int* tmp = new int[s.size]; //Creates a new array of the size of the set being copied
		size = s.size; //Sets the size variable of the new array equal to the size variable of the set being copied
		if (size == 0){
			elements = NULL; //Sets the elements equal to NULL if the new size is 0
		}else{
			for(int i = 0; i < s.size; ++i) //Adds the elements from the set being copied from to the set beign copied into
				tmp[i] = s.elements[i];
		}
		elements = tmp; //Sets the array equal to the temporary array
	}

	return *this;

}

Set& Set::resize(unsigned int new_size){
	if(new_size = 0) { //If the new size is 0 sets the elements equal to NULL
		size = 0; 
		elements = NULL;
	}
	if(new_size > getSize()){
		int* tmp = new int[new_size]; //Creates a new temporary array
		for(int i = 0; i < getSize(); ++i) //Adds all of the elements from the old array to the new one
			tmp[i] = elements[i]; 
		delete[] elements; //Deletes the old array
		elements = tmp; //Sets the old array equal to the new array
	}
	if(new_size < getSize() || new_size != 0){
		int* tmp = new int[new_size]; //Creates a temporary new array
		for(int i = 0; i < new_size; ++i) //Adds as many of the elements of the old array to the new one as possible
			tmp[i] = elements[i];
		delete[] elements; //Deletes the old array
		elements = tmp; //Sets the new array equal to the old array
		size = new_size; //Resizes the new array
	}

	return *this; //Returns the calling set, now with a new array
}


ostream& operator<<(ostream& out, const Set& z){
	
	ostringstream oss;

	oss << "{";
	for(int i=0; i < z.getSize(); i++){
		if (i!=z.getSize()-1) oss << z[i] << " ";
		else oss << z[i];
	}
	oss << "}";
	out << oss.str();

	return out;
}

istream& operator>>(istream& in, Set& z){
	char i;
	in >> i;
	while(in.peek()!='}') {
		int j;
		in >> j;
		z+=j;
	}
	in >> i;
	return in;
}

Set operator+(const Set& a, const Set& b){
	Set c = a;
	return c+=b;
}

Set operator-(const Set& a, const Set& b){
	Set c = a;
	return c-=b;
}

Set operator*(const Set& a, const Set& b){
	Set c = a;
	return c*=b;
}