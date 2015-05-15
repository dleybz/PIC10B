/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef LINEARLIST_H
#define LINEARLIST_H

#include "Node.h"
#include "Iterator.h"
#include<iostream>
using namespace std;

template<typename T>
class LinearList {

	template<typename T> 
	friend ostream& operator<<(ostream& os, const LinearList <T>& l);

	public:
		LinearList();
		~LinearList();
		LinearList(const LinearList <T>& l);
		LinearList& operator=(const LinearList <T>& l);

		Iterator<T> begin()const;
		Iterator<T> end()const;
		Iterator<T> search(T data)const;
		Iterator<T> previous(Iterator <T>& current);
		void insert(Iterator <T>& before, T data);
		void remove(Iterator <T>& current);
		bool isEmpty()const;
		void empty();

		void reverse(); //reverses the order of the Nodes in the LinearList
		
	private:
		Node<T>* head;
		
		
};

template<typename T>
void LinearList<T>::reverse(){
	for(Iterator<T> i = begin(); !(i==end()); ){
		insert(begin(), i.get());
		Iterator<T> j = i;
		i.next();
		remove(j); 

	}
}

template<typename T>
LinearList<T>::LinearList(){
	head = NULL;
}

template<typename T>
LinearList<T>::~LinearList(){
	empty();
}
		
template<typename T>
LinearList<T>::LinearList(const LinearList <T>& l){
	head = NULL;
	for(Iterator<T> i = l.begin(); !(i == l.end()); i.next()){
		insert(end(), i.get());
	}
}

template<typename T>
LinearList<T>& LinearList<T>::operator=(const LinearList <T>& l){
	if(this != &l){
		empty();
		for(Iterator <T> i = l.begin(); !(i == l.end()); i.next()){
			insert(end(), i.get());
		}
	}
	return (*this);
}

template<typename T>
Iterator<T> LinearList<T>::begin()const{
	Iterator <T> i;
	i.position = head;
	i.container = this;
    return i;
}

template<typename T>
Iterator<T> LinearList<T>::end()const{
	Iterator <T> i;
	i.position = NULL;
	i.container = this;
    return i;
}

template<typename T>
Iterator<T> LinearList<T>::search(T data)const {
	for(Iterator <T> i = begin(); !(i == end()); i.next() ){
		if(i.get() == data){
		    return i;
		}
	}
	return end();
}

template<typename T>
Iterator<T> LinearList<T>::previous(Iterator <T>& current){
	for(Iterator <T> i = begin(); !(i == end()); i.next()) {
		if (i.position->next == current.position) {
			  return i;
		}
	}
	return end();
}

// Inserts a Node with the given data before the Node at the iterator before
template<typename T>
void LinearList<T>::insert(Iterator <T>& before, T data){
	Node<T>* temp = new Node<T>(data); //Node<T>(data) or Node(data)?

	if(before == begin()){
		// insert at beginning of the list
		temp->next = head;
		head = temp;
	}
	else {
		Iterator <T> current = previous(before);
		temp->next = current.position->next;
		current.position->next = temp;
	}
}

template<typename T>
void LinearList<T>::remove(Iterator <T>& current){
	if(current == end())  return;
	else if(current == begin()){
	    head = head->next;
		delete current.position;
	}
	else{
		Iterator <T> prev = previous(current);
		prev.position->next = current.position->next;
		delete current.position;
	}
}

template<typename T>
bool LinearList<T>::isEmpty()const{
	return (begin() == end());
}

template<typename T>
void LinearList<T>::empty(){
	while(!isEmpty()){
		remove(begin());
	}
}

template<typename T>
ostream& operator<<(ostream& os, const LinearList <T>& l){
	for(Iterator <T> i = l.begin(); !(i==l.end()); i.next()){
	   os << i.get() << " ";
	}
	os << endl;
	return os;
}


#endif