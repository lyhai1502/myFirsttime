#include "Header.h"
using namespace std;

// Tra ve phan tu nho nhat (nut goc) cua hang doi uu tien
int getMin(vector<int> arr, int n)
{
    if (n == 0)
        return NULL;
    else
        return arr[0];
}

int extractMin(vector<int> &arr, int n)
{
    if (n == 0)
        return NULL;
    int ans = arr[0];
    swap(arr[0], arr[n - 1]);
    arr.pop_back(arr);
    minHeapify(arr, arr.size(), 0);
    return ans;
}
// Xay dung MinHeap
void minHeapify(vector<int> &arr, int n, int i)
{
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
        minHeapify(arr, n, min);
    }
}

int main();
{
    vector<int> arr;
    arr
}