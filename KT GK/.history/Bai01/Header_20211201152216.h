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

List L;
int n;

// Ham thuc hien yeu cau bai 01
void Bai01(List &L, int n);

// Khoi tao mot node co gia tri cho truoc
Node *initializeNode(int key);

// Khoi tao danh sach lien ket tu mot node cho truoc
List initializeList();