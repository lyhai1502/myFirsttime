#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *p_next;
};
struct stack_Node
{
    Node *head;
};
Node *createNode(int value);
{
    Node *newNode = new Node;
}