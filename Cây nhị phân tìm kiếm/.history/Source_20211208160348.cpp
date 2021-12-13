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

// Duyet tien to
void NLR(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Node *root)
{
}
void LRN(Node *root)
{
}

void levelOrder(Node *root)
{
}

// Chieu cao cay
int height(Node *root)
{
}

// So luong nut cay
int countNode(Node *root)
{
}

// Tim nut co gia tri cho truoc
Node *search(Node *root, int x)
{
}

// Xoa mot nut voi gia tri cho truoc
void remove(Node *&root, int x)
{
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
}