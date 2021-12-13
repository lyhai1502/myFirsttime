#include "Header.h"

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *X = A->left;
    NODE *Y = X->right;
    A->left = Y;
    X->right = A;

    // Cap nhat chieu cao
    A->height = max(A->left->height, A->right->height) + 1;
    X->height = max(X->left->height, X->right->height) + 1;

    return X;
}

NODE *leftRotate(NODE *B)
{
    NODE *X = B->right;
    NODE *Y = X->left;
    B->right = Y;
    X->left = B;

    // Cap nhat chieu cao
    B->height = max(B->left->height, B->right->height) + 1;
    X->height = max(X->left->height, X->right->height) + 1;

    return X;
}

// He so can bang
int balanceFactor(NODE *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

// Khoi tao mot nut, chieu cao 1
NODE *createNode(int x)
{
    NODE *newNode = new NODE;
    if (!newNode)
    {
        cout << "Khong du bo nho!";
        exit(0);
    }
    newNode->key = x;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(NODE *&root, int x)
{
    if (!root)
    {
        root = createNode(x);
        return;
    }
    if (x < root->key)
        insert(root->left, x);
    else if (x > root->key)
        insert(root->right, x);
    else
    {
        cout << "Co gia tri bi trung!";
        return;
    }

    // Cap nhat chieu cao cac Node trong cay
    root->height = max(root->left->height, root->right->height) + 1;

    // Cap nhat he so can bang va can bang cay
    int balance = balanceFactor(root);
    if (balance > 1 && x < root->left->x)
        root = rightRotate(root);
    if (balance < -1 && x > root->right->x)
        root = leftRotate(root);
    if (balance > 1 && x > root->left->x)
    {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    if (balance < -1 && x < root->right->x)
    {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return;
}

NODE *updateAvlTree(NODE *root)
{
}