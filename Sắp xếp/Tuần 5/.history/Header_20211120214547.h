#include <iostream>
#include <vector>
using namespace std;

// Tra ve phan tu lon nhat cua mang
int getMax(vector<int> arr);

// Sap xep vun dong: Heap sort
void heapSort(vector<int> &arr);
// Xay dung maxHeap
void maxHeapify(vector<int> &arr, int n, int i);

// Sap xep tron: Merge sort
void mergeSort(vector<int> &arr, int left, int right);
// Gop 2 mang arr[left->mid] va arr[mid+1 -> right] voi nhau
void merge(vector<int> &arr, int left, int mid, int right);

// Sap xep nhanh: Quick sort
void quickSort(vector<int> &arr, int left, int right);

// Sap xep dem: Couting sort (cac so co 1 chu so)
void countingSort(vector<int> &arr, int place);

// Sap xep theo co so: Radix sort
void radixSort(vector<int> &arr);