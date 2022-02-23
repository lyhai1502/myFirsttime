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

// Sap xep dem: Couting sort
// void countingSort(vector<int> &arr)
// {
//     int result[arr.size()];
//     int max = arr[0];
//     int min = arr[0];
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (arr[i] > max)
//             max = arr[i];
//         else if (arr[i] < min)
//             min = arr[i];
//     }
//     int countArray[max - min + 1];
//     for (int i = 0; i < max - min + 1; i++)
//         countArray[i] = 0;
//     for (int i = 0; i < arr.size(); i++)
//         countArray[arr[i] - min]++;
//     for (int i = 1; i < max - min + 1; i++)
//         countArray[i] += countArray[i - 1];
//     for (int i = 0; i < arr.size(); i++)
//     {
//         result[countArray[arr[i] - min] - 1] = arr[i];
//         countArray[arr[i] - min]--;
//     }
//     for (int i = 0; i < arr.size(); i++)
//         arr[i] = result[i];
// }
void countingSort(vector<int> &array, int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}
// Sap xep theo co so: Radix sort
void radixSort(vector<int> &arr)
{
    int n = arr.size();
    int i, b[5], m = arr[0], exp = 1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > m)
            m = arr[i];
    }
    while (m / exp > 0)
    {
        int bucket[10] = {0};
        for (i = 0; i < n; i++)
            bucket[arr[i] / exp % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; i--)
            b[--bucket[arr[i] / exp % 10]] = arr[i];
        for (i = 0; i < n; i++)
            arr[i] = b[i];
        exp *= 10;
    }
}
// In mang
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}