/* CAY NHI PHAN TIM KIEM */
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

// Khoi tao mot nut tu mot gia tri cho truoc
Node *createNode(int data)
{
    Node *newNode = new Node;
    if (newNode == NULL)
    {
        cout << "Khong du bo nho!";
        return NULL;
    }
    newNode->key = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Them nut moi vao cay
void insert(Node *&root, int x)
{
    if (root == NULL)
    {
        root = createNode(x);
        return;
    }
    if (x <= root->key)
        insert(root->left, x);
    else
        insert(root->right, x);
}

// Duyet tien tu
void NLR(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

// Duyet trung tu
void LNR(Node *root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

// Duyet hau tu
void LRN(Node *root)
{
    if (root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

// Chieu cao cay
int height(Node *root)
{
    if (root == NULL)
        return -1;
    int heightLeft = height(root->left);
    int heighRight = height(root->right);
    if (heightLeft > heighRight)
        return (heightLeft + 1);
    else
        return (heighRight + 1);
}

void nodeLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1)
    {
        nodeLevel(root->left, level - 1);
        nodeLevel(root->right, level - 1);
    }
}

// Duyet tung tang
void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    for (int i = 1; i <= height(root) + 1; i++)
        nodeLevel(root, i);
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
    if (x <= root->key)
        return search(root->left, x);
    else
        return search(root->right, x);
}

// Xoa mot nut voi gia tri cho truoc
void remove(Node *&root, int x)
{
    if (!root)
        return;
    Node *delNode = search(root, x);
}

// Xoa toan bo cay
void removeTree(Node *&root)
{
}

// Chieu cao tai 1 nut voi gia tri cho truoc
int heightNode(Node *root, int x)
{
}

// Kiem tra phai la cay nhi ohan tim kiem
bool isBST(Node *root)
{
}

int main()
{
    Node *root = NULL;
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, -8);
    insert(root, 8);
    cout << search(root, -8)->key;
    return 0;
}