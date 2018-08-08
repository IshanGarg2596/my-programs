//Binary Search in c++
#include <iostream>
#include "tree.h"
using namespace std;

int main() {
	Tree T;
	int e, n;
	cout << "enter number of elements to be added in Binary Search Tree";
	cin >> n;
	cout << "Enter" << n << "elements of list:";
	for (int i = 0; i<n; i++) {
	   		cin >> e;
			T.insert(e);
	}
	T.inorder_traversal(T.root);
	return 0;
}

/* Function: 					    Use:
   insert(int) 					    insertion
   inorder_traversal(struct node*)  inorder traversal
   
*/   