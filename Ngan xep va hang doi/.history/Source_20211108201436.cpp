#include "Header.h"
using namespace std;

//--------------- NODE ----------------
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

// --------------- STACK ----------------
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

// ------------------ QUEUE -----------------
// Khoi tao hang doi
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
// Xoa phan tu cua hang doi (xoa o DAU danh sach)
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
// In cac phan tu cua hang doi
void printQueue(queueNode q)
{
    for (Node *p = q.head; p != NULL; p = p->next)
        cout << p->value << " ";
}

/* *************************************************** */
int doUuTien(char x)
{
    if (x == '+' || x == '-')
        return 0;
    else if (x == '*' || x == '/')
        return 1;
    else if (x == '^')
        return 2;
}
char *trungToSangHauTo(char *trungTo)
{
    char *hauTo = new char;
    stackNode toanTu = createStack();
    char token;
    int indexTrungTo = 0, indexHauTo = 0;
    while (trungTo[indexTrungTo] != '\0')
    {
        token = trungTo[indexTrungTo++];
        if (token - '0' >= 0 && token - '0' <= 9)
            hauTo[indexHauTo++] = token;
        else
        {
            while (doUuTien(token) <= doUuTien((char)(toanTu.head->value + '0')) && !isStack_Empty(toanTu))
                hauTo[indexHauTo++] = (char)(popStack(toanTu) + 48);
            pushStack(toanTu, token - '0');
            if (isStack_Empty(toanTu))
                cout << "khong co";
        }
    }
    while (!isStack_Empty(toanTu))
        hauTo[indexHauTo++] = (char)(popStack(toanTu) + 48);
    hauTo[indexHauTo] = '\0';
    return hauTo;
}