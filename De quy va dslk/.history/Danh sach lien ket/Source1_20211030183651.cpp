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

// khoi tao mot node co gia tri cho truoc
Node *initialize(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL;
    return node;
}
// khoi tao danh sach lien ket
void initializeList(List *&L, Node *&head)
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