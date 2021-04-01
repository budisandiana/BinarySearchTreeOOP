#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
	root = nullptr;
	left = nullptr;
	right = nullptr;
}
Tree::Tree(Node *root, Node *left, Node *right)
{
	this->root = root;
	this->left = left;
	this->right = right;
}

//Destructor
Tree::~Tree()
{

}

/*Function, which inserts an element in binary tree */
void Tree::insert(int data)
{
	Node *temp = new Node;
	Node *parent;
	temp->val = data;
	temp->right = nullptr;
	temp->left = nullptr;
	parent = nullptr;
	if (root == 0)
	{
		root = temp;
	}
	else
	{
		Node *current;
		current = root;
		while (current != 0)
		{
			parent = current;
			if (temp->val > current->val)
				current = current->right;
			else
				current = current->left;
		}
		if (temp->val < parent->val)
			parent->left = temp;
		else
			parent->right = temp;
	}
}

// The Function that removes a value from the binary tree.
void Tree::remove(int a)
{
	//Locate the element
	bool found = false;
	if (root == nullptr)
	{
		cout << " This Tree is empty! " << endl;
		return;
	}

	Node *current;
	Node *parent;
	current = root;
	parent = nullptr;

	while (current != nullptr)
	{
		if (current->val == a)
		{
			found = true;
			break;
		}
		else
		{
			parent = current;
			if (a > current->val) 
				current = current->right;
			else 
				current = current->left;
		}
	}
	if (found == 0)
	{
		cout << " Data not found! " << endl;
		return;
	}

		// We have 3 cases of removing a value from a node:
		// 1. We're removing a leaf node
		// 2. We're removing a node with a single child
		// 3. we're removing a node with 2 children


		// Node with single child
		if ((current->left == nullptr && current->right != nullptr) || (current->left != nullptr && current->right == nullptr))
		{
			if (current->left == nullptr && current->right != nullptr)
			{
				if (parent->left == current)
				{
					parent->left = current->right;
					delete current;
				}
				else
				{
					parent->right = current->right;
					delete current;
				}
			}
			else // left child present, no right child
			{
				if (parent->left == current)
				{
					parent->left = current->left;
					delete current;
				}
				else
				{
					parent->right = current->left;
					delete current;
				}
			}
			return;
		}

		//We're looking at a leaf node
		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent->left == current)
				parent->left = nullptr;
			else parent->right = nullptr;
			delete current;
			return;
		}

		//Node with 2 children
		// replace node with smallest value in right subtree
		if (current->left != nullptr && current->right != nullptr)
		{
			Node* aux;
			aux = current->right;
			if ((aux->left == nullptr) && (aux->right == nullptr))
			{
				current = aux;
				delete aux;
				current->right = nullptr;
			}
			else // right child has children
			{
				//if the node's right child has a left child
				// Move all the way down left to locate smallest element

				if ((current->right)->left != nullptr)
				{
					Node* elem; // elem(valoarea curenta din partea stanga)
					Node* elempos; // 
					elempos = current->right;
					elem = (current->right)->left;
					while (elem->left != nullptr)
					{
						elempos = elem;
						elem = elem->left;
					}
					current->val = elem->val;
					delete elem;
					elempos->left = nullptr;
				}
				else
				{
					Node* b; // b = valoarea din dreapta pe care o sterg
					b = current->right;
					current->val = b->val;
					current->right = b->right;
					delete b;
				}

			}
			return;
		}
}

/* The inorder function:
1. Check if the current node is empty or null.
2. Traverse the left subtree by recursively calling the in-order function.
3. Display the data part of the root (or current node).
4. Traverse the right subtree by recursively calling the in-order function */

void Tree::print_inorder()
{
	inorder(root);
}
	

void Tree::inorder(Node* p)
{
	if (p != nullptr)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->val << " ";
		if (p->right) inorder(p->right);
	}
	else 
		return;
}

/* The preorder function:
1. Check if the current node is empty or null.
2. Display the data part of the root (or current node).
3. Traverse the left subtree by recursively calling the pre-order function.
4. Traverse the right subtree by recursively calling the pre-order function. */

void Tree::print_preorder()
{
	preorder(root);
}

void Tree::preorder(Node* p)
{
	if (p != nullptr)
	{
		cout << " " << p->val << " ";
		if (p->left) preorder(p->left);
		if (p->right) preorder(p->right);
	}
		else 
			return;
	}

/* The postorder function:
1. Check if the current node is empty or null.
2. Traverse the left subtree by recursively calling the post-order function.
3. Traverse the right subtree by recursively calling the post-order function.
4. Display the data part of the root (or current node). */

void Tree::print_postorder()
	{
		postorder(root);
	}

void Tree::postorder(Node* p)
{
	if (p != nullptr)
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		cout << " " << p->val << " ";
		}
		else 
			return;
}

/* 
This function counts, how many nodes are in the tree.
*/

int Tree::countNodes(Node* p)
{
	int count = 1;
	if (p == nullptr)
		return 0;
	else
	{
		count += countNodes(p->left);
		count += countNodes(p->right);
	}
	return count;
}

int Tree::countNodes()
{
	return countNodes(root);
}

/*
This function counts, how many edges are in the tree.
*/

int Tree::countEdges(Node * n)
{
	if (n == nullptr)
		return 0;
	else
		return countNodes() - 1;
}

int Tree::countEdges()
{
	return countEdges(root);
}

/*
The function, which shows the height of a tree. 
*/

int Tree::treeHeight(Node *p)
{
	if (p == nullptr)
	{
		return -1;
	}
	int left = treeHeight(p->left);
	int right = treeHeight(p->right);
	return (1 + std::max(left, right));
	}

int Tree::treeHeight()
{
	return treeHeight(root);
}