#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
struct stackNode
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
stackNode createStack()
{
    stackNode s;
    s.head = NULL;
    return s;
}

int isStack_Empty(stackNode s)
{
    if (s.head == NULL)
        return 1;
    else
        return 0;
}
void pushStack(stackNode &s, int value)
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
int popStack(stackNode &s)
{
    if (isStack_Empty(s))
        return 0; // Khong co phan tu de lay
    Node *p = s.head;
    int data = s.head->value;
    s.head = s.head->next;
    deleteNode(p);
    return data;
}
int countStack(stackNode s)
{
    if (isStack_Empty(s))
        return 0;
    int count = 0;
    for (Node *p = s.head; p != NULL; p = p->next)
        count++;
    return count;
}
void printStack(stackNode s)
{
    for (Node *p = s.head; p != NULL; p = p->next)
        cout << p->value << " ";
}

struct queueNode
{
    Node *head;
    Node *tail;
};
queueNode createQueue()
{
    queueNode q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}
int isQueue_Empty(queueNode q)
{
    if (q.head == NULL)
        return 1;
    else
        return 0;
}
int main()
{
}