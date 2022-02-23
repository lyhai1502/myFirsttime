#pragma once
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

// Ham thuc hien yeu cau bai 01
void Bai01(List &L, int n);

// Khoi tao mot node co gia tri cho truoc
Node *initializeNode(int key);

// Khoi tao danh sach lien ket tu mot node cho truoc
List initializeList();

// Them mot phan tu vao cuoi danh sach lien ket
void addElement(List &L, int value);

// In ra man hinh
void printList(List L);

// Nhap du lieu dau vao
void inputLinkedList(List &L, int &n);

// Tra ve node truoc cua node do
Node *pre_Node(List L, Node *node);
