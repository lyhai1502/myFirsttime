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

// khởi tạo một node với giá trị cho trước
Node *initialize(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL;
    return node;
}
// khởi tạo một dslk
void initializeList(List *&L, Node *&head)
{
}
// in ra màn hình một node
void printNode(Node *p)
{
    cout << p->key;
}
int main()
{
    Node *p;
    p = initialize(5);
    cout << p->key;
    return 0;
}