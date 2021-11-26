#include "Header.h"
using namespace std;

// Sap xep vun dong: Heap sort
void heapSort(vector<int> arr)
{
}
void heapify(vector<int> arr, int i)
{
    int n = arr.size();
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n &&)
}
// In mang
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}