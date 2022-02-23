#include "LienKetDon_Source.cpp"
using namespace std;

int main()
{
    // BAI 1
    List ls;
    Node *newNode = initializeNode(9);
    initializeList(ls, newNode);
    addElement(ls, 7);
    addElementIndex(ls, 2, 6);
    addElementIndex(ls, 1, 4);
    addElement(ls, -1);
    addElement(ls, 1);

    printList(ls);
    return 0;
}
