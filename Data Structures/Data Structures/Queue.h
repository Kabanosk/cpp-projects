#pragma once

#include <iostream>

struct QueueNode
{	
	int key;
	struct QueueNode* next;

	QueueNode(int key) {
		this->key = key;
		next = NULL;
	}

	QueueNode* newQueueNode(int key) {
		QueueNode* node = new QueueNode(key);
		return (node);
	}
};

class Queue
{
private:
	QueueNode* first;
	int qSize;
	void deleteNode(QueueNode* node);
	void enqueue(QueueNode* node, int key);

public:
	Queue();
	void deleteQueue();

	void enqueue(int key);
	int dequeue();
	int peek();

	int size();
};

