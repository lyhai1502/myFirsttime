#include <iostream>

using namespace std;

struct NODE
{
    int key;
    int height;
    NODE *left;
    NODE *right;
};

int height(NODE *root)
{
    if (!root)
        return 0;
    return root->height;
}

// Lay so lon nhat trong 2 so
int findMax(int a, int b)
{
    return a > b ? a : b;
}

// He so can bang cua cay
int balanceFactor(NODE *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

// Xoay phai tai mot nut
NODE *rightRotate(NODE *A)
{
    NODE *X = A->left;
    NODE *Y = X->right;
    X->right = A;
    A->left = Y;

    // Cap nhat chieu cao
    A->height = findMax(height(A->left), height(A->right)) + 1;
    X->height = findMax(height(X->left), height(X->right)) + 1;

    return X;
}

NODE *leftRotate(NODE *B)
{
    NODE *X = B->right;
    NODE *Y = X->left;
    X->left = B;
    B->right = Y;

    // Cap nhat chieu cao
    B->height = findMax(height(B->left), height(B->right)) + 1;
    X->height = findMax(height(X->left), height(X->right)) + 1;

    return X;
}

// Khoi tao mot nut, chieu cao 1
NODE *createNode(int x)
{
    NODE *newNode = new NODE;
    if (!newNode)
    {
        cout << "Khong du bo nho!";
        exit(0);
    }
    newNode->key = x;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Update cay can bang moi khi cay mat can bang
NODE *updateAvlTree(NODE *root, int x)
{
    int balance = balanceFactor(root);
    if (balance > 1 && x < root->left->key)
        return rightRotate(root);
    if (balance < -1 && x > root->right->key)
        return leftRotate(root);
    if (balance > 1 && x > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && x < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// Tim node co gia tri nho nhat
NODE *findMinValue(NODE *root)
{
    NODE *cur = root;
    while (cur->left)
        cur = cur->left;
    return cur;
}

// Them mot nut moi
void insert(NODE *&root, int x)
{
    if (!root)
    {
        root = createNode(x);
        return;
    }
    if (x < root->key)
        insert(root->left, x);
    else if (x > root->key)
        insert(root->right, x);
    else
    {
        cout << "Gia tri vua them da bi trung!\n";
        return;
    }

    // Cap nhat chieu cao moi cac Node trong cay
    root->height = findMax(height(root->left), height(root->right)) + 1;

    // Cap nhat he so can bang va can bang cay
    root = updateAvlTree(root, x);
    return;
}
// Tim va tra ve mot node cho truoc hoac tim node nho gan nhat
NODE *search(NODE *root, int x)
{
    if (root->left == NULL && root->right == NULL)
        return root;
    else if (root->right != NULL && root->right->left == NULL && root->left == NULL && x > root->key && x != root->right->key)
        return root;
    if (root->key == x)
        return root; // Tim thay
    else if (x < root->key)
        return search(root->left, x);
    else
        return search(root->right, x);
}

long long function2(NODE *tree, int n, int giaTien)
{
    NODE *min = findMinValue(tree);
    int minValue = min->key;
    if (giaTien < minValue)
        return -1;
    else if (giaTien == minValue)
        return giaTien;
    else
    {
        NODE *timThay = search(tree, giaTien);
        return timThay->key;
    }
}

int main()
{
    // Bo cmt cac dong duoi day neu ban muon giao tiep chuong trinh thong qua file

    // if (fopen("./input1.txt", "r")) {
    //     freopen("./input1.txt", "r", stdin);
    //     freopen("./output1.txt", "w", stdout);
    // }
    // freopen_s("input.txt", "r", stdin);
    int n;
    cin >> n;
    NODE *tree = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(tree, x);
    }
    int giaTien;
    cin >> giaTien;
    cout << function2(tree, n, giaTien);

    // Luu y rang ban se phai cmt dong duoi day lai khi nop bai, neu khong se bi sai output.
    // cerr << "Execution time: " << ((double) (end - start)) / CLOCKS_PER_SEC << "s";
    return 0;
}