#include "Source.cpp"
using namespace std;

int main()
{
    cout << "Nhap so phan tu mang: ";
    int size;
    cin >> size;
    int maxSize = size + 1;
    int *array = initialize(size);
    addElement(array, 9999, size, maxSize);
    addElementAtIndex(array, 2, 999, size, maxSize);
    removeElement(array, size, maxSize);
    removeElementAtIndex(array, 2, size, maxSize);
    cout << maxElement(array, size);
    printArray(array, 13);

    if (array != NULL)
        delete[] array;
    return 0;
}