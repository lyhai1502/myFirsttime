#include <iostream>
#include <vector>
using namespace std;

// Sap xep vun dong: heap sort
void heap_Sort(vector<int> arr);
void Max_Heapify(vector <int> arr, int n, int i);
// Sap xep tron: merge sort
void mergeSort(vector<int> arr);

// Sap xep nhanh: quick sort
void quickSort(vector<int> arr);

// Sap xep dem: couting sort
void countingSort(vector<int> arr);

// Sap xep theo co so: radix sort
void radixSort(vector<int> arr);