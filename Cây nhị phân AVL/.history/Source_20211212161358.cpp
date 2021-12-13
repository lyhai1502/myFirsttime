#include "Header.h"

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *B = A->left;
    NODE *C = B->right;
    A->left = C;
    B->right = A;

    // Cap nhat chieu cao
    A->height = max(A->left, A->right);
    B->height = max(B->left, B->right);

    return B;
}

//