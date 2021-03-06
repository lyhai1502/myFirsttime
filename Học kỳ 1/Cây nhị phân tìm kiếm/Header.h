#ifndef __HEADER_H__
#define __HEADER_H__

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

// Duyet hau tu
void LRN(Node *root);

// Duyet tung tang
void levelOrder(Node *root);

// Chieu cao cay
int height(Node *root);

// So luong nut cay
int countNode(Node *root);

// Tim nut co gia tri cho truoc
Node *search(Node *root, int x);

// Xoa mot nut voi gia tri cho truoc
void remove(Node *&root, int x);

// Xoa toan bo cay
void removeTree(Node *&root);

// Chieu cao tai 1 nut voi gia tri cho truoc
int heightNode(Node *root, int x);

// Kiem tra phai la cay nhi phan tim kiem
bool isBST(Node *root);
#endif // __HEADER_H__