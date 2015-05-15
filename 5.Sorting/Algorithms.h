/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void bubble_sort(int a[], const int size, int& statements);
void selection_sort(int a[], const int size, int& statements);
void insertion_sort(int a[], const int size, int& statements);
void merge_sort(int a[], const int size, int& statements);
void radix_sort(int a[], const int size, int& statements);

void shell_sort(int a[], const int size, int& statements);

#endif