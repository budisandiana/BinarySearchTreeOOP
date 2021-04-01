#pragma once
#include "Node.h"
#include <algorithm>

class Tree
{
private:
	Node * left;
	Node * right;
	Node * root;

public:
	Tree();
	Tree(Node *root, Node *left, Node *right);
	~Tree();

	// The methods:
	void print_inorder();
	void print_preorder();
	void print_postorder();
	void inorder(Node *p);
	void preorder(Node *p);
	void postorder(Node *p);
	void remove(int a);
	void insert(int data);
	int countNodes(Node *p);
	int countNodes();
	int countEdges(Node* p);
	int countEdges();
	int treeHeight(Node* p);
	int treeHeight();
};

