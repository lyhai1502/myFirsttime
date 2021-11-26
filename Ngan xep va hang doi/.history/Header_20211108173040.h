#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
struct stackNode
{
    Node *head;
};

struct queueNode
{
    Node *head;
    Node *tail;
};