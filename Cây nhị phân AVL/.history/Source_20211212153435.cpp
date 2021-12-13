#include "Header.h"

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *B = A->left;
    NODE *C = B->right;
    A->left = C;
    B->right = A;
    return B;
}