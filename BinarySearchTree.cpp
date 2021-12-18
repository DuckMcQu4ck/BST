#include "BST.h"
#include <iostream>

using namespace std;

void DisplayTree(BST tree) {
	cout << "INORDER:\n";
	tree.Inorder();
	cout << endl;

	cout << "PREORDER:\n";
	tree.Preorder();
	cout << endl;

	cout << "POSTORDER:\n";
	tree.Postorder();
	cout << endl;
}

int main() {
	BST tree;

	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(5);
	tree.Insert(7);

	DisplayTree(tree);

	cout << tree.succ(6)->data << endl;
	cout << tree.pred(6)->data << endl;

	tree.remove(2);

	cout << "Remove 2" << endl;
	tree.Inorder();

	cout << tree.max()->data;

	system("pause");
	return 0;
}