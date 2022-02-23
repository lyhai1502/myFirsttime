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

void delete_dNode(dNode *&dnode)
{
    dnode->p_next = NULL;
    dnode->p_prev = NULL;
    delete dnode;
    dnode = NULL;
}
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
void addElement_dList(dList &L, int value)
{
    dNode *newdNode = initialize_dNode(value);
    newdNode->p_next = L.p_head;
    L.p_head->p_prev = newdNode;
    L.p_head = newdNode;
}
// Xoa dNode dau tien cua danh sach
void removeElement_dList(dList &L)
{
    dNode *p = L.p_head;
    L.p_head = L.p_head->p_next;
    L.p_head->p_prev = NULL;
    delete_dNode(p);
}
// Xoa tat ca cac Node cua danh sach
void removeAllElement_dList(dList &L)
{
    if (L.p_head == L.p_tail && L.p_head == NULL)
        return;
    while (L.p_head != NULL)
        removeElement_dList(L);
}
// In cac phan tu cua danh sach lien ket doi
void print_dList(dList L)
{
    for (dNode *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
}
// Them 1 phan tu vao vi tri thu x cua danh sach
void addElementIndex_dList(dList &L, int index, int value)
{
    dNode *newdNode = initialize_dNode(value);
    dNode *p = L.p_head;
    int i = 1;
    if (index < 1)
        return;
    if (index == 1)
    {
        addElement_dList(L, value);
        return;
    }
    while (i != index)
    {
        p = p->p_next;
        i++;
    }
    if (index > i)
        return;
    dNode *left = p->p_prev;
    dNode *right = p;
    left->p_next = newdNode;
    newdNode->p_prev = left;
    newdNode->p_next = right;
    right->p_prev = newdNode;
}
int main()
{
    dList ls;
    dNode *p = initialize_dNode(66);
    initialize_dList(ls, p);
    addElement_dList(ls, 77);
    addElement_dList(ls, 1001);
    addElementIndex_dList(ls, 9, 13);
    print_dList(ls);
    return 0;
}