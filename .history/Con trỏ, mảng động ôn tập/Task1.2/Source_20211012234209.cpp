#include "Header.h"

using namespace std;

int *initialize(int maxSize) //khoi tao mang dong
{
    int *array = new int[maxSize];
    return array;
}
int *growSize(int *array, int size, int &maxSize)
{
    maxSize = maxSize * 2;
    int *newArray = new int[maxSize];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    if (array != NULL)
        delete[] array;
    return newArray;
}
void addElement(int *&array, int data, int &size, int &maxSize)
{
    if (size + 1 > maxSize)
        array = growSize(array, size, maxSize);
    size++;
    array[size - 1] = data;
}

void swapElement(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void addElementAtIndex(int *&array, int index, int data, int &size, int &maxSize)
{
    if (index + 1 > size)
        return;
    addElement(array, data, size, maxSize);

    for (int i = size - 1; i >= index; i--)
    {
        swapElement(&array[i], &array[i - 1]);
    }
}
void removeElement(int *&array, int &size, int &maxSize)
{
    if (array == NULL)
        return;
    array[size - 1] = 0;
    size--;
}
void removeElementAtIndex(int *array, int index, int &size, int maxSize)
{
    if (array == NULL || index > size)
        return;
    for (int i = index - 1; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    removeElement(array, size, maxSize);
}
int *shrinkArray(int *array, int size, int &maxSize)
{
    int *newArray = new int[size];
    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    maxSize = size;
    if (array != NULL)
        delete[] array;
    return newArray;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}
int maxElement(int *array, int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (max < array[i])
            max = array[i];
    return max;
}
int searchElement(int *array, int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
            return array[i];
        return 0;
    }
}
int *merge2Arrays(int *a, int *b, int na, int nb)
{
    int *newArray = initialize(na + nb);
    int index = 0;
    int *p1 = a;
    int *p2 = b;
    while (p1 != &a[na] || p2 != &b[nb])
    {
        if (p1 == &a[na] && p2 != &b[nb])
        {
            while (index < na + nb)
            {
                newArray[index++] = *p2;
                p2 = p2 + 1;
            }
        }
        else if (p1 != &a[na] && p2 == &b[nb])
        {
            while (index < na + nb)
            {
                newArray[index++] = *p1;
                p1 = p1 + 1;
            }
        }
        else
        {
            if (*p1 < *p2)
            {
                newArray[index++] = *p1;
                p1 = p1 + 1;
            }
            else
            {
                newArray[index++] = *p2;
                p2 = p2 + 1;
            }
        }
    }
    delete p1;
    delete p2;
    return newArray;
}
