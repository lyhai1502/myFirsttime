#include "Header.h"
using namespace std;

// Ham chuc nang
void Bai01(List &L, int n)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;

    // Tao 2 con tro Node o dau va cuoi va chay ve phia nhau
    Node *left = L.p_head;
    Node *right = L.p_tail;

    while (left != right && left != right->p_next)
    {
        // Luu Node ke tiep cua LEFT va node truoc do cua RIGHT
        Node *leftNext = left->p_next;
        Node *rightPrev = pre_Node(L, right);

        // Lien ket LEFT voi RIGHT, RIGHT voi node ke tiep LEFT
        left->p_next = right;
        right->p_next = leftNext;

        // Xu ly truong hop Node cuoi cung ko tro NULL
        if (rightPrev->p_next == leftNext)
            leftNext->p_next = NULL;
        else
            rightPrev->p_next = NULL;

        left = leftNext;
        right = rightPrev;
    }
    cout << endl;
}

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

// In ra man hinh danb sach lien ket
void printList(List L)
{
    if (L.p_head == L.p_tail && L.p_head == NULL)
        return;
    for (Node *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
    cout << endl;
}

// Nhap du lieu dau vao
void inputLinkedList(List &L, int &n)
{
    cin >> n;
    L = initializeList();
    for (int i = 0; i < n; i++)
    {
        int key;
        // cout << "Nhap phan tu thu " << i + 1 << " : ";
        cin >> key;
        addElement(L, key);
    }
}

// Tra ve node truoc cua node do
Node *pre_Node(List L, Node *node)
{
    if (L.p_head == NULL)
        return NULL;
    for (Node *p = L.p_head; p->p_next != NULL; p = p->p_next)
        if (p->p_next == node)
            return p;
}