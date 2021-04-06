#include "Stack.h"

StackArr::StackArr(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
}
StackArr::~StackArr() {
	delete[] arr;	
}

bool StackArr::isEmpty() {
	if (top == -1) return true;
	else return false;
}
bool StackArr::isFull() {
	if (top == capacity - 1) return true;
	else return false;
}
int StackArr::size() {
	return top + 1;
}

void StackArr::push(int key) {
	if (isFull()) 
		std::cout << "ERROR: Stack overflow\n";
	else 
		arr[++top] = key;
}
int StackArr::pop() {
	if (isEmpty()) 
		std::cout << "ERROR: Stack underflow\n";
	else 
		return arr[top--];
}
int StackArr::peek() {
	if (isEmpty()) 
		std::cout << "Stack is empty";
	else 
		return arr[top];
}

