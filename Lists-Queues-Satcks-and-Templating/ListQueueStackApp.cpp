/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#include "Node.h"
#include "LinearList.h"
#include "Iterator.h"
#include "Queue.h"
#include "Stack.h"
#include<iostream>
#include<string>
using namespace std;

unsigned int changeBase(unsigned int n, unsigned int b){
	//from Wikipedia "To convert from decimal to another base one must simply start dividing by the value of the other base, then dividing the result of the first division and overlooking the remainder, and so on until the base is larger than the result (so the result of the division would be a zero). Then the number in the desired base is the remainders, the most significant value being the one corresponding to the last division and the least significant value being the remainder of the first division."
	Stack <int> stack; //creates a Stack which accepts integer objects named stack
	do{
		stack.push(n%b); //pushes the remainder of c divided by b into the Stack stack
		n=n/b; //divides c by the base, creating a new product
	}while(n>b); //ensures that we stop when the base is larger than the remainder
	stack.push(n%b);
	n=n/b;
	if(n!=0) return 31415;
	int d = 0; //integer which will be returned; not in decimal form
	do{
		d+=(pow(10, (stack.getSize())-1)*stack.top()); //takes the top element off the stack and multiplies it so that it occupies the right place in d
		stack.pop(); //takes the top element off the stack
	}while(!stack.isEmpty()); //stops this process when the stack is empty
	return d; //returns the integer which has been storing the values
}

bool isPalindrome(string phrase){ //Do not ignore punctuation and spaces
	Stack <char> stack; //creates a Stack which accepts character objects called stack
	Queue <char> queue; //creates a Queue which accepts character objects called queue
	for(unsigned int i = 0; i<phrase.size(); i++){ //fills up the queue and the stack with the phrase
		stack.push(phrase[i]); //loads the ith character in the phrase to the top of the stack
		queue.push(phrase[i]); //loads the ith character in the string to the top of the queue
	}
	for(unsigned int i =0; i<(phrase.size()/2); i++){ //tests to see that the ith letter from the front matches the ith letter from the back; if phrase.length is odd doesn't check the middle character against itself
		if(stack.top()!=queue.front()) return false; //returns false if the ith character from the front doesn't match the ith character from the back
		queue.pop(); //removes the tested character from the queue
		stack.pop(); //removes the tested character from the stack
	}

	return true; //returns true if not false
}

int main(){
	int n;
	cout  << "Base Converter\n" << "Enter a nonnegative integer: ";
	cin >> n;
	for(int i = 2; i<=9; i++){
		cout << "[" << changeBase(n, i) << "]_" << i << endl;
	}

	cout << endl;

	cout << "Palindrome Tester" << endl <<"Enter a phrase: ";
	string phrase;
	cin >> phrase;
	cout << phrase << " is ";
	if(!isPalindrome(phrase)) cout << "not ";
	cout << "a palindrome.\n";
	return 0;
}