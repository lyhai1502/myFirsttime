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

List L;
int n;

// Khoi tao mot node co gia tri cho truoc
Node *initializeNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL;
    return node;
}
// Khoi tao danh sach lien ket tu mot node cho truoc
List initializeList()
{
    List L;
    L.p_head = L.p_tail = NULL;
    return L;
}
// Them mot phan tu vao cuoi danh sach lien ket
void addElement(List &L, int value)
{
    Node *newNode = initializeNode(value);
    if (L.p_head == NULL)
    {
        L.p_head = newNode;
        L.p_tail = newNode;
    }
    else
    {
        L.p_tail->p_next = newNode;
        L.p_tail = newNode;
    }
}

// In ra màn hình danh sách liên kết
void printList(List L)
{
    if (L.p_head == L.p_tail && L.p_head == NULL)
        return;
    for (Node *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
    cout << endl;
}

void inputLinkedList(List &L, int &n)
{
    cout << "Nhap so phan tu danh sach (1 -> 10^3): ";
    cin >> n;
    while (n <= 0 || n > 1000)
    {
        cout << "Ban nhap khong thoa man. Hay nhap lai: ";
        cin >> n;
    }
    L = initializeList();
    for (int i = 0; i < n; i++)
    {
        int key;
        cout << "Nhap phan tu thu " << i + 1 << " : ";
        cin >> key;
        addElement(L, key);
    }
}

Node *pre_Node(List L, Node *node)
{
    if (L.p_head == NULL)
        return NULL;
    Node *preNode;
    for (Node *p = L.p_head; p->p_next != NULL; p = p->p_next)
        if (p->p_next == node)
            preNode = p;
    return preNode;
}
void function01(List &L, int n)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;
    Node *left = L.p_head;
    Node *right = L.p_tail;
    while (left != right && left != right->p_next)
    {
        Node *q1 = left->p_next;
        Node *q2 = pre_Node(L, right);
        left->p_next = right;
        right->p_next = q1;

        left = q1;
        right = q2;
        if (right == left->p_next)
            q2->p_next->p_next = NULL;
        else
            q2->p_next = NULL;
    }
    cout << endl;
}
int main()
{
    inputLinkedList(L, n);
    printList(L);
    function01(L, n);
    printList(L);
    return 0;
}