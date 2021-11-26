#include "Header.h"
using namespace std;

// Hoan doi 2 phan tu
// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr, int n)
{
    if (n == 0)
        return -1;
    else
        return arr[0];
}

// int extractMin(vector<int> &arr)
// {
//     int n = arr.size();
//     if (n == 0)
//         return -1;
//     int ans = arr[0];
//     swap(arr[0], arr[n - 1]);
//     arr.pop_back();
//     minHeapify(arr, arr.size(), 0);
//     return ans;
// }
// Xay dung MinHeap
void minHeapify(vector<int> &arr, int i)
{
    int n = arr.size();
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[min])
        min = l;
    if (r < n && arr[r] < arr[min])
        min = r;
    if (min != i)
    {
        swap(arr[i], arr[min]);
        minHeapify(arr, min);
    }
}
void allMinHeapify(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, i);
}
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(2);
    printArray(arr);
    allMinHeapify(arr);
    printArray(arr);
    return 0;
}