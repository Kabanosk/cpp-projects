#pragma once
#include <iostream>

class Stack
{
private:
	int* arr;
	int top, capacity;

public:
	Stack(int size);
	~Stack();
	bool isEmpty();
	bool isFull();
	int size();

	void push(int key);
	int pop();
	int peek();
};
