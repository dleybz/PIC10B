/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"
#include "LinearList.h"
#include "Assert.h"

template<typename T>
class Iterator {
	template<typename T> friend class LinearList;
	
	public:
		Iterator();
		void next();
		T get() const;
		bool operator==(const Iterator<T>& it) const;
		
	private:
		Node<T>* position;
		const LinearList<T>* container;
};

template<typename T>
Iterator<T>::Iterator(){
	position = NULL;
	container = NULL;
}

template<typename T>
void Iterator<T>::next(){
	assert(position != NULL);
    position = position->next;
}

template<typename T>
T Iterator<T>::get()const{
	assert(position != NULL);
	return position->data;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& it)const{
	return position == it.position;
}

#endif