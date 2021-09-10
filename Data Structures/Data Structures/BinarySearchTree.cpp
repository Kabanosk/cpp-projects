#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

void BinarySearchTree::deleteNode(BSTNode* node) {
	if (node != NULL) {
		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}
}
void BinarySearchTree::deleteTree() {
	deleteNode(root);
}

void BinarySearchTree::insert(int key) {
	if (root == NULL) {
		root = new BSTNode(key);
	}
	else {
		insert(key, root);
	}
}
void BinarySearchTree::insert(int key, BSTNode* node) {
	if (key >= node->key) {
		if (node->right == NULL)
			node->right = new BSTNode(key);
		else
			insert(key, node->right);
	}
	else {
		if (node->left == NULL)
			node->left = new BSTNode(key);
		else
			insert(key, node->left);
	}
}

BSTNode* BinarySearchTree::search(int key) {
	return search(key, root);
}
BSTNode* BinarySearchTree::search(int key, BSTNode* node) {
	if (node->key == NULL) {
		return NULL;
	}
	else {
		if (node->key == key) {
			return node;
		}
		else if (key > node->key) {
			return search(key, node->right);
		}
		else {
			return search(key, node->left);
		}
	}
}


