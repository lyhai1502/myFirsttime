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
}
// Them mot phan tu vao cuoi danh sach lien ket
void addElement(List &L, int value)
{
    Node *newNode = initializeNode(value);
    L.p_tail->p_next = newNode;
}

// In ra màn hình danh sách liên kết
void printList(List L)
{
    if (L.p_head == L.p_tail || L.p_head == NULL)
        return;
    for (Node *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
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
    for (int i = 0; i < n; i++)
    {
        int key;
        cout << "Nhap phan tu thu " << i + 1 << " : ";
        cin >> key;
        addElement(L, key);
    }
}
int main()
{
    inputLinkedList(L, n);
    printList(L);
    return 0;
}