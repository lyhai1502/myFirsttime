#include <iostream>
#include <vector>
using namespace std;

// Tra ve phan tu lon nhat cua mang
int getMax(vector<int> arr);

// Sap xep vun dong: heap sort
void heapSort(vector<int> &arr);
void maxHeapify(vector<int> &arr, int n, int i);

// Sap xep tron: merge sort
void mergeSort(vector<int> &arr, int left, int right);
void merge(vector<int> &arr, int left, int mid, int right);

// Sap xep nhanh: quick sort
void quickSort(vector<int> &arr, int left, int right);

// Sap xep dem: couting sort
void countingSort(vector<int> &arr, int place);

// Sap xep theo co so: radix sort
void radixSort(vector<int> &arr);