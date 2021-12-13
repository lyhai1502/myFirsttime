#include "Source.cpp"

int main()
{
    NODE *tree = NULL;

    // Them cac node moi vao cay
    insert(tree, 4);
    insert(tree, 5);
    insert(tree, 2);
    insert(tree, 4);
    insert(tree, 3);
    insert(tree, 99);

    levelOrder(tree);
    remove(tree, 0);
    cout << endl;
    levelOrder(tree);
    return 0;
}