/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"
using namespace std;

class BinaryTree {

	friend ostream& operator<<(ostream& os, const BinaryTree& l);
	friend class Learner;

	public:	
		BinaryTree();
		~BinaryTree();

		void display(ostream& os) const;
	
	private:
		bool isLeaf(TreeNode* node) const;
		void free(TreeNode*& subtree);
		void display(ostream& os, TreeNode* subtree) const;

		TreeNode* root;
};

#endif