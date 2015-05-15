/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "LinearList.h"

template<typename T>
class Queue {
	template<typename T> friend class LinearList;

	template<typename T> 
	friend ostream& operator<<(ostream& os, const Queue <T>& l);
	
	public:
		Queue();
		~Queue();
		Queue(const Queue<T>& l);

		Queue& operator=(const Queue <T>& l);

		void push(T data);
		void pop();
		T front() const;
		bool isEmpty() const;
		void empty();
		unsigned int getSize() const;
		
	private:
		LinearList<T> list;
		unsigned int size;
};

template<typename T>
Queue<T>::Queue(){
	size = 0;
}

template<typename T>
Queue<T>::~Queue(){
	empty();
}

template<typename T>
Queue<T>::Queue(const Queue<T>& l){
	for(Iterator<T> i = l.list.begin(); !(i == l.list.end()); i.next()){
		insert(end(), i.get());
	}
	size = l.getSize();
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue <T> & l){
	if(this!=&l){
	empty();
	for(Iterator<T> i = l.list.begin(); !(i == l.list.end()); i.next()){
		insert(end(), i.get());
	}
	size = l.getSize();
	}
}

template<typename T>
void Queue<T>::push(T data){
	list.insert(list.end(), data);
	size++;
}

template<typename T>
void Queue<T>::pop(){
	list.remove(list.begin());
	size--;
	return;
}

template<typename T>
T Queue<T>::front() const{
	return list.begin().get();
}

template<typename T>
bool Queue<T>::isEmpty() const{
	return size==0;
}

template<typename T>
void Queue<T>::empty(){
	if(!isEmpty()){
		do{
			pop();
		}while(!isEmpty());
	}
	size = 0;
	return;
}

template<typename T>
unsigned int Queue<T>::getSize() const{
	return size;
}

template<typename T>
ostream& operator<<(ostream& os, const Queue <T>& l){
	for(Iterator <T> i = l.list.begin(); !(i==l.list.end()); i.next()){
	   os << i.get() << " ";
	}
	os << endl;
	return os;
}


#endif