#pragma once
#include <iostream>

struct Node {
    int key, height;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        key = val;
        height = 1;
        left = NULL;
        right = NULL;
    }

    Node* newNode(int key)
    {
        Node* node = new Node(key);
        return(node);
    }
};



class AVLtree
{
public:

    AVLtree();
    void insert(int key);

private:

    Node* root;

    int height(Node* node);
    int max(int a, int b);
    int getBalance(Node* node);

    Node* insert(Node* node, int key);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);

};

