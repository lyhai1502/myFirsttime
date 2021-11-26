#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *p_next;
};
struct stack_Node
{
    Node *head;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->p_next = NULL;
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
        node->p_next = s.head;
        s.head = node;
    }
}
int popStack(stack_Node &s)
{
}