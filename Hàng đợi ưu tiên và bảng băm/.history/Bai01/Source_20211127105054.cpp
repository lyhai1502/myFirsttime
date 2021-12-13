#include "Header.h"
using namespace std;

// Xay dung MinHeap tu nut goc co index = i
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

// MinHeapify nguoc tu nut co index = i
void reverseHeapify(vector<int> &arr, int i)
{
    int n = arr.size();
    int index;
    if (i % 2 == 0)
        index = (i - 2) / 2;
    else
        index = (i - 1) / 2;
    if (index >= 0 && arr[i] < arr[index])
    {
        swap(arr[i], arr[index]);
        reverseHeapify(arr, index);
    }
}

// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    else
        return arr[0];
}

// Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
int extractMin(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;
    int ans = arr[0];
    swap(arr[0], arr[n - 1]);
    arr.pop_back();
    minHeapify(arr, 0);
    return ans;
}

// Them phan tu moi vao hang doi uu tien, heapify lai nut do
void insert(vector<int> &arr, int data)
{
    arr.push_back(data);
    reverseHeapify(arr, arr.size() - 1);
}

// In mang
void printArray(vector<int> arr)
{
    if (!arr.size())
        cout << "Hang doi khong co du lieu!";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}