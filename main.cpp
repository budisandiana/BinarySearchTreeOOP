#include <iostream>
#include <algorithm>
#include "Tree.h"
using namespace std;

int main()
{
	Tree t;
	int ch, tmp, tmp1, nr;
	bool val;
	val = true;
	while (val)
	{
		cout << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " 1. Insertion/Creation " << endl;
		cout << " 2. In-Order Traversal " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. Post-Order Traversal " << endl;
		cout << " 5. Removal " << endl;
		cout << " 6. Number of nodes " << endl;
		cout << " 7. Number of edges " << endl;
		cout << " 8. Height " << endl;
		cout << " 9. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1: 
			cout << " Enter number of nodes: ";
			cin >> nr;
			for (int i = 0; i < nr; i++)
			{
				cout << " Enter number to be inserted : ";
				cin >> tmp;
				t.insert(tmp);
			}
			break;
		case 2: cout << endl;
			cout << " In-Order Traversal " << endl;
			t.print_inorder();
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			t.print_preorder();
			break;
		case 4: cout << endl;
			cout << " Post-Order Traversal " << endl;
			t.print_postorder();
			break;
		case 5: cout << " Enter data to be deleted : ";
			cin >> tmp1;
			t.remove(tmp1);
			break;
		case 6: cout << "Number of nodes: " << endl;
			cout << t.countNodes() << endl;
			break;	
		case 7:
			cout << "Number of edges: " << endl;
			cout << t.countEdges() << endl;
			break;
		case 8:
			cout << "Height: " << endl;
			cout << t.treeHeight() << endl;
			break;
		case 9:
			return 0;
		}
	}
}
