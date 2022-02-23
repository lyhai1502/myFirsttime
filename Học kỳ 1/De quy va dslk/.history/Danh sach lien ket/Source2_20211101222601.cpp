#include <iostream>
using namespace std;
struct dNode
{
    int key;
    dNode *p_prev;
    dNode *p_next;
};
struct dList
{
    dNode *p_head;
    dNode *p_tail;
};

// Khoi tao mot node co gia tri cho truoc
dNode *initialize_dNode(int key)
{
    dNode *newdNode = new dNode;
    newdNode->key = key;
    newdNode->p_prev = NULL;
    newdNode->p_next = NULL;
    return newdNode;
}
// Khoi tao danh sach lien ket doi tu mot dNode cho truoc
void initialize_dList(dList &L, dNode *&head)
{
    L.p_head = L.p_tail = NULL;
    L.p_head = head;
    L.p_tail = head;
}
// Them mot phan tu vao dau danh sach lien ket doi
void addElement_dNode(dList &L, int value)
{
    dNode *newdNode = initialize_dNode(value);
    newdNode->p_next = L.p_head;
    L.p_head->p_prev = newdNode;
    L.p_head = newdNode;
}

// In cac phan tu cua danh sach lien ket doi
void print_dNode(dList L)
{
    for (dNode *p = L.p_head; p != NULL; p = p->p_next)
        cout << p->key << " ";
}
int main()
{
    dList ls;
    dNode *p = initialize_dNode(66);
    initialize_dList(ls, p);
    print_dNode(ls);
    if (ls.p_head->p_next == NULL)
        cout << 1;
    return 0;
}