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
Node *createNode(int data);

// Them nut moi vao cay
void insert(Node *&root, int x);

// Duyet tien tu
void NLR(Node *root);

// Duyet trung tu
void LNR(Node *root);