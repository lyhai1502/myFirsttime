#include "Header.h"
using namespace std;

// Xoa vinh vien con tro Node
void deleteNode(Node *&p)
{
    p->p_next = NULL;
    delete p;
    p = NULL;
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
void initializeList(List &L, Node *&head)
{
    L.p_head = L.p_tail = NULL;
    L.p_head = head;
    L.p_tail = head;
}
// Them mot phan tu vao dau danh sach lien ket
void addElement(List &L, int value)
{
    Node *newNode = initializeNode(value);
    newNode->p_next = L.p_head;
    L.p_head = newNode;
}
// Xoa node dau tien khoi danh sach
void removeElement(List &L)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;
    Node *p = L.p_head;
    L.p_head = L.p_head->p_next;
    deleteNode(p);
}
// Xoa tat cac cac node khoi danh sach
void removeAllElement(List &L)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;
    while (L.p_head != NULL)
    {
        removeElement(L);
    }
}
// Them 1 phan tu vao vi tri thu x của danh sach lien ket
void addElementIndex(List &L, int index, int value)
{
    Node *newNode = initializeNode(value);
    Node *p = L.p_head;
    int i = 1;
    if (index < 1)
        return;
    if (index == 1)
    {
        addElement(L, value);
        return;
    }
    while (i < index - 1 && p->p_next != NULL)
    {
        p = p->p_next;
        i++;
    }
    if (index - 1 > i)
        return;
    newNode->p_next = p->p_next;
    p->p_next = newNode;
    if (p->p_next == newNode && newNode->p_next == NULL)
        L.p_tail = newNode;
}
// Xoa node vi tri thu x khoi danh sach
void removeElementIndex(List &L, int index)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;
    if (index < 1)
        return;
    if (index == 1)
    {
        removeElement(L);
        return;
    }
    Node *p = L.p_head;
    int i = 1;
    while (i < index - 1 && p->p_next->p_next != NULL)
    {
        p = p->p_next;
        i++;
    }
    if (index - 1 > i)
        return;
    if (index - 1 == i)
        L.p_tail = p;
    Node *q = p->p_next;
    p->p_next = p->p_next->p_next;
    deleteNode(q);
}
// Xoa cac node trung nhau ma van giu lai cac node co gia tri rieng biet
void removeDuplicateElements(List &L)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;
    int count = 1;
    int temp = 1;
    for (Node *p = L.p_head; p->p_next != NULL; p = p->p_next)
    {
        for (Node *q = p->p_next; q != NULL; q = q->p_next)
        {
            count++;
            if (p->key == q->key)
            {
                Node *tmp = p;
                int idx = 1;
                while (idx < count - 1)
                {
                    tmp = tmp->p_next;
                    idx++;
                }
                cout << tmp->p_next->key << endl;
            }
        }
        count = ++temp;
    }
}
// In ra màn hình danh sách liên kết
void printList(List L)
{
    for (Node *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
}
// In phan tu chinh giua cua danh sach lien ket
void printMidKey(List L)
{
    if (L.p_head == NULL || L.p_head->p_next == NULL)
        return;
    Node *p1 = L.p_head;
    Node *p2 = L.p_head;
    while (p2 != NULL)
    {
        if (p2->p_next == NULL)
            p2 = p2->p_next;
        else
        {
            p2 = p2->p_next->p_next;
            p1 = p1->p_next;
        }
    }
    cout << p1->key << endl;
}

Node *daoNguocDanhSach(Node *head)
{
    if (head == NULL || head->p_next == NULL)
        return head;
    Node *dao = daoNguocDanhSach(head->p_next);
    head->p_next->p_next = head;
    head->p_next = NULL;
    return dao;
}
// Dao nguoc danh sach lien ket
List reverseLinked_List(List L)
{
    Node *cuoi = L.p_head;
    Node *p = daoNguocDanhSach(L.p_head);
    L.p_head = p;
    L.p_tail = cuoi;
    return L;
}
