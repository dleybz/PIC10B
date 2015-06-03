/*
Daniel Leybzon        PIC 10B Intermediate Programming
ID: 804503913         Spring 2015
Email: dannyleybzon@gmail.com
Section:
Honesty Pledge:

	I, Daniel Leybzon, pledge that this is my own independent work, which conforms to the guideliens of academic honesty as described in the course syllabus.

List of known bugs:
*/

#ifndef TREENODE_H
#define TREENODE_H
#include<string>
using namespace std;

class TreeNode {

	friend class BinaryTree;
	friend class Learner;

	public:	
		TreeNode(string data);
		TreeNode(string data, TreeNode* left, TreeNode* right);
	
	private:
		string data;
		TreeNode* leftChild;
		TreeNode* rightChild;
};

#endif