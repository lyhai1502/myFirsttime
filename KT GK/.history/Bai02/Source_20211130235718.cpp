#include <iostream>
#include <vector>
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

// Xay dung MaxHeap tu nut goc co index = i
void maxHeapify(vector<int> &arr, int i)
{
    int n = arr.size();
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;
    if (max != i)
    {
        swap(arr[i], arr[max]);
        maxHeapify(arr, max);
    }
}

// Tra ve phan tu nho nhat (nut goc), xoa nut goc va heapify lai nut goc moi
void extractMin(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return;
    swap(arr[0], arr[n - 1]);
    arr.pop_back();
    minHeapify(arr, 0);
}

// Tra ve phan tu lon nhat (nut goc), xoa nut goc va heapify lai nut goc moi
void extractMax(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return;
    swap(arr[0], arr[n - 1]);
    arr.pop_back();
    maxHeapify(arr, 0);
}

int function02(vector<int> &arr1, vector<int> &arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr1[i] - arr2[i];
        arr2[i] = arr1[i];
    }

    // Xay dung maxHeapify va minHeapify hoan chinh
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr1, i);
        minHeapify(arr2, i);
    }

    // int sum = 0;

    // int max = arr1[0];
    // int min = arr2[0];

    // while (max != min)
    // {
    //     cout << sum << endl;
    //     if (max + min <= 0)
    //     {
    //         extractMin(arr2);
    //         min = arr2[0];
    //     }
    //     else
    //     {
    //         sum += arr1.size() - 1;
    //         extractMax(arr1);
    //         max = arr1[0];
    //     }
    // }
    // return sum;
}
void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    vector<int> arr1, arr2;
    int n;
    cout << "Nhap: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Nhap so tien ng " << i + 1 << " : ";
        cin >> data;
        arr1.push_back(data);

        cout << "Nhap gia tien ng " << i + 1 << " : ";
        cin >> data;
        arr2.push_back(data);
    }

    cout << function02(arr1, arr2, n);
    printArray(arr1, n);
    printArray(arr2, n);
    return 0;
}