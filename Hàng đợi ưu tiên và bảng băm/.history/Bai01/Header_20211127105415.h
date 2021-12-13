#ifndef __HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <vector>
using namespace std;

// Xay dung MinHeap tu nut goc co index = i
void minHeapify(vector<int> &arr, int i);

// MinHeapify nguoc tu nut co index = i
void reverseHeapify(vector<int> &arr, int i);

// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr);

// Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
int extractMin(vector<int> &arr);

// Them phan tu moi vao hang doi uu tien, heapify lai nut do
void insert(vector<int> &arr, int data);

// In mang
void printArray(vector<int> arr);

#endif // __HEADER_H__