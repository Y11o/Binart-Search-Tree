#include "BST.h"

int main() {
	BinarySearchTree tree;
	tree.insert(5);
	tree.insert(10);
	tree.insert(-3);
	tree.insert(8);
	tree.insert(4);
	tree.insert(25);
	tree.preOrder();
	tree.width();

	return 0;
}
