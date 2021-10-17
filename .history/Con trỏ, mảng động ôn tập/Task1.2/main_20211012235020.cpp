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
    addElementAtIndex(array, 5, 999, size, maxSize);
    removeElement(array, size, maxSize);
    removeElementAtIndex(array, 5, size, maxSize);
    //thu nho kich thuoc mang dong
    array = shrinkArray(array, size, maxSize);
    //in cac phan tu
    printArray(array, size);
    // phan tu lon nhat trong mang
    int maxValue = maxElement(array, size);
    // tim kiem phan tu co gia tri xac dinh
    int key = 12;
    int xacdinhValue = searchElement(array, key, size);

    //merge2Arrays(array1, array2, size1, size2);
    if (array != NULL)
        delete[] array;
    return 0;
}