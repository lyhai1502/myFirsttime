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
    Node *p = L.p_head;
    L.p_head = L.p_head->p_next;
    p->p_next = NULL;
    delete p;
    p = NULL;
}
// Xoa tat cac cac node khoi danh sach
void removeAllElement(List &L)
{
    if (L.p_head == L.p_tail && L.p_head == NULL)
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
}
// Xoa node vi tri thu x khoi danh sach
void removeElementIndex(List &L, int index)
{
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
    q->p_next = NULL;
    delete q;
    q = NULL;
}
void removeDuplicateElements(List &L)
{
    int count = 1;
    int temp = 1;
    for (Node *p = L.p_head; p->p_next != NULL; p = p->p_next)
    {
        for (Node *q = p->p_next; q != NULL; q = q->p_next)
        {
            count++;
            if (p->key == q->key)
            {
                Node *q_temp = p;
                while (q_temp->p_next != q && q_temp != NULL)
                    q_temp = q_temp->p_next;
                removeElementIndex(L, count);
                q = q_temp;
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
    Node *p = L.p_head;
    Node *q = L.p_tail;
}
int main()
{
    List ls;
    Node *head = initializeNode(5);
    initializeList(ls, head);
    addElement(ls, 4);
    addElement(ls, 3);
    addElementIndex(ls, 1, 99);
    addElement(ls, 99);
    addElement(ls, 5);
    addElementIndex(ls, 8, -6);
    printList(ls);
    return 0;
}