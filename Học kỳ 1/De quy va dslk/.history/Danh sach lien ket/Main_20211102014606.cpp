#include "LienKetDon_Source.cpp"
using namespace std;

int main()
{
    List ls;
    Node *newNode = initializeNode(9);
    initializeList(ls, newNode);
    addElement(ls, 6);
    addElementIndex(ls, 2, 2);
    addElementIndex(ls, 1, 4);
    addElement(ls, -1);
    addElement(ls, 1);
    addElementIndex(ls, 4, 999);

    // BAI 1: Tim phan tu chinh giua cua danh sach lien ket
    printMidKey(ls);

    printList(ls);
    return 0;
}
