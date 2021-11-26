#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
struct stack_Node
{
    Node *head;
};
void deleteNode(Node *&p)
{
    p->next = NULL;
    delete p;
    p = NULL;
}
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void createStack(stack_Node &s)
{
    s.head = NULL;
}

int isStack_Empty(stack_Node s)
{
    if (s.head == NULL)
        return 1;
    else
        return 0;
}
void pushStack(stack_Node &s, Node *node)
{
    if (isStack_Empty(s))
        s.head = node;
    else
    {
        node->next = s.head;
        s.head = node;
    }
}
int popStack(stack_Node &s)
{
    if (isStack_Empty(s))
        return 0; // Khong co phan tu de lay
    Node *p = s.head;
    int data = s.head->value;
    s.head = s.head->next;
    deleteNode(p);
}