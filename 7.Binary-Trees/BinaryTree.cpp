/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#include "BinaryTree.h"
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	free(root);
}

void BinaryTree::display(ostream& os) const{
	display(os, root);
}

bool BinaryTree::isLeaf(TreeNode* node) const{
	assert(node!= NULL);
	return (node->leftChild == NULL && node->rightChild == NULL);
}

void BinaryTree::free(TreeNode*& subtree) {
	if(subtree != NULL){
		free(subtree->leftChild);
		free(subtree->rightChild);
		cout << "Deleting node: " << subtree->data << endl;
		delete subtree;
		subtree = NULL;
		
	}
}

void BinaryTree::display(ostream& os, TreeNode* subtree) const{
	if(subtree != NULL){
		os << subtree->data << endl;
		display(os, subtree->leftChild);
		display(os, subtree->rightChild);
	}
}

ostream& operator<<(ostream& os, const BinaryTree& l){
	l.display(os);
	return os;
}