#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *p_next;
};

struct List
{
    Node *p_head;
    Node *p_tail;
};

// Khoi tao mot node co gia tri cho truoc
Node *initializeNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL;
    return node;
}

// Them mot phan tu vao dau danh sach lien ket
void addElement(List &L, int value)
{
    Node *newNode = initializeNode(value);
    newNode->p_next = L.p_head;
    L.p_head = newNode;
}