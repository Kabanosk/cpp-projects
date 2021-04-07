#include "AVLtree.h"

AVLtree::AVLtree() {
    root = NULL;
}

int AVLtree::max(int a, int b)
{
    return (a > b) ? a : b;
}
int AVLtree::height(AVLNode* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
int AVLtree::getBalance(AVLNode* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void AVLtree::insert(int key) {
    root = insert(root, key);
}
AVLNode* AVLtree::insert(AVLNode* node, int key)
{
    if (node == NULL)
        return(node->newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
        height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* AVLtree::rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
AVLNode* AVLtree::leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}