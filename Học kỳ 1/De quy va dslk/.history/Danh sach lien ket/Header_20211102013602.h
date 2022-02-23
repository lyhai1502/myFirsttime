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