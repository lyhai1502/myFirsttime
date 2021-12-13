#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *p_next;
};

// Khoi tao mot node co gia tri cho truoc
Node *initializeNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->p_next = NULL;
    return node;
}