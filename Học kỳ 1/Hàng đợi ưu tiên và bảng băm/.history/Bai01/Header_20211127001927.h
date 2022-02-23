#ifndef __HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <vector>
using namespace std;

// Xay dung MinHeap tu nut goc co index = i
void Heapify(vector<int> &arr, int i);

// Xay dung MinHeap hoan chinh
void minHeapify(vector<int> &arr);

// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr);

// Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
int extractMin(vector<int> &arr);

// Them phan tu moi vao hang doi uu tien, heapify lai nut do
void insert(vector<int> &arr, int data);

// In mang
void printArray(vector<int> arr);

#endif // __HEADER_H__