/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef LEARNER_H
#define LEARNER_H
#include "TreeNode.h"
#include "BinaryTree.h"
using namespace std;

class Learner {
	public:	
		Learner();
		
		void learn();
	
	private:
		BinaryTree memory;
		void learn(string question, string yes_answer, string no_answer, TreeNode* subtree);

};

#endif