#include <iostream>
#include <vector>
using namespace std;

// Xay dung MinHeap tu nut goc co index = i
void Heapify(vector<int> &arr, int i);

// Xay dung MinHeap hoan chinh
void minHeapify(vector<int> &arr);

// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr, int n);