#include <iostream>
using namespace std;

struct NODE
{
    int key;
    int height;
    NODE *left;
    NODE *right;
};
typedef struct NODE *AVL;

AVL rightRotate(AVL A);