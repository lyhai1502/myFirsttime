#include "Header.h"

// Tìm chiều cao của cây
int height(NODE *root)
{
    if (!root)
        return 0;
    return root->height;
}

int findMax(int a, int b)
{
    return a > b ? a : b;
}
// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *X = A->left;
    NODE *Y = X->right;
    X->right = A;
    A->left = Y;

    // Cap nhat chieu cao
    A->height = max(A->left->height, A->right->height) + 1;
    X->height = max(X->left->height, X->right->height) + 1;

    return X;
}

NODE *leftRotate(NODE *B)
{
    NODE *X = B->right;
    NODE *Y = X->left;
    X->left = B;
    B->right = Y;

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
    else // if (x > root->key)
        insert(root->right, x);
    // else
    // {
    //     cout << "Co gia tri bi trung!";
    //     return;
    // }

    // Cap nhat chieu cao cac Node trong cay
    root->height = max(root->left->height, root->right->height) + 1;

    // Cap nhat he so can bang va can bang cay
    // int balance = balanceFactor(root);
    // if (balance > 1 && x < root->left->key)
    // {
    //     root = rightRotate(root);
    //     return;
    // }
    // if (balance < -1 && x > root->right->key)
    // {
    //     root = leftRotate(root);
    //     return;
    // }
    // if (balance > 1 && x > root->left->key)
    // {
    //     root->left = leftRotate(root->left);
    //     root = rightRotate(root);
    //     return;
    // }
    // if (balance < -1 && x < root->right->key)
    // {
    //     root->right = rightRotate(root->right);
    //     root = leftRotate(root);
    //     return;
    // }
    // return;
}

// NODE *updateAvlTree(NODE *root)
// {
// }

void rootLevel(NODE *root, int level)
{
    if (!root)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1)
    {
        rootLevel(root->left, level - 1);
        rootLevel(root->right, level - 1);
    }
}

// Duyet tung tang
void levelOrder(NODE *root)
{
    if (!root)
        return;
    for (int i = 1; i <= height(root) + 1; i++)
        rootLevel(root, i);
}

// In ra cây
void NLR(NODE *root)
{
    if (root)
    {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

int main()
{
    NODE *tree = NULL;
    insert(tree, 1);
    insert(tree, 5);

    NLR(tree);
    return 0;
}