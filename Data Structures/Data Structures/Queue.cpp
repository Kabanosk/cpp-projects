#include "Queue.h"

Queue::Queue() {
	first = NULL;
}

void Queue::deleteNode(QueueNode* node) {
	if (node != NULL) {
		deleteNode(node->next);
		delete node;
	}
}
void Queue::deleteQueue() {
	deleteNode(first);
}
int Queue::size() {
	return qSize;
}

void Queue::enqueue(QueueNode* node, int key) {
	if (node == NULL)
		node = new QueueNode(key);
	else 
		enqueue(node->next, key);
}
void Queue::enqueue(int key) {
	enqueue(first, key);
}
int Queue::dequeue() {
	if (first == NULL)
		std::cout << "ERROR: Queue underflow";
	else {
		int tmp = first->key;
		QueueNode* tmpNode = first->next;
		delete first;
		first = tmpNode;
		return tmp;
	}
}
int Queue::peek() {
	return first->key;
}