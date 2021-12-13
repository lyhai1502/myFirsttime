#include "Source.cpp"

int main()
{
    Node *root = NULL;

    // Them nut moi
    insert(root, 11);
    insert(root, 6);
    insert(root, 19);
    insert(root, 4);
    insert(root, 8);
    insert(root, 5);
    insert(root, 10);
    insert(root, 17);
    insert(root, 43);
    insert(root, 49);
    insert(root, 31);

    // Cac phep duyet
    cout << "Duyet NLR: ";
    NLR(root);
    cout << "\nDuyet LNR: ";
    LNR(root);
    cout << "\nDuyet NLR: ";
    NLR(root);
    cout << "\nDuyet theo tang: ";
    levelOrder(root);

    // Chieu cao va so luong nut cua cay
    cout << "\nChieu cao cua cay: " << height(root);
    cout << "\nSo luong nut cua cay: " << countNode(root);

    // Tim va tra ve nut co gia tri
    int x1 = 49;
    Node *X = search(root, x1);
    cout << (X ? "\nCo gia tri " : "\nKhong co gia tri ");
    cout << x1 << " trong cay";

    // Chieu cao tai nut co gia tri
    int x2 = 19;
    cout << "\nChieu cao tai nut " << x2 << " la: " << heightNode(root, x2);

    // Kiem tra co phai cay nhi phan
    cout << (isBST(root) ? "\nROOT la cay nhi phan tim kiem!" : "\nROOT khong phai cay nhi phan tim kiem!");

    // Xoa mot nut
    int del = 19;
    remove(root, del);
    cout << "\nSau khi xoa nut " << del << ", cay con lai: ";
    NLR(root);
    cout << "(NLR)";

    // Xoa toan bo cay
    cout << "\nXoa toan bo cay: ";
    removeTree(root);
    cout << (root ? "Khong thanh cong!" : "Thanh cong!");

    return 0;
}