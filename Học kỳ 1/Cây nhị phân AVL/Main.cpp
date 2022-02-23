#include "Source.cpp"

int main()
{
    NODE *tree = NULL;

    // Them cac node moi vao cay (vua insert vua can bang cay)
    insert(tree, 4);
    insert(tree, 7);
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 3);
    insert(tree, 5);
    insert(tree, 10);

    // Cac phep duyet
    cout << "Duyet NLR: ";
    NLR(tree);
    cout << "\nDuyet LNR: ";
    LNR(tree);
    cout << "\nDuyet NLR: ";
    NLR(tree);
    cout << "\nDuyet theo tang: ";
    levelOrder(tree);

    // Tim va tra ve mot Node co ton tai trong cay
    int x1 = 11; // Gia tri can tim
    if (search(tree, x1))
        cout << "\nCo tim thay gia tri " << x1 << " trong cay!";
    else
        cout << "\nKhong tim thay gia tri " << x1 << " trong cay!";

    // Kiem tra phai la cay AVL
    if (isAVL(tree))
        cout << "\nTREE la cay AVL!";
    else
        cout << "\nTREE khong phai cay AVL!";

    // Dem so luong cac nut
    int x2 = 6; // Gia tri so sanh
    cout << "\nSo luong nut nho hon " << x2 << " la " << countLesser(tree, x2);
    cout << "\nSo luong nut lon hon " << x2 << " la " << countGreater(tree, x2);
    cout << "\nSo luong nut la cua cay la " << countLeaves(tree);

    // Xoa mot nut
    int del = 7; // Gia tri can xoa
    remove(tree, del);
    cout << "\nSau khi xoa nut " << del << ", cay tro thanh: ";
    NLR(tree); // Duyet truoc

    // Xoa toan bo cay
    if (removeTree(tree))
        cout << "\nXoa cay thanh cong!";
    else
        cout << "\nXoa cay that bai!";

    return 0;
}