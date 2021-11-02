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
initializeNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL;
    return node;
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