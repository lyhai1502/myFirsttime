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
void initializeNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->p_next = NULL;
    return p;
}

// khoi tao danh sach lien ket tu mot node cho truoc
void initializeList(List *&L, Node *&head)
{
    L = new List;
}
// Xoa node co vi tri thu x
void removeElement(List *&L, int index)
{
}
// Xoa cac node co gia tri trung
void removeDuppicateElement(List *&L)
{
}
// in ra màn hình danh sách liên kết
void printList(List *L)
{
    for (Node *p = L->p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
}
int main()
{

    return 0;
}