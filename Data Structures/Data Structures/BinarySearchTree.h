#pragma once
#include <iostream>

using namespace std;

struct Node {
	int key;
	struct Node* left;
	struct Node* right;

	Node(int key) {
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree
{
public:
	BinarySearchTree();

	void insert(int key);
	Node* search(int key);
	void deleteTree();

private:
	Node* root;
	void deleteNode(Node* node);
	void insert(int key, Node* node);
	Node* search(int key, Node* node);
};

