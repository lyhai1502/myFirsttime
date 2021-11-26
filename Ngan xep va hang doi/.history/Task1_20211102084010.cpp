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
stack_Node createStack()
{
    stack_Node s;
    s.head = NULL;
    return s;
}

int isStack_Empty(stack_Node s)
{
    if (s.head == NULL)
        return 1;
    else
        return 0;
}
void pushStack(stack_Node &s, int value)
{
    Node *node = createNode(value);
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
    return data;
}

void printStack(stack_Node s)
{
    for (Node *p = s.head; p != NULL; p = p->next)
        cout << p->value << " ";
}
int main()
{
    stack_Node s = createStack();
    pushStack(s, 77);
    pushStack(s, 66);
    printStack(s);
    return 0;
}