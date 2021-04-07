#pragma once
#include <iostream>

struct AVLNode {
    int key, height;
    struct AVLNode* left;
    struct AVLNode* right;

    AVLNode(int val) {
        key = val;
        height = 1;
        left = NULL;
        right = NULL;
    }

    AVLNode* newNode(int key)
    {
        AVLNode* node = new AVLNode(key);
        return(node);
    }
};



class AVLtree
{
public:

    AVLtree();
    void insert(int key);

private:

    AVLNode* root;

    int height(AVLNode* node);
    int max(int a, int b);
    int getBalance(AVLNode* node);

    AVLNode* insert(AVLNode* node, int key);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);

};

