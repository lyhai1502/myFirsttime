#include <iostream>
using namespace std;

int *initialize(int maxSize); //khoi tao mang dong

//tham phan tu moi vao sau mang dong
void addElement(int *&array, int data, int &size, int &maxSize);

//them phan tu tai 1 vi tri xac dinh
void addElementAtIndex(int *&array, int index, int data, int &size, int &maxSize);

//xoa phan tu cuoi cung cua mang dong
void removeElement(int *&array, int &size, int &maxSize);

//xoa phan tu tai 1 vi tri cua mang
void removeElementAtIndex(int *array, int index, int &size, int maxSize);

//thu nho kich thuoc mang dong
int *shrinkArray(int *array, int size, int &maxSize);

//in cac phan tu trong mang
void printArray(int *array, int size);

//tim phan tu lon nhat trong mang
int maxElement(int *array, int size);

// tim kiem phan tu co gia tru xac dinh trong mang dong
int searchElement(int *array, int key, int size);

//noi 2 mang dong tang dan
int *merge2Arrays(int *a, int *b, int na, int nb);