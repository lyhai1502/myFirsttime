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
Node *initialize(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL; // node vừa tạo chưa thêm vào danh sách nên chưa liên kết với phần tử nào cả nên phần liên kết gán bằng NULL
    return node;
}
