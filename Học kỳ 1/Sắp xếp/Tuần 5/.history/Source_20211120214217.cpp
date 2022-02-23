#include "Header.h"
using namespace std;

// Tra ve phan tu lon nhat cua mang
int getMax(vector<int> arr)
{
    int n = arr.size();
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

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

// Sap xep tron: Merge sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int size = right - left + 1;
    int tmp[size];
    for (int k = 0; k < size; k++)
    {
        if (i <= mid && (j > right || arr[i] < arr[j]))
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
    }

    for (int k = 0; k < size; k++)
        arr[left + k] = tmp[k];
}

// Sap xep nhanh: Quick sort
void quickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int x = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// Sap xep dem: Couting sort (cac so 1 chu so)
void countingSort(vector<int> &arr, int place)
{
    const int max = 10;
    int size = arr.size();
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(arr[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

// Sap xep theo co so: Radix sort
void radixSort(vector<int> &arr)
{
    int size = arr.size();
    int max = getMax(arr);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, place);
}
// In mang
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}