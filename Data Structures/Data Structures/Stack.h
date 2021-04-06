#pragma once
#include <iostream>

class StackArr
{
private:
	int* arr;
	int top, capacity;

public:
	StackArr(int size);
	~StackArr();
	bool isEmpty();
	bool isFull();
	int size();

	void push(int key);
	int pop();
	int peek();
};