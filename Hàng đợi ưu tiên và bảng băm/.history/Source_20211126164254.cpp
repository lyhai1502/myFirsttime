#include "Header.h"
using namespace std;

// Xay dung MinHeap tu nut goc co index = i
void Heapify(vector<int> &arr, int i)
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
        Heapify(arr, min);
    }
}
// Xay dung MinHeap hoan chinh
void minHeapify(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, i);
}

// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr, int n)
{
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
    minHeapify(arr);
    return ans;
}

// Them phan tu moi vao hang doi uu tien, heapify lai nut do
void insert(vector<int> &arr, int data)
{
    int n = arr.size();
    arr.push_back(data);
    minHeapify(arr);
}

// In mang
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
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(7);
    printArray(arr);
    minHeapify(arr);
    cout << extractMin(arr) << endl;
    arr.push_back(4);
    printArray(arr);
    cout << extractMin(arr) << endl;
    cout << extractMin(arr) << endl;
    cout << extractMin(arr);
    return 0;
}