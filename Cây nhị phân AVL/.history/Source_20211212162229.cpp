#include "Header.h"

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *X = A->left;
    NODE *Y = X->right;
    A->left = Y;
    X->right = A;

    // Cap nhat chieu cao
    A->height = max(A->left->height, A->right->height) + 1;
    X->height = max(X->left->height, X->right->height) + 1;

    return X;
}

NODE *leftRotate(NODE *B)
{
    NODE *X = B->right;
    NODE *Y = X->left;
    B->right = Y;
    X->left = B;

    // Cap nhat chieu cao
    B->height = max(B->left->height, B->right->height) + 1;
    X->height = max(X->left->height, X->right->height) + 1;

    return X;
}

// Xu ly can bang
node *updateTreeAvl(node *t)
{
    if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1)
    {
        if (treeLevel(t->left) > treeLevel(t->right))
        {
            node *p = t->left;
            if (treeLevel(p->left) >= treeLevel(p->right))
            {
                t = turnRight(t);
            }
            else
            {
                t->left = turnLeft(t->left);
                t = turnRight(t);
            }
        }
        else
        {
            node *p = t->right;
            if (treeLevel(p->right) >= treeLevel(p->left))
            {
                t = turnLeft(t);
            }
            else
            {
                t->right = turnRight(t->right);
                t = turnLeft(t);
            }
        }
    }
    if (t->left != NULL)
        t->left = updateTreeAvl(t->left);
    if (t->right != NULL)
        t->right = updateTreeAvl(t->right);
    return t;
}
