#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}


void BinarySearchTree::destroyNode(Node* node) {
	if (node != NULL) {
		destroyNode(node->left);
		destroyNode(node->right);
		delete node;
	}
}

void BinarySearchTree::destroyTree() {
	destroyNode(root);
}


void BinarySearchTree::insert(int key) {
	if (root == NULL) 
		root = new Node(key);
	else 
		insert(key, root);
}

void BinarySearchTree::insert(int key, Node* node) {
	if (key >= node->data) {
		if (node->right == NULL) 
			node->right= new Node(key);
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
	if (node->data == NULL) {
		return NULL;
	}
	else {
		if (key == node->key) 
			return node;
		else if (key > node->key) 
			return search(key, node->right);
		else 
			return search(key, node->left);
	}
}

