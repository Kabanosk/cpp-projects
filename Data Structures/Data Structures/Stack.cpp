#include "Stack.h"

Stack::Stack(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
}
Stack::~Stack() {
	delete[] arr;	
}

bool Stack::isEmpty() {
	if (top == -1) return true;
	else return false;
}
bool Stack::isFull() {
	if (top == capacity - 1) return true;
	else return false;
}
int Stack::size() {
	return top + 1;
}

void Stack::push(int key) {
	if (isFull()) 
		std::cout << "ERROR: Stack overflow\n";
	else 
		arr[++top] = key;
}
int Stack::pop() {
	if (isEmpty()) 
		std::cout << "ERROR: Stack underflow\n";
	else 
		return arr[top--];
}
int Stack::peek() {
	if (isEmpty()) 
		std::cout << "Stack is empty";
	else 
		return arr[top];
}

