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
// khoi tao danh sach lien ket tu mot node cho truoc
void initializeList(List &L, Node *&head)
{
    L.p_head = L.p_tail = NULL;
    L.p_head = head;
    L.p_tail = head;
}
// Them mot phan tu vao dau danh sach lien ket
void addElement(List &L, int value)
{
    Node *newNode = initializeNode(value);
    newNode->p_next = L.p_head;
    L.p_head = newNode;
}
// Xoa node dau tien khoi danh sach
void removeElement(List &L)
{
    Node *p = L.p_head;
    L.p_head = L.p_head->p_next;
    p->p_next = NULL;
    delete p;
    p = NULL;
}
// Xoa tat cac cac node khoi danh sach
void removeAllElement(List &L)
{
    Node *p = L.p_head;
    while (p == L.p_head)
    {
        removeElement(L);
        p->p_next = NULL;
        delete p;
        if (L.p_head != NULL)
            p = L.p_head;
    }
}
// Them 1 phan tu vao vi tri thu x của danh sach lien ket
void addElementIndex(List &L, int index, int value)
{
    Node *newNode = initializeNode(value);
    Node *p = L.p_head;
    int i = 1;
    if (index < 1)
        return;
    if (index == 1)
    {
        newNode->p_next = L.p_head;
        L.p_head = newNode;
        return;
    }
    while (i < index - 1 && p->p_next != NULL)
    {
        p = p->p_next;
        i++;
    }
    newNode->p_next = p->p_next;
    p->p_next = newNode;
}
// Xoa node vi tri thu x khoi danh sach
void removeElementIndex(List &L, int index)
{
    if (index < 1)
        return;
    if (index == 1)
    {
        removeElement(L);
        return;
    }
    Node *p = L.p_head;
    int i = 1;
    while (i < index - 1 && p->p_next->p_next != NULL)
    {
        p = p->p_next;
        i++;
    }
    if (index - 1 > i)
        return;
    Node *q = p->p_next;
    p->p_next = p->p_next->p_next;
    q->p_next = NULL;
    delete q;
    q = NULL;
}
// in ra màn hình danh sách liên kết
void printList(List L)
{
    for (Node *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
}
int main()
{
    List ls;
    Node *newNode = initializeNode(5);
    initializeList(ls, newNode);
    addElement(ls, 7);
    addElement(ls, 8);
    addElementIndex(ls, 1, 3);
    printList(ls);
    return 0;
}