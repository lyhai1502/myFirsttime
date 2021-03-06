/* CAY NHI PHAN TIM KIEM */
#include "Header.h"

// Khoi tao mot nut tu mot gia tri cho truoc
Node *createNode(int data)
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cout << "Khong du bo nho!";
        exit(0);
    }
    newNode->key = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Them nut moi vao cay
void insert(Node *&root, int x)
{
    if (!root)
    {
        root = createNode(x);
        return;
    }
    if (x < root->key)
        insert(root->left, x);
    else
        insert(root->right, x);
}

// Duyet tien tu
void NLR(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

// Duyet trung tu
void LNR(Node *root)
{
    if (root)
    {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

// Duyet hau tu
void LRN(Node *root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

void rootLevel(Node *root, int level)
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
void levelOrder(Node *root)
{
    if (!root)
        return;
    for (int i = 1; i <= height(root) + 1; i++)
        rootLevel(root, i);
}

// Chieu cao cay
int height(Node *root)
{
    if (!root)
        return -1;
    if (height(root->left) > height(root->right))
        return (height(root->left) + 1);
    else
        return (height(root->right) + 1);
}

// So luong nut cay
int countNode(Node *root)
{
    if (!root)
        return 0;
    return countNode(root->left) + countNode(root->right) + 1;
}

// Tim nut co gia tri cho truoc
Node *search(Node *root, int x)
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

void replaceNode(Node *&p, Node *&q)
{
    if (q->left)
        replaceNode(p, q->left);
    else
    {
        p->key = q->key;
        p = q;
        q = q->right;
    }
}
// Xoa mot nut voi gia tri cho truoc
void remove(Node *&root, int x)
{
    if (!root)
        return;
    if (x < root->key)
        remove(root->left, x);
    else if (x > root->key)
        remove(root->right, x);
    else
    {
        Node *p = root;
        if (!root->left)
            root = root->right;
        else if (!root->right)
            root = root->left;
        else
        {
            replaceNode(p, root->right);
        }
        delete p;
    }
}
// Xoa toan bo cay
void removeTree(Node *&root)
{
    if (root)
    {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
    }
    root = NULL;
}

// Chieu cao tai 1 nut voi gia tri cho truoc
int heightNode(Node *root, int x)
{
    if (!root)
        return -1;
    if (root->key == x)
    {
        if (!root->left && !root->right)
            return 0;
        int l = 0, r = 0;
        if (root->left)
            l = heightNode(root->left, root->left->key);
        if (root->right)
            r = heightNode(root->right, root->right->key);
        return (l > r ? l : r) + 1;
    }
    else if (x < root->key)
        return heightNode(root->left, x);
    else
        return heightNode(root->right, x);
}

// Kiem tra phai la cay nhi phan tim kiem
bool isBST(Node *root)
{
    if (!root)
        return true;
    if (root->left && root->key <= root->left->key)
        return false;
    if (root->right && root->key >= root->right->key)
        return false;
    return isBST(root->left) && isBST(root->right);
}
