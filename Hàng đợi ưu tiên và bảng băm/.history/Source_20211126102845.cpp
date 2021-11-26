#include "Header.h"
using namespace std;

void getMin(vector<int> arr, int n)
{
    if (n == 0)
        return NULL;
    else
        return arr[0];
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