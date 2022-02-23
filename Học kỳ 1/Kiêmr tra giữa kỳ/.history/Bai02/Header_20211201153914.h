#ifndef __HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr1, arr2;
int n;

// Ham chuc nang
int Bai02(vector<int> arr1, vector<int> arr2, int n);

// Xay dung MinHeap tu nut goc co index = i
void minHeapify(vector<int> &arr, int i);

// Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
void extractMin(vector<int> &arr);

// Xay dung MaxHeap tu nut goc co index = i
void maxHeapify(vector<int> &arr, int i);

// Tra ve phan tu lon nhat (nut goc), xoa nut goc va heapify lai nut goc moi
void extractMax(vector<int> &arr);

// Input du lieu
void inputArray(vector<int> &arr, int n);

// In mang
void printArray(vector<int> arr);

#endif // __HEADER_H__