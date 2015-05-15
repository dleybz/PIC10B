/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/
#include<iostream>
#include<vector>
#include "Algorithms.h"
using namespace std;

void bubble_sort(int a[], const int size, int& statements){
    bool quit = false;
	statements++; //variable quit declared
	// each iteration passes through the array creates a 'bubble'
	statements++;//variable i declared
	for(int i = 1; (i < size && quit==false); i++){
		statements+=2;//for loop #1 evaluated true, two conditions checked
   	    quit = true;
		statements++;//variable change
		// pass through the array, swapping adjacent elements if out of order 
		// this moves the bubble along
		statements++;//variable j declared
		for(int j = 0; j < size-i; j++){
			statements++; //for loop #2 evaluated true
			if(a[j] > a[j+1]){
				statements++; //condition in if statement evaluated true
				statements += 3; //swap call is 3 statements
				swap(a[j], a[j+1]);
			  // continue with bubble sort if you had to make a swap
				statements++;//variable change
				quit = false;
			} else {
				statements++; //condition in if statement evaluated false
			}
			statements+=2; //j is incremeneted, incrementing index counts as two
		}
		statements-=2;//compensate for j being incremented 1 less times than the for loop is run
		statements++; //for loop #2 evaluated false
		statements++; //i is incremented
	}
	statements--;//compensate for i being incremented 1 less times than the for loop is run
	statements+=2; //for loop #1 evaluated false, two conditions checked
}

void selection_sort(int a[], const int size, int& statements){
    int smallest;
	statements++; //variable smallest declared
	statements++;//variable i declared
	for(int i = 0; i < size-1; i++){
		statements++; //for loop #1 evaluated true
	    smallest = i;
		statements++; //variable smallest set to i
		// find the index of the smallest unsorted item (ith smallest overall)
		statements++;//variable j declared
		for(int j = i+1; j < size; j++){
			statements++;//for loop #2 evaluated true
			if(a[j] < a[smallest]){
			  smallest = j;
			  statements++; //variable smallest  set to j
			  statements++; //if condition evaluated true
			} else {
				statements++; //if condition evaluated false
			}
			statements+=2; //j is incremented, incrementing index counts as 2
		}
		statements-=2;//compensate for j being incremented 1 less times than the for loop is run
		statements++; //for loop #2 evaluated false
		// swap the ith element with the ith smallest element
		swap(a[i], a[smallest]);
		statements+=3;//swap counts as 3
		statements++;//i is incremented
	}
	statements--;//compensate for i being incremented 1 less times than the for loop is run
	statements++; //for loop #1 evaluated false
}

void insertion_sort(int a[], const int size, int& statements){
    int inserted_item;
	statements++; //variable inserted_item declared
	int j;
	statements++; //variable j declared
    // insert each element into its proper place in the sorted region of the array
	statements++;//variable i declared
	for(int i = 1; i < size; i++){
		statements++; //for loop #1 evaluated true
		// chose the item to insert
		inserted_item = a[i];
		for(j = i-1; j >= 0 && a[j] > inserted_item; j--){
			statements++;//for loop #2 evaluated true
		   // shift to the right by 1 place each element in sorted region  
		   // that is bigger then the inserted item
			a[j+1] = a[j];			
			statements++;//place in array is defined
			statements++;//j is incremented
		}
		statements--;//compensate for i being incremented 1 less times than the for loop is run
		statements++;//for loop #2 evaluated false
		// insert the item into its correct position in the sorted region
		a[j+1] = inserted_item;
		statements++;//place in array is defined
		statements++;//i is incremented
	}
	statements++; //for loop #1 evaluated false
	statements--; //compensate for i being incremented 1 less times than the for loop is run
}

void merge(int a[], int first, int middle, int last, int& statements){
  
  int* temp = new int[last - first + 1];
  statements++; //variable temp declared
  int i;      // index for first sorted array
  statements++; //variable i declared
  int j;      // index for second sorted array
  statements++; //variable j declared
  int k = 0;  // index for temp array
  statements++; //variable k declared

  // Copy first sorted array into temp array
  statements++;//variable set
  for(i = first; i <= middle; i++){
	  statements++;//for loop evaluated true
     temp[k++] = a[i];
	 statements++;//variable set
	 statements++;//i is incremented
  }
  statements++;//for loop evaluated false
  statements--;//to comepsnate for i being incremented 1 less times than the for loop is run

   // Copy second sorted array backwards into temp array
  statements++;//variable set
  for(j = last; j > middle; j--){
	  statements++;//for loop evaluated true
     temp[k++] = a[j];
	 statements++;//variable set
	 statements++;//j is incremented
  }
  statements++;//for loop evaluated false
  statements--;//to compensate for j being incremented 1 less times than the for loop is run

  i = 0;
  statements++;//variable set
  j = last - first;
  statements++;//variable set

  // merge the two arrays back into original array
  statements++;//variable set
  for(k = first; k <= last; k++){
	  statements++;//for loop evaluted true
    a[k] = (temp[i] <= temp[j] ? temp[i++] : temp[j--]);
	statements++;//variable is set
	statements++;//k is incremented
  }
  statements++;//for loop evaluated false
  statements--;//to compensate for k being incremented 1 less time than the for loop is run

  delete[] temp;
}

void merge_sort(int a[], const int size, int first, int last, int& statements){
	if(first < last){
		statements++;//if condition evaluated true
     	int middle = (first + last)/2;
		statements++;//variable set
	    merge_sort(a, size, first, middle, statements);
		statements++;//function called
	    merge_sort(a, size, middle + 1, last, statements);
		statements++;//function called
	    merge(a, first, middle, last, statements);
		statements++;//function called
	} else {
		statements++;//if condition evaluated false
	}
}

void merge_sort(int a[], const int size, int& statements){
	merge_sort(a, size, 0, size-1, statements);
	statements++;//function called
}

void sort_into_vectors_by_radix(int a[], const int size, int radix, vector<int> bin[], int& statements){
   // sort by given radix
	statements++;//j declared
   for(int j = 0; j < size; j++) {
	   statements++;//for loop returns true
	   int n = pow(10, radix);
	   statements++;//variable set
	   int index = (a[j] % n) / (n/10.0);
	   statements++;//variable set
	   bin[index].push_back(a[j]);
	   statements++;//function called
	  statements++; //j is iterated
   }
   statements++;//for loop returns false
   statements--;//to compensate for j being iterated one less times than the for loop is called
}

void empty_vectors_back_into_array(int a[], const int size, vector<int> bin[], int& statements){
   int j = size-1;
   statements++; //variable j declared
     // empty vectors in order into array
   statements++;//variable i declared
   for(int i = 9; i >= 0; i--) {	   
	   statements++;//for loop returns true
	   while(!bin[i].empty()){
		   statements++;//while loop is true
	     a[j--] = bin[i].back();
		 statements++;//variable set
		 bin[i].pop_back();		 
		 statements++;//function called
	   }	   
	   statements++;//while loop is false
	   statements++;//i is iterated
   }
   statements++;//for loop returns false
   statements--;//to compensate for i being iterated one less times than the for loop is called
}

void radix_sort(int a[], const int size, int& statements){
   vector<int> bin[10];
   statements++;//array bin declared
   statements++;//variable i declared
   for(int i = 0; i < 10; i++){
	   statements++;//for loop returns true
     bin[i] = vector<int>();
	 statements++;//variable set
   }

   // sort by ones
   sort_into_vectors_by_radix(a, size, 1, bin, statements);
   statements++;//function called
  
   // empty vectors in order into array
   empty_vectors_back_into_array(a, size, bin, statements);  
      statements++;//function called

   // sort by tens
   sort_into_vectors_by_radix(a, size, 2, bin, statements); 
      statements++;//function called

   // empty vectors in order into array
   empty_vectors_back_into_array(a, size, bin, statements);
      statements++;//function called

   // sort by hundreds
   sort_into_vectors_by_radix(a, size, 3, bin, statements);
      statements++;//function called
 
   // empty vectors in order into array
   empty_vectors_back_into_array(a, size, bin, statements);
      statements++;//function called

   // sort by thousands
   sort_into_vectors_by_radix(a, size, 4, bin, statements);
      statements++;//function called
  
   // empty vectors in order into array
   empty_vectors_back_into_array(a, size, bin, statements);
      statements++;//function called

   // sort by ten thousands
   sort_into_vectors_by_radix(a, size, 5, bin, statements);
      statements++;//function called

   // empty vectors in order into array
   empty_vectors_back_into_array(a, size, bin, statements);
      statements++;//function called
}

void shell_sort(int a[], const int size, int& statements){
	statements++;//array defined
	int hArray[9] = {9841, 3280, 1093, 364, 121, 40, 13, 3, 1};
	statements++;//variable h declared
	for(int h = 0; h < 9; h++){
		statements++;//for loop #1 evaluated true
		if(hArray[h]<size){
			statements++;//if condition evaluated true
			statements++;//variable i declared
			for( int i = hArray[h]; i <size; i++){
				statements++;//for loop #2 evaluated true
				statements++;//variable j declared
				for( int j = i-hArray[h]; j>=0 && a[j] > a[j+hArray[h]]; j-=hArray[h]){
					statements++;//for loop #3 evauated true
					swap(a[j], a[j+hArray[h]]);
					statements+=3;//swap counts as 3
				}
				statements++;//j is iterated
			}
			statements++;//for loop #3 returns false
			statements--;//to compensate for j being iterated one less times than the for loop is called
			statements++;//i is iterated
		} else{
			statements++;//if statement evalauted false
		}
		statements++;//h is iterated
	}
	statements++;//for loop #1 returns false
	statements--;//to compensate for h being iterated one less times than the for loop is called
}