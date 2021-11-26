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

// Xoa vinh vien con tro Node
void deleteNode(Node *&p)
{
    p->next = NULL;
    delete p;
    p = NULL;
}
// Khoi tao mot node co gia tri
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
// Khoi tao ngan xep
stackNode createStack()
{
    stackNode s;
    s.head = NULL;
    return s;
}
// Kiem tra ngan xep co dang rong?
int isStack_Empty(stackNode s)
{
    if (s.head == NULL)
        return 1;
    else
        return 0;
}
// Them phan tu moi vao ngan xep (them vao DAU danh sach)
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
// Xoa phan tu cua ngan xep (xoa o DAU danh sach) va tra ve gia tri phan tu do
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
// Dem so luong phan tu trong ngan xep
int countStack(stackNode s)
{
    if (isStack_Empty(s))
        return 0;
    int count = 0;
    for (Node *p = s.head; p != NULL; p = p->next)
        count++;
    return count;
}
// In cac gia tri phan tu trong ngan xep
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
// Kiem tra hang doi co dang rong?
int isQueue_Empty(queueNode q)
{
    if (q.head == NULL)
        return 1;
    else
        return 0;
}
// Them phan tu moi vao hang doi (them vao CUOI danh sach)
void enQueue(queueNode &q, int value)
{
    Node *node = createNode(value);
    if (isQueue_Empty(q))
    {
        q.head = node;
        q.tail = node;
    }
    else
    {
        q.tail->next = node;
        q.tail = node;
    }
}
int deQueue(queueNode &q)
{
    if (isQueue_Empty(q))
        return 0; // Khong co phan tu de lay
    Node *p = q.head;
    int data = q.head->value;
    q.head = q.head->next;
    deleteNode(p);
    if (q.head == NULL)
        q.tail = NULL;
    return data;
}
void printQueue(queueNode q)
{
    for (Node *p = q.head; p != NULL; p = p->next)
        cout << p->value << " ";
}
int main()
{
    queueNode q = createQueue();
    enQueue(q, 11);
    enQueue(q, 88);
    enQueue(q, 1212);
    enQueue(q, 32);
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    printQueue(q);
    return 0;
}