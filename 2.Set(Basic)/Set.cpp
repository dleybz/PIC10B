#include "Set.h"
#include <sstream>

using namespace std;

Set::Set(): elements(){
}

Set::Set(int element){
	elements.push_back(element);
}


unsigned int Set::size() const{
	return elements.size();
}

bool Set::contains(int element) const{
	bool c=false;
	for(int i=0; i < elements.size(); i++){
		if(elements[i]==element){
			c=true;
			break;
		}
	}
	return c;
}


int Set::operator[](unsigned int index) const{
	if(index < elements.size()) {
		return elements[index];
	}
	else {
		cout << "Error message";
		exit(1);
	}
}

Set& Set::operator+=(const Set& a){
	for(int i=0; i < a.size(); i++){
		if (!contains(a[i])) elements.push_back(a[i]);
	}

	return *this;
}

Set& Set::operator-=(const Set& a){
	Set b;
	for(int i=0; i < size(); i++){
			if(!a.contains(elements[i])) b+=elements[i];
	}
	elements = b.elements;
	return *this;
}

Set& Set::operator*=(const Set& a){
	Set b;
	for(int i=0; i < size(); i++){
			if(a.contains(elements[i])) b+=elements[i];
	}
	elements = b.elements;
	return *this;
}


ostream& operator<<(ostream& out, const Set& z){
	
	ostringstream oss;

	oss << "{";
	for(int i=0; i < z.size(); i++){
		if (i!=z.size()-1) oss << z[i] << " ";
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


bool operator<=(const Set& a, const Set& b){

	for(int i=0; i<a.size(); i++){
		if (!b.contains(a[i])) {
			return false;
		}
	}

	return true;

}

bool operator>=(const Set& a, const Set& b){
	return b<=a;
}

bool operator==(const Set& a, const Set& b){
	return a<=b && a>=b;
}

bool operator!=(const Set& a, const Set& b){
	return !(a==b);
}

bool operator<(const Set& a, const Set& b){
	return a<=b && a!=b;
}

bool operator>(const Set& a, const Set& b){
	return b<a;
}