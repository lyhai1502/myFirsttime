#include <iostream>
using namespace std;

struct NODE
{
    int key;
    int height;
    NODE *left;
    NODE *right;
};

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A);
// Xoay trai tai mot nut
NODE *leftRotate(NODE *B);

// Khoi tao 1 nut, chieu cao = 1
NODE *createNode(int data);

// Them mot nut moi
void insert(NODE *&root, int x);

// Xoa mot nut
void remove(NODE *&root, int x);

// Tim va tra ve 1 Node
NODE *search(NODE *root, int x);

// Kiem tra co phai cay AVL
bool isAVL(NODE *root);

// Xuat cay: Duyet truoc
void NLR(NODE *root);
// Xuat cay: Duyet giua
void LNR(NODE *root);
// Xuat cay: Duyet sau
void LRN(NODE *root);
// Xuat cay: Duyet tung tang
void levelOrder(NODE *root);

// Dem so luong nut nho hon gia tri cho truoc
int countLesser(NODE *root, int x);
// Dem so luong nut lon hon gia tri cho truoc
int countGreater(NODE *root, int x);
// Dem so luong nut la
int countLeaves(NODE *root);

// Xoa toan bo cay
int removeTree(NODE *&root);
