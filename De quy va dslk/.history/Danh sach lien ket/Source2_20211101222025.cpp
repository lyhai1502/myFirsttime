#include <iostream>
using namespace std;
struct dNode
{
    int key;
    dNode *p_prev;
    dNode *p_next;
};
struct dList
{
    dNode *p_head;
    dNode *p_tail;
};

// Khoi tao mot node co gia tri cho truoc
dNode *initialize_dNode(int key)
{
    dNode *newdNode = new dNode;
    newdNode->key = key;
    newdNode->p_prev = NULL;
    newdNode->p_next = NULL;
    return newdNode;
}
// Khoi tao danh sach lien ket doi tu mot dNode cho truoc
void initialize_dList(dList &L, dNode *&head)
{
    L.p_head = L.p_tail = NULL;
    L.p_head = head;
    L.p_tail = head;
}
// Them mot phan tu vao dau danh sach lien ket doi
void addElement_dNode(dList &L, int value)
{
    dNode *newNode = initialize_dNode(value);
}