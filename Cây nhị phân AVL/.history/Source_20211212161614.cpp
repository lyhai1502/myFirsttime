#include "Header.h"

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *X = A->left;
    NODE *Y = X->right;
    A->left = X;
    Y->right = A;

    // Cap nhat chieu cao
    A->height = max(A->left->height, A->right->height) + 1;
    B->height = max(B->left->height, B->right->height) + 1;

    return B;
}

NODE *leftRotate(NODE *B)
{
}
//