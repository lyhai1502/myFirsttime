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
    return 0;
}