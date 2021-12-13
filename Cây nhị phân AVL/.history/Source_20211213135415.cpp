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
    A->height = findMax(height(A->left), height(A->right)) + 1;
    X->height = findMax(height(X->left), height(X->right)) + 1;

    return X;
}

NODE *leftRotate(NODE *B)
{
    NODE *X = B->right;
    NODE *Y = X->left;
    X->left = B;
    B->right = Y;

    // Cap nhat chieu cao
    B->height = findMax(height(B->left), height(B->right)) + 1;
    X->height = findMax(height(X->left), height(X->right)) + 1;

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

NODE *updateAvlTree(NODE *root, int x)
{
    int balance = balanceFactor(root);
    if (balance > 1 && x < root->left->key)
        return rightRotate(root);
    if (balance < -1 && x > root->right->key)
        return leftRotate(root);
    if (balance > 1 && x > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && x < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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
    root->height = findMax(height(root->left), height(root->right)) + 1;

    // Cap nhat he so can bang va can bang cay
    root = updateAvlTree(root, x);
    return;
}

// Tim node co gia tri nho nhat
NODE *findMinValue(NODE *root)
{
    NODE *cur = root;
    while (cur->left)
        cur = cur->left;
    return cur;
}
// Xoa mot node
void remove(NODE *&root, int x)
{
    if (!root)
        return;
    if (x < root->key)
        remove(root->left, x);
    else if (x > root->key)
        remove(root->right, x);
    else
    {
        if (!root->left || !root->right)
        {
            NODE *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            NODE *temp = findMinValue(root->right);
            root->key = temp->key;
            remove(root->right, temp->key);
        }
    }
}

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

// Xuat cay duyet truoc
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
    insert(tree, 2);
    insert(tree, 4);
    insert(tree, 3);
    insert(tree, 99);
    insert(tree, 4);

    levelOrder(tree);
    return 0;
}