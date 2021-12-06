#pragma once
#include <iostream>
using namespace std;

class BinarySearchTree {
private:
	struct Node {							//Node of the tree structure
		int data;
		Node* leftChild;
		Node* rightChild;
	};
	//static int nodesCount;					//Counter of Nodes
	Node* root;								//Root pointer
	Node* clear(Node* currRoot) {			//Private section functions
		if (currRoot == NULL) return NULL;
		else {
			clear(currRoot->leftChild);
			clear(currRoot->rightChild);
			delete currRoot;
		}
		return NULL;
	}
	Node* insertNode(int data, Node* currRoot) {
		if (currRoot == NULL) {
			currRoot = new Node;
			currRoot->data = data;
			currRoot->leftChild = NULL;
			currRoot->rightChild = NULL;
		}
		else if (currRoot->data > data)
		{
			currRoot->leftChild = insertNode(data, currRoot->leftChild);
		}
		else if (currRoot->data <= data)
		{
			currRoot->rightChild = insertNode(data, currRoot->rightChild);
		}
		//nodesCount++;
		return currRoot;
	}
	Node* search(int data, Node* currRoot) {
		if (currRoot == NULL) return NULL;
		else if (currRoot->data > data)
		{
			search(data, currRoot->leftChild);
		}
		else if (currRoot->data < data)
		{
			search(data, currRoot->rightChild);
		}
		else
		{
			return currRoot;
		}
	}
	Node* removeNode(int data, Node* currRoot) {
		Node* tempNode;
		if (currRoot == NULL) return NULL;
		else if (currRoot->data > data) currRoot->leftChild = removeNode(data, currRoot->leftChild);
		else if (currRoot->data < data) currRoot->rightChild = removeNode(data, currRoot->rightChild);
		else if (currRoot->rightChild || currRoot->leftChild) {
			tempNode = minNode(currRoot->rightChild);
			currRoot->data = tempNode->data;
			currRoot->rightChild = removeNode(currRoot->data, currRoot->rightChild);
		}
		else
		{
			tempNode = currRoot;
			if (currRoot->leftChild == NULL) {
				currRoot = currRoot->rightChild;
			}
			else if (currRoot->rightChild == NULL) {
				currRoot = currRoot->leftChild;
			}
			delete tempNode;
		}
	}
	Node* maxNode(Node* currRoot) {
		if (currRoot == NULL) return NULL;
		else if (currRoot->rightChild == NULL) return currRoot;
		else return maxNode(currRoot->rightChild);
	}
	Node* minNode(Node* currRoot) {
		if (currRoot == NULL) return NULL;
		else if (currRoot->leftChild == NULL) return currRoot;
		else return minNode(currRoot->leftChild);
	}
	Node* returnRoot() {											//end of Private section functions
		return root;
	}
	void dftTravers(Node* root) {									//Dft Travers
		Stack* pointerStack = createStack();
		while (pointerStack->size != 0 || root != NULL) {
			if (root != NULL) {
				cout << root->data << ' ';
				if (root->rightChild) {
					push(pointerStack, root->rightChild);
				}
				root = root->leftChild;
			}
			else {
				root = pop(pointerStack);
			}
		}
		cout << endl;
		cout << "DftTravers end" << endl;
		cout << endl;
		freeStack(&pointerStack);
	}
	void bftTravers(Node* root) {									//Bft Travers
		struct Queue* queue = createQ();
		insertQ(queue, root);
		//int counter = nodesCount - 1;
		while (isEmptyQ(queue) == 0) {
			Node* tmp = (Node*)removeQ(queue);
			cout << tmp->data << ' ';
			if (tmp->leftChild) {
				insertQ(queue, tmp->leftChild);
			}
			if (tmp->rightChild) {
				insertQ(queue, tmp->rightChild);
			}
		}
		cout << endl;
		cout << "BftTravers end" << endl;
		cout << endl;
	}
public:
	/// <summary>
	/// Stack implantation
	/// </summary>
	typedef struct Stack {
		size_t size;
		size_t limit;
		Node** data;
	} Stack;

	Stack* createStack() {
		Stack* tmp = (Stack*)malloc(sizeof(Stack));
		tmp->limit = 100;
		tmp->size = 0;
		tmp->data = (Node**)malloc(tmp->limit * sizeof(Node*));
		return tmp;
	}

	void freeStack(Stack** stack) {
		free((*stack)->data);
		free(*stack);
		*stack = NULL;
	}

	void push(Stack* stack, Node* value) {
		if (stack->size >= stack->limit) {
			stack->limit *= 2;
			stack->data = (Node**)realloc(stack->data, stack->limit * sizeof(Node*));
		}
		stack->data[stack->size++] = value;
	}

	Node* pop(Stack* stack) {
		if (stack->size == 0) {
			exit(7);
		}
		stack->size--;
		return stack->data[stack->size];
	}

	Node* peek(Stack* stack) {
		return stack->data[stack->size - 1];
	}
	/// <summary>
	/// Queue implantation
	/// </summary>
	typedef struct Queue {
		Node** data;
		size_t size;
		int lastElem, frstElem;
	}Queue;

	Queue* createQ() {
		Queue* queue = (Queue*)malloc(sizeof(Queue));
		queue->size = 0;
		queue->data = (Node**)malloc(queue->size * sizeof(Node*));
		queue->frstElem = 1;
		queue->lastElem = 0;
		return queue;
	}

	void insertQ(struct Queue* queue, Node* data) {
		if (queue->lastElem < 100 - 1) {
			queue->lastElem++;
			queue->data[queue->lastElem] = data;
		}
		else
			cout << "Queue is full" << endl;
		return;
	}

	bool isEmptyQ(struct Queue* queue) {
		if ((queue->lastElem) < (queue->frstElem)) return 1;
		else  return 0;
	}

	void print(struct Queue* queue) {
		if (isEmptyQ(queue) == 1) {
			cout << "Queue is empty" << endl;
			return;
		}
		for (int i = queue->frstElem; i <= queue->lastElem; i++)
			cout << queue->data[i] << ' ';
		cout << endl;
		return;
	}

	Node* removeQ(struct Queue* queue) {
		Node* toDelete;
		if (isEmptyQ(queue) == 1) {
			cout << "Queue is empty" << endl;
			return 0;
		}
		else
		{
			toDelete = queue->data[queue->frstElem];
			for (int i = queue->frstElem; i < queue->lastElem; i++) {
				queue->data[i] = queue->data[i + 1];
			}
			queue->lastElem--;
			return toDelete;
		}
	}
	/// <summary>
	/// BST Functions 
	/// </summary>
	BinarySearchTree();
	~BinarySearchTree();
	void preOrder();
	void width();
	void insert(int data);
	bool contains(int data);
	void remove(int data);
};

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	root = clear(root);
}

void BinarySearchTree::insert(int data)
{
	root = insertNode(data, root);
}

bool BinarySearchTree::contains(int data)
{
	root = search(data, root);
	if (root == NULL) return 0;
	if (data == root->data) return 1;
	else return 0;
}

void BinarySearchTree::remove(int data)
{
	root = removeNode(data, root);
}

void BinarySearchTree::preOrder() {
	bftTravers(root);
}

void BinarySearchTree::width() {
	dftTravers(root);
}

