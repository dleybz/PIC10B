/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#include "TreeNode.h"
#include<iostream>
#include<string>
using namespace std;

TreeNode::TreeNode(string data) {
	this->data = data;
	leftChild = rightChild = NULL; 
}

TreeNode::TreeNode(string data, TreeNode* leftChild, TreeNode* rightChild) {
	this->data = data;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}