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
        cout << "Gia tri vua them da bi trung!\n";
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

// Tim va tra ve mot node cho truoc
NODE *search(NODE *root, int x)
{
    if (!root)
        return NULL; // Khong tim thay
    if (root->key == x)
        return root; // Tim thay
    else if (x < root->key)
        return search(root->left, x);
    else
        return search(root->right, x);
}

// Chieu cao cua cay
int heightTree(NODE *root)
{
    if (!root)
        return -1;
    return findMax(heightTree(root->left), heightTree(root->right)) + 1;
}
// Kiem tra co phai cay AVL
bool isAVL(NODE *root)
{
    if (!root)
        return true;
    if (abs(heightTree(root->left) - heightTree(root->right)) > 1)
        return false;
    return isAVL(root->left) && isAVL(root->right);
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

// Xuat cay duyet giua
void LNR(NODE *root)
{
    if (root)
    {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

// Xuat cay duyet sau
void LRN(NODE *root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

// Xuat cac phan tu o tang level
void printLevel(NODE *root, int level)
{
    if (!root)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Duyet tung tang
void levelOrder(NODE *root)
{
    if (!root)
        return;
    for (int i = 1; i <= height(root) + 1; i++)
        printLevel(root, i);
}

// Dem so luong nut nho hon gia tri cho truoc
int countLesser(NODE *root, int x)
{
    if (!root)
        return 0;
    if (root->key >= x)
        return countLesser(root->left, x);
    else
        return 1 + countLesser(root->left, x) + countLesser(root->right, x);
}

// Dem so luong nut lon hon gia tri cho truoc
int countGreater(NODE *root, int x)
{
    if (!root)
        return 0;
    if (root->key <= x)
        return countGreater(root->right, x);
    else
        return 1 + countGreater(root->left, x) + countGreater(root->right, x);
}

// Dem so luong nut la
int countLeaves(NODE *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    else
        return countLeaves(root->left) + countLeaves(root->right);
}

// Xoa toan bo cay
int removeTree(NODE *&root)
{
    if (root)
    {
        return removeTree(root->left);
        return removeTree(root->right);
        delete root;
    }
    root = NULL;
    if (!root)
        return 1;
    else
        return 0;
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

    cout << removeTree(tree) << endl;
    NLR(tree);
    return 0;
}