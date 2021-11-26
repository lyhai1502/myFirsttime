#include "Header.h"
using namespace std;

// Sap xep vun dong: Heap sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}
void maxHeapify(vector<int> &arr, int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[large])
        large = left;
    if (right < n && arr[right] > arr[large])
        large = right;
    if (large != i)
    {
        swap(arr[i], arr[large]);
        maxHeapify(arr, n, large);
    }
}
// In mang
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}