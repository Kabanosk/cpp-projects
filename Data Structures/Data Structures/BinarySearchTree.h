#pragma once
#include <iostream>

using namespace std;

struct BSTNode {
	int key;
	struct BSTNode* left;
	struct BSTNode* right;

	BSTNode(int key) {
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
	BSTNode* search(int key);
	void deleteTree();

private:
	BSTNode* root;
	void deleteNode(BSTNode* node);
	void insert(int key, BSTNode* node);
	BSTNode* search(int key, BSTNode* node);
};

