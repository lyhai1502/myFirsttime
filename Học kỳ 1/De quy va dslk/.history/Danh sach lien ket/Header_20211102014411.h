#include <iostream>
using namespace std;

// ---------------- CAI DAT DANH SACH LIEN KET DON --------------
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
// Xoa vinh vien con tro Node
void deleteNode(Node *&p);

// Khoi tao mot node co gia tri cho truoc
Node *initializeNode(int key);

// Khoi tao danh sach lien ket tu mot node cho truoc
void initializeList(List &L, Node *&head);

// Them mot phan tu vao dau danh sach lien ket
void addElement(List &L, int value);

// Xoa node dau tien khoi danh sach
void removeElement(List &L);

// Xoa tat cac cac node khoi danh sach
void removeAllElement(List &L);

// Them 1 phan tu vao vi tri thu x của danh sach lien ket
void addElementIndex(List &L, int index, int value);

// Xoa node vi tri thu x khoi danh sach
void removeElementIndex(List &L, int index);

// Xoa cac node trung nhau ma van giu lai cac node co gia tri rieng biet
void removeDuplicateElements(List &L);

// In ra màn hình danh sách liên kết
void printList(List L);

// In phan tu chinh giua cua danh sach lien ket
void printMidKey(List L);

Node *daoNguocDanhSach(Node *head);

// Dao nguoc danh sach lien ket
List reverseLinked_List(List L);

// ---------- CAI DẢT CAC HAM DANH SACH LIEN KET DOI -------------
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
void delete_dNode(dNode *&dnode);

// Khoi tao mot node co gia tri cho truoc
dNode *initialize_dNode(int key);

// Khoi tao danh sach lien ket doi tu mot dNode cho truoc
void initialize_dList(dList &L, dNode *&head);

// Them mot phan tu vao dau danh sach lien ket doi
void addElement_dList(dList &L, int value);

// Xoa dNode dau tien cua danh sach
void removeElement_dList(dList &L);

// Xoa tat ca cac Node cua danh sach
void removeAllElement_dList(dList &L);

// In cac phan tu cua danh sach lien ket doi
void print_dList(dList L);

// Them 1 phan tu vao vi tri thu x cua danh sach
void addElementIndex_dList(dList &L, int index, int value);

// Xoa cac node trung nhau ma giu lai cac node co gia tri rieng biet
void removeDuplicateElements_dList(dList &L);
