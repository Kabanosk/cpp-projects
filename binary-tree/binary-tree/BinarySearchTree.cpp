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


void BinarySearchTree::insert(int val) {
	if (root == NULL) 
		root = new Node(val);
	else 
		insert(val, root);
}

void BinarySearchTree::insert(int val, Node* node) {
	if (val >= node->data) {
		if (node->right == NULL) 
			node->right= new Node(val);
		else 
			insert(val, node->right);
	}
	else {
		if (node->left == NULL) 
			node->left = new Node(val);
		else
			insert(val, node->left);
	}
}


Node* BinarySearchTree::search(int val) {
	return search(val, root);
}

Node* BinarySearchTree::search(int val, Node* node) {
	if (node->data == NULL) {
		return NULL;
	}
	else {
		if (val == node->data) 
			return node;
		else if (val > node->data) 
			return search(val, node->right);
		else 
			return search(val, node->left);
	}
}

