#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

void BinarySearchTree::deleteNode(Node* node) {
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
		root = new Node(key);
	}
	else {
		insert(key, root);
	}
}
void BinarySearchTree::insert(int key, Node* node) {
	if (key >= node->key) {
		if (node->right == NULL)
			node->right = new Node(key);
		else
			insert(key, node->right);
	}
	else {
		if (node->left == NULL)
			node->left = new Node(key);
		else
			insert(key, node->left);
	}
}

Node* BinarySearchTree::search(int key) {
	return search(key, root);
}
Node* BinarySearchTree::search(int key, Node* node) {
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