#pragma once
#include <iostream>

class Node
{
public:
	Node * left;  // left node
	Node * right;  // right node
	Node * root;  // the root 
	int val;  // the value of a node

	// Constructor
	Node();

	// Destructor
	~Node();
};

