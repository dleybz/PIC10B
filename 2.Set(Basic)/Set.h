#ifndef SET_H
#define SET_H

#include<iostream>
#include<vector>


using namespace std;

class Set{

	friend ostream& operator<<(ostream& out, const Set& z);
	friend istream& operator>>(istream& in, Set& z);

	public:
		Set();
		Set(int element);

		unsigned int size() const;
		bool contains(int element) const;

		int operator[](unsigned int index) const;
		Set& operator+=(const Set& a);
		Set& operator-=(const Set& a);
		Set& operator*=(const Set& a);



	private:
		vector<int> elements;

};

Set operator+(const Set& a, const Set& b);
Set operator-(const Set& a, const Set& b);
Set operator*(const Set& a, const Set& b);

bool operator<=(const Set& a, const Set& b);
bool operator>=(const Set& a, const Set& b);
bool operator==(const Set& a, const Set& b);
bool operator!=(const Set& a, const Set& b);
bool operator<(const Set& a, const Set& b);
bool operator>(const Set& a, const Set& b);

#endif