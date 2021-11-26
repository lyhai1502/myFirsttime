#include "LienKetDon_Source.cpp"
using namespace std;

int main()
{
    List ls;
    Node *newNode = initializeNode(9);
    initializeList(ls, newNode);
    addElement(ls, 6);
    addElementIndex(ls, 2, 2);
    addElementIndex(ls, 1, 999);
    addElement(ls, -1);
    addElement(ls, -3);
    addElement(ls, 1);
    addElement(ls, 5);
    addElementIndex(ls, 4, 5);
    printList(ls);
    reverseFromLeftToRight(ls, 2, 6);
    // //BAI 1: Tim phan tu chinh giua cua danh sach lien ket
    // cout << "\nPhan tu chinh giua cua danh sach la: ";
    // printMidKey(ls);

    // // BAI 2: Dao nguoc danh sach lien ket
    // cout << "Reverse Linked-List: ";
    // ls = reverseLinked_List(ls);
    // printList(ls);

    return 0;
}