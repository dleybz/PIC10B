/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#include "Learner.h"
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

Learner::Learner() {
	memory.root = new TreeNode("");
	learn("Does it have legs?", "dog", "snake", memory.root);
}

void Learner::learn() {
	cout << "Let me guess which animal you are thinking of.\n \n";
	string response;
	do{
	TreeNode* currentNode = memory.root;
		do{
			string i;
			cout << currentNode->data << " ";
			cin >> i;
			while(i!="y" && i!="yes" && i!="n" && i!="no"){
				cout << "Please enter yes or no\n";
				cin >> i;
			}
			if(i=="y" || i=="yes") {
				currentNode=currentNode->leftChild; 
			}else{
				currentNode=currentNode->rightChild;
			}
		}while(!memory.isLeaf(currentNode));

		cout << "Is it a " << currentNode->data << "? ";
		string i;
		cin >> i;
		while(i!="y" && i!="yes" && i!="n" && i!="no"){
			cout << "Please enter yes or no\n";
			cin >> i;
		}
		if(i=="y" || i=="yes") {
			cout << "Victory is mine human scum\n"; 
		}else{
			cout << "What animal is it? ";
			string yes_answer;
			cin >> yes_answer;
			string no_answer = currentNode->data;
			string question;
			cout << "Enter a question which is true for a " << yes_answer << " but false for a " << no_answer << ":\n";
			getline(cin, question);
			getline(cin, question);
			learn(question, yes_answer, no_answer, currentNode);
		}
		cout << "Try again? Enter 'y' for yes or 'n' for no: ";
		cin >> response;
		cout << endl;
	}while(response!="n");
	cout << "Here's what I learned:\n" << memory;
}

void Learner::learn(string question, string yes_answer, string no_answer, TreeNode* subtree) {
	assert(subtree!=NULL);
	subtree->leftChild = new TreeNode(yes_answer);
	subtree->rightChild = new TreeNode(no_answer);
	subtree->data = question;
}