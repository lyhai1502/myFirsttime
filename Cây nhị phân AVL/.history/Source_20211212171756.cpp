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

// Xu ly can bang
NODE *updateAVLTree(NODE *tree)
{
    if (abs(tree->left->height - tree->right->height) > 1)
    {
        if (tree->left->height > tree->right->height)
        {
            NODE *p = tree->left;
            if (p->left->height >= p->right->height)
            {
                tree = rightRotate(t);
            }
            else
            {
                t->left = leftRotate(t->left);
                tree = rightRotate(t);
            }
        }
        else
        {
            NODE *p = tree->right;
            if (p->right->height >= p->left->height)
            {
                tree = leftRotate(tree);
            }
            else
            {
                tree->right = rightRotate(tree->right);
                tree = leftRotate(tree);
            }
        }
    }
    if (tree->left != NULL)
        tree->left = updateAVLTree(tree->left);
    if (tree->right != NULL)
        tree->right = updateAVLTree(tree->right);
    return tree;
}

// He so can bang
int balanceFactor(NODE *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

NODE *createNode(int data)
{
    NODE *newNode = new NODE;
    if (!newNode)
    {
        cout << "Khong du bo nho!";
        exit(0);
    }
    newNode->key = data;
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
}