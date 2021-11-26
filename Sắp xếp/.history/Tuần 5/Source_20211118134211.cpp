#include "Header.h"
using namespace std;

// Sap xep vun dong: Heap sort
void heapSort(vector<int> arr)
{
}
void max_Heapify(vector<int> arr, int root)
{
    int n = arr.size();
    int large = root;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[large])
        large = left;
    if (right < n && arr[right] > arr[large])
        large = right;
    if (large != root)
    {
        swap(arr[root], arr[large]);
        max_Heapify(arr, heapify);
    }
}
// In mang
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}