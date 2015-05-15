/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

template<typename T>
class Node {
	template<typename T> 
	friend class LinearList;

	template<typename T>
	friend class Iterator;
	
     public:
		Node();
		Node(T data);

	private:
		T data;
		Node<T>* next;	    
};

template<typename T>
Node<T>::Node(){
   next = NULL;
}

template<typename T>
Node<T>::Node(T data){
   this->data = data;
   this->next = NULL;
}

#endif