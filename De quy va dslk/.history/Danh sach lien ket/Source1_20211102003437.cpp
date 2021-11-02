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
    Node *p = L.p_head;
    L.p_head = L.p_head->p_next;
    deleteNode(p);
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
    if (p->p_next == newNode && newNode->p_next == NULL)
        L.p_tail = newNode;
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
    deleteNode(q);
}
// Xoa cac node trung nhau ma van giu lai cac node co gia tri rieng biet
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
                Node *tmp = p;
                int idx = 1;
                while (idx < count - 1)
                {
                    tmp = tmp->p_next;
                    idx++;
                }
                removeElementIndex(L, count);
                q = tmp;
                cout << q->key << endl;
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
    Node *head = initializeNode(4);
    initializeList(ls, head);
    addElement(ls, 5);
    addElement(ls, 7);
    addElementIndex(ls, 1, 7);
    addElement(ls, 99);
    addElementIndex(ls, 2, -6);
    addElement(ls, 5);
    //addElement(ls, 5);
    //addElement(ls, 5);
    //addElement(ls, 5);
    printList(ls);
    cout << endl;
    removeDuplicateElements(ls);
    printList(ls);
    return 0;
}