/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef STACK_H
#define STACK_H

#include "LinearList.h"

template<typename T>
class Stack {
	template<typename T> friend class LinearList;

	template<typename T> 
	friend ostream& operator<<(ostream& os, const Stack <T>& l);
	
	public:
		Stack();
		~Stack();
		Stack(const Stack <T>& l);

		Stack& operator=(const Stack <T>& l);

		void push(T data);
		void pop();
		T top();
		bool isEmpty() const;
		void empty();
		unsigned int getSize() const;
		
	private:
		LinearList<T> list;
		unsigned int size;
};

template<typename T>
Stack<T>::Stack(){
	size = 0;
}

template<typename T>
Stack<T>::~Stack(){
	empty();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& l){
	for(Iterator<T> i = l.list.begin(); !(i == l.list.end()); i.next()){
		insert(end(), i.get());
	}
	size = l.getSize();
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack <T> & l){
	if(this!=&l){
	empty();
	for(Iterator<T> i = l.list.begin(); !(i == l.list.end()); i.next()){
		insert(end(), i.get());
	}
	size = l.getSize();
	}
}

template<typename T>
void Stack<T>::push(T data){
	list.insert(list.end(), data);
	size++;
}

template<typename T>
void Stack<T>::pop(){
	list.remove(list.previous(list.end()));
	size--;
	return;
}

template<typename T>
T Stack<T>::top(){
	return list.previous(list.end()).get();
}

template<typename T>
bool Stack<T>::isEmpty() const{
	return size==0;
}

template<typename T>
void Stack<T>::empty(){
	list.empty();
	size = 0;
}

template<typename T>
unsigned int Stack<T>::getSize() const{
	return size;
}

template<typename T>
ostream& operator<<(ostream& os, const Stack <T>& l){
	for(Iterator <T> i = l.list.begin(); !(i==l.list.end()); i.next()){
	   os << i.get() << " ";
	}
	os << endl;
	return os;
}


#endif