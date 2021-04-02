#pragma once
#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	
	void insert(int val);
	Node* search(int val);
	void destroyTree();

private:
	Node* root;
	void destroyNode(Node* node);
	void insert(int val, Node* node);
	Node* search(int val, Node* node);
};

